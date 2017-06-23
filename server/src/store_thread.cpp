#include "header/store_thread.h"
#include "header/log_queue.h"

using std::cout;
using std::endl;

#define __DEBUG__
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
    cout << "Oracle Dao start..." << endl;
    while (true)
    {
        MatchedLogRec mlg;
        // get data from log queue
        log_queue >> mlg;
        // insert data received into file
        log_dao.insert(mlg);
#ifdef __DEBUG__
        cout << "DataBase writing succeeded" << endl;
#endif
    }
}
