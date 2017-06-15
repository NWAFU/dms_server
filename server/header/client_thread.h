#ifndef CLIENT_THREAD_H
#define CLIENT_THREAD_H
#include "base_thread.h"

class ClientThread : public BaseThread
{
private:
    int conn_fd;
public:
    ClientThread(int conn_fd);
    ~ClientThread();
    void run();
};

#endif // CLIENT_THREAD_H
