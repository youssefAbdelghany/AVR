/*
 * External_Cpg.h
 *
 *  Created on: Apr 14, 2018
 *      Author: Youssef
 */

#ifndef EXTERNAL_CPG_H_
#define EXTERNAL_CPG_H_
#define ENABLE 1
#define DISABLE 0
/*Registers for setting External Interrupt,Addresses from datasheet */
#define SREG *( (volatile u8*) (0x5F))
#define MCUCR *( (volatile u8*) (0x55))
#define GICR *( (volatile u8*) (0x5B))
void Ext_vidInit(void);
#define EXT0 ENABLE
#define EXT1 DISABLE
#define EXT2 DISABLE

#endif /* EXTERNAL_CPG_H_ */
