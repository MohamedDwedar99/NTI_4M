/*
 * HW_ICU.c
 *
 * Created: 7/2/2023 12:31:18 PM
 *  Author: es-MohamedHAbdelAziz
 */ 
/*
 * Calculator.c
 *
 * Created: 6/16/2023 2:24:30 PM
 *  Author: es-MohamedHAbdelAziz
 */ 

#define F_CPU  8000000UL

#include <util/delay.h>

#include "Services/BIT_MATH.h"
#include "Services/STD.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/EXTI0/EXTI0_Interface.h"
#include "MCAL/TIMER0/TIMER0_Interface.h"
#include "MCAL/TIMER1/TIMER1_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"

#include "ECU/LED/LED_Interface.h"
#include "ECU/LCD/LCD_Interface.h"
#include "MCAL/TIMER1/TIMER1_Interface.h"



void ICU (void);
u8* NumToArr(u16 num);

u16 Preiod_Time;
u16 rising_Time;

int main(void)
{
	DIO_SetPinDirection(PINA0,PIN_INPUT);
	
	DIO_SetPinDirection(PINB3,PIN_OUTPUT);
	
	TIMER0PwmFast_Init();
	
	TIMER1Normal_Enable();

	
	EXTI0_RisingEdgeInit();
	EXTI0_SetCallBack(ICU);

	ADC_Init();

	
	LCD_Init();
	LCD_WriteString("DUTY: ");
	GInterupt_Enable();
	//EXTI0_Enable();
	u8 DUTY_SET = 0;
	ADC0_StartConversion();
	while(1)
	{
		DUTY_SET = ADC_Read();	
		TIMER0PwmFast_Duty( (f32)DUTY_SET /1024 * 60);
		
		u16 duty = (f32)rising_Time / Preiod_Time*100;
		_delay_ms(100);
		//GInterupt_Disable();
		LCD_GOTO(0,6);
		LCD_WriteString(NumToArr(duty));
		//GInterupt_Enable();
		
	}
	return 1;
}


void ICU (void)
{
	u8 static flag = 0;
	if (flag == 0)
	{
		Preiod_Time = TIMER1_OVRread();
		TIMER1Normal_Start(0);
		EXTI0_ChangeMode(FAILING_EDGE);
		flag = 1;
	}
	else
	{
		rising_Time = TIMER1_OVRread();
		EXTI0_ChangeMode(RISING_EDGE);
		flag = 0;
	}
}


u8* NumToArr(u16 num){
	u8 arr[6] = {0};
	static u8 arr2[6] = {0};
	s16 i = 0;
	s16 j = 0;
	do
	{
		arr[i] = num%10;
		num /= 10;
		i++;
	}while(num > 0);
	while((i) > 0)
	{
		i--;
		arr2[j] = arr[i] + '0';
		j++;
	}
	arr2[j] = '\0';
	return arr2;
}