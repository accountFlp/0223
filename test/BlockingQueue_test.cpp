#include "mBlockingQueue.h"
#include "mthread.h"
#include <unistd.h>

int testPush(C0223::BQueue<int> &bq){
    for(int i=0;i<100;i++){
        bq.push(i);
        
    }
    return 0;
}
int testPop(C0223::BQueue<int> &bq){
    while(true){
        std::cout<<"size:"<<bq.getSize()<<"get:"<<bq.get()<<std::endl;
    }
    return 0;
}

int main(){
    C0223::BQueue<int> bq;
    BASE::mThread t1(std::bind(testPush,std::ref(bq)),"pro");
    BASE::mThread t2(std::bind(testPop,std::ref(bq)),"cons");
    t1.start();
    t2.start();
    t1.join();
    t2.join();
    return 0;
}