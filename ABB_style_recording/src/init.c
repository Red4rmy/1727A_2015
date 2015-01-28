/** @file init.c
 * @brief File for initialization code
 *
 * This file should contain the user initialize() function and any functions related to it.
 *
 * Copyright (c) 2011-2013, Purdue University ACM SIG BOTS.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Purdue University ACM SIG BOTS nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL PURDUE UNIVERSITY ACM SIG BOTS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Purdue Robotics OS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs pre-initialization code. This function will be started in kernel mode one time while the
 * VEX Cortex is starting up. As the scheduler is still paused, most API functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes (pinMode()) and port
 * states (digitalWrite()) of limit switches, push buttons, and solenoids. It can also safely
 * configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
 */
void initializeIO() {
	pinMode(CLAW_PIN,OUTPUT);
	digitalWrite(CLAW_PIN,LOW);
	pinMode(ARM_PIN,OUTPUT);
	digitalWrite(ARM_PIN,LOW);
}

/*
 * Runs user initialization code. This function will be started in its own task with the default
 * priority and stack size once when the robot is starting up. It is possible that the VEXnet
 * communication link may not be fully established at this time, so reading from the VEX
 * Joystick may fail.
 *
 * This function should initialize most sensors (gyro, encoders, ultrasonics), LCDs, global
 * variables, and IMEs.
 *
 * This function must exit relatively promptly, or the operatorControl() and autonomous() tasks
 * will not start. An autonomous mode selection menu like the pre_auton() in other environments
 * can be implemented in this task if desired.
 */
/*
 * This is the final auton selection variable.
 */
int autonProgram;
/*
 * This is the final auton selection variable.
 */
int driveProgram;



Gyro gyroYaw;
Ultrasonic skyFind1;
Encoder armPos;
point *input;
int steps = 0;
int RFcount;
int RBcount;
int LFcount;
int LBcount;
double RFvel;
double RBvel;
double LFvel;
double LBvel;
int frontAngle;
int ARMpos;
int SKYdist;
void initialize() {
	FILE *toRead;
	lcdInit(uart1);
	lcdSetBacklight(uart1, true);
	lcdClear(uart1);
	delay(1000);
	autonProgram = autoSelect();
	delay(1000);
	driveProgram = driveSelect();
	imeInitializeAll();
	gyroYaw = gyroInit(7, 0);

	speakerInit();
	armPos = encoderInit(1,2,false);

	skyFind1 = ultrasonicInit(3,4);

	switch (autonProgram) {
	case RED_0:
		toRead = fopen("red_0", "r");
		break;
	case BLUE_0:
		toRead = fopen("blue_0", "r");
		break;
	case RED_1:
		toRead = fopen("red_1", "r");
		break;
	case BLUE_1:
		toRead = fopen("blue_1", "r");
		break;
	case NOAUTO:
		toRead = NULL;
		break;
	default:
		toRead = NULL;
		break;
	}
	lcdClear(uart1);

	if (toRead == NULL) {
		lcdClear(uart1 );
		lcdPrint(uart1, 1, "NO READ");
		delay(1000);
	} else {
		lcdPrint(uart1, 1, "start Read");
		delay(500);
		steps = fgetc(toRead);
		input = (point*)malloc(steps*sizeof(point));
		fread(input, sizeof(point), steps, toRead);
		lcdPrint(uart1, 1, "end Read");
		fclose(toRead);
	}
	delay(1000);
	lcdPrint(uart1,1,"%d   %d",autonProgram,driveProgram);
	delay(500);
	lcdClear(uart1);
}

