#include "tcp_service.h"

#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BACKLOG 10
#define PORT 345

#define TCP_SND_SIZE 1024
#define TCP_REC_SIZE 10240
unsigned char tcprecvbuf[TCP_REC_SIZE];

void str_echo(int sockfd)
{
    int ret, sock_error = 0;

again:
    ret = recv(sockfd, tcprecvbuf, sizeof(tcprecvbuf), 0);
    if (ret > 0)
    {
        printf("recv data: [%d] length:%d\r\n", tcprecvbuf[4], ret);
    }
    else if (ret == 0)
    {
        printf("*** peer closed ***\r\n");
    }
    else
    {
        printf("recv() error\n");
        exit(1);
    }
}

void *tcp_recv_process(void *arg)
{
    pid_t childpid;

    int listenfd, connectfd;
    struct sockaddr_in server;
    struct sockaddr_in client;
    socklen_t addrlen;

    //socket()确定一个socket文件描述符
    //AF_INET 决定了要用ipv4地址（32位的）与端口号（16位的）的组合
    //SOCK_STREAM 表示建立TCP链接；SOCK_DGRAM 表示建立UDP链接
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Creating  socket failed.");
        exit(1);
    }

    //一般来说，一个端口释放后会等待两分钟之后才能再被使用，SO_REUSEADDR是让端口释放后立即就可以被再次使用。
    //server程序总是应该在调用bind()之前设置SO_REUSEADDR套接字选项。
    //SO_REUSEADDR允许启动一个监听服务器并捆绑其众所周知端口，即使以前建立的将此端口用做他们的本地端口的连接仍存在。这通常是重启监听服务器时出现，若不设置此选项，则bind时将出错。
    int opt = SO_REUSEADDR;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listenfd, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        perror("Binderror.");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) == -1)
    {
        perror("listen()error\n");
        exit(1);
    }

    while (1)
    {
        addrlen = sizeof(client);
        if ((connectfd = accept(listenfd, (struct sockaddr *)&client, &addrlen)) == -1)
        {
            perror("accept()error\n");
            exit(1);
        }

        if ((childpid = fork()) == 0)
        {                        /* child process */
            close(listenfd);     /* close listening socket */
            str_echo(connectfd); /* process the request */
            //printf("Yougot a connection from cient's ip is %s, prot is %d\n", inet_ntoa(client.sin_addr), htons(client.sin_port));
            // send(connectfd, "Welcometo my server.\n", 22, 0);
            exit(0);
        }
        close(connectfd); /* parent closes connected socket */
    }
    close(listenfd);
}

int tcp_recv_thread_create(void)
{
    pthread_t ntid;

    return pthread_create(&ntid, NULL, tcp_recv_process, NULL);
}