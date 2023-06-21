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

#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/TIMER0/TIMER0_Interface.h"
#include "MCAL/EXTI1/EXTI1_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/EXTI0/EXTI0_Interface.h"

#include "ECU/LCD/LCD_Interface.h"

#define OhoResisitor   5000

u8* NumToArr(u16 num);

#define VoltMeter 0
#define OhmMeter  1

u8 volatile mode = VoltMeter;
void static ChangeMode(void);

int main(void)
{
	DIO_SetPinDirection(PINA0,PIN_INPUT);
	DIO_SetPinDirection(PINA1,PIN_INPUT);
	
	DIO_SetPinDirection(PIND2,PIN_INPUT);
	DIO_SetPinValue(PIND2,PIN_HIGH);
	
	GInterupt_Enable();
	EXTI0_RisingEdgeInit();
	EXTI0_SetCallBack(ChangeMode);
	
	ADC_Init();
	u16 result = 0;
	LCD_Init();
	LCD_WriteString("Voltameter Mode");
	while(1)
	{
		switch (mode)
		{
			case VoltMeter:
				ADC_DiffA0A1();
				DIO_SetPinDirection(PINA1,PIN_INPUT);
				DIO_SetPinValue(PINA1,PIN_LOW);
				result = ADC_Read();
				GInterupt_Disable();
				LCD_GOTO(1,0);
				GInterupt_Enable();
				if (result <= 512)
				{
					result = (f32)result/512*5000;
					GInterupt_Disable();
					LCD_WriteString(NumToArr(result));
					LCD_WriteString("mv");
					GInterupt_Enable();
				}
				else
				{
					GInterupt_Disable();
					LCD_WriteData('-');
					GInterupt_Enable();
					result =  result - 512;
					result = 5000-(f32)result/512*5000;
					GInterupt_Disable();
					LCD_WriteString(NumToArr(result));
					LCD_WriteString("mv");
					GInterupt_Enable();
				
				}
			break;
			case OhmMeter:
				GInterupt_Disable();
				LCD_GOTO(1,0);
				GInterupt_Enable();
				DIO_SetPinDirection(PINA1,PIN_OUTPUT);
				DIO_SetPinValue(PINA1,PIN_HIGH);
				ADC0_StartConversion();
				result = ADC_Read();
				result = 5000*(f32)result/(f32)(1024-result);
				GInterupt_Disable();
				LCD_WriteString(NumToArr(result));
				LCD_WriteData(244);
				GInterupt_Enable();
			break;
		}
		LCD_WriteData(' ');
		LCD_WriteData(' ');
		LCD_WriteData(' ');
		_delay_ms(500);
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

void static ChangeMode(void)
{
	if (mode == VoltMeter)
	{
		mode = OhmMeter;
		LCD_SendCommand(LCD_CLR);
		LCD_GOTO(0,0);
		LCD_WriteString("Ohmmeter Mode");
	}
	else
	{
		mode = VoltMeter;
		LCD_SendCommand(LCD_CLR);
		LCD_GOTO(0,0);
		LCD_WriteString("Voltameter Mode");
	}
}