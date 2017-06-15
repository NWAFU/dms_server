#include "header/server_socket.h"
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include "header/client_thread.h"
#include <string.h>

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
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    strcpy(server_ip, "10.0.2.15");
    server_port = 4096;
}

ServerSocket::ServerSocket(short server_port, char *server_ip)
{
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
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
    server_address.sin_port = server_port;
    int server_len = sizeof(server_address);
    // bind socket and address
    int ret = bind(socket_fd, (struct sockaddr *)&server_address, server_len);

    if (ret < 0)
    {
        // bind exception
    }
    listen(socket_fd, 100);

    while (true)
    {
        struct sockaddr_in client_address;
        int client_len = sizeof(client_address);
        client_sockfd = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t *)&client_len);
        if (client_sockfd < 0)
        {
            // connect exception
        }
        else
        {
            ClientThread client_thread(client_sockfd);
            client_thread.start();
        }
    }
}

