/*
 * AVR ATMEGA32 INSTRUCTIONS:
 * --------------------------
 * 1-DIO:
 * ======
 * 	DIO_vidSetPinDirection(PIN0, [OUTPUT/INPUT_PULLUP/INPUT_HIGHIMPEDANCE]);
	DIO_vidSetPinValue(PIN31 ,LOW/HIGH ); // [[PINS FROM 0-31]]
	DIO_u8GetPinValue(PIN31);
	DIO_vidSetPortDirection(PORT_A,[OUTPUT/INPUT_PULLUP/INPUT_HIGHIMPEDANCE]);
	SETTING PORT VALUE ->  PORTA = 0x$$;
	GETTING PORT VALUE ->   u8 x ; x=PINA ;
	DIO_vidSetNibbleDirection(NIBBLE0, [OUTPUT/INPUT_PULLUP/INPUT_HIGHIMPEDANCE]);
	DIO_vidSetNibbleValue(NIBBLE7 ,VALUE ); //[[ NIBBLES FROM 0-7]]
	DIO_u8GetNibbleValue(NIBBLE7);
	==================================================================================
	2-LCD:
	======
	LCD_Init();
	LCD_WriteCommand(LCD_FIRST_ROW);
	*LCD_CLEAR,LCD_FIRST_ROW,LCD_SECOND_ROW,LCD_HIDE_CURSOR LCD_SHIFT_RIGHT
	 *  LCD_SHIFT_LEFT LCD_DISP_OFF_CURSOR_OFF LCD_DISP_OFF_CURSOR_OFF CURSOR_BLINK
	 *  CURSOR_BLINK CURSOR_BLINK
	LCD_WriteData('a'); DATA TO WRITE ON LCD (ONE CHARACTER / INSTRUCTION)
	LCD_WriteString((u8*) "name"); TO WRITE STRING ON LCD
	==================================================================================
	3-Seven_Segment:
	===========
	SevenSegment_vidWrite(decimal,time to display); //2 digits number
	SevenSegment_vidCountUp(from,to,step);
	SevenSegment_vidCountDown(from,to,step);
	==================================================================================
	4-Keypad:
	==========
        Keypad_vidKeypadInit();
	u8 Keypad_u8GetKey(u8* Copy_u8KeyValue);  // e.g(x=Keypad_u8GetKey(&Local_u8KeyValue);)
	==================================================================================
	5-Interrupts:
	============
	Ext_vidInit();
	===================================================================================



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
//#define MOVING_DELAY_SEC 2

void main()
{
	Ext_vidInit();
		while(1)
		{
		    SevenSegment_vidCountUp(15,30,5);
		    SevenSegment_vidCountDown(60,0,5);

		}


}



