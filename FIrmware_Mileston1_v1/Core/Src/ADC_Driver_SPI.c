/*
 * ADC_Driver_SPI.c
 *
 *  Created on: Jul 29, 2024
 *      Author: Aswanth
 */
#include "ADC_Driver_SPI.h"


uint8_t SPI_ADC_Driver_Read(uint8_t Command ,uint16_t Address,uint32_t ReadData )

{
    uint32_t Message = 0;
    Message = (Command & 0x1F) << 11 | // Command needs only 5 bit but occupy 16bits so we need to shift to 11
              (Address & 0x01FF) << 0  | // 9-bit address (no shift needed)
              (0x0000);          // 16-bit data (no shift needed)

    // Convert Message to an array of bytes for SPI transfer
    uint8_t txData[4];
    uint8_t Rx_Buff[4];
    txData[0] = (Message >> 24) & 0xFF; // MSB
    txData[1] = (Message >> 16) & 0xFF;
    txData[2] = (Message >> 8) & 0xFF;
    txData[3] = Message & 0xFF;


    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);//Making CONVST/CS to High
	uint8_t status =(HAL_SPI_TransmitReceive(&hspi1, txData, Rx_Buff, 2, HAL_MAX_DELAY)==HAL_OK);//Transmitting Data and receiving to SPI interface
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);//Making CONVST/CS to LOW
	ReadData=Rx_Buff[4];//Reading Result
	return status;//if transmit complete = 1 else 0

}
uint8_t SPI_ADC_Driver_Write(uint8_t Command ,uint16_t Address,uint16_t WriteData )

{
    uint32_t Message = 0;
    Message = (Command & 0x1F) << 11 | // Command needs only 5 bit but occupy 16bits so we need to shift to 11
              (Address & 0x01FF) << 0  | // 9-bit address (no shift needed)
              (WriteData & 0xFFFF);          // 16-bit data (no shift needed)

    // Convert Message to an array of bytes for SPI transfer
    uint8_t txData[4];
    txData[0] = (Message >> 24) & 0xFF; // MSB
    txData[1] = (Message >> 16) & 0xFF;
    txData[2] = (Message >> 8) & 0xFF;
    txData[3] = Message & 0xFF;


    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);//Making CONVST/CS to High
	uint8_t status =(HAL_SPI_Transmit(&hspi1, txData, 2, HAL_MAX_DELAY)==HAL_OK);//Transmitting Data to SPI interface
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);//Making CONVST/CS to LOW
	return status;//if transmit complete = 1 else 0

}

void SPI_ADC_Driver_Init(void)
{
	SPI_ADC_Driver_Write(WRITE, RST_PWRCTL_REG, 0x0000);//active mode , full device initialization
	SPI_ADC_Driver_Write(WRITE, SDI_CTL_REG, 0x0000);//spi cpol=0  & cphase = 0
	SPI_ADC_Driver_Write(WRITE, SDO_CTL_REG, 0x8000);//sdo 1bit mode 2nd sdo in tri state
	SPI_ADC_Driver_Write(WRITE, RANGE_SEL_REG, 0x0400);//range 10.24

}


