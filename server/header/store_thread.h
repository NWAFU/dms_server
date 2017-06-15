#ifndef STORE_THREAD_H
#define STORE_THREAD_H
#include "header/file_dao.h"
#include "header/oracle_dao.h"
#include "header/base_thread.h"

class StoreThread : public BaseThread
{
private:
    FileDao &file_dao;
    OracleDao &oracle_dao;
public:
    StoreThread(FileDao &, OracleDao &);
    ~StoreThread();
    void run();
};

#endif // STORE_THREAD_H
