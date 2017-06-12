#ifndef STORE_THREAD_H
#define STORE_THREAD_H
#include "header/log_dao.h"

class StoreThread
{
private:
    LogDao &log_dao;
public:
    StoreThread(LogDao &);
    ~StoreThread();
};

#endif // STORE_THREAD_H
