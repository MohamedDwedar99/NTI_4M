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
#include "ECU/LCD/LCD_Interface.h"

u8* NumToArr(u16 num);


int main(void)
{

	LCD_Init();
	LCD_WriteData('A');
	DIO_SetPinDirection(PINA0,PIN_INPUT);
	ADC_Init();
	ADC0_StartConversion();
	u16 read = 0;
	while(1)
	{
		read = ADC_Read();
		LCD_WriteString(NumToArr(read));
		_delay_ms(1000);
		LCD_SendCommand(LCD_CLR);
	}
	return 1;
}

u8* NumToArr(u16 num){
	u8 arr[6] = {0};
	static u8 arr2[6] = {0};
	s16 i = 0;
	s16 j = 0;
	do
	{
		arr[i] = num%10;
		num /= 10;
		i++;
	}while(num > 0);
	while((i) > 0)
	{
		i--;
		arr2[j] = arr[i] + '0';
		j++;
	}
	arr2[j] = '\0';
	return arr2;
}

