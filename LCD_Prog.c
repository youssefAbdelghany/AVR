/*
 * LCD_Prog.c
 *
 *  Created on: Apr 7, 2018
 *      Author: Youssef
 */
#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Cfg.h"
#include"DIO_Interface.h"
#include"Delay.h"
#include"LCD_Cfg.h"
#include "LCD_Interface.h"



void LCD_Init()
{
	/* PORTS Initialization  */
	// DIO_vidSetNibbleDirection((u8)LCD_DATA, (u8)OUTPUT);
	 DIO_vidSetPinDirection(LCD_D4, (u8)OUTPUT);
	 DIO_vidSetPinDirection(LCD_D5, (u8)OUTPUT);
	 DIO_vidSetPinDirection(LCD_D6, (u8)OUTPUT);
	 DIO_vidSetPinDirection(LCD_D7, (u8)OUTPUT);

	 DIO_vidSetPinDirection(LCD_RS, (u8)OUTPUT);
	 DIO_vidSetPinDirection(LCD_RW, (u8)OUTPUT);
	 DIO_vidSetPinDirection(LCD_E, (u8)OUTPUT);

	/***********/

	/*****LCD have some initialization preparations in the datasheet commanding and delaying .. ******/
	DELAY_ms(50);
	LCD_WriteCommand(0x02);
	LCD_WriteCommand(0x28);

	DELAY_ms(50);
	LCD_WriteCommand(0x0c);

	DELAY_ms(50);
	LCD_WriteCommand(0x01);
	DELAY_ms(100);

}
void LCD_WriteCommand(u8 Copy_u8Command)
{

	DIO_vidSetPinValue((u8)LCD_RS ,(u8)LOW);
	DIO_vidSetPinValue((u8)LCD_RW ,(u8)LOW);
	/*4-BIT INITIALIZATION ON 2 STEPS (sending high and low nibble both on high nibble to save pins
	 * FALLING EDGE(E=1--delay-- E=0)--> in the controller ..send high nibble ->
	 * FALLING EDGE(E=1--delay-- E=0) -> ) -->then sending the low nibble */

	//DIO_vidSetNibbleValue((u8)LCD_DATA,GET_HIGHNIBBLE(Copy_u8Command));
	DIO_vidSetPinValue(LCD_D4,GET_BIT(Copy_u8Command,4));
	DIO_vidSetPinValue(LCD_D5,GET_BIT(Copy_u8Command,5));
	DIO_vidSetPinValue(LCD_D6,GET_BIT(Copy_u8Command,6));
	DIO_vidSetPinValue(LCD_D7,GET_BIT(Copy_u8Command,7));

	/*INIT E=1 E=0 FALLING EDGE */
	DIO_vidSetPinValue((u8)LCD_E ,(u8)HIGH );
	DELAY_ms(5);
	DIO_vidSetPinValue((u8)LCD_E ,(u8)LOW );

	//DIO_vidSetNibbleValue((u8)LCD_DATA,GET_LOWNIBBLE(Copy_u8Command));
	DIO_vidSetPinValue(LCD_D4,GET_BIT(Copy_u8Command,0));
	DIO_vidSetPinValue(LCD_D5,GET_BIT(Copy_u8Command,1));
	DIO_vidSetPinValue(LCD_D6,GET_BIT(Copy_u8Command,2));
	DIO_vidSetPinValue(LCD_D7,GET_BIT(Copy_u8Command,3));
	DIO_vidSetPinValue((u8)LCD_E ,(u8)HIGH );
	DELAY_ms(5);
	DIO_vidSetPinValue((u8)LCD_E ,(u8)LOW );


}
/*same way as writing command but RS=1 */
void LCD_WriteData(u8 Copy_u8Data)
{
	DIO_vidSetPinValue((u8)LCD_RS ,(u8)HIGH);
	DIO_vidSetPinValue((u8)LCD_RW ,(u8)LOW);

	//DIO_vidSetNibbleValue((u8)LCD_DATA,GET_HIGHNIBBLE(Copy_u8Data));
	DIO_vidSetPinValue(LCD_D4,GET_BIT(Copy_u8Data,4));
	DIO_vidSetPinValue(LCD_D5,GET_BIT(Copy_u8Data,5));
	DIO_vidSetPinValue(LCD_D6,GET_BIT(Copy_u8Data,6));
	DIO_vidSetPinValue(LCD_D7,GET_BIT(Copy_u8Data,7));
	/*INIT E=1 E=0 FALLING EDGE */
	DIO_vidSetPinValue((u8)LCD_E ,(u8)HIGH );

	DELAY_ms(5);
	DIO_vidSetPinValue((u8)LCD_E ,(u8)LOW );

	//DIO_vidSetNibbleValue((u8)LCD_DATA,GET_LOWNIBBLE(Copy_u8Data));
	DIO_vidSetPinValue(LCD_D4,GET_BIT(Copy_u8Data,0));
	DIO_vidSetPinValue(LCD_D5,GET_BIT(Copy_u8Data,1));
	DIO_vidSetPinValue(LCD_D6,GET_BIT(Copy_u8Data,2));
	DIO_vidSetPinValue(LCD_D7,GET_BIT(Copy_u8Data,3));

	DIO_vidSetPinValue((u8)LCD_E ,(u8)HIGH );

	DELAY_ms(5);
	DIO_vidSetPinValue((u8)LCD_E ,(u8)LOW );
}

void LCD_WriteString(u8 Copy_u8aString[])
{

	u8 Local_u8StringLength,Local_u8LoopIndex;
	/*Counting Number of String Characters so we can control them .. counting depends on
	 * finding the NULL at the end of the string */
	for(Local_u8StringLength=0;Copy_u8aString[Local_u8StringLength] != '\0' ;Local_u8StringLength++);
	for(Local_u8LoopIndex=0;Local_u8LoopIndex<Local_u8StringLength;Local_u8LoopIndex++)
		{
		LCD_WriteData(Copy_u8aString[Local_u8LoopIndex]);
		}
}

