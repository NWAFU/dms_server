#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H
#include <string>

using std::string;

class ServerSocket
{
private:
    int socket_fd;
    int client_sockfd;
    short server_port;      // 4096
    char server_ip[32];
public:
    ServerSocket();
    ServerSocket(short server_port, char *server_ip);
    ~ServerSocket();
    void acceptClient();
};

#endif // SERVER_SOCKET_H
