#ifndef __SETING_H__
#define __SETING_H__

#define ZPOC_UDP_SETING_TIME 4 * 5

typedef struct
{
	struct sockaddr_in sin;

	uint16 udptimer;
	uint16 synctimer;
} stSetingPar;

unsigned short crc_fun(unsigned char *pbuf, unsigned short numc);

#endif
