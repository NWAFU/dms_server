#ifndef SERVEREXCEPTION_H
#define SERVEREXCEPTION_H

#include <exception>
#include <string>

//0.客户端异常
class ServerException:public exception
{
private:
    string msg;
public:
    ServerException();
    ClientException(const string& msg);
    ~ClientException() throw();
    const char* whatMsg();
};

#endif
