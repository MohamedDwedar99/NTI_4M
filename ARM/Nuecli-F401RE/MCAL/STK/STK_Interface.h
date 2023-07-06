/*
 * STK_Interface.h
 *
 *  Created on: Jun 25, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#ifndef STK_STK_INTERFACE_H_
#define STK_STK_INTERFACE_H_


void	STK_voidInit();
void	STK_voidBusyWait(u32 Ticks);
void	STK_voidSingleInterval(u32 Ticks , void (*Pf)(void));
void	STK_voidPeriodicInterval(u32 Ticks , void (*Pf)(void));
void	STK_voidStopInterval();

#endif /* STK_STK_INTERFACE_H_ */
