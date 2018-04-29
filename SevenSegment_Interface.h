/*
 * 7Segment_Interface.h
 *
 *  Created on: Apr 18, 2018
 *      Author: Youssef
 */

#ifndef SEGMENT_INTERFACE_H_
#define SEGMENT_INTERFACE_H_

void SevenSegment_vidWrite(u8 Copy_u8Decimal,u32 Copy_u8TimeToDisplay);
void SevenSegment_vidCountUp(u8 Copy_u8CountFrom,u8 Copy_u8CountTo,u8 Copy_u8CountingStep);
void SevenSegment_vidCountDown(u8 Copy_u8CountFrom,u8 Copy_u8CountTo,u8 Copy_u8CountingStep);


#endif /* 7SEGMENT_INTERFACE_H_ */
