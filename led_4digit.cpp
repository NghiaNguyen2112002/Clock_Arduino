#include "Arduino.h"
#include "led_4digit.h"

uint8_t led7_numbuffer[4] = {0, 0, 0, 0};
uint8_t led7_dotbuffer[4] = {0, 0, 0, 0};       //0: no dot,  1: dot is on

void EnableLed(uint8_t index){
  switch(index){
    case 0:
      digitalWrite(PIN_LED_EN_1, HIGH);
      digitalWrite(PIN_LED_EN_2, LOW);
      digitalWrite(PIN_LED_EN_3, LOW);
      digitalWrite(PIN_LED_EN_4, LOW);
    break;
    case 1:
      digitalWrite(PIN_LED_EN_1, LOW);
      digitalWrite(PIN_LED_EN_2, HIGH);
      digitalWrite(PIN_LED_EN_3, LOW);
      digitalWrite(PIN_LED_EN_4, LOW);
    break;
    case 2:
      digitalWrite(PIN_LED_EN_1, LOW);
      digitalWrite(PIN_LED_EN_2, LOW);
      digitalWrite(PIN_LED_EN_3, HIGH);
      digitalWrite(PIN_LED_EN_4, LOW);
    break;
    case 3:
      digitalWrite(PIN_LED_EN_1, LOW);
      digitalWrite(PIN_LED_EN_2, LOW);
      digitalWrite(PIN_LED_EN_3, LOW);
      digitalWrite(PIN_LED_EN_4, HIGH);
    break;
  }
}

void Display(uint8_t num, uint8_t is_dot){
  switch(num){
    case 0:
      digitalWrite(PIN_LED_A, LOW);
      digitalWrite(PIN_LED_B, LOW);
      digitalWrite(PIN_LED_C, LOW);
      digitalWrite(PIN_LED_D, LOW);
      digitalWrite(PIN_LED_E, LOW);
      digitalWrite(PIN_LED_F, LOW);
      digitalWrite(PIN_LED_G, HIGH);
    break;
    case 1:
      digitalWrite(PIN_LED_A, HIGH);
      digitalWrite(PIN_LED_B, LOW);
      digitalWrite(PIN_LED_C, LOW);
      digitalWrite(PIN_LED_D, HIGH);
      digitalWrite(PIN_LED_E, HIGH);
      digitalWrite(PIN_LED_F, HIGH);
      digitalWrite(PIN_LED_G, HIGH);
    break;
    case 2:
      digitalWrite(PIN_LED_A, LOW);
      digitalWrite(PIN_LED_B, LOW);
      digitalWrite(PIN_LED_C, HIGH);
      digitalWrite(PIN_LED_D, LOW);
      digitalWrite(PIN_LED_E, LOW);
      digitalWrite(PIN_LED_F, HIGH);
      digitalWrite(PIN_LED_G, LOW);
    break; 
    case 3:
      digitalWrite(PIN_LED_A, LOW);
      digitalWrite(PIN_LED_B, LOW);
      digitalWrite(PIN_LED_C, LOW);
      digitalWrite(PIN_LED_D, LOW);
      digitalWrite(PIN_LED_E, HIGH);
      digitalWrite(PIN_LED_F, HIGH);
      digitalWrite(PIN_LED_G, LOW);
    break; 
    case 4:
      digitalWrite(PIN_LED_A, HIGH);
      digitalWrite(PIN_LED_B, LOW);
      digitalWrite(PIN_LED_C, LOW);
      digitalWrite(PIN_LED_D, HIGH);
      digitalWrite(PIN_LED_E, HIGH);
      digitalWrite(PIN_LED_F, LOW);
      digitalWrite(PIN_LED_G, LOW);
    break; 
    case 5:
      digitalWrite(PIN_LED_A, LOW);
      digitalWrite(PIN_LED_B, HIGH);
      digitalWrite(PIN_LED_C, LOW);
      digitalWrite(PIN_LED_D, LOW);
      digitalWrite(PIN_LED_E, HIGH);
      digitalWrite(PIN_LED_F, LOW);
      digitalWrite(PIN_LED_G, LOW);
    break; 
    case 6:
      digitalWrite(PIN_LED_A, LOW);
      digitalWrite(PIN_LED_B, HIGH);
      digitalWrite(PIN_LED_C, LOW);
      digitalWrite(PIN_LED_D, LOW);
      digitalWrite(PIN_LED_E, LOW);
      digitalWrite(PIN_LED_F, LOW);
      digitalWrite(PIN_LED_G, LOW);
    break; 
    case 7:
      digitalWrite(PIN_LED_A, LOW);
      digitalWrite(PIN_LED_B, LOW);
      digitalWrite(PIN_LED_C, LOW);
      digitalWrite(PIN_LED_D, HIGH);
      digitalWrite(PIN_LED_E, HIGH);
      digitalWrite(PIN_LED_F, HIGH);
      digitalWrite(PIN_LED_G, HIGH);
    break; 
    case 8:
      digitalWrite(PIN_LED_A, LOW);
      digitalWrite(PIN_LED_B, LOW);
      digitalWrite(PIN_LED_C, LOW);
      digitalWrite(PIN_LED_D, LOW);
      digitalWrite(PIN_LED_E, LOW);
      digitalWrite(PIN_LED_F, LOW);
      digitalWrite(PIN_LED_G, LOW);
    break; 
    case 9:
      digitalWrite(PIN_LED_A, LOW);
      digitalWrite(PIN_LED_B, LOW);
      digitalWrite(PIN_LED_C, LOW);
      digitalWrite(PIN_LED_D, LOW);
      digitalWrite(PIN_LED_E, HIGH);
      digitalWrite(PIN_LED_F, LOW);
      digitalWrite(PIN_LED_G, LOW);
    break; 
  }

  if(is_dot > 0){
    digitalWrite(PIN_LED_DP, LOW);
  }
  else {
    digitalWrite(PIN_LED_DP, HIGH);
  }
}


//===================HIGH LEVEL FUNCTION===================//
void LED7_Init(void){
  pinMode(PIN_LED_EN_1, OUTPUT);
  pinMode(PIN_LED_EN_2, OUTPUT);
  pinMode(PIN_LED_EN_3, OUTPUT);
  pinMode(PIN_LED_EN_4, OUTPUT);

  pinMode(PIN_LED_A, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  pinMode(PIN_LED_C, OUTPUT);
  pinMode(PIN_LED_D, OUTPUT);
  pinMode(PIN_LED_E, OUTPUT);
  pinMode(PIN_LED_F, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_DP, OUTPUT);

}

void LED7_UpdateDotBuffer(uint8_t index_led, uint8_t dot_on){
  led7_dotbuffer[index_led] = dot_on;
}

void LED7_UpdateNumBuffer(uint8_t num1, uint8_t num2){
  led7_numbuffer[0] = num1 / 10;
  led7_numbuffer[1] = num1 % 10;
  led7_numbuffer[2] = num2 / 10;
  led7_numbuffer[3] = num2 % 10;
}

void LED7_Display(uint8_t index_led){
  EnableLed(index_led);
  Display(led7_numbuffer[index_led], led7_dotbuffer[index_led]);
}