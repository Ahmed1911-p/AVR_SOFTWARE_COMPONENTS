#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_Config.h"
#include "avr/interrupt.h"

void TIMER1_voidInit(void)
{
	/*MODE*/
	TIMER1_REG -> TCCR &= ~(0x030C);
	TIMER1_REG -> TCCR |=TIMER1_MODE_OPERATION ;
	/*PRESCALLER*/
	TIMER1_REG -> TCCR &= ~(0x0000|0b00000111);
	TIMER1_REG -> TCCR |= TIMER1_CLOCK_SELECT ;
	/*COMPARE OUTPUT MATCH PINS--> OC1A&OC1B*/
	TIMER1_REG -> TCCR &= ~(0xF000);
	TIMER1_REG -> TCCR |= TIMER1_OC1A_MODE_OPERATION ;
	TIMER1_REG -> TCCR |= TIMER1_OC1B_MODE_OPERATION ;
	/*INPUT CAPTURE UNIT */
	if   (INPUT_CAPTURE_NOISE_CANCELER == INPUT_CAPTURE_NOISE_CANCELER_ENABLE)
	{
			SET_BIT(TIMER1_REG -> TCCR , INPUT_CAPTURE_NOISE_CANCELER_BIT);
	}
	else
	{
			CLR_BIT(TIMER1_REG -> TCCR , INPUT_CAPTURE_NOISE_CANCELER_BIT);
	}

		/*ENABLE INTERRUPT*/
	if (TIMER1_INTERRUPT_STATE == TIMER1_INTERRUPT_ENABLE)
	{
	TIMER1_TIMSK_REG  &= ~(0b00111100);
	TIMER1_TIMSK_REG |= TIMER1_INTERRUPT ;
	SET_BIT(SREG_REG,GLOBAL_INTERRUPT_ENABLE);
	}
	else
	{
		/*NO INTERRUPT*/
	}
}



void TIMER1_voidSetInputCaptureEdgeSelector(u8 Copy_u8SensitveLatch)
{
	if( Copy_u8SensitveLatch == RISING_EDGE)
	{
		SET_BIT(TIMER1_REG -> TCCR , INPUT_CAPTURE_EDG_SELECTOR_BIT);
	}
	else if (Copy_u8SensitveLatch == FALLING_EDGE)
	{
		CLR_BIT(TIMER1_REG -> TCCR , INPUT_CAPTURE_EDG_SELECTOR_BIT);
	}
	else
	{
		/*ERROR*/
	}

}


void TIMER1_voidSetTimerCountVal(u16 Copy_u16TimeVal)
{
	TIMER1_REG -> TCNT = Copy_u16TimeVal;
}

void TIMER1_voidSetTimeOcAVal(u16 Copy_u16TimeVal)
{
	TIMER1_REG -> OCRB = Copy_u16TimeVal;
}

void TIMER1_voidSetTimeOcBVal(u16 Copy_u16TimeVal)
{
	TIMER1_REG -> OCRA = Copy_u16TimeVal;
}

void TIMER1_voidSetInputCapture(u16 Copy_u16TimeVal)
{
	TIMER1_REG -> ICR = Copy_u16TimeVal;
}

u16 TIMER1_u16GetInputCapture(void)
{
	u16 Loc_u16Result ;
	Loc_u16Result = TIMER1_REG -> ICR ;
	return Loc_u16Result ;
}


void TIMER1_voidSetOvfAction(void (*ptr) (void))
{
	TIMER1_CallBack[0] = ptr ;
}

void TIMER1_voidSetOcA_Action(void (*ptr) (void))
{
	TIMER1_CallBack[1] = ptr ;
}
void TIMER1_voidSetOcB_Action(void (*ptr) (void))
{
	TIMER1_CallBack[2] = ptr ;
}
void TIMER1_voidSetInputCaptureAction(void (*ptr) (void))
{
	TIMER1_CallBack[3] = ptr ;
}


ISR(TIMER1_OVF_vect)
{

		TIMER1_CallBack[0]();

}


ISR(TIMER1_COMPA_vect)
{

		TIMER1_CallBack[1]();

}
ISR(TIMER1_COMPB_vect)
{
		TIMER1_CallBack[2]();


}
ISR(TIMER1_CAPT_vect)
{

		TIMER1_CallBack[3]();

}

