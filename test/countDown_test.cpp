#include "mCountDown.h"
#include <iostream>
#include <unistd.h>
#include "mthread.h"
#include <signal.h> 
#include "mException.h"
#include <vector>
#include <memory>
#include <algorithm>
void testFunc(MCD::mCountDown &mc){
    mc.wait();
    std::cout<<"test"<<std::endl;
    sleep(10);   
}
void handler(int sig){
    std::cout<<EXP::stackTrace(true)<<std::endl;
    exit(0);
}
//MCD::mCountDown mc(1);
int main(){
    signal(SIGSEGV,handler);
    MCD::mCountDown mc(1);
    std::vector<std::shared_ptr<THD::mThread> > vc;
    for(int i=0;i<10;i++){
        std::cout<<"start thread"<<std::endl;
        vc.push_back(std::shared_ptr<THD::mThread>(new THD::mThread(std::bind(testFunc,std::ref(mc)),(std::string("thread")+std::to_string(i)).c_str())));
        //THD::mThread t1(std::bind(testFunc,std::ref(mc)),(std::string("thread")+std::to_string(i)).c_str());
        vc.back()->start();
    }
    sleep(10);
    std::cout<<"start wait"<<std::endl;
    mc.countDown();
    for_each(vc.begin(),vc.end(),[](std::shared_ptr<THD::mThread> t){t->join();});

    return 0;
}