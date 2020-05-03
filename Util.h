//
// Created by jojo on 2020/5/3.
//

#ifndef JOJO_WEBSERVER_UTIL_H
#define JOJO_WEBSERVER_UTIL_H

#define LISTEN_LEN 1024


#include <iostream>
#include <cstring> // bzero

#include <stdio.h> // perror
#include <unistd.h> // fcntl, close
#include <fcntl.h> // fcntl
#include <sys/socket.h> // socket, setsockopt, bind, listen
#include <arpa/inet.h> // htonl, htons
namespace Util
{
    int Create_Epoll(int port);
    int Set_Non_Blocking(int fd);
}

#endif //JOJO_WEBSERVER_UTIL_H
