/*
 * WDG_Private.h
 *
 * Created: 7/5/2023 8:54:29 PM
 *  Author: es-MohamedHAbdelAziz
 */ 


#ifndef WDG_PRIVATE_H_
#define WDG_PRIVATE_H_


#define WDTCR_Register   *((volatile u8 *)0x41)
#define MCUCSR_Register  *((volatile u8 *)0x54)


#define WDP      0
#define WDP0     0
#define WDP1     1
#define WDP2     2
#define WDE      3
#define WDTOE    4


#define WDRF     3





#endif /* WDG_PRIVATE_H_ */