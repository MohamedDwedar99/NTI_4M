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

	while(1)
	{
		
	}
	return 1;
}



