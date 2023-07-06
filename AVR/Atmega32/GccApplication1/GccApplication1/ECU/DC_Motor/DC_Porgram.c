/*
 * DC_Porgram.c
 *
 * Created: 6/10/2023 9:30:57 AM
 *  Author: es-MohamedHAbdelAziz
 */ 

#include "../../Services/BIT_MATH.h"
#include "../../Services/STD.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "DC_Config.h"
#include "DC_Interface.h"

void DC_Init(void)
{
	DIO_SetPinDirection(DC_PIN_CW,PIN_OUTPUT);
	DIO_SetPinDirection(DC_PIN_CCW,PIN_OUTPUT);
}
void DC_OFF(void)
{
	DIO_SetPinValue(DC_PIN_CW,PIN_LOW);
	DIO_SetPinValue(DC_PIN_CCW,PIN_LOW);
}
void DC_RotateCW(void)
{
	DIO_SetPinValue(DC_PIN_CW,PIN_HIGH);
	DIO_SetPinValue(DC_PIN_CCW,PIN_LOW);
}
void DC_RotateCCW(void)
{
	DIO_SetPinValue(DC_PIN_CW,PIN_LOW);
	DIO_SetPinValue(DC_PIN_CCW,PIN_HIGH);
}