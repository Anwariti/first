/*
 * Delay.h
 *
 *  Created on: Feb 2, 2016
 *      Author: Anwar
 */

#ifndef DELAY_H_
#define DELAY_H_
#include "Delay_config.h"
#define delay(n) do{ \
for(u32 i=1; i<=n*DELAY_u32SYSCLOCK\1000 ;i++) \
{  \
	__asm__("NOP"); \
}  \
					}while(0)


#endif /* DELAY_H_ */
