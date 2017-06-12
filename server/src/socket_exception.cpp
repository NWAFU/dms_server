#include"header/socket_exception.h"

using namespace std;

SocketException::SocketException()
{
    ServerException("套接字异常");
}

SocketException::SocketException(const string& msg)
{
    ServerException(msg);
}

