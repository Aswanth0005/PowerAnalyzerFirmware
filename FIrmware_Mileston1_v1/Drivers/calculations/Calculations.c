/*
 * Calculations.c
 *
 *  Created on: Aug 26, 2024
 *      Author: Aswanth
 */

#include "Calculations.h"

extern TIM_HandleTypeDef htim1;

Variabletypedef Variable;

arm_rfft_fast_instance_f32 fftHandler;

void HAL_SPI_RxHalfCpltCallback(SPI_HandleTypeDef *hspi)

/*This Function is an interrupt function which occurs when the array is half filled*/
{

	ptrInputBuffer =& SPI_RxArray[0];

	/*Initialize data pointer to half of the array*/

	DataReadyFlag = 1;

	/*If the DataReadyFlag is set we can do the processing*/


}


void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)

/*This Function is an interrupt function which occurs when  the array is completely filled*/

{
	ptrInputBuffer =& SPI_RxArray[BufferSize/2];

	/*Initialize data pointer to Second half of the array*/

	DataReadyFlag=1;

	/*If the DataReadyFlag is set we can do the processing*/

}

void DataProcessing(Variabletypedef *Variable)

{
	/*Conversion of SPI data to Real ADC Values*/

	if(DataReadyFlag)

	{

		arm_rms_f32(Variable->V_inst, BufferSize/2, Variable->V_rms);/*rms Calculation*/

		arm_rms_f32(Variable->I_inst, BufferSize/2, Variable->I_rms);/*rms Calculation*/




		for(int i =0;i<BufferSize/2;i++)


		{

			Variable->PowerArray[i] = *Variable->ptr_V_inst * *Variable->ptr_I_inst;//pointing to v and i instant arrays

			Variable->Sum_Power += Variable->PowerArray[i];// Adding the Instantaneous Power



		}

		Variable->RealPower = Variable->Sum_Power / (BufferSize/2);/*Average Real Power*/

		Variable->ApparentPower = Variable->V_rms[0] * Variable->I_rms[0];/* Apparent Power*/

		EnergyFlag = 1;/* Set Energy Flag 1 for energy Calculation*/

		Variable->ReactivePowerDiff = (Variable->ApparentPower*Variable->ApparentPower)-(Variable->RealPower*Variable->RealPower);/* Reactive Power Calculation*/

		arm_sqrt_f32(Variable->ReactivePowerDiff, &Variable->ReactivePower);/* Reactive power Calculation*/

		Variable->PowerFactor = Variable->RealPower / Variable->ApparentPower;/*  power factor Calculation*/



		DataReadyFlag=0;/*Data Processing is done set DataReadFlag = 1*/
	}




}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)

{

	if(htim==&htim1)/*If timer is 1*/
	{

		if (EnergyFlag)/*If energy flag =1 calculate energy*/
		{
			Variable.energy += Variable.ApparentPower * dt;/*Energy Calculation*/

			EnergyFlag = 0;/*Set energy Flag to Zero After energy Calculation*/

		}

	}


}
void FFtFunctions()

{
	if(FFTEnableFlag)/*Check if fft enable flag is set*/

	{
		Counter++;/*Counter Increment and check 1 or 2 so that at a single time 1 fft should be functioned */

		if(Counter==1){
		CurrentFFtFlag = 1;
		VoltageFFtFlag = 0;
		arm_rfft_fast_f32(&fftHandler, FFTInBufferCurrent, FFTOutBufferCurrent, 0);/*fft for Current Values*/
		}
		else if(Counter==2){
		CurrentFFtFlag = 0;
		VoltageFFtFlag = 1;
		arm_rfft_fast_f32(&fftHandler, FFTInBufferVoltage, FFTOutBufferVoltage, 0);/*fft for Voltage Values*/
		Counter=0;
		}

	}
	if(CurrentFFtFlag)
	{
		arm_abs_f32(FFTOutBufferCurrent, AbsFFTOutBufferCurrent, BufferSize/2);/*remove complex part from fft results*/
		arm_max_f32(AbsFFTOutBufferCurrent, BufferSize/2, &Variable.PeakCurrent, &Variable.PeakCurrentIndex);/*find peak value in array and index which is the peak value or fundamental value and index is the frequency */
	}
	else if (VoltageFFtFlag)
	{
		arm_abs_f32(FFTOutBufferVoltage, AbsFFTOutBufferVoltage, BufferSize/2);/*remove complex part from fft results*/
		arm_max_f32(AbsFFTOutBufferVoltage, BufferSize/2, &Variable.PeakVoltage, &Variable.PeakVoltageIndex);/*find peak value in array and index which is the peak value or fundamental value and index is the frequency */
	}

	if(CrestFactorFlag)/*Checks CrestFactor flag is enable*/
	{
		Variable.vcrestfactor = Variable.PeakVoltage / (*Variable.V_rms);/*crest factor Calculation for voltage*/
		Variable.icreastfactor = Variable.PeakCurrent /(*Variable.I_rms);/*crest factor Calculation for current*/
	}




}
