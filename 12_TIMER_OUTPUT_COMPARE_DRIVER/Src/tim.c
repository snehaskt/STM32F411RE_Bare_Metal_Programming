/*
 * tim.c
 *
 *  Created on: Apr 5, 2025
 *      Author: hp
 */


#include "stm32f4xx.h"
#include <stdint.h>


#define TIM2EN				(1U<<0)
#define CR1_CEN				(1U<<0)


void tim2_1hz_init(void)
{
	/*Enable clock access to tim2*/
	RCC-> APB1ENR |= TIM2EN;

	/*Set pre-scaler value*/
	TIM2 -> PSC = 1600-1;
	//16000000/1600 = 10000

	/*clear counter*/
	TIM2 -> ARR = 10000-1;
	//10000/10000 = 1

	/*Enable timer*/
	TIM2 -> CR1 = CR1_CEN;

}

