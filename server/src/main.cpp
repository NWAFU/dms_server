#include <iostream>
#include <header/server_socket.h>
#include <header/server.h>

using namespace std;

int main()
{
    cout << "Hello, World!" << endl;
    ServerSocket ss;
    ss.acceptClient();
    return 0;
}

