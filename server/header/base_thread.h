#ifndef BASE_THREAD_H
#define BASE_THREAD_H
#include "pthread.h"
#include "unistd.h"

class BaseThread
{
private:
    pthread_t tid;
public:
    BaseThread();
    ~BaseThread();
    virtual void run() = 0;
    static void *task(void *arg)
    {
        static_cast<BaseThread*>(arg)->run();
    }
    void start();
};

#endif // BASE_THREAD_H
