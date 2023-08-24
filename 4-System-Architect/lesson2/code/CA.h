#include "states.h"
#include "stdio.h"
#include "stdlib.h"


enum{
	CA_waiting,
	CA_driving
};
extern int CA_state_id; 

STATE_define(CA_driving);
STATE_define(CA_waiting);

extern void (*CA_state)();