#include <stdlib.h>
#include <stdint.h>

#include "stm32f103x8.h"

#include "GPIO.h"
#include "EXTI.h"

#include "lcd.h"
#include "keypad.h"

uint8_t IRQ_flag = 0;

void my_wait(int x)
{
	unsigned int i, j;
	for(i = 0; i<x; i++)
		for(j=0; j<255; j++);
}

void EXTI9_Callback(void)
{
	IRQ_flag = 1;
	LCD_WRITE_STRING("IRQ EXTI9 HAS HAPPENED _|- ");
	my_wait(1000);
}



void Clock_init()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}


void GPIO_init()
{


}



int main(void)
{
	Clock_init();

	LCD_INIT();
	LCD_clear_screen();



	EXTI_PinConfig_t  EXTI_CFG;
	EXTI_CFG.EXTI_Pin = EXTI9PB9;
	EXTI_CFG.TriggerCase = EXTI_TriggerRising;
	EXTI_CFG.P_IRQ_CallBack = EXTI9_Callback;
	EXTI_CFG.IRQ_EN = EXTI_IRQ_Enable;

	MCAL_EXTI_GPIO_Init(&EXTI_CFG);

	IRQ_flag = 1;
	while (1)
	{
		if(IRQ_flag)
		{
			LCD_clear_screen();
			IRQ_flag = 0;
		}
	}
}

