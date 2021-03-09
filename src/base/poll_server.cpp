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
namespace F_poll{
    pollSev::pollSev(spdlog::logger m_logger,std::string ip,int port)
    :logger_(std::move(m_logger)),
    ip(ip),
    port(port)
    {
    }
    pollSev::~pollSev()
    {
    }
    int pollSev::init(){
        listenFD=creatListenFD(ip.c_str(),port);
        if(listenFD<0){
            logger_.error("init failed creat listenfd error");
            return -1;
        }
        addfd(listenFD,POLLIN);
    }
    int pollSev::addfd(int fd,int event){
        struct pollfd m_fd;
        m_fd.fd=fd;
        m_fd.events=event;
        pollfds.push_back(std::move(m_fd));
        return 0;
    }
    int pollSev::start(){
        while(true){
            nready=poll(&*pollfds.begin(),pollfds.size(),-1);
            logger_.debug("nready :{}",nready);
            if(nready==-1){
                if(errno==EAGAIN){
                    continue;
                }
                logger_.error("poll error");
                return -1;
            }
            if(nready==0){
                logger_.debug("nready==0");
                continue;
            }
            if(pollfds[0].revents & POLLIN){
                logger_.info("get new connect");
                handleAccept();
                --nready;
            }
            // for_each(pollfds.begin(), pollfds.end(), [](struct poll val)->void {  if(val.revent &　POLLIN){handleEventIn();}});
            for(auto i=pollfds.begin()+1;i!=pollfds.end();i++){
                if(i->revents & POLLIN){
                    handleEventIn(i);
                    --nready;
                }     
            }
        }
    }
    int pollSev::removefd(std::vector<struct pollfd>::iterator &it){
        close(it->fd);
        pollfds.erase(it);  
    }
    int pollSev::handleAccept(){
        struct sockaddr_in peeraddr;
        int peeraddrlen;
        logger_.debug("get new accept");
        int fd=accept4(listenFD,(struct sockaddr*)&peeraddr,(socklen_t*)&peeraddrlen,SOCK_NONBLOCK|SOCK_CLOEXEC);
        if(fd<0){
            logger_.error("accept new client error {}",strerror(errno));
            return -1;
        }
        addfd(fd,POLLIN);
        return 0;
    }
    int pollSev::handleEventIn(std::vector<struct pollfd>::iterator &it){
        logger_.debug("handle event in");
        char buff[1024]={};
        int ret=read(it->fd,buff,sizeof(buff));
        if(ret<0){
            logger_.error("read data error");
            removefd(it);
            it --;
            return -1;
        }
        if(ret==0){
            logger_.info("client closed");
            removefd(it);
            it --; 
            return 0;         
        }
        write(it->fd,buff,sizeof(buff));
        logger_.debug("handle event  int success");
        return 0;
    }
//在发送缓冲区满时（发送返回<0,errno==EAGAIN），将POLLOUT放入events中，发送缓冲区有空闲时会调用函数，发送完成后将POLLOUT移出events中
    int pollSev::handleEventOut(){}

    int pollSev::creatListenFD(const char *addr,int port){
        int ret=0;
        int fd=socket(AF_INET,SOCK_STREAM|SOCK_NONBLOCK|SOCK_CLOEXEC,0);
        if(fd<0){
            logger_.error("creat socket error");
            return -1;
        }
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
  