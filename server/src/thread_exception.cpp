#include"header/thread_exception.h"
using std::string;

ThreadException::ThreadException()
{
    ServerException("线程异常");
}

ThreadException::ThreadException(const string& msg) : ServerException(msg)
{

}

