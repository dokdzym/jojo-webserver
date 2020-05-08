//
// Created by jojo on 2020/5/3.
//

#include "Server.h"


Server::Server(int port, int num_threads):
	_port(port),
	_listen_fd(Util::Create_Epoll(_port)),
	_threadpool(new ThreadPoll()),
	_listen(new HttpRequest(_listen_fd)),
	_epoll(new Epoll()),
	_timer(new Timer())
	
{
	assert(_listen_fd >= 0);
}

Server::~Server()
{
	//Do nothing in Server.cpp   because various server sources have their own destructor.
}

void Server::Run()
{
	_epoll -> Epoll_Add(_listen_fd, _listen.get(), (EPOLLIN | EPOLLET));
	_epoll -> Connect_(std::bind(&Server::ConnectTCP, this));
	_epoll -> Close_(std::bind(&Server::CloseTCP, this, std::placeholders::_1));
	_epoll -> Handle_Request_(std::bind(&Server::HandleRequest, this, std::placeholders::_1));
	_epoll -> Handle_Response_(std::bind(&Server::HandleResponse, this, std::placeholders::_1));
	
	while(true)
	{
		int wait_time = _timer -> Get_Next_Expire_Time();
		int num_events = _epoll -> wait(wait_time);
		
		if(num_events > 0)
			_epoll -> Handle_Event(_listen_fd, _threadpool, num_events);
		
		_timer -> Handle_Expire_Timers();
	}
}

void Server::ConnectTCP()
{
	
}

void Server::CloseTCP(HttpRequest* request)
{
	
}

void Server::HandleRequest(HttpRequest* request)
{
	
}

void Server::HandleResponse(HttpRequest* request)
{
	
}
