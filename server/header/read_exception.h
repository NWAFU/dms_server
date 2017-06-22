#ifndef READ_EXCEPTION_H
#define READ_EXCEPTION_H

#include "server_exception.h"

using std::string;

//2.读取异常
class ReadException:public ServerException
{
public:
    ReadException();
    ReadException(const string& msg);
};

#endif // READ_EXCEPTION_H


