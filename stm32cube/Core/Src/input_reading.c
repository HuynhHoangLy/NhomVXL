/*
 * input_reading.c
 *
 *  Created on: Sep 8, 2022
 *      Author: phamv
 */
#include "main.h"

#define NO_OF_BUTTON	1
#define DURATION_FOR_AUTO_INCREASING	100
#define BUTTON_IS_PRESSED	GPIO_PIN_RESET
#define BUTTON_IS_RELEASED	GPIO_PIN_SET

// buffer storing final result after debouncing
static GPIO_PinState buttonBuffer[NO_OF_BUTTON];

// debouncing buffers
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTON];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTON];

// flag for button pressed more than 1 second
static uint8_t flagForButtonPress1s[NO_OF_BUTTON];

// counter for auto increasing after button is pressed more than 1s
static uint16_t counterFotButtonPress1s[NO_OF_BUTTON];

void button_reading(void){
	for(char i = 0; i < NO_OF_BUTTON; i++){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i]){
			buttonBuffer[i] == debounceButtonBuffer1[i];
		}
		if(buttonBuffer[i] == BUTTON_IS_PRESSED){
			// if counter is pressed, we start counting
			if(counterFotButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING){
				counterFotButtonPress1s[i]++;
			} else {
				flagForButtonPress1s[i] = 1;
			}
		} else {
			counterFotButtonPress1s[i] = 0;
			flagForButtonPress1s[i] = 0;
		}
	}
}

unsigned char is_button_pressed(unsigned char index){
	if(index >= NO_OF_BUTTONS) return 0;
	return buttonBuffer[index] == BUTTON_IS_PRESSED;
}

unsigned char is_button_pressed_1s(unsigned char index){
	if(index >= NO_OF_BUTTONS) return 0xff;
	return flagForButtonPress1s[index] == 1;
}
