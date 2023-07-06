/*
 * NVIC_Interface.h
 *
 *  Created on: Jun 24, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#ifndef NVIC_NVIC_INTERFACE_H_
#define NVIC_NVIC_INTERFACE_H_

void		NVIC_voidInit(void);

void		NVIC_voidEnablePerInt(u8 IntNum);
void		NVIC_voidDisablePerInt(u8 IntNum);

void		NVIC_voidSetPendingFlag(u8 IntNum);
void		NVIC_voidClrPendingFlag(u8 IntNum);

u8			NVIC_u8ReadActiveFlag(u8 IntNum);

void		NVIC_voidSetSwIntPriority(u8 IntNum , u8 priority);

#endif /* NVIC_NVIC_INTERFACE_H_ */
