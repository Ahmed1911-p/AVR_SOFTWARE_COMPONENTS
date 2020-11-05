/*****************************************/
/**   Author : Ahmed Ashraf				*/
/**   DATE   : 22 OCT 2020              */
/**   Version: V01						*/
/****************************************/
#ifndef		TIMER1_INTERFACE_H
#define     TIMER1_INTERFACE_H

#define RISING_EDGE		1
#define	FALLING_EDGE    3


void TIMER1_voidInit(void);
void TIMER1_voidSetInputCaptureEdgeSelector(u8 Copy_u8SensitveLatch);
void TIMER1_voidSetTimerCountVal(u16 Copy_u16TimeVal);
void TIMER1_voidSetTimeOcAVal(u16 Copy_u16TimeVal);
void TIMER1_voidSetTimeOcBVal(u16 Copy_u16TimeVal);
void TIMER1_voidSetInputCapture(u16 Copy_u16TimeVal);
u16 TIMER1_u16GetInputCapture(void);
void TIMER1_voidSetOvfAction(void (*ptr) (void));
void TIMER1_voidSetOcA_Action(void (*ptr) (void));
void TIMER1_voidSetOcB_Action(void (*ptr) (void));
void TIMER1_voidSetInputCaptureAction(void (*ptr) (void));



#endif
