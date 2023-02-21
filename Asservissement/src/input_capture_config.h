/*
 * input_capture_config.h
 *
 *  Created on: Feb 21, 2023
 *      Author: ousmane
 */

#ifndef INPUT_CAPTURE_CONFIG_H_
#define INPUT_CAPTURE_CONFIG_H_

#include "stm32f4xx.h"

void TIM5_CH1_IC_Init();
void configureGPIOA0();

void TIM5_CH2_IC_Init();
void configureGPIOA1();

void TIM5_CH3_IC_Init();
void configureGPIOA2();

void TIM5_CH4_IC_Init();
void configureGPIOA3();


#endif /* INPUT_CAPTURE_CONFIG_H_ */
