
#ifndef __TOMPOC_H
#define __TOMPOC_H

typedef enum
{
    ZPOC_MSG_AT_CMD = 1,
    ZPOC_MSG_NET_WORK_REDAY,
    ZPOC_MSG_PPP_OPENED,
    ZPOC_MSG_GET_IP_FAILD,
    ZPOC_MSG_TCP_CONNECTED,
    ZPOC_MSG_TCP_DISCONNECT,
    ZPOC_MSG_TCP_DATA,
    ZPOC_MSG_UDP_CONNECTED,
    ZPOC_MSG_UDP_DATA,
    ZPOC_MSG_IVOC_INREAD,
    ZPOC_MSG_PCM_INREAD,
    ZPOC_MSG_EVRC_CTL,
    ZPOC_MSG_HB_TIMER,
    ZPOC_MSG_TTS_FINISH,
    ZPOC_MSG_SYSTEM_WAKEUP,
    ZPOC_MSG_REC_PLAY_START,
    ZPOC_MSG_REC_PLAY_FINISH
} POC_MSG_TYPE;

typedef struct
{
    POC_MSG_TYPE msg_type; //队列消息的类型，AT or LOG or NET消息
    void *message;         //消息的内容
    unsigned short int message_length;
} poc_msg_type_t;

#endif