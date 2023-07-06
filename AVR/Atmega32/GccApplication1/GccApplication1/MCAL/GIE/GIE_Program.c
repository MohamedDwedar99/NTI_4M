/*
 * GIE_Program.c
 *
 * Created: 6/16/2023 12:27:57 PM
 *  Author: es-MohamedHAbdelAziz
 */ 

#include "../../Services/BIT_MATH.h"
#include "../../Services/STD.h"



#include "GIE_Private.h"
#include "GIE_Interface.h"

void GInterupt_Enable(void)
{
	SET_BIT(SREG,I);
}
void GInterupt_Disable(void)
{
	CLR_BIT(SREG,I);
}