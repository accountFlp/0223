#include "pollpoll.h"
#include <algorithm>
#include <assert.h>
#include <errno.h>
#include <iostream>
#include <string.h>
namespace net{
    void pollpoll::update(Channel *ch){
        std::cout<<"pollpoll update"<<std::endl;
        int index=ch->getIndex();
        if(index<0){
            //新的channel -->add
            struct pollfd temp;
            temp.fd=ch->getfd();
            temp.events=ch->events();
            temp.revents=0;
            pollfds.push_back(temp);
            ch->setIndex(pollfds.size()-1);
            channels[ch->getfd()]=ch;
        }else{
            //old channel -->update
            assert(index>=0);
            pollfds[index].events=ch->events();
            channels[ch->getfd()]=ch;
        }
        std::cout<<"pollfds size:"<<pollfds.size()<<std::endl;
    }
    void pollpoll::remove(Channel *ch){
        int index=ch->getIndex();
        channels.erase(ch->getfd());
        if(index==pollfds.size()-1){
            pollfds.pop_back();
        }else{
            //swap  cur and end
            int indexAtEnd=pollfds.size()-1;
            pollfds[index]=pollfds[pollfds.size()-1];
            pollfds.pop_back();
            channels[pollfds[index].fd]->setIndex(index);
        }
    }
    void pollpoll::POLL(int timeoutMs,ChannelList &activeList){
        std::cout<<"start poll"<<std::endl;
        int nReady=poll(&*pollfds.begin(),pollfds.size(),timeoutMs);
        if(nReady<0){
            std::cout<<"err occur,errno:"<<errno<<" "<<strerror(errno)<<std::endl;
        }
        if(nReady==0){
            std::cout<<"nothing happen"<<std::endl;
        }
        if(nReady>0){
            fillActiveChannelList(nReady,activeList);
        }
    }
    void pollpoll::fillActiveChannelList(int nReady,ChannelList &activeList){
        std::cout<<"fill active channel list:"<<nReady<<std::endl;
        for(auto &temp:pollfds){
            if(temp.revents>0)
                activeList.push_back(channels[temp.fd]);
        }
    }
}