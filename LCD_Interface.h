/*
 * LCD_Interface.h
 *
 *  Created on: Apr 7, 2018
 *      Author: Youssef
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_WriteCommand(u8 );
void LCD_Init(void);
void LCD_WriteData(u8 Copy_u8Data);
void LCD_WriteString(u8 []);
/*Data Sheet Configuration for LCD*/
#define LCD_CLEAR                  0x01
#define LCD_FIRST_ROW              0x80
#define LCD_SECOND_ROW             0xC0
#define LCD_HIDE_CURSOR            0x0C
#define LCD_SHIFT_RIGHT            0x1C
#define LCD_SHIFT_LEFT             0x18
#define LCD_DISP_OFF_CURSOR_OFF    0x08
#define LCD_DISP_ON_CURSOR_BLINK   0x0E
#define CURSOR_BLINK               0x0F
#define CURSOR_SHIFT_RIGHT         0x14
#define CURSOR_SHIFT_LEFT          0x10


#endif /* LCD_INTERFACE_H_ */
