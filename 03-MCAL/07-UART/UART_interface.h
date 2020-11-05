/*
 * UART_interface.h
 *Author  :  Ahmed Ashraf
 *Date    :	 31 Oct 2020
 *Version :  V01
 */
;
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit();
void UART_voidSendData(u16 Copy_u16Data);
void UART_voidSetTransmitCompleteFunc(void (*ptr) (void));
void UART_voidReadToReceiveFunc(void (*ptr) (void));
u16 UART_u16SynchReceiveData(void);
void UART_voidReceiveAsynch(void (*ptr)(u16));


#endif /* UART_INTERFACE_H_ */
