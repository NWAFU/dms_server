#include <iostream>
#include "header/log_queue.h"
#include "header/server.h"

using namespace std;

// define global variable 'log_queue'
LogQueue log_queue = LogQueue();

int main()
{
    Server server;
    server.dataMine();
    return 0;
}

