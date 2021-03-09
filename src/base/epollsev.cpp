#include "epollsev.h"
namespace EPOLL{
    int EPOLLSEV::init(){
        epfd=epoll_create(1024);
        evs.reserve(1024);
        listenfd=creatListenfd(ip.c_str(),port);
        if(listenfd<0){
            logger_.error("creat listernfd error");
            return -1;
        }
        addfd(listenfd,EPOLLIN);
        return 0;
    }
    int EPOLLSEV::start(){
        while(true){
            int nready=epoll_wait(epfd,&*evs.begin(),1,-1);
            if(nready<0){
                if(errno==EINTR)continue;
                logger_.error("epoll wait error errno:{}",errno);
            }
            for(int i=0;i<nready;i++){
                if(evs[i].data.fd==listenfd){
                    logger_.debug("handle accept");
                    handleAccept();
                }else{
                    logger_.debug("handle recive");
                    if(evs[i].events &(EPOLLRDHUP | EPOLLHUP | EPOLLERR)){
                        logger_.warn("client close");
                        removefd(evs[i].data.fd);
                    }
                    handleEventIn(evs[i].data.fd);
                }
            }
        }

        
    }
    int EPOLLSEV::addfd(int fd,int event){
        struct epoll_event ev;
        ev.data.fd=fd;
        ev.events=event;
        epoll_ctl(epfd,EPOLL_CTL_ADD,fd,&ev);
        if((uint)fd>fds.size())fds.resize(fd*2);
        if(fds[fd].fd!=0){
            logger_.warn("fd already in use");
        }
        fds[fd].fd=fd;
        fds[fd].t=ev;
        return 0;
    }
    int EPOLLSEV::removefd(int fd){
        epoll_ctl(epfd,EPOLL_CTL_DEL,fd ,&fds[fd].t);
        close(fd);
        if((uint)fd>fds.size()){
            logger_.error("fd is out of fds");
            return -1;
        }
        fds[fd].fd=0;
        return 0;
    }
    int EPOLLSEV::handleAccept(){
        struct epoll_event ev;
        struct sockaddr_in peeraddr;
        int peeraddrlen;
        int fd=accept4(listenfd,(struct sockaddr*)&peeraddr,(socklen_t*)&peeraddrlen,SOCK_NONBLOCK|SOCK_CLOEXEC);
        if(fd<0){
            logger_.error("accept client error:{}",strerror(errno));
            return -1;
        }
        ev.data.fd=fd;
        ev.events=EPOLLIN | EPOLLHUP;
        epoll_ctl(epfd,EPOLL_CTL_ADD,fd,&ev);
        if(fds.size()<(uint)fd){
            logger_.info("fds is not enough fd:{}",fd);
            fds.resize(fd*2);
        }
        fds[fd].fd=fd;
        fds[fd].t=ev;
        return 0;
    }
    int EPOLLSEV::handleEventIn(int fd){
        char buff[1024];
        read(fd,buff,sizeof(buff));
        write(fd,buff,sizeof(buff));
        return 0;
    }
    int EPOLLSEV::handleEventOut(){
        return 0;
    }
}