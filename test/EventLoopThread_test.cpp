#include "mEventLoopThread.h"
void test(){
    std::cout<<"test"<<std::endl;
}
int main(){
    std::cout<<BASE::getCurrentPthreadID()<<std::endl;
    net::mEventLoopThread t1,t2,t3;
    net::EventLoop *ev1=t1.startLoop();
    net::EventLoop *ev2=t2.startLoop();
    net::EventLoop *ev3=t3.startLoop();
    ev1->runInThread(test);
    ev2->runInThread(test);
    ev3->runInThread(test);
    std::cout<<"eventloop thread id "<<ev1->currentThreadId()<<std::endl;
    std::cout<<"eventloop thread id "<<ev2->currentThreadId()<<std::endl;
    std::cout<<"eventloop thread id "<<ev3->currentThreadId()<<std::endl;
    sleep(10);
    ev1->stop();
    ev2->stop();
    ev3->stop();
    return 0;
}