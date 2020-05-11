//
// Created by jojo on 2020/5/3.
//

#include "HttpResponse.h"
#include "Buffer.h"

#include <cstring>
#include <fcntl.h> // open
#include <sys/stat.h> // stat
#include <sys/mman.h> // mmap, munmap

const std::map<int, std::string> HttpResponse::statusCode2Message = {
    {200, "OK"},
    {400, "Bad Request"},
    {403, "Forbidden"},
    {404, "Not Found"}
};

const std::map<std::string, std::string> HttpResponse::suffix2Type = {
    {".html", "text/html"},
    {".xml", "text/xml"},
    {".xhtml", "application/xhtml+xml"},
    {".txt", "text/plain"},
    {".rtf", "application/rtf"},
    {".pdf", "application/pdf"},
    {".word", "application/nsword"},
    {".png", "image/png"},
    {".gif", "image/gif"},
    {".jpg", "image/jpeg"},
    {".jpeg", "image/jpeg"},
    {".au", "audio/basic"},
    {".mpeg", "video/mpeg"},
    {".mpg", "video/mpeg"},
    {".avi", "video/x-msvideo"},
    {".gz", "application/x-gzip"},
    {".tar", "application/x-tar"},
    {".css", "text/css"}
};

Buffer HttpResponse::Make_Response()
{
    Buffer output;

    if(statusCode_ == 400) {
        doErrorResponse(output, "Swings can't parse the message");
        return output;
    }

    struct stat sbuf;
    // No error
    if(::stat(path_.data(), &sbuf) < 0) {
        statusCode_ = 404;
        doErrorResponse(output, "Swings can't find the file");
        return output;
    }
    // chmod error
    if(!(S_ISREG(sbuf.st_mode) || !(S_IRUSR & sbuf.st_mode))) {
        statusCode_ = 403;
        doErrorResponse(output, "Swings can't read the file");
        return output;
    }

    doStaticRequest(output, sbuf.st_size);
    return output;
}

// TODO : Fill in the headers
void HttpResponse::doStaticRequest(Buffer& output, long fileSize)
{
    assert(fileSize >= 0);

    auto itr = statusCode2Message.find(statusCode_);
    if(itr == statusCode2Message.end()) {
        statusCode_ = 400;
        doErrorResponse(output, "Unknown status code");
        return;
    }

    // response line
    output.Append("HTTP/1.1 " + std::to_string(statusCode_) + " " + itr -> second + "\r\n");
    // header
    if(keepAlive_) {
        output.Append("Connection: Keep-Alive\r\n");
        output.Append("Keep-Alive: timeout=" + std::to_string(CONNECTION_TIMEOUT) + "\r\n");
    } else {
        output.Append("Connection: close\r\n");
    }
    output.Append("Content-type: " + __getFileType() + "\r\n");
    output.Append("Content-length: " + std::to_string(fileSize) + "\r\n");
	
    output.Append("Server: Swings\r\n");
    output.Append("\r\n");

    // body
    int srcFd = ::open(path_.data(), O_RDONLY, 0);
    // mmap
    void* mmapRet = ::mmap(NULL, fileSize, PROT_READ, MAP_PRIVATE, srcFd, 0);
    ::close(srcFd);
    if(mmapRet == (void*) -1) {
        munmap(mmapRet, fileSize);
        output.Reset_Index();
        statusCode_ = 404;
        doErrorResponse(output, "Swings can't find the file");
        return;
    }
    char* srcAddr = static_cast<char*>(mmapRet);
    output.Append(srcAddr, fileSize);

    munmap(srcAddr, fileSize);
}

std::string HttpResponse::__getFileType()
{
    int idx = path_.find_last_of('.');
    std::string suffix;
    // Cannot get the suffix, default :plain text
    if(idx == std::string::npos) {
        return "text/plain";
    }
        
    suffix = path_.substr(idx);
    auto itr = suffix2Type.find(suffix);
    // Unknown suffix, default :plain text
    if(itr == suffix2Type.end()) {
        return "text/plain";
    }   
    return itr -> second;
}

// TODO : Fill in the headers
void HttpResponse::doErrorResponse(Buffer& output, std::string message) 
{
    std::string body;

    auto itr = statusCode2Message.find(statusCode_);
    if(itr == statusCode2Message.end()) {
        return;
    }

    body += "<html><title>Swings Error</title>";
    body += "<body bgcolor=\"ffffff\">";
    body += std::to_string(statusCode_) + " : " + itr -> second + "\n";
    body += "<p>" + message + "</p>";
    body += "<hr><em>Swings web server</em></body></html>";

    // response line
    output.Append("HTTP/1.1 " + std::to_string(statusCode_) + " " + itr -> second + "\r\n");
    // header
    output.Append("Server: Swings\r\n");
    output.Append("Content-type: text/html\r\n");
    output.Append("Connection: close\r\n");
    output.Append("Content-length: " + std::to_string(body.size()) + "\r\n\r\n");
    // body
    output.Append(body);
}