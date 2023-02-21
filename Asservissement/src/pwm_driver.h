/*
 * pwm_driver.h
 *
 *  Created on: Feb 21, 2023
 *      Author: ousmane
 */

#ifndef PWM_DRIVER_H_
#define PWM_DRIVER_H_

#include "stm32f4xx.h"

void TIM4_CH1_PWM_Init();
void configureGPIOB6();

void TIM4_CH2_PWM_Init();
void configureGPIOB7();

void TIM4_CH3_PWM_Init();
void configureGPIOB8();

void TIM4_CH4_PWM_Init();
void configureGPIOB9();


#endif /* PWM_DRIVER_H_ */
