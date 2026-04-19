/*
 * exti.c
 *
 *  Created on: May 24, 2025
 *      Author: hp
 */
#include "stm32f4xx.h"
#include "exti.h"
#define GPIOCEN			(1U<<2)
#define SYSCFGEN 		(1U<<14)

void pc13_exti_init(void)
{
	/*Disable global interrupt*/
	__disable_irq();
	/*Enable clock access for GPIO*/
	RCC->AHB1ENR |= GPIOCEN;

	/*Set pc13 to INPUT mode */
	GPIOC-> MODER &=~ (1U<<26);
	GPIOC-> MODER &=~ (1U<<27);

	/*Enable clock access for SYSCFG exti is a part of SYSCFG module so enable clock access to it*/
	RCC->APB2ENR |= SYSCFGEN;
	/*Select PORTC for EXTI13*/
	SYSCFG->EXTICR[3] |= (1U<<5);
	/*Unmask EXTI13*/
	EXTI->IMR |= (1U<<13);
	/*Select faling edge trigger*/
	EXTI->FTSR |=(1U<<13);
	/*Enable EXTI13 line in NVIC (the nested controller vector table the NVIC)*/
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	/*Enable global interrupt*/
	__enable_irq();


}
