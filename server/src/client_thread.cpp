#include "header/client_thread.h"
#include "header/data.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <header/log_queue.h>
#include <iostream>
#include <cstring>
#include <header/data.h>
#include <cstdlib>
#include "header/server_exception.h"

//#define _DEBUG

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
*日期：2017.06.26
*函数名：run
*功能：receive message from clients
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/

void ClientThread::run()
{
    int rlen;
    MatchedLogRec buf;
    int rcv_count = 0;      // count the number of received logs

#ifdef _DEBUG
    int error_num=0;
#endif

    while (true)
    {
        rlen = recv(conn_fd, (MatchedLogRec*)&buf, sizeof(MatchedLogRec), 0);
        if (rlen < 0)
        {
#ifdef _DEBUG
            cout << "Receiving data failed!" << endl;
#endif
            throw ServerException("Receiving data failed!");
        }
        else if (rlen == 0)
        {           
            //cout << "Disconnected to this client." << endl;
            cout << "Received: " << rcv_count << endl;
#ifdef _DEBUG
            cout<<"Error number: "<<error_num<<endl;
#endif
            delete this;
        }
        else if (rlen == 80)
        {
            rcv_count++;
#ifdef _DEBUG
            // print data received to console(just for test)
            //cout << buf << endl;
#endif
            // insert data received into log queue
            g_log_queue << buf;
        }
        else if (rlen < sizeof(MatchedLogRec))
        {
            int buf_cur_num = 0;
#ifdef _DEBUG
            //cout << "Oops!" << endl;
            error_num++;
#endif

            while (true)
            {
                buf_cur_num += rlen;
                if (buf_cur_num == 80)
                {
                    break;
                }
                //cout << "Before Receive: " << sizeof(MatchedLogRec) - buf_cur_num << endl;
                rlen = recv(conn_fd, (MatchedLogRec*)&buf + buf_cur_num,
                            sizeof(MatchedLogRec) - buf_cur_num, 0);
                //cout << "After Receive: " << rlen << endl;
                try
                {
                    if (rlen == 0)
                    {
                        break;
                    }
                    else if (rlen < 0)
                    {
                        throw ServerException("Receiving data failed!");
                    }
                }
                catch (ServerException s)
                {
                    cout << s.what() << endl;
                    delete this;
                }
            }

            rcv_count++;
#ifdef _DEBUG          
            // print data received to console(just for test)
            //cout << buf << endl;
#endif
            // insert data received into log queue
            g_log_queue << buf;
        }
    }
}
