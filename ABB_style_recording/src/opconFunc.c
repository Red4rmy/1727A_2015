/*
 * opconFunc.c
 *
 *  Created on: Feb 23, 2014
 *      Author: Anton
 */
#include "main.h"
/*
 * This auto corrects the robot in digitized mode.
 */
void opstraight() {
	/*float factor;

	factor = 1 - (abs(gyroGet(gyroYaw)) / 5.0);
	if (gyroGet(gyroYaw) < 0) {
		motorSet(RF, -127);
		motorSet(RB, -127);
		motorSet(LF, 127 * factor);
		motorSet(LB, 127 * factor);
	} else if (gyroGet(gyroYaw) > 0) {
		motorSet(RF, -127 * factor);
		motorSet(RB, -127 * factor);
		motorSet(LF, 127);
		motorSet(LB, 127);
	} else {
		motorSet(RF, -127);
		motorSet(RB, -127);
		motorSet(LF, 127);
		motorSet(LB, 127);
	}*/
	motorSet(RF, -127);
	motorSet(RB, -127);
	motorSet(LF, 127);
	motorSet(LB, 127);
}
/*
 * This auto corrects the robot in digitized mode.
 */
void opback() {
	/*float factor;

	factor = 1 - (abs(gyroGet(gyroYaw)) / 5.0);
	if (gyroGet(gyroYaw) < 0) {
		motorSet(RF, 127 * factor);
		motorSet(RB, 127 * factor);
		motorSet(LF, -127);
		motorSet(LB, -127);
	} else if (gyroGet(gyroYaw) > 0) {
		motorSet(RF, 127);
		motorSet(RB, 127);
		motorSet(LF, -127 * factor);
		motorSet(LB, -127 * factor);
	} else {
		motorSet(RF, 127);
		motorSet(RB, 127);
		motorSet(LF, -127);
		motorSet(LB, -127);
	}*/
	motorSet(RF, 127);
	motorSet(RB, 127);
	motorSet(LF, -127);
	motorSet(LB, -127);
}
/*
 * This is the digital drive equivalent of turnRight(127);
 */
void opturnRight() {
	motorSet(RF, 127);
	motorSet(RB, 127);
	motorSet(LF, 127);
	motorSet(LB, 127);
}
/*
 * This is the digital drive equivalent of turnLeft(127);.
 */
void opturnLeft() {
	motorSet(RF, -127);
	motorSet(RB, -127);
	motorSet(LF, -127);
	motorSet(LB, -127);
}
/*
 * Function invoked when no action is taken in digital mode.
 */
void opdriveStop() {
	motorSet(RF, 0);
	motorSet(RB, 0);
	motorSet(LF, 0);
	motorSet(LB, 0);
}
/*
 * This is the digital drive equivalent of strafeRight(127);
 */
void opstrafeRight() {
		motorSet(RF, 127);
		motorSet(RB, -127);
		motorSet(LF, 127);
		motorSet(LB, -127);
}
/*
 * This is the digital drive equivalent of strafeLeft(127);
 */
void opstrafeLeft() {
		motorSet(RF, -127);
		motorSet(RB, 127);
		motorSet(LF, -127);
		motorSet(LB, 127);
}
