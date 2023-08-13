/*
 * lifo.c
 *
 *  Created on: Aug 12, 2023
 *      Author: mw296
 */

#include "lifo.h"
LIFO_status LIFO_add_item (LIFO_Buf_t* lifo_buf_p, unsigned int item)
{
	// we have to check the status before commencing with the addding

	if(!lifo_buf_p -> base || !lifo_buf_p-> head)   //this cheks if it was initilized (the pointers arent nulled)
		return LIFO_Null;

	if(lifo_buf_p -> count == lifo_buf_p-> length)  //this cheks if it was full
		return LIFO_full;

	*(lifo_buf_p->head) = item;
	lifo_buf_p -> head++;
	lifo_buf_p -> count ++;

	return LIFO_no_error; // finally after adding it should return no error to continue in the switch statemnt

}
LIFO_status LIFO_get_item (LIFO_Buf_t* lifo_buf_p, unsigned int* item)
{
	//check if it was init
	if(!lifo_buf_p -> base || !lifo_buf_p-> head)
		return LIFO_Null;

	//check if it was empty
	if(!lifo_buf_p -> count)
		return LIFO_empty;

	lifo_buf_p->head--;
	*item = *(lifo_buf_p->head);
	lifo_buf_p->count--;

	return LIFO_no_error;

}
LIFO_status LIFO_init (LIFO_Buf_t* lifo_buf_p, unsigned int* buf,unsigned int length)
{
	if(!buf)
		return LIFO_Null;
	lifo_buf_p ->base = buf;
	lifo_buf_p ->head = buf;
	lifo_buf_p ->length = length;
	lifo_buf_p ->count = 0;
	return LIFO_no_error;
}

