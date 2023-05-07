#include "UART.h" // including the header file for functions and the source code to the stm32f4xx

// declaring a driver function
void USART2_Init(void){ 
    // configure the system clock (RCC) for the microcontroller.

    // 1. enable clock for uart2
    RCC->APB1ENR  |=  0x20000; // activate UART2

    // 2. Enable clock for port A
    RCC->AHB1ENR   |=0x01; // activate GPIO

    // 3. enabling pins
    GPIOA->MODER &=~0x00F0; // clearing bits 4-7 to prepare pins PA2 and PA3.
    GPIOA->MODER |= 0x00A0; // putting bits 5 and 7 to 1 

    GPIOA->AFR[0] &= ~0xFF00; // clearing bits 8-15 to prepare pins PA2 and PA3.
    GPIOA->AFR[0] |= 0x7700; // puting bits 8-11 and 12-14 to the format 0111
    /*Construction of the device communication ends*/

    // configuring UART
    USART2->BRR  =  0x0683; // initializing baud rate to 9600bps
    USART2->CR1  =  0x000C; // putting tx och rx to work in 8 bits data. (8 bits data, 1 stop bit, no parity)
    USART2->CR2  =  0x000; // zeroing the CR2
    USART2->CR3  =  0x000; // zeroing the CR3
    USART2->CR1  |=  0x2000; // reputing bit 13 to 1
}
    // UART Write
int USART2_write(int ch){ // Declaring the write function

    //a loop for sending byte by byte
	while(!(USART2->SR & 0x0080)){}
	USART2->DR = (ch & 0xFF);
	
  return ch;
}
    //Uart read
int USART2_read(void){ // Declaring the read function
  while(!(USART2->SR & 0x0020)){} 
	return USART2->DR;
}
// Interface for standard I/0
struct __FILE { int handle; };
FILE __stdin  = {0};
FILE __stdout = {1};
FILE __stderr = {2};


int fgetc(FILE *f) { // gets a byte from the standard stream and also processes character returns
    int c;

    c = USART2_read();     

    if (c == '\r') {        
        USART2_write(c);    
        c = '\n';
    }

    USART2_write(c);       

    return c;
}

int fputc(int c, FILE *f) { // writes a byte to the standard stream
    return USART2_write(c);
}


int n; // declaring a variable
char str[80]; // putting a max limit of characters which is 80 in this case
		
void test_setup(void){ 

    printf("Test");
}
