#include"header/socket_exception.h"


SocketException::SocketException()
{
    ServerException("套接字异常");
}

SocketException::SocketException(const std::string& msg)
{
    ServerException(msg);
}

