#include <stdio.h>
#include <stdint.h>

#define PORTA_BASE 	0x40010800
#define GPIOA_CRH		*(volatile int*)(PORTA_BASE + 0x04)
#define GPIOA_ODR		*(volatile int*)(PORTA_BASE + 0x0c)

#define RCC_BASE 	  0x40021000
#define RCC_CFGR    *(volatile int *)( RCC_BASE +0x04)
#define RCC_APB2ENR *(volatile int *)( RCC_BASE +0x18)


int main(void)
{

	//by default SYSCLK and AHB are HSI 8MHZ
	RCC_APB2ENR |= 1<<2;
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;

	//configure APB1 and APB2 prescalars

	RCC_CFGR |=0b101<<11;   //divide by 4, APB2  = 2MHZ
	RCC_CFGR |=0b100<<8;    //divide by 2, APB1  = 4MHZ

	while(1){
		GPIOA_ODR |= 1<<13;
		for(int i =0 ; i<3000 ; i++);
		GPIOA_ODR &= ~(1<<13);
		for(int i =0 ; i<3000 ; i++);
	}
	return 0;
}