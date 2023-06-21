/*
 * DIO_Program.c
 *
 * Created: 6/10/2023 2:34:29 AM
 *  Author: es-MohamedHAbdelAziz
 */ 


#include "../../Services/BIT_MATH.h"
#include "../../Services/STD.h"
#include "DIO_Private.h"
#include "DIO_interface.h"

void DIO_SetPinDirection(u8 PinCopy,u8 PinDirCopy)
{
	u8 PORT = PinCopy/8;
	u8 PIN = PinCopy%8;
	switch (PinDirCopy)
	{
	case PIN_OUTPUT:
		switch (PORT)
		{
		case PORTA: SET_BIT(DDRA_Register,PIN);break;
		case PORTB: SET_BIT(DDRB_Register,PIN);break;
		case PORTC: SET_BIT(DDRC_Register,PIN);break;
		case PORTD: SET_BIT(DDRD_Register,PIN);break;
		}
		break;
	case PIN_INPUT:
		switch (PORT)
		{
		case PORTA: CLR_BIT(DDRA_Register,PIN);break;
		case PORTB: CLR_BIT(DDRB_Register,PIN);break;
		case PORTC: CLR_BIT(DDRC_Register,PIN);break;
		case PORTD: CLR_BIT(DDRD_Register,PIN);break;
		}
		break;
	}
}
void DIO_SetPinValue(u8 PinCopy,u8 PinValCopy)
{
	u8 PORT = PinCopy/8;
	u8 PIN = PinCopy%8;
	switch (PinValCopy)
	{
	case PIN_HIGH:
		switch (PORT)
		{
		case PORTA: SET_BIT(PORTA_Register,PIN);break;
		case PORTB: SET_BIT(PORTB_Register,PIN);break;
		case PORTC: SET_BIT(PORTC_Register,PIN);break;
		case PORTD: SET_BIT(PORTD_Register,PIN);break;
		}
		break;
	case PIN_LOW:
		switch (PORT)
		{
		case PORTA: CLR_BIT(PORTA_Register,PIN);break;
		case PORTB: CLR_BIT(PORTB_Register,PIN);break;
		case PORTC: CLR_BIT(PORTC_Register,PIN);break;
		case PORTD: CLR_BIT(PORTD_Register,PIN);break;
		}
		break;
	}
}
void DIO_TogPinValue(u8 PinCopy)
{
	u8 PORT = PinCopy/8;
	u8 PIN = PinCopy%8;
	switch (PORT)
	{
	case PORTA: TOG_BIT(PORTA_Register,PIN);break;
	case PORTB: TOG_BIT(PORTB_Register,PIN);break;
	case PORTC: TOG_BIT(PORTC_Register,PIN);break;
	case PORTD: TOG_BIT(PORTD_Register,PIN);break;
	}
}
u8 DIO_GetPinValue(u8 PinCopy)
{
	u8 PORT = PinCopy/8;
	u8 PIN = PinCopy%8;
	u8 BIT = 0;
	switch (PORT)
	{
	case PORTA: BIT = GET_BIT(PINA_Register,PIN);break;
	case PORTB: BIT = GET_BIT(PINB_Register,PIN);break;
	case PORTC: BIT = GET_BIT(PINC_Register,PIN);break;
	case PORTD: BIT = GET_BIT(PIND_Register,PIN);break;
	}
	return BIT;
}




void DIO_SetPortDirection(u8 PortCopy,u8 PortDirCopy)
{

	switch (PortCopy)
	{
	case PORTA:DDRA_Register = PortDirCopy; break;
	case PORTB:DDRB_Register = PortDirCopy; break;
	case PORTC:DDRC_Register = PortDirCopy; break;
	case PORTD:DDRD_Register = PortDirCopy; break;
	}
}
void DIO_SetPortValue(u8 PortCopy,u8 PortValCopy)
{
	switch (PortCopy)
	{
	case PORTA:PORTA_Register = PortValCopy; break;
	case PORTB:PORTB_Register = PortValCopy; break;
	case PORTC:PORTC_Register = PortValCopy; break;
	case PORTD:PORTD_Register = PortValCopy; break;
	}

}
void DIO_TogPortValue(u8 PortCopy)
{
	switch (PortCopy)
	{
	case PORTA:PORTA_Register ^= 0xFF; break;
	case PORTB:PORTB_Register ^= 0xFF; break;
	case PORTC:PORTC_Register ^= 0xFF; break;
	case PORTD:PORTD_Register ^= 0xFF; break;
	}
}
u8 DIO_GetPortValue(u8 PortCopy)
{
	switch (PortCopy)
	{
	case PORTA:return(PINA_Register); break;
	case PORTB:return(PINB_Register); break;
	case PORTC:return(PINC_Register); break;
	case PORTD:return(PIND_Register); break;
	}
	return 0;
}