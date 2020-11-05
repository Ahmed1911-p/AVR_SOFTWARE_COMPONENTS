/***********************************/
/*  Author : Ahmed Ashraf		   */
/* 	DATE   : 13 OCT 2020    	   */
/*  Version: V01				   */
/***********************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/*ADC REFERENCE VOLTAGE*/
#define ADC_AREF				0b00000000
#define	ADC_INTERNAL_2_56		0b11000000
#define ADC_AVCC				0b01000000

#define ADC_ADJSTMENT_BIT		5
#define ADC_LEFT_ADJUST 		1
#define ADC_RIGHT_ADJUST 		0


#define ADC_ENABLE_BIT			7

#define ADC_START_COVERSION_BIT	6
#define ADC_CONVERSIOM_FLAG_BIT	4

/*MACRONS OF AUTO TRIGGER*/
#define ADC_AUTO_TRIGGER_OFF	0
#define	ADC_AUTO_TRIGGER_ON		1
#define ADC_AUTO_TRIGGER_BIT	5
//MODES
#define ADC_FREE_RUNNING						0b00000000
#define ADC_ANALOG_COMPARTOR					0b00100000
#define	ADC_INTERRUPT_REQUEST_0					0b01000000
#define ADC_TIMER_COUNTER_0_COMPARE_MATCH		0b01100000
#define	ADC_TIMER_COUNTER_0_OVERFLOW			0b10000000
#define	ADC_COUNTER_COMPARE_MATCH_B				0b10100000
#define	ADC_TIMER_COUNTER_1_OVERFLOW			0b11000000
#define	ADC_TIMER_COUNTER_1_CAPTURE_EVENT		0b11100000


/*INTERRUPT ADC*/
#define ADC_INTERRUPT_BIT		3
#define ADC_INTERRUPT_DISABLE	0
#define ADC_INTERRUPT_ENABLE	1

/*Macron of PRESCALER FOR CLOCK DIVISION OF ADC*/
#define   DIVISION_FACTOR_2		0b00000000
#define   DIVISION_FACTOR_4		0b00000010
#define   DIVISION_FACTOR_8     0b00000011
#define   DIVISION_FACTOR_16    0b00000100
#define   DIVISION_FACTOR_32    0b00000101
#define   DIVISION_FACTOR_64    0b00000110
#define   DIVISION_FACTOR_128	0b00000111

/*ADC REGISTERS */
#define ADC_ADMUX_REG	*((volatile u8 *) 0x27)
#define ADC_ADSRA_REG	*((volatile u8 *) 0x26)
#define ADC_ADCL_REG	*((volatile u8 *) 0x24)
#define ADC_ADHL_REG	*((volatile u8 *) 0x25)
#define ADC_SFIOR_REG	*((volatile u8 *) 0x50)


#endif
