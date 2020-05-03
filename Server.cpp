//
// Created by jojo on 2020/5/3.
//

#include "Server.h"


Server::Server(int port, int num_threads)
{
    _port = port;
    _listen_fd = Util::Create_Epoll(_port);
}

Server::~Server()
{

}

void Server::Run()
{

}
