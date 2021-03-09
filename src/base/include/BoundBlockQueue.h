/**
 * @file BoundBlockQueue.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <boost/circular_buffer.hpp>
#include <iostream>
#include "mMutex.h"
#include "mCondition.h"
#include <mutex>

namespace C0223
{
    template< typename T>
    class BBQueue{
        public:
            BBQueue(int size):mutex_(),notEmpty(mutex_),fullCond(mutex_),que(size){}
            ~BBQueue(){}
            void put(T t);
            T get();
            int getSize();
            int getCap();

        private:
            BASE::MutexLock mutex_;
            BASE::mCondition  notEmpty;
            BASE::mCondition  fullCond;
            boost::circular_buffer<T> que;
    };
    template<typename T>
    void BBQueue<T>::put(T t){
        std::lock_guard<BASE::MutexLock> l(mutex_);
        while(que.full()){
            std::cout<<"full"<<std::endl;
            fullCond.wait();
        }
        que.push_back(t);
        notEmpty.notify();
    }
    template<typename T>
    T BBQueue<T>::get(){
        std::lock_guard<BASE::MutexLock> l(mutex_);
        while(que.empty()){
            std::cout<<"empty"<<std::endl;
            notEmpty.wait();
        }
        T t(que.front());
        que.pop_front();
        fullCond.notify();
        return t;
    }
    template<typename T>
    int BBQueue<T>::getSize(){
        std::lock_guard<BASE::MutexLock> l(mutex_);
        return que.size();
    }
    template<typename T>
    int BBQueue<T>::getCap(){
        std::lock_guard<BASE::MutexLock> l(mutex_);
        return que.capacity();
    }

} // namespace C0223
