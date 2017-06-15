#include <stdio.h>
#include "header/base_thread.h"
#include <pthread.h>
BaseThread::BaseThread()
{

}

BaseThread::~BaseThread()
{

}

/**************************************************
*作者：Liu Chaoyang
*函数名：task
*功能：used to call run method
*输入参数：arg
*输出参数：void
*返回值：void
**************************************************/
//void BaseThread::*task(void *arg)
//{
//    static_cast<BaseThread*>(arg)->run();
//}


/**************************************************
*作者：Liu Chaoyang
*函数名：start
*功能：used to create thread and start it
*输入参数：void
*输出参数：void
*返回值：void
**************************************************/
void BaseThread::start()
{
    pthread_create(&tid, NULL, task, this);
}
