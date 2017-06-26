#ifndef ORACLE_DAO_H
#define ORACLE_DAO_H
#include "log_dao.h"

class OracleDao:public LogDao
{
public:
    OracleDao();
    ~OracleDao();
    void insert(MatchedLogRec const& matched_log);
};

#endif // ORACLE_DAO_H
