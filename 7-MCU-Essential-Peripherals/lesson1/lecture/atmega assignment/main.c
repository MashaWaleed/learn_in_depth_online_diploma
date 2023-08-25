/*
 * Assignment.c
 *
 * Created: 8/22/2023 11:40:47 PM
 * Author : mw296
 */ 

#include "MemMap.h"
#include "bitManip.h"
#include "util/delay.h"
#define F_CPU 8000000UL

void GPIO_init()
{
	//d5,6,7 LEDs
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
	
	//buzzer d4
	SET_BIT(DDRD,4);
}

void myWait()
{
	_delay_ms(1000);
}

int main(void)
{
	GPIO_init();
    /* Replace with your application code */
    while (1) 
    {
		SET_BIT(PORTD,5);
		myWait();
		CLR_BIT(PORTD, 5);
		SET_BIT(PORTD,6);
		myWait();
		CLR_BIT(PORTD, 6);
		SET_BIT(PORTD,7);
		myWait();
		CLR_BIT(PORTD, 7);
		SET_BIT(PORTD, 4);
		myWait();
		CLR_BIT(PORTD, 4);
    }
}

