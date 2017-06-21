#ifndef SERVER_H
#define SERVER_H
#include "header/server_socket.h"
#include "header/store_thread.h"

class Server
{
private:
    ServerSocket *server_socket;
    StoreThread *store_thread;
public:
    Server();
    Server(char *server_ip, short server_port);
    ~Server();
    void dataMine();
};

#endif // SERVER_H
