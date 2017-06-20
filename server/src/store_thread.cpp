#include "header/store_thread.h"
#include "header/log_queue.h"

/**************************************************
*作者：Liu Chaoyang
*日期：2017.06.12
*函数名：StoreThread
*功能：Constructor of StoreThread
*输入参数：log_dao
*输出参数：void
*返回值：void
**************************************************/

StoreThread::StoreThread(LogDao &log_dao)
    : log_dao(log_dao)
{

}

/**************************************************
*作者：Liu Chaoyang
*日期：2017.06.12
*函数名：~StoreThread
*功能：Destructor of StoreThread
*输入参数：void
*输出参数：void
*返回值：void
**************************************************/

StoreThread::~StoreThread()
{

}

void StoreThread::run()
{
    while (true)
    {
        MatchedLogRec mlg;
        log_queue >> mlg;
        log_dao.insert(mlg);
    }
}
