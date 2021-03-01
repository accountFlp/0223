#include "mthread.h"
#include<unistd.h>
void test(){
    std::cout<<"hello test"<<std::endl;
}
class A{
    public:
        void  pr(){std::cout<<"pt"<<std::endl;}
};
int main(){
    A a;
    THD::mThread t1(test,"test");
    THD::mThread t2(std::bind(&A::pr,&a),"test");
    THD::mThread t3(test,"test");
    t1.start();
    t2.start();
    t3.start();
    std::cout<<"count:"<<t1.getCount()<<std::endl;
    std::cout<<"name:"<<t1.name()<<std::endl;
    sleep(2);
    return 0;
}