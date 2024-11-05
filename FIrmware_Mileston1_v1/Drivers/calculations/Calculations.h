/*
 * Calculations.h
 *
 *  Created on: Aug 26, 2024
 *      Author: Aswanth
 */

#ifndef CALCULATIONS_CALCULATIONS_H_
#define CALCULATIONS_CALCULATIONS_H_

#include "stm32h7xx_hal.h"

#include "stdint.h"
#define ARM_MATH_CM7
#include "arm_math.h"
#define BufferSize 4096/*Buffer Size of the SPI Array*/

static volatile uint8_t *ptrInputBuffer;/*Pointer to the buffer*/

uint8_t SPI_RxArray[BufferSize];/*Initialize array to receive Data*/

uint8_t DataReadyFlag = 0;/*Initialize flag to when data is ready for process*/

uint8_t EnergyFlag =0;/*Flag to check energy Calculation*/

uint8_t FFTEnableFlag=0;/*Flag to Enable fft*/

uint8_t VoltageFFtFlag=0;/*Flag to Swap fft for Voltage*/

uint8_t CurrentFFtFlag=0;/*Flag to Swap fft for Current*/

uint8_t Counter;/*For Counting*/

uint8_t CrestFactorFlag;/*Flag to enable crest factor calculation*/

float dt = 1/3600;/*dt for energy Calculation*/

float32_t FFTOutBufferVoltage[BufferSize/2];/*FFT output DataBuffer*/

float32_t FFTOutBufferCurrent[BufferSize/2];/*FFT output DataBuffer*/

float32_t AbsFFTOutBufferVoltage[BufferSize/2];/*FFT output DataBuffer*/

float32_t AbsFFTOutBufferCurrent[BufferSize/2];/*FFT output DataBuffer*/

float32_t FFTInBufferVoltage[BufferSize/2];/*FFT Input DataBuffer*/

float32_t FFTInBufferCurrent[BufferSize/2];/*FFT Input DataBuffer*/

typedef struct variables


{
	float ADC_I_Value;

	float ADC_V_Value;

	uint16_t PowerArray[BufferSize/2];

	volatile uint16_t *ptr_V_inst;

	volatile uint16_t *ptr_I_inst;

	float32_t V_inst[BufferSize/2];

	float32_t I_inst[BufferSize/2];

	float32_t V_rms[BufferSize/2];

	float32_t I_rms[BufferSize/2];

	float32_t PeakVoltage;

	uint32_t PeakVoltageIndex;

	float32_t PeakCurrent;

	uint32_t PeakCurrentIndex;

	float Voltage;

	float Current;

	float RealPower;

	float Sum_Power;

	float32_t PowerFactor;

	float32_t ReactivePower;

	float32_t ptrReactivePower;

	float32_t ReactivePowerDiff;

	volatile float energy;


	float vcrestfactor;

	float icreastfactor;


	float ApparentPower;

	float VoltageHarmonics;

	float CurrentHarmonics;

	float PowerHarmonics;

	float FFTvoltage;

	float FFTcurrent;

	float FFTpower;


}Variabletypedef;

void HAL_SPI_RxHalfCpltCallback(SPI_HandleTypeDef *hspi);

void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi);

void DataProcessing(Variabletypedef *Variable);

void FFtFunctions();

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* CALCULATIONS_CALCULATIONS_H_ */
