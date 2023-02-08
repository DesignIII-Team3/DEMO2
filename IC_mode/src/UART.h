/*
 * UART.h
 *
 *  Created on: 27 nov. 2022
 *      Author: chtho
 */

#ifndef UART_MODULE_UART_H_
#define UART_MODULE_UART_H_

#include "stm32f4xx.h"

#define TAILLE_DU_BUFFER_RX 20

char UART_CB_RX[TAILLE_DU_BUFFER_RX];
volatile uint8_t RX_TeteLecture;
volatile uint8_t RX_TeteEcriture;

void configureUART(void);
void sendByteUART(uint8_t p_byte);
void sendStringUART(const char *p_string);
void UART4_IRQHandler(void);

#endif /* UART_MODULE_UART_H_ */
