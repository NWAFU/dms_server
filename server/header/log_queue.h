#ifndef LOG_QUEUE_H
#define LOG_QUEUE_H
#include "data.h"
#include <pthread.h>
#include <list>
using std::list;

class LogQueue
{
private:
    list<MatchedLogRec> log_record;
    pthread_mutex_t client_store_mutex;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;
//    int max_size;
//    int cur_size;
public:
    LogQueue();
    ~LogQueue();
//    int getMaxSize();
//    int getCurSize();
    LogQueue& operator <<(MatchedLogRec const& matched_log);
    LogQueue& operator >>(MatchedLogRec& matched_log);
};

extern LogQueue log_queue;
#endif // LOG_QUEUE_H
