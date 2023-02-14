/*
******************************************************************************
File:     main.c
Info:     Generated by Atollic TrueSTUDIO(R) 9.3.0   2023-02-13

******************************************************************************
*/

/* Includes */
#include "stm32f4xx.h"

#define TIM3CLOCK 26880000
#define TIM3PRESCALAR 26

#define TIM5CLOCK 26880000
#define TIM5PRESCALAR 1

#define ARRAY_SIZE 500

void TIM3_CH1_IC_Init(void);
void TIM5_CH1_IC_Init(void);
void configureGPIOA6(void);
void configureGPIOA0(void);

int main(void)
{
	TIM3_CH1_IC_Init();
	TIM5_CH1_IC_Init();
	configureGPIOA6();
	configureGPIOA0();

  while (1);

}

void TIM3_CH1_IC_Init(void)
{
	// Enable clock for TIM3
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	// Configure TIM3_CH1 in input capture mode
	TIM3->CCMR1 &= ~TIM_CCMR1_CC1S;
	TIM3->CCMR1 |= TIM_CCMR1_CC1S_0;
	TIM3->CCER &= ~TIM_CCER_CC1P;
	TIM3->CCER |= TIM_CCER_CC1E;
	TIM3->CCMR1 &= ~TIM_CCMR1_IC1F;

	TIM3->PSC = 26 - 1;
	TIM3->DIER |= (TIM_DIER_CC1IE);


	// Enable TIM3 global interrupt
	NVIC_EnableIRQ(TIM3_IRQn);

	// Start TIM3
	TIM3->CR1 |= TIM_CR1_CEN;
}


void TIM5_CH1_IC_Init(void)
{
	// Enable clock for TIM5
	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;

	// Configure TIM5_CH1 in input capture mode
	TIM5->CCMR1 &= ~TIM_CCMR1_CC1S;
	TIM5->CCMR1 |= TIM_CCMR1_CC1S_0;
	TIM5->CCER &= ~TIM_CCER_CC1P;
	TIM5->CCER |= TIM_CCER_CC1E;
	TIM5->CCMR1 &= ~TIM_CCMR1_IC1F;

	TIM5->PSC = 0;
	TIM5->DIER |= (TIM_DIER_CC1IE);


	// Enable TIM5 global interrupt
	NVIC_EnableIRQ(TIM5_IRQn);

	// Start TIM5
	TIM5->CR1 |= TIM_CR1_CEN;
}


void configureGPIOA6(void)
{
	// Enable clock for GPIOA
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	// Configure PA6 as alternate function
	GPIOA->MODER &= ~GPIO_MODER_MODER6;
	GPIOA->MODER |= GPIO_MODER_MODER6_1;
	GPIOA->AFR[0] |= 0x2 << 24;
}

void configureGPIOA0(void)
{
	// Enable clock for GPIOA
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	// Configure PA0 as alternate function
	GPIOA->MODER &= ~GPIO_MODER_MODER0;
	GPIOA->MODER |= GPIO_MODER_MODER0_1;
	GPIOA->AFR[0] |= 0x2 << 0;
}

uint32_t IC_Val1 = 0;
uint32_t IC_Val2 = 0;
uint32_t Difference = 0;
int Is_First_Captured = 0;
float frequency = 0;
int i = 0 ;
float buffer[ARRAY_SIZE];

void TIM3_IRQHandler(void)
{
	if (TIM3->SR & TIM_SR_CC1IF)
	{

		if(Is_First_Captured == 0){
			IC_Val1 = TIM3->CCR1;
			Is_First_Captured = 1;
		}
		else{
			IC_Val2 = TIM3->CCR1;
			if(IC_Val2 > IC_Val1){
				Difference = IC_Val2 -IC_Val1;
			}
			else if(IC_Val1 > IC_Val2){
				Difference = (0xFFFF - IC_Val1) + IC_Val2;

			}
			float refClock = TIM3CLOCK /(TIM3PRESCALAR);
			frequency = refClock/Difference;
			buffer[i++] = frequency;
			while(i > ARRAY_SIZE);
			TIM3->SR &= ~TIM_SR_CC1IF;
			Is_First_Captured = 0;
		}
	}
}

uint32_t TIM5IC_Val1 = 0;
uint32_t TIM5IC_Val2 = 0;
uint32_t TIM5Difference = 0;

int TIM5Is_First_Captured = 0;
float TIM5frequency = 0;
int TIM5i = 0 ;
float TIM5buffer[ARRAY_SIZE];
void TIM5_IRQHandler(void)
{
	if (TIM5->SR & TIM_SR_CC1IF)
	{

		if(TIM5Is_First_Captured == 0){
			TIM5IC_Val1 = TIM5->CCR1;
			TIM5Is_First_Captured = 1;
		}
		else{
			TIM5IC_Val2 = TIM5->CCR1;
			if(TIM5IC_Val2 > TIM5IC_Val1){
				TIM5Difference = TIM5IC_Val2 - TIM5IC_Val1;
			}
			else if(TIM5IC_Val1 > TIM5IC_Val2){
				TIM5Difference = (0xFFFFFFFF - TIM5IC_Val1) + TIM5IC_Val2;

			}
			float TIM5refClock = TIM5CLOCK /(TIM5PRESCALAR);
			TIM5frequency = TIM5refClock/TIM5Difference;
			TIM5buffer[TIM5i++] = TIM5frequency;
			while(TIM5i > ARRAY_SIZE);
			TIM5->SR &= ~TIM_SR_CC1IF;
			TIM5Is_First_Captured = 0;
		}
	}
}
