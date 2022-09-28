/*
 * timer.c
 *
 *  Created on: Sep 28, 2022
 *      Author: phamv
 */
#include "timer.h"
#include "input_reading.h"
#include "main.h"

int timer0_counter = 0;
int timer0_flag = 0;

void setTimer0(int duration){
	timer0_flag = 0;
	timer0_counter = duration/10;
}

void timerRun(){
	if(timer0_counter > 0){
		timer0_counter--;
		if(timer0_counter == 0) timer0_flag = 1;
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	timerRun();
	if(htim->Instance == TIM2){
		buttonReading();
	}
}
