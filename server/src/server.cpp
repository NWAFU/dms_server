#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#include "header/server.h"
#include "header/file_dao.h"
#include "header/server_exception.h"

#define __DEBUG__

#define DEFAULT_IP "127.0.0.1"
#define DEFAULT_PORT 4096

using std::cout;
using std::endl;

Server::Server()
{
    char server_ip[32] = DEFAULT_IP;
    short server_port = DEFAULT_PORT;
#ifdef __DEBUG__
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

Server::Server(char *server_ip, short server_port)
{
#ifdef __DEBUG__
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
