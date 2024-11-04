/*
 * iocontroller.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Aswanth
 */
#include "stdio.h"
#include "stdint.h"
#include "stm32h7xx_hal.h"
#include "main.h"

#ifndef INC_IOCONTROLLER_H_
#define INC_IOCONTROLLER_H_


const uint8_t IODIRA_REG_A = 0b00000000; //Configure  input/output for port A
const uint8_t IODIRA_REG_B = 0b00010000; //Configure  input/output for port B
const uint8_t GPIO_REG_A   = 0b00001001; //Configure GPIO pin ports A
const uint8_t GPIO_REG_B   = 0b00011001; //Configure GPIO pin ports B
const uint8_t OLATA_REG_A  = 0b00001010; //Configure Logic high/low for ports A
const uint8_t OLATA_REG_B  = 0b00011010; //Configure Logic high/low for ports B

const uint8_t CMD_GPO_IODIRA_REG_A = 0b00000000;//Set every port as Output for port A
const uint8_t CMD_GPO_IODIRA_REG_B = 0b00000000;//Set every port as Output for port A

//SET CMD GPA 0-7 TO HIGH
const uint8_t CMD_GPA0_HIGH = 0b00000001;
const uint8_t CMD_GPA1_HIGH = 0b00000010;
const uint8_t CMD_GPA2_HIGH = 0b00000100;
const uint8_t CMD_GPA3_HIGH = 0b00001000;
const uint8_t CMD_GPA4_HIGH = 0b00010000;
const uint8_t CMD_GPA5_HIGH = 0b00100000;
const uint8_t CMD_GPA6_HIGH = 0b01000000;
const uint8_t CMD_GPA7_HIGH = 0b10000000;

//SET CMD GPB 0-7 TO HIGH
const uint8_t CMD_GPB0_HIGH = 0b00000001;
const uint8_t CMD_GPB1_HIGH = 0b00000010;
const uint8_t CMD_GPB2_HIGH = 0b00000100;
const uint8_t CMD_GPB3_HIGH = 0b00001000;
const uint8_t CMD_GPB4_HIGH = 0b00010000;
const uint8_t CMD_GPB5_HIGH = 0b00100000;
const uint8_t CMD_GPB6_HIGH = 0b01000000;
const uint8_t CMD_GPB7_HIGH = 0b10000000;

//SET CMD GPA 0-7 TO LOW
const int8_t  CMD_GPA0_LOW = ~0b00000001;
const int8_t  CMD_GPA1_LOW = ~0b00000010;
const int8_t  CMD_GPA2_LOW = ~0b00000100;
const int8_t  CMD_GPA3_LOW = ~0b00001000;
const int8_t  CMD_GPA4_LOW = ~0b00010000;
const int8_t  CMD_GPA5_LOW = ~0b00100000;
const int8_t  CMD_GPA6_LOW = ~0b01000000;
const int8_t  CMD_GPA7_LOW = (int8_t)~0b10000000;


//SET CMD GPB 0-7 TO LOW
const int8_t  CMD_GPB0_LOW = ~0b00000001;
const int8_t  CMD_GPB1_LOW = ~0b00000010;
const int8_t  CMD_GPB2_LOW = ~0b00000100;
const int8_t  CMD_GPB3_LOW = ~0b00001000;
const int8_t  CMD_GPB4_LOW = ~0b00010000;
const int8_t  CMD_GPB5_LOW = ~0b00100000;
const int8_t  CMD_GPB6_LOW = ~0b01000000;
const int8_t  CMD_GPB7_LOW = (int8_t)~0b10000000;


//SET OPCODE FOR READ and WRITE

const int8_t OPCODE_WRITE = 0b01000000;
const int8_t OPCODE_READ  = 0b01000001;



uint8_t Transfer_CMD ;
uint8_t TX_Buffer[3];


typedef struct{

//0 logic low 1 logic high
	uint8_t GPA0_LOGIC;
	uint8_t GPA1_LOGIC;
	uint8_t GPA2_LOGIC;
	uint8_t GPA3_LOGIC;
	uint8_t GPA4_LOGIC;
	uint8_t GPA5_LOGIC;
	uint8_t GPA6_LOGIC;
	uint8_t GPA7_LOGIC;

	uint8_t GPB0_LOGIC;
	uint8_t GPB1_LOGIC;
	uint8_t GPB2_LOGIC;
	uint8_t GPB3_LOGIC;
	uint8_t GPB4_LOGIC;
	uint8_t GPB5_LOGIC;
	uint8_t GPB6_LOGIC;
	uint8_t GPB7_LOGIC;


}typdef_GPV_logic;

void GPIO_logic(typdef_GPV_logic *GP_logic);
void MCP23S17_WriteRegister(SPI_HandleTypeDef *hspi, uint8_t reg, uint8_t value);
uint8_t MCP23S17_ReadRegister(SPI_HandleTypeDef *hspi, uint8_t reg);



#endif /* INC_IOCONTROLLER_H_ */
