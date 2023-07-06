/*
 * EXTI0_Private.h
 *
 * Created: 6/16/2023 12:33:56 PM
 *  Author: es-MohamedHAbdelAziz
 */ 


#ifndef EXTI0_PRIVATE_H_
#define EXTI0_PRIVATE_H_


#define MCUCR_Register	*((volatile u8*)0x55)
#define	MCUCSR_Register *((volatile u8*)0x54)
#define GICR_Register   *((volatile u8*)0x5B)
#define GIFR_Register   *((volatile u8*)0x5A)

//MCUCR
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

//MCUCSR
#define ISC2 6

//GICR
#define INT0 6
#define INT1 7
#define INT2 5

//GIFR
#define INTF0 6
#define INTF1 7
#define INTF2 5



#endif /* EXTI0_PRIVATE_H_ */