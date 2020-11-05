/*****************************************/
/**   Author : Ahmed Ashraf				*/
/**   DATE   : 22 OCT 2020              */
/**   Version: V01						*/
/****************************************/
#ifndef		TIMER1_PRIVATE_H
#define     TIMER1_PRIVATE_H

/**********************************************************/
/* 		<-------  REGISTERS	---------->					  */

typedef struct 
{
	volatile u16 ICR;
	volatile u16 OCRB;
	volatile u16 OCRA;
	volatile u16 TCNT;
	volatile u16 TCCR;

	
	
}TIMER1_REGS ;

#define TIMER1_REG 			((TIMER1_REGS *) 0x46)

#define TIMER1_TIMSK_REG  									*((volatile u8*) 0x59)
#define SREG_REG											*((volatile u8 *) 0x5F)

/*************************************************************/

/****		<-- MODE OF OPERATION  -->						*/
#define 	TIMER1_NORMAL_0xFFFF_TOP_UPDATED_IMMEDIATE				0x0000
#define		TIMER1_PHASE_CORRECT_PWM_0x00FF_TOP_UPDATED_TOP			0x0100
#define		TIMER1_PHASE_CORRECT_PWM_0x01FF_TOP_UPDATED_TOP			0x0200
#define		TIMER1_PHASE_CORRECT_PWM_0x03FF_TOP_UPDATED_TOP			0x0300
#define		TIMER1_CTC_OCR1A_TOP_UPDATED_IMMEDIATE					0x0008
#define		TIMER1_FAST_PWM_0x00FF_TOP_UPDATED_TOP					0x0108
#define		TIMER1_FAST_PWM_0x01FF_TOP_UPDATED_TOP					0x0208
#define		TIMER1_FAST_PWM_0x03FF_TOP_UPDATED_TOP					0x0308
#define		TIMER1_PHASE_CORRECT_PWM_ICR1_TOP_UPDATED_BOTTOM		0x0010
#define		TIMER1_PHASE_CORRECT_PWM_OCR1A_TOP_UPDATED_BOTTOM		0x0110
#define		TIMER1_PHASE_CORRECT_PWM_ICR1_TOP_UPDATED_TOP			0x0210
#define		TIMER1_PHASE_CORRECT_PWM_OCR1A_TOP_UPDATED_TOP			0x0310
#define		TIMER1_CTC_MODE_ICR1_TOP_UPDATED_IMMEDIATE				0x0018
#define		TIMER1_FAST_PWM_MODE_ICR1_TOP_UPDATED_TOP				0x0218
#define		TIMER1_FAST_PWM_MODE_OCR1A_TOP_UPDATED_TOP				0x0318
/*************************************************************/

/*CLOCK SELECT FOR TIMER*/
#define     TIMER1_COUNTER_STOPPED							0x0000|0b00000000
#define     TIMER1_NO_PRESCALLER							0x0000|0b00000001
#define     TIMER1_8_PRESCALER								0x0000|0b00000010
#define     TIMER1_64_PRESCALER								0x0000|0b00000011
#define     TIMER1_256_PRESCALER							0x0000|0b00000100
#define     TIMER1_1024_PRESCALER							0x0000|0b00000101
#define		TIMER1_EXTERNAL_CLOCK_ON_T0_PIN_FALLING_EDGE	0x0000|0b00000110   
#define		TIMER1_EXTERNAL_CLOCK_ON_T0_PIN_RISING_EDGE		0x0000|0b00000111
/*******************************************************************************/
/*OC1A PIN*/
#define     TIMER1_OC1A_NORMAL_PORT_OPERATION												0x0000

#define     TIMER1_OC1A_TOGGLE_ON_COMPARE_MATCH_NON_PWM										0x4000
#define		TIMER1_OC1A_CLEAR_ON_COMPARE_MATCH_NON_PWM										0x8000
#define		TIMER1_OC1A_SET_ON_COMPARE_MATCH_NON_PWM										0xC000
	
#define		TIMER1_OC1A_CLEAR_ON_COMPARE_MATCH_SET_TOP_FAST_PWM								0x8000
#define		TIMER1_OC1A_SET_ON_COMPARE_MATCH_CLEAR_TOP_FAST_PWM								0xC000

#define	TIMER1_OC1A_CLEAR_ON_UP_COUNTING_SET_DOWN_COUNTING_PHASE_CORRECT				0x8000
#define		TIMER1_OC1A_SET_ON_UP_COUNTING_CLEAR_DOWN_COUNTING_PHASE_CORRECT				0xC000

/*********************************************************************************/
/*OC1B   PIN*/

#define     TIMER1_OC1B_NORMAL_PORT_OPERATION												0x0000
					  
#define     TIMER1_OC1B_TOGGLE_ON_COMPARE_MATCH_NON_PWM										0x1000
#define		TIMER1_OC1B_CLEAR_ON_COMPARE_MATCH_NON_PWM										0x2000
#define		TIMER1_OC1B_SET_ON_COMPARE_MATCH_NON_PWM										0x3000
					  
#define		TIMER1_OC1B_CLEAR_ON_COMPARE_MATCH_SET_TOP_FAST_PWM								0x2000
#define		TIMER1_OC1B_SET_ON_COMPARE_MATCH_CLEAR_TOP_FAST_PWM								0x3000
					  
#define	TIMER1_OC1B_CLEAR_ON_UP_COUNTING_SET_DOWN_COUNTING_PHASE_CORRECT				0x2000
#define		TIMER1_OC1B_SET_ON_UP_COUNTING_CLEAR_DOWN_COUNTING_PHASE_CORRECT				0x3000
/****************************************************************************************/
/*ICU*/
#define INPUT_CAPTURE_NOISE_CANCELER_ENABLE					1
#define INPUT_CAPTURE_NOISE_CANCELER_DISABLE				0

#define INPUT_CAPTURE_NOISE_CANCELER_BIT					7

#define INPUT_CAPTURE_EDG_SELECTOR_BIT						6
/*****************************************************************************************/
/*INTERRUPT*/
/*BITS*/
#define  GLOBAL_INTERRUPT_ENABLE							7
#define  TIMER1_INTERRUPT_ENABLE							1
#define  TIMER1_INTERRUPT_DISABLE							0


#define  TIMER1_INPUT_CAPTURE_INTERRUPT						0b00100000
#define	 TIMER1_COMPARE_MATCH_A_INTERRUPT					0b00010000
#define	 TIMER1_COMPARE_MATCH_B_INTERRUPT					0b00001000
#define	 TIMER1_OVERFLOW_INTERRUPT_ENABLE					0b00000100

#define TIMER1_INPUT_CABTURE_AND_COMPATE_MATCH_A            0b00110000
#define TIMER1_INPUT_CABTURE_AND_COMPATE_MATCH_A_AND_B      0b00111000
#define TIMER1_COMPATE_MATCH_A_AND_B          			    0b00011000

#define TIMER1_OVERFLOW_AND_COMPATE_MATCH_A        		    0b00010100
#define TIMER1_OVERFLOW_AND_COMPATE_MATCH_A_AND_B     	    0b00011100



static void (*TIMER1_CallBack[4]) (void) = {0,0,0,0};


#endif
