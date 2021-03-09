#pragma once
#include <pthread.h>
#include "mMutex.h"
namespace BASE
{
    class mCondition{
        public:
            mCondition(MutexLock& mutex):mutex_(mutex){
                pthread_cond_init(&cond_,NULL);
            };
            ~mCondition(){
                pthread_cond_destroy(&cond_);
            }
            int wait(){
                pthread_cond_wait(&cond_,mutex_.getMutex());
                return 0;
            }
            int notify(){
                pthread_cond_signal(&cond_);
                return 0;
            }
            int notifyAll(){
                pthread_cond_broadcast(&cond_);
                return 0;
            }
        private:
            BASE::MutexLock& mutex_;
            pthread_cond_t cond_;
    };
} // namespace CND
