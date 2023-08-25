#include <stdint.h>
#include "Platform_Types.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


/*
 *
0x4001 0C00 - 0x4001 0FFF GPIO Port B
0x4001 0800 - 0x4001 0BFF GPIO Port A
0x4002 1000 - 0x4002 13FF RCC
0x18        - RCC_APB2ENR
IOPAEN 2
IOPBEN 3
CRL 0X00 CRH 0X04 IDR 0X08 ODR 0X0C
*/


#define RCC_BASE        0x40021000
#define RCC_APB2ENR     *(vu32 *)(RCC_BASE + 0x18)

#define PORTA_BASE      0x40010800
#define GPIOA_CRL       *(vu32 *)(PORTA_BASE + 0x00)
#define GPIOA_CRH       *(vu32 *)(PORTA_BASE + 0x04)
#define GPIOA_IDR       *(vu32 *)(PORTA_BASE + 0x08)
#define GPIOA_ODR       *(vu32 *)(PORTA_BASE + 0x0C)

#define PORTB_BASE      0x40010C00
#define GPIOB_CRL       *(vu32 *)(PORTB_BASE + 0x00)
#define GPIOB_CRH       *(vu32 *)(PORTB_BASE + 0x04)
#define GPIOB_IDR       *(vu32 *)(PORTB_BASE + 0x08)
#define GPIOB_ODR       *(vu32 *)(PORTB_BASE + 0x0C)



void Clock_init()
{
	//Clock for portA
	RCC_APB2ENR |= (1<<2);
	//Clock for portB
	RCC_APB2ENR |= (1<<3);
}


void GPIO_init()
{
	GPIOA_CRL = 0;
	GPIOA_CRH = 0;


	//PA1 PA13 as input floating
	GPIOA_CRL &= ~(0b11 <<4);
	GPIOA_CRL |= (0b01 <<6);

	GPIOA_CRH &= ~(0b11 <<20);
	GPIOA_CRH |= (0b01 <<22);

	//PB1 PB13 as output push-pull
	GPIOB_CRL |= (0b01 <<4);
	GPIOB_CRL &= ~(0b11 <<6);

	GPIOB_CRH |= (0b01 <<20);
	GPIOB_CRH &= ~(0b11 <<22);

}



int main(void)
{
	Clock_init();
	GPIO_init();

	while(1)
    {
		if(((GPIOA_IDR & (1<<1)) >> 1) == 0){
			GPIOB_ODR ^= (1<<1);
			while(((GPIOA_IDR & (1<<1)) >> 1) == 0);
		}
		if(((GPIOA_IDR & (1<<13)) >> 13) == 1){
			GPIOB_ODR ^= (1<<13);
		}
		volatile int i ;
		for(i = 0; i<10000; i++);
    }
	
}
