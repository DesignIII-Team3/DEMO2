/*
 * speed_control_loop.c
 *
 *  Created on: Feb 21, 2023
 *      Author: ousmane
 */

#include "speed_control_loop.h"
#include "macros_utiles.h"

void configureTIM6(){

	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
	TIM6->PSC = 0;
	TIM6->ARR = 1340 - 1;
	TIM6->CR1 |= TIM_CR1_URS;
	TIM6->DIER |= TIM_DIER_UIE;
	TIM6->EGR |= TIM_EGR_UG;//re-initializes the counter and generates an update for the registers
	NVIC->ISER[1] |= BIT22;
	TIM6->CR1 |= TIM_CR1_CEN;

}
