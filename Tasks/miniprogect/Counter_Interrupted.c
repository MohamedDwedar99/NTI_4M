/*
 * Counter_Interrupted.c
 *
 * Created: 6/16/2023 2:27:45 PM
 *  Author: es-MohamedHAbdelAziz
 */ 
#define F_CPU 16000000UL

#include <util/delay.h>
#include "Services/BIT_MATH.h"
#include "Services/STD.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "ECU/LED/LED_Interface.h"
#include "ECU/Segment7/Segment7_Interface.h"
#include "ECU/LCD/LCD_Interface.h"
#include "ECU/KEYPAD/KEYPAD_Interface.h"
#include "ECU/BUZZER/BUZZER_Interface.h"
#include "MCAL/EXTI0/EXTI0_Interface.h"
#include "MCAL/EXTI1/EXTI1_Interface.h"
#include "MCAL/GInterrupt/GIE_Interface.h"




u16 SegNum = 0;

void SegUP(void);
void Segreset(void);


int main(void)
{
	GInterupt_Enable();
	EXTI0_RisingEdgeInit();
	EXTI1_RisingEdgeInit();
	EXTI0_SetCallBack(SegUP);
	EXTI1_SetCallBack(Segreset);
	DIO_SetPinDirection(PINA5,PIN_INPUT);
	DIO_SetPinValue(PINA5,PIN_HIGH);
	while(1)
	{
		DIO_SetPinValue(PINA5,PIN_HIGH);
		asm("NOP");
	}
}


void SegUP(void)
{
	GInterupt_Enable();
	DIO_SetPinValue(PINA5,PIN_LOW);
	while(1);
}

void Segreset(void)
{
	DIO_SetPinValue(PINA5,PIN_HIGH);
	_delay_ms(25);
}