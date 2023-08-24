#include "DC.h"

static int DC_speed  = 0;

int DC_state_id;

void (*DC_state)();


void DC_init()
{
	printf("DC_init \n");
	
}

void DC_motor(int s)
{
	DC_speed = s;
	DC_state = STATE(DC_busy);
	printf("CA------------SPEED=%d------------> DC\n", DC_speed);
}

STATE_define(DC_idle)
{ 
	//state name
	DC_state_id = DC_idle;

	printf("DC_idle state speed = %d \n", DC_speed);
}

STATE_define(DC_busy)
{

	//state name
	DC_state_id = DC_busy;

	DC_state = STATE(DC_idle);
	printf("DC_busy state speed = %d \n", DC_speed);
	
}
