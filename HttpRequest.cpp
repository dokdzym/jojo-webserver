//
// Created by jojo on 2020/5/3.
//

#include "HttpRequest.h"

HttpRequest::HttpRequest(int fd):_fd(fd)
{

}

HttpRequest::~HttpRequest() {

}

int HttpRequest::Read(int *httperrno) {
    return 0;
}

int HttpRequest::Write(int *httperrno) {
    return 0;
}
