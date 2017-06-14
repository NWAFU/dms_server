#include "header/client_thread.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

ClientThread::ClientThread(int conn_fd) : conn_fd(conn_fd)
{

}

ClientThread::~ClientThread()
{

}

void ClientThread::task(void *arg)
{
    conn_fd = socket(AF_INET, SOCK_STREAM, 0);

}
