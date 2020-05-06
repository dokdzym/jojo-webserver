//
// Created by jojo on 2020/5/3.
//

#include "HttpRequest.h"

HttpRequest::HttpRequest(int fd):_fd(fd), _working(false), _status(RequestLine), _method(InvalidMethod), _version(UnknownVersion)
{
	assert(_fd >= 0);
}

HttpRequest::~HttpRequest() {
	close(_fd);
}

int HttpRequest::Read(int *httperrno) {
	//Read from buffer and save errno;
	return 0;
}

int HttpRequest::Write(int *httperrno) {
	//Write to buffer and save errno;
	return 0;
}
