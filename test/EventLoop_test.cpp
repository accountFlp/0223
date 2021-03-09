#include "mChannel.h"
#include "mEventLoop.h"
#include "mthread.h"
#include <unistd.h>
#include "mEventLoopThread.h"
#include "mException.h"
#include <signal.h>


void test(net::EventLoop* &ev){
    net::EventLoop loop;
    ev=&loop;
    std::cout<<"thread 1"<<std::endl;
    ev->loop();
}
void handler(int sig){
    std::cout<<"signal:"<<sig<<std::endl;
    BASE::stackTrace(true);
    exit(0);
}
int main(){
    signal(SIGSEGV,handler);
    //std::cout<<BASE::currentPthreadID_<<std::endl;
    net::EventLoop *ev;
    BASE::mThread t1(std::bind(test,std::ref(ev)),"thread1");
    t1.start();
    sleep(10);
    std::cout<<"eventfd"<<ev->getEventfd()<<std::endl;
    ev->stop();
    t1.join();
    return 0;
}