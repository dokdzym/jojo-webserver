//
// Created by jojo on 2020/5/3.
//

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
