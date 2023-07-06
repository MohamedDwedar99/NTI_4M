/*
 * TIMER1_Interface.h
 *
 * Created: 6/19/2023 2:20:02 PM
 *  Author: es-MohamedHAbdelAziz
 */ 


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_


void TIMER1Pwm_Init(void);
void TIMER1Pwm_Enable(void);
void TIMER1Pwm_Setvalue(u16 value);

void TIMER1Normal_Init(void);

void TIMER1Normal_Enable(void);
u16 TIMER1_OVRread(void);
void TIMER1Normal_Start(u8 first_count);



void __vector_ (void) __attribute__((signal,used));


#endif /* TIMER1_INTERFACE_H_ */