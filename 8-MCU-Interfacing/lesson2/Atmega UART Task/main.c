/*
 * ATMEGA32-Driver.c
 *
 * Created: 9/11/2023 11:43:57 AM
 * Author : Masha
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>


#include "./MCAL/UART/UART.h"
#include "./MCAL/GPIO/GPIO.h"

#include "./HAL/LCD/lcd.h"

char buf[30];

int main(void)
{	
	UART_Init();
	LCD_init();

    while (1) 
    {
		UART_Receive_String(buf, 30);
		LCD_Write_string(buf);
		
	}
}

