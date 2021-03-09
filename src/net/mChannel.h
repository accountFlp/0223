/**
 * @file mChannel.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include "mEventLoop.h"
#include <functional>
namespace net
{
    class EventLoop;
    class Channel{
        public:
            typedef  std::function<void()> ChannelCallBack;
            Channel(EventLoop *ev,int fd);
            ~Channel();
            void handleEvent();

            void setReadCallback(ChannelCallBack &cb){readCallback=cb;}
            void setWriteCallback(ChannelCallBack &cb){writeCallback=cb;}
            void setCloseCallback(ChannelCallBack &cb){closeCallback=cb;}
            void setErrCallback(ChannelCallBack &cb){errCallback=cb;}

            void setReadCallback(ChannelCallBack &&cb){readCallback=cb;}
            void setWriteCallback(ChannelCallBack &&cb){writeCallback=cb;}
            void setCloseCallback(ChannelCallBack &&cb){closeCallback=cb;}
            void setErrCallback(ChannelCallBack &&cb){errCallback=cb;}

            void enableRead(){event|=kPOLLIN;update();}
            void disableRead(){event&=~kPOLLOUT;update();}
            void enableWrite(){event|=kPOLLOUT;update();}
            void disableWrite(){event&=~kPOLLOUT;update();}
            void disableAll(){event=0;update();}

            bool isEnableRead()const {return event & kPOLLIN;}
            bool isEnableWrite()const {return event & kPOLLOUT;}
            bool isEnableNone()const {return event==0;}
            
            bool isAddToEvent(){return isAdd;}
            bool isHandlingEvent(){return isHandleEvent;}

            int getfd()const {return fd;}
            int getIndex()const {return index;}
            void setRevents(int events){revent=events;}
            void setIndex(int i){index=i;}
            int events(){return event;}
            int revents(){return revent;}
            void remove();
        private:
            void update();
            ChannelCallBack readCallback;
            ChannelCallBack writeCallback;
            ChannelCallBack closeCallback;
            ChannelCallBack errCallback;

            static const int kNONE;
            static const int kPOLLIN;
            static const int kPOLLOUT;

            int event;
            int revent;

            EventLoop *ev;
            const int fd;
            bool isHandleEvent;
            bool isAdd;
            int index;

    };
} // namespace net
