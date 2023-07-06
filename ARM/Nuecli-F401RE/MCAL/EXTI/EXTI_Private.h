/*
 * EXTI_Private.h
 *
 *  Created on: Jun 25, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#ifndef EXTI_EXTI_PRIVATE_H_
#define EXTI_EXTI_PRIVATE_H_

#define RISING_EDGE   0
#define FALLING_EDGE  1
#define IOC           2



void		EXTI0_voidInit(void);
void		EXTI_voidEnableInt(u8 line_num);
void		EXTI_voidDisableInt(u8 line_num);

void		EXTI_voidEnableSWI(u8 line_num);
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode);


void		EXTI0_voidSetCallBack(void (*Fptr)(void));


#endif /* EXTI_EXTI_PRIVATE_H_ */
