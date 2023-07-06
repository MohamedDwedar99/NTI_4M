/*
 * STK_Private.h
 *
 *  Created on: Jun 25, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#ifndef STK_STK_PRIVATE_H_
#define STK_STK_PRIVATE_H_

typedef struct
{
	volatile u32	CTRL;
	volatile u32	LOAD;
	volatile u32	VAL;
	volatile u32	CALIB;

}STK_type;

#define			STK				((volatile STK_type *) (0xE000E010))

#define			SINGLE_INTERVALE			0
#define			PERIOD_INTERVALE			1

#endif /* STK_STK_PRIVATE_H_ */
