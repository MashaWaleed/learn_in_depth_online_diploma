/*
 * UART.c
 *
 * Created: 9/27/2023 4:36:26 PM
 *  Author: mw296
 */ 
#include "UART.h"

void UART_Init()
{
	//BaudRate
	UBRRL = 51;
	
	//normal speed asynchronous 
	CLR_BIT(UCSRA, U2X);
	CLR_BIT(UCSRC, UMSEL);
	
	//frame
	
	//no parity
	CLR_BIT(UCSRC, UPM0);
	CLR_BIT(UCSRC, UPM1);
	
	//8 bit
	CLR_BIT(UCSRB, UCSZ2);
	SET_BIT(UCSRC, UCSZ1);
	SET_BIT(UCSRC, UCSZ0);
		
	
	
	
	//enable 
	SET_BIT(UCSRB, TXEN);
	SET_BIT(UCSRB, RXEN);
}

void UART_Send_Char(u8 data)
{
	while(!(GET_BIT(UCSRA,UDRE)));
	UDR = data;
}

u8 UART_Receive_Char()
{
	while(!(GET_BIT(UCSRA,RXC)));
	return UDR;
}
void UART_Receive_String(char * buf, u8 size)
{
	u8 i = 0;
	while(i<size)
	{
		buf[i] = UART_Receive_Char();
		if (buf[i] == 13) break;
		i++;
	}
	buf[i] = '\0';
	
}