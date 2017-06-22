#ifndef SAVE_EXCEPTION_H
#define SAVE_EXCEPTION_H

#include "server_exception.h"

using std::string;

//5.保存异常
class SaveException:public ServerException
{
public:
    SaveException();
    SaveException(const string& msg);
};

#endif // SAVE_EXCEPTION_H


