/*
 * fsm_automatic.c
 *
 *  Created on: Oct 4, 2022
 *      Author: phamv
 */
#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
	case INIT:
			status = AUTO_RED;
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin|LED_YELLOW_Pin, GPIO_PIN_SET);
			setTimer1(500);

		break;
	case AUTO_RED:
		if(timer1_flag == 1){
			status = AUTO_GREEN;
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_YELLOW_Pin, GPIO_PIN_SET);
			setTimer1(300);
		}
		break;
	case AUTO_GREEN:
		if(timer1_flag == 1){
			status = AUTO_YELLOW;
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_GREEN_Pin, GPIO_PIN_SET);
			setTimer1(200);
		}
		break;
	case AUTO_YELLOW:
		if(timer1_flag == 1){
			status = AUTO_RED;
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin|LED_YELLOW_Pin, GPIO_PIN_RESET);
			setTimer1(500);
		}
		break;
	default:
		break;
	}
}

