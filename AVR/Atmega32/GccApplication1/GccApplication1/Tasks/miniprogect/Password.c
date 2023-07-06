/*
 * IncFile1.h
 *
 * Created: 6/12/2023 2:56:01 PM
 *  Author: es-MohamedHAbdelAziz
 */ 

/*
#define F_CPU    16000000UL
#include <util/delay.h>
#include "Services/BIT_MATH.h"
#include "Services/STD.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "ECU/LED/LED_Interface.h"
#include "ECU/Segment7/Segment7_Interface.h"
#include "ECU/LCD/LCD_Interface.h"
#include "ECU/KEYPAD/KEYPAD_Interface.h"
#include "ECU/BUZZER/BUZZER_Interface.h"

=
u8 PASS_arr[5] = "1234";

int main(void)
{

	LCD_Init();
	KEYPAD_Init();
	LED_INIT(PORTA,PIN4);
	LED_INIT(PORTA,PIN5);
	BUZZER_Init();
	
	u8 flag = 0;
	u8 Count = 3;
	u8 read;
	LCD_WriteString("Enter Password");
	for(u8 i = 0; i<3;i++)
	{
		LCD_GOTO(1,0);
		flag = 0;
		for (u8 j =0; j < 4;j++)
		{
			while((read = KEYPAD_Read()) == 0xff);
			LCD_WriteData('*');
			if (PASS_arr[j] != read)
			{
				flag = 1;
			}
			u8 read = 0xff;
		}
		if (flag == 1 && i < 2)
		{
			LCD_SendCommand(LCD_CLR);
			LCD_GOTO(0,0);
			LCD_WriteString("Try Again");
			LED_ON(PORTA,PIN5);
		}
		else if (flag == 0)
		{
			LCD_SendCommand(LCD_CLR);
			LCD_GOTO(0,0);
			LCD_WriteString("Welcome Ahmed");
			LED_ON(PORTA,PIN4);
			break;
		}
		else
		{
			LCD_SendCommand(LCD_CLR);
			LCD_GOTO(0,0);
			LCD_WriteString("Theaf");
			BUZZER_ON();
			while(1);
		}
	}
	while(1);
	return 0;
}

*/
