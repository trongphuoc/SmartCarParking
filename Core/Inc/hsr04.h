/*
 * hsr04.h
 *
 *  Created on: Nov 22, 2019
 *      Author: Administrator
 */

#ifndef INC_HSR04_H_
#define INC_HSR04_H_
#include "stm32f1xx_hal.h"
#include "dwt_stm32_delay.h"
#include <stdbool.h>


/***************************************************************
 * TYPEDEF
 ****************************************************************/
typedef struct{
	float Distance;

	GPIO_TypeDef* ECHO_GPIOx;
	uint16_t ECHO_GPIO_PIN;

	GPIO_TypeDef* TRIGGER_GPIOx;
	uint16_t TRIGGER_GPIO_PIN;

	uint8_t sensorID;
} HCSR04_T;
/**********************************************************************
@func  void HCSR04_Init(GPIO_TypeDef* ECHO_GPIOx, uint16_t ECHO_PIN,
				GPIO_TypeDef* TRIGGER_GPIOx,
				uint16_t TRIGGER_PIN)
@brief Init GPIO port and GPIO pin for HCSR04 sensor

@param ECHO_GPIOx 	 pointer to  GPIO port of ECHO pin
@param ECHO_PIN   	 echo pin
@param TRIGGER_GPIOx pointer to GPIO of TRIGGER pin
@param TRIGGER_PIN 	 trigger pin

 **********************************************************************/
void HCSR04_Init(HCSR04_T* HCSR04, GPIO_TypeDef* ECHO_GPIOx, uint16_t ECHO_PIN,
							GPIO_TypeDef* TRIGGER_GPIOx,uint16_t TRIGGER_PIN);
/**********************************************************************
@func  uint32_t HCSR04_Read(HCSR04_T* HCSR04)
@brief Read time between transmit and receive of trigger pin and echo pin

@param HCSR04  pointer to typedef of hcsr04 sensor

@return 	   value of time between transmit and receive pulse
 **********************************************************************/
uint32_t HCSR04_Read(HCSR04_T* HCSR04);
/**********************************************************************
@func  bool HCSR04_CompareDistance(HCSR04_T* HCSR04)
@brief Compare value of distance of typedef struct HCSR04 with reference data

@param HCSR04  			pointer to typedef of hcsr04 sensor
@param distance_value   reference distance

@return true  distance is smaller than reference value
@return false distance is bigger than reference value

 **********************************************************************/
bool HCSR04_CompareDistance(HCSR04_T* HCSR04, uint8_t distance_value);
#endif /* INC_HSR04_H_ */
