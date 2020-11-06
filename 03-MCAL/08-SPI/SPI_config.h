/**********************************************************/
/* Author : Ahmed Ashraf								  */
/* DATE   : 5th Nov										  */
/* Version: V01											  */
/**********************************************************/

#ifndef		SPI_CONFIG_H
#define 	SPI_CONFIG_H


/**********************************************************/
/*SLAVE PIN*/
/*Write it in pair PORT,PIN */ 
#define SLAVE_PIN		DIO_PORTB,DIO_PIN4
/**********************************************************/
/*ENABLE SPI*/
/*
Options:
SPI_ENABLE
SPI_DISABLE
*/
#define SPI_STATE			SPI_ENABLE
/***********************************************************/
/*SPI INTERRUPT*/
/*
Options :
SPI_INTERRUPT_ENABLE
SPI_INTERRUPT_DISABLE
*/
#define		SPI_INTERRUPT_STATE					SPI_INTERRUPT_DISABLE
/*************************************************************/
/*SPI DATA ORDER*/
/*
Options :
SPI_LSB_FIRST_TRANSFER
SPI_MSB_FIRST_TRANSFER
*/
#define	SPI_DATA_ORDER						SPI_MSB_FIRST_TRANSFER
/**************************************************************/
/*MASTER OR SLAVE*/
/*
Options:
SPI_MASTER
SPI_SLAVE
*/
#define	SPI_MASTER_SLAVE_SELECT				SPI_MASTER
/**************************************************************/
/*CPOL*/
/*
Options:
SPI_LEADING_EDG_RISING
SPI_LEADING_EDG_FALLING
*/
#define		SPI_CPOL			SPI_LEADING_EDG_RISING
/*************************************************************/
/*CPHA*/
/*
Options:
SPI_SAMPLE_THEN_SETUP
SPI_SETUP_THEN_SAMPLE
*/
#define		SPI_CPHA				SPI_SAMPLE_THEN_SETUP
/**************************************************************/
/*Clock Rate*/
/*
Options:
SPI_F_OSCILLATOR_DIVIDED_4
SPI_F_OSCILLATOR_DIVIDED_16
SPI_F_OSCILLATOR_DIVIDED_64
SPI_F_OSCILLATOR_DIVIDED_128
*/

#define  SPI_CLOCK_RATE				SPI_F_OSCILLATOR_DIVIDED_4
/**************************************************************/
/*Double SPI Speed rate*/
/*
Options :
SPI_DOUBLE_SPEED_RATE_ENABLE
SPI_DOUBLE_SPEED_RATE_DISABLE
*/
#define		SPI_DOUBLE_SPEED_RATE		SPI_DOUBLE_SPEED_RATE_ENABLE

#endif
