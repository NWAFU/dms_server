#include "header/client_thread.h"
#include "header/data.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <header/log_queue.h>
#include <iostream>
#include <header/data.h>
#include "header/server_exception.h"

#define __DEBUG__

using std::cout;
using std::endl;

ClientThread::ClientThread(int conn_fd) : conn_fd(conn_fd)
{

}

ClientThread::~ClientThread()
{
    // close this thread
    pthread_exit(NULL);
}

/**************************************************
*作者：Liu Chaoyang
*函数名：run
*功能：receive message from clients
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/

void ClientThread::run()
{
    printf("start running\n");
    int rlen;
    MatchedLogRec buf;
#ifdef __DEBUG__
    int rcv_count = 0;      // count the number of received logs
#endif
    while (true)
    {
        rlen = recv(conn_fd, (MatchedLogRec*)&buf, sizeof(MatchedLogRec), 0);
        if (rlen < 0)
        {
            cout << "Receive error!" << endl;
            throw ServerException("Receive error!");
        }
        else if (rlen == 0)
        {
            cout << "Finish receiving!" << endl;
#ifdef __DEBUG__
            cout << "Received: " << rcv_count << endl;
#endif
            delete this;
        }
        else
        {
#ifdef __DEBUG__
            rcv_count++;           
            // print data received to console(just for test)
            cout << buf << endl;
#endif
            // insert data received into log queue
            log_queue << buf;
        }
    }
}
