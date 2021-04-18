#ifndef __ZPOC_WORK_H__
#define __ZPOC_WORK_H__

//#define	ZPOC_UDP_HB_TIME	4*5
#define ZPOC_UDP_HB_TIME 6 * 5

#define ZPOC_TCP_HB_TIME 20 * 5

#define ZPOC_SYNC_TIME 3600 * 3 * 5

#define ZPOC_MEM_GET_MIC_MAX_TIME 10 * 5

#define ZPOC_INVITE_TIMEOUT 10 * 5

#define ZPOC_REGISTER_CHECK_TIMER 1 * 5

#define ZPOC_ENTER_SLEEP_MAX_CNT 60 * 5 //120*5//180*5

#define ZPOC_NETWORK_TYPE_CHK_TIMER 5 * 5

typedef struct
{
	uint16 udptimer;
	uint16 tcptimer;

	uint16 synctimer;
} stWorkPar;

void work_push_evrc_ctl_msg(unsigned char ucType, unsigned char ucReason);
int8 work_evrc_ctrl_process(void);
int8 work_voice_test(void);
int8 work_pcm_test(void);
int work_create_record_send_task();

#endif
