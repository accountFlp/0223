#include <iostream>
#include "mException.h"
int main (){
    try{
        std::cout<<"start test exception"<<std::endl;
        BASE::mexception e("test");
        throw  e;
    }
    catch(BASE::mexception &e){
        std::cout<<e.what()<<std::endl;
        std::cout<<e.mstackTrace()<<std::endl;
    }
    catch(std::exception &e){
        e.what();
    }
    catch(...){
        std::cout<<"...."<<std::endl;
    }
    std::cout<<"test exception end"<<std::endl;
    return 0;
}