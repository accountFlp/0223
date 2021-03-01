/**
 * @file mMutex.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include "mMutex.h"
#include <sys/syscall.h>   /* For SYS_xxx definitions */
#include <unistd.h>
namespace mMUTEX
{   
    void MutexLock::lock(){
        pthread_mutex_lock(&mutex);
    }
    void MutexLock::unlock(){
        pthread_mutex_unlock(&mutex);
    }
    pid_t MutexLock::getHolder(){
        return hold_;
    }
    void MutexLock::setHolder(pid_t p){
        hold_=p; 
    }
    bool MutexLock::isCurrentHolder(){
        return hold_==syscall(SYS_gettid);
    }
    pthread_mutex_t* MutexLock::getMutex(){
        return &mutex;
    }

} // namespace mMUTEX
