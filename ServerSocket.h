#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

class ServerSocket
{
private:
    int socket_fd;
    int port;
public:
    void acceptClient();
};

#endif // SERVERSOCKET_H
