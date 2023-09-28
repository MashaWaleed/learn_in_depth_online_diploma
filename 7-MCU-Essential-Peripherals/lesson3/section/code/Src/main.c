/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdlib.h>
#include <stdint.h>

#include "stm32f103x8.h"

#include "GPIO.h"

#include "lcd.h"
#include "keypad.h"


#define ZERO  0x01
#define ONE   0x79
#define TWO   0x24
#define THREE  0x30
#define FOUR  0x4C
#define FIVE  0x12
#define SIX   0x02
#define SEVEN 0x19
#define EIGHT 0x00
#define NINE  0x10




void Clock_init()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}


void GPIO_init()
{
	GPIO_PinConfig_t PinCfg;

	//9->15 are for seven segment
	PinCfg.GPIO_PinNumber = GPIO_PIN_9;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_10;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_11;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_12;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);


	PinCfg.GPIO_PinNumber = GPIO_PIN_14;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_15;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

}



int main(void)
{
	Clock_init();
	GPIO_init();
	LCD_INIT();

	unsigned char key_pressed;
	LCD_WRITE_STRING("HEY");
	delay_ms(30);
	LCD_clear_screen();

	unsigned char LCD_DISPLAY [11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	unsigned char DISPLAY [11] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};
	for (unsigned char i = 0; i < 11; i++) {
		LCD_WRITE_CHAR(LCD_DISPLAY[i]);
		MCAL_GPIO_WritePort(GPIOB, DISPLAY[i] << 9);
		delay_ms(100);

	}

	LCD_clear_screen();
	Keypad_init();
	LCD_WRITE_STRING("Keypad is ready");
	delay_ms(30);
	LCD_clear_screen();

	while (1) {

		key_pressed = Keypad_getkey();
		switch (key_pressed) {
		case '~':
			break;
		case '?':
			LCD_clear_screen();
			break;
		default:
			//				if (key_pressed >= '0' && key_pressed <= '9') {
			//				        LCD_WRITE_CHAR(key_pressed);
			//				        MCAL_GPIO_WritePort(GPIOB, DISPLAY[key_pressed - '0'] << 9);
			//				    } else {
			//				        LCD_WRITE_CHAR(key_pressed);
			//				    }
			//				    break;
			//
			//
			//			}
			LCD_WRITE_CHAR(key_pressed);
			break;
		}

	}
}
