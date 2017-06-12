#ifndef DB_EXCEPTION_H
#define DB_EXCEPTION_H

#include"server_exception.h"

//4.数据库异常
class DBException:public ServerException
{
public:
    DBException();
    DBException(const string& msg);
};

#endif

#endif // DB_EXCEPTION_H
