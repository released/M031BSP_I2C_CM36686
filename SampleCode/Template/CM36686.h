

#ifndef CM36686_H_
#define CM36686_H_

#include <stdio.h>

typedef enum _CM36686_I2C_MESSAGE{
	CM36686_i2c_success = 0,
	CM36686_i2c_error,
}CM36686_I2C_MESSAGE;

#define CM36686_DEVADDR_7BIT					(0x60)		// 7 bit
#define CM36686_DEVADDR_8BIT					(CM36686_DEVADDR_7BIT << 1)

//CM36686 register addresses
#define ALS_CONF								0x00
#define ALS_THDH								0x01
#define ALS_THDL								0x02
#define PS_CONF1_2								0x03
#define PS_CONF3								0x04
#define PS_CANC									0x05
#define PS1_THDL								0x06
#define PS2_THDH								0x07
#define PS_DATA									0x08	//read
#define ALS_DATA								0x09	//read
#define White_DATA								0x0A
#define INT_Flag								0x0B
#define CM36686_ID								0x0C

void CM36686_WriteReg(unsigned char RegAddr, unsigned char* txData , unsigned char length);
int CM36686_ReadReg(unsigned char RegAddr , unsigned char* rxData , unsigned char length);

unsigned int CM36686_ReadALS(void);
unsigned int CM36686_ReadPS(void);

void CM36686_Init(void);

#endif /* CM36686_H_ */

