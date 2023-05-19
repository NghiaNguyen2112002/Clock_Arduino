#include "ds130x.h"

uint8_t BCD2DEC(uint8_t bcd){
	uint8_t low, high;
	low = bcd & 0x0F;
	high = (bcd >> 4) * 10;

	return (low + high);
}

uint8_t DEC2BCD(uint8_t dec){
	uint8_t low, high;
	low = dec % 10;
	high = (dec / 10) << 4;

	return (low + high);
}

//===================HIGH LEVEL FUNCTION===================//
void DS_Init(void){
  // Wire.begin();
}


void DS_Write(uint8_t address, uint8_t data){
	uint8_t byte[2] = { address, DEC2BCD(data) };

  Wire.beginTransmission(ADDRESS_DS1307);
  Wire.write(byte, 2);
  Wire.endTransmission();

}

uint8_t DS_Read(uint8_t address){
	uint8_t value = 0;

  Wire.beginTransmission(ADDRESS_DS1307); 
  Wire.write(address);
  Wire.endTransmission();

  Wire.requestFrom(ADDRESS_DS1307, 1);
  
  value = Wire.read();

	return BCD2DEC(value);
}



