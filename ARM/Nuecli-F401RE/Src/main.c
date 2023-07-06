/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "Std_Types.h"
#include "Bit_Math.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "NVIC_Interface.h"
#include "STK_Interface.h"

#include "DMA_Interface.h"

void _delay_ms(u32 delay)
{
	u32 i;
	for(i = 0; i < 1000*delay ;i++)
	{
		asm("NOP");
	}
}

void TOG(void);

u32 arr1[1000];
u32 arr2[1000];

u32 arr3[1000];
u32 arr4[1000];
int main(void)
{
    /* Loop forever */
	RCC_voidSysClkInit();
	RCC_voidEnablePerClk(RCC_AHB1, 21);

	for (u16 i = 0; i < 1000;i++)
	{
		arr1[i] = i;
	}
	for (u16 i = 0; i < 1000;i++)
	{
		arr2[i] = i;
	}

	DMA1_voidChannelInit(0,DMA_Memory,DMA_Memory);
	DMA1_voidStartChannel(DMA_Channel1, arr1, arr3, 1000);
	NVIC_voidInit();
	NVIC_voidEnablePerInt(18);

	for (u16 i = 0; i < 100; i++)
	{
		arr4[i] = arr2[i];
	}

	while(1)
	{
		asm("NOP");
	}
}

void TOG(void)
{
	GPIO_voidTogPinValue(PORTA, PIN5);
}

void DMA1_Channely_IRQHandler (void)
{
	while(1);
}