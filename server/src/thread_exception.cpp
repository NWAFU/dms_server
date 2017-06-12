#include"header/thread_exception.h"



ThreadException::ThreadException()
{
    ServerException("线程异常");
}

ThreadException::ThreadException(const std::string& msg)
{
    ServerException(msg);
}

