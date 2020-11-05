#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_Config.h"
#include "avr/interrupt.h"




void TIMER0_voidInit(void)
{
	/*Select MODES OF OPERATION */
	TIMER0_TCCR0_REG &= ~(0b01001000);
	TIMER0_TCCR0_REG |= TIMER0_MODE_OF_OPERATION;
	/*COMPARE OUTPUT MATCH MODE--> PIN*/

		if ( TIMER0_MODE_OF_OPERATION == NORMAL_TIME_MODE || TIMER0_MODE_OF_OPERATION == CTC_MODE)
		{
			TIMER0_TCCR0_REG &= ~(0b00110000);
			TIMER0_TCCR0_REG |= TIMER0_COMPARE_MATCH_OUTPUT_MODE_NOMAL_CTC_MODE;
		}
		else if (TIMER0_MODE_OF_OPERATION == FAST_PWM_MODE)
		{
			TIMER0_TCCR0_REG &= ~(0b00110000);
			TIMER0_TCCR0_REG |= TIMER0_COMPARE_MATCH_OUTPUT_MODE_FAST_PMW;
		}
		else if (TIMER0_MODE_OF_OPERATION == PHASE_CORRECT_PWM)
		{
			TIMER0_TCCR0_REG &= ~(0b00110000);
			TIMER0_TCCR0_REG |= TIMER0_COMPARE_MATCH_OUTPUT_MODE_PHASE_CORRECT;
		}
		else
		{
			/*ERROR*/
		}

	/*CLOCK SELECT PRESCALE*/
	TIMER0_TCCR0_REG &= ~(0b00000111);
	TIMER0_TCCR0_REG |= TIMER0_CLOCK_SELECT ;

	/*ENABLE INTERRUPT*/
	if (TIMER0_INTERRUPT_STATE == TIMER0_INTERRUPT_ENABLE)
	{
	TIMER0_TIMSK_REG  &= ~(0b00000011);
	TIMER0_TIMSK_REG |= TIMER0_INTERRUPT ;
	SET_BIT(SREG_REG,GLOBAL_INTERRUPT_ENABLE);
	}
	else
	{
		/*NO INTERRUPT*/
	}
}


void TIMER0_voidSetTimerCountVal(u8 Copy_u8TimeVal)
{
	TIMER0_TCNT0_REG = Copy_u8TimeVal;
}

void TIMER0_voidSetTimeOcVal(u8 Copy_u8TimeVal)
{
	TIMER0_OCR0_REG = Copy_u8TimeVal;
}

void TIMER0_voidSetOvfAction(void (*ptr) (void))
{
	TIMER0_CallBack[0] = ptr ;
}

void TIMER0_voidSetOcAction(void (*ptr) (void))
{
	TIMER0_CallBack[1] = ptr ;
}




ISR(TIMER0_OVF_vect)
{
	TIMER0_CallBack[0]();
}


ISR(TIMER0_COMP_vect)
{
	TIMER0_CallBack[1]();
}

