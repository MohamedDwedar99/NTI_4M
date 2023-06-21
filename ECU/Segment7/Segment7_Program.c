/*
 * Segment7_Program.c
 *
 * Created: 6/10/2023 2:44:52 AM
 *  Author: es-MohamedHAbdelAziz
 */ 



#include "../../Services/BIT_MATH.h"
#include "../../Services/STD.h"
#include <util/delay.h>


#include "../../MCAL/DIO/DIO_Interface.h"

#include "Segment_Config.h"
#include "Segment7_Interface.h"

u8 NUM[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};


void Segment7_Mult4Init(void)
{
	DIO_SetPinDirection(PINB0,PIN_OUTPUT);
	DIO_SetPinDirection(PINB1,PIN_OUTPUT);
	DIO_SetPinDirection(PINB2,PIN_OUTPUT);
	DIO_SetPinDirection(PINB4,PIN_OUTPUT);
	
	
	DIO_SetPinDirection(PINA3,PIN_OUTPUT);
	DIO_SetPinDirection(PINA2,PIN_OUTPUT);
	DIO_SetPinDirection(PINB5,PIN_OUTPUT);
	DIO_SetPinDirection(PINB6,PIN_OUTPUT);
}

void Segment7_Mult4SetDisplay(u16 data)
{
	u8 Ones = data%10;
	u8 Tens = ((data-Ones)/10)%10;
	u8 Hundreds = ((data-Tens)/100)%10;
	u8 Thousands = ((data-Hundreds)/1000)%10;
	
	DIO_SetPinValue(PINB0,(Ones>>0) & 0b01);
	DIO_SetPinValue(PINB1,(Ones>>1) & 0b01);
	DIO_SetPinValue(PINB2,(Ones>>2) & 0b01);
	DIO_SetPinValue(PINB4,(Ones>>3) & 0b01);

	DIO_SetPinValue(PINA3,PIN_LOW);
	DIO_SetPinValue(PINA2,PIN_HIGH);
	DIO_SetPinValue(PINB5,PIN_HIGH);
	DIO_SetPinValue(PINB6,PIN_HIGH);
	_delay_ms(20);
	DIO_SetPinValue(PINB0,(Tens>>0) & 0b01);
	DIO_SetPinValue(PINB1,(Tens>>1) & 0b01);
	DIO_SetPinValue(PINB2,(Tens>>2) & 0b01);
	DIO_SetPinValue(PINB4,(Tens>>3) & 0b01);

	DIO_SetPinValue(PINA3,PIN_HIGH);
	DIO_SetPinValue(PINA2,PIN_LOW);
	DIO_SetPinValue(PINB5,PIN_HIGH);
	DIO_SetPinValue(PINB6,PIN_HIGH);
	_delay_ms(20);
	DIO_SetPinValue(PINB0,(Hundreds>>0) & 0b01);
	DIO_SetPinValue(PINB1,(Hundreds>>1) & 0b01);
	DIO_SetPinValue(PINB2,(Hundreds>>2) & 0b01);
	DIO_SetPinValue(PINB4,(Hundreds>>3) & 0b01);

	DIO_SetPinValue(PINA3,PIN_HIGH);
	DIO_SetPinValue(PINA2,PIN_HIGH);
	DIO_SetPinValue(PINB5,PIN_LOW);
	DIO_SetPinValue(PINB6,PIN_HIGH);
	_delay_ms(20);
	DIO_SetPinValue(PINB0,(Thousands>>0) & 0b01);
	DIO_SetPinValue(PINB1,(Thousands>>1) & 0b01);
	DIO_SetPinValue(PINB2,(Thousands>>2) & 0b01);
	DIO_SetPinValue(PINB4,(Thousands>>3) & 0b01);

	DIO_SetPinValue(PINA3,PIN_HIGH);
	DIO_SetPinValue(PINA2,PIN_HIGH);
	DIO_SetPinValue(PINB5,PIN_HIGH);
	DIO_SetPinValue(PINB6,PIN_LOW);
	_delay_ms(20);	
}