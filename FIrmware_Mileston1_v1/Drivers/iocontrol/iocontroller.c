

/*
 * iocontroller.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Aswanth
 */


#include "iocontroller.h"


uint8_t Transfer_CMD ;
void GPIO_logic_voltageswitch(typdef_GPV_logic *GP_logic_v){

	//Logic for turning switchs on/off for voltage Side
	if (GP_logic_v->GPA0_LOGIC==1){

		Transfer_CMD |= CMD_GPA0_HIGH;

	}

	else if (GP_logic_v->GPA0_LOGIC==0){

		Transfer_CMD &= CMD_GPA0_LOW;
	}
	else if (GP_logic_v->GPA1_LOGIC==1){

		Transfer_CMD |= CMD_GPA1_HIGH;

	}

	else if (GP_logic_v->GPA1_LOGIC==0){

		Transfer_CMD &= CMD_GPA1_LOW;
	}
	else if (GP_logic_v->GPA2_LOGIC==1){

		Transfer_CMD |= CMD_GPA2_HIGH;

	}

	else if (GP_logic_v->GPA2_LOGIC==0){

		Transfer_CMD &= CMD_GPA2_LOW;
	}
	else if (GP_logic_v->GPA3_LOGIC==1){

		Transfer_CMD |= CMD_GPA3_HIGH;

	}

	else if (GP_logic_v->GPA3_LOGIC==0){

		Transfer_CMD &= CMD_GPA3_LOW;
	}
	else if (GP_logic_v->GPA4_LOGIC==1){

		Transfer_CMD |= CMD_GPA4_HIGH;

	}

	else if (GP_logic_v->GPA4_LOGIC==0){

		Transfer_CMD &= CMD_GPA4_LOW;
	}
	else if (GP_logic_v->GPA5_LOGIC==1){

		Transfer_CMD |= CMD_GPA5_HIGH;

	}

	else if (GP_logic_v->GPA5_LOGIC==0){

		Transfer_CMD &= CMD_GPA5_LOW;
	}
	else if (GP_logic_v->GPA6_LOGIC==1){

		Transfer_CMD |= CMD_GPA6_HIGH;

	}

	else if (GP_logic_v->GPA6_LOGIC==0){

		Transfer_CMD &= CMD_GPA6_LOW;
	}
	else if (GP_logic_v->GPA7_LOGIC==1){

		Transfer_CMD |= CMD_GPA7_HIGH;

	}

	else if (GP_logic_v->GPA7_LOGIC==0){

		Transfer_CMD &= CMD_GPA7_LOW;
	}
	else if (GP_logic_v->GPB0_LOGIC==1){

		Transfer_CMD |= CMD_GPB0_HIGH;

	}

	else if (GP_logic_v->GPB0_LOGIC==0){

		Transfer_CMD &= CMD_GPB0_LOW;
	}
	else if (GP_logic_v->GPB1_LOGIC==1){

		Transfer_CMD |= CMD_GPB1_HIGH;

	}

	else if (GP_logic_v->GPB1_LOGIC==0){

		Transfer_CMD &= CMD_GPB1_LOW;
	}
	else if (GP_logic_v->GPB2_LOGIC==1){

		Transfer_CMD |= CMD_GPB2_HIGH;

	}

	else if (GP_logic_v->GPB2_LOGIC==0){

		Transfer_CMD &= CMD_GPB2_LOW;
	}
	else if (GP_logic_v->GPB3_LOGIC==1){

		Transfer_CMD |= CMD_GPB3_HIGH;

	}

	else if (GP_logic_v->GPB3_LOGIC==0){

		Transfer_CMD &= CMD_GPB3_LOW;
	}
	else if (GP_logic_v->GPB4_LOGIC==1){

		Transfer_CMD |= CMD_GPB4_HIGH;

	}

	else if (GP_logic_v->GPB4_LOGIC==0){

		Transfer_CMD &= CMD_GPB4_LOW;
	}
	else if (GP_logic_v->GPB5_LOGIC==1){

		Transfer_CMD |= CMD_GPB5_HIGH;

	}

	else if (GP_logic_v->GPB5_LOGIC==0){

		Transfer_CMD &= CMD_GPB5_LOW;
	}
	else if (GP_logic_v->GPB6_LOGIC==1){

		Transfer_CMD |= CMD_GPB6_HIGH;

	}

	else if (GP_logic_v->GPB6_LOGIC==0){

		Transfer_CMD &= CMD_GPB6_LOW;
	}
	else if (GP_logic_v->GPB7_LOGIC==1){

		Transfer_CMD |= CMD_GPB7_HIGH;

	}

	else if (GP_logic_v->GPB7_LOGIC==0){

		Transfer_CMD &= CMD_GPB7_LOW;
	}



}
void GPIO_logic_currentswitch(typdef_GPV_logic *GP_logic_i){

	//Logic for turning switchs on/off for Current Side


	if (GP_logic_i->GPA0_LOGIC==1){

		Transfer_CMD |= CMD_GPA0_HIGH;

	}

	else if (GP_logic_i->GPA0_LOGIC==0){

		Transfer_CMD &= CMD_GPA0_LOW;
	}
	else if (GP_logic_i->GPA1_LOGIC==1){

		Transfer_CMD |= CMD_GPA1_HIGH;

	}

	else if (GP_logic_i->GPA1_LOGIC==0){

		Transfer_CMD &= CMD_GPA1_LOW;
	}
	else if (GP_logic_i->GPA2_LOGIC==1){

		Transfer_CMD |= CMD_GPA2_HIGH;

	}

	else if (GP_logic_i->GPA2_LOGIC==0){

		Transfer_CMD &= CMD_GPA2_LOW;
	}
	else if (GP_logic_i->GPA3_LOGIC==1){

		Transfer_CMD |= CMD_GPA3_HIGH;

	}

	else if (GP_logic_i->GPA3_LOGIC==0){

		Transfer_CMD &= CMD_GPA3_LOW;
	}
	else if (GP_logic_i->GPA4_LOGIC==1){

		Transfer_CMD |= CMD_GPA4_HIGH;

	}

	else if (GP_logic_i->GPA4_LOGIC==0){

		Transfer_CMD &= CMD_GPA4_LOW;
	}
	else if (GP_logic_i->GPA5_LOGIC==1){

		Transfer_CMD |= CMD_GPA5_HIGH;

	}

	else if (GP_logic_i->GPA5_LOGIC==0){

		Transfer_CMD &= CMD_GPA5_LOW;
	}
	else if (GP_logic_i->GPA6_LOGIC==1){

		Transfer_CMD |= CMD_GPA6_HIGH;

	}

	else if (GP_logic_i->GPA6_LOGIC==0){

		Transfer_CMD &= CMD_GPA6_LOW;
	}
	else if (GP_logic_i->GPA7_LOGIC==1){

		Transfer_CMD |= CMD_GPA7_HIGH;

	}

	else if (GP_logic_i->GPA7_LOGIC==0){

		Transfer_CMD &= CMD_GPA7_LOW;
	}
	else if (GP_logic_i->GPB0_LOGIC==1){

		Transfer_CMD |= CMD_GPB0_HIGH;

	}

	else if (GP_logic_i->GPB0_LOGIC==0){

		Transfer_CMD &= CMD_GPB0_LOW;
	}
	else if (GP_logic_i->GPB1_LOGIC==1){

		Transfer_CMD |= CMD_GPB1_HIGH;

	}

	else if (GP_logic_i->GPB1_LOGIC==0){

		Transfer_CMD &= CMD_GPB1_LOW;
	}
	else if (GP_logic_i->GPB2_LOGIC==1){

		Transfer_CMD |= CMD_GPB2_HIGH;

	}

	else if (GP_logic_i->GPB2_LOGIC==0){

		Transfer_CMD &= CMD_GPB2_LOW;
	}
	else if (GP_logic_i->GPB3_LOGIC==1){

		Transfer_CMD |= CMD_GPB3_HIGH;

	}

	else if (GP_logic_i->GPB3_LOGIC==0){

		Transfer_CMD &= CMD_GPB3_LOW;
	}
	else if (GP_logic_i->GPB4_LOGIC==1){

		Transfer_CMD |= CMD_GPB4_HIGH;

	}

	else if (GP_logic_i->GPB4_LOGIC==0){

		Transfer_CMD &= CMD_GPB4_LOW;
	}
	else if (GP_logic_i->GPB5_LOGIC==1){

		Transfer_CMD |= CMD_GPB5_HIGH;

	}

	else if (GP_logic_i->GPB5_LOGIC==0){

		Transfer_CMD &= CMD_GPB5_LOW;
	}
	else if (GP_logic_i->GPB6_LOGIC==1){

		Transfer_CMD |= CMD_GPB6_HIGH;

	}

	else if (GP_logic_i->GPB6_LOGIC==0){

		Transfer_CMD &= CMD_GPB6_LOW;
	}
	else if (GP_logic_i->GPB7_LOGIC==1){

		Transfer_CMD |= CMD_GPB7_HIGH;

	}

	else if (GP_logic_i->GPB7_LOGIC==0){

		Transfer_CMD &= CMD_GPB7_LOW;
	}

}

void MCP23S17_WriteRegister_voltage(SPI_HandleTypeDef *hspi, uint8_t reg, uint8_t value) {
    uint8_t TX_Buffer[3] = {OPCODE_WRITE, reg, value};
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_0, GPIO_PIN_RESET); // Pull CS low for selecting voltage side
    HAL_SPI_Transmit(hspi, TX_Buffer, 3, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_0, GPIO_PIN_SET);   // Pull CS high for selecting voltage  side
}
void MCP23S17_WriteRegister_current(SPI_HandleTypeDef *hspi, uint8_t reg, uint8_t value) {
    uint8_t TX_Buffer[3] = {OPCODE_WRITE, reg, value};
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_RESET); // Pull CS low for selecting current side
    HAL_SPI_Transmit(hspi, TX_Buffer, 3, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_SET);   // Pull CS high for selecting current side
}

void Init_GPIOs_OUTPUT(void){

	MCP23S17_WriteRegister_voltage(&hspi1, IODIRA_REG_A, CMD_GPO_IODIRA_REG_A);//setting gpios as output for channel A
	MCP23S17_WriteRegister_voltage(&hspi1, IODIRA_REG_B, CMD_GPO_IODIRA_REG_B);//setting gpios as output for channel B
	MCP23S17_WriteRegister_current(&hspi1, IODIRA_REG_A, CMD_GPO_IODIRA_REG_A);//setting gpios as output for channel A
	MCP23S17_WriteRegister_current(&hspi1, IODIRA_REG_B, CMD_GPO_IODIRA_REG_B);//setting gpios as output for channel B

}

void updateSwitch(void){//run this in a loop

	MCP23S17_WriteRegister_voltage(&hspi1, OLATA_REG_A, Transfer_CMD);//setting gpios as output for channel A
	MCP23S17_WriteRegister_voltage(&hspi1, OLATA_REG_B, Transfer_CMD);//setting gpios as output for channel B

	MCP23S17_WriteRegister_current(&hspi1, OLATA_REG_A, Transfer_CMD);//setting gpios as output for channel A
	MCP23S17_WriteRegister_current(&hspi1, OLATA_REG_B, Transfer_CMD);//setting gpios as output for channel B
}
