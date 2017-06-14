#include"header/db_exception.h"

/**************************************************
*作者：马骏
*函数名：DBException()
*功能：数据库异常类默认构造函数
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/
DBException::DBException()  :ServerException("数据库异常")
{

}
/**************************************************
*作者：马骏
*函数名：DBException(const string& msg)
*功能：数据库异常类构造函数
*输入参数：const string& msg
*输出参数：none
*返回值：none
**************************************************/
DBException::DBException(const string& msg) : ServerException(msg)
{

}

