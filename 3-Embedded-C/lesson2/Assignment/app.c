#include "uart.h"

unsigned char string_buf[100] = "learn-in-depth-Mohamed Waleed";
void main(void)
{
	uart_send_string(string_buf);
}