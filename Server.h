//
// Created by jojo on 2020/5/3.
//

#ifndef JOJO_WEBSERVER_SERVER_H
#define JOJO_WEBSERVER_SERVER_H

#include<memory> //C++ 11 locks
#include<mutex>

#define TIMEOUT -1 //epoll_wait timeout(default : no timeout)
#define CONNECTION_TIMEOUT 512
#define NUM_THREADS 4 //size of thread pool

class HttpRequest;
class Epoll;
class ThreadPool;
class Timer;

using TheadPoolPtr = std::shared_ptr<ThreadPool>;
using ListenPtr    = std::unique_ptr<HttpRequest>;
using EpollPtr     = std::unique_ptr<Epoll>;
using TimerPtr     = std::unique_ptr<Timer>;


class Server {
public:
    //Initializing function
	Server(int port, int num_threads);
    ~Server();
    void Run();
	
	//Work function
	void ConnectTCP();
	void CloseTCP(HttpRequest* request);
	void HandleRequest(HttpRequest* request);
	void HandleResponse(HttpRequest* request);
	
private:
    int _port;
    int _listen_fd;
	
	TheadPoolPtr _threadpool;
	ListenPtr _listen;
	EpollPtr _epoll;
	TimerPtr _timer;
};
#endif //JOJO_WEBSERVER_SERVER_H
