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

bool HttpRequest::Is_KeepAlive() const
{
	std::string status = Get_Header("Connection");
	return ("Keep-Alive" == status)||(HTTP11 == _version && "close" != status);
}

std::string HttpRequest::Get_Header(const std::string& field) const
{
	std::string res;
	auto itr = _header.find(field);
	if(itr != _header.end())
		res = itr -> second;
	return res;
}

std::string HttpRequest::Get_Method() const
{	
	std::string res;
	if(GET == _method)
		res = "GET";
	else if(POST == _method)
		res = "POST";
	else if(HEAD == _method)
		res = "HEAD";
	else if(PUT == _method)
		res = "PUT";
	else if(DELETE == _method)
		res = "DELETE";
	else
		res = "ERROR";
	
	return res;
}

void HttpRequest::Reset_Parse()
{
	_status = RequestLine;
	_method = InvalidMethod;
	_version = UnknownVersion;
	_path = "";
	_query = "";
	_header.clear();
}

bool HttpRequest::Parse_Request()
{
	bool ok = true;
	bool has_more = true;
	
	while(has_more)
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
					has_more = false;//error occurs!
			}
			else
				has_more = false;//error occurs!
		}
		else if(Headers == _status) //Handle headers
		{
			const char* crlf = _in_buf.Find_CRLF();
			if(crlf)
			{
				const char* colon = std::find(_in_buf.Read_Peek(), crlf, ':');
				if(colon != crlf)
					Add_Head(_in_buf.Read_Peek(), colon, crlf);
				else
				{
					_status = Finished;
					has_more = false;
				}
				_in_buf.Retrieve_Until(crlf + 2);
			}
			else
				has_more =false;
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

bool HttpRequest::Set_Method(const char* begin, const char* end)
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


void HttpRequest::Add_Head(const char* start, const char* colon, const char* end)
{
	std::string field(start, colon);
	++ colon;
	while(colon < end && ' ' == *colon)
		++ colon;//skip spaces at the beginning
	
	std::string str(colon, end);
	while(!str.empty() && str[str.size() - 1] == ' ')
		str.resize(str.size() - 1);//Delete spaces at the end

	_header[field] = str;
}