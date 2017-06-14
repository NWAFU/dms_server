#ifndef LOG_DAO_H
#define LOG_DAO_H
#include "header/data.h"

class LogDao
{
public:
    LogDao();
    ~LogDao();
    virtual void insert(MatchedLogRec const& matched_log) = 0;
};

#endif // LOG_DAO_H
