#pragma once
#include "mPoll.h"
#include <sys/epoll.h>
#include "mEventLoop.h"

namespace net{
    class Epollpoll:public mPOLL{
        public:
            Epollpoll(EventLoop *ev);
            ~Epollpoll();
            void update(Channel *ch);
            void update(int opt,Channel *ch);
            void remove(Channel *ch);
            void POLL(int timeout,ChannelList &activeList);
        private:
            typedef std::vector<struct epoll_event> EventList;
            void fileActiveChannel(int nready,ChannelList &activeList);
            int epollfd;
            int MaxNum;
            
            EventList events;
            
    };
}