/*
 * UART_program.c
 *Author  :  Ahmed Ashraf
 *Date    :	 31 Oct 2020
 *Version :  V01
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_prvate.h"
#include "UART_config.h"
#include "LCD_interface.h"
#include "avr/interrupt.h"

void (*callBackFunc)(u16);
void (*callBackFuncs[2]) (void);
void UART_voidInit()
{
	/*DOUBLE SPEED*/
	UCSRA &= ~(0x02);
	UCSRA |= (USART_DOUBLE_USART_SPEED << 1);
	if((USART_COMPLETE_RECEIVED_INTERRUPT_ENABLE == RXCIE_ENABLE )||(USART_COMPLETE_TRANSMIT_INTERRUPT_ENABLE == TXCIE_ENABLE) ||(USART_DATA_REGISER_EMPTY_INTERRUPT_ENABLE == UDRIE_ENABLE))
	{
		/*RECEIVED COMPLETE INTERRUPT*/
		UCSRB &= ~(0x80);
		UCSRB |= (USART_COMPLETE_RECEIVED_INTERRUPT_ENABLE << 7) ;
		/*TRANSMIT COMPLETE INTERRUPT*/
		UCSRB &= ~(0x40);
		UCSRB |= (USART_COMPLETE_TRANSMIT_INTERRUPT_ENABLE << 6) ;
		/*USART DATA REGISITER EMPTY INTERRUPT*/
		UCSRB &= ~(0x20);
		UCSRB |= (USART_DATA_REGISER_EMPTY_INTERRUPT_ENABLE << 5) ;
		//ENABLE GLOBAL INTERRUPT
		SET_BIT(SREG_REG,GLOBAL_INTERRUPT_ENABLE);
	}
	/*Character Size And MODE OF UART AND STOP BITS AND PARITY MODE*/
	if (USART_CHARACTER_SIZE == USART_9_BIT)
	{
		UCSRB &= ~(0x04);
		UCSRB |= 0x04 ;
		UCSRC = 0;
		UCSRC |= (0x80) | (USART_MODE_SELECT <<6) | (USART_PARITY_MODE <<4) | (USART_STOP_BIT <<3) |(USART_CHARACTER_SIZE) |(USART_CPOL);
	}
	else
	{
		UCSRB &= ~(0x04);
		UCSRC = 0;
		UCSRC |= (0x80) | (USART_MODE_SELECT <<6) | (USART_PARITY_MODE <<4) | (USART_STOP_BIT <<3) |(USART_CHARACTER_SIZE )|(USART_CPOL);
	}
	/*Baud Rate*/
	UBRRL = USART_UBRR_8MHZ ;
	
	/*SET TRANSMITER AND RECEIVER ENABLE	*/
	UCSRB &= ~(0x18);
	UCSRB |= USART_TRANSMITER_STATE|USART_RECEIVER_STATE ;
}
void UART_voidSendData(u16 Copy_u16Data)
{
	u8 Loc_u8LastBit;
	Loc_u8LastBit= GET_BIT(Copy_u16Data , UDR_BIT_8);
	UCSRB &= ~(0x01);
	UCSRB |= Loc_u8LastBit;

	if ( (GET_BIT(UCSRA,UCSRA_FRAME_ERROR)) ==0 && (GET_BIT(UCSRA,UCSRA_PARITY_ERROR)) ==0 && (GET_BIT(UCSRA,UCSRA_DATA_OVER_RUN)) ==0)
	{
		while ( (GET_BIT(UCSRA,UCSRA_UDRE)) ==0 );
		
		UDR = Copy_u16Data;
	}
	else if ((GET_BIT(UCSRA,UCSRA_FRAME_ERROR)) ==1)
	{
		/*ERROR IN FRAME ERROR*/
	}
	else if ((GET_BIT(UCSRA,UCSRA_DATA_OVER_RUN)) ==1)
	{
		/*ERROR IN DATA*/
	}
	else if ((GET_BIT(UCSRA,UCSRA_PARITY_ERROR )) == 1)
	{
			/*ERROR IN PARITY*/
	}
	else
	{
		/*ERROR*/
	}
}
void UART_voidSetTransmitCompleteFunc(void (*ptr) (void))
{
	callBackFuncs[0] = ptr;
}
void UART_voidReadToReceiveFunc(void (*ptr) (void))
{
	callBackFuncs[1] = ptr;
}
u16 UART_u16SynchReceiveData(void)
{
	while ((GET_BIT(UCSRA,UCSRA_RXC)) == 0	);
	if((GET_BIT(UCSRB , USART_RXB8)) == 1)
	{
		return (UDR+256) ;
	}
	return UDR ;
}
void UART_voidReceiveAsynch(void (*ptr)(u16))
{
	/*AssIgn Call Back*/
	callBackFunc =  ptr ;
}
ISR(USART_RXC_vect)
{
	/*Receive Data*/
	u16 loc_u16RecData = UDR ;
	/*Call Function*/
	callBackFunc(loc_u16RecData);

}
ISR(USART_TXC_vect)
{
	callBackFuncs[0]();
}

ISR(USART_UDRE_vect)
{
	callBackFuncs[1]();
}
