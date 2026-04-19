/*
 * exti.h
 *
 *  Created on: May 24, 2025
 *      Author: hp
 */

#ifndef EXTI_H_
#define EXTI_H_

#include "stm32f4xx.h"

void pc13_exti_init(void);
//static void exti_callback(void);


#define LINE13		(1U<<13)  //bit 13 in the pending register




#endif /* EXTI_H_ */
