/**
 * @file thread.h
 * @author your name (you@domain.com)
 * @brief 封装一个thread类，需要记录，
 *        tid   线程id
 *        pid   线程pid
 *        threadname  线程名字  
 *        func   线程执行函数
 *        ppid   主线程pid
 *        running 运行状态
 *        join    线程回收
 * @version 0.1
 * @date 2021-02-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <iostream>
#include <functional>
#include <algorithm>
#include <atomic>
#include <thread>

namespace THD
{
    extern thread_local pthread_t currentPthreadID_;
    extern thread_local std::string currentPthreadName;
    class mThread{
        typedef std::function<void()> mThreadFunc;
        enum status{initted,runing,stoped,joined};
        public:
            explicit mThread(mThreadFunc func,const char* tName);
            ~mThread();
            void start();
            void join();
            static int  getCount();
            pid_t getTid();
            status getStatus();  
            std::string name(){return threadName;}
            
        private:
            void setDefaultThreadName();
            pthread_t pthreadID_;
            pid_t pid_;
            status status_;
            std::string threadName;
            mThreadFunc mFunc; 
            static void*run(void*);
            static std::atomic<int32_t>  count;
    };
} // namespace MTHREAD
