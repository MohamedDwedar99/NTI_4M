/*
 * EXTI0_Program.c
 *
 * Created: 6/16/2023 12:32:51 PM
 *  Author: es-MohamedHAbdelAziz
 */ 


/*Interrupt_0 Initialization & program*/

#include "../../Services/BIT_MATH.h"
#include "../../Services/STD.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "EXTI0_Private.h"
#include "EXTI0_Interface.h"


static void (*func_CallBack)(void) = NULL;

void EXTI0_LowLevelInit(void)
{
	CLR_BIT(MCUCR_Register,ISC00);
	CLR_BIT(MCUCR_Register,ISC01);
	EXTI0_Enable();
	DIO_SetPinDirection(PIND2,PIN_INPUT);
	DIO_SetPinValue(PIND2,PIN_HIGH);
}
void EXTI0_FailingEdgeInit(void)
{
	CLR_BIT(MCUCR_Register,ISC00);
	SET_BIT(MCUCR_Register,ISC01);
	EXTI0_Enable();
	DIO_SetPinDirection(PIND2,PIN_INPUT);
	DIO_SetPinValue(PIND2,PIN_HIGH);
}
void EXTI0_RisingEdgeInit(void)
{
	SET_BIT(MCUCR_Register,ISC00);
	SET_BIT(MCUCR_Register,ISC01);
	EXTI0_Enable();
	DIO_SetPinDirection(PIND2,PIN_INPUT);
	DIO_SetPinValue(PIND2,PIN_HIGH);
}
void EXTI0_AnyChangeInit(void)
{
	SET_BIT(MCUCR_Register,ISC00);
	CLR_BIT(MCUCR_Register,ISC01);
	EXTI0_Enable();
	DIO_SetPinDirection(PIND2,PIN_INPUT);
	DIO_SetPinValue(PIND2,PIN_HIGH);
}

void EXTI0_Enable(void)
{
	SET_BIT(GICR_Register,INT0);
}

void EXTI0_Disable(void)
{
	CLR_BIT(GICR_Register,INT0);
}

void EXTI0_ClearFlag(void)
{
	SET_BIT(GICR_Register,INTF0);
}


void EXTI0_SetCallBack(void ( *func)(void) )
{
	func_CallBack = func;
}

void __vector_1 (void){
	func_CallBack();
}