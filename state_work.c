
#include "state_work.h"
#include "state.h"

short work_state_init(unsigned int arg1)
{
	return 0;
}

short work_state_term(void)
{
	return 0;
}

short work_state_proc(unsigned int sig_set, unsigned int arg1, void *pArg2)
{
	return 0;
}

POC_STATE WorkStateMgr =
	{
		work_state_init,
		work_state_term,
		work_state_proc};
