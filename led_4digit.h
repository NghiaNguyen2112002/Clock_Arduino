#ifndef __LED_4DIGIT_H__
#define __LED_4DIGIT_H__

#include "pin.h"

void LED7_Init(void);

void LED7_UpdateDotBuffer(uint8_t index_led, uint8_t dot_on);
void LED7_UpdateNumBuffer(uint8_t num1, uint8_t num2);

void LED7_Display(uint8_t index_led);

#endif