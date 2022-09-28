/*
 * input_processing.c
 *
 *  Created on: Sep 8, 2022
 *      Author: phamv
 */
#include "main.h"
#include "input_reading.h"
#include "timer.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
enum ButtonState buttonState = BUTTON_RELEASED;

void fsm_for_input_processing(void){
	switch(buttonState){
	case BUTTON_RELEASED:
		if(isButtonPressed(0)){
			buttonState = BUTTON_PRESSED;
			// increase value
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		}
		break;
	case BUTTON_PRESSED:
		if(!isButtonPressed(0)){
			buttonState = BUTTON_RELEASED;
		} else if(isButtonPressed1s(0)){
			buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND;
			setTimer0(10);
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND:
		if(!isButtonPressed(0)){
			buttonState = BUTTON_RELEASED;
		} else {
			if(timer0_flag){
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				setTimer0(500);
			}
		}
		//todo
		break;
	}
}

