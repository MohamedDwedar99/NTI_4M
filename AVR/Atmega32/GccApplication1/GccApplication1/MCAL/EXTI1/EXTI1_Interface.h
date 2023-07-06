/*
 * EXTI0_Interface.h
 *
 * Created: 6/16/2023 12:33:11 PM
 *  Author: es-MohamedHAbdelAziz
 */ 


#ifndef EXTI0_INTERFACE_H_
#define EXTI0_INTERFACE_H_




void EXTI1_LowLevelInit(void);
void EXTI1_FailingEdgeInit(void);
void EXTI1_RisingEdgeInit(void);
void EXTI1_AnyChangeInit(void);


/*Enable*/
void EXTI1_Enable(void);

/*Disable*/
void EXTI1_Disable(void);

/*Clear Flag By Adding Logical 1*/
void EXTI1_ClearFlag(void);

void EXTI1_SetCallBack(void (* func)(void));


void __vector_2 (void) __attribute__((signal,used));

#endif /* EXTI0_INTERFACE_H_ */