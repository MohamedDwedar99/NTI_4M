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

//Define Channels
#define Cahnnel0           0
#define Cahnnel1           1
#define Cahnnel2           2
#define Cahnnel3           3
#define Cahnnel4           4
#define Cahnnel5           5
#define Cahnnel6           6
#define Cahnnel7           7
#define Cahnnel8           8
#define Cahnnel9           9
#define Cahnnel10          10
#define Cahnnel11          11
#define Cahnnel12          12
#define Cahnnel13          13
#define Cahnnel14          14
#define Cahnnel15          15
#define Cahnnel16          16
#define Cahnnel17          17
#define Cahnnel18          18
#define Cahnnel19          19
#define Cahnnel20          20
#define Cahnnel21          21
#define Cahnnel22          22
#define Cahnnel23          23
#define Cahnnel24          24
#define Cahnnel25          25
#define Cahnnel26          26
#define Cahnnel27          27
#define Cahnnel28          28
#define Cahnnel29          29
#define Cahnnel30          30
#define Cahnnel31          31

















































//PINs APIs
void DIO_SetPinDirection(u8 PortCopy,u8 PinCopy,u8 PinDirCopy);
void DIO_SetPinValue(u8 PortCopy,u8 PinCopy,u8 PinValCopy);
void DIO_TogPinValue(u8 PortCopy,u8 PinCopy);
u8	 DIO_GetPinValue(u8 PortCopy,u8 PinCopy);

//PORTs APIs
void DIO_SetPortDirection(u8 PortCopy,u8 PortDirCopy);
void DIO_SetPortValue(u8 PortCopy,u8 PortValCopy);
void DIO_TogPortValue(u8 PortCopy);
u8   DIO_GetPortValue(u8 PortCopy);


#endif /* DIO_INTERFACE_H_ */