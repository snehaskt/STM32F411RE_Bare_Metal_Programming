/*
 * systick.c
 *
 *  Created on: Mar 8, 2025
 *      Author: hp
 */


#include <stdint.h>
#include "stm32f4xx.h"
#include "systick.h"



#define SYSTICK_LOAD_VAL			16000
#define CTRL_ENABLE					(1U<<0)
#define CTRL_CLKSRC					(1U<<2)
#define CTRL_COUNTFLAG				(1U<<16)
#define ONE_SEC_LOAD				16000000
#define CTRL_TICKINT				(1U<<1)


void systickDelayMs(int delay)
{
	/*Reload with number of clock per millisecond*/
	SysTick->LOAD = SYSTICK_LOAD_VAL;


	/*clear the  systick current value register*/
	SysTick->VAL = 0;

	/* Enable systick and select internal clk src*/
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;

	for(int i=0; i<delay; i++)
	{
		/*waite until the count flag is set*/
		while((	SysTick->CTRL & CTRL_COUNTFLAG) == 0 ) {}
	}

	SysTick->CTRL = 0;

}


void systick_1hz_interrupt(void)
{
	/*Reload with number of clock per second*/
	// 16 MHZ meaning
		SysTick->LOAD = ONE_SEC_LOAD - 1;


		/*clear the  systick current value register*/
		SysTick->VAL = 0;

		/* Enable systick and select internal clk src*/
		SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;

		/*Enable systick interrupt*/
		SysTick->CTRL |= CTRL_TICKINT;


}


