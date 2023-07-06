/*
 * BOTTOM_Program.c
 *
 * Created: 6/10/2023 9:20:23 AM
 *  Author: es-MohamedHAbdelAziz
 */ 



#include "../../Services/BIT_MATH.h"
#include "../../Services/STD.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "BOTTOM_Interface.h"


void BOTTOM_Init(u8 pin)
{
	DIO_SetPinDirection(pin,PIN_INPUT);
	DIO_SetPinValue(pin,PIN_HIGH);
}
u8   BOTTOM_Read(u8 pin)
{
	u8 static read = 0;
	if (read != DIO_GetPinValue(pin))
	{
		for (u16 i = 0; i< 500;i++);
		read = DIO_GetPinValue(pin);
	}
	return read;
}
