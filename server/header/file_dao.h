#ifndef FILE_DAO_H
#define FILE_DAO_H
#include "log_dao.h"

class FileDao:public LogDao
{
public:
    void insert(MatchedLogRec const& matched_log);
};

#endif // FILE_DAO_H
