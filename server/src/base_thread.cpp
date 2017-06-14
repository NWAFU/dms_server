#include <stdio.h>
#include "header/base_thread.h"

BaseThread::BaseThread()
{

}

BaseThread::~BaseThread()
{

}

/**************************************************
*作者：Liu Chaoyang
*日期：2017.06.12
*函数名:run
*功能：execute task function in a single thread
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/
void BaseThread::run()
{
    pthread_create(&tid, NULL, task, NULL);
}
