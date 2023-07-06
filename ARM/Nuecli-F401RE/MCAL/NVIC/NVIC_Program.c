/*
 * NVIC_Program.c
 *
 *  Created on: Jun 24, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#include "Std_Types.h"
#include "Bit_Math.h"

#include "NVIC_Config.h"
#include "NVIC_Private.h"
#include "NVIC_Interface.h"


void		NVIC_voidInit(void)
{
#ifndef SCB_AIRCR
#define SCB_BASE_ADD    0xE000ED00
#define SCB_AIRCR        *((volatile u32 * )(SCB_BASE_ADD + 0x0C))
#endif
	SCB_AIRCR = 0x05FA0600;
}

void		NVIC_voidEnablePerInt(u8 IntNum)
{
	if (IntNum < 32)
	{
		NVIC_ISER0 = 1 << IntNum;
	}
	else if (IntNum < 64)
	{
		IntNum -= 32;
		NVIC_ISER1 = 1 << IntNum;
	}
}
void		NVIC_voidDisablePerInt(u8 IntNum)
{
	if (IntNum < 32)
	{
		NVIC_ICER0 = 1 << IntNum;
	}
	else if (IntNum < 64)
	{
		IntNum -= 32;
		NVIC_ICER1 = 1 << IntNum;
	}
}

void		NVIC_voidSetPendingFlag(u8 IntNum)
{
	if (IntNum < 32)
	{
		NVIC_ISPR0 = 1 << IntNum;
	}
	else if (IntNum < 64)
	{
		IntNum -= 32;
		NVIC_ISPR1 = 1 << IntNum;
	}
}
void		NVIC_voidClrPendingFlag(u8 IntNum)
{
	if (IntNum < 32)
	{
		NVIC_ICPR0 = 1 << IntNum;
	}
	else if (IntNum < 64)
	{
		IntNum -= 32;
		NVIC_ICPR1 = 1 << IntNum;
	}
}

u8			NVIC_u8ReadActiveFlag(u8 IntNum)
{
	u8 read = 99;
	if (IntNum < 32)
	{
		read = GET_BIT(NVIC_IABR0, IntNum);
	}
	else if (IntNum < 64)
	{
		IntNum -= 32;
		read = GET_BIT(NVIC_IABR1, IntNum);
	}
	return read;
}

void		NVIC_voidSetSwIntPriority(u8 IntNum , u8 priority)
{
	if (IntNum < 64 && priority < 16)
	{
		NVIC_IPR[IntNum] = priority << 4;
	}
}
