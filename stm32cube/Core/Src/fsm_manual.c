/*
 * fsm_manual.c
 *
 *  Created on: Oct 11, 2022
 *      Author: phamv
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
	case MAN_RED:
		set_traffic_red();
		if(timer1_flag == 1){
			status = AUTO_RED;
			setTimer1(3000);
		}
		if(button1_flag == 1){
			button1_flag = 0;
			status = MAN_GREEN;
			setTimer1(5000);
		}
		break;
	case MAN_GREEN:
		set_traffic_green();
		if(timer1_flag == 1){
			status = AUTO_GREEN;
			setTimer1(2000);
		}
		if(button1_flag == 1){
			button1_flag = 0;
			status = MAN_YELLOW;
			setTimer1(5000);
		}
		break;
	case MAN_YELLOW:
		set_traffic_yellow();
		if(timer1_flag == 1){
			status = AUTO_YELLOW;
			setTimer1(1000);
		}
		if(button1_flag == 1){
			button1_flag = 0;
			status = MAN_RED;
			setTimer1(5000);
		}
		break;
	default:
		break;
	}
}
