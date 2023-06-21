/*
 * Counter.c
 *
 * Created: 6/16/2023 2:22:54 PM
 *  Author: es-MohamedHAbdelAziz
 */ 
/*
 * GccApplication1.c
 *
 * Created: 6/10/2023 2:28:29 AM
 * Author : es-MohamedHAbdelAziz
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
	Segment7_Mult4Init();
	EXTI0_SetCallBack(SegUP);
	EXTI1_SetCallBack(Segreset);
	
	while(1)
	{
		Segment7_Mult4SetDisplay(SegNum);
		asm("NOP");
	}
}


void SegUP(void)
{
	SegNum++;
	_delay_ms(25);
}

void Segreset(void)
{
	SegNum = 0;
	_delay_ms(25);
}