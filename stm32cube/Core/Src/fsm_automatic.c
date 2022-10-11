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
		setTimer1(3000);
		break;
	case AUTO_RED:
		set_traffic_red();
		if(timer1_flag == 1){
			status = AUTO_GREEN;
			setTimer1(2000);
		}
		if(button1_flag == 1){
			button1_flag = 0;
			status = MAN_GREEN;
			setTimer1(5000);
		}
		break;
	case AUTO_GREEN:
		set_traffic_green();
		if(timer1_flag == 1){
			status = AUTO_YELLOW;
			setTimer1(1000);
		}
		if(button1_flag == 1){
			button1_flag = 0;
			status = MAN_YELLOW;
			setTimer1(5000);
		}
		break;
	case AUTO_YELLOW:
		set_traffic_yellow();
		if(timer1_flag == 1){
			status = AUTO_RED;
			setTimer1(5000);
		}
		if( button1_flag == 1){
			button1_flag = 0;
			status = MAN_RED;
			setTimer1(5000);
		}
		break;
	default:
		break;
	}
}
