/*
 * UART.c
 *
 *  Created on: 27 nov. 2022
 *      Author: chtho
 /
  *
  */

#include "macros_utiles.h"
#include "UART.h"


void configureUART(){

    //PA.0  USART_TX
    //PA.1 USART_RX

    RCC->AHB1ENR |= BIT0; //Horloge port A
    GPIOA->MODER |= BIT3 | BIT1;
    GPIOA->AFR[0] |= BIT3 | BIT7;  //AF8 alternate functions for PA.0 and PA.1

    //Rx pin is in push-pull
    GPIOA->OTYPER &= ~(BIT1| BIT0);

    //Pull-up the pin
    GPIOA->PUPDR &= ~(BIT3 | BIT1 );
    GPIOA->PUPDR |= (BIT2 | BIT0 );

    RCC->APB1ENR |= BIT19;

    UART4->CR1 &= ~BIT12; //1 start bit and 8 data bits;

    UART4->CR1 |= BIT10; //Parity control enabled

    UART4->CR1 &= ~BIT9; //Even parity

    UART4->CR1 |= BIT5; //An USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register


    UART4->CR1 |=  BIT2 | BIT3;

    //19200 = (53760000/4)/(8(2-0)USART_DIV)
    //115200 = (53760000/4)/(8(2-0)USART_DIV)
    //USART_DIV = 43.75
    UART4->BRR = (unsigned int)(43.75f*16);
    UART4->CR1 |= BIT13;

    //End setup the UART**/

    //UART4_IRQn  = 52
    NVIC->ISER[1] |= BIT20;
}


void sendByteUART(uint8_t p_byte)
{
    while(!(UART4->SR & BIT6));
    UART4->DR = p_byte;
}


void sendStringUART(const char *p_string){

    volatile int i = 0;
    do{
        sendByteUART(p_string[i]);
    }while(p_string[i++] != '\0');

}


void UART4_IRQHandler(void)
{
    if(UART4->SR & USART_SR_RXNE)
    {
    	char ByteRecu;
        ByteRecu = UART4->DR;
        UART_CB_RX[RX_TeteEcriture] = ByteRecu;
        RX_TeteEcriture++;
        if(RX_TeteEcriture >= TAILLE_DU_BUFFER_RX){
        	RX_TeteEcriture = 0;
        }
        if(GPIOD->ODR & BIT14){
        	GPIOD->ODR &= ~BIT14;
        }
        if(!(GPIOD->ODR & BIT14)){
        	GPIOD->ODR |= BIT14;
        }

    }
}
