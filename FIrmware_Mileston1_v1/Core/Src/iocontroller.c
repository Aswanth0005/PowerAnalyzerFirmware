

/*
 * iocontroller.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Aswanth
 */


#include "iocontroller.h"


//
void GPIO_logic(typdef_GPV_logic *GP_logic){

	if (GP_logic->GPA0_LOGIC==1){

		Transfer_CMD |= CMD_GPA0_HIGH;

	}

	else if (GP_logic->GPA0_LOGIC==0){

		Transfer_CMD &= CMD_GPA0_LOW;
	}
	else if (GP_logic->GPA1_LOGIC==1){

		Transfer_CMD |= CMD_GPA1_HIGH;

	}

	else if (GP_logic->GPA1_LOGIC==0){

		Transfer_CMD &= CMD_GPA1_LOW;
	}
	else if (GP_logic->GPA2_LOGIC==1){

		Transfer_CMD |= CMD_GPA2_HIGH;

	}

	else if (GP_logic->GPA2_LOGIC==0){

		Transfer_CMD &= CMD_GPA2_LOW;
	}
	else if (GP_logic->GPA3_LOGIC==1){

		Transfer_CMD |= CMD_GPA3_HIGH;

	}

	else if (GP_logic->GPA3_LOGIC==0){

		Transfer_CMD &= CMD_GPA3_LOW;
	}
	else if (GP_logic->GPA4_LOGIC==1){

		Transfer_CMD |= CMD_GPA4_HIGH;

	}

	else if (GP_logic->GPA4_LOGIC==0){

		Transfer_CMD &= CMD_GPA4_LOW;
	}
	else if (GP_logic->GPA5_LOGIC==1){

		Transfer_CMD |= CMD_GPA5_HIGH;

	}

	else if (GP_logic->GPA5_LOGIC==0){

		Transfer_CMD &= CMD_GPA5_LOW;
	}
	else if (GP_logic->GPA6_LOGIC==1){

		Transfer_CMD |= CMD_GPA6_HIGH;

	}

	else if (GP_logic->GPA6_LOGIC==0){

		Transfer_CMD &= CMD_GPA6_LOW;
	}
	else if (GP_logic->GPA7_LOGIC==1){

		Transfer_CMD |= CMD_GPA7_HIGH;

	}

	else if (GP_logic->GPA7_LOGIC==0){

		Transfer_CMD &= CMD_GPA7_LOW;
	}


}


void MCP23S17_WriteRegister(SPI_HandleTypeDef *hspi, uint8_t reg, uint8_t value) {
    uint8_t TX_Buffer[3] = {OPCODE_WRITE, reg, value};
    HAL_GPIO_WritePin(swvcs_GPIO_Port, swvcs_Pin, GPIO_PIN_RESET); // Pull CS low
    HAL_SPI_Transmit(hspi, TX_Buffer, 3, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(swvcs_GPIO_Port, swvcs_Pin, GPIO_PIN_SET);   // Pull CS high
}

