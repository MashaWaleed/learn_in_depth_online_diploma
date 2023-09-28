#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_

#define F_CPU 8000000UL

#include "../../Services/Platform_Types.h"
#include "../../Services/bitManip.h"
#include "../../Services/RegisterMap.h"
#include <util/delay.h>

#include "../../MCAL/GPIO/GPIO.h"


//keypad Information
#define R0				0
#define R1				1
#define R2				2
#define R3				3
#define C0				4
#define C1				5
#define C2				6
#define C3              7

#define KEYPAD_PORT     PORTD
#define KEYPAD_PIN      PIND
#define KEYPAD_DDR      DDRD 


#define KEYPAD_NOT_PRESSED     '~'


void keypad_Init();
char keypad_GetKey();

#endif /* KEYPAD_DRIVER_H_ */