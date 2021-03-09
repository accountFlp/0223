#include "mEventLoopThread.h"
#include <functional>
namespace net{
    mEventLoopThread::mEventLoopThread():mutex(),cond_(mutex),
            t1(std::bind(&mEventLoopThread::threadFunc,this),"thread1"),
            ev(NULL){
                std::cout<<BASE::getCurrentPthreadID()<<std::endl;
            }
    mEventLoopThread::~mEventLoopThread(){
        std::cout<<"~mEventloopThread"<<std::endl;
        t1.join();
        if(ev!=NULL)delete ev;
    }
    EventLoop* mEventLoopThread::startLoop(){
        t1.start();
        while(ev==NULL){
            {
                std::cout<<"wait for event loop init"<<std::endl;
                std::lock_guard<BASE::MutexLock> lock(mutex);
                cond_.wait();
            }
            std::cout<<"got event loop *"<<std::endl;
            return ev;
        }
    }
    void mEventLoopThread::threadFunc(){
        std::cout<<"start threadfunc"<<std::endl;
        ev=new EventLoop();
        {
            std::lock_guard<BASE::MutexLock> lock(mutex);
            cond_.notify();
        }
        ev->loop();
    }
}