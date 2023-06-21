/*
 * BUZZER_Program.c
 *
 * Created: 6/12/2023 11:29:52 AM
 *  Author: es-MohamedHAbdelAziz
 */ 
#include "../../Services/BIT_MATH.h"
#include "../../Services/STD.h"


#include "../../MCAL/DIO/DIO_Interface.h"

#include "BUZZER_Config.h"
#include "BUZZER_Interface.h"

#include <util/delay.h>
void BUZZER_Init(void)
{
	DIO_SetPinDirection(BUZZER_PIN,PIN_OUTPUT);
}
void BUZZER_ON(void)
{
	DIO_SetPinValue(BUZZER_PIN,PIN_HIGH);
}
void BUZZRT_OFF(void)
{
	DIO_SetPinValue(BUZZER_PIN,PIN_LOW);
}