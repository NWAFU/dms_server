#include <iostream>
#include <header/server_socket.h>
#include <header/server.h>

using namespace std;

int main()
{
    // Test for module of data-receive
    ServerSocket server_socket;
    server_socket.acceptClient();
    return 0;
}

