/*
 * GPIO_Interface.h
 *
 *  Created on: Jun 23, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#ifndef GPIO_GPIO_INTERFACE_H_
#define GPIO_GPIO_INTERFACE_H_





#define GPIO_INPUT    		  0
#define GPIO_OUTPUT           1
#define GPIO_ALTFUNC  		  2
#define GPIO_ANALOG           3


#define GPIO_PUSHPULL         0
#define GPIO_OPENDRAIN        1

#define GPIO_NOPULLUPDOWN     0
#define GPIO_PULLUP           1
#define GPIO_PULLDOWN         2






#define PIN0           0
#define PIN1           1
#define PIN2           2
#define PIN3           3
#define PIN4           4
#define PIN5           5
#define PIN6           6
#define PIN7           7
#define PIN8           8
#define PIN9           9
#define PIN10          10
#define PIN11          11
#define PIN12          12
#define PIN13          13
#define PIN14          14
#define PIN15          15

#define PORTA          0
#define PORTB          1
#define PORTC          2
#define PORTD          3

#define GPIO_LOW     0
#define GPIO_HIGH    1

void GPIO_voidSetPinDirection(u8 PORT,u8 PIN,u8 DIRECTION, u8 INPUT_PULL, u8 OUT_PULL);
void GPIO_voidSetPinValue(u8 PORT,u8 PIN, u8 VALUE);
u8   GPIO_voidGetPinValue(u8 PORT,u8 PIN);
void GPIO_voidTogPinValue(u8 PORT, u8 PIN);


#endif /* GPIO_GPIO_INTERFACE_H_ */
