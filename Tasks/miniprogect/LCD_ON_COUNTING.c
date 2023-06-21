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



void static LCD_ON(void);
void static Counter(void);
void static NON_FUNC(void);
void static BUZZEROFF(void);
u8* NumToArr(u16 num);

u16 ALARM_NUM = 0;
u8  AlarmFlag = 0;
int main(void)
{
	// Anode LCD
	DIO_SetPinDirection(PINC0,PIN_OUTPUT);
	DIO_SetPinValue(PINC0,PIN_LOW);
	// EXT0 PINS
	DIO_SetPinDirection(PIND2,PIN_INPUT);
	DIO_SetPinValue(PIND2,PIN_HIGH);
	// SetAlarmPin
	DIO_SetPinDirection(PINC1,PIN_INPUT);
	DIO_SetPinValue(PINC1,PIN_HIGH);
	//BUZZER
	DIO_SetPinDirection(PINC2,PIN_OUTPUT);
	DIO_SetPinValue(PINC2,PIN_LOW);
	
	GInterupt_Enable();
	LCD_Init();
	EXTI0_RisingEdgeInit();
	EXTI0_SetCallBack(LCD_ON);
	LCD_WriteString(NumToArr(ALARM_NUM));
	while(AlarmFlag == 0)
	{
		if (DIO_GetPinValue(PINC1) == 0)
		{
			AlarmFlag = 1;
			EXTI0_SetCallBack(NON_FUNC);
		}
	}
	for (u8 i = 0; i < ALARM_NUM;i++)
	{
		LCD_SendCommand(LCD_CLR);
		LCD_WriteString(NumToArr(ALARM_NUM-i));
		_delay_ms(1000);
	}
	DIO_SetPinValue(PINC2,PIN_HIGH);
	EXTI0_SetCallBack(BUZZEROFF);
	
	while(1)
	{
		
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
	EXTI0_SetCallBack(Counter);
}

void static Counter(void)
{
	ALARM_NUM++;
	LCD_SendCommand(LCD_CLR);
	LCD_WriteString(NumToArr(ALARM_NUM));
}

void static NON_FUNC(void)
{
	
}

void static BUZZEROFF(void)
{
	DIO_SetPinValue(PINC2,PIN_LOW);
}