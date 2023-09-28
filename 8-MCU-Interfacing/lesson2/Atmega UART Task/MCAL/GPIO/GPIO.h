//Masha

#ifndef GPIO_H_
#define GPIO_H_

#define F_CPU 8000000UL

#include "../../Services/Platform_Types.h"
#include "../../Services/bitManip.h"
#include "../../Services/RegisterMap.h"

#include <util/delay.h>


#define GPIO_PIN_0           0
#define GPIO_PIN_1           1
#define GPIO_PIN_2           2
#define GPIO_PIN_3		     3
#define GPIO_PIN_4		     4
#define GPIO_PIN_5		     5
#define GPIO_PIN_6		     6
#define GPIO_PIN_7 	 	     7


#define GPIO_LOW             0
#define GPIO_HIGH            1

#define GPIO_INPUT           0
#define GPIO_OUTPUT          1

#define GPIO_A         0
#define GPIO_B         1
#define GPIO_C         2
#define GPIO_D         3


void GPIO_voidSetPinDirection(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Direction);
void GPIO_voidSetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Value);
void GPIO_voidTogglePinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID);
u8 GPIO_u8GetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID);

void GPIO_voidSetPortDirection(u8 Copy_u8GroupID, u8 Copy_u8Direction);
void GPIO_voidSetPortValue(u8 Copy_u8GroupID, u8 Copy_u8Value);


#endif