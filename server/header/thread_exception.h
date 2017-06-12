#ifndef THREAD_EXCEPTION_H
#define THREAD_EXCEPTION_H

#include"server_exception.h"

//3.线程异常
class ThreadException:public ServerException
{
public:
    ThreadException();
    ThreadException(const string& msg);
};

#endif // THREAD_EXCEPTION_H
