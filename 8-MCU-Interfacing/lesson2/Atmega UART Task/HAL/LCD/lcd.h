#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000UL

#include "../../Services/Platform_Types.h"
#include "../../Services/bitManip.h"
#include "../../Services/RegisterMap.h"
#include <util/delay.h>

#include "../../MCAL/GPIO/GPIO.h"


#define LCD_in_port              PORTA

#define LCD_Data_PORT            GPIO_A
#define LCD_Data_Dir_PORT        DDRA

#define LCD_Ctrl_PORT            GPIO_B
#define LCD_Ctrl_Dir_PORT        DDRB

#define LCD_D0                   GPIO_PIN_0
#define LCD_D1                   GPIO_PIN_1
#define LCD_D2                   GPIO_PIN_2
#define LCD_D3                   GPIO_PIN_3
#define LCD_D4                   GPIO_PIN_4
#define LCD_D5                   GPIO_PIN_5
#define LCD_D6                   GPIO_PIN_6
#define LCD_D7                   GPIO_PIN_7
								 
#define LCD_RS                   GPIO_PIN_1
#define LCD_RW                   GPIO_PIN_2
#define LCD_EN                   GPIO_PIN_3

//#define Eight_bit_mode
#define Four_bit_mode


#define Func_set_8bit_1line      0x30
#define Func_set_8bit_2line      0x38
#define Func_set_4bit_1line      0x20
#define Func_set_4bit_2line      0x28
#define Entry_mode               0x06
#define Display_off_cursor_off   0x08
#define Display_on_cursor_on     0x0E
#define Display_on_cursor_off    0x0C
#define Display_on_cursor_blink  0x0F
#define Shift_entire_Disp_left   0x18
#define Shift_entire_Disp_right  0x1C
#define Move_cursor_left_by_one  0x10
#define Move_cursor_right_by_one 0x14
#define Begin_first_row			 0x80
#define Begin_second_row		 0xC0
#define Clear_display            0x01

void LCD_init();
void LCD_Write_command(unsigned char commmand);
void LCD_Write_char(unsigned char data);
void LCD_Write_string(char* string);
void LCD_is_busy(void);
void LCD_clear_screen(void);
void LCD_gotoXY(uint8_t line, uint8_t position);
void LCD_kick();
void LCD_Display_Number(s32 Number);
void LCD_Display_Real_Number(f64 Number);

	


#endif /* LCD_H_ */

