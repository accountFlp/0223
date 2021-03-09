#include "mthread.h"
#include<unistd.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */
void test(){
    std::cout<<"curthread:"<<BASE::currentPthreadID_<<"hello test"<<std::endl;
}
class A{
    public:
        void  pr(){std::cout<<"pt"<<std::endl;std::cout<<BASE::currentPthreadID_<<std::endl;}
};
int main(){
    A a;
    BASE::mThread t1(test,"test");
    BASE::mThread t2(std::bind(&A::pr,&a),"test");
    BASE::mThread t3(test,"test");
    t1.start();
    t2.start();
    t3.start();
    std::cout<<"count:"<<t1.getCount()<<std::endl;
    std::cout<<"name:"<<t1.name()<<std::endl;
    std::cout<<"current"<<syscall(SYS_gettid)<<"thradid"<<t1.getTid()<<std::endl;
    sleep(2);
    return 0;
}