#ifndef INC_DS130X_H_
#define INC_DS130X_H_

#include <Wire.h>

#define ADDRESS_DS1307       	  0x68		//ds1307

#define ADDRESS_SECOND          0x00
#define ADDRESS_MINUTE          0x01
#define ADDRESS_HOUR            0x02
#define ADDRESS_WEEK_DAY        0x03
#define ADDRESS_DATE            0x04
#define ADDRESS_MONTH           0x05
#define ADDRESS_YEAR            0x06


void DS_Init(void);
void DS_Write(uint8_t address, uint8_t data);
uint8_t DS_Read(uint8_t address);


#endif /* INC_DS130X_H_ */
