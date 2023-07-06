/*
 * ADC_Interface.h
 *
 * Created: 6/17/2023 11:14:18 AM
 *  Author: es-MohamedHAbdelAziz
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_



void ADC_Init(void);
void ADC_TurnON(void);
void ADC_TurnOFF(void);
void ADC0_StartConversion(void);
void ADC1_StartConversion(void);
void ADC2_StartConversion(void);
void ADC3_StartConversion(void);
void ADC4_StartConversion(void);
void ADC5_StartConversion(void);
void ADC6_StartConversion(void);
void ADC7_StartConversion(void);
void ADC_DiffA0A1(void);

u16  ADC_Read(void);
u16  ADC_Mapping(u16 ADC_Input,u16 ADC_min, u16 ADC_max, u16 sensorMin, u16 sensorMax);

void ADC_SetCallBack(void (*CALLBACK)(void));

void __vector_16 (void) __attribute__((signal,used));
u16  ADC_Mapping(u16 y ,u16 y1 ,u16 y2,u16 x1, u16 x2);
#endif /* ADC_INTERFACE_H_ */