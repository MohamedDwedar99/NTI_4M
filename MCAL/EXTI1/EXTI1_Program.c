/*
 * EXTI0_Program.c
 *
 * Created: 6/16/2023 12:32:51 PM
 *  Author: es-MohamedHAbdelAziz
 */ 


/*Interrupt_0 Initialization & program*/

/*Interrupt_1 Initialization & program*/

#include "../../Services/BIT_MATH.h"
#include "../../Services/STD.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "EXTI1_Private.h"
#include "EXTI1_Interface.h"

static void (*func_CallBack)(void) = NULL;

void EXTI1_LowLevelInit(void)
{
	CLR_BIT(MCUCR_Register,ISC10);
	CLR_BIT(MCUCR_Register,ISC11);
	EXTI1_Enable();
	DIO_SetPinDirection(PIND3,PIN_INPUT);
	DIO_SetPinValue(PIND3,PIN_HIGH);
}
void EXTI1_FailingEdgeInit(void)
{
	CLR_BIT(MCUCR_Register,ISC10);
	SET_BIT(MCUCR_Register,ISC11);
	EXTI1_Enable();
	DIO_SetPinDirection(PIND3,PIN_INPUT);
	DIO_SetPinValue(PIND3,PIN_HIGH);
}
void EXTI1_RisingEdgeInit(void)
{
	SET_BIT(MCUCR_Register,ISC10);
	SET_BIT(MCUCR_Register,ISC11);
	EXTI1_Enable();
	DIO_SetPinDirection(PIND3,PIN_INPUT);
	DIO_SetPinValue(PIND3,PIN_HIGH);
}
void EXTI1_AnyChangeInit(void)
{
	SET_BIT(MCUCR_Register,ISC10);
	CLR_BIT(MCUCR_Register,ISC11);
	EXTI1_Enable();
	DIO_SetPinDirection(PIND3,PIN_INPUT);
	DIO_SetPinValue(PIND3,PIN_HIGH);
}

void EXTI1_Enable(void)
{
	SET_BIT(GICR_Register,INT1);
}

void EXTI1_Disable(void)
{
	CLR_BIT(GICR_Register,INT1);
}

void EXTI1_ClearFlag(void)
{
	SET_BIT(GICR_Register,INTF1);
}


void EXTI1_SetCallBack(void (* func)(void))
{
	func_CallBack = func;
}

void __vector_2 (void)
{
	func_CallBack();	
}