/*
 * UART_Program.c
 *
 * Created: 7/2/2023 12:27:06 PM
 *  Author: es-MohamedHAbdelAziz
 */ 
#include "../../Services/BIT_MATH.h"
#include "../../Services/STD.h"
#include "UART_Config.h"
#include "UART_Private.h"
#include "UART_Interface.h"


void UART_Init(void)
{
	/*Set Baud Rate*/
	UBRR_Register = BAUD_9600;
	/*Enable reciever & transmitter*/
	UCSRB_Register = (1<<RXEN)|(1<<TXEN);
	/*Set frame format: 8data, 2stop bit*/
	UCSRC_Register = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0); 
}

void UART_Transmit(u8 data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA_Register & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR_Register = data;
}

u8 UART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA_Register & (1<<RXC)) );
	/* Get and return received data from buffer */
	return UDR_Register;
}