#include <iostream>
#include "mChannel.h"
#include <poll.h>
namespace net{
    const int Channel::kNONE=0;
    const int Channel::kPOLLIN=POLLIN|POLLPRI;
    const int Channel::kPOLLOUT=POLLOUT;
    Channel::Channel(EventLoop *ev,int fd):\
        ev(ev),fd(fd),isHandleEvent(false),isAdd(false),index(-1){}
    Channel::~Channel(){}
    void Channel::handleEvent(){
        isHandleEvent=true;
        if((revent & POLLHUP) && !(revent & POLLIN)){
            closeCallback();
        }
        if(revent & POLLNVAL){
            std::cout<<"操作的是非文件描述符"<<std::endl;
        }
        if(revent &(POLLERR|POLLNVAL)){
            errCallback();
        }
        if(revent &(POLLIN | POLLPRI | POLLRDHUP)){
            readCallback();
        }
        if(revent & POLLOUT){
            writeCallback();
        }
        isHandleEvent=false;
    }
    void Channel::update(){
        std::cout<<"channel update"<<std::endl;
        isAdd=true;
        ev->update(this);
    }
    void Channel::remove(){
        isAdd=false;
        ev->remove(this);
    }
}