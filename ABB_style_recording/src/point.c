/*
 * point.c
 *
 *  Created on: Oct 24, 2014
 *      Author: Anton
 */
#include "main.h"

/*
 * Returns a point with the "turn" type and a turn factor of int turn.
 */
point turnPointWrite(int turn)
{
	point aPoint;

	aPoint.type = type_turn;
	aPoint.turn = turn;

	return aPoint;
}
/*
 * Returns a point with the "straight" type and int rf, int lf, int rb, int lb as the motion
 * factors for each wheel.
 */
point straightPointWrite(int rf,int lf, int rb, int lb)
{
	point aPoint;
	aPoint.type = type_straight;
	aPoint.rb = rb;
	aPoint.lb = lb;
	aPoint.rf = rf;
	aPoint.lf = lf;


	return aPoint;
}
/*
 * Returns a point with the "arm" type and int arm as the arm height factor.
 */
point armPointWrite(int arm)
{
	point aPoint;

	aPoint.type = type_arm;
	aPoint.arm = arm;

	return aPoint;
}
/*
 * Returns a point with the "claw" type and bool claw as the claw state.
 */
point clawPointWrite(bool claw)
{
	point aPoint;

	aPoint.type = type_claw;
	aPoint.claw = claw;

	return aPoint;
}
/*
 * Returns a point with the "func"(function) type and int func as the cooresponding integer to
 * the function to run.
 */
point funcPointWrite(int func)
{
	point aPoint;

	aPoint.func = func;
	aPoint.type = type_func;

	return aPoint;
}
/*
 * Plays back the point aPoint based on its types and the values of its dimensions.
 */
void playPoint(point aPoint)
{
	switch(aPoint.type)
	{
	case type_turn:
		if(aPoint.turn<0)
			turnLeftTo(aPoint.turn);
		else
			turnRightTo(aPoint.turn);
		break;
	case type_straight:
		driveToPID(aPoint.rb,aPoint.lb,aPoint.rf,aPoint.lf);
		break;
	case type_arm:
		armSet(aPoint.arm);
		break;
	case type_claw:
		clawSet(aPoint.claw);
		break;
	case type_func:
		switch(aPoint.func)
		{
		case SKYFIND:
			skyFind();
			break;
		}
		break;

	}

}


/*
 * Button functions:
 * joy:2,btn_grp:8,btn:UP = recording stop button
 * joy:2,btn_grp:5,btn:UP = run skyFind
 * joy:2,btn_grp:6,btn:RIGHT = point type scroll right
 * joy:2,btn_grp:6,btn:LEFT = point type scroll left
 * joy:2,btn_grp:8,btn:DOWN = point type select
 */
point recordPoint()
{

	int func;
	while(joy2_channel8 == 0)
	{

		digitalDrive();
		if(joy1_channel7 == 1)
		{
			skyFind();
			func = 0;
		}
	}
	point aPoint;
	switch(pointWriteSelect())
	{
	case 1:
		return turnPointWrite(gyroGet(gyroYaw));
		break;
	case 2:
		return straightPointWrite(RFcount,LFcount,RBcount,LBcount);
		break;
	case 3:
		return armPointWrite(ARMpos);
		break;
	case 4:
		return clawPointWrite(1/* INCLUDE ACTUAL BOOL VALUE*/);
		break;
	case 5:
		return funcPointWrite(func);
		break;
	case 6:
		break;
	default:
		return aPoint;
		break;
	}
	lcdClear(uart1);
	return aPoint;
}
