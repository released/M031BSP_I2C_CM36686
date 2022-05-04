
#include <stdio.h>
#include "CM36686.h"

#include "i2c_driver.h"
#include <math.h>
#include "project_config.h"


void CM36686_Delay(unsigned int nCount)
{
    /* Decrement nCount value */
    while (nCount != 0)
    {
        nCount--;
    }
}

void CM36686_WriteReg(unsigned char RegAddr, unsigned char* txData , unsigned char length)
{
	i2c_reg_write(CM36686_DEVADDR_7BIT ,RegAddr ,txData ,length);
}

int CM36686_ReadReg(unsigned char RegAddr , unsigned char* rxData , unsigned char length)
{
	i2c_reg_read(CM36686_DEVADDR_7BIT ,RegAddr ,rxData ,length);	
	return 0;
}

unsigned int CM36686_ReadPS(void)	// HEART RATE
{
	unsigned char rxData[2] = {0,0};

	CM36686_ReadReg(PS_DATA,rxData,2);
	CM36686_Delay(5);

	return (unsigned int)( (rxData[1] << 8) | rxData[0]);
}		

unsigned int CM36686_ReadALS(void)
{
	unsigned char rxData[2] = {0,0};

	CM36686_ReadReg(ALS_DATA,rxData,2);
	CM36686_Delay(5);

	return (unsigned int)( (rxData[1] << 8) | rxData[0]);
}		

void CM36686_Init(void)
{
	unsigned char wData[2] = {0,0};

	CM36686_Delay(0xFFF);

	wData[0]= (unsigned char)(0x0101 << 8);//MSB
	wData[1]= (unsigned char)(0x0101 & 0x00FF);//LSB
	CM36686_WriteReg(0x0C,wData,2);
	CM36686_Delay(5);

	wData[0]= (unsigned char)( 0x0101 << 8);//MSB
	wData[1]= (unsigned char)( 0x0101 & 0x00FF);//LSB	
	CM36686_WriteReg(0x0C,wData,2);
	CM36686_Delay(5);

	wData[0]= (unsigned char)( 0x0000 << 8);//MSB
	wData[1]= (unsigned char)( 0x0000 & 0x00FF);//LSB	
	CM36686_WriteReg(0x00,wData,2);
	CM36686_Delay(5);
	
	wData[0]= (unsigned char)( 0x0000 << 8);//MSB
	wData[1]= (unsigned char)( 0x0000 & 0x00FF);//LSB	
	CM36686_WriteReg(0x00,wData,2);
	CM36686_Delay(5);
	
	wData[0]= (unsigned char)( 0x0000 << 8);//MSB
	wData[1]= (unsigned char)( 0x0000 & 0x00FF);//LSB	
	CM36686_WriteReg(0x00,wData,2);;
	CM36686_Delay(5);
	
	wData[0]= (unsigned char)( 0x0000 << 8);//MSB
	wData[1]= (unsigned char)( 0x0000 & 0x00FF);//LSB	
	CM36686_WriteReg(0x00,wData,2);
	CM36686_Delay(5);
	
	wData[0]= (unsigned char)( 0x0000 << 8);//MSB
	wData[1]= (unsigned char)( 0x0000 & 0x00FF);//LSB	
	CM36686_WriteReg(0x00,wData,2);
	CM36686_Delay(5);
	
	wData[0]= (unsigned char)( 0x0000 << 8);//MSB
	wData[1]= (unsigned char)( 0x0000 & 0x00FF);//LSB	
	CM36686_WriteReg(0x03,wData,2);
	CM36686_Delay(5);
	
	wData[0]= (unsigned char)( 0x0000 << 8);//MSB
	wData[1]= (unsigned char)( 0x0000 & 0x00FF);//LSB	
	CM36686_WriteReg(0x03,wData,2);
	CM36686_Delay(5);
	
	wData[0]= (unsigned char)( 0x0000 << 8);//MSB
	wData[1]= (unsigned char)( 0x0000 & 0x00FF);//LSB	
	CM36686_WriteReg(0x03,wData,2);
	CM36686_Delay(5);

	wData[0]= (unsigned char)( 0x0800 << 8);//MSB
	wData[1]= (unsigned char)( 0x0800 & 0x00FF);//LSB	
	CM36686_WriteReg(0x03,wData,2);
	CM36686_Delay(5);

	wData[0]= (unsigned char)( 0x0000 << 8);//MSB
	wData[1]= (unsigned char)( 0x0000 & 0x00FF);//LSB	
	CM36686_WriteReg(0x04,wData,2);
	CM36686_Delay(5);

	wData[0]= (unsigned char)( 0x0000 << 8);//MSB
	wData[1]= (unsigned char)( 0x0000 & 0x00FF);//LSB	
	CM36686_WriteReg(0x04,wData,2);
	CM36686_Delay(5);
	
	wData[0]= (unsigned char)( 0x0000 << 8);//MSB
	wData[1]= (unsigned char)( 0x0000 & 0x00FF);//LSB	
	CM36686_WriteReg(0x04,wData,2);
	CM36686_Delay(5);
	
	wData[0]= (unsigned char)( 0x0000 << 8);//MSB
	wData[1]= (unsigned char)( 0x0000 & 0x00FF);//LSB	
	CM36686_WriteReg(0x04,wData,2);
	CM36686_Delay(5);
	
	wData[0]= (unsigned char)( 0x0000 << 8);//MSB
	wData[1]= (unsigned char)( 0x0000 & 0x00FF);//LSB	
	CM36686_WriteReg(0x04,wData,2);
	CM36686_Delay(5);
	
	wData[0]= (unsigned char)( 0x0000 << 8);//MSB
	wData[1]= (unsigned char)( 0x0000 & 0x00FF);//LSB	
	CM36686_WriteReg(0x04,wData,2);
	CM36686_Delay(5);
	
	wData[0]= (unsigned char)( 0x0000 << 8);//MSB
	wData[1]= (unsigned char)( 0x0000 & 0x00FF);//LSB	
	CM36686_WriteReg(0x04,wData,2);
	CM36686_Delay(5);

	wData[0]= (unsigned char)( 0x0002 << 8);//MSB
	wData[1]= (unsigned char)( 0x0002 & 0x00FF);//LSB	
	CM36686_WriteReg(0x03,wData,2);	
	CM36686_Delay(5);

	wData[0]= (unsigned char)( 0x0500 << 8);//MSB
	wData[1]= (unsigned char)( 0x0500 & 0x00FF);//LSB	
	CM36686_WriteReg(0x04,wData,2);
	CM36686_Delay(5);	

}

