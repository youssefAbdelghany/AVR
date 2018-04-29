/*
 * 7Segment_Prog.c
 *
 *  Created on: Apr 18, 2018
 *      Author: Youssef
 */
#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Cfg.h"
#include"DIO_Interface.h"
#include"Delay.h"
#include "SevenSegment_Cfg.h"
#include"SevenSegment_Interface.h"

	void SevenSegment_vidWrite(u8 Copy_u8Decimal,u32 Copy_u8TimeToDisplay)
	{
		u32 Local_u8LoopIndex;
		u8 Local_u8Tenth,Local_u8Units;
		//DIO_vidSetNibbleDirection((u8) SEVENSEG_DATA, (u8)OUTPUT);
		 DIO_vidSetPinDirection(SEVENSEGMENT_A, (u8)OUTPUT);
		 DIO_vidSetPinDirection(SEVENSEGMENT_B, (u8)OUTPUT);
		 DIO_vidSetPinDirection(SEVENSEGMENT_C, (u8)OUTPUT);
		 DIO_vidSetPinDirection(SEVENSEGMENT_D, (u8)OUTPUT);

		DIO_vidSetPinDirection((u8)SEVENSEG_ENABLE1, (u8)OUTPUT);
		DIO_vidSetPinDirection((u8)SEVENSEG_ENABLE2, (u8)OUTPUT);
		Local_u8Tenth=Copy_u8Decimal/10;
		Local_u8Units=Copy_u8Decimal%10;

		for(Local_u8LoopIndex=0;Local_u8LoopIndex<=Copy_u8TimeToDisplay;Local_u8LoopIndex++)
		{
			//DIO_vidSetNibbleValue(SEVENSEG_DATA ,Local_u8Tenth );
			DIO_vidSetPinValue(SEVENSEGMENT_A,GET_BIT(Local_u8Tenth,0));
			DIO_vidSetPinValue(SEVENSEGMENT_B,GET_BIT(Local_u8Tenth,1));
			DIO_vidSetPinValue(SEVENSEGMENT_C,GET_BIT(Local_u8Tenth,2));
			DIO_vidSetPinValue(SEVENSEGMENT_D,GET_BIT(Local_u8Tenth,3));

			DIO_vidSetPinValue(SEVENSEG_ENABLE2 ,HIGH );
			DELAY_ms(1);
			DIO_vidSetPinValue(SEVENSEG_ENABLE2 ,LOW );

			//DIO_vidSetNibbleValue(SEVENSEG_DATA ,Local_u8Units );
			DIO_vidSetPinValue(SEVENSEGMENT_A,GET_BIT(Local_u8Units,0));
			DIO_vidSetPinValue(SEVENSEGMENT_B,GET_BIT(Local_u8Units,1));
			DIO_vidSetPinValue(SEVENSEGMENT_C,GET_BIT(Local_u8Units,2));
			DIO_vidSetPinValue(SEVENSEGMENT_D,GET_BIT(Local_u8Units,3));
			DIO_vidSetPinValue(SEVENSEG_ENABLE1 ,HIGH );
			DELAY_ms(1);
			DIO_vidSetPinValue(SEVENSEG_ENABLE1 ,LOW );

		}
	}
	void SevenSegment_vidCountUp(u8 Copy_u8CountFrom,u8 Copy_u8CountTo,u8 Copy_u8CountingStep)
	{
		s8  Local_u8LoopIndex ;
		for(Local_u8LoopIndex=Copy_u8CountFrom;Local_u8LoopIndex<=Copy_u8CountTo;Local_u8LoopIndex+=Copy_u8CountingStep)
		{
		SevenSegment_vidWrite(Local_u8LoopIndex,COUNT_SPEED_ms);
		}

	}
	void SevenSegment_vidCountDown(u8 Copy_u8CountFrom,u8 Copy_u8CountTo,u8 Copy_u8CountingStep)
	{
		s8  Local_u8LoopIndex ;
		for(Local_u8LoopIndex=Copy_u8CountFrom;Local_u8LoopIndex>=Copy_u8CountTo;Local_u8LoopIndex-=Copy_u8CountingStep)
		{
		SevenSegment_vidWrite(Local_u8LoopIndex,COUNT_SPEED_ms);
		}

	}


