#include"header/server_exception.h"


ServerException::ServerException()
{
    this ->msg ="客户端异常！";
}

ClientException(const std::string& msg)
{
    this ->msg = "客户端异常————";
    this -> msg += msg;
    this -> msg +="!";
}

ClientException::~ClientException() throw(){}

ClientException::const char*whatMsg()
{
    return this ->msg.c_str();
}
