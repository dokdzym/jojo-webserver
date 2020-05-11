//
// Created by jojo on 2020/5/3.
//

#ifndef JOJO_WEBSERVER_HTTPRESPONSE_H
#define JOJO_WEBSERVER_HTTPRESPONSE_H

#include<string>
#include<map>
#include<iostream>

class Buffer;

#define CONNECTION_TIMEOUT 512

class HttpResponse {
public:
    static const std::map<int, std::string> statusCode2Message;
    static const std::map<std::string, std::string> suffix2Type;

    HttpResponse(int statusCode, std::string path, bool keepAlive)
        : statusCode_(statusCode),
          path_(path),
          keepAlive_(keepAlive)
    {}

    ~HttpResponse() {}

    Buffer Make_Response();
    void doErrorResponse(Buffer& output, std::string message);
    void doStaticRequest(Buffer& output, long fileSize);

private:
    std::string __getFileType();

private:
    std::map<std::string, std::string> headers_; 
    int statusCode_; 
    std::string path_; 
    bool keepAlive_; 
};


#endif //JOJO_WEBSERVER_HTTPRESPONSE_H
