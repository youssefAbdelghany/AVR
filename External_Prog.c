/*
 * External_Prog.c
 *
 *  Created on: Apr 14, 2018
 *      Author: Youssef
 */
#include "Std_Types.h"
#include "Utils.h"
#include"Delay.h"
#include "DIO_Cfg.h"
#include"DIO_Interface.h"
#include "SevenSegment_Cfg.h"
#include"SevenSegment_Interface.h"
#include "LCD_Cfg.h"
#include "LCD_Interface.h"
#include"Keypad_Cfg.h"
#include"Keypad_Interface.h"
#include"External_Cfg.h"
#include"External_Interface.h"
/*Prototype for telling the compiler that vector_1 is not an ordinary function , it's a declaration
 * for external intrrupt*/
void __vector_1 (void) __attribute__((signal,__INTR_ATTRS));
void __vector_2 (void) __attribute__((signal,__INTR_ATTRS));
void Ext_vidInit(void)
{
#if(EXT0==ENABLE)
	SET_BIT(SREG,7); /*Enable External Interrupt*/
	SET_BIT(MCUCR,1);/*External Interrupt jump tp ISR on Falling Edge Trigger*/
	SET_BIT(GICR,6); /*INT0 ENABLE*/
#endif
#if(EXT1==ENABLE)
	SET_BIT(SREG,7);
	SET_BIT(MCUCR,1);
	SET_BIT(GICR,7);
#endif
#if(EXT2==ENABLE)
	SET_BIT(SREG,7);
	SET_BIT(MCUCR,0);
	SETBIT(GICR,5);
#endif
}

void __vector_1(void)
{	/*Function to write any thing can be done then external interrupt 0 is on and is pressed*/
	u8 word[]={"Interrupted"};
u8 Local_u8StringLength,Local_u8LoopIndex;
	LCD_Init();
	LCD_WriteCommand(LCD_FIRST_ROW);

	for(Local_u8StringLength=0;word[Local_u8StringLength] != '\0' ;Local_u8StringLength++);
	for(Local_u8LoopIndex=0;Local_u8LoopIndex<Local_u8StringLength;Local_u8LoopIndex++)
			{
				LCD_WriteData(word[Local_u8LoopIndex]);
			}
	DELAY_ms(1000);
	LCD_WriteCommand(LCD_CLEAR);

	}

void __vector_2(void)
{

}



