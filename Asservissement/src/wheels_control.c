/*
 * wheels_control.c
 *
 *  Created on: Feb 21, 2023
 *      Author: ousmane
 */

#include "wheels_control.h"
#include "macros_utiles.h"

void configureWheelsDirection(void){
	RCC->AHB1ENR |= BIT3;
	GPIOD->MODER |= (BIT16 | BIT18 | BIT20 | BIT22 | BIT24 | BIT26 | BIT28 | BIT30);
	GPIOD->MODER &= ~(BIT17 | BIT19 | BIT21 | BIT23 | BIT25 | BIT27 | BIT29 | BIT31);
}
void M1ClockWise(void){
	GPIOD->ODR &= ~(BIT8);
	GPIOD->ODR |= (BIT9);
}
void M1CounterClockWise(void){
	GPIOD->ODR |= (BIT8);
	GPIOD->ODR &= ~(BIT9);
}
void M1Brake(){
	GPIOD->ODR &= ~(BIT8);
	GPIOD->ODR &= ~(BIT9);
}
void M2ClockWise(void){
	GPIOD->ODR &= ~(BIT10);
	GPIOD->ODR |= (BIT11);
}
void M2CounterClockWise(void){
	GPIOD->ODR |= (BIT10);
	GPIOD->ODR &= ~(BIT11);
}
void M2Brake(){
	GPIOD->ODR &= ~(BIT10);
	GPIOD->ODR &= ~(BIT11);
}
void M3ClockWise(void){
	GPIOD->ODR &= ~(BIT12);
	GPIOD->ODR |= (BIT13);
}
void M3CounterClockWise(void){
	GPIOD->ODR |= (BIT12);
	GPIOD->ODR &= ~(BIT13);
}
void M3Brake(){
	GPIOD->ODR &= ~(BIT12);
	GPIOD->ODR &= ~(BIT13);
}
void M4ClockWise(void){
	GPIOD->ODR &= ~(BIT14);
	GPIOD->ODR |= (BIT15);
}
void M4CounterClockWise(void){
	GPIOD->ODR |= (BIT14);
	GPIOD->ODR &= ~(BIT15);
}
void M4Brake(){
	GPIOD->ODR &= ~(BIT14);
	GPIOD->ODR &= ~(BIT15);
}
