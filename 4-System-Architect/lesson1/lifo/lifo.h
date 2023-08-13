/*
 * lifo.h
 *
 *  Created on: Aug 12, 2023
 *      Author: mw296
 */

#ifndef LIFO_H_
#define LIFO_H_

//type def

 typedef struct
{
	unsigned int length;
	unsigned int count ;
	unsigned int *base ;
	unsigned int *head ;

}LIFO_Buf_t;

//enumeration in order to get the status

typedef enum {
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null
}LIFO_status;

//API
LIFO_status LIFO_add_item (LIFO_Buf_t* lifo_buf_p, unsigned int item);
LIFO_status LIFO_get_item (LIFO_Buf_t* lifo_buf_p, unsigned int* item);
LIFO_status LIFO_init (LIFO_Buf_t* lifo_buf_p, unsigned int* buf, unsigned int length);
#endif /* LIFO_H_ */
