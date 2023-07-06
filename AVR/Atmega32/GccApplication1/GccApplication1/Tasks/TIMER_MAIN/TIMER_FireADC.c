/*
 * Calculator.c
 *
 * Created: 6/16/2023 2:24:30 PM
 *  Author: es-MohamedHAbdelAziz
 */ 

#undef  F_CPU
#define F_CPU 16000000UL

#include "Services/BIT_MATH.h"
#include "Services/STD.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "ECU/KEYPAD/KEYPAD_Interface.h"
#include "ECU/LCD/LCD_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "ECU/Segment7/Segment7_Interface.h"
#include "MCAL/EXTI0/EXTI0_Interface.h"
#include "MCAL/ADC/ADC_Pirvate.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/TIMER0/TIMER0_Interface.h"



void TimerResult(void);

int main(void)
{
	
	DIO_SetPinDirection(PINA5,PIN_OUTPUT);
	DIO_SetPinValue(PINA5,PIN_HIGH);
	GInterupt_Enable();
	TINER0_SetCallBack(TimerResult);
	TIMER0Normal_Init();
	TIMER0Normal_Start(112);
	ADC_Init();
	ADC0_StartConversion();
	Segment7_Mult4Init();
	u16 READ = 0;
	while(1)
	{
		READ = ADC_Read();
		Segment7_Mult4SetDisplay(READ);
	}
	return 1;
}

void TimerResult(void)
{
	static u16 x = 0;
	x++;
	if (x == 976)
	{
		DIO_TogPinValue(PINA5);
		x = 0;
		TIMER0Normal_Start(112);
	}
}
