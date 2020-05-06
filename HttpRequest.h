//
// Created by jojo on 2020/5/3.
//

#ifndef JOJO_WEBSERVER_HTTPREQUEST_H
#define JOJO_WEBSERVER_HTTPREQUEST_H

#include "Buffer.h"

#include<string>
#include<map>

enum ParseStatus{RequestLine = 0, Headers, Body, Finished};
enum Method{InvalidMethod = -1, Get, Post, Head, Put, Delete};
enum HttpVersion{UnknownVersion = -1, HTTP10, HTTP11};

class HttpRequest {
public:
    HttpRequest(int fd);
    ~HttpRequest();

    int GetFd() {return _fd;}

    int Read(int* httperrno);
    int Write(int* httperrno);


    void SetWorking() {_working = true; }
    void SetNotWorking() { _working = false; }
    bool WorkingStatus() {return _working;}

	
private:
	//About basic attribution
    int _fd;
    bool _working;
	
	//About Buffer
	Buffer _in_Buffer;
	Buffer _out_Buffer;
	
	//About HTTP request
	std::string _URL;
	std::string _URL_Parameter;
	ParseStatus _status;
	Method _method;
	HttpVersion _version;
    std::map<std::string, std::string> _header; // 报文头部
};


#endif //JOJO_WEBSERVER_HTTPREQUEST_H
