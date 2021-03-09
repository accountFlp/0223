#pragma once
#include "mMutex.h"
#include "mCondition.h"
#include <mutex>

namespace MCD
{
    class mCountDown{
        public:
            mCountDown(int c):mutex(),cond(mutex),count(c){}
            ~mCountDown(){}
            void wait(){
                std::lock_guard<BASE::MutexLock> l(mutex);
                if(count>0){
                    cond.wait();
                }
            }
            void countDown(){
                std::lock_guard<BASE::MutexLock> l(mutex);
                if(count>0)count--;
                if(count==0)cond.notifyAll();
            }
        private:
            BASE::MutexLock mutex;
            BASE::mCondition cond;
            int count;

    };
} // namespace MCD
