#include "header/server.h"
#include "header/file_dao.h"
#include "header/oracle_dao.h"

Server::Server()
{
    FileDao file_dao;
    OracleDao oracle_dao;
    store_thread = new StoreThread(file_dao, oracle_dao);
    char ip[32] = "127.0.0.1";
    server_socket = new ServerSocket(4096, ip);
}

Server::~Server()
{
    delete store_thread;
    delete server_socket;
}

void Server::dataMine()
{
    server_socket->acceptClient();
}
