#ifndef DB_EXCEPTION_H
#define DB_EXCEPTION_H
#include"server_exception.h"
using std::string;

//4.数据库异常
class DBException:public ServerException
{
public:
    DBException();
    DBException(const string& msg);
};

#endif // DB_EXCEPTION_H
