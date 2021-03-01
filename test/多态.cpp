#include <iostream>
class animal{
    public:
    virtual void speak(){
        std::cout<<"animal speak"<<std::endl;
    }
};
class cat:public animal{
    public:
    void speak(int a){
        std::cout<<"cat speak:%d"<<a<<std::endl;
    }
    void speak(){
        std::cout<<"cat speak"<<std::endl;
    }
};
void test(animal &am){
    am.speak();
}

int main(){
    cat c;
    test(dynamic_cast<animal&>(c));
    std::cout<<"hello world"<<std::endl;
    return 0;
}