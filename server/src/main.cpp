#include <iostream>
#include "header/log_queue.h"
#include "header/server.h"

// test for store thread
#include "header/store_thread.h"
#include "header/file_dao.h"

using namespace std;

// define global variable 'log_queue'
LogQueue log_queue = LogQueue();

int main()
{
//    Server server;
//    server.dataMine();
    FileDao fd;
    for (int i = 0; i < 16; i++)
    {
        MatchedLogRec mlg = {"majun", 1, 2324, 234324, 4324, "172.29.23.110"};
        log_queue << mlg;
        MatchedLogRec mlg1;
        log_queue >> mlg1;
        fd.insert(mlg);
    }

//    FileDao fd;
//    StoreThread *st = new StoreThread(fd);
//    st->start();
//    int t;
//    cin >> t;
    return 0;
}

