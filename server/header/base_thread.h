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
    static virtual void *task(void *arg) = 0;
    void run();
};

#endif // BASE_THREAD_H
