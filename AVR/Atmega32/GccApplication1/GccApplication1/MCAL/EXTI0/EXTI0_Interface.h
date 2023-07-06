/*
 * EXTI0_Interface.h
 *
 * Created: 6/16/2023 12:33:11 PM
 *  Author: es-MohamedHAbdelAziz
 */ 


#ifndef EXTI0_INTERFACE_H_
#define EXTI0_INTERFACE_H_

// MODE
#define LOW_LEVEL       0
#define ON_CHANGE       1
#define FAILING_EDGE    2
#define RISING_EDGE     3


void EXTI0_LowLevelInit(void);
void EXTI0_FailingEdgeInit(void);
void EXTI0_RisingEdgeInit(void);
void EXTI0_AnyChangeInit(void);
void EXTI0_ChangeMode(u8 MODE);

/*Enable*/
void EXTI0_Enable(void);

/*Disable*/
void EXTI0_Disable(void);

/*Clear Flag By Adding Logical 1*/
void EXTI0_ClearFlag(void);

void EXTI0_SetCallBack(void (* func)(void));


void __vector_1 (void) __attribute__((signal,used));

#endif /* EXTI0_INTERFACE_H_ */