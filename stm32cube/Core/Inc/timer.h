/*
 * timer.h
 *
 *  Created on: Oct 4, 2022
 *      Author: phamv
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "button.h"

extern int timer1_flag;
extern int timer2_flag;

void setTimer1(int);
void setTimer2(int);
void timer_run();

#endif /* INC_TIMER_H_ */
