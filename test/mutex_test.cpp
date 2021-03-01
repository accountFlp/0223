#include "mMutex.h"
#include <mutex>
#include <vector>
#include <memory>
#include "mthread.h"
#include "mTimestamp.h"
#define MaxNum  10*1024*1024
mMUTEX::MutexLock mu;
std::vector<int> vec;

void test(){
    for(int i=0;i<MaxNum;i++){
        std::lock_guard<mMUTEX::MutexLock> l(mu);
        vec.push_back(i); 
    }
}

int main(){
    TMS::mTimestamp start=0;
    vec.reserve(MaxNum*10);
    mu.lock();
    mu.unlock();
    {
        std::lock_guard<mMUTEX::MutexLock> l(mu);
    }
    start=TMS::mTimestamp::now();
    for(int i=0;i<MaxNum;i++){
        vec.push_back(i);
    }
    std::cout<<"time:"<< TMS::timeDifference(TMS::mTimestamp::now(),start) <<std::endl;
    start=time(NULL);
    for(int i=0;i<MaxNum;i++){
        std::lock_guard<mMUTEX::MutexLock> l(mu);
        vec.push_back(i); 
    }
    std::cout<<"time:"<< TMS::timeDifference(TMS::mTimestamp::now(),start) <<std::endl;
    for(int i=0;i<10;i++){
        vec.clear();
        std::vector<std::unique_ptr<THD::mThread>> vecThreads;
        vecThreads.clear();
        start=TMS::mTimestamp::now();
        for(int j=0;j<i;j++){
            vecThreads.push_back(std::unique_ptr<THD::mThread>(new THD::mThread(test,"123")));
            vecThreads.back()->start();
        }
        for(int j=0;j<(int)vecThreads.size();j++){
            vecThreads[j]->join();
        }
        std::cout<<"time count:"<< TMS::timeDifference(TMS::mTimestamp::now(),start) <<std::endl;
    }

    
    return 0;
}