#include "TimerQueue.h"
#include <string.h>
namespace net{
    //创建timefd
    int creatTimefd(){
        int fd=timerfd_create(CLOCK_MONOTONIC,
                                 TFD_NONBLOCK | TFD_CLOEXEC);
        if(fd<0){
            std::cout<<"creat timefd error"<<std::endl;
            return -1;
        }
        return fd;
    }
    //设置timefd 
    /*int timerfd_settime(int fd, int flags,const struct itimerspec *new_value,struct itimerspec *old_value);
    // struct timespec {            
    // time_t tv_sec;    /* Seconds */            
    // long   tv_nsec;  /* Nanoseconds */      
    // };        

    // struct itimerspec {            
    // struct timespec it_interval;  /* Timer interval */            
    // struct timespec it_value;     /* Initial expiration */        
    // }; 
    // */
    // int timerfd_settime(int fd, int flags,
    //                        const struct itimerspec *new_value,
    //                        struct itimerspec *old_value);

    // int timerfd_gettime(int fd, struct itimerspec *curr_value);

    int setTimefd(int timerfd,BASE::mTimestamp when){
        struct itimerspec new_value;
        struct itimerspec old_value;
        memset(&new_value,0,sizeof(struct itimerspec));
        memset(&old_value,0,sizeof(struct itimerspec));
        //非重复定时器
        new_value.it_interval.tv_nsec=0;
        new_value.it_interval.tv_sec=0;
        //定时时间
        new_value.it_value.tv_nsec=when.getMicrosecond()%100000*1000;
        new_value.it_value.tv_sec=when.getMicrosecond()/100000;
        int ret=timerfd_settime(timerfd,0,&new_value,&old_value);//flag 0:绝对时间 1:相对时间
        if(ret<0){
            std::cout<<"set timerfd error"<<std::endl;
        }
        return ret;
    }
    //定时when-new时执行,
    void resetTimerfd(int timerfd,BASE::mTimestamp when){
        setTimefd(timerfd,when.getMicrosecond()-BASE::mTimestamp::now().getMicrosecond());
    }
    void readTimerfd(int timerfd){
        int64_t temp;
        int ret=read(timerfd,&temp,sizeof(temp));
        if(ret<0){
            std::cout<<"read timerfd error"<<std::endl;
        }else{
            std::cout<<"read timerfd:time:"<<temp<<"time now:"<<BASE::mTimestamp::now().getMicrosecond()<<std::endl;
        }
    }

    mTimerQueue::mTimerQueue(EventLoop* loop)\
    :loop_(loop),
    timerfd_(creatTimefd()),
    timerfdChannel_(loop,timerfd_),
    timers(),
    callingExpiredTimers_(false){
            timerfdChannel_.setReadCallback(std::bind(&mTimerQueue::handleRead,this));
            timerfdChannel_.enableRead();
        }
    mTimerQueue::~mTimerQueue(){
        timerfdChannel_.disableAll();
        timerfdChannel_.remove();
        close(timerfd_);
        for(const Element& timer : timers_){
            delete timer.second;
        }
    }
    TimerId mTimerQueue::addTimer(TimerCallback cb,BASE::mTimestamp when,double interval){
        mTimer *timer=new mTimer(cb,when,interval);
        loop_->runInThread(std::bind(&mTimerQueue::addTimerInloop,this,timer));
        return TimerId(timer,timer->getTimerId());
    }
    void mTimerQueue::cancelTimer(TimerId tm){
        loop_->runInThread(std::bind(&mTimerQueue::cancelInloop,this,tm));
    }
    //loop内添加定时器，避免线程竞争,优点，不用加锁，会不会加的不及时呢？
    void mTimerQueue::addTimerInloop(mTimer* timer){
        bool earliestChanged=insert(timer);
        if(earliestChanged){
            resetTimerfd(timerfd_,timer->getTimestamp());
        }
    }
    //loop内删除定时器，同上
    void mTimerQueue::cancelInloop(TimerId tm){
        ActiveTimer timer(tm.timer_,tm.ID);

    }
    //处理超时
    void mTimerQueue::handleRead(){}
    //所有超时的定时器
    std::vector<mTimerQueue::Element> mTimerQueue::getExp(BASE::mTimestamp now){}
    //删除或重置定时器
    void mTimerQueue::reset(const std::vector<Element>& expired,BASE::mTimestamp now){}
    //set中添加定时器
    bool mTimerQueue::insert(mTimer* timer){}

}