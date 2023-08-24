#include "CA.h"
#include "US.h"
#include "DC.h"

void setup()
{
	//init drivers
	US_init();
	DC_init();

	CA_state = 	STATE(CA_waiting);
	US_state = 	STATE(US_busy);
	DC_state = 	STATE(DC_idle);
}


void main()
{
	setup();

	while(1)
	{
		US_state();
		CA_state();
		DC_state();
		for(int i =0 ; i<10000; i++);
		
	}
}