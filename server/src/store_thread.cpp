#include "header/store_thread.h"
#include "header/log_queue.h"

using std::cout;
using std::endl;

#define _DEBUG
/**************************************************
*作者：Liu Chaoyang
*日期：2017.06.12
*函数名：StoreThread
*功能：Constructor of StoreThread
*输入参数：log_dao
*输出参数：none
*返回值：none
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
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/
StoreThread::~StoreThread()
{

}

/**************************************************
*作者：Liu Chaoyang
*日期：2017.06.26
*函数名：run
*功能：get data from log queue and insert data
*     into database
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/
void StoreThread::run()
{
    cout << "File Dao thread starts running..." << endl;
    while (true)
    {
        MatchedLogRec mlg;
        // get data from log queue
        g_log_queue >> mlg;
        // insert data received into file
        log_dao.insert(mlg);
#ifdef _DEBUG
        cout << "OK:file writing succeeded." << endl;
#endif
    }
}
