#pragma once
#include <pthread.h>
namespace mMUTEX
{   
    class MutexLock{
        public:
            explicit MutexLock():hold_(0){
                pthread_mutex_init(&mutex, NULL);
            }
            ~MutexLock(){
                pthread_mutex_destroy(&mutex);
            }
            void lock();
            void unlock();
            pid_t getHolder();
            void setHolder(pid_t p);
            bool isCurrentHolder(); 
            pthread_mutex_t* getMutex();
        private:
            pid_t hold_;
            pthread_mutex_t mutex;
    };
} // namespace mMUTEX