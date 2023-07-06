/*
 * GPIO_Program.c
 *
 *  Created on: Jun 23, 2023
 *      Author: es-MohamedHAbdelAziz
 */


#include "Bit_Math.h"
#include "Std_Types.h"

#include "GPIO_Config.h"
#include "GPIO_Private.h"
#include "GPIO_Interface.h"

void GPIO_voidSetPinDirection(u8 PORT,u8 PIN,u8 DIRECTION, u8 INPUT_PULL, u8 OUT_PULL)
{
	if (PORT < 4 && PIN < 16)
	{

		switch(PORT)
		{
		case PORTA:
			// Clear the 4 bits
			GPIOA -> MODER &= ~((0b11)<<(PIN * 2));
			// Assign the Direction
			GPIOA -> MODER |= ((DIRECTION)<<(PIN * 2));
			if (DIRECTION == GPIO_INPUT)
			{

				GPIOA -> PUPDR |= (INPUT_PULL << 2*PIN);
			}
			else
			{
				GPIOA -> OTYPER |= (OUT_PULL << PIN);
			}
			break;
		case PORTB:
			// Clear the 4 bits
			GPIOB -> MODER &= ~((0b11)<<(PIN * 2));
			// Assign the Direction
			GPIOB -> MODER |= ((DIRECTION)<<(PIN * 2));
			if (DIRECTION == GPIO_INPUT)
			{

				GPIOB -> PUPDR |= (INPUT_PULL << 2*PIN);
			}
			else
			{
				GPIOB -> OTYPER |= (OUT_PULL << PIN);
			}
			break;
		case PORTC:
			// Clear the 4 bits
			GPIOC -> MODER &= ~((0b11)<<(PIN * 2));
			// Assign the Direction
			GPIOC -> MODER |= ((DIRECTION)<<(PIN * 2));
			break;
			if (DIRECTION == GPIO_INPUT)
			{

				GPIOC -> PUPDR |= (INPUT_PULL << 2*PIN);
			}
			else
			{
				GPIOC -> OTYPER |= (OUT_PULL << PIN);
			}
		case PORTD:
			// Clear the 4 bits
			GPIOD -> MODER &= ~((0b11)<<(PIN * 2));
			// Assign the Direction
			GPIOD -> MODER |= ((DIRECTION)<<(PIN * 2));
			break;
			if (DIRECTION == GPIO_INPUT)
			{

				GPIOD -> PUPDR |= (INPUT_PULL << 2*PIN);
			}
			else
			{
				GPIOD -> OTYPER |= (OUT_PULL << PIN);
			}
		}

	}
}


void GPIO_voidSetPinValue(u8 PORT,u8 PIN, u8 VALUE)
{
	if (PORT < 4 && PIN < 16)
	{
		if (VALUE == GPIO_HIGH)
		{
			switch (PORT)
			{
			case PORTA:
				GPIOA -> BSRR = 1 << (PIN);
				break;
			case PORTB:
				GPIOB -> BSRR = 1 << (PIN);
				break;
			case PORTC:
				GPIOC -> BSRR = 1 << (PIN);
				break;
			case PORTD:
				GPIOD -> BSRR = 1 << (PIN);
				break;
			}
		}
		else
		{
			switch (PORT)
			{
			case PORTA:
				GPIOA -> BSRR = 1 << (PIN+16);
				break;
			case PORTB:
				GPIOB -> BSRR = 1 << (PIN+16);
				break;
			case PORTC:
				GPIOC -> BSRR = 1 << (PIN+16);
				break;
			case PORTD:
				GPIOD -> BSRR = 1 << (PIN+16);
				break;
			}
		}
	}

}


u8   GPIO_voidGetPinValue(u8 PORT,u8 PIN)
{
	u8 value = 0xff;
	if (PORT < 4 )
	{
		if (PIN < 16)
		{
			switch (PORT)
			{
			case PORTA:
				value = GET_BIT(GPIOA->IDR,PIN);
				break;
			case PORTB:
				value = GET_BIT(GPIOB->IDR,PIN);
				break;
			case PORTC:
				value = GET_BIT(GPIOC->IDR,PIN);
				break;
			case PORTD:
				value = GET_BIT(GPIOD->IDR,PIN);
				break;
			}
		}
	}
	return value;
}
void GPIO_voidTogPinValue(u8 PORT, u8 PIN)
{
	if (PORT < 4 )
	{
		if (PIN < 16)
		{
			switch (PORT)
			{
			case PORTA:
				TOG_BIT(GPIOA->ODR,PIN);
				break;
			case PORTB:
				TOG_BIT(GPIOB->ODR,PIN);
				break;
			case PORTC:
				TOG_BIT(GPIOC->ODR,PIN);
				break;
			case PORTD:
				TOG_BIT(GPIOD->ODR,PIN);
				break;
			}
		}
	}
}

