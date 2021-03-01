#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h" // support for loading levels from the environment variable
#include <poll.h>
#include <vector>
#include <string>
namespace F_poll{
    class pollSev
    {
    private:
        /* data */
        spdlog::logger  logger_;
        int listenFD;
        int port;
        int nready;
        std::string ip;
        std::vector<struct pollfd> pollfds;
    public:
        pollSev(spdlog::logger,std::string ip,int port);
        ~pollSev();
        int init();
        int start();
        int creatListenFD(const char *addr,int port);
        inline int addfd(int fd,int event);
        inline int removefd(std::vector<struct pollfd>::iterator &it);
        int handleAccept();
        int handleEventIn(std::vector<struct pollfd>::iterator &it);
        int handleEventOut();
        
   };
    
    
}