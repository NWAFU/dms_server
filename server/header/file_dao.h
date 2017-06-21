#ifndef FILE_DAO_H
#define FILE_DAO_H
#include "log_dao.h"
#include <iostream>

class FileDao:public LogDao
{
private:
    // replace with file_name
    ofstream file;
public:
    FileDao();
    ~FileDao();
    void insert(MatchedLogRec const& matched_log);
};

#endif // FILE_DAO_H
