#include"header/server_exception.h"
using std::string;

ServerException::ServerException()
{
    this ->msg ="客户端异常！";
}

ServerException::ServerException(const string& msg)
{
    this->msg = "客户端异常————";
    this->msg += msg;
    this->msg +="!";
}

ServerException::~ServerException() throw()
{

}

const char* ServerException::whatMsg()
{
    return this ->msg.c_str();
}
