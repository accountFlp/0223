/**
 * @file mBlockingQueue.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "mMutex.h"
#include "mCondition.h"
#include <deque>
#include <mutex>
namespace C0223
{
    template<typename T>
    class BQueue{
        public:
            BQueue():mutex_(),cond_(mutex_){}
            // ~BQueue(){}
            T get();
            void push(T t);
            int getSize();

        private:
            mMUTEX::MutexLock mutex_;
            CND::mCondition cond_;
            std::deque<T> que;
    };
    
    template<typename T>
    T BQueue<T>::get(){
        std::lock_guard<mMUTEX::MutexLock> l(mutex_);
        while(que.empty()){
            cond_.wait();
        }    
        T front(que.front());
        que.pop_front();
        return front;
    }

    template<typename T>
    void BQueue<T>::push(T t){
        std::lock_guard<mMUTEX::MutexLock> l(mutex_);
        que.push_back(t);
        cond_.notify();
    }
    template<typename T>
    int BQueue<T>::getSize(){
        std::lock_guard<mMUTEX::MutexLock> l(mutex_);
        return que.size();
    }

} // namespace 0223

