/*
 * MemMap.h
 *
 * Created: 8/22/2023 11:42:29 PM
 *  Author: mw296
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

#include "Platform_Types.h"

#define PORTA   *((vu8 *)0x3B)
#define DDRA    *((vu8 *)0x3A)
#define PINA    *((vu8 *)0x39)

#define PORTB   *((vu8 *)0x38)
#define DDRB    *((vu8 *)0x37)
#define PINB    *((vu8 *)0x36)

#define PORTC   *((vu8 *)0x35)
#define DDRC    *((vu8 *)0x34)
#define PINC    *((vu8 *)0x33)

#define PORTD   *((vu8 *)0x32)
#define DDRD    *((vu8 *)0x31)
#define PIND    *((vu8 *)0x30)




#endif /* MEMMAP_H_ */