#ifndef SOCKET_EXCEPTION_H
#define SOCKET_EXCEPTION_H

#include"server_exception.h"

//2.套接字异常
class SocketException:public ServerException
{
public:
    SocketException();
    SocketException(const string& msg);
};

#endif // SOCKET_EXCEPTION_H
