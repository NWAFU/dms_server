#ifndef SERVER_H
#define SERVER_H

#include "ServerSocket.h"
#include "StoreThread.h"

class Server
{
private:
    ServerSocket server_socket;
    StoreThread store_thread;
public:
    void dataMine();
};

#endif // SERVER_H
