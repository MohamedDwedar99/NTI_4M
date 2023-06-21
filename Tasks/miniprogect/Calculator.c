/*
 * Calculator.c
 *
 * Created: 6/16/2023 2:24:30 PM
 *  Author: es-MohamedHAbdelAziz
 */ 

#include "Services/BIT_MATH.h"
#include "Services/STD.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "ECU/KEYPAD/KEYPAD_Interface.h"
#include "ECU/LCD/LCD_Interface.h"



/***How To Use**/
/*
*		set config of KEYPAD
			u8 KEY_GIT[4][4] = {
				{'1','2','3','+'},
				{'4','5','6','-'},
				{'7','8','9','*'},
				{'=','0','E','/'}
			};
*	1- Enter 1st Num 
*   2- Enter 'E'
*	3- Enter 2nd Num 
*	4- Press 'E'
*      the Result will be desplayed
*/


u16 TakeNum(void);
u8* NumToArr(u16 num);
u8 TakeOP(void);

void main()
{
	LCD_Init();
	KEYPAD_Init();
	u16 op1 = 0;
	u16 op2 = 0;
	u16 result = 0;
	u8  assigner = 0;
	u8 * Numstring = NULL;
	while(1)
	{
		op1 = TakeNum();
		assigner = TakeOP();
		op2 = TakeNum();
		switch (assigner)
		{
			case '+': result = op1+op2; break;
			case '-': result = op1-op2;break;
			case '*': result = op1*op2;break;
			case '/': result = op1/op2;break;
		}
		Numstring = NumToArr(result);
		LCD_WriteData('=');
		LCD_WriteString(Numstring);
		while(KEYPAD_Read()!= 'C');
		LCD_SendCommand(LCD_CLR);
	}
}

u16 TakeNum(void)
{
	u8 read_Char;
	u32 read_int = 0;
	for (u8 i = 0; i < 20;i++)
	{
		while((read_Char = KEYPAD_Read()) == 0xff);
		if(read_Char == 'E')
		{
			break;
		}
		else if (read_Char >= '0' && read_Char <= '9')
		{
			LCD_WriteData(read_Char);
			read_int= read_int*10 + (read_Char-'0');	
		}
		else
		{
			i--;
		}
	}
	return read_int;
}

u8 TakeOP(void)
{
	u8 OPP = 0;
	while((OPP = KEYPAD_Read()) == 0xff);
	LCD_WriteData(OPP);
	return OPP;
}

u8* NumToArr(u16 num){
	u8 arr[6] = {0};
	static u8 arr2[6] = {0};
	s16 i = 0;
	s16 j = 0;
	do
	{
		arr[i] = num%10;
		num /= 10;
		i++;
	}while(num > 0);
	while((i) > 0)
	{
		i--;
		arr2[j] = arr[i] + '0';
		j++;
	}
	arr2[j] = '\0';
	return arr2;
}