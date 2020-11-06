/**********************************************************/
/* Author : Ahmed Ashraf								  */
/* DATE   : 5th Nov										  */
/* Version: V01											  */
/**********************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"SPI_interface.h"
#include"SPI_private.h"
#include"SPI_config.h"
#include"DIO_interface.h"

void (*callBack)(u8);
void SPI_voidInit(void)
{
	/*Clear the bits first*/
	SPCR = 0;
	SPSR = 0 ;
	/*(CHOOSE THE STATE OF SPI ENABLE OR DISABLE) AND (SPI INTERRUPT) AND (DATA ORDER)
		AND (CLOCK POLARITY) AND SLAVE OR MASTER AND(CPOL&CPHA) AND () */
	SPCR = (SPI_STATE<<SPCR_SPE) | 
		   (SPI_INTERRUPT_STATE<<SPCR_SPIE) |
		   (SPI_DATA_ORDER<<SPCR_DORD)|
		   (SPI_MASTER_SLAVE_SELECT<<SPCR_MSTR)|
		   (SPI_CPOL<<SPCR_CPOL)|
		   (SPI_CPHA<<SPCR_CPHP);
	/*ONLY SPEED RATE FOR MASTER */
	if(SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
	{
		SPCR|=(SPI_CLOCK_RATE);
		SPSR |= SPI_DOUBLE_SPEED_RATE;
	}
	/*ONLY FOR ENABLE INTERRUPT*/
	if(SPI_INTERRUPT_STATE == SPI_INTERRUPT_ENABLE)
	{
		SET_BIT(SREG_REG,GLOBAL_INTERRUPT_ENABLE);
	}  	
}

void SPI_voidSendReceiveSynch(u8 Copy_u8Data , u8 * Copy_DataToReceive)
{
	if(SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
	{
		DIO_voidSetPinValue(SLAVE_PIN,DIO_LOW);
	}
	SPDR = u8Data;
	while(GET_BIT(SPSR,SPSR_SPIF) == 0);
	*Copy_DataToReceive = SPDR;
	if(SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
	{
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_HIGH);
	}
}

void SPI_voidSendReceiveAsynch(u8 Copy_u8Data , void (*ptr) (u8))
{
	/*Send Data*/
	SPDR = u8Data;
	/*Assign Functions*/
	callBack = ptr ;
}


ISR(SPI_STC_vect)
{
	u8 Loc_u8Res;
	Loc_u8Res = SPDR ; 
	callBack(Loc_u8Res);
	
}
