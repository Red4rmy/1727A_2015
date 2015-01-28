#include "main.h"

/*
 * Turns left at the int power passed to it.
 */
void turnLeft(int power)
{
	motorSet(RF,-power);
	motorSet(RB,-power);
	motorSet(LF,-power);
	motorSet(LB,-power);
}
/*
 * Turns right at the int power passed to it.
 */
void turnRight(int power)
{
	motorSet(RF,power);
	motorSet(RB,power);
	motorSet(LF,power);
	motorSet(LB,power);
}
/*
 * Moves forward at the int power passed to it.
 */
void forward(int power)
{
	motorSet(RF,-power);
	motorSet(RB,-power);
	motorSet(LF,power);
	motorSet(LB,power);
}
/*
 * Moves backward at the int power passed to it.
 */
void backward(int power)
{
	motorSet(RF,power);
	motorSet(RB,power);
	motorSet(LF,-power);
	motorSet(LB,-power);
}
/*
 * Strafes right at the int power passed to it.
 */
void strafeRight(int power)
{
	motorSet(RF, power);
	motorSet(RB, -power);
	motorSet(LF, power);
	motorSet(LB, -power);
}

/*
 * Strafes Left at the int power passed to it.
 */
void strafeLeft (int power)
{
	motorSet(RF, -power);
	motorSet(RB, power);
	motorSet(LF, -power);
	motorSet(LB, power);
}
/*
 * Lifts the arm at the int power passed to it.
 */
void armUp(int power)
{
	motorSet(LIFT_RO,power);
	motorSet(LIFT_RI,power);
	motorSet(LIFT_LI,power);
	motorSet(LIFT_LO,power);
	motorSet(LIFT_RS,-power);
	motorSet(LIFT_LS,-power);
}
/*
 * Drops the arm at the int power passed to it.
 */
void armDown(int power)
{
	motorSet(LIFT_RO,-power);
	motorSet(LIFT_RI,-power);
	motorSet(LIFT_LI,-power);
	motorSet(LIFT_LO,-power);
	motorSet(LIFT_RS,power);
	motorSet(LIFT_LS,power);
}
/*
 * Stops the arm.
 */
void armStop()
{
	motorSet(LIFT_RO,0);
	motorSet(LIFT_RI,0);
	motorSet(LIFT_LI,0);
	motorSet(LIFT_LO,0);
	motorSet(LIFT_RS,0);
	motorSet(LIFT_LS,0);
}

/*
 * Prints the IME readout to the UART1 lcd in minimum 3 digits.
 */
void printIMEVelocity()
{

	lcdPrint(uart1,1,"%3f  %3f",LFvel,RFvel);
	lcdPrint(uart1,2,"%3f  %3f",LBvel,RBvel);
}

