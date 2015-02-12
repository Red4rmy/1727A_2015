/** @file main.h
 * @brief Header file for global functions
 * 
 * Any experienced C or C++ programmer knows the importance of header files. For those who
 * do not, a header file allows multiple files to reference functions in other files without
 * necessarily having to see the code (and therefore causing a multiple definition). To make
 * a function in "opcontrol.c", "auto.c", "main.c", or any other C file visible to the core
 * implementation files, prototype it here.
 *
 * This file is included by default in the predefined stubs in each VEX Cortex PROS Project.
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

#ifndef MAIN_H_

// This prevents multiple inclusion, which isn't bad for this file but is good practice
#define MAIN_H_

#include <API.h>

// Allow usage of this file in C++ programs
#ifdef __cplusplus
extern "C" {
#endif

// A function prototype looks exactly like its declaration, but with a semicolon instead of
// actual code. If a function does not match a prototype, compile errors will occur.

// Prototypes for initialization, operator control and autonomous

/**
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost, the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if																																																																																																											q!~~~~~qq~Q1`!!~!!!~ called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */
void autonomous();
/**
 * Runs pre-initialization code. This function will be started in kernel mode one time while the
 * VEX Cortex is starting up. As the scheduler is still paused, most API functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes (pinMode()) and port
 * states (digitalWrite()) of limit switches, push buttons, and solenoids. It can also safely
 * configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
 */
void initializeIO();
/**
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
void initialize();
/**
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */
void operatorControl();



//movement commands See declaration
void turnRight(int power);   void opturnRight();
void turnLeft(int power);    void opturnLeft();
void forward(int power);     void opstraight();
void backward(int power);    void opback();
                             void opdriveStop();
void strafeRight(int power); void opstrafeRight();
void strafeLeft(int power);  void opstrafeLeft();
void armUp(int power);
void armDown(int power);
void armStop();

//autonomous and driver assist functions
bool turnRightTo(int degrees);//See declaration
bool turnLeftTo(int degrees);//See declaration
void driveToPID(int targetRB,int targetLB,int targetRF, int targetLF);//See declaration
void clawSet(bool state);//See declaration
void rotSet(bool state);
void armSet(int target);//See declaration
void skyFind();//See declaration
void skySection(int height);//see declaration


/*
 * A single point in the autonomous routine.
 * integer turn: the amount of turn in degrees.
 * integer rb: the raw # of clicks of rotation in the Right back wheel.
 * integer lb: the raw # of clicks of rotation in the Left back wheel.
 * integer rf: the raw # of clicks of rotation in the Right front wheel.
 * integer lf: the raw # of clicks of rotation in the Left front wheel.
 * integer arm: the raw angle between the arms in potentiometer values.
 * integer type: the integer which corresponds to the type of point recorded.
 * bool claw: the boolean value of the claw; true-closed; false-open;
 * integer func: the integer which corresponds to the type of function used in this point.
 */
typedef struct point {
	int turn;
	int rb;
	int lb;
	int rf;
	int lf;
	int arm;
	int type;
	bool claw;
	int func;
} point;
//Leave this value alone.
extern int lcdScreenMin;
//This keeps track of which program you want to run.
extern int lcdScreen;
//Change this value to be the maximum number of programs you want on the robot.
extern int lcdScreenMax;
//This is the final auton selection variable.
extern int autonProgram;
//this is the final drive selection variable.
extern int driveProgram;
extern bool autonSelectDone;
extern bool driveSelectDone;

//selection functions.
int autoSelect();
int driveSelect();
int pointWriteSelect();

//Looped task functions.
void getSensors();
void sensorDebug();
void getJoystickValues();

//point writing functions.
point turnPointWrite(int turn);//See declaration
point straightPointWrite(int rf,int lf, int rb, int lb);//See declaration
point armPointWrite(int arm);//See declaration
point clawPointWrite(bool claw);//See declaration
//Read out and playback of a single point aPoint.
void playPoint(point aPoint);//See declaration

//control types
void gameControl();
void digitalDrive();

// function which is used to return a single point.
point recordPoint();

//drive routines.
void gameRoutine();//Fully driver (or driver assist) controlled routine; Run this when competeing
void recordRed_0();
void recordRed_1();
void recordBlue_0();
void recordBlue_1();


//songs
void songTask();

/*
 * prints IME velocity values to the LCD screen.
 */
void printIMEVelocity();

//Sensor variable.
extern Gyro gyroYaw;// Gyroscopic sensor which is used to measure yaw.
extern Ultrasonic skyFind1;//Ultrasonic sensor which is used to find the skyrise peice.

//Sensor return variables
extern int RFcount;
extern int RBcount;
extern int LFcount;
extern int LBcount;
extern double RFvel;
extern double RBvel;
extern double LFvel;
extern double LBvel;
extern int ARMpos;
extern int SKYdist;
extern int frontAngle;


/*
 * Live updated joystick values
 * Digital Ports 5 and 6:
 *  0: none
 *  1: up
 *  2: down
 *  3: both
 * Digital Ports 7 and 8:
 * 	0: none
 * 	1:  up
 * 	2:  down
 * 	3:  up+down
 * 	4:  right
 * 	5:  right+up
 * 	6:  right+down
 * 	7:  right+up+down
 * 	8:  left
 * 	9:  left+up
 * 	10: left+down
 * 	11: left+up+down
 * 	12: left+right
 * 	13: left+right+up
 * 	14: left+right+down
 * 	15: left+right+up+down
 */
extern int joy1_channel1;
extern int joy1_channel2;
extern int joy1_channel3;
extern int joy1_channel4;
extern int joy2_channel1;
extern int joy2_channel2;
extern int joy2_channel3;
extern int joy2_channel4;
extern int joy1_channel5;
extern int joy1_channel6;
extern int joy1_channel7;
extern int joy1_channel8;
extern int joy2_channel5;
extern int joy2_channel6;
extern int joy2_channel7;
extern int joy2_channel8;

//TaskHandle variables for tasks
extern TaskHandle debug;
extern TaskHandle sensor;

//Variables used in the saving of the string of points to RAM
extern point *input;//pointer to the string of input points.
extern int steps;//# of steps beginning in the *input memory location.

//Integer values corresponding to the autonomous routines to execute.
#define RED_0     1
#define BLUE_0    2
#define RED_1     3
#define BLUE_1    4
#define NOAUTO    5

//Integer values corresponding to the drive routines to execute.
#define GAME      1
#define R_RED_0   2
#define R_BLUE_0  3
#define R_RED_1   4
#define R_BLUE_1  5

//Integer values cooresponding to the type of point represented.
#define type_turn      0
#define type_straight  1
#define type_arm       2
#define type_claw      3
#define type_func      4

//Integer value cooresponding to IME address for each wheel.
#define imeRB    0
#define imeLB    3
#define imeRF    1
#define imeLF    2

//MOTOR AND PIN VALUES FOR EACH ACTUATOR.
#define RB       1
#define RF       2
#define LB       10
#define LF       9
#define LIFT_RO  3
#define LIFT_RI  8
#define LIFT_LI  4
#define LIFT_LO  7
#define LIFT_RS  5
#define LIFT_LS  6
#define CLAW_PIN 12
#define ARM_PIN  11

//potentiometer pin

#define ARM_POS 1

//Integer value cooresponding to the function to be executed.
#define SKYFIND  0

// End C++ export structure
#ifdef __cplusplus
}
#endif

#endif
