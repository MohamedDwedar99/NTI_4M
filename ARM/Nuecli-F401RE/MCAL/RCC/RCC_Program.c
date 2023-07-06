/*
 * RCC_Program.c
 *
 *  Created on: Jun 23, 2023
 *      Author: es-MohamedHAbdelAziz
 */


#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_Interface.h"

#include	"RCC_Private.h"
#include	"RCC_Config.h"

void	RCC_voidSysClkInit(void)
{
	RCC->CR &= 0b11111 << CR_HSITRIM;
#if HSI == ON
	// Enable Internal Clock
	RCC->CR |= (1 << CR_HSION);
	// Waiting Internal Ready
	while(!GET_BIT(RCC->CR,CR_HSIRDY));
#endif

#if HSE == ON
	// Enable External Clock
	RCC->CR |= (1 << CR_HSEON);
	// Waiting External Ready
	while(!GET_BIT(RCC->CR,CR_HSERDY));
#endif

#if PLL == ON
	// Enable PLL Clock
	RCC->CR |= (1 << CR_PLLON);
	// Waiting PLL Ready
	while(!GET_BIT(RCC->CR,CR_PLLRDY));
#endif

// Select Sys Clock
#if CLK_SRC == HSI_SRC
	RCC->CFGR |= HSI_ON;
#elif CLK_SRC == CLK_HSE
	RCC->CFGR |= HSE_ON;
	#if HSE == OFF
		#error "Wrong Clock Selection"
	#endif
#elif CLK_SRC == CLK_PLL
	RCC->CFGR |= PLL_ON;
#if PLL == OFF
	#error "Wrong Clock Selection"
#endif
#endif

	// AHP Prescaller
	RCC->CFGR |= AHP_PRESCALLER << CFGR_HPRE;
	// APB1 Prescaller
	RCC->CFGR |= APB1_PRESCALLER << CFGR_PPRE1;
	// APB2 Prescaller
	RCC->CFGR |= APB2_PRESCALLER << CFGR_PPRE2;
}

//RCC_voidEnablePerClk(RCC_AHB1,0);

void	RCC_voidEnablePerClk(u8 BusId , u8 PerId)
{
	/*		Range Check		*/
	if(BusId < 3 && PerId < 32)
	{
		switch(BusId)
		{
			case RCC_AHB1 :	SET_BIT(RCC->AHB1ENR,PerId);		break;
			case RCC_APB1 :	SET_BIT(RCC->APB1ENR,PerId);		break;
			case RCC_APB2 :	SET_BIT(RCC->APB2ENR,PerId);		break;
		}
	}else{	/*	Report Error  */}

}

void	RCC_voidDisablePerClk(u8 BusId , u8 PerId)
{
		/*		Range Check		*/
	if(BusId < 3 && PerId < 32)
	{
		switch(BusId)
		{
			case RCC_AHB1 :	CLR_BIT(RCC->AHB1ENR,PerId);		break;
			case RCC_APB1 :	CLR_BIT(RCC->APB1ENR,PerId);		break;
			case RCC_APB2 :	CLR_BIT(RCC->APB2ENR,PerId);		break;
		}
	}else{	/*	Report Error  */}

}
