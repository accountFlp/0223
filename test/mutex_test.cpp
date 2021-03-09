#include "mMutex.h"
#include <mutex>
#include <vector>
#include <memory>
#include "mthread.h"
#include "mTimestamp.h"
#define MaxNum  10*1024*1024
BASE::MutexLock mu;
std::vector<int> vec;

void test(){
    for(int i=0;i<MaxNum;i++){
        std::lock_guard<BASE::MutexLock> l(mu);
        vec.push_back(i); 
    }
}

int main(){
    BASE::mTimestamp start=0;
    vec.reserve(MaxNum*10);
    mu.lock();
    mu.unlock();
    {
        std::lock_guard<BASE::MutexLock> l(mu);
    }
    start=BASE::mTimestamp::now();
    for(int i=0;i<MaxNum;i++){
        vec.push_back(i);
    }
    std::cout<<"time:"<< BASE::timeDifference(BASE::mTimestamp::now(),start) <<std::endl;
    start=time(NULL);
    for(int i=0;i<MaxNum;i++){
        std::lock_guard<BASE::MutexLock> l(mu);
        vec.push_back(i); 
    }
    std::cout<<"time:"<< BASE::timeDifference(BASE::mTimestamp::now(),start) <<std::endl;
    for(int i=0;i<10;i++){
        vec.clear();
        std::vector<std::unique_ptr<BASE::mThread>> vecThreads;
        vecThreads.clear();
        start=BASE::mTimestamp::now();
        for(int j=0;j<i;j++){
            vecThreads.push_back(std::unique_ptr<BASE::mThread>(new BASE::mThread(test,"123")));
            vecThreads.back()->start();
        }
        for(int j=0;j<(int)vecThreads.size();j++){
            vecThreads[j]->join();
        }
        std::cout<<"time count:"<< BASE::timeDifference(BASE::mTimestamp::now(),start) <<std::endl;
    }

    
    return 0;
}