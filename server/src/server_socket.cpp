#include "header/server_socket.h"
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include "header/client_thread.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

/**************************************************
*作者：Liu Chaoyang
*日期：2017.06.12
*函数名：ServerSocket
*功能：default constructor of ServerSocket
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/
ServerSocket::ServerSocket()
{
    int ret = socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (ret < 0)
    {
        cout << "socket create fails!" << endl;
        // TODO: add exception
        exit(-1);
    }
    else
    {
        cout << "socket create succeed." << endl;
    }
    strcpy(server_ip, "127.0.0.1");
    server_port = 4096;
}

ServerSocket::ServerSocket(short server_port, char *server_ip)
{
    int ret = socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (ret < 0)
    {
        cout << "socket create fail!" << endl;
        // TODO: add exception
        exit(-1);
    }
    else
    {
        cout << "socket create success." << endl;
    }
    strcpy(this->server_ip, server_ip);
    this->server_port = server_port;
}

/**************************************************
*作者：Liu Chaoyang
*日期：2017.06.12
*函数名：ServerSocket
*功能：Destructor of ServerSocket
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/
ServerSocket::~ServerSocket()
{
    close(socket_fd);
    close(client_sockfd);
}

/**************************************************
*作者：Liu Chaoyang
*日期：2017.06.12
*函数名：acceptClient
*功能：listen requests from client, and return socket
* file descriptor and create a thread to communicate
* with the client if there is request
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/
void ServerSocket::acceptClient()
{
    // name socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(server_port);
    int server_len = sizeof(server_address);

    // bind socket and address 
    int ret = bind(socket_fd, (struct sockaddr *)&server_address, server_len);

    if (ret < 0)
    {
        cout << "bind socket fail!" << endl;
        // TODO: add exception
    }
    else
    {
        cout << "bind socket success." << endl;
    }
    // listen socket
    listen(socket_fd, 100);

    // waiting for request of connection
    while (true)
    {
        struct sockaddr_in client_address;
        int client_len = sizeof(client_address);
        cout << "waiting for request of connection..." << endl;
        client_sockfd = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t *)&client_len);
        if (client_sockfd < 0)
        {
            cout << "connection error!" << endl;
            //TODO: add exception
        }
        else
        {
            // start a new client thread to deal with the client connecting
            ClientThread *client_thread = new ClientThread(client_sockfd);
            client_thread->start();
        }
    }
}

