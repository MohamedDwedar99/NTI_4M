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
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"

#include "ECU/LED/LED_Interface.h"
#include "ECU/LCD/LCD_Interface.h"


// ADC Under Water 315 and off water 1023
// Consider < 500 underwater

u8* NumToArr(u16 num);


int main(void)
{


	DIO_SetPinDirection(PINA0,PIN_INPUT);
	DIO_SetPinValue(PINA0,PIN_HIGH);
	DIO_SetPinDirection(PINA0,PIN_INPUT);
	DIO_SetPinValue(PINA1,PIN_HIGH);
	DIO_SetPinDirection(PINA0,PIN_INPUT);
	DIO_SetPinValue(PINA2,PIN_HIGH);
	DIO_SetPinDirection(PINA0,PIN_INPUT);
	DIO_SetPinValue(PINA3,PIN_HIGH);
	LED_INIT(PINB0);
	LED_INIT(PINB1);
	LED_INIT(PINB2);
	LED_INIT(PINB3);
	ADC_Init();
	u8 LEVEL1 = 0;
	u8 LEVEL2 = 0;
	u8 LEVEL3 = 0;
	u8 LEVEL4 = 0;
	while(1)
	{
		ADC0_StartConversion();
		if (ADC_Read() <= 500)
		{
			LEVEL1 = 1;
		}
		else
		{
			LEVEL1 = 0;
		}
		ADC1_StartConversion();
		if (ADC_Read() <= 500)
		{
			LEVEL2 = 1;
		}
		else
		{
			LEVEL2 = 0;
		}
		ADC2_StartConversion();
		if (ADC_Read() <= 500)
		{
			LEVEL3 = 1;
		}
		else
		{
			LEVEL3 = 0;
		}
		ADC0_StartConversion();
		if (ADC_Read() <= 500)
		{
			LEVEL4 = 1;
		}
		else
		{
			LEVEL4 = 0;
		}
		if (LEVEL1 == 0)
		{
			LED_OFF(PINB0);
			LED_OFF(PINB1);
			LED_OFF(PINB2);
			LED_OFF(PINB3);
		}
		else if (LEVEL4 == 1)
		{

			LED_ON(PINB0);
			LED_ON(PINB1);
			LED_ON(PINB2);
			LED_ON(PINB3);
		}
		else if (LEVEL3 == 1)
		{
			LED_ON(PINB0);
			LED_ON(PINB1);
			LED_ON(PINB2);
			LED_OFF(PINB3);
		}
		else if (LEVEL2 == 1)
		{
			LED_ON(PINB0);
			LED_ON(PINB1);
			LED_OFF(PINB2);
			LED_OFF(PINB3);
		}
		else if (LEVEL1 == 1)
		{
			LED_ON(PINB0);
			LED_OFF(PINB1);
			LED_OFF(PINB2);
			LED_OFF(PINB3);
		}

	}
	return 1;
}



