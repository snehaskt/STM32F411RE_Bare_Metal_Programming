/*
 * tim.c
 *
 *  Created on: Apr 5, 2025
 *      Author: hp
 */


#include "stm32f4xx.h"
#include <stdint.h>



#define TIM2EN				(1U<<0)
#define TIM3EN				(1U<<1)
#define CR1_CEN				(1U<<0)
#define OC_TOGGLE           (1U<<4) | (1U<<5)
#define CCER_CC1E			(1U<<0)


#define GPIOAEN				(1U<<0)
#define AFR5_TIM			(1U<<20)
#define AFR6_TIM			(1U<<25)
#define CCER_CC1S			(1U<<0)

void tim2_1hz_init(void)
{
	/*Enable clock access to tim2*/
	RCC-> APB1ENR |= TIM2EN;

	/*Set prescaler value*/
	TIM2 -> PSC = 1600-1;  //16000000/1600 = 10000

	/*clear counter*/
	TIM2 -> ARR = 10000-1;
	//10000/10000 = 1

	/*Enable timer*/
	TIM2 -> CR1 = CR1_CEN;

}


void tim2_PA5output_compare(void)
{
	/*Enable clock access to tim2*/
	RCC -> AHB1ENR |= GPIOAEN;

	/*Set PA5 as alternate function mode*/
	GPIOA -> MODER &= ~(1<<10);
	GPIOA -> MODER |= (1<<11);

	/*set PA5 alternate function type to TIM2_CH1 (AF01)*/
	GPIOA -> AFR[0] |= AFR5_TIM;

	/*Enable clock access to TIM2*/
	RCC -> APB1ENR |= TIM2EN;

	/*Set pre-scaler value*/
	TIM2 -> PSC = 1600-1;

	/*Set auto-relode value*/
	TIM2 -> ARR = 10000-1;

	/*Set output compare toggle mode*/
	TIM2 -> CCMR1 = OC_TOGGLE;

	/*Enable tim2 ch1 in compare mode*/
	TIM2 -> CCER |= CCER_CC1E;

	/*Clear counter*/
	TIM2 -> CNT = 0;

	/*Enable timer*/
	TIM2 -> CR1 = CR1_CEN;

}




void tim3_input_capture(void)
{
	/*Enable clock access to tim3*/
	RCC -> AHB1ENR |= GPIOAEN;

	/*Set PA6 as alternate function mode*/
	GPIOA -> MODER &= ~(1<<12);
	GPIOA -> MODER |= (1<<13);

	/*set PA6 alternate function type to TIM3_CH1 (AF02)*/
	GPIOA -> AFR[0] |= AFR6_TIM;

	/*Enable clock access to TIM2*/
	RCC -> APB1ENR |= TIM3EN;

	/*Set prescaler value*/
	TIM3 -> PSC = 1600-1;

	/*Set CH1 to input capture mode*/
	TIM3 -> CCMR1 = CCER_CC1S;

	/*Set CH1 to capture at raising edge*/
	TIM3 -> CCER = CCER_CC1E;


	/*Set auto-relode value*/
	TIM3 -> ARR = 10000-1;

	/*Clear counter*/
	TIM3 -> CNT = 0;

	/*Enable timer*/
	TIM3 -> CR1 = CR1_CEN;

}


