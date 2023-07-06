/*
 * ADC_Program.c
 *
 * Created: 6/17/2023 11:14:51 AM
 *  Author: es-MohamedHAbdelAziz
 */ 

#include "../../Services/BIT_MATH.h"
#include "../../Services/STD.h"

#include "../DIO/DIO_Interface.h"

#include "ADC_Pirvate.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"

void ADC_Init(void)
{
#if ADC_Channel0 == 1
	DIO_SetPinDirection(PINA0,PIN_INPUT);
#endif
#if ADC_Channel1 == 1
	DIO_SetPinDirection(PINA1,PIN_INPUT);
#endif
#if ADC_Channel2 == 1
	DIO_SetPinDirection(PINA2,PIN_INPUT);
#endif
#if ADC_Channel3 == 1
	DIO_SetPinDirection(PINA3,PIN_INPUT);
#endif
#if ADC_Channel4 == 1
	DIO_SetPinDirection(PINA4,PIN_INPUT);
#endif
#if ADC_Channel5 == 1
	DIO_SetPinDirection(PINA5,PIN_INPUT);
#endif
#if ADC_Channel6 == 1
	DIO_SetPinDirection(PINA6,PIN_INPUT);
#endif
#if ADC_Channel7 == 1
	DIO_SetPinDirection(PINA7,PIN_INPUT);
#endif
	ADMUX_Register = 0;
	/*Adjust Data Register*/
	#if ADC_ADJUST == ADJUST_LEFT
		SET_BIT(ADMUX_Register,ADLAR);
	#elif ADC_ADJUST == ADJUST_RIGH
		CLR_BIT(ADMUX_Register,ADLAR);
	#endif
	ADMUX_Register |= ADC_VOLT_REF << REFS;
	ADCSRA_Register = 0;
	/*Enable ADC*/
		ADCSRA_Register = 1 << ADEN;
	/*Check Auto Trigger*/
	#if ADC_AUTOTRIGGER == 1
		ADCSRA_Register |= 1 << ADATE;
		SFIOR_Register &= ~0b00011111;
		SFIOR_Register |= ADC_TRIGGER << ADTS;
	#endif
	/*Check Interrupt*/
	#if ADC_INTERRUPT == 1
		ADCSRA_Register |= 1 << ADIE;
	#endif
	/*Select Prescaller*/
	ADCSRA_Register |= ADC_PRESCALLER << ADPS;
}


void ADC_TurnON(void)
{
	ADCSRA_Register = 1 << ADEN;
}
void ADC_TurnOFF(void)
{
	CLR_BIT(ADCSRA_Register,ADEN);
}

u16 ADC_Read(void)
{
	u16 read;
	#if ADC_INTERRUPT == 1
		SET_BIT(ADCSRA_Register,ADIF);
	#else
		while(!GET_BIT(ADCSRA_Register,ADIF));
		SET_BIT(ADCSRA_Register,ADIF);
	#endif
	read = ADC_Register;
	return read;
}
void ADC0_StartConversion(void)
{
	ADMUX_Register &= ~0b11111;
	ADMUX_Register |= MUX_ADC0;
	ADCSRA_Register |= 1 << ADSC;
}
void ADC1_StartConversion(void)
{
	ADMUX_Register &= ~0b11111;
	ADMUX_Register |= MUX_ADC1;
	ADCSRA_Register |= 1 << ADSC;
}
void ADC2_StartConversion(void)
{
	ADMUX_Register &= ~0b11111;
	ADMUX_Register |= MUX_ADC2;
	ADCSRA_Register |= 1 << ADSC;
}
void ADC3_StartConversion(void)
{
	ADMUX_Register &= ~0b11111;
	ADMUX_Register |= MUX_ADC3;
	ADCSRA_Register |= 1 << ADSC;
}
void ADC4_StartConversion(void)
{
	ADMUX_Register &= ~0b11111;
	ADMUX_Register |= MUX_ADC4;
	ADCSRA_Register |= 1 << ADSC;
}
void ADC5_StartConversion(void)
{
	ADMUX_Register &= ~0b11111;
	ADMUX_Register |= MUX_ADC5;
	ADCSRA_Register |= 1 << ADSC;
}
void ADC6_StartConversion(void)
{
	ADMUX_Register &= ~0b11111;
	ADMUX_Register |= MUX_ADC6;
	ADCSRA_Register |= 1 << ADSC;
}
void ADC7_StartConversion(void)
{
	ADMUX_Register &= ~0b11111;
	ADMUX_Register |= MUX_ADC7;
	ADCSRA_Register |= 1 << ADSC;
}
void (*ADC_CALLBACK)(void) = NULL;

void ADC_DiffA0A1(void)
{
	ADMUX_Register &= ~0b11111;
	ADMUX_Register |= 0b10000;
	ADCSRA_Register |= 1 << ADSC;
}


void ADC_SetCallBack(void (*CALLBACK)(void))
{
	ADC_CALLBACK = CALLBACK;
}
void __vector_16 (void)
{
	ADC_CALLBACK();
}


u16  ADC_Mapping(u16 y ,u16 y1 ,u16 y2,u16 x1, u16 x2)
{
	u16 x = 0;
	x = (y-y1)*((f32)(x2-x1)/(y2-y1))+1;
	return x;
}