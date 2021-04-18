#include "state_init.h"
#include "state.h"

short init_state_init(unsigned int arg1)
{
	return 0;
}

short init_state_term(void)
{
	return 0;
}

short init_state_proc(unsigned int set_sigs, unsigned int arg1, void *pArg2)
{
	return 0;
}

POC_STATE InitStateMgr =
	{
		init_state_init,
		init_state_term,
		init_state_proc};
