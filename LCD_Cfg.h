/*
 * LCD_Cfg.h
 *
 *  Created on: Apr 7, 2018
 *      Author: Youssef
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define LCD_RS PIN9
#define LCD_RW PIN10
#define LCD_E PIN11

/*Write a NibbleNumber 0-7 (nibble0-1 are on portA .. etc )
			   DATA pins have to be on the same nibble of PORT*/
//#define LCD_DATA NIBBLE1
#define LCD_D4 (u8)PIN4
#define LCD_D5 (u8)PIN5
#define LCD_D6 (u8)PIN6
#define LCD_D7 (u8)PIN7



#endif /* LCD_CFG_H_ */
