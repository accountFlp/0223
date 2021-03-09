#include "mEventLoop.h"
#include "mPoll.h"
#include "pollpoll.h"
#include <memory>
#include <unistd.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */
#include <iostream>
#include <assert.h>
#include <sys/eventfd.h>
#include <string.h>
#include "epollpoll.h"

#define USE_EPOLL
namespace net
{
    __thread EventLoop* currentLoop;
    mPOLL* newDefaultPoller(EventLoop * ev){
        #ifdef USE_EPOLL
            return new Epollpoll(ev);
        #endif
            return new pollpoll(ev);
    }

    EventLoop::EventLoop():
        isRunPendingFunc(false),
        isRunning(false),
        poller(std::unique_ptr<mPOLL>(newDefaultPoller(this))),
        activeChannels(),
        tid(syscall(SYS_gettid)),
        threadId(pthread_self()),
        eventFd_(eventfd(0,EFD_NONBLOCK|EFD_NONBLOCK|EFD_CLOEXEC)),
        wakeUpChannel(new Channel(this,eventFd_)),
        pendingFuncMutex(),
        dePendingFunc(){
            std::cout<<"enter eventloop"<<" eventfd:"<<eventFd_<<std::endl;
            wakeUpChannel->setReadCallback(std::bind(&EventLoop::handleEventFdRead,this));
            wakeUpChannel->enableRead();
            currentLoop=this;
        }
    EventLoop::~EventLoop(){
        std::cout<<"exit eventloop"<<std::endl;
        wakeUpChannel->disableAll();
        wakeUpChannel->remove();
        close(eventFd_);
    }
    void EventLoop::loop(){
        isRunning=true;
        std::cout<<"current thread"<<BASE::getCurrentPthreadID()<<std::endl;
        assert(isInCurrentThread());
        while (isRunning)
        {
            /* code */
            std::cout<<"enter loop"<<std::endl;
            activeChannels.clear();
            poller->POLL(-1,activeChannels);
            std::cout<<"active list size:"<<activeChannels.size()<<std::endl;
            for(auto &c:activeChannels){
                std::cout<<"handle event"<<std::endl;
                c->handleEvent();
            }
            runPendingFunc();
        }
        
    }
    int EventLoop::update(Channel *c){
        std::cout<<"eventloop update"<<std::endl;
        poller->update(c);
    }
    int EventLoop::remove(Channel *c){
        poller->remove(c);
    }
    void EventLoop::stop(){
        std::cout<<"enter stop"<<std::endl;
        isRunning=false;
        handleEventFdWrite();
    }
    bool EventLoop::isInCurrentThread(){return tid==BASE::getCurrentPthreadID();}

    void EventLoop::handleEventFdWrite(){
        std::cout<<"event fd write"<<std::endl;
        int64_t temp=20;
        int ret=write(eventFd_,&temp,sizeof(temp));
        if(ret<0){
            std::cout<<"ret:"<<ret<<"errno:"<<errno<<":"<<strerror(errno)<<std::endl;
        }
    }
    void EventLoop::handleEventFdRead(){
        std::cout<<"event fd read"<<std::endl;
        int64_t temp=0;
        int ret=read(eventFd_,&temp,sizeof(temp));
        if(ret<0){
            std::cout<<"ret:"<<ret<<"errno:"<<errno<<":"<<strerror(errno)<<std::endl;
        }
    }

    void EventLoop::runInThread(Func func){
        if(isInCurrentThread()){
            func();    
        }else{
            {
                std::lock_guard<std::mutex> lock(pendingFuncMutex);
                dePendingFunc.push_back(func);
            }
            handleEventFdWrite();
        }
    }
    void EventLoop::runPendingFunc(){
        assert(isInCurrentThread());
        if(dePendingFunc.size()>0){
            std::vector<Func> temp;
            {
                std::lock_guard<std::mutex> lock(pendingFuncMutex);
                temp.swap(dePendingFunc);
            }
            for(auto &func:temp){
                func();
            } 
        }
    }

} // namespace net
