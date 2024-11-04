
#include "iocontroller.h"

//test two




///*
// * iocontroller.c
// *
// *  Created on: Oct 29, 2024
// *      Author: Aswanth
// */
//
//
//// Define MCP23S17 addresses
//#define MCP23S17_WRITE_CMD 0x40  // MCP23S17 opcode for write
//#define MCP23S17_READ_CMD  0x41  // MCP23S17 opcode for read
//#define MCP23S17_GPIOB_REG 0x13  // Address of GPIOB register
//#define MCP23S17_IODIRB    0x01  // I/O direction register for GPIOB
//
//// Function prototypes
//void MCP23S17_WriteRegister(SPI_HandleTypeDef *hspi, uint8_t reg, uint8_t value);
//uint8_t MCP23S17_ReadRegister(SPI_HandleTypeDef *hspi, uint8_t reg);
//
//void MCP23S17_Init(SPI_HandleTypeDef *hspi) {
//    // Set GPIOB pins as output (0 = output)
//    MCP23S17_WriteRegister(hspi, MCP23S17_IODIRB, 0x00);
//}
//
//void MCP23S17_TogglePins(SPI_HandleTypeDef *hspi) {
//    uint8_t gpioState = MCP23S17_ReadRegister(hspi, MCP23S17_GPIOB_REG);
//    gpioState ^= 0x03; // Toggle GPB0 and GPB1
//    MCP23S17_WriteRegister(hspi, MCP23S17_GPIOB_REG, gpioState);
//}
//
//void MCP23S17_WriteRegister(SPI_HandleTypeDef *hspi, uint8_t reg, uint8_t value) {
//    uint8_t txData[3] = {MCP23S17_WRITE_CMD, reg, value};
//    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET); // Pull CS low
//    HAL_SPI_Transmit(hspi, txData, 3, HAL_MAX_DELAY);
//    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);   // Pull CS high
//}
//
//uint8_t MCP23S17_ReadRegister(SPI_HandleTypeDef *hspi, uint8_t reg) {
//    uint8_t txData[2] = {MCP23S17_READ_CMD, reg};
//    uint8_t rxData = 0;
//    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET); // Pull CS low
//    HAL_SPI_Transmit(hspi, txData, 2, HAL_MAX_DELAY);
//    HAL_SPI_Receive(hspi, &rxData, 1, HAL_MAX_DELAY);
//    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);   // Pull CS high
//    return rxData;
//}
