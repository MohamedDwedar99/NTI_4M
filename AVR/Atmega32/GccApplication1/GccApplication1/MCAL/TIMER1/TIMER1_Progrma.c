/*
 * TIMER1_Progrma.c
 *
 * Created: 6/19/2023 2:19:38 PM
 *  Author: es-MohamedHAbdelAziz
 */ 

#include "../../Services/BIT_MATH.h"
#include "../../Services/STD.h"

#include "TIMER1_Config.h"
#include "TIMER1_Private.h"
#include "TIMER1_Interface.h"

void TIMER1Pwm_Init(void)
{
	SET_BIT(TCCR1A_Register,7);
	SET_BIT(TCCR1A_Register,1);
	
	SET_BIT(TCCR1B_Register,3);
	SET_BIT(TCCR1B_Register,4);
	
	ICR1_Register = 40000;
	
}


void TIMER1Normal_Init(void)
{
	// nothing to do
}

void TIMER1Pwm_Enable(void)
{
	SET_BIT(TCCR1B_Register,1);
}

void TIMER1Normal_Enable(void)
{
	SET_BIT(TCCR1B_Register,1);
}


void TIMER1Pwm_Setvalue(u16 value)
{
	OCR1A_Register = value;
}


void TIMER1Normal_Start(u8 first_count)
{
	//Set Starting Value
	TCNT1_Register = first_count;
	//Set Prescaler
	TCCR1B_Register = 2;
}

void TIMER1ICU_Init(void)
{
	
}

u16 TIMER1_OVRread(void)
{
	return TCNT1_Register;
}
void __vector_9 (void)
{
	
}