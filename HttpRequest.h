//
// Created by jojo on 2020/5/3.
//

#ifndef JOJO_WEBSERVER_HTTPREQUEST_H
#define JOJO_WEBSERVER_HTTPREQUEST_H

#include "Buffer.h"

#include<iostream>
#include<string>
#include<map>

#define STATIC_ROOT "../www"

class Timer;

enum ParseStatus{RequestLine = 0, Headers, Body, Finished};
enum Method{InvalidMethod = -1, GET, POST, HEAD, PUT, DELETE};
enum HttpVersion{UnknownVersion = -1, HTTP10, HTTP11};

class HttpRequest {
public:
    HttpRequest(int fd);
    ~HttpRequest();

    int Read(int* httperrno);
    int Write(int* httperrno);
	
	//Get private member
    int GetFd() {return _fd;}
	int GetWorking() {return _working;}
	bool Parse_All() {return Finished == _status;}
    bool WorkingStatus() {return _working;}
	
	
	//Set work status
    void SetWorking() {_working = true; }
    void SetNotWorking() { _working = false; }

	//Parse HTTP request
	bool Parse_Request();
	bool Parse_Request_Line(const char* begin, const char* end);
	
	//Set path/method/query/version
	void Set_Path(const char* begin, const char* end);
	void Set_Method(const char* begin, const char* end);
	void Set_Query(const char* begin, const char* end);
	void Set_Version(HttpVersion version);
	
	
private:
	//About basic attribution
    int _fd;
    bool _working;
	
	//About Buffer
	Buffer _in_buf;
	Buffer _out_buf;
	
	//About HTTP request
	std::string _URL;
	std::string _URL_Parameter;
	ParseStatus _status;
	Method _method;
	HttpVersion _version;
	std::string _path;
	std::string _query;
    std::map<std::string, std::string> _header; // 报文头部
};


#endif //JOJO_WEBSERVER_HTTPREQUEST_H
