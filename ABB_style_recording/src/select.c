#include"main.h"	

/*
 * Leave this value alone.
 */
int lcdScreenMin = 1;

/*
 * Change this value to be the maximum number of programs you want on the robot
 */
int lcdScreenMax = 5;
/*
 * Returns integer cooresponding to the autonomous Program to be executed.
 * This function can only and should only be run in the initialization stage while the robot is
 * disabled.
 * Button functions:
 * Center-select
 * right-scroll right
 * left-scroll left
 */
int autoSelect() {
	int lcdScreen = 1;
	delay(1000);
	while (isEnabled() == 0) { //Ensures this code will run ONLY when the robot is disabled
		if (lcdReadButtons(uart1 ) == 1) { //Scrolls to the left
			if (lcdScreenMin == lcdScreen) {
				lcdScreen = lcdScreenMax;
				delay(250);
			} else {
				lcdScreen--;
				delay(250);
			}
		}
		if (lcdReadButtons(uart1 ) == 4) { //Scrolls to the right
			if (lcdScreenMax == lcdScreen) {
				lcdScreen = lcdScreenMin;
				delay(250);
			} else {
				lcdScreen++;
				delay(250);
			}
		}

		if (lcdScreen == 1) {
			lcdPrint(uart1, 1, "Red"); //Name the first program here
			lcdPrint(uart1, 2, " 0"); //Name the first program here
			if (lcdReadButtons(uart1 ) == 2) {
				lcdPrint(uart1, 1, "Autonomous Has");
				lcdPrint(uart1, 2, "Been Selected!");
				return lcdScreen;
				delay(1500);
			}
		} else if (lcdScreen == 2) {
			lcdPrint(uart1, 1, "blue"); //Name the second program here
			lcdPrint(uart1, 2, " 0"); //Name the second program here
			if (lcdReadButtons(uart1 ) == 2) {
				lcdPrint(uart1, 1, "Autonomous Has");
				lcdPrint(uart1, 2, "Been Selected!");
				return lcdScreen;
				delay(1500);
			}
		} else if (lcdScreen == 3) {
			lcdPrint(uart1, 1, "Red"); //Name the third program here
			lcdPrint(uart1, 2, " 1"); //Name the third program here
			if (lcdReadButtons(uart1 ) == 2) {
				lcdPrint(uart1, 1, "Autonomous Has");
				lcdPrint(uart1, 2, "Been Selected!");
				return lcdScreen;
				delay(1500);
			}
		} else if (lcdScreen == 4) {
			lcdPrint(uart1, 1, "blue"); //Name the fourth program here
			lcdPrint(uart1, 2, " 1"); //Name the fourth program here
			if (lcdReadButtons(uart1 ) == 2) {
				lcdPrint(uart1, 1, "Autonomous Has");
				lcdPrint(uart1, 2, "Been Selected!");
				return lcdScreen;
				delay(1500);
			}
		} else if (lcdScreen == 5) {
			lcdPrint(uart1, 1, "no"); //Name the fifth program here
			lcdPrint(uart1, 2, "auto"); //Name the fifth program here
			if (lcdReadButtons(uart1 ) == 2) {
				lcdPrint(uart1, 1, "Autonomous Has");
				lcdPrint(uart1, 2, "Been Selected!");
				return lcdScreen;
				delay(1500);
			}
		}
		delay(20);
	}
	return 1;
}

/*
 * Returns integer cooresponding to the drive routine to be executed.
 * This function can only and should only be run in the initialization stage while the robot is
 * disabled.
 * Button functions:
 * Center-select
 * right-scroll right
 * left-scroll left
 */
int driveSelect() {
	int lcdScreen = 1;
	delay(1000);
	while (isEnabled() == 0) { //Ensures this code will run ONLY when the robot is disabled
		if (lcdReadButtons(uart1 ) == 1) { //Scrolls to the left
			if (lcdScreenMin == lcdScreen) {
				lcdScreen = lcdScreenMax;
				delay(250);
			} else {
				lcdScreen--;
				delay(250);
			}
		}
		if (lcdReadButtons(uart1 ) == 4) { //Scrolls to the right
			if (lcdScreenMax == lcdScreen) {
				lcdScreen = lcdScreenMin;
				delay(250);
			} else {
				lcdScreen++;
				delay(250);
			}
		}

		if (lcdScreen == 1) {
			lcdPrint(uart1, 1, "game"); //Name the first program here
			lcdPrint(uart1, 2, "routine"); //Name the first program here
			if (lcdReadButtons(uart1 ) == 2) {
				lcdPrint(uart1, 1, "Drive Has");
				lcdPrint(uart1, 2, "Been Selected!");
				return lcdScreen;
				delay(1500);
			}
		} else if (lcdScreen == 2) {
			lcdPrint(uart1, 1, "red_0"); //Name the second program here
			lcdPrint(uart1, 2, "record"); //Name the second program here
			if (lcdReadButtons(uart1 ) == 2) {
				lcdPrint(uart1, 1, "Drive Has");
				lcdPrint(uart1, 2, "Been Selected!");
				return lcdScreen;
				delay(1500);
			}
		} else if (lcdScreen == 3) {
			lcdPrint(uart1, 1, "blue_0"); //Name the third program here
			lcdPrint(uart1, 2, "record"); //Name the third program here
			if (lcdReadButtons(uart1 ) == 2) {
				lcdPrint(uart1, 1, "Drive Has");
				lcdPrint(uart1, 2, "Been Selected!");
				return lcdScreen;
				delay(1500);
			}
		} else if (lcdScreen == 4) {
			lcdPrint(uart1, 1, "red_1"); //Name the fourth program here
			lcdPrint(uart1, 2, "record"); //Name the fourth program here
			if (lcdReadButtons(uart1 ) == 2) {
				lcdPrint(uart1, 1, "Drive Has");
				lcdPrint(uart1, 2, "Been Selected!");
				return lcdScreen;
				delay(1500);
			}
		} else if (lcdScreen == 5) {
			lcdPrint(uart1, 1, "blue_1"); //Name the fifth program here
			lcdPrint(uart1, 2, "record"); //Name the fifth program here
			if (lcdReadButtons(uart1 ) == 2) {
				lcdPrint(uart1, 1, "Drive Has");
				lcdPrint(uart1, 2, "Been Selected!");
				return lcdScreen;
				delay(1500);
			}
		}
		delay(20);
	}
	return 1;
}
/*
 * Returns integer cooresponding to the point type to be recorded.
 * This function can run at any time but should only be run during a recording routine to save
 * point as the correct type.
 * Button functions:
 * Center-select
 * right-scroll right
 * left-scroll left
 */
void lcdselect() {
	lcdInit(uart1 );
	lcdSetBacklight(uart1, true);
	while (isEnabled(0)) { //Ensures this code will run ONLY when the robot is disabled
		if (lcdReadButtons(uart1 ) == 1) { //Scrolls to the left
			if (lcdScreenMin == lcdScreen) {
				lcdScreen = lcdScreenMax;
				delay(250);
			} else {
				lcdScreen--;
				delay(250);
			}
		}
		if (lcdReadButtons(uart1 ) == 4) { //Scrolls to the right
			if (lcdScreenMax == lcdScreen) {
				lcdScreen = lcdScreenMin;
				delay(250);
			} else {
				lcdScreen++;
				delay(250);
			}
		}

		if (lcdScreen == 1 && autonProgram != 1) {
			lcdPrint(uart1, 1, "Red"); //Name the first program here
			lcdPrint(uart1, 2, "score"); //Name the first program here
			if (lcdReadButtons(uart1 ) == 2) {
				autonProgram = lcdScreen; //Sets the Program to the one on-screen
				lcdPrint(uart1, 1, "Autonomous Has");
				lcdPrint(uart1, 2, "Been Selected!");
				autonSelectDone = true;
				delay(1500);
			}
		}

		else if (lcdScreen == 2 && autonProgram != 2) {
			lcdPrint(uart1, 1, "blue"); //Name the second program here
			lcdPrint(uart1, 2, "score"); //Name the second program here
			if (lcdReadButtons(uart1 ) == 2) {
				autonProgram = lcdScreen; //Sets the Program to the one on-screen
				lcdPrint(uart1, 1, "Autonomous Has");
				lcdPrint(uart1, 2, "Been Selected!");
				autonSelectDone = true;
				delay(1500);
			}
		}

		else if (lcdScreen == 3 && autonProgram != 3) {
			lcdPrint(uart1, 1, "red "); //Name the third program here
			lcdPrint(uart1, 2, "hang"); //Name the third program here
			if (lcdReadButtons(uart1 ) == 2) {
				autonProgram = lcdScreen; //Sets the Program to the one on-screen
				lcdPrint(uart1, 1, "Autonomous Has");
				lcdPrint(uart1, 2, "Been Selected!");
				autonSelectDone = true;
				delay(1500);
			}
		}

		else if (lcdScreen == 4 && autonProgram != 4) {
			lcdPrint(uart1, 1, "blue"); //Name the fourth program here
			lcdPrint(uart1, 2, "hang"); //Name the fourth program here
			if (lcdReadButtons(uart1 ) == 2) {
				autonProgram = lcdScreen; //Sets the Program to the one on-screen
				lcdPrint(uart1, 1, "Autonomous Has");
				lcdPrint(uart1, 2, "Been Selected!");
				autonSelectDone = true;
				delay(1500);
			}
		}

		else if (lcdScreen == 5 && autonProgram != 5) {
			lcdPrint(uart1, 1, "no"); //Name the fourth program here
			lcdPrint(uart1, 2, "auto"); //Name the fourth program here
			if (lcdReadButtons(uart1 ) == 2) {
				autonProgram = lcdScreen; //Sets the Program to the one on-screen
				lcdPrint(uart1, 1, "Autonomous Has");
				lcdPrint(uart1, 2, "Been Selected!");
				autonSelectDone = true;
				delay(1500);
			}
		}
	}
	/*while(isEnabled(0)&&driveSelectDone==false)
	 {
	 if (lcdReadButtons(uart1 ) == 1) { //Scrolls to the left
	 if (lcdScreenMin == lcdScreen) {
	 lcdScreen = lcdScreenMax;
	 delay(250);
	 } else {
	 lcdScreen --;
	 delay(250);
	 }
	 }
	 if (lcdReadButtons(uart1 ) == 4) { //Scrolls to the right
	 if (lcdScreenMax == lcdScreen) {
	 lcdScreen = lcdScreenMin;
	 delay(250);
	 } else {
	 lcdScreen++;
	 delay(250);
	 }
	 }




	 if (lcdScreen == 1 && driveProgram != 1)
	 {
	 lcdPrint(uart1, 1, "standard"); //Name the first program here
	 lcdPrint(uart1, 2, "drive"); //Name the first program here
	 if (lcdReadButtons(uart1 ) == 2)
	 {
	 driveProgram = lcdScreen; //Sets the Program to the one on-screen
	 lcdPrint(uart1, 1, "Drive Has");
	 lcdPrint(uart1, 2, "Been Selected!");
	 driveSelectDone = true;
	 delay(1500);
	 }
	 }







	 else if (lcdScreen == 2 && driveProgram != 2)
	 {
	 lcdPrint(uart1, 1, "redscore"); //Name the second program here
	 lcdPrint(uart1, 2, "record"); //Name the second program here
	 if (lcdReadButtons(uart1 ) == 2)
	 {
	 driveProgram = lcdScreen; //Sets the Program to the one on-screen
	 lcdPrint(uart1, 1, "Drive Has");
	 lcdPrint(uart1, 2, "Been Selected!");
	 driveSelectDone = true;
	 delay(1500);
	 }
	 }






	 else if (lcdScreen == 3 && driveProgram != 3)
	 {
	 lcdPrint(uart1, 1, "bluescore"); //Name the third program here
	 lcdPrint(uart1, 2, "record"); //Name the third program here
	 if (lcdReadButtons(uart1 ) == 2)
	 {
	 driveProgram = lcdScreen; //Sets the Program to the one on-screen
	 lcdPrint(uart1, 1, "Drive Has");
	 lcdPrint(uart1, 2, "Been Selected!");
	 driveSelectDone = true;
	 delay(1500);
	 }





	 else if (lcdScreen == 4 && driveProgram != 4)
	 {
	 lcdPrint(uart1, 1, "redhang"); //Name the fourth program here
	 lcdPrint(uart1, 2, "record"); //Name the fourth program here
	 if (lcdReadButtons(uart1 ) == 2)
	 {
	 driveProgram = lcdScreen; //Sets the Program to the one on-screen
	 lcdPrint(uart1, 1, "Drive Has");
	 lcdPrint(uart1, 2, "Been Selected!");
	 driveSelectDone = true;
	 delay(1500);
	 }
	 } 





	 else if (lcdScreen == 5 && driveProgram != 5)
	 {
	 lcdPrint(uart1, 1, "bluehang"); //Name the fourth program here
	 lcdPrint(uart1, 2, "record"); //Name the fourth program here
	 if (lcdReadButtons(uart1 ) == 2)
	 {
	 autonProgram = lcdScreen; //Sets the Program to the one on-screen
	 lcdPrint(uart1, 1, "drive Has");
	 lcdPrint(uart1, 2, "Been Selected!");
	 autonSelectDone = true;
	 delay(1500);
	 }
	 }

	 }
	 }*/
}




int pointWriteSelect() {
	int lcdScreen = 1;
	int lcdScreenMax1 = 6;
	while (true) { //Ensures this code will run ONLY when the robot is disabled
		if (joy2_channel8 == 8) { //Scrolls to the left
			if (lcdScreenMin == lcdScreen) {
				lcdScreen = lcdScreenMax1;
				delay(250);
			} else {
				lcdScreen--;
				delay(250);
			}
		}
		if (joy2_channel8 == 4) { //Scrolls to the right
			if (lcdScreenMax1 == lcdScreen) {
				lcdScreen = lcdScreenMin;
				delay(250);
			} else {
				lcdScreen++;
				delay(250);
			}
		}

		if (lcdScreen == 1) {
			lcdPrint(uart1, 1, "point type"); //Name the first point type here
			lcdPrint(uart1, 2, "turn"); //Name the first point type here
			if (joy2_channel8 == 2) {
				lcdPrint(uart1, 1, "Turn Point");
				lcdPrint(uart1, 2, "Selected!");
				return lcdScreen;
				delay(1500);
			}
		} else if (lcdScreen == 2) {
			lcdPrint(uart1, 1, "point type"); //Name the second point type here
			lcdPrint(uart1, 2, "straight"); //Name the second point type here
			if (joy2_channel8 == 2) {
				lcdPrint(uart1, 1, "Straight Point");
				lcdPrint(uart1, 2, "Selected!");
				return lcdScreen;
				delay(1500);
			}
		} else if (lcdScreen == 3) {
			lcdPrint(uart1, 1, "point type"); //Name the third point type here
			lcdPrint(uart1, 2, "arm"); //Name the third point type here
			if (joy2_channel8 == 2) {
				lcdPrint(uart1, 1, "Arm Point");
				lcdPrint(uart1, 2, "Selected!");
				return lcdScreen;
				delay(1500);
			}
		} else if (lcdScreen == 4) {
			lcdPrint(uart1, 1, "point type"); //Name the fourth point type here
			lcdPrint(uart1, 2, "claw"); //Name the fourth point type here
			if (joy2_channel8 == 2) {
				lcdPrint(uart1, 1, "Claw Point");
				lcdPrint(uart1, 2, "Selected!");
				return lcdScreen;
				delay(1500);
			}
		} else if (lcdScreen == 5) {
			lcdPrint(uart1, 1, "point type"); //Name the fifth point type here
			lcdPrint(uart1, 2, "func"); //Name the fifth point type here
			if (joy2_channel8 == 2) {
				lcdPrint(uart1, 1, "Func Point");
				lcdPrint(uart1, 2, "Selected!");
				return lcdScreen;
				delay(1500);
			}
		} else if (lcdScreen == 6) {
			lcdPrint(uart1, 1, "cancel"); //Name the sixth point type here
			lcdPrint(uart1, 2, "point"); //Name the sixth point type here
			if (joy2_channel8 == 2) {
				lcdPrint(uart1, 1, "point");
				lcdPrint(uart1, 2, "Canceled!");
				return lcdScreen;
				delay(1500);
			}
		}
		delay(20);
	}
	return 6;
}







