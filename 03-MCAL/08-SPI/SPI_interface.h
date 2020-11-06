/**********************************************************/
/* Author : Ahmed Ashraf								  */
/* DATE   : 5th Nov										  */
/* Version: V01											  */
/**********************************************************/

#ifndef		SPI_INTERFACE_H
#define 	SPI_INTERFACE_H

void SPI_voidInit(void);
void SPI_voidSendReceiveSynch(u8 Copy_u8Data , u8 * Copy_DataToReceive);
void SPI_voidSendReceiveAsynch(u8 Copy_u8Data , void (*ptr) (u8));



#endif
