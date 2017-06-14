#include"header/server_exception.h"
/**************************************************
*作者：马骏
*函数名：ServerException
*功能：服务器异常类默认构造函数
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/
ServerException::ServerException()
{
    this->msg ="服务器异常";
}
/**************************************************
*作者：马骏
*函数名：ServerException(string& msg)
*功能：服务器异常类帯参数构造函数
*输入参数：msg
*输出参数：none
*返回值：none
**************************************************/
ServerException::ServerException(const string& msg)
{
    this->msg = "服务器异常————";
    this->msg += msg;
    this->msg +="!";
}


ServerException::~ServerException() throw()
{

}
/**************************************************
*作者：马骏
*函数名：const char*whatMsg()
*功能：返回服务器异常类错误字符串msg
*输入参数：none
*输出参数：none
*返回值：const char*
**************************************************/
const char* ServerException::whatMsg()
{
    return this ->msg.c_str();
}
