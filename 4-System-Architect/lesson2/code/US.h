#include "states.h"
#include "stdio.h"
#include "stdlib.h"


enum{
	US_busy,
};
extern int US_state_id; 

STATE_define(US_busy);

void US_init();

extern void (*US_state)();