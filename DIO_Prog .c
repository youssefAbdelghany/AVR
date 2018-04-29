/*
 * main.c
 *
 *  Created on: Apr 6, 2018
 *      Author: Youssef
 */
#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Cfg.h"
#include"DIO_Interface.h"
#include"Keypad_Cfg.h"
#include"Keypad_Interface.h"
#define PORTPINS_NUMBER 8
#define DDRA_ADDRESS 0x3A
#define PORTA_ADDRESS 0x3B
#define PINA_ADDRESS 0x39
/*This Concept Depends on the relation between the Addresses of DDR(A-D) as well as PORT and PIN
 *  in ATMEGA32 , The relation between the Address and the succesive port is 3 Addresses
 *  so we can make a generic DDR,PORT and PIN to deal with and no need for DIO_Cfg.h unless user
 *   want to acess the ports himself */
#define DDRO  *( (volatile u8*) ((DDRA_ADDRESS -(3*Local_u8Port))))
#define PORTO *( (volatile u8*) ((PORTA_ADDRESS -(3*Local_u8Port))))
#define PINO  *( (volatile u8*) ((PINA_ADDRESS -(3*Local_u8Port))))

	void DIO_vidSetPortDirection(u8 Copy_u8PortNumber,u8 Copy_u8Direction)
	{
		u8 Local_u8Port  ;
		switch(Copy_u8Direction)
		{
		case OUTPUT :
		  DDRO = (u8) HIGH;
		  break;
		case INPUT_PULLUP :
		  DDRO = (u8) HIGH;
		  PORTO = (u8) HIGH;
		  break;
		case INPUT_HIGHIMPEDANCE :
		  DDRO = (u8) HIGH;
		  PORTO = (u8)LOW;
		break;
		}
	}
	void DIO_vidSetNibbleDirection(u8 Copy_u8NibbleNumber , u8 Copy_u8Direction)
	{
		u8 Local_u8Port , Local_u8HighorLowNibble ;
		Local_u8Port = Copy_u8NibbleNumber / 2;
		Local_u8HighorLowNibble = Copy_u8NibbleNumber % 2 ;
		switch(Copy_u8Direction)
		{
		case OUTPUT :
			switch(Local_u8HighorLowNibble)
			{
			case LOW:
				SET_LOWNIBBLE(DDRO);
				break;
			case HIGH:
				SET_HIGHNIBBLE(DDRO);
				break;
			}
			break;
		case INPUT_PULLUP :
			switch(Local_u8HighorLowNibble)
			{
				case LOW:
					CLR_LOWNIBBLE(DDRO);
					SET_LOWNIBBLE(PORTO);
					break;
				case HIGH:
					CLR_HIGHNIBBLE(DDRO);
					SET_HIGHNIBBLE(PORTO);
					break;
			}
			break;
		case INPUT_HIGHIMPEDANCE :
			switch(Local_u8HighorLowNibble)
			{
				case LOW:
					CLR_LOWNIBBLE(DDRO);
					CLR_LOWNIBBLE(PORTO);
					break;
				case HIGH:
					CLR_HIGHNIBBLE(DDRO);
					CLR_HIGHNIBBLE(PORTO);
					break;
			}
			break;
		}
	}

	void DIO_vidSetPinDirection(u8 Copy_u8PinNumber , u8 Copy_u8Direction)
	{
		u8 Local_u8Port , Local_u8Pin ;
		/*To get Ports Number 0=>A ..4=>D*/
		Local_u8Port = Copy_u8PinNumber / PORTPINS_NUMBER;
		 /*To get Pin's Number in Port */
		Local_u8Pin = Copy_u8PinNumber % PORTPINS_NUMBER ;
			switch(Copy_u8Direction)
			{
			case OUTPUT :
				SET_BIT(DDRO,Local_u8Pin);
				break;
			case INPUT_PULLUP :
				CLR_BIT(DDRO,Local_u8Pin);
				SET_BIT(PORTO,Local_u8Pin);
				break;
			case INPUT_HIGHIMPEDANCE :
				CLR_BIT(DDRO,Local_u8Pin);
				CLR_BIT(PORTO,Local_u8Pin);
				break;
			}
	}
	void DIO_vidSetNibbleValue(u8 Copy_u8NibbleNumber , u8 Copy_NibbleValue )
	{
		u8 Local_u8Port , Local_u8HighorLowNibble ;
		Local_u8Port = Copy_u8NibbleNumber / 2;
		Local_u8HighorLowNibble = Copy_u8NibbleNumber % 2 ;
		switch(Local_u8HighorLowNibble)
		{
		case LOW:
			ASSIGN_LOWNIBBLE(PORTO,Copy_NibbleValue);
			break;
		case HIGH:
			ASSIGN_HIGHNIBBLE(PORTO,Copy_NibbleValue);
			break;
		}

	}

	void DIO_vidSetPinValue(u8 Copy_u8PinNumber , u8 Copy_PinValue )
	{
		u8 Local_u8Port , Local_u8Pin ;
		Local_u8Port = Copy_u8PinNumber / PORTPINS_NUMBER;
		Local_u8Pin = Copy_u8PinNumber % PORTPINS_NUMBER ;
		ASSIGN_BIT(PORTO,Local_u8Pin,Copy_PinValue);

	}
	u8 	 DIO_u8GetNibbleValue(u8 Copy_u8NibbleNumber)
	{
		u8 Local_u8Port , Local_u8HighorLowNibble ,Local_NibbleValueOut ;
		Local_u8Port = Copy_u8NibbleNumber / 2;
		Local_u8HighorLowNibble = Copy_u8NibbleNumber % 2 ;
		switch(Local_u8HighorLowNibble)
		{
		case LOW:
			Local_NibbleValueOut = GET_LOWNIBBLE(PINO);
			break;
		case HIGH:
			Local_NibbleValueOut=GET_HIGHNIBBLE(PINO);
			break;
		}
		return Local_NibbleValueOut;
	}


	u8 	 DIO_u8GetPinValue(u8 Copy_u8PinNumber)
	{
		u8 Local_u8Port , Local_u8Pin ;
		Local_u8Port = Copy_u8PinNumber / PORTPINS_NUMBER;
		Local_u8Pin = Copy_u8PinNumber % PORTPINS_NUMBER ;
		u8 Local_PinValueOut;
		Local_PinValueOut=GET_BIT(PINO,Local_u8Pin);
		return Local_PinValueOut;

	}






