#include "header/log_dao.h"
#include "header/file_dao.h"
#include <fstream>
#include <iostream>
using namespace std;

#define __DEBUG__

/**************************************************
*作者:sunwei
*日期：2017.06.14
*函数名：FileDao
*功能：构造函数
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/

FileDao::FileDao(): LogDao(),file("matched_record.txt", ofstream::out|ofstream::ate){}

/**************************************************
*作者:sunwei
*日期：2017.06.09
*函数名：insert
*功能：将日志记录写到文件中
*输入参数：Log匹配好的登录日志记录
*输出参数：无
*返回值：void
**************************************************/

void FileDao::insert(MatchedLogRec const& matched_log)
{
    // TODO: open file here
    if (file.fail())
    {
#ifdef __DEBUG__
        cout<<"error:file_dao open file!"<<endl;
#endif
        return;
    }
    else
    {
#ifdef __DEBUG__
        cout<<"write success"<<endl;
#endif
    }
    file << matched_log;
    file << "\n";
    // TODO: close file
    // ...
    // TODO: remove return
    //return ;
}

/**************************************************
*作者:sunwei
*日期：2017.06.14
*函数名：~FileDao
*功能：析构函数
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/

FileDao::~FileDao()
{
    file.close();
}
