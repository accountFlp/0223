#pragma once
#include <unordered_map>
#include <vector>
#include "mChannel.h"
#include "mEventLoop.h"
namespace net{
    class Channel;
    class EventLoop;
    class mPOLL{
        public:
            typedef std::vector<Channel*>  ChannelList;  
            mPOLL(EventLoop *ev):ev(ev){}
            virtual ~mPOLL()=default;
            virtual void update(Channel *ch)=0;
            virtual void remove(Channel *ch)=0;
            virtual void POLL(int timeout,ChannelList &activeList)=0;
        protected:
            EventLoop *ev;
            std::unordered_map<int,Channel*> channels;//用于优化查找速度
    };
}