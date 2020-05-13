#include "Server.h"

int main(int argc, char** argv)
{
    std::cout << "Server is running..."<<std::endl;
    // TODO 读配置文件
    int port = 6666;
    if(argc >= 2) {
        port = atoi(argv[1]);
    }
    std::cout << "port = " << port<<std::endl;
    int numThread = 4;
    if(argc >= 3) {
        numThread = atoi(argv[2]);
    }

    Server server(port, numThread);
    server.Run();
    std::cout << "Server stop!"<<std::endl;
    return 0;
}
