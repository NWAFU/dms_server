#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H

#include "server_exception.h"

//2.套接字异常
class SocketException:public ServerException
{
public:
    SocketException();
    SocketException(const string& msg);
};

#endif // SERVER_SOCKET_H