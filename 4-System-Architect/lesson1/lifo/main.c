/*
 * main.c
 *
 *  Created on: Aug 12, 2023
 *      Author: mw296
 */

#include "lifo.h"
#include "stdio.h"

unsigned int buf1 [5];


void main ()
{
	int temp = 0;
	//declaring and initilaizing lifo buffers
	LIFO_Buf_t uart_lifo, I2C_lifo;
	LIFO_init(&uart_lifo, buf1,5); //static

	unsigned int * buf2  = malloc(5*sizeof(unsigned int));
	LIFO_init(&I2C_lifo, buf2,5); //dynamic

	for(int i = 0; i<5; i++){
		if(LIFO_add_item(&uart_lifo, i) == LIFO_no_error)
			printf("LIFO_UART add: %d \n", i);
	}
	for(int i = 0; i<5; i++){
		if(LIFO_get_item(&uart_lifo, &temp) == LIFO_no_error)
			printf("LIFO_UART get: %d \n", temp);
	}

}
