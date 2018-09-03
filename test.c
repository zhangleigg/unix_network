#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc,const char** argv){
    printf("program start!\n");
    
    static pid_t pid;
    int mark=0;

    if(pid==fork()){
        printf("This is father process! pid:%d\n",pid);
    }else if(pid==0){
        printf("This is child process! pid:%d\n",pid);
        mark=1;
    }else{
        printf("Error! Code:%d\n",pid);
    }
    printf("Done!\n");

    return 0;
}