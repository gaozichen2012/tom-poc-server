#include "server_main.h"
#include "tcp_service.h"
#include "state.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    tcp_recv_thread_create();

    while (1)
    {

        iRes = msgrcv(gMsqid, &iMsg, sizeof(iMsg), 0, 0);
        if (iRes == -1)
        {
            if (errno != EINTR)
                _DEBUG("recv error:%d!!\r\n", errno);

            continue;
        }

        STATE_MgrProcessMsg(iMsg.enMsgType, iMsg.usMsgLen, iMsg.pMsg);

        if (iMsg.pMsg != NULL && iMsg.usMsgLen != 0)
        {
            free(iMsg.pMsg);
        }
    }

    STATE_MgrTerminate();
}
