/*
 * DIO_Interface.h
 *
 * Created: 6/10/2023 2:33:37 AM
 *  Author: es-MohamedHAbdelAziz
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_



//PORT Status
#define PORT_LOW  	0x00
#define PORT_HIGH 	0xFF
#define PORT_INPUT	0x00
#define PORT_OUTPUT 0xFF

//PIN Status
#define PIN_LOW		0
#define PIN_HIGH	1
#define PIN_INPUT	0
#define PIN_OUTPUT	1

//PIN Name

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

//Port Name

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3


#define PINA0	0
#define PINA1	1
#define PINA2	2
#define PINA3	3
#define PINA4	4
#define PINA5	5
#define PINA6	6
#define PINA7	7

#define PINB0	8
#define PINB1	9
#define PINB2	10
#define PINB3	11
#define PINB4	12
#define PINB5	13
#define PINB6	14
#define PINB7	15

#define PINC0	16
#define PINC1	17
#define PINC2	18
#define PINC3	19
#define PINC4	20
#define PINC5	21
#define PINC6	22
#define PINC7	23


#define PIND0	24
#define PIND1	25
#define PIND2	26
#define PIND3	27
#define PIND4	28
#define PIND5	29
#define PIND6	30
#define PIND7	31






//PINs APIs
void DIO_SetPinDirection(u8 PinCopy,u8 PinDirCopy);
void DIO_SetPinValue(u8 PinCopy,u8 PinValCopy);
void DIO_TogPinValue(u8 PinCopy);
u8	 DIO_GetPinValue(u8 PinCopy);

//PORTs APIs
void DIO_SetPortDirection(u8 PortCopy,u8 PortDirCopy);
void DIO_SetPortValue(u8 PortCopy,u8 PortValCopy);
void DIO_TogPortValue(u8 PortCopy);
u8   DIO_GetPortValue(u8 PortCopy);


#endif /* DIO_INTERFACE_H_ */