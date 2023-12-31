/*
 * EXTI_Program.c
 *
 *  Created on: Jun 25, 2023
 *      Author: es-MohamedHAbdelAziz
 */


#include "Bit_Math.h"
#include "Std_Types.h"

#include "EXTI_Private.h"
#include "EXTI_Config.h"
#include "EXTI_Interface.h"


#ifndef		NULL
#define		NULL			((void *)0)
#endif


static	void	(*EXTI0_CallBack)	(void)	= NULL;

void		EXTI0_voidInit(void)
{
#ifndef AFIO_EXTICR1
#define AFIO_BASE_ADD  0x40010000
#define AFIO_EXTICR1   *((u8 *)(0x40010000 + 0x08))
#endif
	// Clear location
	AFIO_EXTICR1 &= ~0b1111;
	// SET location
	AFIO_EXTICR1 |= PORTA;

}
void		EXTI_voidEnableInt(u8 line_num)
{
	SET_BIT(EXTI -> IMR,line_num);
}
void		EXTI_voidDisableInt(u8 line_num)
{
	CLR_BIT(EXTI -> IMR,line_num);
}

void		EXTI_voidEnableSWI(u8 line_num)
{
	SET_BIT(EXTI -> SWIER,line_num);
}
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode)
{
	switch(Sense_Mode)
	{
		case	RISING_EDGE		:	SET_BIT(EXTI -> RTSR,line_num);
									CLR_BIT(EXTI -> FTSR,line_num);		break;
		case	FALLING_EDGE	:	SET_BIT(EXTI -> FTSR,line_num);
									CLR_BIT(EXTI -> RTSR,line_num);		break;
		case	IOC				:	SET_BIT(EXTI -> RTSR,line_num);
									SET_BIT(EXTI -> FTSR,line_num);		break;
	}
	SET_BIT(EXTI -> IMR,line_num);
}

void		EXTI0_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI0_CallBack = Fptr;
	}
}

void	EXTI0_IRQHandler(void)
{

	/*	Clear the Flag			*/
	EXTI0_CallBack();
	SET_BIT(EXTI->PR,6);
}

