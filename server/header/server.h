#ifndef SERVER_H
#define SERVER_H

#include "server_socket.h"
#include "store_thread.h"

class Server
{
private:
    ServerSocket server_socket;
    StoreThread store_thread;
public:
    void dataMine();
};


#endif // SERVER_H
