/*
 * TIMER0_Interface.h
 *
 * Created: 6/18/2023 11:00:02 AM
 *  Author: es-MohamedHAbdelAziz
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


void TIMER0Normal_Init(void);
void TIMER0PwmPhaseCorrect_Init(void);
void TIMER0CTC_Init(void);
void TIMER0PwmFast_Init(void);
void TIMER0PwmFast_Duty(u8 Duty);

void TIMER0Normal_Start(u8 first_count);
void TINER0_SetCallBack(void (* CallBackFuch)(void));

void __vector_10 (void) __attribute__((signal,used));
void __vector_11 (void) __attribute__((signal,used));

#endif /* TIMER0_INTERFACE_H_ */