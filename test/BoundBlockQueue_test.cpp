#include "BoundBlockQueue.h"
#include "mthread.h"

void testPush(C0223::BBQueue<int> &que){
    for(int i=0;i<100;i++)
        que.put(i);
}
void testPop(C0223::BBQueue<int> &que){
    while(true)
        std::cout<<"get:"<<que.get()<<std::endl;
}

int main(){
    C0223::BBQueue<int> que(10);
    THD::mThread t1(std::bind(testPush,std::ref(que)),"push");
    THD::mThread t2(std::bind(testPop,std::ref(que)),"pop");
    t1.start();
    t2.start();
    t1.join();
    t2.join();
    return 0;
}