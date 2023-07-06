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

u8 Story[][20] = {
	"Hello Every Body",
	"Let’s Start",
	"First, How Are you",
	"I’m Mohamed",
	"Mechanical Engineer",
	"This is my story",
	"I love Dynamics",
	"And controlling it",
	"So, voila Embedded",
	"I Love Embedded",
	"So Good Luck"
	};

void static LCD_ON(void);
void static StartStory(void);
u8* NumToArr(u16 num);
u8 flag = 0;

int main(void)
{
	// Anode LCD
	DIO_SetPinDirection(PINC0,PIN_OUTPUT);
	DIO_SetPinValue(PINC0,PIN_LOW);
	// EXT0 PINS
	DIO_SetPinDirection(PIND2,PIN_INPUT);
	DIO_SetPinValue(PIND2,PIN_HIGH);
	GInterupt_Enable();
	LCD_Init();
	LCD_SaveCustomChar(Man_UP,0);
	EXTI0_RisingEdgeInit();
	EXTI0_SetCallBack(LCD_ON);
	while (flag == 0);
	u8 i = 0;
	while(1)
	{
		
		LCD_WriteString(Story[i]);
		LCD_WriteData(0);
		_delay_ms(1000);
		LCD_SendCommand(LCD_CLR);
		i++;
		if (i == 11)
		{
			i = 0;
		}
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

void static LCD_ON(void)
{
	DIO_SetPinValue(PINC0,PIN_HIGH);
	EXTI0_SetCallBack(StartStory);
}

void static NON_FUNC(void)
{
	
}

void static StartStory(void)
{
	flag = 1;
	EXTI0_SetCallBack(NON_FUNC);
}