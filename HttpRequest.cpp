//
// Created by jojo on 2020/5/3.
//

#include "HttpRequest.h"
#include<cassert>
#include<unistd.h>

HttpRequest::HttpRequest(int fd):
    _fd(fd),
    _working(false),
    _status(RequestLine),
    _method(InvalidMethod),
    _version(UnknownVersion)
{
	assert(_fd >= 0);
}

HttpRequest::~HttpRequest() {
	close(_fd);
}

int HttpRequest::Read(int* err_no) {
	//Read from buffer and save errno;
	int ret = _in_buf.Read_Fd(_fd, err_no);
	return ret;
}

int HttpRequest::Write(int* err_no) {
	//Write to buffer and save errno;
	int ret = _in_buf.Read_Fd(_fd, err_no);
	return ret;
}

bool HttpRequest::Parse_Request()
{
	bool ok = true;
	bool has_more = true;
	
	while(hasmore)
	{
		if(RequestLine == _status) //Handle request line
		{
			const char* crlf = _in_buf.Find_CRLF();
			if(crlf)
			{
				ok = Parse_Request_Line(_in_buf.Read_Peek(), crlf);
				if(ok)
				{
					_in_buf.Retrieve_Until(crlf + 2);
					_status = Headers;
				}
				else
					hasmore = false;//error occurs!
			}
			else
				hasmore = false;//error occurs!
		}
		else if(Headers == _status) //Handle headers
		{
			const char* crlf = _in_buf.Find_CRLF();
			if(crlf)
			{
				const char* colon = std::find(_in_buf.Read_Peek(), crlf, ':');
				if(colon != crlf)
					Add_Header(_in_buf, colon, crlf);
				else
				{
					_status = Finished;
					hasmore = false;
				}
				_in_buf.Retrieve_Until(crlf + 2);
			}
			else
				hasmore =false;
		}
		else if(Body == _status)
			;//Handle body
	}
	return ok;
}

bool HttpRequest::Parse_Request_Line(const char* begin, const char* end)
{
	bool finished = false;
	const char* start = begin;
	const char* space = std::find(start, end, ' ');
	
	if(space != end && Set_Method(start, space))
	{
		start = space + 1;
		space = std::find(start, end, ' ');
		if(space != end)
		{
			const char* question_mark = std::find(start, end, '?');
			if(question_mark != space)
			{
				Set_Path(start, question_mark);
				Set_Query(question_mark, space);
			}
			else
				Set_Path(start, space);
			
			start = space + 1;
			finished = end - start == 8 && std::equal(start, end - 1, "HTTP/1.");
			
			if(finished)
			{
				if(*(end - 1) == '1')
					Set_Version(HTTP11);
				else if(*(end - 1) == '0')
					Set_Version(HTTP10);
				else finished = false;
			}
			else
				std::cout << "Error occurs in HttpRequest.cpp! Parse_Request_Line failed! errno = " << errno << std::endl;
		}
	}
	return finished;
}

//Following methods set path/method/query/version
void HttpRequest::Set_Path(const char* begin, const char* end)
{
	std::string path;
	path.assign(begin, end);
	if(path == "/")
		path = "/index.html";
	_path = STATIC_ROOT + path;
}

void HttpRequest::Set_Method(const char* begin, const char* end) 
{
	std::string method(begin, end);
	if("GET" == method)
		_method = GET;
	else if("POST" == method)
		_method = POST;
	else if("HEAD" == method)
		_method = HEAD;
	else if("PUT" == method)
		_method = PUT;
	else if("DELETE" == method)
		_method = DELETE;
	else
		_method = InvalidMethod;
	
	return _method != InvalidMethod;
	
} 

void HttpRequest::Set_Query(const char* begin, const char* end) 
{
	_query.assign(begin, end);
}

void HttpRequest::Set_Version(HttpVersion version)
{
	_version = version;
}