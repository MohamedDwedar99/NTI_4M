/*
 * DMA_Private.h
 *
 *  Created on: Jun 25, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#ifndef DMA_DMA_PRIVATE_H_
#define DMA_DMA_PRIVATE_H_

#define DMA_BASE_ADD       (u32)0x40026000


typedef struct{
	u32 SCR;
	u32 SNDTR;
	u32 SPAR;
	u32 SM0AR;
	u32 SM1AR;
	u32 SFCR;
}DMA_Channel;


typedef struct{
	u32 LISR;
	u32 HISR;
	u32 LIFCR;
	u32 HIFCR;
	DMA_Channel Channel[8];
}DMA_Type;



#define DMA1        ((volatile  DMA_Type *) DMA_BASE_ADD)








#endif /* DMA_DMA_PRIVATE_H_ */
