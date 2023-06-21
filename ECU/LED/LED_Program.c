/*
 * LED_Program.c
 *
 * Created: 6/10/2023 2:43:36 AM
 *  Author: es-MohamedHAbdelAziz
 */ 

#include "../../Services/BIT_MATH.h"
#include "../../Services/STD.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "LED_Interface.h"

void LED_INIT(u8 pin)
{
	DIO_SetPinDirection(pin,PIN_OUTPUT);
}
void LED_ON(u8 pin)
{
	DIO_SetPinValue(pin,PIN_HIGH);
}
void LED_OFF(u8 pin)
{
	DIO_SetPinValue(pin,PIN_LOW);
}
void LED_TOG(u8 pin)
{
	DIO_TogPinValue(pin);
}