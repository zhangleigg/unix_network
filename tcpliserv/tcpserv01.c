#include <unp.h>

int main(int argc, const char ****argv)
{
    int linstenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;
    linstenfd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    Bind(linstenfd, (SA *)&servaddr, sizeof(servaddr));
    Listen(linstenfd, LISTENQ);
    for (;;)
    {
        clilen = sizeof(cliaddr);
        connfd = Accept(linstenfd, (SA *)&cliaddr, &clilen);
        if ((childpid = fork()) == 0)
        {
            Close(linstenfd);
            str_echo(connfd);
            exit(0);
        }
        Close(connfd);
    }
}