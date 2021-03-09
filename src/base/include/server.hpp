/**
 * @file server.h
 * @author your name (you@domain.com)
 * @brief server基类
 * @version 0.1
 * @date 2021-02-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h" // support for loading levels from the environment variable
#include <poll.h>
#include <vector>
#include <string>
#include <iostream>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h" // support for loading levels from the environment variable
#include <errno.h>
#include "poll_server.h"
#include <vector>
namespace BSERVER{
    template<typename T>
    class bserver{
        public:
            struct pkg{
                int fd;
                T   t;
            };
            spdlog::logger logger_;
            int listenfd;
            std::string ip;
            int port;
            int size_fds;  
            std::vector<struct pkg> fds;
        public:
            bserver(spdlog::logger logger,std::string ip,int port,int size_fds=1024):\
            logger_(logger),ip(ip),port(port),size_fds(size_fds){}
            virtual ~bserver(){}
            virtual int init()=0;
            virtual int start()=0;
            virtual int creatListenfd(const char *addr,int port);
            virtual inline int addfd(int fd,int event)=0;
            virtual inline int removefd(int fd)=0;
            virtual int handleAccept()=0;
            virtual int handleEventIn(int fd)=0;
            virtual int handleEventOut()=0;
    };
    template<typename T1>
    int bserver<T1>::creatListenfd(const char *addr,int port){
        int fd=socket(AF_INET,SOCK_STREAM|SOCK_NONBLOCK|SOCK_CLOEXEC,0);
        struct  sockaddr_in serveraddr;
        serveraddr.sin_addr.s_addr=inet_addr(addr);
        serveraddr.sin_family=AF_INET;
        serveraddr.sin_port=htons(port);
        int on=1;
        if(setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on))<0){
            logger_.error("sersockopt error {} {}",errno,strerror(errno));
            return -1;
        }
        if(bind(fd,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0){
            logger_.error("bind error {} {}",errno,strerror(errno));
            return -1;
        }
        if(listen(fd,SOMAXCONN)<0){
            logger_.error("listen error {} {}",errno,strerror(errno));
            return -1;
        }
        logger_.info("listerning ip:{} port:{}",addr,port);
        return fd;
    }
}