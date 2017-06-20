#ifndef STORE_THREAD_H
#define STORE_THREAD_H
#include "header/log_dao.h"
#include "header/base_thread.h"

class StoreThread : public BaseThread
{
private:
    LogDao& log_dao;
public:
    StoreThread(LogDao& log_dao);
    ~StoreThread();
    void run();
};

#endif // STORE_THREAD_H
