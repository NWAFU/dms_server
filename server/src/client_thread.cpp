#include "header/client_thread.h"
#include "header/data.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <header/log_queue.h>
#include <iostream>
#include <header/data.h>

using std::cout;
using std::endl;

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
    printf("start running\n");
    int rlen;
    MatchedLogRec *buf = new MatchedLogRec();
    while (true)
    {
        rlen = recv(conn_fd, (MatchedLogRec*) buf, sizeof(MatchedLogRec), 0);
        if (rlen < 0)
        {
            printf("Receive Error!\n");
            // TODO: add exception
            pthread_exit(NULL);
        }
        else if (rlen == 0)
        {
            printf("Finish receiving!\n");
            // TODO: add exception
            pthread_exit(NULL);
        }
        else
        {
            // print data received to console(just for test)
            // TODO: insert data received into log queue
            cout << *buf << endl;
        }
    }
}
