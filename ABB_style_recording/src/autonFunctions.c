#include "main.h"



/*
 * Function which turns the robot to the right for the degrees amount.
 * Uses a scaleing power curve which is based on a P loop.
 * Returns true if completed withing 2 seconds.
 * Exits and returns false if not complete in 2 seconds.
 */
bool turnRightTo(int degrees)
{
	gyroReset(gyroYaw);
	int power;
	float error;
	int timing=0;
	while(gyroGet(gyroYaw)<degrees)
	{
		error = abs(degrees-gyroGet(gyroYaw));
		power = 27+(((float)(error)/degrees)*100);
		turnRight(power);
		timing+=20;
		if(timing>2000)
			return false;
		delay(20);
	}
	return true;
}
/*
 * Function which turns the robot to the left for the degrees amount.
 * Uses a scaleing power curve which is based on a P loop.
 * Returns true if completed withing 2 seconds.
 * Exits and returns false if not complete in 2 seconds.
 */
bool turnLeftTo(int degrees)
{
	gyroReset(gyroYaw);
	int power;
	float error;
	int timing=0;
	while(gyroGet(gyroYaw)<degrees)
	{
		error = abs(degrees-gyroGet(gyroYaw));
		power = 27+(((float)(error)/degrees)*100);
		turnLeft(power);
		timing+=20;
		if(timing>2000)
			return false;
		delay(20);
	}
	return true;
}

/*
 * Sets the digital out state of the CLAW_PIN.
 * true: closed.
 * false: open.
 */
void clawSet(bool state)
{
	digitalWrite(CLAW_PIN,state);
}


void rotSet(bool state)
{
	digitalWrite(ARM_PIN,state);
}

/*
 * Sets the arm to the target # of potentiometer clicks.
 */
void armSet(int target)
{
	while(ARMpos>(target+5)||ARMpos<(target-5))
	{
		if(ARMpos>(target+5))
		{
			armDown(127);
		}
		else if(ARMpos<(target-5))
		{
			armUp(127);
		}
	}
	armStop();
}

/*
 * Uses the Ultrasonic sensor to find the Skyrise piece.
 * Approach must be in a straigt line.
 * THE DISTANCE IS NOT FINAL. TESTING NEEDED AND MUST BE COMPLETED.
 */
void skyFind()
{
	while(SKYdist>3)
	{
		forward(127);
	}
	backward(40);
	delay(50);
	backward(0);
}
/*
 * Builds a single skyrise section at a given height (potentiometer readout)
 */
void skySection(int height)
{
	clawSet(1);//close claw
	armSet(height);
	rotSet(1);//rotate to skyrise
	delay(1000);
	clawSet(0);//release claw
	delay(500);
	rotSet(0);//rotate to autoloader
	armSet(0);//replace 0 with rest position
	delay(500);

}


