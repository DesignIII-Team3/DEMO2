/*
 * wheels_control.h
 *
 *  Created on: Feb 21, 2023
 *      Author: ousmane
 */

#ifndef WHEELS_CONTROL_H_
#define WHEELS_CONTROL_H_
#include "stm32f4xx.h"

void configureWheelsDirection(void);
void M1ClockWise(void);
void M1CounterClockWise(void);
void M1Brake();
void M2ClockWise(void);
void M2CounterClockWise(void);
void M2Brake();
void M3ClockWise(void);
void M3CounterClockWise(void);
void M3Brake();
void M4ClockWise(void);
void M4CounterClockWise(void);
void M4Brake();


#endif /* WHEELS_CONTROL_H_ */
