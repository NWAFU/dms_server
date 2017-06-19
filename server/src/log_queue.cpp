#include "header/log_queue.h"
using std::list;

LogQueue::LogQueue()
{
    pthread_mutex_init(&client_store_mutex, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);
}

LogQueue& LogQueue::operator <<(MatchedLogRec const& matched_log)
{
    log_record.push_back(matched_log);
    return *this;
}

LogQueue& LogQueue::operator >>(MatchedLogRec& matched_log)
{
    pthread_mutex_lock(&client_store_mutex);
    matched_log = log_record.front();
    log_record.pop_front();
    pthread_mutex_unlock(&client_store_mutex);
    return *this;
}

LogQueue::~LogQueue()
{
    pthread_mutex_destroy(&client_store_mutex);
    pthread_cond_destroy(&not_full);
    pthread_cond_destroy(&not_empty);
}
