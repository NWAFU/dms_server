#include"header/thread_exception.h"
/**************************************************
*作者：马骏
*日期：2017.6.26
*函数名：ThreadException()
*功能：线程异常类默认构造函数
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/

ThreadException::ThreadException() : ServerException("Thread Exception")
{

}
/**************************************************
*作者：马骏
*日期：2017.6.26
*函数名：ThreadException(const string& msg)
*功能：线程异常类帯参数构造函数
*输入参数：msg
*输出参数：none
*返回值：none
**************************************************/
ThreadException::ThreadException(const string& msg) : ServerException(msg)
{

}

