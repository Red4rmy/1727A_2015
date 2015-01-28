/*
 * taskFunc.c
 *
 *  Created on: Dec 25, 2014
 *      Author: Anton
 */
#include "main.h"

int tRB;
int tRF;
int tLB;
int tLF;

void getSensors()
{
	imeGet(imeRB, &RBcount);
	imeGet(imeRF, &RFcount);
	imeGet(imeLB, &LBcount);
	imeGet(imeLF, &LFcount);
	imeGetVelocity(imeRB, &tRB);RBvel = tRB / 24.5;
	imeGetVelocity(imeRF, &tRF);RFvel = tRF / 24.5;
	imeGetVelocity(imeLB, &tLB);LBvel = tLB / 24.5;
	imeGetVelocity(imeLF, &tLF);LFvel = tLF / 24.5;
	SKYdist = ultrasonicGet(skyFind1);
	ARMpos = encoderGet(armPos);
	frontAngle = gyroGet(gyroYaw);
	taskDelay(20);
}

int lcdScreen = 1;
int lcdScreenMax1 = 5;
void sensorDebug() {

	if (joystickGetDigital(2, 8, JOY_LEFT) == 1) { //Scrolls to the left
		if (lcdScreenMin == lcdScreen) {
			lcdScreen = lcdScreenMax1;
			delay(250);
		} else {
			lcdScreen--;
			delay(250);
		}
	}
	if (joystickGetDigital(2, 8, JOY_RIGHT) == 1) { //Scrolls to the right
		if (lcdScreenMax1 == lcdScreen) {
			lcdScreen = lcdScreenMin;
			delay(250);
		} else {
			lcdScreen++;
			delay(250);
		}
	}

	if (lcdScreen == 1) {
		lcdPrint(uart1, 1, "LFV:%2.0fRFV:%2.0f",LFvel,RFvel); //Name the first point type here
		lcdPrint(uart1, 2, "LBV:%2.0fRBV:%2.0f",LBvel,RBvel); //Name the first point type here
	} else if (lcdScreen == 2) {
		lcdPrint(uart1, 1, "LF:%3dRF:%3d",LFcount, RFcount); //Name the second point type here
		lcdPrint(uart1, 2, "LB:%3dRB:%3d",LBcount, RBcount); //Name the second point type here
	} else if (lcdScreen == 3) {
		lcdPrint(uart1, 1, "Angle:"); //Name the third point type here
		lcdPrint(uart1, 2, "%d",frontAngle); //Name the third point type here
	} else if (lcdScreen == 4) {
		lcdPrint(uart1, 1, "Arm"); //Name the fourth point type here
		lcdPrint(uart1, 2, "%3d",ARMpos); //Name the fourth point type here
	} else if (lcdScreen == 5) {
		lcdPrint(uart1, 1, "skydist"); //Name the fifth point type here
		lcdPrint(uart1, 2, "%4d",SKYdist); //Name the fifth point type here
	}
}
