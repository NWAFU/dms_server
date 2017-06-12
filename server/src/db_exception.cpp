#include"header/db_exception.h"


DBException::DBException()
{
    ServerException("数据库异常");
}

DBException::DBException(const std::string& msg) : ServerException(msg)
{

}

