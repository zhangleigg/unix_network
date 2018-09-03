#include<sys/socket.h>
#include<errno.h>

void Listen(int fd,int backlog){
    char* ptr;

    if((ptr=getenv("LISTENQ"))!=0)
        backlog=atoi(ptr);
    if(Listen(fd,backlog)<0)
        err_sys("Listen error");
}
