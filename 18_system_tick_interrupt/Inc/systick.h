/*
 * systick.h
 *
 *  Created on: Mar 8, 2025
 *      Author: hp
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

//#include <stdio.h>
#include <stdint.h>


void systickDelayMs(int delay);
void systick_1hz_interrupt(void);



#endif /* SYSTICK_H_ */
