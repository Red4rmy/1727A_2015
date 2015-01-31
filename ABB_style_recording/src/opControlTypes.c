/*
 * opControlTypes.c
 *
 *  Created on: Nov 10, 2014
 *      Author: Anton
 */
#include"main.h"







/*
 * Button functions:
 * joy:1,btn_grp:5,btn:UP = Arm up at full power.
 * joy:1,btn_grp:5,btn:DOWN = Arm down at full power
 * joy:1,btn_grp:6,btn:UP = Claw set to closed.
 * joy:1,btn_grp:6,btn:DOWN = Claw set to open.
 */
void gameControl()
{

	motorSet(RF,joy1_channel1+joy1_channel3-joy1_channel4);
	motorSet(RB,-(joy1_channel1+joy1_channel3+joy1_channel4));
	motorSet(LF,-(joy1_channel1-joy1_channel3-joy1_channel4));
	motorSet(LB,joy1_channel1-joy1_channel3+joy1_channel4);

	if(joy1_channel5==1)
		armUp(127);
	else if(joy1_channel5==2)
		armDown(127);
	else
		armStop();
	if(joy1_channel6==1)
		clawSet(1);
	else if(joy1_channel6==2)
		clawSet(0);

	if(joy1_channel7==8)
		rotSet(1);
	else if(joy1_channel7==4)
		rotSet(0);
	//printIMEVelocity();

	/*if(joystickGetDigital(2,5,JOY_UP))
	{
		//SMB2 win
		speakerPlayRtttl("Meta:d=4,o=5,b=160:8e,8e,8g,8g,a,16c6,16g,16a,8d#6,16p,8d6,16c6,16a,8g,16a,8c6,8c6,16a,8d6,e6,d6,16a,8c6,8c6,16c6,8d6,8e6,8g6,16e6,16d6,8c6,16g,16g#,16p,16a,16p,16d#,2d,8p,a,16c6,16g,16a,16d#6,8p,8d6,16c6,16a,8g,16a,8c6,8c6,16a,8d6,e6,d6,8a,8d6,16d#6,16e6,16p,16d6,16p,16c6,16p,16a,16p,16g,16e,16d#,2d.,p,b,b,8f#.,8g.,8a,e,g,d6,a,b,b,8f#.,8g.,8a,2e6,2a,8d#.,8a.,8d#,8d.,8g#.,8d,8g.,8f.,8c,8d#.,8g.,8c6,16d#,16f,g.,p,g#,16a#,16f,16f,16f,16f,16p,16f,16f,16f,16f,16f,16p,p,8a6,16a,16p,16g,16a,16p,16a,16p,16a,16p,16g,16a,16c6,16d6,16d#6,8p,16d6,16p,16a,16g,16p,16d#6,16p,16d6,16p,16c6,16a,16g,16a,16g,8a,16a6,16p,16g6,16a6,16d#6,16d6,16c6,16d6,16p,16e6,16p,16a,16g,16g#,16a,16f#,16p,16e,16p,16d,8c,16e,16a,16b,8c6,16d#,16g,16a,8a#,16a#,16p,16g#,16a#,16p,16a#,16p,16a#,16p,16g#,16a#,16c#6,16d#6,16e6,8p,16d#6,16p,16a#,16g#,16p,16e6,16p,16d#6,16p,16c#6,16a#,16g#,16a#,16g#,8a#,16a#,16p,16g#,16a#,16f6,16d#6,16c#6,16d#6,16p,16f6,16p,16a#,16g#,16a,16a#,16g,16p,16f,16p,16d#,8c#,16a#,16c#6,16d#6,8e6,16f,16g,16a#,8a6,16a,16p,16g,16a,16p,16a,16p,16a,16p,16g,16a,16c6,16d6,16d#6,8p,16d6,16p,16a,8g,16d#6,16p,16d6,16p,16c6,16a,16g,16a,16c6,8a,16a6,16p,16g6,16a6,16d#6,16d6,16c6,16d6,16p,16e6,16p,16a,16g,16g#,16a,16f#,16p,16e,16p,16d,8c,16e,16a,16b,8c6,16d#,16g,16a,16a#,16f,16a#,16p,16g#,16a#,16p,16a#,16p,16a#,16p,16g#,16a#,16c#6,16d#6,16e6,8p,16d#6,16p,16a#,8g#,16e6,16p,16d#6,16p,16c#6,16a#,16g#,16c6,16c#6,16c#,16f,16a#,16p,16g#,16a#,16f6,16d#6,16c#6,16d#6,16p,16f6,16p,16a#,16g#,16a,16a#,16g,16p,16f,16p,16d#,8c#,16a#,16c#6,16d#6,8e6,16f,16g,16a#,c,c6,8g.,8g#.,8a#,f,g#,d#6,a#,c,c6,8g.,8g#.,8a#,2f6,a#,p,8e.,8a#.,8e,8d#.,8a.,8d#,8g#.,8f#.,8c#,8e.,8g#.,8c#6,16e,16f#,g#.,p,a,16b,16f#,16f#,16f#,16p,16f#,8f#,8e6,8e6,8g6,8g6,16a6,8p,2a.,8p,8a.,2a,8p,16p,16a#,16b,8c.6,2c6,8p,16p,16d6,16d#6,8e.6,2e6,8p,16p,16g6,16p,8a6,16a,16p,16c6,16p,16a,16d#6,8p,16d6,16p,16c6,16a,16g,16p,16a,16c6,16p,16c6,16p,16a,16d6,16p,2p,16c,16d#,16p,16d#,16p,16d#,16f,16p,16g,16p,16a#,16p,16g,16f,16d#,16p,16d,16e,16p,16g#,16p,16a,2b,p,8e6,16c6,16d6,16p,16e6,8p,16a,16p,8c6,16a,16p,8p,16e6,16p,16c6,16d6,16p,16e6,8p,16d#6,16p,16d6,16c6,16a,16p,8p,16g,16p,16c6,16d#6,16p,16g6,8p,16c6,16p,8d#6,16c6,16p,8p,16g6,16p,16d#6,16f6,16p,16g6,8p,8g.6,8g.6,16a6,16p,16e6,16p,16c6,16d6,16p,16e6,8p,16a,16p,8c6,16a,16p,8p,16e6,16p,16c6,16d6,16p,16e6,8p,8d#6,16d6,16c6,16a,16p,8p,8g,16c6,16d#6,16p,16g6,8p,16c6,16p,8d#6,16c6,16p,8p,16d#6,16p,16f6,8g6,8f6,16d#6,16g6,16f6,16d#6,16d6,16c6,16p,8p,16c6,16p,16c6,16d6,16p,8d#.6,16c6,16p,16a#,16c6,p,8g,16c6,16d#6,16p,8g.6,16d#6,16p,16d6,16d#6,p,16g#,16p,16b,16d#6,16p,8b.,16g#,16p,16f#,16g#,p,16g#,16p,16b,16d#6,16p,8f#.6,8d#6,16c#6,16d#6,16c#6,16b,16a#,g#,16p,16f#,16g#,8a#.,8d#.6,8a#,8c.6,8f.,8c,8e.,8f.,8g,8f.,8d.,8f,8g#.,8a.,8b,c.6,16b,16c6,8d.6,8b.,8d6,8c.6,16b,2a.,c.6,16b,16c6,8d.6,8b.,8d6,2d#.6,p,c.6,16a#,16g#,8g,8f,8d#,8f,g,8f.,16g,c,8c.,16c,2d.,8d.,16d#,2d.,16c.,16d#.,16g,c.6,16a#,16g#,8g,8f,8d#,8f,g,8f.,16g,c,c,2d.,d,2d.,8d.,16d#,d.,8d#,d.,8d#,16d,16d#,16d,16d#,16d,16d#,16d,16d#,8e,8e,8g,8g,a,16c6,16g,16a,8d#6,16p,8d6,16c6,16a,8g,16a,8c6,8c6,16a,8d6,e6,d6,16a,8c6,8c6,16c6,8d6,8e6,8g6,16e6,16d6,8c6,16g,16g#,16p,16a,16p,16d#,2d,8p,a,16c6,16g,16a,16d#6,8p,8d6,16c6,16a,8g,16a,8c6,8c6,16a,8d6,e6,d6,8a,8d6,16d#6,16e6,16p,16d6,16p,16c6,16p,16a,16p,16g,16e,16d#,2d.,p,b,b,8f#.,8g.,8a,e,g,d6,a,b,b,8f#.,8g.,8a,2e6,2a,8d#.,8a.,8d#,8d.,8g#.,8d,8g.,8f.,8c,8d#.,8g.,8c6,16d#,16f,2g,8p,g#,16a#,16f6,16f6,16f6,16f6,16p,16f6,16f6,8e6,8e6,8g6,8g6,16a6,8p,16a6,16p,16a6,16g6,16g#6,8a6,8p,8a,8p,2p");
	}
	else if(joystickGetDigital(2,5,JOY_RIGHT))
	{
		//mario GAME OVER
		speakerPlayRtttl("MGO:d=4,o=5,b=63:16c6,8p,16g,8p,16e,16p,16a.,16b.,16a.,16g#.,8a#,g#,32g.,32d.,2e,2p");
	}
	else if(joystickGetDigital(2,5,JOY_DOWN))
	{
		//SMB2 life loss
		speakerPlayRtttl("Fail:d=4,o=5,b=125:16d#6,16e6,16d#6,16e6,16c6,16g,16g#,16a,16d#6,16e6,16c6,16g,16g#,16a,16d#,16e,8c,2p");
	}
	else if(joystickGetDigital(2,5,JOY_LEFT))
	{
		//level up
		speakerPlayRtttl("LU:d=4,o=5,b=140:16e,16e,16e,8b,2p");
	}
	else if(joystickGetDigital(2,6,JOY_UP))
	{
		//1812 overture
		speakerPlayRtttl("1812:d=4,o=5,b=200:8c,16g,16g,8c6,8d6,8e6,8d6,8c6,8d6,8e6,8p,8c6,8p,c.6,8g,8c,16g,16g,8c,8d,8e,8d,8c,8d,8e,8p,8c,8p,2c,8p,16a,16a,8d6,8e6,8d6,8a,8f,8a,8d6,8a,8f,8a,d.6,8g,8c,16g,16g,8c6,8d6,8c6,8g,8e,8g,8c6,8g,8e,8g,c.6,8p,1g,2a,2a,2g.,e,1c,1c6,2b,2a,1g,2a.,p,1f,2g,2g,2e.,e,f,f#,g,a,1g,1g6,8c6,16g,16g,8c6,8d6,8e6,8d6,8c6,8d6,8c6,16g,16g,8c6,8d6,8c6,8g,8e,8g,1c.6,2p");
	}
	else if(joystickGetDigital(2,6,JOY_RIGHT))
	{
		//EVOLVE
		speakerPlayRtttl("Evolve:d=4,o=5,b=500:8c,8d,8e,8f,8g,8g#,2a.,2f.,1c.,a#,a#,a#,g,g,a#,1a.,f6,1p,1p");
	}
	else if(joystickGetDigital(2,6,JOY_DOWN))
	{
		//jeapordy
		speakerPlayRtttl("Jeapordy:d=4,o=5,b=50:8g,8c6,8g,8c,8g,8c6,8g.,16p,8g,8c6,8g,8c6,16e6,8p,16d6,16c6,16b,16a,16g#,8g,8c6,8g,16e,16f,8g,8c6,8g,8p,16c6,16p,16p,16a,16g,16p,16f,16p,16e,16p,16d,16p,16c,2p");
	}
	else if(joystickGetDigital(2,6,JOY_LEFT))
	{
		//Meta knights revenge
		speakerPlayRtttl("Meta:d=4,o=5,b=160:8e,8e,8g,8g,a,16c6,16g,16a,8d#6,16p,8d6,16c6,16a,8g,16a,8c6,8c6,16a,8d6,e6,d6,16a,8c6,8c6,16c6,8d6,8e6,8g6,16e6,16d6,8c6,16g,16g#,16p,16a,16p,16d#,2d,8p,a,16c6,16g,16a,16d#6,8p,8d6,16c6,16a,8g,16a,8c6,8c6,16a,8d6,e6,d6,8a,8d6,16d#6,16e6,16p,16d6,16p,16c6,16p,16a,16p,16g,16e,16d#,2d.,p,b,b,8f#.,8g.,8a,e,g,d6,a,b,b,8f#.,8g.,8a,2e6,2a,8d#.,8a.,8d#,8d.,8g#.,8d,8g.,8f.,8c,8d#.,8g.,8c6,16d#,16f,g.,p,g#,16a#,16f,16f,16f,16f,16p,16f,16f,16f,16f,16f,16p,p,8a6,16a,16p,16g,16a,16p,16a,16p,16a,16p,16g,16a,16c6,16d6,16d#6,8p,16d6,16p,16a,16g,16p,16d#6,16p,16d6,16p,16c6,16a,16g,16a,16g,8a,16a6,16p,16g6,16a6,16d#6,16d6,16c6,16d6,16p,16e6,16p,16a,16g,16g#,16a,16f#,16p,16e,16p,16d,8c,16e,16a,16b,8c6,16d#,16g,16a,8a#,16a#,16p,16g#,16a#,16p,16a#,16p,16a#,16p,16g#,16a#,16c#6,16d#6,16e6,8p,16d#6,16p,16a#,16g#,16p,16e6,16p,16d#6,16p,16c#6,16a#,16g#,16a#,16g#,8a#,16a#,16p,16g#,16a#,16f6,16d#6,16c#6,16d#6,16p,16f6,16p,16a#,16g#,16a,16a#,16g,16p,16f,16p,16d#,8c#,16a#,16c#6,16d#6,8e6,16f,16g,16a#,8a6,16a,16p,16g,16a,16p,16a,16p,16a,16p,16g,16a,16c6,16d6,16d#6,8p,16d6,16p,16a,8g,16d#6,16p,16d6,16p,16c6,16a,16g,16a,16c6,8a,16a6,16p,16g6,16a6,16d#6,16d6,16c6,16d6,16p,16e6,16p,16a,16g,16g#,16a,16f#,16p,16e,16p,16d,8c,16e,16a,16b,8c6,16d#,16g,16a,16a#,16f,16a#,16p,16g#,16a#,16p,16a#,16p,16a#,16p,16g#,16a#,16c#6,16d#6,16e6,8p,16d#6,16p,16a#,8g#,16e6,16p,16d#6,16p,16c#6,16a#,16g#,16c6,16c#6,16c#,16f,16a#,16p,16g#,16a#,16f6,16d#6,16c#6,16d#6,16p,16f6,16p,16a#,16g#,16a,16a#,16g,16p,16f,16p,16d#,8c#,16a#,16c#6,16d#6,8e6,16f,16g,16a#,c,c6,8g.,8g#.,8a#,f,g#,d#6,a#,c,c6,8g.,8g#.,8a#,2f6,a#,p,8e.,8a#.,8e,8d#.,8a.,8d#,8g#.,8f#.,8c#,8e.,8g#.,8c#6,16e,16f#,g#.,p,a,16b,16f#,16f#,16f#,16p,16f#,8f#,8e6,8e6,8g6,8g6,16a6,8p,2a.,8p,8a.,2a,8p,16p,16a#,16b,8c.6,2c6,8p,16p,16d6,16d#6,8e.6,2e6,8p,16p,16g6,16p,8a6,16a,16p,16c6,16p,16a,16d#6,8p,16d6,16p,16c6,16a,16g,16p,16a,16c6,16p,16c6,16p,16a,16d6,16p,2p,16c,16d#,16p,16d#,16p,16d#,16f,16p,16g,16p,16a#,16p,16g,16f,16d#,16p,16d,16e,16p,16g#,16p,16a,2b,p,8e6,16c6,16d6,16p,16e6,8p,16a,16p,8c6,16a,16p,8p,16e6,16p,16c6,16d6,16p,16e6,8p,16d#6,16p,16d6,16c6,16a,16p,8p,16g,16p,16c6,16d#6,16p,16g6,8p,16c6,16p,8d#6,16c6,16p,8p,16g6,16p,16d#6,16f6,16p,16g6,8p,8g.6,8g.6,16a6,16p,16e6,16p,16c6,16d6,16p,16e6,8p,16a,16p,8c6,16a,16p,8p,16e6,16p,16c6,16d6,16p,16e6,8p,8d#6,16d6,16c6,16a,16p,8p,8g,16c6,16d#6,16p,16g6,8p,16c6,16p,8d#6,16c6,16p,8p,16d#6,16p,16f6,8g6,8f6,16d#6,16g6,16f6,16d#6,16d6,16c6,16p,8p,16c6,16p,16c6,16d6,16p,8d#.6,16c6,16p,16a#,16c6,p,8g,16c6,16d#6,16p,8g.6,16d#6,16p,16d6,16d#6,p,16g#,16p,16b,16d#6,16p,8b.,16g#,16p,16f#,16g#,p,16g#,16p,16b,16d#6,16p,8f#.6,8d#6,16c#6,16d#6,16c#6,16b,16a#,g#,16p,16f#,16g#,8a#.,8d#.6,8a#,8c.6,8f.,8c,8e.,8f.,8g,8f.,8d.,8f,8g#.,8a.,8b,c.6,16b,16c6,8d.6,8b.,8d6,8c.6,16b,2a.,c.6,16b,16c6,8d.6,8b.,8d6,2d#.6,p,c.6,16a#,16g#,8g,8f,8d#,8f,g,8f.,16g,c,8c.,16c,2d.,8d.,16d#,2d.,16c.,16d#.,16g,c.6,16a#,16g#,8g,8f,8d#,8f,g,8f.,16g,c,c,2d.,d,2d.,8d.,16d#,d.,8d#,d.,8d#,16d,16d#,16d,16d#,16d,16d#,16d,16d#,8e,8e,8g,8g,a,16c6,16g,16a,8d#6,16p,8d6,16c6,16a,8g,16a,8c6,8c6,16a,8d6,e6,d6,16a,8c6,8c6,16c6,8d6,8e6,8g6,16e6,16d6,8c6,16g,16g#,16p,16a,16p,16d#,2d,8p,a,16c6,16g,16a,16d#6,8p,8d6,16c6,16a,8g,16a,8c6,8c6,16a,8d6,e6,d6,8a,8d6,16d#6,16e6,16p,16d6,16p,16c6,16p,16a,16p,16g,16e,16d#,2d.,p,b,b,8f#.,8g.,8a,e,g,d6,a,b,b,8f#.,8g.,8a,2e6,2a,8d#.,8a.,8d#,8d.,8g#.,8d,8g.,8f.,8c,8d#.,8g.,8c6,16d#,16f,2g,8p,g#,16a#,16f,16f,16f,16f,16p,16f,16f,8e,8e,8g,8g,16a,8p,16a,16p,16a,16g,16g#,8a,2p");
	}
	else if(joystickGetDigital(2,7,JOY_UP))
	{
		//Dr.Wily's theme
		speakerPlayRtttl("Wily:d=4,o=5,b=180:8c,16d#,16d#,8d#,16d#,16d#,8d#,8c,8p,16c,16c,8d#,16d#,16d#,8d#,8c,8p,8g,8f,8g,8p,16d#,16d#,8d#,16d#,16d#,8d#,8c,8p,8g,8p,8f,8p,8d#,8p,8f,p,8p,16f,16f,8f,16f,16f,8f,8d,8p,8g,8p,8f,8p,8d#,8p,8d,8p,8c,8c,8c,8g,8a#,a.,8c,8c,8c,8g,8a#,a,8a#,8c6,8p,16d#,16d#,8d#,16d#,16d#,8d#,8c,8p,16c,16c,8d#,16d#,16d#,8d#,8c,8p,8g,8f,8g,8p,16d#,16d#,8d#,16d#,16d#,8d#,8c,8p,8g,8p,8f,8p,8d#,8p,8f,p, 8p,16f,16f,8f,16f,16f,8f,8d,8p,8g,8p,8f,8p,8d#,8p,8d,8p,8c,8c,8c,8g,8a#,a.,8c,8c,8c,8g,8a#,a,8a#,2c.6,8p,8a#,d#6,c6,a#,c.6,2a#,8a#,c.6,8g,8g#,8g,8g#,8g,8d#,8g,8a#,2c.6,8a#,d#6,c6,a#,c.6,2a#,8a#,8g,8a#,b,8b,8b,8d6,g6,p,2g.,8f,a#,g#,g,g#,2g.,8p,8f,a#,g#,g,g#,d#.,p,8d#,8f,8g,1d,8c,8c,8c,8g,8a#,a.,8c,8c,8c,8g,8a#,a, 8a#,2c6,8p,c6,8a#,c6,d#.6,8g6,8f6,8d#6,8d6,2c6,c6,8a#,c6,d#.6,8d#6,8f6,d#6,2d6,8d6,8c6,8a#,g.6,f6,d#6,d6,8d6,8d#6,8d6,2c6,8c,8c,8c,8g,8a#,a.,8a#,2c.6,8a#,d#6,c6,a#,c.6,2a#,8a#,c.6,8g,8g#,8g,8d#,8c,8d#,8g,8a#,2c.6,8a#,d#6,c6,a#,c.6,2a#,8a#,8g,8a#,b,8b,8b,8d6,g6,8p,8d#,8p,8d#,8d#,8d,d#,8c6,a#,g#,g,f,8f,8p,8g,8g,8p,8g,p,8f,8p,8g,8g,8p,8g,8p,8f,8d#,8p,8d#,8d#,8d,d#,8c6,a#,g#,g,f,8p,8d,8d#,8d,1c.,p,16d#,16d#,8d#,16d#,16d#,8d#,8c,8p,16c,16c,8d#,16d#,16d#,8d#,8c,8p,8g,8f,8g,8p,16d#,16d#,8d#,16d#,16d#,8d#,8c,8p,8g,8p,8f,8p,8d#,8p,8f,p,8p,16f,16f,8f,16f,16f,8f,8d,8p,8g,8p,8f,8p,8d#,8p,8d,8p,8c,8c,8c,8g,8a#,a.,8c,8c,8c,8g,8a#,a,8a#,8c6,2p");
	}
	else if(joystickGetDigital(2,7,JOY_DOWN))
	{
		//DeDeDe's theme
		speakerPlayRtttl("DDD:d=4,o=5,b=180:16d#,16e,16f,16f#,16g,16g#,16a,16a#,16b,16c6,16c#6,16d6,16d#6,16e6,16f6,16f#6,8a#6,g6,8a#6,g6,8a#6,g6,8p,p,2p,d#6,c6,8p,8a#,8c6,d#6,c.6,8p,8f6,g6,16d#6,16d6,c6,p,8g,8d#6,c6,8a#,c6,8a#,c6,8a#,8f6,d#.6,8p,8f6,d#6,8c6,d#6,8c6,8d#6,8f6,8f#6,8g6,8a#6,g6,2p,8a#6,8g6,2p,8a#6,g.6,d#6,c6,8p,8a#,8c6,d#6,c.6,8p,8f6,g6,16d#6,16d6,c6,p,8g,8d#6,c6,8a#,c6,8a#,c6,8a#,8f6,d#.6,8p,8f6,d#6,8c6,d#6,8c6,8d#6,8f6,8f#6,8g6,8a#,g.,p,8a#,g.,p,8a#,g,16p,16a#,8c6,8c6,8c6,8d6,8d#6,8d#6,8d6,8c6,8a#,c6,g.,p,8c6,8c6,8c6,8d6,8d#6,8d#6,8f6,8d#6,8f6,g6,2g6,16d#6,16d6,8c6,8c6,8c6,8d6,8d#6,8d#6,8d6,8c6,8a#,c6,2g,16g,16a#,8c6,8c6,8c6,8d6,8c6,8c6,8a#,8g,8f,g,2c,8p,d.6,16c6,16d6,8a#.,8a.,8f,8d#.,16f,2g,8p,16c6,16c#6,d.6,16c6,16d6,8a#.,8a.,8f,2c6,8p,8e.,8g.,c.6,16a#,16g#,8g.,8f.,8g,a#.,16g#,16g,8f.,8d#,8f.,8d.,16g,2g.,b.,g,b.,8d#6,8c6,8p,c6,g6,16d#6,16d6,8c6,8c6,8a#,8c6,2p");
	}
	else if(joystickGetDigital(2,8,JOY_UP))
	{
		//DK 25m theme
		speakerPlayRtttl("DK1:d=4,o=5,b=200:8a#,p,8d6,8p,8f6,8g6,8f6,8a#,p,8d6,8p,8f6,8g6,8f6,8a#,p,8d6,8p,8f6,8g6,8f6,8a#,p,8d6,8p,8f6,8g6,8f6,8a#,p,8d6,8p,8f6,8g6,8f6,8a#,p,8d6,8p,8f6,8g6,8f6");
		speakerPlayRtttl("DKe:d=4,o=5,b=200:8a#,p,8d6,8p,8f5,8g6,8f6,8a#");
	}
	else if(joystickGetDigital(2,8,JOY_DOWN))
	{
		//
		speakerPlayRtttl("Gerudo:d=4,o=5,b=125:16c,16g,16a#,8c#6,8f,8g#,16e,16g,16a#,c6,16c,16c,16c,8c,8c,16c,16c,16c,16c,8c,8p,16p,16f,16f,16c,16f,16p,16f,16p,16c,16f,16f,16c,16f,16p,16f,16p,16c,16f,16f,16c#,16f,16p,16f,16p,16c#,16f,16c#,16d#,16f,16p,16f,16p,16g#,16g,16d#,16d#,16g,16p,16a#,16p,16g#,16g,16d#,16d#,16g,p,16f,16f,16c,16f,16p,16c,16f,2e,16p,16f,16p,16c,16f,16p,16c,16f,16g,g#,d#,8c#,16f,16p,16f,16p,16c#,16f,16p,16c#,8f,16c#,16f,16c#,16f,16d#,16d#,16g,16p,16a#,16p,16g#,16g,16d#,16d#,16g,p,8g#,8f,8g#.,8g#,16g#,16g#,16g#,2g,16p,16c,16f,16g,8g#.,16c,16f,16g,g#,8p,16c#,16f,16g,8g#.,16c#,16f,16p,16g,g#,8p,16a#,16d#,16f,8g.,16a#,16d#,16f,g.,16p,16f,16g,16f,e,16e,16e,16e,16e,32e,32e,32e,32e,32e,32e,32e,32e,16p,16c,16f,16g,8g#.,16c,16f,16g,g#.,16p,16c#,16f,16g,8g#.,16c#,16f,16c#,16g,c6,8p,16a#,16d#,16f,8g.,16a#,16d#,16f,a#.,16p,16g#,16a#,16g#,g,16g,16g,16g,16g,32g,32g,32g,32g,32g,32g,32g,32g,8p,16a#,8c6,16g6,8g#6,32g6,32g#6,8g6,8f.6,8c6,d#6,16d#6,16f6,16d#6,2c#6,16p,8p,16g#,8a#,8g.6,8f.6,8d#.6,8c#6,c6,16c#6,16d#6,16c#6,2c6,16p,8p,16a#,8c6,16g6,8g#6,32g6,32g#6,8g6,8f.6,8c6,d#6,16d#6,16f6,16d#6,c#.6,16p,8a#,a#.,16d#6,16f6,d#.6,8c#6,c.6,16c6,16c6,2c6,8p,16f,16g,16g#,16c6,8p,16f,16g,16g#,8c.6,p,16f,16g,16g#,16c#6,8p,16f,16g,16g#,8c#.6,8p,a#.,16f6,16g6,f.6,8a#,2c6,2e,8f,16g#,8g.,8g#,8f,16g#,8g.,8g#,8c#,16g#,16f,8g,8g#,8c#,16g#,16f,8g,8g#,8d#,16a#,8a.,8a#,8d#,16a#,8a.,8a#,8p,16c#6,16d#6,16c#6,8c.6,2p,16f,16f,16c,16f,16p,16f,16p,16c,16f,16f,16c,16f,16p,16f,16p,16c,16f,16f,16c#,16f,16p,16f,16p,16c#,16f,16c#,16d#,16f,16p,16f,16p,16g#,16g,16d#,16d#,16g,16p,16a#,16p,16g#,16g,16d#,16d#,16g,p,16f,16f,16c,16f,16p,16c,16f,2e,p,16p,16c,16f,16g,32g#,32a#,8g#.,8g,8f,p,16p,16c#,16f,16g,32g#,32a#,8g#.,8g,8f,p,16p,16a#,16d#,16f,8g,8g#,8a#,c.6,32c6,32c#6,16c6,16a#,16g#,16g,16e,16f,16g,16g#,16a#,16c6,16c#6,16p,16c,16f,16g,8g#,16c,16f,16g,16g#,16a#,16c6,32f6,32g6,16f6,16a#,16g#,16p,16c#,16f,16g,8g#,16c#,16f,32g,32g#,16g,16a#,16c6,16f6,16c6,16a#,16g#,16p,16a#,16d#,16f,32g,32g#,16g,16a#,16d#,16f,16g,16g#,16a#,16c6,16a#,16g#,16g,16g#,16c,16d,16e,32f,32g,16f,16a#,16g#,16g,16e,16f,16g,16g#,16a#,16c6,16c#6,16p,16c,16f,16g,8g#.,16c,16f,16g,g#.,16p,16c#,16f,16g,8g#.,16c#,16f,16p,16g,g#,8p,16a#,16d#,16f,8g.,16a#,16d#,16f,g.,16p,16f,16g,16f,e,16e,16e,16e,16e,32e,32e,32e,32e,32e,32e,32e,32e,16p,16c,16f,16g,8g#.,16c,16f,16g,g#.,16p,16c#,16f,16g,8g#.,16c#,16f,16c#,16g,c6,8p,16a#,16d#,16f,8g.,16a#,16d#,16f,a#.,16p,16g#,16a#,16g#,g,16g,16g,16g,16g,32g,32g,32g,32g,32g,32g,32g,32g,8p,16f,16g,16g#,16c6,8p,16f,16g,16g#,8c.6,p,16f,16g,16g#,16c#6,8p,16f,16g,16g#,8c#.6,8p,a#.,16f6,16g6,f.6,8a#,2c.6,e,2f.,32g#,32a#,8g.,2g#.,c6,1a#,8p,16c#6,16d#6,16c#6,8c.6,16c6,16c6,16c6,32g,32c6,32g,32e,32g,32c6,32g,32e,32g,16c6,1f6");
	}*/
	lcdPrint(uart1,1,"%d",ARMpos);
	delay(20);
}

/*
 * Button functions:
 * joy:1,btn_grp:8,btn:UP = Forward at full power.
 * joy:1,btn_grp:8,btn:DOWN = Backward at full power.
 * joy:1,btn_grp:7,btn:RIGHT = Turn Right at full power.
 * joy:1,btn_grp:7,btn:LEFT = Turn Left at full power.
 * joy:1,btn_grp:8,btn:RIGHT = Strafe Right at full power.
 * joy:1,btn_grp:8,btn:LEFT = Strafe Left at full power.
 * joy:1,btn_grp:5,btn:UP = Arm up at full power.
 * joy:1,btn_grp:5,btn:DOWN = Arm down at full power
 * joy:1,btn_grp:6,btn:UP = Claw set to closed.
 * joy:1,btn_grp:6,btn:DOWN = Claw set to open.
 */
void digitalDrive()
{

	/*int forward = joystickGetDigital(1, 8, JOY_UP);
	int backward = joystickGetDigital(1, 8, JOY_DOWN);
	int turnRight = joystickGetDigital(1, 7, JOY_RIGHT);
	int turnLeft = joystickGetDigital(1, 7, JOY_LEFT);
	int strafeRight = joystickGetDigital(1, 8, JOY_RIGHT);
	int strafeLeft = joystickGetDigital(1, 8, JOY_LEFT);
	int all = forward + backward + turnRight + turnLeft + strafeRight + strafeLeft;*/
	if (joy1_channel8 == 1)
		opstraight();
	else if (joy1_channel8 == 2)
		opback();
	else if (joy1_channel8 == 4)
		opturnRight();
	else if (joy1_channel8 == 8)
		opturnLeft();
	else if (joy1_channel7 == 4)
		opstrafeRight();
	else if (joy1_channel7 == 8)
		opstrafeLeft();
	else
		opdriveStop();

	if(joy1_channel5==1)
		armUp(127);
	else if(joy1_channel5==2)
		armDown(127);
	else
		armStop();

	if(joy1_channel6==1)
		clawSet(1);
	else if(joy1_channel6==2)
		clawSet(0);

	if(joy1_channel7==8)
		rotSet(1);
	else if(joy1_channel7==4)
		rotSet(0);

	//printIMEVelocity();
	delay(20);
}

