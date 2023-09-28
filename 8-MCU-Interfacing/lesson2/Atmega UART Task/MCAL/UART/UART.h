/*
 * UART.h
 *
 * Created: 9/27/2023 4:36:40 PM
 *  Author: mw296
 */ 


#ifndef UART_H_
#define UART_H_


#define F_CPU 8000000UL

#include "../../Services/Platform_Types.h"
#include "../../Services/bitManip.h"
#include "../../Services/RegisterMap.h"
#include <util/delay.h>

#include "../GPIO/GPIO.h"


void UART_Init();
void UART_Send_Char(u8);
u8 UART_Receive_Char();
void UART_Receive_String(char * buf, u8 size);


#endif /* UART_H_ */