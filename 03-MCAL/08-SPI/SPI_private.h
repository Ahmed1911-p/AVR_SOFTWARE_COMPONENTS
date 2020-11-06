/**********************************************************/
/* Author : Ahmed Ashraf								  */
/* DATE   : 5th Nov										  */
/* Version: V01											  */
/**********************************************************/

#ifndef		SPI_PRIVATE_H
#define 	SPI_PRIVATE_H

/*******************************************/
/*REGISTERS*/
#define	SPDR	(*(volatile u8*)0x2F)
#define	SPSR	(*(volatile u8*)0x2E)
#define	SPCR	(*(volatile u8*)0x2D)

#define SREG_REG		*((volatile u8 *) 0x5F)
/********************************************/
/*BITS OF REGISTERS*/
#define	SPSR_SPIF							7
#define	SPSR_WCOL							6
#define	SPSR_SPI2X							0
	
#define SPCR_SPIE							7
#define SPCR_SPE							6
#define	SPCR_DORD							5
#define SPCR_MSTR							4		
#define	SPCR_CPOL							3
#define	SPCR_CPHP							2
#define	SPCR_SPR1							1
#define	SPCR_SPR0							0



#define    GLOBAL_INTERRUPT_ENABLE			7

/***********************************************/
/*STATE OF SPI*/
#define     SPI_ENABLE						1
#define     SPI_DISABLE						0
/***********************************************/
/*INTERRUPT OF OF SPI*/
#define		SPI_INTERRUPT_DISABLE				0
#define		SPI_INTERRUPT_ENABLE				1
/***********************************************/
/*DATA ORDER*/
#define   SPI_LSB_FIRST_TRANSFER				1
#define   SPI_MSB_FIRST_TRANSFER				0
/***********************************************/
/*MASTER OR SLAVE*/
#define	SPI_MASTER							1
#define	SPI_SLAVE							0
/***********************************************/
/*CPOL*/
#define		SPI_LEADING_EDG_RISING		 	0
#define		SPI_LEADING_EDG_FALLING			1
/***********************************************/
/*CPHA*/
#define		SPI_SAMPLE_THEN_SETUP			0	
#define		SPI_SETUP_THEN_SAMPLE			1
/**********************************************/
/*CLOCK RATE*/

#define    SPI_F_OSCILLATOR_DIVIDED_4		0
#define    SPI_F_OSCILLATOR_DIVIDED_16		1
#define    SPI_F_OSCILLATOR_DIVIDED_64		2
#define    SPI_F_OSCILLATOR_DIVIDED_128		3
/**********************************************/
/*DOUBLE SPEED RATE*/
#define    SPI_DOUBLE_SPEED_RATE_ENABLE		1
#define    SPI_DOUBLE_SPEED_RATE_DISABLE	0
/*************************************************/
#endif
