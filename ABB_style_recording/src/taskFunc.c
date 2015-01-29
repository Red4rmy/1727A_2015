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

int joy1_channel1;
int joy1_channel2;
int joy1_channel3;
int joy1_channel4;
int joy2_channel1;
int joy2_channel2;
int joy2_channel3;
int joy2_channel4;
int joy1_channel5;
int joy1_channel6;
int joy1_channel7;
int joy1_channel8;
int joy2_channel5;
int joy2_channel6;
int joy2_channel7;
int joy2_channel8;
void getJoystickValues(void *ignore)
{
joy1_channel1 = joystickGetAnalog(1,1);
joy1_channel2 = joystickGetAnalog(1,2);
joy1_channel3 = joystickGetAnalog(1,3);
joy1_channel4 = joystickGetAnalog(1,4);
joy2_channel1 = joystickGetAnalog(2,1);
joy2_channel2 = joystickGetAnalog(2,2);
joy2_channel3 = joystickGetAnalog(2,3);
joy2_channel4 = joystickGetAnalog(2,4);


joy1_channel5 = joystickGetDigital(1,5,JOY_UP)+(2*joystickGetDigital(1,5,JOY_DOWN));

joy1_channel6 = joystickGetDigital(1,6,JOY_UP)+(2*joystickGetDigital(1,6,JOY_DOWN));

joy1_channel7 = joystickGetDigital(1,7,JOY_UP)+(2*joystickGetDigital(1,7,JOY_DOWN))
		+(4*joystickGetDigital(1,7,JOY_RIGHT))+(8*joystickGetDigital(1,7,JOY_LEFT));

joy1_channel8 = joystickGetDigital(1,8,JOY_UP)+(2*joystickGetDigital(1,8,JOY_DOWN))
		+(4*joystickGetDigital(1,8,JOY_RIGHT))+(8*joystickGetDigital(1,8,JOY_LEFT));

joy2_channel5 = joystickGetDigital(2,5,JOY_UP)+(2*joystickGetDigital(2,5,JOY_DOWN));

joy2_channel6 = joystickGetDigital(2,6,JOY_UP)+(2*joystickGetDigital(2,6,JOY_DOWN));

joy2_channel7 = joystickGetDigital(2,7,JOY_UP)+(2*joystickGetDigital(2,7,JOY_DOWN))
		+(4*joystickGetDigital(2,7,JOY_RIGHT))+(8*joystickGetDigital(2,7,JOY_LEFT));

joy2_channel8 = joystickGetDigital(2,8,JOY_UP)+(2*joystickGetDigital(2,8,JOY_DOWN))
		+(4*joystickGetDigital(2,8,JOY_RIGHT))+(8*joystickGetDigital(2,8,JOY_LEFT));
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
