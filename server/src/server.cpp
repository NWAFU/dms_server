#include <iostream>

#include "header/server.h"
#include "header/file_dao.h"
#include "header/oracle_dao.h"
#include "header/server_exception.h"

using std::cout;
using std::endl;

Server::Server()
{
    FileDao file_dao;
    OracleDao oracle_dao;
    store_thread = new StoreThread(file_dao, oracle_dao);
    char ip[32] = "127.0.0.1";
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
    try
    {
        server_socket->acceptClient();
    }
    catch(ServerException se)
    {
        cout << se.what() << endl;
    }
}
