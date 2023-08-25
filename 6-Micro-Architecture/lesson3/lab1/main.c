#include <stdio.h>
#include <stdint.h>

#define PORTA_BASE 	0x40010800
#define GPIOA_CRH		*(volatile int*)(PORTA_BASE + 0x04)
#define GPIOA_ODR		*(volatile int*)(PORTA_BASE + 0x0c)

#define RCC_Base 	0x40021000
#define RCC_APB2ENR *(volatile uint32_t*)( RCC_Base +0x18)

int main(void)
{
	//enable porta clock
	RCC_APB2ENR |= 1<<2;   

	//configure pin a13 as output
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;


	while(1){
		//toggling pin

		GPIOA_ODR |= 1<<13;
		for(int i =0 ; i<3000 ; i++);
		GPIOA_ODR &= ~(1<<13);
		for(int i =0 ; i<3000 ; i++);
	}
	return 0;
}