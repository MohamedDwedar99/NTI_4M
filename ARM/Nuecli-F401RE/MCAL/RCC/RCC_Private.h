/*
 * RCC_Private.h
 *
 *  Created on: Jun 23, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#ifndef RCC_RCC_PRIVATE_H_
#define RCC_RCC_PRIVATE_H_

#define		RCC_BASE_ADD		((u32)0x40023800)



typedef		struct
{	u32				CR;
	u32				PLLCFGR;
	u32				CFGR;
	u32				CIR;
	u32				AHB1RSTR;
	u32				AHB2RSTR;
	u32				reserved1;
	u32				reserved2;
	u32				APB1RSTR;
	u32				APB2RSTR;
	u32				reserved3;
	u32				reserved4;
	u32				AHB1ENR;
	u32				AHB2ENR;
	u32				reserved5;
	u32				reserved6;
	u32				APB1ENR;
	u32				APB2ENR;
	u32				reserved7;
	u32				reserved8;
	u32				AHB1LPENR;
	u32				AHB2LPENR;
	u32				reserved9;
	u32				reserved10;
	u32				APB1LPENR;
	u32				APB2LPENR;
	u32				reserved11;
	u32				reserved12;
	u32				BDCR;
	u32				CSR;
	u32				reserved13;
	u32				reserved14;
	u32				SSCGR;
	u32				PLLI2SCFGR;
	u32				reserved15;
	u32				DCKCFGR;
}RCC_Types;

#define		RCC		((volatile RCC_Types*)(RCC_BASE_ADD))

// RCC CR
#define CR_HSION       0
#define CR_HSIRDY      1
#define CR_HSITRIM     3
#define CR_HSICAL      8
#define CR_HSEON       16
#define CR_HSERDY      17
#define CR_HSEBYP      18
#define CR_CSSON       19
#define CR_PLLON       24
#define CR_PLLRDY      25
#define CR_PLL2SON     26
#define CR_PLL2SRDY    27

// RCC PLLCFGR
#define PLLCFGR_PLLM   0
#define PLLCFGR_PLLN   6
#define PLLCFGR_PLLP   16
#define PLLCFGR_PLLSRC 22
#define PLLCFGR_PLLQ   24

// RCC CFGR
#define CFGR_SW        0
#define CFGR_SWS       2
#define CFGR_HPRE      4
#define CFGR_PPRE1     10
#define CFGR_PPRE2     13
#define CFGR_RTCPRE    16
#define CFGR_MCO1      21
#define CFGR_I2SSCR    23
#define CFGR_MCO1PRE   24
#define CFGR_MCO2PRE   27
#define CFGR_MCO2      30




#define OFF       0
#define ON        1

#define CLK_HSI   0
#define CLK_HSE   1
#define CLK_PLL   2


#define HSI_ON    00
#define HSE_ON    01
#define PLL_ON    10


#define AHP_SYS_PRE_1       0
#define AHP_SYS_PRE_2       8
#define AHP_SYS_PRE_4		9
#define AHP_SYS_PRE_8		10
#define AHP_SYS_PRE_16	   	11
#define AHP_SYS_PRE_64	   	12
#define AHP_SYS_PRE_128	    13
#define AHP_SYS_PRE_256	    14
#define AHP_SYS_PRE_512	    15




#define APB_AHP_PRE_1       0
#define APB_AHP_PRE_2      	4
#define APB_AHP_PRE_4		5
#define APB_AHP_PRE_8		6
#define APB_AHP_PRE_16	   	7



#endif /* RCC_RCC_PRIVATE_H_ */
