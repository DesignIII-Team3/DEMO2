/*
 * pwm_driver.c
 *
 *  Created on: Feb 21, 2023
 *      Author: ousmane
 */
#include "pwm_driver.h"
#include "macros_utiles.h"

void TIM4_CH1_PWM_Init(){

	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	TIM4->PSC = 268 - 1;
	TIM4->ARR = 100 -1;
	TIM4->CCMR1 &= ~TIM_CCMR1_OC1M;
	TIM4->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1;
	TIM4->CCMR1 |= TIM_CCMR1_OC1PE;
	TIM4->CCER |= TIM_CCER_CC1E;
}

void configureGPIOB6(){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	GPIOB->MODER &= ~GPIO_MODER_MODER6;
	GPIOB->MODER |= (GPIO_MODER_MODER6_1);
	GPIOB->AFR[0] |= (2 << 24);
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_6;
}

void TIM4_CH2_PWM_Init(){
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	TIM4->PSC = 268 - 1;
	TIM4->ARR = 100 - 1;
	TIM4->CCMR1 &= ~TIM_CCMR1_OC2M;
	TIM4->CCMR1 |= (TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1);
	TIM4->CCMR1 |= TIM_CCMR1_OC2PE;
	TIM4->CCER |= TIM_CCER_CC2E;
}

void configureGPIOB7(){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	GPIOB->MODER &= ~GPIO_MODER_MODER7;
	GPIOB->MODER |= (GPIO_MODER_MODER7_1);
	GPIOB->AFR[0] |= (2 << 28);
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_7;
}

void TIM4_CH3_PWM_Init(){
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	TIM4->PSC = 268 - 1;
	TIM4->ARR = 100 -1;
	TIM4->CCMR2 &= ~TIM_CCMR2_OC3M;
	TIM4->CCMR2 |= (TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1);
	TIM4->CCMR2 |= TIM_CCMR2_OC3PE;
	TIM4->CCER |= TIM_CCER_CC3E;
}

void configureGPIOB8(){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	GPIOB->MODER &= ~GPIO_MODER_MODER8;
	GPIOB->MODER |= (GPIO_MODER_MODER8_1);
	GPIOB->AFR[1] |= (2 << 0);
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_8;
}

void TIM4_CH4_PWM_Init(){
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	TIM4->PSC = 268 - 1;
	TIM4->ARR = 100 - 1;
	TIM4->CCMR2 &= ~TIM_CCMR2_OC4M;
	TIM4->CCMR2 |= (TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1);
	TIM4->CCMR2 |= TIM_CCMR2_OC4PE;
	TIM4->CCER |= TIM_CCER_CC4E;
}

void configureGPIOB9(){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	GPIOB->MODER &= ~GPIO_MODER_MODER9;
	GPIOB->MODER |= (GPIO_MODER_MODER9_1);
	GPIOB->AFR[1] |= (2 << 4);
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_9;
}

