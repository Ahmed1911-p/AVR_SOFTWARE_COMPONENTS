/*
 * UART_prvate.h
 *Author  :  Ahmed Ashraf
 *Date    :	 31 Oct 2020
 *Version :  V01
 */

#ifndef UART_PRVATE_H_
#define UART_PRVATE_H_
/************************************************************/
/* <-- REGISTERS	-->										*/


#define	UDR		 (*(volatile u8 *)0x2C)
#define	UCSRA	 (*(volatile u8 *)0x2B)
#define	UCSRB	 (*(volatile u8 *)0x2A)
#define	UCSRC	 (*(volatile u8 *)0x40)
#define	UBRRH	 (*(volatile u8 *)0x40)
#define	UBRRL	 (*(volatile u8 *)0x29)

#define SREG_REG		*((volatile u8 *) 0x5F)
/**************************************************************/
/*U2X*/
#define  U2X_ENABLE				1
#define  U2X_DISABLE			0
/**************************************************************/
/*BAUD RATE WITH NO UTX*/
#define   USART_2400_BAUD_RATE			207
#define   USART_4800_BAUD_RATE			103
#define   USART_9600_BAUD_RATE			51
#define   USART_14.4k_BAUD_RATE			34
#define   USART_19.2k_BAUD_RATE			25
#define   USART_28.8k_BAUD_RATE			16
#define   USART_38.4k_BAUD_RATE			12
#define   USART_57.6k_BAUD_RATE			8
#define   USART_78.8k_BAUD_RATE			6
#define   USART_115.2k_BAUD_RATE		3
#define   USART_230.4k_BAUD_RATE		1
#define   USART_250k_BAUD_RATE			1
#define   USART_0.5m_BAUD_RATE			0
#define   USART_1m_BAUD_RATE			0
/**************************************************************/
/*RXCEIE*/
#define		RXCIE_ENABLE		1
#define		RXCIE_DISABLE		0
/***************************************************************/
/*TXCIE*/
#define		TXCIE_ENABLE		1
#define		TXCIE_DISABLE		0
/***************************************************************/
/*UDRIE*/
#define		UDRIE_ENABLE		1
#define		UDRIE_DISABLE		0
/****************************************************************/
/*		<-- Character Siza-->									*/

#define    USART_5_BIT		0x00
#define    USART_6_BIT		0x02
#define    USART_7_BIT		0x04
#define    USART_8_BIT		0x06
#define    USART_9_BIT		0x06
/*******************************************************************/
/*BIT NUMBER  WHEN CHOOSING CHARACTER SIZE 9 BITS*/
#define		RECEIVE_DATA_BIT_8			1
#define		TRANSMIT_DATA_BIT_8			0

/********************************************************************/
/*MODE SELECT*/
#define	Asynchronous_Operation			0
#define	Syncrounous_Operation			1
/********************************************************************/
/*PARTIY MODE*/

#define		PARAITY_DISABLE				00
#define		PARAITY_EVEN				10
#define		PARITY_ODD					11
/********************************************************************/
/*STOPS BITS*/
#define			STOP_1_BIT				0
#define			STOP_2_BIT				1
/**********************************************************************/
/*CPOL*/
#define  USART_SET_UP_RISING_SAMPLE_FALLING			0
#define  USART_SET_UP_FALLING_SAMPLE_RISING			1

/*********************************************************************/
/*RX ENABLE */
#define			USART_RXEN			16
#define			USART_RXDISEN		0
/*********************************************************************/
/*TX ENABLE */
#define			USART_TXEN			8
#define			USART_TXDISEN		0
/************************************************************************/
/*FLAGS*/

#define UCSRA_RXC						7
#define UCSRA_TXC						6
#define UCSRA_UDRE						5
#define UCSRA_FRAME_ERROR				4
#define UCSRA_DATA_OVER_RUN 			3
#define	UCSRA_PARITY_ERROR				2
/************************************************************************/
#define		UDR_BIT_8						8
#define		USART_TXB8						0
#define		USART_RXB8						1

#define    GLOBAL_INTERRUPT_ENABLE			7






#endif /* UART_PRVATE_H_ */
