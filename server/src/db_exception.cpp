#include"header/db_exception.h"

/**************************************************
*作者：马骏
*日期：2017.6.26
*函数名：DBException()
*功能：数据库异常类默认构造函数
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/
DBException::DBException()  :ServerException("DatebaseException")
{

}
/**************************************************
*作者：马骏
*日期：2017.6.26
*函数名：DBException(const string& msg)
*功能：数据库异常类帯参数构造函数
*输入参数：msg
*输出参数：none
*返回值：none
**************************************************/
DBException::DBException(const string& msg) : ServerException(msg)
{

}

