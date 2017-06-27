#include <iostream>
#include <pthread.h>

#include "header/base_thread.h"
#include "header/thread_exception.h"

using std::cout;
using std::endl;

//#define _DEBUG

BaseThread::~BaseThread()
{

}

/**************************************************
*作者：Liu Chaoyang
*日期：2017.06.26
*函数名：task
*功能：used to call run method
*输入参数：arg
*输出参数：none
*返回值：none
**************************************************/
void* BaseThread::task(void *arg)
{
    static_cast<BaseThread*>(arg)->run();
    return NULL;
}


/**************************************************
*作者：Liu Chaoyang
*日期：2017.06.26
*函数名：start
*功能：used to create thread and start it
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/
void BaseThread::start()
{
    int res = pthread_create(&tid, NULL, task, this);
    if (res != 0)
    {
#ifdef _DEBUG
        cout << "Thread creation failed!" << endl;
#endif
        throw ThreadException("Thread creation failed!");
    }
#ifdef _DEBUG
        cout << "Thread creation succeeded." << endl;
#endif
}
