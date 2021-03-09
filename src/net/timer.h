#pragma once
#include <stdint.h>
#include <functional>
#include "mEventLoop.h"
#include "mChannel.h"
#include "mTimestamp.h"
namespace net{
    typedef std::function<void()> TimerCallback;
    class mTimer{
        public:
            //typedef std::function<void()>  Func;
            mTimer(TimerCallback &cb,BASE::mTimestamp when,double interval):
                cb(cb),t(when),interval(interval),isRepeat(interval>0),currentTimerId(TimerId){
                    TimerId.fetch_add(1);
                }
            ~mTimer(){}
            void run(){
                cb();
            }
            double getInterval()const {return interval;}
            BASE::mTimestamp getTimestamp()const {return t;}
            bool  isTimerRepeat(){return isRepeat;}
            int64_t getTimerId(){return currentTimerId;}
            void restart(){t=addTime(t,interval);}
        private:
            const TimerCallback cb;
            BASE::mTimestamp t;
            double interval;
            bool isRepeat;
            const int64_t currentTimerId;
            static std::atomic<int64_t> TimerId;
    };
}