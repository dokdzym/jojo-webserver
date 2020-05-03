//
// Created by jojo on 2020/5/3.
//

#ifndef JOJO_WEBSERVER_EPOLL_H
#define JOJO_WEBSERVER_EPOLL_H

#include<functional>
#include<memory>
#include<vector>
#include<sys/epoll.h> // epoll_event
class HttpRequest;
class ThreadPool;

using NewConnectionFunc = std::function<void()>;
using CloseConnectionFunc = std::function<void(HttpRequest*)>;
using HandleRequestFunc = std::function<void(HttpRequest*)>;
using HandleResponseFunc = std::function<void(HttpRequest*)>;
using Event_Lists = std::vector<epoll_event>;

#define MAX_EVENTS 1024


class Epoll {
public:
    Epoll();
    ~Epoll();
    int Epoll_Wait(int timeout);

    int Epoll_Add(int fd, HttpRequest * request, int events);//add
    int Epoll_Mod(int fd, HttpRequest * request, int events);//modify
    int Epoll_Del(int fd, HttpRequest * request, int events);//delete

    void Handle_Event(int listen_fd, std::shared_ptr<ThreadPool> & threadpool, int events_num);

    void Connect_(const NewConnectionFunc & Connecting_){Connecting = Connecting_;}
    void Close_(const CloseConnectionFunc & Closing_){Closing = Closing_;}
    void Handle_Request(const HandleRequestFunc & Request_){HandlingRequest = Request_;}
    void Handle_Response(const HandleResponseFunc & Response_){HandlingResponse = Response_;}

private:
    Event_Lists events;
    int epoll_fd;

    //the following function templates work when epoll gets an event.
    NewConnectionFunc Connecting;
    CloseConnectionFunc Closing;
    HandleRequestFunc HandlingRequest;
    HandleResponseFunc HandlingResponse;
};


#endif //JOJO_WEBSERVER_EPOLL_H
