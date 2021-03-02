/**
 * @file mThreadLocal.h
 * @author your name (you@domain.com)
 * @brief 存储线程局部数据
 * @version 0.1
 * @date 2021-03-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <thread>
namespace C0223
{
    template<typename T>
    class mThreadLocal{
        public:
            mThreadLocal(){
                pthread_key_create(&key,dele);
            }
            ~mThreadLocal(){
                pthread_key_delete(key);
            }
            T &Value(){
                T* t=static_cast<T*>(pthread_getspecific(key));
                if(!t){
                    T* temp=new T();    
                    pthread_setspecific(key,temp);
                    t=temp;
                }
                return *t;
            }
        private:
            static void dele(void *x){
                T* temp=static_cast<T*>(x);
                delete temp;
            }
            pthread_key_t key;

    };
} // namespace C0223
