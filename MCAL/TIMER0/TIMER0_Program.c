/*
 * TIMER0_Program.c
 *
 * Created: 6/18/2023 10:59:38 AM
 *  Author: es-MohamedHAbdelAziz
 */ 
#include "../../Services/BIT_MATH.h"
#include "../../Services/STD.h"

#include "TIMER0_Config.h"
#include "Timer0_Private.h"
#include "TIMER0_Interface.h"


void (*FUNC_PTR)(void) = NULL;

void TIMER0Normal_Init(void)
{
	//Set Mode
	CLR_BIT(TCCR0_Register,WGM00);
	CLR_BIT(TCCR0_Register,WGM01);
	//Enable Interrupt
	SET_BIT(TIMSK_Register,TOIE0);
}
void TIMER0Normal_Start(u8 first_count)
{
	//Set Prescaler
	TCCR0_Register = (TCCR0_Register & !7) | Timer_Prescaler;
	//Set Starting Value
	TCNT0_Register = first_count;
}
/*void TIMER0PwmPhaseCorrect_Init(void)
{
	//Set Mode
	SET_BIT(TCCR0_Register,WGM00);
	CLR_BIT(TCCR0_Register,WGM01);
	//Set Starting Value
	TCNT0_Register = Initial_Count;
	//Enable Interrupt
	SET_BIT(TIFR_Register,TOV0);
	//Set Prescaler
	TCCR0_Register = (TCCR0_Register & 7) | Timer_Prescaler;
}*/
void TIMER0CTC_Init(void)
{
	//Set Mode
	CLR_BIT(TCCR0_Register,WGM00);
	SET_BIT(TCCR0_Register,WGM01);
	//Set Starting Value
	OCR0_Register = Compare_Count;
	//Enable Interrupt
	SET_BIT(TIMSK_Register,OCIE0);
	//Set Prescaler
	TCCR0_Register = (TCCR0_Register & !7) | Timer_Prescaler;
}
void TIMER0PwmFast_Init(void)
{
	//Set Mode
	SET_BIT(TCCR0_Register,WGM00);
	SET_BIT(TCCR0_Register,WGM01);
	//Set Starting Value
	TCNT0_Register = 0;
	//Enable Interrupt
	SET_BIT(TCCR0_Register,COM01);
}

void TIMER0PwmFast_Duty(u8 Duty)
{
	OCR0_Register = (u8)((f32)Duty/100 * 255);
	//Set Prescaler
	TCCR0_Register = (TCCR0_Register & 0b11111000) | 5;
}

void TINER0_SetCallBack(void (* CallBackFuch)(void))
{
	CLR_BIT(TIFR_Register,0);
	FUNC_PTR = CallBackFuch;
}
void __vector_10(void)
{
	//FUNC_PTR();
}
void __vector_11(void)
{
	FUNC_PTR();
}
