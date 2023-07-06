/*
 * UART_Interface.h
 *
 * Created: 7/2/2023 12:27:41 PM
 *  Author: es-MohamedHAbdelAziz
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#define UDR_Register	*((volatile u16*)0x2C)
/*#define UDR_R           *((volatile u8*)0x)
#define UDR_W           *((volatile u8*)0x)*/
#define UCSRA_Register  *((volatile u8*)0x2B)
#define UCSRB_Register  *((volatile u8*)0x2A)
#define UCSRC_Register  *((volatile u8*)0x40)
#define UBRRL_Register  *((volatile u8*)0x29)
#define UBRRH_Register  *((volatile u8*)0x40)
#define UBRR_Register  *((volatile u16*)0x29)







void UART_Init(void);
void UART_Transmit(u8 data );
u8 UART_Receive( void );



#endif /* UART_INTERFACE_H_ */