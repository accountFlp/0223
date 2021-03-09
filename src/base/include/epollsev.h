/**
 * @file epollsev.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "server.hpp"
#include <sys/epoll.h>


namespace EPOLL{
    class EPOLLSEV : public BSERVER::bserver<struct epoll_event>
    {
        public:
            EPOLLSEV(spdlog::logger logger,std::string ip,int port,int size_fds=1024):\
            bserver(logger,ip,port,size_fds){}
            ~EPOLLSEV(){}
            int init();
            int start();
        private:
            int epfd;
            std::vector<struct epoll_event>evs;
            inline int addfd(int fd,int event);
            inline int removefd(int fd);
            int handleAccept();
            int handleEventIn(int fd);
            int handleEventOut();
    };
}