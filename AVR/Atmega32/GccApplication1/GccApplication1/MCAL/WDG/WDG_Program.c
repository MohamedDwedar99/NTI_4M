/*
 * WDG_Program.c
 *
 * Created: 6/26/2023 3:42:49 PM
 *  Author: es-MohamedHAbdelAziz
 */ 

#include "../../Services/STD.h"
#include "WDG_Private.h"
#include "WDG_Interface.h"

void WDG_SET(u8 WDG_TIME)
{
	WDTCR_Register |=  1 << WDE | WDG_TIME << WDP;
}
void WDG_Sleep(void)
{
	WDTCR_Register |= 1 <<WDTOE | 1 <<  WDE;
}
void WDG_Stop(void)
{
	// Reset WDG
	MCUCSR_Register &= ~(1 << WDRF);
	
	WDTCR_Register |= 1 <<WDTOE | 1 <<  WDE;
	WDTCR_Register  = 0;
}