#ifndef DATA_H
#define DATA_H

#include <unistd.h>//pid_t
#include <fstream>//ofstream
#include <iostream>//ostream

using std::ifstream;
using std::ofstream;
using std::ostream;

struct LogRec
{
    char log_name[32];
    pid_t pid;
    int log_time;
    char log_ip[32];
    short log_type;
};

struct MatchedLogRec
{
    char log_name[32];
    pid_t pid;
    int login_time;
    int logout_time;
    int duration;
    char log_ip[32];
    friend ifstream & operator>>(ifstream & fin,MatchedLogRec & matched_log);
    friend ofstream & operator<<(ofstream & fout,MatchedLogRec const & matched_log);
    friend ostream & operator<<(ostream & out,MatchedLogRec const & matched_log);
};

#endif // DATA_H
