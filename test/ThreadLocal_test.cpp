#include  "mThreadLocal.h"
#include "mthread.h"
C0223::mThreadLocal<int> a;

void test(){
    std::cout<<a.Value()<<std::endl;
    a.Value()++;
}
int main(){
    a.Value()=0;
    BASE::mThread t1(test,"thread1");
    t1.start();
    t1.join();
    std::cout<<a.Value()<<std::endl;

    return 0;
}