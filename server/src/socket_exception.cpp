#include"header/socket_exception.h"
/**************************************************
*作者：马骏
*函数名：SocketException()
*功能：套接字异常类默认构造函数
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/

SocketException::SocketException() :ServerException("套接字异常")
{

}
/**************************************************
*作者：马骏
*函数名：SocketException(const string& msg)
*功能：套接字异常类帯参数构造函数
*输入参数：const string& msg
*输出参数：none
*返回值：none
**************************************************/
SocketException::SocketException(const string& msg) : ServerException(msg)
{

}

