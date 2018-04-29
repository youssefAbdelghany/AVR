/*
 * Keypad_Interface.h
 *
 *  Created on: Apr 14, 2018
 *      Author: Youssef
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_
typedef enum KEYPAD_STATE { PRESSED ,NOTPRESSED } KEYPAD_STATE;
typedef enum SW_KP {SWITCH0=48 , SWITCH1, SWITCH2, SWITCH3,SWITCH4,
	SWITCH5,SWITCH6,SWITCH7,SWITCH8,SWITCH9,SWITCHA='A',SWITCHB,
	SWITCHC,SWITCHD,SWITCH_ASTRIK='*',SWITCH_SH='#'} SWITCH_KEYPAD ;
u8 Keypad_u8GetKey(u8* Copy_u8KeyValue);
void Keypad_vidKeypadInit(void);



#endif /* KEYPAD_INTERFACE_H_ */
