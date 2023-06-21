/*
 * ADC_Pirvate.h
 *
 * Created: 6/17/2023 11:14:04 AM
 *  Author: es-MohamedHAbdelAziz
 */ 


#ifndef ADC_PIRVATE_H_
#define ADC_PIRVATE_H_


#define ADMUX_Register       *((volatile u8*)0x27)
#define ADCSRA_Register      *((volatile u8*)0x26)
#define ADCH_Register        *((volatile u8*)0x25)
#define ADCL_Register        *((volatile u8*)0x24)
#define ADC_Register         *((volatile u16*)0x24)
#define SFIOR_Register       *((volatile u8*)0x50)



/*ADMUX_Register*/
#define MUX                  0
#define ADLAR                5
#define REFS                 6

/*ADCSRA_Register*/
#define ADPS				0
#define ADIE				3
#define ADIF				4
#define ADATE				5
#define ADSC				6
#define ADEN                7

/*SFIOR*/
#define ADTS                5


/*Configurations*/

/*REFS*/
#define ADC_AREF            0
#define ADC_AVCC            1
#define ADC_AREF_2_56       3

#define ADJUST_LEFT         0
#define ADJUST_RIGH         1

#define MUX_ADC0			0
#define MUX_ADC1			1
#define MUX_ADC2			2
#define MUX_ADC3			3
#define MUX_ADC4			4
#define MUX_ADC5			5
#define MUX_ADC6			6
#define MUX_ADC7			7

#define PRESCALLER_2		1
#define PRESCALLER_4		2
#define PRESCALLER_8		3
#define PRESCALLER_16		4
#define PRESCALLER_32		5
#define PRESCALLER_64		6
#define PRESCALLER_128		7


#define TRIG_FREE        0
#define TRIG_ANALOGCOMP  1
#define TRIG_EXTI0       2
#define TRIG_TIMER0CTC   3
#define TRIG_TIMER0OVF   4

#endif /* ADC_PIRVATE_H_ */