#include "server_main.h"
#include "state.h"
#include "tcp_service.h"
#include "tompoc.h"

#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
int gMsqid = -1;

int main(int argc, char **argv)
{
    int iRes;
    poc_msg_type_t iMsg;

    gMsqid = msgget(ftok("/data", 100), IPC_CREAT | 0777);

    tcp_recv_thread_create();

    while (1)
    {

        iRes = msgrcv(gMsqid, &iMsg, sizeof(iMsg), 0, 0);
        if (iRes == -1)
        {
            printf("recv error:%d!!\r\n", errno);
            continue;
        }

        STATE_MgrProcessMsg(0, 0, &iMsg);
    }

    STATE_MgrTerminate();
}
