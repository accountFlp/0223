/**
 * @file mSingleton.h
 * @author your name (you@domain.com)
 * @brief  单例类模板，通过改模板创建任意类型的单例对象
 * @version 0.1
 * @date 2021-03-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
namespace C0223
{
    template<typename T>
    struct has_no_destroy
    {
        /* data */
        template<typename C> static char test(decltype(&C::no_destroy));
        template<typename C> static int32_t test(...);
        const static bool value=sizeof(test<T>(0))==1;
    };
    template<typename T>
    class mSingleton{
        public:
            mSingleton()=delete;
            ~mSingleton()=delete;
            static T& instance(){
                pthread_once(&once_,&mSingleton::init);
                assert(value_!=NULL);
                return *value_;
            }
        private:
            static void init(){
                value_=new T();
                if(!has_no_destroy<T>::value)
                    ::atexit(destroy);
            }
            static void destroy(){
                
                if(value_)delete value_;
                value_=NULL;
            }
            static pthread_once_t once_;
            static T* value_;
    };
    template<typename T>
    pthread_once_t mSingleton<T>::once_=PTHREAD_ONCE_INIT;

    template<typename T>
    T* mSingleton<T>::value_=NULL;
} // namespace C0223
