#define PORTA_BASE 	    0x40010800
#define GPIOA_CRH		*(volatile unsigned int*)(PORTA_BASE + 0x04)
#define GPIOA_ODR		*(volatile unsigned int*)(PORTA_BASE + 0x0c)

#define RCC_BASE 	    0x40021000
#define RCC_CR          *(volatile unsigned int *)( RCC_BASE +0x00)
#define RCC_CFGR        *(volatile unsigned int *)( RCC_BASE +0x04)
#define RCC_APB2ENR     *(volatile unsigned int *)( RCC_BASE +0x18)



void clock_init()
{
	//choose PLL source and multiplier
	RCC_CFGR |=  (0b0110 << 18);   //mult 4 * 8 = 32 MHZ

	//indicate pll is ready
	RCC_CR |= (1<<24);

	//APB1 and APB2 prescalars
	RCC_CFGR |= (0b100 << 8);     //APB1 / 2 = 16MHZ
	RCC_CFGR |= (0b101 << 11);     //APB2 / 4 = 8MHZ

	

	//config SYSCLK
	RCC_CFGR |= (0b10 << 0);

	RCC_APB2ENR |= (1<<2);

}

int main(void)
{
    clock_init();
    GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;


    while(1){
		GPIOA_ODR |= 1<<13;
		for(int i =0 ; i<3000 ; i++);
		GPIOA_ODR &= ~(1<<13);
		for(int i =0 ; i<3000 ; i++);
	}


}
