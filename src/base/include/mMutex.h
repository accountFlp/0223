#pragma once
#include <pthread.h>
#include <iostream>
#include <sys/syscall.h>   /* For SYS_xxx definitions */
#include <unistd.h>
namespace BASE
{   
    class MutexLock{
        public:
            explicit MutexLock():hold_(0){
                pthread_mutex_init(&mutex, NULL);
            }
            ~MutexLock(){
                pthread_mutex_destroy(&mutex);
            }
            void lock(){
                pthread_mutex_lock(&mutex);
            }
            void unlock(){
                pthread_mutex_unlock(&mutex);
            }
            pid_t getHolder(){
                return hold_;
            }
            void setHolder(pid_t p){
                hold_=p; 
            }
            bool isCurrentHolder(){
                return hold_==syscall(SYS_gettid);
            }
            pthread_mutex_t* getMutex(){
                return &mutex;
            }
        private:
            pid_t hold_;
            pthread_mutex_t mutex;
    };
} // namespace mMUTEX