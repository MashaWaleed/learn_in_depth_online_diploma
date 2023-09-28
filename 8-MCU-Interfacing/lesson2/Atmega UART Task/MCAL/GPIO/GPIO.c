//Masha

#include "GPIO.h"

void GPIO_voidSetPinDirection(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Direction)
{
	if (Copy_u8GroupID <= GPIO_D && Copy_u8PinID <= GPIO_PIN_7
			&& Copy_u8Direction <= GPIO_OUTPUT)
	{
        switch(Copy_u8GroupID)
        {
            case GPIO_A:
                if (Copy_u8Direction == GPIO_INPUT)
                    DDRA &=~ (1<<Copy_u8PinID);
                else
                    DDRA |= (1<<Copy_u8PinID);
            break;

            case GPIO_B:
                if (Copy_u8Direction == GPIO_INPUT)
                    DDRB &= ~(1<<Copy_u8PinID);
                else
                    DDRB |= (1<<Copy_u8PinID);
            break;

            case GPIO_C:
                if (Copy_u8Direction == GPIO_INPUT)
                    DDRC &= ~(1<<Copy_u8PinID);
                else
                    DDRC |= (1<<Copy_u8PinID);
            break;

            case GPIO_D:
                if (Copy_u8Direction == GPIO_INPUT)
                    DDRD &=~ (1<<Copy_u8PinID);
                else
                    DDRD |= (1<<Copy_u8PinID);
            break;

        }
	}

}

void GPIO_voidSetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
    if (Copy_u8GroupID <= GPIO_D && Copy_u8PinID <= GPIO_PIN_7
			&& Copy_u8Value <= GPIO_HIGH)
	{
        switch(Copy_u8GroupID)
        {
            case GPIO_A:
                if (Copy_u8Value == GPIO_LOW)
                    PORTA &= ~(1<<Copy_u8PinID);
                else
                    PORTA |= (1<<Copy_u8PinID);
            break;

            case GPIO_B:
                if (Copy_u8Value == GPIO_LOW)
                    PORTB &= ~(1<<Copy_u8PinID);
                else
                    PORTB |= (1<<Copy_u8PinID);
            break;

            case GPIO_C:
                if (Copy_u8Value == GPIO_LOW)
                    PORTC &= ~(1<<Copy_u8PinID);
                else
                    PORTC |= (1<<Copy_u8PinID);
            break;

            case GPIO_D:
                if (Copy_u8Value == GPIO_LOW)
                    PORTD &= ~(1<<Copy_u8PinID);
                else
                    PORTD |= (1<<Copy_u8PinID);
            break;

        }
	}

}

void GPIO_voidTogglePinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID)
{
    if (Copy_u8GroupID <= GPIO_D && Copy_u8PinID <= GPIO_PIN_7)
	{
        switch(Copy_u8GroupID)
        {
            case GPIO_A:
                PORTA ^= (1<<Copy_u8PinID);
            break;

            case GPIO_B:
                PORTB ^= (1<<Copy_u8PinID);
            break;

            case GPIO_C:
                PORTC ^= (1<<Copy_u8PinID);
            break;

            case GPIO_D:
                PORTD ^= (1<<Copy_u8PinID);
            break;

        }
	}
}

u8 GPIO_u8GetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID)
{
    u8 Local_u8PinValue = 0xff;
    if (Copy_u8GroupID <= GPIO_D && Copy_u8PinID <= GPIO_PIN_7)
	{
        switch(Copy_u8GroupID)
        {
            case GPIO_A:
                Local_u8PinValue = ((PINA>>Copy_u8PinID)&1);
            break;

            case GPIO_B:
                Local_u8PinValue = ((PINB>>Copy_u8PinID)&1);
            break;

            case GPIO_C:
                Local_u8PinValue = ((PINC>>Copy_u8PinID)&1);
            break;

            case GPIO_D:
                Local_u8PinValue = ((PIND>>Copy_u8PinID)&1);
            break;

        }
	}
    return Local_u8PinValue;
}


void GPIO_voidSetPortDirection(u8 Copy_u8GroupID,  u8 Copy_u8Direction)
{
	if (Copy_u8GroupID <= GPIO_D 
	&& Copy_u8Direction <= GPIO_OUTPUT)
	{
		switch(Copy_u8GroupID)
		{
			case GPIO_A:
			if (Copy_u8Direction == GPIO_INPUT)
			DDRA = (0x00);
			else
			DDRA = (0xFF);
			break;

			case GPIO_B:
			if (Copy_u8Direction == GPIO_INPUT)
			DDRB = (0x00);
			else
			DDRB = (0xFF);
			break;

			case GPIO_C:
			if (Copy_u8Direction == GPIO_INPUT)
			DDRC = (0x00);
			else
			DDRC = (0xFF);
			break;

			case GPIO_D:
			if (Copy_u8Direction == GPIO_INPUT)
			DDRD = (0x00);
			else
			DDRD = (0xFF);
			break;

		}
	}
	
}
void GPIO_voidSetPortValue(u8 Copy_u8GroupID, u8 Copy_u8Value)
{
	if (Copy_u8GroupID <= GPIO_D
	&& Copy_u8Value <= GPIO_HIGH)
	{
		switch(Copy_u8GroupID)
		{
			case GPIO_A:
			if (Copy_u8Value == GPIO_LOW)
			PORTA = (0x00);
			else
			PORTA = (0xFF);
			break;

			case GPIO_B:
			if (Copy_u8Value == GPIO_LOW)
			PORTB = (0x00);
			else
			PORTB = (0xFF);
			break;

			case GPIO_C:
			if (Copy_u8Value == GPIO_LOW)
			PORTC = (0x00);
			else
			PORTC = (0xFF);
			break;

			case GPIO_D:
			if (Copy_u8Value == GPIO_LOW)
			PORTD = (0x00);
			else
			PORTD = (0xFF);
			break;

		}
	}
	
}
