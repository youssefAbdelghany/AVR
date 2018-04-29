/*
 * Keypad_Prog.c
 *
 *  Created on: Apr 14, 2018
 *      Author: Youssef
 */
#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Cfg.h"
#include"DIO_Interface.h"
#include"Keypad_Cfg.h"
#include"Keypad_Interface.h"
#include"LCD_Cfg.h"
#include"LCD_Interface.h"
#define ASCII 48


u8 Keypad_u8GetKey(u8* Copy_u8KeyValue)
{
	u8 Local_u8KeypadStatus;
	/*Initializing Output Pins as High*/
	DIO_vidSetPinValue(R1 , (u8)HIGH );
	DIO_vidSetPinValue(R2, (u8)HIGH );
	DIO_vidSetPinValue(R3, (u8)HIGH );
	DIO_vidSetPinValue(R4, (u8)HIGH );
	/*===============================*/
	/*The concept depends on making R1=0 and R234=1 and cheking for C1234 = 0 or not
	 * If pressed it will be =0 .. then Cheking for R234 = 0 one by one and so the 2-D Matrix is
	 * formed by looping on R as output and cheking for C1234 every time */
	DIO_vidSetPinValue(R1 , (u8)LOW );

	if((DIO_u8GetPinValue(C1))==0)
	{
		*Copy_u8KeyValue = (u8)	SWITCH1 ;
		Local_u8KeypadStatus = (u8)HIGH;


	}
	if((DIO_u8GetPinValue(C2))==0)
	{
		*Copy_u8KeyValue = (u8)	SWITCH2 ;
		Local_u8KeypadStatus = (u8)HIGH;
	}
	if((DIO_u8GetPinValue(C3))==0)
	{
		*Copy_u8KeyValue = (u8)	SWITCH3 ;
		Local_u8KeypadStatus = (u8)HIGH;
	}
	if((DIO_u8GetPinValue(C4))==0)
	{
		*Copy_u8KeyValue = (u8)SWITCHA;

		Local_u8KeypadStatus = (u8)HIGH;
	}
	/*=======================================*/
	DIO_vidSetPinValue(R1 , (u8)HIGH );
	DIO_vidSetPinValue(R2 , (u8)LOW );


	if((DIO_u8GetPinValue(C1))==0)
	{
		*Copy_u8KeyValue = (u8)	SWITCH4 ;
		Local_u8KeypadStatus = (u8)HIGH;
	}
	if((DIO_u8GetPinValue(C2))==0)
	{
		*Copy_u8KeyValue = (u8)	SWITCH5 ;
		Local_u8KeypadStatus = (u8)HIGH;
	}
	if((DIO_u8GetPinValue(C3))==0)
	{
		*Copy_u8KeyValue = (u8)	SWITCH6 ;
		Local_u8KeypadStatus = (u8)HIGH;
	}
	if((DIO_u8GetPinValue(C4))==0)
	{
		*Copy_u8KeyValue =(u8)SWITCHB ;
		Local_u8KeypadStatus = (u8)HIGH;
	}
	/*=======================================*/
	DIO_vidSetPinValue(R2 , (u8)HIGH );
	DIO_vidSetPinValue(R3 , (u8)LOW );



		if((DIO_u8GetPinValue(C1))==0)
		{
			*Copy_u8KeyValue = (u8)	SWITCH7 ;
			Local_u8KeypadStatus = (u8)HIGH;
		}
		if((DIO_u8GetPinValue(C2))==0)
		{
			*Copy_u8KeyValue = (u8)	SWITCH8 ;
			Local_u8KeypadStatus = (u8)HIGH;
		}
		if((DIO_u8GetPinValue(C3))==0)
		{
			*Copy_u8KeyValue = (u8)	SWITCH9;
			Local_u8KeypadStatus = (u8)HIGH;
		}
		if((DIO_u8GetPinValue(C4))==0)
		{
			*Copy_u8KeyValue = (u8)SWITCHC ;
			Local_u8KeypadStatus = (u8)HIGH;
		}
		/*=======================================*/
		DIO_vidSetPinValue(R3 , (u8)HIGH );
		DIO_vidSetPinValue(R4 , (u8)LOW );




			if( (DIO_u8GetPinValue(C1))==0)
			{
				*Copy_u8KeyValue =(u8)SWITCH_ASTRIK ;
				Local_u8KeypadStatus = (u8)HIGH;
			}
			if((DIO_u8GetPinValue(C2))==0)
			{
				*Copy_u8KeyValue = (u8)	SWITCH0 ;
				Local_u8KeypadStatus = (u8)HIGH;
			}
			if((DIO_u8GetPinValue(C3))==0)
			{
				*Copy_u8KeyValue =(u8)SWITCH_SH ;
				Local_u8KeypadStatus = (u8)HIGH;
			}
			if((DIO_u8GetPinValue(C4))==0)
			{
				*Copy_u8KeyValue =(u8)SWITCHD ;
				Local_u8KeypadStatus = (u8)HIGH;
			}

			/*=======================================*/


	return Local_u8KeypadStatus;
}


void Keypad_vidKeypadInit(void)
{
	DIO_vidSetPinDirection( R1 , OUTPUT );
	DIO_vidSetPinDirection( R2 , OUTPUT );
	DIO_vidSetPinDirection( R3 , OUTPUT );
	DIO_vidSetPinDirection( R4 , OUTPUT );
	DIO_vidSetPinDirection( C1 , INPUT_PULLUP );
	DIO_vidSetPinDirection( C2 , INPUT_PULLUP );
	DIO_vidSetPinDirection( C3 , INPUT_PULLUP );
	DIO_vidSetPinDirection( C4 , INPUT_PULLUP );
}



