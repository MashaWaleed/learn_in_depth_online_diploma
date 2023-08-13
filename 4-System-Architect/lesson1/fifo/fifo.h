/*
 * fifo.h
 *
 *  Created on: Aug 12, 2023
 *      Author: mw296
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"


//to make this generic we can make a choice for the width of the variable

#define element_type    uint8_t    //make a reconfigurable default data type for the buffer
#define width1          5          //same thing for the width of the buffer.

extern element_type buff [width1];


typedef struct
{
	unsigned int count;
	unsigned int length;
	element_type *base;
	element_type *head;
	element_type *tail;
}FIFO_Buf_t;

typedef enum
{
	FIFO_no_error,
	FIFO_full,
	FIFO_null,
	FIFO_empty
}FIFO_Buf_Status;


//API's
FIFO_Buf_Status FIFO_init(FIFO_Buf_t *fifo, element_type* buf, unsigned int length);
FIFO_Buf_Status FIFO_Enqueue(FIFO_Buf_t *fifo, element_type item);
FIFO_Buf_Status FIFO_Dequeue(FIFO_Buf_t *fifo, element_type* item);
FIFO_Buf_Status FIFO_Is_Full(FIFO_Buf_t *fifo);
void fifo_print(FIFO_Buf_t *fifo);

#endif /* FIFO_H_ */
