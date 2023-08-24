#include "US.h"

static int US_distance = 0;

int US_state_id;

void (*US_state)();
int US_get_distance_random (int l, int r, int count);

void US_init()
{
	//nint drivers
	printf("US_inint");
}

STATE_define(US_busy)
{

	//state name
	US_state_id = US_busy;

	//state action
	

	US_distance = US_get_distance_random(45, 55, 1);
	//event check
	
	printf("US_busy state d = %d \n", US_distance);
	US_set_distance(US_distance); 

	US_state = STATE(US_busy);

}

int US_get_distance_random (int l, int r, int count)
{
	int i;
	for(i = 0; i<count; i++){
		int rand_num = 	(rand() % (r-l+1)) + l;
		return rand_num;
	}
}
