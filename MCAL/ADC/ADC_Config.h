/*
 * ADC_Config.h
 *
 * Created: 6/17/2023 11:14:34 AM
 *  Author: es-MohamedHAbdelAziz
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define ADC_Channel0          1
#define ADC_Channel1          1
#define ADC_Channel2          1
#define ADC_Channel3          1
#define ADC_Channel4          0
#define ADC_Channel5          0
#define ADC_Channel6          0
#define ADC_Channel7          0

#define ADC_VOLT_REF          ADC_AVCC
#define ADC_ADJUST			  ADJUST_RIGH
#define ADC_PRESCALLER        PRESCALLER_128
#define ADC_TRIGGER           TRIG_FREE

#define ADC_AUTOTRIGGER       0
#define ADC_INTERRUPT         0

#endif /* ADC_CONFIG_H_ */