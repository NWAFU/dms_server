#include "header/data.h"
#include <iostream>

using std::endl;

/**************************************************
*作者：Liu Huisen
*日期：2017.06.13
*函数名：operator>>
*功能：Overload >> operator for MatchedLogRec object
*     inputed from file.
*输入参数：fout,matched_log
*输出参数：none
*返回值：fout
**************************************************/
ifstream & operator>>(ifstream & fin,MatchedLogRec & matched_log)
{
    fin>>matched_log.log_name;
    fin>>matched_log.pid;
    fin>>matched_log.login_time;
    fin>>matched_log.logout_time;
    fin>>matched_log.duration;
    fin>>matched_log.log_ip;
    return fin;
}

/**************************************************
*作者：Liu Huisen
*日期：2017.06.13
*函数名：operator<<
*功能：Overload << operator for MatchedLogRec object
*     output to file.
*输入参数：fout,matched_log
*输出参数：none
*返回值：fout
**************************************************/
ofstream & operator <<(ofstream & fout,MatchedLogRec const & matched_log)
{
    fout<<matched_log.log_name;
    fout<<" ";
    fout<<matched_log.pid;
    fout<<" ";
    fout<<matched_log.login_time;
    fout<<" ";
    fout<<matched_log.logout_time;
    fout<<" ";
    fout<<matched_log.duration;
    fout<<" ";
    fout<<matched_log.log_ip;
    fout<<endl;
    return fout;
}

