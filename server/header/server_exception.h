#ifndef SERVEREXCEPTION_H
#define SERVEREXCEPTION_H

#include <exception>
#include <string>

//0.客户端异常
class ServerException:public std::exception
{
private:
    std::string msg;
public:
    ServerException();
    ServerException(const std::string& msg);
    ~ServerException() throw();
    const char* whatMsg();
};

#endif
