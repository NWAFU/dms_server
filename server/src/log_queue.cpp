#include "header/log_queue.h"
using std::list;

LogQueue::LogQueue(list<MatchedLogRec> &log_record, pthread_mutex_t client_store_mutex,
                   pthread_cond_t not_full, pthread_cond_t not_empty)
                       : log_record(log_record),
                       client_store_mutex(client_store_mutex),
                       not_full(not_full),
                       not_empty(not_empty)
{

}

LogQueue& LogQueue::operator <<(MatchedLogRec const& matched_log)
{

}

LogQueue& LogQueue::operator >>(MatchedLogRec& matched_log)
{

}

