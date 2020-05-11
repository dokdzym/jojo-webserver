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
	
	
	//About Timer
	void Set_Timer(Timer* timer) {_timer = timer;}
	Timer* Get_Timer() const{return _timer;}
	
	
	//About Buffer
	void Append_Out_Buf(const Buffer& buf) {_out_buf.append(buf);}
	int Writable_Bytes() {return _out_buf.Readable_Bytes();}
	
	
	//Get HTTP status
    int GetFd() const {return _fd;}
	int GetWorking() const {return _working;}
	bool Parse_All() const {return Finished == _status;}
    bool WorkingStatus() const {return _working;}
	bool Is_KeepAlive() const;
	
	std::string Get_Path() const {return _path;}
	std::string Get_Query() const {return _query;}
    std::string Get_Header(const std::string& field) const;
    std::string Get_Method() const;
	
	
	//Set work status
    void Set_Working() {_working = true; }
    void Set_Not_Working() { _working = false; }

	//Parse HTTP request
	bool Parse_Request();
	bool Parse_Request_Line(const char* begin, const char* end);

private:
	//Set path/method/query/version
	void Set_Path(const char* begin, const char* end);
	void Set_Method(const char* begin, const char* end);
	void Set_Query(const char* begin, const char* end);
	void Set_Version(HttpVersion version);
	void Add_Head(const char* start, const char* colon, const char* end);
	
private:
	//About basic attribution
    int _fd;
    bool _working;
	
	//About Timer
	Timer* _timer;
	
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
