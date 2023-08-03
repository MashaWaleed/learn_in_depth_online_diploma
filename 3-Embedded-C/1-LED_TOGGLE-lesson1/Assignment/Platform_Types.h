/*
 * Platform_Types.h
 *
 *  Created on: July 21, 2023
 *      Author: MohamedWaleed
 */


#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_


#ifndef _Bool
#define _Bool unsigned char
#endif

#define CPU_TYPE                   CPU_TYPE_32
#define CPU_BIT_ORDER              MSB_FIRST
#define CPU_BYTE_ORDER             HIGH_BYTE_FIRST

#ifndef FALSE
#define FALSE                      (boolean)false
#endif

#ifndef TRUE
#define TRUE                       (boolean)true
#endif


// BOOLEAN TYPE
typedef _Bool                           boolean;

// CHAR TYPE 8-BIT
typedef unsigned char                   uint8;
typedef signed char                     sint8;
typedef volatile unsigned char          vuint8;
typedef volatile signed char            vsint8;

// SHORT TYPE 16-BIT
typedef unsigned short                  unit16;
typedef signed short                    sint16;
typedef volatile unsigned short         vunit16;
typedef volatile signed short           vsint16;

// INT TYPE 32-BIT
typedef unsigned int                    uint32;
typedef signed int                      sint32;
typedef volatile unsigned int           vuint32;
typedef volatile signed int             vsint32;

// LONG LONG TYPE 64-BIT
typedef signed long long                sint64;
typedef unsigned long long              uint64;
typedef volatile unsigned long long     vuint64;
typedef volatile signed long long       vsint64;

#endif /* PLATFORM_TYPES_H_ */