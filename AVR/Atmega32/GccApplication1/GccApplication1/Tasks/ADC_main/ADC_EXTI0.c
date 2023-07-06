/*
 * ADC_EXTI0.c
 *
 * Created: 6/17/2023 8:17:55 PM
 *  Author: es-MohamedHAbdelAziz
 */ 
/*
 * Calculator.c
 *
 * Created: 6/16/2023 2:24:30 PM
 *  Author: es-MohamedHAbdelAziz
 */ 




#include "Services/BIT_MATH.h"
#include "Services/STD.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "ECU/KEYPAD/KEYPAD_Interface.h"
#include "ECU/LCD/LCD_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "ECU/Segment7/Segment7_Interface.h"
#include "MCAL/EXTI0/EXTI0_Interface.h"
#include "MCAL/ADC/ADC_Pirvate.h"
#include "MCAL/ADC/ADC_Interface.h"



/* 
**************Configs*****************
#define ADC_Channel0          1
#define ADC_Channel1          1
#define ADC_Channel2          1
#define ADC_Channel3          1
#define ADC_Channel4          1
#define ADC_Channel5          1
#define ADC_Channel6          1
#define ADC_Channel7          1

#define ADC_VOLT_REF          ADC_AVCC
#define ADC_ADJUST			  ADJUST_RIGH
#define ADC_PRESCALLER        PRESCALLER_128
#define ADC_TRIGGER           TRIG_EXTI0

#define ADC_AUTOTRIGGER       1
#define ADC_INTERRUPT         0

*/



void SET_FLAG(void);
u8 x = 0;
u16 read = 0;
int main(void)
{
	GInterupt_Enable();
	EXTI0_RisingEdgeInit();
	DIO_SetPinDirection(PIND2,PIN_INPUT);
	DIO_SetPinValue(PIND2,PIN_HIGH);
	ADC_Init();
	Segment7_Mult4Init();
	ADC_SetCallBack(SET_FLAG);
	ADC0_StartConversion();
	while(1)
	{
		if (GET_BIT(ADCSRA_Register,ADIF))
		{
			read = ADC_Read();
		}
		Segment7_Mult4SetDisplay(read);
		asm("NOP");
	}
	return 1;
}


void SET_FLAG(void)
{
	x = 1;
}