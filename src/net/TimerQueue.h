#pragma once
#include <set>
#include <functional>
#include "mChannel.h"
#include "mTimestamp.h"
#include "timer.h"
#include "TimerId.h"
#include <sys/timerfd.h>
namespace net{
    class mTimerQueue{
        public:

            mTimerQueue(EventLoop* loop);
            ~mTimerQueue();
            TimerId addTimer(TimerCallback cb,BASE::mTimestamp when,double interval);
            void cancelTimer(TimerId tm);

        private:
            typedef std::pair<BASE::mTimestamp,mTimer*> Element;
            typedef std::set<Element> TimerList;
            typedef std::pair<mTimer*,int64_t> ActiveTimer;
            typedef std::set<ActiveTimer> ActiveTimerSet;
            //loop内添加定时器，避免线程竞争,优点，不用加锁，会不会加的不及时呢？
            void addTimerInloop(mTimer* timer);
            //loop内删除定时器，同上
            void cancelInloop(TimerId tm);
            //处理超时
            void handleRead();
            //所有超时的定时器
            std::vector<Element> getExp(BASE::mTimestamp now);
            //删除或重置定时器
            void reset(const std::vector<Element>& expired,BASE::mTimestamp now);
            //set中添加定时器
            bool insert(mTimer* timer);
            //主循环
            EventLoop *loop_;
            //定时器描述符
            const int timerfd_;
            //定时器描述符通道，用于超时时产生课读时间
            Channel timerfdChannel_;
            //存放所有的定时器
            TimerList timers_;
            //活跃的定时器
            ActiveTimerSet timers;
            //是否在处理超时定时器
            bool callingExpiredTimers_;
            //需要取消的定时器
            ActiveTimerSet cancelingTimers_;

    };
}