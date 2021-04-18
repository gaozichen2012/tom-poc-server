#include "state_setting.h"
#include "state.h"

short setting_state_init(unsigned int arg1)
{
	return 0;
}

short setting_state_term(void)
{
	return 0;
}

short setting_state_proc(unsigned int sig_set, unsigned int arg1, void *pArg2)
{
	return 0;
}

POC_STATE SettingStateMgr =
	{
		setting_state_init,
		setting_state_term,
		setting_state_proc};
