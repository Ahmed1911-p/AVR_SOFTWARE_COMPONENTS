#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"


void STEP_voidRotateCWStep(void)
{
	DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_B_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_P_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_Y_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_O_PIN,DIO_LOW);
	_delay_ms(10);
	
	
	DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_B_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_P_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_Y_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_O_PIN,DIO_LOW);
		_delay_ms(10);
	
	
	DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_B_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_P_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_Y_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_O_PIN,DIO_LOW);
		_delay_ms(10);
	
	
	
		DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_B_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_P_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_Y_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_O_PIN,DIO_HIGH);
		_delay_ms(10);
	
}
void STEP_voidRotateACWStep(void)
{
		DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_O_PIN,DIO_HIGH);
		DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_Y_PIN,DIO_LOW);
		DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_P_PIN,DIO_LOW);
		DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_B_PIN,DIO_LOW);
			_delay_ms(10);
		
		
		DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_O_PIN,DIO_LOW);
		DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_Y_PIN,DIO_HIGH);
		DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_P_PIN,DIO_LOW);
		DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_B_PIN,DIO_LOW);
			_delay_ms(10);
		
		
		DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_O_PIN,DIO_LOW);
		DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_Y_PIN,DIO_LOW);
		DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_P_PIN,DIO_HIGH);
		DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_B_PIN,DIO_LOW);
			_delay_ms(10);
		
		
		DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_O_PIN,DIO_LOW);
		DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_Y_PIN,DIO_LOW);
		DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_P_PIN,DIO_LOW);
		DIO_voidSetPinValue(STEP_MOTOR_PORT,STEP_MOTOR_B_PIN,DIO_HIGH);
			_delay_ms(10);
		
}