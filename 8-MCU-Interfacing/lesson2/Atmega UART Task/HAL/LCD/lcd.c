#include <stdio.h>
#include <string.h>

#include "lcd.h"

void LCD_init()
{
	LCD_is_busy();
	
	//set control port as output
	LCD_Ctrl_Dir_PORT |= (1<<LCD_RS) | (1<<LCD_RW) | (1<<LCD_EN);
	
	//====================================================
	#ifdef Eight_bit_mode
	//set data port as output
	LCD_Data_Dir_PORT |= 0xFF;
	
	LCD_clear_screen();
	_delay_ms(20);
	LCD_Write_command(Func_set_8bit_2line);
	#endif

	#ifdef Four_bit_mode
	//set data port as output
	LCD_Data_Dir_PORT |= 0xF0;
	LCD_clear_screen();
	_delay_ms(20);
	LCD_Write_command(0x02);
	LCD_Write_command(Func_set_4bit_2line);
	#endif
	//====================================================
	LCD_Write_command(Display_on_cursor_blink);
	LCD_Write_command(Entry_mode);
	LCD_Write_command(Begin_first_row);
}

void LCD_Write_command(unsigned char commmand)
{
	
	#ifdef Eight_bit_mode
	LCD_Ctrl_PORT &= ~((1<<LCD_RS) | (1<<LCD_RW) | (1<<LCD_EN)); //write command Instruction
	GPIO_voidSetPinValue(LCD_Ctrl_PORT , LCD_RS , GPIO_LOW);
	GPIO_voidSetPinValue(LCD_Ctrl_PORT , LCD_RW , GPIO_LOW);
	GPIO_voidSetPinValue(LCD_Ctrl_PORT , LCD_EN , GPIO_LOW);
	
	GPIO_voidSetPortValue(LCD_Data_PORT , commmand);
	
	LCD_kick();
	#endif
	
	#ifdef Four_bit_mode
	LCD_in_port = (LCD_in_port &(0x0F)) | (commmand & 0xF0);
	
	GPIO_voidSetPinValue(LCD_Ctrl_PORT , LCD_RS , GPIO_LOW);
	GPIO_voidSetPinValue(LCD_Ctrl_PORT , LCD_RW , GPIO_LOW);
	
	_delay_ms(100);
	LCD_kick();
	
	LCD_in_port = (LCD_in_port &(0x0F)) | ((commmand & 0x0F)<<4);
	
	GPIO_voidSetPinValue(LCD_Ctrl_PORT , LCD_RS , 0);
	GPIO_voidSetPinValue(LCD_Ctrl_PORT , LCD_RW , 0);
	
	_delay_ms(100);
	LCD_kick();
	
	_delay_ms(5);
	#endif
}

void LCD_Write_char(unsigned char data)
{
	
	#ifdef Eight_bit_mode
	//write data
	GPIO_voidSetPinValue(LCD_Ctrl_PORT , LCD_RS , 1);
	GPIO_voidSetPinValue(LCD_Ctrl_PORT , LCD_RW , 0);
	GPIO_voidSetPinValue(LCD_Ctrl_PORT , LCD_EN , 0);
	
	GPIO_voidSetPortValue(LCD_Data_PORT , data);
	LCD_kick();
	#endif
	
	#ifdef Four_bit_mode
	
	LCD_in_port = (LCD_in_port &(0x0F)) | (data & 0xF0);
	
	GPIO_voidSetPinValue(LCD_Ctrl_PORT , LCD_RS , 1);
	GPIO_voidSetPinValue(LCD_Ctrl_PORT , LCD_RW , 0);
	
	//_delay_ms(100);
	LCD_kick();
	
	LCD_in_port = (LCD_in_port &(0x0F)) | ((data & 0x0F)<<4);
	GPIO_voidSetPinValue(LCD_Ctrl_PORT , LCD_RS , 1);
	GPIO_voidSetPinValue(LCD_Ctrl_PORT , LCD_RW , 0);
	
	//_delay_ms(100);
	LCD_kick();
	
	_delay_ms(5);
	#endif
}
void LCD_Write_string(char* string)
{
	int count =0;
	for(count = 0 ; (string[count]!='\0') ; count++)
	{
		if(count == 16)
		LCD_gotoXY(1,0);
		
		if(count == 32)
		{
			LCD_clear_screen();
			LCD_gotoXY(0,0);
		}
		
		LCD_Write_char(string[count]);
	}
}

void LCD_is_busy(void)
{
	#ifdef Eight_bit_mode

	GPIO_voidSetPinDirection(LCD_Ctrl_PORT ,LCD_RS ,GPIO_OUTPUT);
	GPIO_voidSetPinDirection(LCD_Ctrl_PORT ,LCD_RW ,GPIO_OUTPUT);
	GPIO_voidSetPinDirection(LCD_Ctrl_PORT ,LCD_EN ,GPIO_OUTPUT);
	
	GPIO_voidSetPortValue(LCD_Data_PORT ,GPIO_INPUT);
	
	//command register select
	GPIO_voidSetPinValue(LCD_Ctrl_PORT ,LCD_RS , 0 );
	
	//read mode
	GPIO_voidSetPinValue(LCD_Ctrl_PORT ,LCD_RW , 1 );
	
	LCD_kick();
	
	//LCD_Data_Dir_PORT = 0xFF;
	GPIO_voidSetPortDirection(LCD_Data_PORT ,GPIO_OUTPUT);
	
	//write mode
	GPIO_voidSetPinValue(LCD_Ctrl_PORT ,LCD_RW , 0 );
	
	#endif
	
	#ifdef Four_bit_mode
	
	GPIO_voidSetPinDirection(LCD_Ctrl_PORT ,LCD_RS ,GPIO_OUTPUT);
	GPIO_voidSetPinDirection(LCD_Ctrl_PORT ,LCD_RW ,GPIO_OUTPUT);
	GPIO_voidSetPinDirection(LCD_Ctrl_PORT ,LCD_EN ,GPIO_OUTPUT);
	
	
	GPIO_voidSetPinDirection(LCD_Data_PORT ,LCD_D4 ,GPIO_INPUT);
	GPIO_voidSetPinDirection(LCD_Data_PORT ,LCD_D5 ,GPIO_INPUT);
	GPIO_voidSetPinDirection(LCD_Data_PORT ,LCD_D6 ,GPIO_INPUT);
	GPIO_voidSetPinDirection(LCD_Data_PORT ,LCD_D7 ,GPIO_INPUT);
	
	_delay_ms(5);
	
	//command register select
	GPIO_voidSetPinValue(LCD_Ctrl_PORT ,LCD_RS , 0 );
	
	//read mode
	GPIO_voidSetPinValue(LCD_Ctrl_PORT ,LCD_RW , 1 );
	
	LCD_kick();
	
	GPIO_voidSetPinDirection(LCD_Data_PORT ,LCD_D4 ,GPIO_OUTPUT);
	GPIO_voidSetPinDirection(LCD_Data_PORT ,LCD_D5 ,GPIO_OUTPUT);
	GPIO_voidSetPinDirection(LCD_Data_PORT ,LCD_D6 ,GPIO_OUTPUT);
	GPIO_voidSetPinDirection(LCD_Data_PORT ,LCD_D7 ,GPIO_OUTPUT);
	
	//write mode
	GPIO_voidSetPinValue(LCD_Ctrl_PORT ,LCD_RW , 0 );
	#endif
}

void LCD_kick()
{
	//set enable
	GPIO_voidSetPinValue(LCD_Ctrl_PORT ,LCD_EN , 1 );
	_delay_ms(5);
	//Reset enable
	GPIO_voidSetPinValue(LCD_Ctrl_PORT ,LCD_EN , 0 );
}

void LCD_clear_screen(void)
{
	LCD_Write_command(Clear_display);
}

void LCD_gotoXY(uint8_t line, uint8_t position)
{
	if (line == 0) // line 1
	{
		if (position < 16 && position >= 0)
		LCD_Write_command(0x80 + position);
	}
	if (line == 1) //  line 2
	{
		if (position < 16 && position >= 0)
		LCD_Write_command(0xC0 + position);
	}
}


void LCD_Display_Number(int Number)
{
	char str[7];
	sprintf(str, "%d", Number);

	LCD_Write_string(str);
}

void LCD_Display_Real_Number(double Number)
{
	char str[16];

	char *tmpsign = (Number < 0) ? "-" : "";
	float tmpVal = (Number < 0) ? -Number : Number;

	int tmpInt1 = tmpVal; // Get the integer value
	double tmpFraction = tmpVal - tmpInt1; // Get fraction value
	int tmpInt2 = tmpFraction * 10000; // Turn into integer

	sprintf(str, "%s%d.%05d", tmpsign, tmpInt1, tmpInt2);
	LCD_Write_string(str);
}

