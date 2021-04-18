#ifndef __POC_INIT_H__
#define __POC_INIT_H__
/*
typedef enum
{
	ZPOC_INIT_START,
	ZPOC_INIT_CREATE,
	ZPOC_INIT_ZPPP,
	ZPOC_INIT_SETUP,
	ZPOC_INIT_AUTHER,
	ZPOC_INIT_FINISH,

	ZPOC_INIT_WAITING
}ZPOC_INIT_STAGE;
*/
typedef enum
{
	ZPOC_LOGIN_OFFLINE,
	ZPOC_LOGIN_LOGING,
	ZPOC_LOGIN_ONLINE,
	ZPOC_LOGIN_OUTING
} ZPOC_LOGIN_STATUS;

#define INIT_ZPPP_CNT_MAX 20
#define INIT_SETUP_CNT_MAX 10
#define INIT_AUTH_CNT_MAX 10

void init_sys_par_reset(void);
void init_load_audio(void);

int8 zpoc_read_cfg_from_file(char *pFileName, stPocSetPar *pSetDat);
extern int dsi_netctrl_thread_create(void);
int8 init_display_login_status(ZPOC_LOGIN_STATUS euSta, stUser *pUser);

//extern char AT_SYS_LOG_STR[100];
/*
typedef struct
{
	ZPOC_INIT_STAGE stage;
}stInitPar;
*/
//pb_decode.o pb_encode.o ptt.pb.o zpoc.o oemECHAT.o protocal.o State.o Codeco.o Init.o Work.o
#endif
