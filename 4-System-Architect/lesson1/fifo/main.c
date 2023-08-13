/*
 * main.c
 *
 *  Created on: Aug 12, 2023
 *      Author: mw296
 */


#include "fifo.h"

element_type buff [width1];

int main(){
	FIFO_Buf_t FIFO_UART;
	element_type i, temp = 0;
	if(FIFO_init(&FIFO_UART, buff, 5) == FIFO_no_error)
		printf("fifo init is done\n\n");

	for(i = 0;i<7;i++){
		printf("enqueue %x\n", i);
		if(FIFO_Enqueue(&FIFO_UART, i) == FIFO_no_error)
			printf("\tenqueue done\n");
		else
			printf("\tenqueue failed\n");
	}

	fifo_print(&FIFO_UART);

	if(FIFO_Dequeue(&FIFO_UART, &temp) == FIFO_no_error)
		printf("dequeue done  %x\n", temp);
	if(FIFO_Dequeue(&FIFO_UART, &temp) == FIFO_no_error)
		printf("dequeue done  %x\n", temp);

	fifo_print(&FIFO_UART);

	return 0;
}
