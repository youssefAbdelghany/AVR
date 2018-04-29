/*
 * DIO_Interface.h
 *
 *  Created on: Apr 13, 2018
 *      Author: Youssef
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

 enum STATE { LOW ,HIGH } ;
 enum DIRECTION {OUTPUT , INPUT_PULLUP , INPUT_HIGHIMPEDANCE }  ;
 enum PORT {PORT_A , PORT_B , PORT_C , PORT_D }  ;
 enum PIN {PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,PIN8,PIN9
	,PIN10,PIN11,PIN12,PIN13,PIN14,PIN15,PIN16,PIN17,PIN18,PIN19,PIN20,
	PIN21,PIN22,PIN23,PIN24,PIN25,PIN26,PIN27,PIN28,PIN29,PIN30,PIN31} ;
	 enum nibble {NIBBLE0 ,NIBBLE1,NIBBLE2,NIBBLE3,NIBBLE4,NIBBLE5,NIBBLE6,NIBBLE7} ;


void	 DIO_vidSetPinDirection(u8 Copy_u8PinNumber , u8 Copy_u8Direction);
void	 DIO_vidSetPinValue(u8 Copy_u8PinNumber , u8 Copy_PinValue );
u8 	 DIO_u8GetPinValue(u8 Copy_u8PinNumber);
void 	 DIO_vidSetPortDirection(u8 Copy_u8PortNumber,u8 Copy_u8Direction);
void 	 DIO_vidSetNibbleDirection(u8 Copy_u8NibbleNumber , u8 Copy_u8Direction);
void 	 DIO_vidSetNibbleValue(u8 Copy_u8NibbleNumber , u8 Copy_NibbleValue );
u8 	 DIO_u8GetNibbleValue(u8 Copy_u8NibbleNumber);






#endif /* DIO_INTERFACE_H_ */
