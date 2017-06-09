#include"header/server_exception.h"

using namespace std;

ServerException::ServerException()
{
    this ->msg ="客户端异常！";
}

ClientException(const string& msg)
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
