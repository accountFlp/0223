#include "mSingleton.h"
#include "mthread.h"

void test(){
    std::cout<<"tid:"<<THD::currentPthreadID_<<"name"<<THD::currentPthreadName<<std::endl;
}
class Dtest{
    public:
        Dtest(){
            std::cout<<"Dtest construct"<<std::endl;
        }
        ~Dtest(){
            std::cout<<"Dtest deconstruct"<<std::endl;
        }
        void setName(std::string n){
            name=n;
        }
        std::string getName(){
            return name;
        }
    private:
        std::string name;
};
class NoDtest{
    public:
        void no_destroy();
        NoDtest(){
            std::cout<<"Nodtest construct"<<std::endl;
        }
        ~NoDtest(){
            std::cout<<"Nodtest destruct"<<std::endl;
        }
};

int main(){
    {
        C0223::mSingleton<Dtest>::instance().setName("111");
        std::cout<<"name"<<C0223::mSingleton<Dtest>::instance().getName()<<std::endl;
        C0223::mSingleton<NoDtest>::instance();
    }

    return 0;
}