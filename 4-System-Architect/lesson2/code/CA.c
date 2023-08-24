#include "CA.h"

static int CA_speed  = 0;
static int CA_distance = 0;
static int CA_threshold  = 0;

int CA_state_id;

void US_set_distance(int d)
{
	CA_distance = d;
	CA_state = (CA_distance > CA_threshold) ? STATE(CA_driving) : STATE(CA_waiting);
	printf("US------------DISTANCE=%d------------> CA\n", CA_distance);

}

void (*CA_state)();
int US_get_distance_random (int l, int r, int count);

STATE_define(CA_driving)
{
	//state name
	CA_state_id = CA_driving;
	printf("CA_driving state d = %d speed = %d \n", CA_distance, CA_speed);
	//state action
	CA_speed = 30;
	DC_motor(CA_speed);


	
}

STATE_define(CA_waiting)
{

	//state name
	CA_state_id = CA_waiting;
	printf("CA_waiting state d = %d speed = %d \n", CA_distance, CA_speed);
	//state action
	CA_speed = 0;
	DC_motor(CA_speed);
}

