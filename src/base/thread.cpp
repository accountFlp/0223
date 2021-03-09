#include "mthread.h"
#include <unistd.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */
#include <assert.h>
#include <string>
#include <sys/prctl.h>
#include <string>


namespace BASE
{
    __thread pid_t currentPthreadID_=0;
    __thread const char* currentPthreadName;
    std::atomic<int32_t> mThread::count(0);

    void catchTid(){
        if(currentPthreadID_==0){
            currentPthreadID_=syscall(SYS_gettid);
        }
    }

    mThread::mThread(mThreadFunc func,const char* tName):\
    status_(initted),mFunc(func),threadName(tName){
        if(tName==NULL)setDefaultThreadName();
        count.fetch_add(1);
    }
    mThread::~mThread(){
        if(status_==runing)pthread_detach(pthreadID_);
        count.fetch_sub(1);
    }
    pid_t mThread::getTid(){
        return pid_;
    }
    void* mThread::run(void*arg){
        prctl(PR_SET_NAME, static_cast<mThread*>(arg)->name());
        static_cast<mThread*>(arg)->pid_=syscall(SYS_gettid);
        currentPthreadID_=syscall(SYS_gettid);
        currentPthreadName=static_cast<mThread*>(arg)->name();
        static_cast<mThread*>(arg)->mFunc();  
        return NULL;
    }
    void mThread::start(){
        pthread_t pt;
        int ret=pthread_create(&pthreadID_,NULL,run,(void*)this);
        status_=runing;
    }
    void mThread::join(){
        assert(pthreadID_!=0);
        this->status_=joined;
        pthread_join(pthreadID_, NULL);
    }
    int mThread::getCount(){
        return count.load();
    }  
    void mThread::setDefaultThreadName(){
        threadName=(std::string("thread")+std::to_string(count.load())).c_str();
    }
} // namespace THD
