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
#include "MCAL/TIMER1/TIMER1_Interface.h"



void TimerResult(void);
u16 READ = 0;
int main(void)
{

	DIO_SetPinDirection(PIND5,PIN_OUTPUT);
	//DIO_SetPinValue(PINB3,PIN_LOW);
	ADC_Init();
	TIMER1Pwm_Init();
	ADC0_StartConversion();
	Segment7_Mult4Init();
	TIMER1Pwm_Enable();	
	u16 x =0;
	u32 counter = 0;
	u8 flag = 0;
	TIMER1Pwm_Setvalue(1000);
	while(1)
	{

	}
	return 1;
}

