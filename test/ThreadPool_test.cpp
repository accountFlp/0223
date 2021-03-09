#include "mThreadPool.h"
#include <functional>
#include <unistd.h>
#include <signal.h>
#include "mException.h"
void test(int i){
    std::cout<<"i:"<<i<<std::endl;
}
void test1(){
    std::cout<<"test"<<std::endl;
    std::cout<<"threadid"<<BASE::currentPthreadID_<<"threadName"<<BASE::currentPthreadName<<std::endl;
}
void handler(int sig){
    std::cout<<"sig"<<sig<<std::endl;
    std::cout<<"trace"<<BASE::stackTrace(true)<<std::endl;
    exit(0);
}

int main(){
    signal(SIGABRT,handler);
    BASE::mThreadPool tPoll(5,20);
    tPoll.start();
    for(int i=0;i<100;i++){
        std::cout<<"put task"<<std::endl;
        tPoll.putTask(test1);
    }
        
    sleep(10);
    std::cout<<"stop"<<std::endl;
    tPoll.stop();
    return 0;
}