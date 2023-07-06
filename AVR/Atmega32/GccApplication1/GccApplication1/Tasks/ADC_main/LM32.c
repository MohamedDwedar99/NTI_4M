/*
 * LM32.c
 *
 * Created: 6/21/2023 3:27:32 PM
 *  Author: es-MohamedHAbdelAziz
 */ 
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
#include "MCAL/TIMER0/TIMER0_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "ECU/LCD/LCD_Interface.h"
u8 Man_UP[8] = {
 0x0E,
 0x0E,
 0x0E,
 0x15,
 0x1F,
 0x04,
 0x0A,
 0x00
};
u8 Man_DOWN[8] = {
  0x0E,
  0x0E,
  0x0E,
  0x04,
  0x1F,
  0x15,
  0x0A,
  0x00
};

u8* NumToArr(u16 num);

int main(void)
{
	DIO_SetPinDirection(PINB3,PIN_OUTPUT);
	LCD_Init();
	//LCD_WriteString("Ahmed");
	ADC_Init();
	ADC0_StartConversion();
	TIMER0PwmFast_Init();
	u16 x = 0;
	u8 * ptrStr = NULL;
	u8 temp;
	while(1)
	{
		// LM32
		x = ADC_Read();
		// to mv
		x = (u16)((f32)x/1024 * 5000) ;
		// to temp every 10 mv = 1 degree
		temp = x/10;
		LCD_WriteString(NumToArr(temp));
		LCD_WriteString("mv");
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

