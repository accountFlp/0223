/**
 * @file mThreadPoll.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <vector>
#include <functional>
#include <memory>
#include "mCondition.h"
#include "mMutex.h"
#include "mthread.h"
#include <deque>
namespace C0223
{
    class mThreadPool{
        public:
            typedef std::function<void()> Func;
            mThreadPool(int t,int queSize):threadSize(t),queueSize(queSize),mutex_(),notFull(mutex_),notEmpty(mutex_){}
            ~mThreadPool();
            void start();
            void run();
            Func getTask();
            void putTask(const Func &t);
            void stop();
            bool isFull();
            bool isEmpty();
            bool isStop();
        private:
            int threadSize;
            int queueSize; 
            bool isRunning;
            mMUTEX::MutexLock mutex_;
            CND::mCondition  notFull;
            CND::mCondition  notEmpty;
            std::deque<Func> task;
            std::vector<std::unique_ptr<THD::mThread>> threads;
    };
} // namespace C0223
