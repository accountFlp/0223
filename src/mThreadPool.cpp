#include "mThreadPool.h"
#include <mutex>
namespace C0223
{
    void mThreadPool::start(){
        isRunning=true;
        for(int i=0;i<threadSize;i++){
            threads.push_back(std::unique_ptr<THD::mThread>(new THD::mThread(std::bind(&mThreadPool::run,this),(std::string("thread")+std::to_string(i)).c_str())));
            threads.back()->start();
        }
    }
    mThreadPool::~mThreadPool(){
        stop();
    }
    void mThreadPool::run(){
        while (isRunning)
        {
            std::cout<<"running task"<<std::endl;
            Func f=getTask();
            if(f!=NULL)f();
        }
        std::cout<<"running stop:"<<"threadid"<<THD::currentPthreadID_<<"threadName"<<THD::currentPthreadName<<std::endl;
    }
    mThreadPool::Func mThreadPool::getTask(){
        std::lock_guard<mMUTEX::MutexLock> l(mutex_);
        while(task.empty() && isRunning){
            std::cout<<"wait for task"<<std::endl;
            notEmpty.wait();
        }
        if(!task.empty()){
            Func func(task.front());
            task.pop_front();
            notFull.notify();
            return func;
        }else{
            return NULL;
        }
    }
    void mThreadPool::putTask(const Func &t){
        std::lock_guard<mMUTEX::MutexLock> l(mutex_);
        while(isFull() && isRunning){
            std::cout<<"wait for empty"<<std::endl;
            notFull.wait();
        }
        task.push_back(t);
        notEmpty.notify();
    }
    bool mThreadPool::isFull(){
        return task.size()==queueSize;
    }
    bool mThreadPool::isEmpty(){
        return task.size()==0;
    }
    bool mThreadPool::isStop(){
        return isRunning;
    }
    void mThreadPool::stop(){
       // std::lock_guard<mMUTEX::MutexLock> l(mutex_); 着里加锁会导致wait无法唤醒
        isRunning=false;
        notFull.notifyAll();
        notEmpty.notifyAll();
        for(auto &t : threads){
            t->join();
        }
    }
} // namespace C0223
