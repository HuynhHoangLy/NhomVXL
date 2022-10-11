/*
 * button.c
 *
 *  Created on: Sep 27, 2022
 *      Author: phamv
 */

#include "button.h"

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int TimeOutForKeyPress =  300;

int button1_flag = 0;

void subKeyProcess(){
	//TODO
	HAL_GPIO_TogglePin(LED_CHECK_GPIO_Port, LED_CHECK_Pin);
	button1_flag = 1;
}

void getKeyInput(){
  KeyReg2 = KeyReg1;
  KeyReg1 = KeyReg0;
  KeyReg0 = HAL_GPIO_ReadPin(BUTTON0_GPIO_Port, BUTTON0_Pin);
  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
	  KeyReg3 = KeyReg2;
	  if(KeyReg3 == PRESSED_STATE){
		  if(TimeOutForKeyPress > 0){
			  TimeOutForKeyPress--;
		  } else{
			  TimeOutForKeyPress = 100;
			  subKeyProcess();
		  }
	  } else {
		  TimeOutForKeyPress = 0;
	  }
  }
}
