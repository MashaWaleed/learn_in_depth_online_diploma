/*
 * fifo.c
 *
 *  Created on: Aug 12, 2023
 *      Author: mw296
 */

#include "fifo.h"

FIFO_Buf_Status FIFO_init(FIFO_Buf_t *fifo, element_type* buf, unsigned int length)
{
	//Check if the buffer was created or not first
	if(buf == NULL) return FIFO_null;

	//initilaise struct properties
	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->count = 0;
	fifo->length = length;

	//return a no error flag after init
	return FIFO_no_error;
}


FIFO_Buf_Status FIFO_Enqueue(FIFO_Buf_t *fifo, element_type item)
{
	//check if buf was created with head tail and base.
	if(!(fifo->base) || !(fifo->head) || !(fifo->tail)){
		return FIFO_null;
	}

	// we have to make sure that the buffer isnt full in order to add items
	if(FIFO_Is_Full(fifo) == FIFO_full){
		return FIFO_full;
	}

	//add item and increment both head and count.
	*(fifo->head) = item;
	fifo->count++;

	//now check if count was decremented so we cab apply the circular fifo configuration
	if(fifo->head == fifo->base + (fifo->length * sizeof(element_type))){
		fifo->head = fifo->base;
		return FIFO_no_error;
	}

	fifo->head++;
	return FIFO_no_error;
}


FIFO_Buf_Status FIFO_Dequeue(FIFO_Buf_t *fifo, element_type* item)
{
	if(!(fifo->base) || !(fifo->head) || !(fifo->tail)){
		return FIFO_null;
	}

	// check if the buffer is empty
	if(fifo->count == 0) return FIFO_empty;

	*item  = *(fifo->tail) ;
	fifo->count--;

	if(fifo->tail == fifo->base + (fifo->length * sizeof(element_type))){
		fifo->tail = fifo->base;
		return FIFO_no_error;
	}

	fifo->tail++;
	return FIFO_no_error;


}


FIFO_Buf_Status FIFO_Is_Full(FIFO_Buf_t *fifo)
{
	if(!(fifo->base) || !(fifo->head) || !(fifo->tail)){
		return FIFO_null;
	}

	if(fifo->count == fifo->length) return FIFO_full;

	return FIFO_no_error;
}



void fifo_print(FIFO_Buf_t *fifo)
{
	element_type *temp;
	int i;

	if(fifo->count == 0){
		printf("fifo is empty \n");
	}

	else{
		temp = fifo->tail;
		printf("\n=======fifo print========\n");
		for(i=0; i< fifo->count; i++){
			printf("\t %x \n", *temp);
			temp++;
		}
		printf("===========================\n");
	}
}


