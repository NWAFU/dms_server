#include <iostream>

#include "header/server.h"
#include "header/file_dao.h"
#include "header/oracle_dao.h"
#include "header/server_exception.h"

#define __DEBUG__
#ifdef __DEBUG__
    #define DEFAULT_IP "127.0.0.1"
#endif

using std::cout;
using std::endl;

Server::Server()
{
    char ip[32] = DEFAULT_IP;
    try
    {
        server_socket = new ServerSocket(4096, ip);
    }
    catch(ServerException se)
    {
        cout << se.what() << endl;
    }
}

Server::~Server()
{
    delete store_thread;
    delete server_socket;
}

void Server::dataMine()
{
    FileDao file_dao;
    store_thread = new StoreThread(file_dao);
    // start store thread
    store_thread->start();
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
