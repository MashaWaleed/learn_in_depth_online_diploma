#include "states.h"
#include "stdio.h"
#include "stdlib.h"


enum{
	DC_idle,
	DC_busy
};
extern int DC_state_id; 

STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init(); 

extern void (*DC_state)();