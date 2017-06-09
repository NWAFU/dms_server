#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H

class ServerSocket
{
private:
    int socket_fd;
    int port;
public:
    void acceptClient();
};

#endif // SERVER_SOCKET_H
