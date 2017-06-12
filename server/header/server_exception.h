#ifndef SERVEREXCEPTION_H
#define SERVEREXCEPTION_H

#include <exception>
#include <string>

using std::string;
using std::exception;

//0.客户端异常
class ServerException:public exception
{
private:
    string msg;
public:
    ServerException();
    ServerException(const string& msg);
    ~ServerException() throw();
    const char* whatMsg();
};

#endif
