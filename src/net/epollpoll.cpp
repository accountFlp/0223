#include "epollpoll.h"
#include <string.h>
namespace net{
    Epollpoll::Epollpoll(EventLoop *ev):mPOLL(ev),MaxNum(32),events(MaxNum){
        epollfd=epoll_create(1024);
    }
    Epollpoll::~Epollpoll(){}
    void Epollpoll::update(Channel *ch){
        int index=ch->getIndex();
        std::cout<<"epoll update"<<std::endl;
        if(index<0){
            update(0,ch);
        }else if(index==0){
            update(1,ch);
        }else{
            update(-1,ch);
        }
    }
    void Epollpoll::update(int opt,Channel *ch){
        int index=ch->getIndex();
        struct epoll_event event;
        event.events=ch->events();
        event.data.ptr=ch;
        if(opt==0){
            //add new channel
            epoll_ctl(epollfd,EPOLL_CTL_ADD,ch->getfd(),&event);
            ch->setIndex(0);
            channels[ch->getfd()]=ch;
        }
        if(opt==1){
            epoll_ctl(epollfd,EPOLL_CTL_MOD,ch->getfd(),&event);
            ch->setIndex(0);
            channels[ch->getfd()]=ch;
        }
        if(opt==-1){
            epoll_ctl(epollfd,EPOLL_CTL_DEL,ch->getfd(),&event);
            ch->setIndex(-1);
            channels.erase(ch->getfd());
        }
    }
    void Epollpoll::remove(Channel *ch){
        update(-1,ch);
    }
    void Epollpoll::POLL(int timeoutMs,ChannelList &activeList){
        //events.clear();
        int nready=epoll_wait(epollfd,&*events.begin(),static_cast<int>(events.size()),timeoutMs);
        if(nready<0){
                std::cout<<"nready:"<<nready<<" errno:"<<errno<<" "<<strerror(errno)<<std::endl;
        }
        if(nready==0){
            std::cout<<"nothing happens"<<std::endl;
        }
        if(nready>0){
            if(nready==MaxNum){
                MaxNum*=2;
                events.resize(MaxNum);
            }
            std::cout<<"nready:"<<nready<<std::endl;
            fileActiveChannel(nready,activeList);
        }
    }
    void Epollpoll::fileActiveChannel(int nready,ChannelList &activeList){
        for(int i=0;i<nready;i++){
            static_cast<Channel*>(events[i].data.ptr)->setRevents(events[i].events);
            activeList.push_back(static_cast<Channel*>(events[i].data.ptr));
        }
    }
}