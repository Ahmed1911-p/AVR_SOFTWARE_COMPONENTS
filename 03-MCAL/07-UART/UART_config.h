/*
 * UART_config.h
 *
 *Author  :  Ahmed Ashraf
 *Date    :	 31 Oct 2020
 *Version :  V01
 */
#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_
/***********************************************/
/*U2X*/
/*
Options : 
U2X_ENABLE
U2X_DISABLE
*/
#define USART_DOUBLE_USART_SPEED			U2X_DISABLE
/************************************************/
/*RECEIVER ENABLE*/
/*
Options :
USART_RXEN
USART_RXDISEN
*/
#define	USART_RECEIVER_STATE			USART_RXEN
/*************************************************/
/*Transmitter Enable*/
/*
Options :
USART_TXEN
USART_TXDISEN
*/
#define	USART_TRANSMITER_STATE			USART_TXEN
/**************************************************/
/*RXCIE*/
/*
Options :
RXCIE_ENABLE
RXCIE_DISABLE
*/
#define USART_COMPLETE_RECEIVED_INTERRUPT_ENABLE		RXCIE_ENABLE
/**************************************************/
/*TXCIE*/
/*
Options :
TXCIE_ENABLE
TXCIE_DISABLE
*/
#define		USART_COMPLETE_TRANSMIT_INTERRUPT_ENABLE	TXCIE_ENABLE
/*******************************************************/
/*UDRIE*/
/*
Options :
UDRIE_ENABLE
UDRIE_DISABLE
*/
#define 	USART_DATA_REGISER_EMPTY_INTERRUPT_ENABLE		UDRIE_DISABLE
/********************************************************/
/*CHAR SIZE*/
/*
Options :
USART_5_BIT
USART_6_BIT
USART_7_BIT
USART_8_BIT
USART_9_BIT
*/
#define		USART_CHARACTER_SIZE				USART_9_BIT
/**********************************************************/
/*MODE SELECT OF USART*/
/*Options : 
Asynchronous_Operation
Syncrounous_Operation
*/
#define		USART_MODE_SELECT		Asynchronous_Operation
/***********************************************************/
/*CPOL*/
/*
Options :
USART_SET_UP_RISING_SAMPLE_FALLING
USART_SET_UP_FALLING_SAMPLE_RISING
*/
#define		USART_CPOL		USART_SET_UP_RISING_SAMPLE_FALLING
/**********************************************************/
/*PARITY MODE*/
/*Options:
PARAITY_DISABLE
PARAITY_EVEN
PARITY_ODD
*/
#define		USART_PARITY_MODE		PARAITY_DISABLE
/**********************************************************/
/*STOPS BITS*/
/*
Options :
STOP_1_BIT
STOP_2_BIT
*/
#define		USART_STOP_BIT			STOP_1_BIT
/**********************************************************/
/*BAUD RATE*/

/*
Options : 
USART_2400_BAUD_RATE		207
USART_4800_BAUD_RATE		103
USART_9600_BAUD_RATE		51
USART_14.4k_BAUD_RATE		34
USART_19.2k_BAUD_RATE		25
USART_28.8k_BAUD_RATE		16
USART_38.4k_BAUD_RATE		12
USART_57.6k_BAUD_RATE		8
USART_78.8k_BAUD_RATE		6
USART_115.2k_BAUD_RATE		3
USART_230.4k_BAUD_RATE		1
USART_250k_BAUD_RATE		1
USART_0.5m_BAUD_RATE		0
USART_1m_BAUD_RATE			0
*/

#define USART_UBRR_8MHZ		USART_9600_BAUD_RATE




#endif /* UART_CONFIG_H_ */
