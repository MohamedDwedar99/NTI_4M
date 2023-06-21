/*
 * Timer_Private.h
 *
 * Created: 6/18/2023 11:00:24 AM
 *  Author: es-MohamedHAbdelAziz
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0_Register		*((volatile u8*)0x53)
#define TCNT0_Register      *((volatile u8*)0x52)
#define OCR0_Register       *((volatile u8*)0x5C)
#define TIMSK_Register     	*((volatile u8*)0x59)
#define TIFR_Register       *((volatile u8*)0x58)


/*TCCR0*/
#define CS00	0
#define CS01	1
#define CS02	2
#define WGM01	3
#define COM00	4
#define COM01	5
#define WGM00	6
#define FOC0	7
/*TIMSK*/
#define TOIE0 0
#define OCIE0 1
/*TIFR*/
#define TOV0 0
#define OCF0 1



#endif /* TIMER_PRIVATE_H_ */