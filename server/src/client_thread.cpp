#include "header/client_thread.h"
#include "header/data.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <header/log_queue.h>

ClientThread::ClientThread(int conn_fd) : conn_fd(conn_fd)
{

}

ClientThread::~ClientThread()
{

}

/**************************************************
*作者：Liu Chaoyang
*函数名：run
*功能：receive message from clients
*输入参数：void
*输出参数：void
*返回值：void
**************************************************/

void ClientThread::run()
{
    int rlen;
    MatchedLogRec *buf = NULL;
    while (true)
    {
        rlen = recv(conn_fd, (MatchedLogRec*) buf, sizeof(buf), 0);
        if (rlen < 0)
            printf("Receive Error!");
        else if (rlen == 0)
        {
            pthread_exit(NULL);
        }
        else
        {
            // add matched log into log queue
            //log_queue << buf;
        }
    }
}
