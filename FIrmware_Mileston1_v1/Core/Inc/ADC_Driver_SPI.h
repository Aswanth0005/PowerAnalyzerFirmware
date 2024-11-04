/*
 * ADC_Driver_SPI.h
 *
 *  Created on: Jul 29, 2024
 *      Author: Aswanth
 */

#ifndef INC_ADC_DRIVER_SPI_H_
#define INC_ADC_DRIVER_SPI_H_
#include "stdint.h"
#include "stm32h7xx_hal.h"




#define DEVICE_ID_REG 0x00 //Device ID register
#define RST_PWRCTL_REG 0x04//Reset and power control register
#define SDI_CTL_REG 0x08//SDI data input control register
#define SDO_CTL_REG 0x0C//SDO-x data input control register
#define DATAOUT_CTL_REG 0x10//Output data control register
#define RANGE_SEL_REG 0x14//Input range selection control register
#define ALARM_REG 0x20//ALARM output register
#define ALARM_H_TH_REG 0x24//ALARM high threshold and hysteresis register
#define ALARM_L_TH_REG 0x28//ALARM low threshold register

//9_bit address



#define CLEAR_HWORD 0b11000
#define READ_HWORD  0b11001
#define READ        0b01001
#define WRITE       0b11010
#define SET_HWORD   0b11011

uint8_t SPI_ADC_Driver_Read(uint8_t Command ,uint16_t Address,uint32_t ReadData );
uint8_t SPI_ADC_Driver_Write(uint8_t Command ,uint16_t Address,uint16_t WriteData );
void SPI_ADC_Driver_Init(void);


void SPI_Protocol_Init(void);
extern SPI_HandleTypeDef hspi1;

#endif /* INC_ADC_DRIVER_SPI_H_ */
