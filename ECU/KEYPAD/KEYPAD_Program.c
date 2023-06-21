/*
 * KEYPAD_Program.c
 *
 * Created: 6/12/2023 9:20:37 AM
 *  Author: es-MohamedHAbdelAziz
 */ 



#include <util/delay.h>

#include "../../Services/BIT_MATH.h"
#include "../../Services/STD.h"


#include "../../MCAL/DIO/DIO_Interface.h"

#include "KEYPAD_Config.h"
#include "KEYPAD_Interface.h"
#include "KEYPAD_Private.h"

void KEYPAD_Init(void)
{
	// Set Raw as Output and LOW
	DIO_SetPinDirection(ROW1_PIN,PIN_OUTPUT);
	DIO_SetPinDirection(ROW2_PIN,PIN_OUTPUT);
	DIO_SetPinDirection(ROW3_PIN,PIN_OUTPUT);
	DIO_SetPinDirection(ROW4_PIN,PIN_OUTPUT);
	
	// Set Columns as PULLUP
	DIO_SetPinDirection(COL1_PIN,PIN_INPUT);
	DIO_SetPinValue(COL1_PIN,PIN_HIGH);
	
	DIO_SetPinDirection(COL2_PIN,PIN_INPUT);
	DIO_SetPinValue(COL2_PIN,PIN_HIGH);
	
    DIO_SetPinDirection(COL3_PIN,PIN_INPUT);
    DIO_SetPinValue(COL3_PIN,PIN_HIGH);
	
	DIO_SetPinDirection(COL4_PIN,PIN_INPUT);
	DIO_SetPinValue(COL4_PIN,PIN_HIGH);
}
u8   KEYPAD_Read(void)
{
	u8 data = 0xFF;
	for (u8 i = 0;i < 4;i++)
	{
		DIO_SetPinValue(ROW_PIN_arr[i], PIN_LOW);
		for (u8 j = 0;j < 4;j++)
		{
			if (!DIO_GetPinValue(COL_PIN_arr[j]))
			{
				data = KEY_GIT[i][j];
			}
			while(!DIO_GetPinValue(COL_PIN_arr[j]));
		}
		DIO_SetPinValue(ROW_PIN_arr[i], PIN_HIGH);
	}
	return data;
}