/*
 * GPIO_Private.h
 *
 *  Created on: Jun 23, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#ifndef GPIO_GPIO_PRIVATE_H_
#define GPIO_GPIO_PRIVATE_H_

#define GPIOA_BASE_ADD      (u32)0x40020000
#define GPIOB_BASE_ADD      (u32)0x40020400
#define GPIOC_BASE_ADD      (u32)0x40020800
#define GPIOD_BASE_ADD      (u32)0x40020C00

typedef struct {
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDR;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
}GPIO_TYPE;


#define  GPIOA    ((volatile GPIO_TYPE *) GPIOA_BASE_ADD)
#define  GPIOB    ((volatile GPIO_TYPE *) GPIOB_BASE_ADD)
#define  GPIOC    ((volatile GPIO_TYPE *) GPIOC_BASE_ADD)
#define  GPIOD    ((volatile GPIO_TYPE *) GPIOD_BASE_ADD)

#endif /* GPIO_GPIO_PRIVATE_H_ */
