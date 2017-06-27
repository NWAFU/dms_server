#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#include "header/server.h"
#include "header/file_dao.h"
#include "header/oracle_dao.h"
#include "header/server_exception.h"

//#define _DEBUG

#define DEFAULT_IP "127.0.0.1"
#define DEFAULT_PORT 4096

using std::cout;
using std::endl;

/**************************************************
*作者：Liu Chaoyang
*日期：2017.06.12
*函数名：Server Constructor
*功能：initial ip and port of server using default values
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/
Server::Server()
{
    // initial store_thread and server_socket
    store_thread = NULL;
    server_socket = NULL;
    char server_ip[32] = DEFAULT_IP;
    short server_port = DEFAULT_PORT;
#ifdef _DEBUG
    cout << "IP address of server is: " << server_ip << endl;
    cout << "Port of server is: " << server_port << endl;
#endif
    cout << "Starting server..." << endl;
    try
    {
        server_socket = new ServerSocket(server_port, server_ip);
    }
    catch(ServerException se)
    {
        cout << se.what() << endl;
    }
}

/**************************************************
*作者：Liu Chaoyang
*日期：2017.06.23
*函数名：Server Constructor
*功能：initial ip and port of server from outside
*输入参数：server_ip, server_port
*输出参数：none
*返回值：none
**************************************************/
Server::Server(char *server_ip, short server_port)
{
    // initial store_thread and server_socket
    store_thread = NULL;
    server_socket = NULL;
#ifdef _DEBUG
    cout << "IP address of server is: " << server_ip << endl;
    cout << "Port of server is: " << server_port << endl;
#endif
    try
    {
        server_socket = new ServerSocket(server_port, server_ip);
    }
    catch(ServerException se)
    {
        cout << se.what() << endl;
    }
}

/**************************************************
*作者：Liu Chaoyang
*日期：2017.06.23
*函数名：Server Destructor
*功能：free memory of store_thread and server_socket
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/
Server::~Server()
{
    delete store_thread;
    store_thread = NULL;
    delete server_socket;
    server_socket = NULL;
}

/**************************************************
*作者：Liu Chaoyang
*日期：2017.06.23
*函数名：DataMine
*功能：start store thread and client thread to deal
*     with clients
*输入参数：none
*输出参数：none
*返回值：none
**************************************************/
void Server::dataMine()
{
    OracleDao oracle_dao;
    cout << "Starting Oracle Dao thread..." << endl;
    store_thread = new StoreThread(oracle_dao);

    // start store thread
    store_thread->start();
    cout << "OK:file dao thread has started." << endl;
    try
    {
        // start to accept data from clients
        server_socket->acceptClient();
    }
    catch(ServerException se)
    {
        cout << se.what() << endl;
    }
}
