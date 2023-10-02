/*****************************< LIB *****************************/
#include <stdint.h>
#include "stm32f103x8.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*****************************< MCAL *****************************/
#include "GPIO.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "USART.h"

/*****************************< HAL *****************************/
#include "LED.h"
#include "PushButton.h"
#include "Seg-5161BS.h"

u16 ch;

/*****************************< Main  *********************************/

int main(void)
{
    /********< Initialize Peripherals and Clock *************************/
	MCAL_RCC_InitSysClock();
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPBEN);
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_AFIOEN);
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_USART1EN);

	GPIO_PinConfig_t cfg;
	cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	cfg.GPIO_Output_Speed = GPIO_SPEED_2M;
	cfg.GPIO_PinNumber = GPIO_PIN_0;
	MCAL_GPIO_Init(GPIOA, &cfg);

	USART_Config_t usartCFG;
	usartCFG.BaudRate = USART_BAUD_RATE_9600;
	usartCFG.FlowCTRL = USART_FLOW_CTRL_NONE;
	usartCFG.Parity = USART_PARITY_NONE;
	usartCFG.PayLoadLength = USART_DATA_8bits;
	usartCFG.StopBits = USART_STOP_BITS_1;
	usartCFG.IRQ_Enable = USART_IRQ_ENABLE_NONE;
	usartCFG.USART_Mode = USART_MODE_TX_RX;
	usartCFG.P_IRQ_CallBack = NULL;

	MCAL_USART_Init(USART1, &usartCFG,USART_CFG_1);
	MCAL_USART_GPIO_SetPins(USART1,0);

	while(1)
	{
		MCAL_USART_Get_Data(USART1, &ch, enable,USART_CFG_1);
		MCAL_USART_Send_Data(USART1, &ch, enable,USART_CFG_1);
	}

}

/*****************************< End of Main  *********************************/
