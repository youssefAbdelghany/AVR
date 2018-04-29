/*
 * Delay.c
 *
 *  Created on: Dec 17, 2016
 *      Author: Mahmoud Khaled
 */

#include"DIO_Cfg.h"
#include"Std_Types.h"
#include"Utils.h"


extern void DELAY_ms (u32 time)
{
  volatile u32 i ;
  volatile  u32 count;
 // count = ((time*1000)-36)/10.8;
  /*  count = ((time*1000)-19)/10.7;*/
   count = ((time*1000))/12;
	for (i=0;i<count;i++)
	{
		asm("nop");
	}

/*  for (i=0;i<(time*1000);i++)
  	{
  		asm("nop");
  	}
		u32 i , count ;
		count=(u32)(((1000.0*time)-0.51273)/2.679309);
		for (i=0;i<count;i++)
		{
			asm("nop");
		}
*/

}

