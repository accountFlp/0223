/**
 * @file mEventLoop.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma  once
#include <vector>
#include <memory>
#include "mPoll.h"
#include "mChannel.h"
#include <mutex>
#include <functional>
#include "mthread.h"
namespace net
{
    class Channel;
    class mPOLL;
    
    class EventLoop{
        public:
            typedef std::function<void()>  Func;
            EventLoop();
            ~EventLoop();
            void loop();
            int update(Channel *c);
            int remove(Channel *c);
            void stop();
            void handleEventFdWrite();//发送唤醒信号
            void handleEventFdRead();//处理唤醒信号

            void runInThread(Func func);
            void runPendingFunc();
            bool isInCurrentThread();
            int  getEventfd()const {return eventFd_;}
            pid_t currentThreadId()const {return tid;}

        private:

            
            bool isRunning;
            bool isRunPendingFunc;

            std::unique_ptr<mPOLL> poller;
            typedef std::vector<Channel*> ChannelLists;
            ChannelLists activeChannels;

            pid_t tid;
            pthread_t threadId;
            int eventFd_;
            std::unique_ptr<Channel> wakeUpChannel;
            std::mutex pendingFuncMutex;
            std::vector<Func> dePendingFunc;

    };
} // namespace net
