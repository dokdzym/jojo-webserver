//
// Created by jojo on 2020/5/3.
//

#include "Server.h"


Server::Server(int port, int num_threads):
	_port(port),
	_listen_fd(Util::Create_Epoll(_port)),
	_threadpool(new ThreadPool(num_threads)),
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
	_epoll -> Add_Epoll(_listen_fd, _listen.get(), (EPOLLIN | EPOLLET));
	_epoll -> Connect_(std::bind(&Server::ConnectTCP, this));
	_epoll -> Close_(std::bind(&Server::CloseTCP, this, std::placeholders::_1));
	_epoll -> Handle_Request_(std::bind(&Server::HandleRequest, this, std::placeholders::_1));
	_epoll -> Handle_Response_(std::bind(&Server::HandleResponse, this, std::placeholders::_1));
	
	while(true)
	{
		//int wait_time = _timer -> Get_Next_Expire_Time();
		//int num_events = _epoll -> wait(wait_time);
		
		//if(num_events > 0)
		//	_epoll -> Handle_Event(_listen_fd, _threadpool, num_events);
		
		//_timer -> Handle_Expire_Timers();
	}
}

void Server::ConnectTCP()
{
	while(true)
	{
		int accept_fd = accept4(_listen_fd, nullptr, nullptr, (SOCK_NONBLOCK | SOCK_CLOEXEC));
		if(accept_fd == -1)
		{
			if(errno == EAGAIN)
				break;
			
			std::cout << "Error occurs in Server.cpp! accept4 failed! errno = " << errno << std::endl;
			break;
		}
		
		//Allocate resources for this connection
		HttpRequest* request = new HttpRequest(accept_fd);
		//TODO : Timer -> Add_Timer(request, CONNECTION_TIMEOUT, std::bind(&Server::CloseTCP, this, request));
		
		_epoll -> Add_Epoll(accept_fd, request, (EPOLLIN | EPOLLONESHOT));
	}
}

void Server::CloseTCP(HttpRequest* request)
{
	int fd = request -> GetFd();
	if(request -> GetWorking())
		return ;
	//Close TCP connection only when the request is not working
	//TODO : _timer -> Del_Timer(request);
	_epoll -> Del_Epoll(fd, request, 0);
	
	delete request;
	request = nullptr;
}

void Server::HandleRequest(HttpRequest* request)
{
	_timer -> Del_Timer(request);
	assert(reuest != nullptr);
	inf fd = request -> GetFd();
	
	int read_errno;
	int nread = request -> Read(&read_errno);
	
	//Server close the connection OR error occurs ；close TCP
	if(0 == nread || (nread < 0 && (read_errno != EAGAIN)))
	{
		request -> Set_Not_Working();
		Close(request);
		return ;
	}
	
	//EAGAIN occurs : free thread, continue listening
	if(nread < 0 && read_errno == EAGAIN)
	{
		_epoll -> Mod_Epoll(fd, request, (EPOLLIN | EPOLLONESHOT));
		request -> Set_Not_Working();
		_timer -> Add_Timer(request, CONNECTION_TIMEOUT, std::bind(&Server::CloseTCP, this, request));
		return ;
	}
	
	//Parse failed
	if(!request -> Parse_Request())
	{
		//HTTP status code 400
		HttpResponse response(400, "", false);
		request -> Append_Out_Buf(response.Make_Response());
		
		int write_errno;
		request -> Write(&write_errno);
		request -> Set_Not_Working();
		CloseTCP();
		return ;
	}
	
	//Parse succeed
	if(request -> Parse_All())
	{
        HttpResponse response(200, request -> Get_Path(), request -> Is_KeepAlive());
		request -> Append_Out_Buf(response.Make_Response());
		_epoll -> Mod_Epoll(fd, request, (EPOLLIN | EPOLLOUT | EPOLLONESHOT));
	}
	
}

void Server::HandleResponse(HttpRequest* request)
{
	//TODO
}
