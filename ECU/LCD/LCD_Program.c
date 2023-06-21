/*
 * LCD_Program.c
 *
 * Created: 6/11/2023 9:12:26 AM
 *  Author: es-MohamedHAbdelAziz
 */

#include "../../Services/BIT_MATH.h"
#include "../../Services/STD.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "LCD_Config.h"
#include "LCD_Private.h"
#include "LCD_Interface.h"



static void _delay_us(u32 ticks){
	u32 i;
	for( i = 0; i < (ticks*50) ; i++)
	{
		asm("NOP");
	}
}

static void _delay_ms(u32 ticks){
	u32 i;
	for( i = 0; i < (ticks*500) ; i++)
	{
		asm("NOP");
	}
}

void LCD_Init(void)
{
		DIO_SetPinDirection(LCD_PIND4,PIN_OUTPUT);
		DIO_SetPinDirection(LCD_PIND5,PIN_OUTPUT);
		DIO_SetPinDirection(LCD_PIND6,PIN_OUTPUT);
		DIO_SetPinDirection(LCD_PIND7,PIN_OUTPUT);
		DIO_SetPinDirection(LCD_PIN_RS,PIN_OUTPUT);
		DIO_SetPinDirection(LCD_PIN_EN,PIN_OUTPUT);
		_delay_ms(35);
		LCD_SendCommand(0x33);
//		_delay_ms(1);
		LCD_SendCommand(0x32);
	//	_delay_ms(1);
		LCD_SendCommand(LCD_MODE);
		//_delay_ms(10);
		LCD_SendCommand(DISPLAY);
//		_delay_ms(10);
		LCD_SendCommand(LCD_CLR);
	//	_delay_ms(20);
		LCD_SendCommand(0x06);
		//_delay_ms(10);
		//LCD_SendCommand(LCD_CLR);
		//_delay_ms(2);
		
			//	LCD_SendCommand(0x06);
			//	_delay_ms(1);
				
		DIO_SetPinValue(LCD_PIN_EN,PIN_LOW);
		//_delay_ms(200);
}
void LCD_SendCommand(u8 Command_Copy)
{
	// Send Lower Nibbles
	DIO_SetPinValue(LCD_PIND4,GET_BIT(Command_Copy,4));
	DIO_SetPinValue(LCD_PIND5,GET_BIT(Command_Copy,5));
	DIO_SetPinValue(LCD_PIND6,GET_BIT(Command_Copy,6));
	DIO_SetPinValue(LCD_PIND7,GET_BIT(Command_Copy,7));
	
	// Enable Send
	DIO_SetPinValue(LCD_PIN_EN,PIN_HIGH);
	_delay_us(10);
	DIO_SetPinValue(LCD_PIN_EN,PIN_LOW);
	_delay_us(10);
	
	// Write Lower Nibbles
	DIO_SetPinValue(LCD_PIND4,GET_BIT(Command_Copy,0));
	DIO_SetPinValue(LCD_PIND5,GET_BIT(Command_Copy,1));
	DIO_SetPinValue(LCD_PIND6,GET_BIT(Command_Copy,2));
	DIO_SetPinValue(LCD_PIND7,GET_BIT(Command_Copy,3));
	
	// Enable Send
	DIO_SetPinValue(LCD_PIN_EN,PIN_HIGH);
	_delay_us(10);
	DIO_SetPinValue(LCD_PIN_EN,PIN_LOW);
	_delay_us(10);

}

void LCD_WriteData(u8 Data_Copy)
{
	DIO_SetPinValue(LCD_PIN_RS,PIN_HIGH);
	DIO_SetPinValue(LCD_PIND4,GET_BIT(Data_Copy,4));
	DIO_SetPinValue(LCD_PIND5,GET_BIT(Data_Copy,5));
	DIO_SetPinValue(LCD_PIND6,GET_BIT(Data_Copy,6));
	DIO_SetPinValue(LCD_PIND7,GET_BIT(Data_Copy,7));
	
	// Enable Send
	DIO_SetPinValue(LCD_PIN_EN,PIN_HIGH);
		_delay_us(10);

	DIO_SetPinValue(LCD_PIN_EN,PIN_LOW);
		_delay_us(10);

	
		
	// Write Lower Nibbles
	DIO_SetPinValue(LCD_PIND4,GET_BIT(Data_Copy,0));
	DIO_SetPinValue(LCD_PIND5,GET_BIT(Data_Copy,1));
	DIO_SetPinValue(LCD_PIND6,GET_BIT(Data_Copy,2));
	DIO_SetPinValue(LCD_PIND7,GET_BIT(Data_Copy,3));
		
	// Enable Send
	DIO_SetPinValue(LCD_PIN_EN,PIN_HIGH);
		_delay_us(10);

	DIO_SetPinValue(LCD_PIN_EN,PIN_LOW);
		_delay_us(10);
			DIO_SetPinValue(LCD_PIN_RS,PIN_LOW);

}

void LCD_WriteString(u8  String[])
{
	int i = 0;
	while(String[i] != NULL)
	{
		LCD_WriteData(String[i]);
		i++;
	}
}

void LCD_GOTO(u8 x, u8 y)
{
	switch (x)
	{
		case 0:LCD_SendCommand(0x80+0x00+y); break;
		case 1:LCD_SendCommand(0x80+0x40+y); break;
		case 2:LCD_SendCommand(0x80+0x14+y); break;
		case 3:LCD_SendCommand(0x80+0x54+y); break;
	}
}



void LCD_SaveCustomChar(u8 character[],u8 Location)
{
	LCD_SendCommand(0x40 + 8*Location);
	for (u8 i = 0; i < 8; i++)
	{
		LCD_WriteData(character[i]);
	}
	LCD_GOTO(0,0);
}


void LCD_WriteNum(u16 num)
{
	u16 num1 = num;
	while (num1)
	{
		
	}
}