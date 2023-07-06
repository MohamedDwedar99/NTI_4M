/*
 * DMA_Program.c
 *
 *  Created on: Jun 25, 2023
 *      Author: es-MohamedHAbdelAziz
 */


#include "Std_Types.h"
#include "Bit_Math.h"

#include "DMA_Private.h"
#include "DMA_Interface.h"

void	DMA1_voidChannelInit(u8 Channel_copy,u8 source,u8 sink)
{
	//	Memory to Memory

	//	priority very high
	//	Size (Source & Destination) u32
	//	MINC, PINC enabled
	//	Direction read from Peripheral
	//	Transfere Complete Interrupt
	//	Channel Disable

		//DMA1 ->	Channel[0].SCR = 0x00007AC2;
		switch (source)
		{
		case DMA_Memory:
			if (sink == DMA_Memory)
			{
				// Choose the Priority
			    DMA1 -> Channel[Channel_copy].SCR |= ( 3 << 16);
			    // Source size
			    DMA1 -> Channel[Channel_copy].SCR |= (3   << 13);
			    // Sink size
			    DMA1 -> Channel[Channel_copy].SCR |= (3   << 11);
			    // source incerment mode
			    DMA1 -> Channel[Channel_copy].SCR |= 1 << 10;
			    // sink incerment mode
			    DMA1 -> Channel[Channel_copy].SCR |= 1 << 9;
			    // Transfer Error interrupt enable
			    DMA1 -> Channel[Channel_copy].SCR |= 1 << 4;
			    // Select Direction
			    DMA1 -> Channel[Channel_copy].SCR |= 3 << 6;
			    // Enable DAM
			    DMA1 -> Channel[Channel_copy].SCR |= 1 << 0;
			}
			else if (sink == DMA_Peripheral)
			{

			}
			break;
		case DMA_Peripheral:
			if (sink == DMA_Memory)
			{

			}
			else if (sink == DMA_Peripheral)
			{

			}
			break;
		}
}


void	DMA1_voidStartChannel(u8 Channel_copy, u32 * SrcAdd,u32 * DestAdd,u16 BlockLength)
{
	/*		Make Sure that the channel is  disabled */
	CLR_BIT(DMA1 -> Channel[Channel_copy].SCR,0);

	DMA1 -> Channel[Channel_copy].SPAR	=	SrcAdd;
	DMA1 -> Channel[Channel_copy].SM0AR	=	DestAdd;

	/*	Load the Block Length				*/
	DMA1 -> Channel[Channel_copy].SNDTR	=	BlockLength;

	//DMA1 -> CHS
	/*		Make Sure that the channel is  Enabled to strat transfere*/
	DMA1 -> HISR = 0xffffffff;
	DMA1 -> LISR = 0xffffffff;
	SET_BIT(DMA1 -> Channel[Channel_copy].SCR,0);
}
