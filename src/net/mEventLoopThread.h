#pragma once
#include "mEventLoop.h"
#include "mMutex.h"
#include "mCondition.h"
namespace net{
    class mEventLoopThread{
        public:
            mEventLoopThread();
            ~mEventLoopThread();
            EventLoop* startLoop();
        private:
            void threadFunc();
            BASE::MutexLock mutex;
            BASE::mCondition cond_;
            BASE::mThread t1;
            EventLoop *ev;

    };
}