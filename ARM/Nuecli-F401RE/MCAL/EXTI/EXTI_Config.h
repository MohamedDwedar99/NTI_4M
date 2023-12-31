/*
 * EXTI_Config.h
 *
 *  Created on: Jun 25, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#ifndef EXTI_EXTI_CONFIG_H_
#define EXTI_EXTI_CONFIG_H_

#define		EXTI_BASE_ADD			0x40010400


typedef struct
{
	volatile	u32		IMR;
	volatile	u32		EMR;
	volatile	u32		RTSR;
	volatile	u32		FTSR;
	volatile	u32		SWIER;
	volatile	u32		PR;

}EXTI_Type;


#define PORTA 0
#define PORTB 1
#define PORTC 2

#define			EXTI				((EXTI_Type *)(EXTI_BASE_ADD))

#endif /* EXTI_EXTI_CONFIG_H_ */
