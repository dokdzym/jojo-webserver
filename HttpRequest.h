//
// Created by jojo on 2020/5/3.
//

#ifndef JOJO_WEBSERVER_HTTPREQUEST_H
#define JOJO_WEBSERVER_HTTPREQUEST_H

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
    int _fd;
    bool _working;
};


#endif //JOJO_WEBSERVER_HTTPREQUEST_H
