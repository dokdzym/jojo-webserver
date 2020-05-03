//
// Created by jojo on 2020/5/3.
//

#ifndef JOJO_WEBSERVER_SERVER_H
#define JOJO_WEBSERVER_SERVER_H

#include "Util.h"

class Server {
public:
    Server(int port, int num_threads);
    ~Server();
    void Run();

private:
    int _port;
    int _listen_fd;
    //thread_pool
    //epoll
    //epoll_fd
    //port
    //Timer
};
#endif //JOJO_WEBSERVER_SERVER_H
