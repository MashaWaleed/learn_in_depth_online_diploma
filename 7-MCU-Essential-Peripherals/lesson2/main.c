#include "lcd.h"
#include "keypad.h"

char Pressed;
int Count = 0;

int main()
{
	
	LCD_Init();
	keypad_Init();
	_delay_ms(50);
	while(1){
		Pressed  = keypad_GetKey();
		switch(Pressed)
		{
			case '~':
				break;
			case '?':
				LCD_Clear_Screen();
				break;
			default:
				Count++;
				if(Count == 16)
				{
					LCD_gotoXY(1,0);
				}
				else if(Count == 32)
				{
					LCD_Clear_Screen();
					LCD_gotoXY(0,0);
					Count = 0;
				}
				LCD_Send_Character(Pressed);
				
				break;
		}
	}
}


