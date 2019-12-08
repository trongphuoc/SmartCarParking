/*
 * hcsr04.c
 *
 *  Created on: Nov 22, 2019
 *      Author: Administrator
 */

#include "hsr04.h"

uint32_t local_time2 = 0;

void HCSR04_Init(HCSR04_T* HCSR04, GPIO_TypeDef* ECHO_GPIOx, uint16_t ECHO_PIN,
							GPIO_TypeDef* TRIGGER_GPIOx,uint16_t TRIGGER_PIN)
{
	HCSR04->Distance 	  = 0;
	HCSR04->ECHO_GPIOx 	  = ECHO_GPIOx;
	HCSR04->ECHO_GPIO_PIN = ECHO_PIN;
	HCSR04->TRIGGER_GPIOx = TRIGGER_GPIOx;
	HCSR04->TRIGGER_GPIO_PIN = TRIGGER_PIN;


}
uint32_t HCSR04_Read(HCSR04_T* HCSR04)
{
	DWT_Delay_Init();
	uint32_t local_time = 0;

	HAL_GPIO_WritePin(HCSR04->TRIGGER_GPIOx, HCSR04->TRIGGER_GPIO_PIN, GPIO_PIN_RESET);
	DWT_Delay_us(2);
	HAL_GPIO_WritePin(HCSR04->TRIGGER_GPIOx, HCSR04->TRIGGER_GPIO_PIN, GPIO_PIN_SET);
	DWT_Delay_us(100);
	HAL_GPIO_WritePin(HCSR04->TRIGGER_GPIOx, HCSR04->TRIGGER_GPIO_PIN, GPIO_PIN_RESET);
	while((HAL_GPIO_ReadPin(HCSR04->ECHO_GPIOx, HCSR04->ECHO_GPIO_PIN ) == GPIO_PIN_RESET))
	{



	}
	while(HAL_GPIO_ReadPin(HCSR04->ECHO_GPIOx, HCSR04->ECHO_GPIO_PIN))
	{
		//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
		local_time=local_time + 1;
		DWT_Delay_us(1);

	}
	return local_time;


}
bool HCSR04_CompareDistance(HCSR04_T* HCSR04, uint8_t distance_value)
{
	if(HCSR04->Distance < distance_value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

