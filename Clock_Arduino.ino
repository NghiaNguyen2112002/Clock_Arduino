#include <Wire.h>

#include "pin.h"
#include "ds130x.h"
#include "led_4digit.h"

#define SERIAL_DEBUG_BAUD       9600

#define EXCECUTING_CYCLE        5        //5ms

unsigned long time_cur = 0; 
uint8_t time_read_ds = 500;              //read ds1307 every 500ms 
uint8_t counter_time_elapsed = 0;


uint8_t index_led = 0;

uint8_t hour, min, second;

void DecodeStr2Time(String str){
// Format:     "HOUR:MIN"
//              "13:30"
  uint8_t index_dot = str.indexOf(':', 0);   //find index of ':'
  uint8_t hour, min;

  hour = atoi((str.substring(0, index_dot)).c_str());
  min = atoi((str.substring(index_dot+1, str.length())).c_str());

  DS_Write(ADDRESS_HOUR, hour);
  DS_Write(ADDRESS_MINUTE, min);

  Serial.print("SET TIME: "); Serial.print(hour); Serial.print(':'); Serial.println(min);
}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(SERIAL_DEBUG_BAUD);

  Wire.begin();

  DS_Init();
  LED7_Init();
 
}

void loop() {
  // put your main code here, to run repeatedly:

  // program code is executed every 50ms
  if(millis() >= time_cur + EXCECUTING_CYCLE){
    time_cur = millis();


    counter_time_elapsed = (counter_time_elapsed + 1) % 200;
    if(time_read_ds >= 5) time_read_ds -= 5;


    if(time_read_ds < 5){
      time_read_ds = 500;
      hour = DS_Read(ADDRESS_HOUR);
      min = DS_Read(ADDRESS_MINUTE);
      second = DS_Read(ADDRESS_SECOND);

      Serial.print(hour); Serial.print(':'); Serial.print(min); Serial.print(':'); Serial.println(second);
    }

    if(Serial.available()){
      DecodeStr2Time(Serial.readString());
    }

    if(counter_time_elapsed % 400 < 200){
      LED7_UpdateDotBuffer(1, 1);
    }
    else LED7_UpdateDotBuffer(1, 0);

    LED7_UpdateNumBuffer(hour, min);

    LED7_Display(  (index_led++) % 4  );

  }
}
