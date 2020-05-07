//
// Created by jojo on 2020/5/3.
//

#ifndef JOJO_WEBSERVER_BUFFER_H
#define JOJO_WEBSERVER_BUFFER_H

#include <vector>
#include <string>
#include <algorithm> // copy
#include <iostream>
#include <unistd.h> //close
#include <cassert>

class Buffer
{
public:
    Buffer();
    ~Buffer();

private:
    size_t _BufferLength;
};


#endif //JOJO_WEBSERVER_BUFFER_H