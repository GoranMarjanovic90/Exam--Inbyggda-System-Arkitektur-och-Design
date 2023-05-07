// this file connects my .c files
#ifndef  __UART_H
#define  __UART_H // the start of my header file

#include "stm32f4xx.h" // gets the source code and references for working on STM hardware.
#include <stdio.h> //  iclude standard I/O
void USART2_Init(void); // calling the UART-function
void test_setup(void); //calling the test function which is in UART.c

#endif // finishing inclusion