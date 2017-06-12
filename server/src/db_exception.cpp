#include"header/db_exception.h"

using namespace std;

DBException::DBException()
{
    ServerException("数据库异常");
}

DBException::DBException(const string& msg)
{
    ServerException(msg);
}

