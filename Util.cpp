//
// Created by jojo on 2020/5/3.
//

#include "Util.h"
namespace Util
{
    int Create_Epoll(int port)
    {
        if(port <= 1024 || port >= 65535) port = 6666;//Unsafe port

        //Create listen fd
        int listen_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
        if(listen_fd == -1)//Failed
        {
            std::cout << "Error occurs in Util.cpp! Create listen fd failed! errno = " << errno << std::endl;
            return - 1;
        }

        //Allow reuse the port
        int optval = 1;
        if(setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, (const void*) &optval, sizeof(int)) == -1)
        {
            std::cout << "Error occurs in Util.cpp! setsockopt failed!" << "errno = " << errno << std::endl;
            return - 1;
        }

        //Set server attribution and bind
        struct sockaddr_in server_addr;
        bzero((char *) &server_addr, sizeof(server_addr));
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//all IP allowed
        server_addr.sin_family = AF_INET;//IPV4
        server_addr.sin_port = htons((unsigned short)port);
        if(bind(listen_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1)
        {
            std::cout << "Error occurs in Util.cpp! bind failed!" << "errno = " << errno << std::endl;
            return - 1;
        }

        //start listening

        if(listen(listen_fd, LISTEN_LEN) == -1)
        {
            std::cout << "Error occurs in Util.cpp! listen failed!" << "errno = " << errno << std::endl;
            return - 1;
        }
        //close useless listen_fd

        if(listen_fd == -1)
        {
            close(listen_fd);
            std::cout << "listen fd closed!" << std::endl;
            return -1;
        }

        return listen_fd;
    }

    int Set_Non_Blocking(int fd)
    {
        int file_attribution = fcntl(fd, F_GETFL, 0);
        if(file_attribution == -1)
        {
            std::cout << "Error occurs in Util.cpp! Get file attribution failed!" << "errno = " << errno << std::endl;
            return - 1;
        }

        file_attribution |= O_NONBLOCK;
        if(fcntl(fd, F_SETFL, file_attribution) == -1)
        {
            std::cout << "Error occurs in Util.cpp! Set file attribution failed!" << "errno = " << errno << std::endl;
            return - 1;
        }

        return 0;
    }

}