#define F_CPU 8000000UL

#include "util/delay.h"
#include "avr/interrupt.h"

#define GPIO_PORTB   *(volatile unsigned char *)(0x38)
#define GPIO_DDRB	 *(volatile unsigned char *)(0x37)
#define GPIO_PINB    *(volatile unsigned char *)(0x36)

#define GPIO_PORTD   *(volatile unsigned char *)(0x32)
#define GPIO_DDRD	 *(volatile unsigned char *)(0x31)
#define GPIO_PIND    *(volatile unsigned char *)(0x30)

#define INT_SREG         *(volatile unsigned char *)(0x5F)
#define INT_GICR         *(volatile unsigned char *)(0x5B)
#define INT_GIFR         *(volatile unsigned char *)(0x5A)
#define INT_MCUCR        *(volatile unsigned char *)(0x55)
#define INT_MCUCSR       *(volatile unsigned char *)(0x54)



void GPIO_init()
{
	//outputs
	GPIO_DDRD |= (1<<5);
	GPIO_DDRD |= (1<<6);
	GPIO_DDRD |= (1<<7);
}

void interrupt_init()
{
	//l bit in SREG to enable all interrupts
	INT_SREG   |= (1<<7);
	
	//enabling external interrupts 0,1,2
	INT_GICR   |= (0b111 << 5);
	
	//setting external IRQ modes
	INT_MCUCR  |= (0b01 << 0);  //INT0 any logical change
	INT_MCUCR  |= (0b11 << 2);  //INT1 rising
	INT_MCUCSR &= ~(1 << 6);    //INT2 falling


	

	
}

int main()
{
	GPIO_init();
	interrupt_init();
	while(1){
		GPIO_PORTD  &= ~(1<<5);
		GPIO_PORTD  &= ~(1<<6);
		GPIO_PORTD  &= ~(1<<7);
	}
}

ISR(INT0_vect)
{
	GPIO_PORTD  |= (1<<5);
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	GPIO_PORTD  |= (1<<6);
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	GPIO_PORTD  |= (1<<7);
	_delay_ms(1000);
}



