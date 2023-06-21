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


long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
void TimerResult(void);
u16 READ = 0;
int main(void)
{

	DIO_SetPinDirection(PINB3,PIN_OUTPUT);
	DIO_SetPinValue(PINB3,PIN_LOW);
	ADC_Init();
	TIMER0PwmFast_Init();
	ADC0_StartConversion();
	Segment7_Mult4Init();
	u16 x =0;
	u32 counter = 0;
	u8 flag = 0;
	while(1)
	{
		x = ADC_Read();
		x = ((f32)100/(298-41))*(x-41);
		TIMER0PwmFast_Duty(x);
		if (x >=  40 && x <= 100 && flag == 0)
		{
			counter++;
			flag = 1;
		}
		if (x < 40)
		{
			flag = 0;
		}
		Segment7_Mult4SetDisplay(counter);
	}
	return 1;
}

