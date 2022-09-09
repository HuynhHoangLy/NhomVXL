/*
 * timer.c
 *
 *  Created on: Sep 8, 2022
 *      Author: phamv
 */
#include "main.h"
#include "input_reading.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2){
		button_reading();
	}
}

