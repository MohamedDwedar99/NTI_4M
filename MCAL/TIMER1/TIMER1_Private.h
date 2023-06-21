/*
 * TIMER1_Private.h
 *
 * Created: 6/19/2023 2:20:19 PM
 *  Author: es-MohamedHAbdelAziz
 */ 


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_


#define TCCR1A_Register  *((volatile u8 *)0x4F)
#define	TCCR1B_Register  *((volatile u8 *)0x4E)

#define	TCNT1L_Register  *((volatile u8 *)0x4C)
#define	TCNT1H_Register  *((volatile u8 *)0x4D)
#define TCNT1_Register   *((volatile u16 *)0x4C)

#define OCR1AL_Register  *((volatile u8 *)0x4A)
#define OCR1AH_Register  *((volatile u8 *)0x4B)
#define OCR1A_Register   *((volatile u16 *)0x4A)

#define OCR1BL_Register  *((volatile u8 *)0x48)
#define OCR1BH_Register  *((volatile u8 *)0x49)
#define OCR1B_Register   *((volatile u16 *)0x48)

#define ICR1L_Register   *((volatile u8 *)0x46)
#define ICR1H_Register   *((volatile u8 *)0x47)
#define ICR1_Register    *((volatile u16 *)0x46)

#ifndef  TIMSK_Register 
	#define TIMSK_Register *((volatile u8 *)0x56)
#endif

#ifndef  TIFR_Register
	#define TIFR_Register  *((volatile u8 *)0x58)
#endif





#endif /* TIMER1_PRIVATE_H_ */