/*
 * main_GPIO.c
 *
 *  Created on: Jun 24, 2023
 *      Author: es-MohamedHAbdelAziz
 */


#include "Std_Types.h"
#include "Bit_Math.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"



void _delay_ms(u32 delay)
{
	u32 i;
	for(i = 0; i < 1000*delay ;i++)
	{
		asm("NOP");
	}
}


int main(void)
{
    /* Loop forever */
	RCC_voidSysClkInit();
	RCC_voidEnablePerClk(RCC_AHB1, 0);
	GPIO_voidSetPinDirection(PORTA, PIN5, GPIO_OUTPUT,0,GPIO_PUSHPULL);
	for(;;)
	{
		GPIO_voidSetPinValue(PORTA, PIN5, GPIO_HIGH);
		_delay_ms(1000);
		GPIO_voidSetPinValue(PORTA, PIN5, GPIO_LOW);
		_delay_ms(1000);
	}
}
