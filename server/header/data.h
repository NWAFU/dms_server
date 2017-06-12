#ifndef DATA_H
#define DATA_H

#include <unistd.h>//pid_t

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
};

#endif // DATA_H
