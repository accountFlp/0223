#pragma once
#include "timer.h"
namespace net{
    class TimerId{
        public:
            TimerId(mTimer* timer,int64_t sequence):timer_(timer),ID(sequence) {}
            ~TimerId();
        private:
            friend class mTimerQueue;
            mTimer *timer_;
            int64_t ID;
    };
}