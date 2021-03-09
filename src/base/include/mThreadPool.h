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
namespace BASE
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
            BASE::MutexLock mutex_;
            BASE::mCondition  notFull;
            BASE::mCondition  notEmpty;
            std::deque<Func> task;
            std::vector<std::unique_ptr<BASE::mThread>> threads;
    };
} // namespace C0223
