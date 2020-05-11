//
// Created by jojo on 2020/5/3.
//

#include "Epoll.h"
#include "HttpRequest.h"
#include "ThreadPool.h"
Epoll::Epoll() :_epoll_fd(epoll_create1(EPOLL_CLOEXEC)),
                _events (MAX_EVENTS)
{
    assert(_epoll_fd >= 0);
}

Epoll::~Epoll() {
    close(_epoll_fd);
}

int Epoll::Epoll_Wait(int timeout) {
    int events_num = epoll_wait(_epoll_fd, &*_events.begin(), static_cast<int>(_events.size()), timeout);
    if(events_num < 0)
    {
        std::cout << "Error occurs in Epoll.cpp! Epoll wait failed! errno = " << errno << std::endl;
        return - 1;
    }
    return events_num;
}

int Epoll::Add_Epoll(int fd, HttpRequest *request, int events) {
    struct epoll_event event;
    event.events = events;
    event.data.ptr = (void*)request;
    int ret = epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, fd, &event);
    return ret;
}

int Epoll::Mod_Epoll(int fd, HttpRequest *request, int events) {
    struct epoll_event event;
    event.events = events;
    event.data.ptr = (void*)request;
    int ret = epoll_ctl(_epoll_fd, EPOLL_CTL_MOD, fd, &event);
    return ret;
}

int Epoll::Del_Epoll(int fd, HttpRequest *request, int events) {
    struct epoll_event event;
    event.events = events;
    event.data.ptr = (void*)request;
    int ret = epoll_ctl(_epoll_fd, EPOLL_CTL_DEL, fd, &event);
    return ret;
}

void Epoll::Handle_Event(int listen_fd, std::shared_ptr<ThreadPool> &threadpool, int events_num) {
    assert(events_num > 0);
    for(int i = 0; i < events_num; ++ i)
    {
        //Get HTTP request corresponding with the event
        //HttpRequest* request = static_cast<HttpRequest*>(events[i].data.ptr);
        HttpRequest* request = static_cast<HttpRequest*>(_events[i].data.ptr);
        int fd = request  -> Get_Fd();

        if(fd == listen_fd)
            Connecting(); //New connection
        else
        {
            if((_events[i].events & EPOLLERR) ||
            (_events[i].events & EPOLLHUP) ||
            !(_events[i].events | EPOLLIN))    //ERROR EVENT!
            {
                //Set request in NOT-WORKING status thus free thread
                Closing(request); //CLose connection
            }
            //Above handle error events : close connection.

            else if(_events[i].events & EPOLLIN) //It is a HTTP request
            {
                //Set request in WORKING status
				request -> Set_Working();
                //wake up thread to handle a request
                threadpool -> AssignJob(std::bind(HandlingRequest, request));
            }
            else if(_events[i].events & EPOLLOUT) //It is a HTTP response
            {
                //Set request in WORKING status
				request -> Set_Not_Working();
                //wake up thread to handle a response
				threadpool -> AssignJob(std::bind(HandlingResponse, request));
            }
        }
    }
    return ;
}
