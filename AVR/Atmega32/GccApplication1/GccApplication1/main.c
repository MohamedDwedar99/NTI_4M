/*
 * Calculator.c
 *
 * Created: 6/16/2023 2:24:30 PM
 *  Author: es-MohamedHAbdelAziz
 */ 

#define F_CPU  8000000UL

#include <util/delay.h>

#include "Services/BIT_MATH.h"
#include "Services/STD.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/EXTI0/EXTI0_Interface.h"
#include "MCAL/TIMER0/TIMER0_Interface.h"
#include "MCAL/TIMER1/TIMER1_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"

#include "ECU/LED/LED_Interface.h"
#include "ECU/LCD/LCD_Interface.h"
#include "MCAL/TIMER1/TIMER1_Interface.h"
#include "MCAL/UART/UART_Interface.h"





int main(void)
{
	DIO_SetPinDirection(PIND0,PIN_INPUT);
	DIO_SetPinDirection(PIND1,PIN_OUTPUT);
	UART_Init();
	while(1)
	{
		u8 x = 0;
	//	x = UART_Receive();
		UART_Transmit('A');
		
	}
	return 1;
}





