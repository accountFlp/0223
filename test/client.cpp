#include <iostream>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>

#include <netinet/in.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <sys/epoll.h> 
#include <errno.h> 
#include <string.h> 
#include <fcntl.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char **argv){
    (void)argc;
    char buff[1024];
    int sk = socket(AF_INET, SOCK_STREAM, 0); 
    if(-1 == sk) 
    { 
        return -1; 
    } 

    struct sockaddr_in sa; 
    sa.sin_family = AF_INET; 
    sa.sin_port = htons(atoi(argv[2])); 
    sa.sin_addr.s_addr=inet_addr(argv[1]);
    int ret=connect(sk,  (struct sockaddr *)&sa,(socklen_t)sizeof(sa));
    if(ret<0){
        std::cout<<"connect server error "<<strerror(errno)<<std::endl;
        return -1;
    }
    
    write(sk,"hello server",sizeof("hello server"));
    read(sk,buff,sizeof(buff));
    std::cout<<buff<<std::endl;
    return 0;
}