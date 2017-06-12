#include"header/server_exception.h"


ServerException::ServerException()
{
    this ->msg ="客户端异常！";
}

ServerException::ServerException(const std::string& msg)
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
