cmake_minimum_required(VERSION 3.15)
project(jojo_webserver)

set(CMAKE_CXX_STANDARD 14)

add_executable(jojo_webserver main.cpp Util.cpp Util.h Server.cpp Server.h Timer.cpp Timer.h Epoll.cpp Epoll.h HttpRequest.cpp HttpRequest.h HttpResponse.cpp HttpResponse.h ThreadPool.cpp ThreadPool.h Buffer.h Buffer.cpp)