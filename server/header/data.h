#ifndef DATA_H
#define DATA_H

#include <unistd.h>//pid_t
#include <fstream>//ofstream

using std::ifstream;
using std::ofstream;

struct LogRec
{
    char log_name[32];
    pid_t pid;
    long log_time;
    char log_ip[32];
    short log_type;
};

struct MatchedLogRec
{
    char log_name[32];
    pid_t pid;
    long login_time;
    long logout_time;
    long duration;
    char log_ip[32];
    friend ifstream & operator>>(ifstream & fin,MatchedLogRec & matched_log);
    friend ofstream & operator<<(ofstream & fout,MatchedLogRec const & matched_log);
};

#endif // DATA_H
