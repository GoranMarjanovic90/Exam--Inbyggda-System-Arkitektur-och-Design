#ifndef LED_H
#define LED_H // The start of the header

#include <stdint.h> // gives us exact width integer types regardless of underlying hardware (int8_t, uint8_t, int16_t, uint16_t, int32_t, uint32_t, int64_t, uint64_t)
#include "UART.h" // including my uart header
#include "stm32f4xx.h" // device header stm32 for f4xx

//defininig which GPIO should be responsible for the LED function
#define	LED_PORT GPIOB

#define	LED_PORT_CLOCK (1U<<1)

//defining the pins for the LED colors
#define LED_RED_PIN	(1U<<14)
#define LED_GREEN_PIN (1U<<12)
#define	LED_BLUE_PIN (1U<<15)
#define LED_YELLOW_PIN (1U<<13)

//defining mode bits for each LED color
#define LED_RED_MODE_BIT (1U<<28)
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_YELLOW_MODE_BIT (1U<<26)
#define LED_BLUE_MODE_BIT (1U<<30)

//defining colors
typedef  enum {
	RED	= 0,
	GREEN,
	YELLOW,
	BLUE
}LedColor_Type;

//defininig the different states the LED can be in
typedef enum {
	OFF =0,
	ON = 1
}LedState_Type;

//Defines the attributes that LED consist of
typedef struct {
	LedColor_Type color; 
	LedState_Type state;  
}Led_Type;

// Declaring the LED construction and status checking functions
void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state);
void Led_setState(Led_Type * const me,LedState_Type _state);
LedState_Type Led_getState(Led_Type * const me);

#endif // the end of the LED header file