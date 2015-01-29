/*
 * autoRoutines.c
 *
 *  Created on: Nov 10, 2014
 *      Author: Anton
 */
#include"main.h"





/*
 * Infinite routine: use for competitions.
 */
void gameRoutine()
{
	//taskCreate(songTask,TASK_DEFAULT_STACK_SIZE,NULL,TASK_PRIORITY_DEFAULT);
	while(1)
	{
		gameControl();
	}
}

/*
 * Recording routine for RED_0
 */
void recordRed_0()
{
	FILE *record;
	point temp[30];
	int done = 0;
	int steps = 0;
	imeReset(imeRB);
	imeReset(imeRF);
	imeReset(imeLB);
	imeReset(imeLF);
	while(!done)
	{
		temp[steps]=recordPoint();
		delay(2000);
		steps++;
		imeReset(imeRB);
		imeReset(imeRF);
		imeReset(imeLB);
		imeReset(imeLF);
		if(joy1_channel5==3)
			done=1;
	}
	motorStopAll();
	record = fopen("red_0", "w");
	fputc(steps,record);
	lcdPrint(uart1,1,"stp writen");
	fwrite(temp, sizeof(point), steps, record);
	lcdPrint(uart1,1,"pts writen");
	lcdClear(uart1);
	fclose(record);
	lcdClear(uart1);
	lcdPrint(uart1,1,"record fin");
}

/*
 * Recording routine for RED_1
 */
void recordRed_1()
{
	FILE *record;
	point temp[30];
	int done = 0;
	int steps = 0;
	imeReset(imeRB);
	imeReset(imeRF);
	imeReset(imeLB);
	imeReset(imeLF);

	while(!done)
	{
		temp[steps]=recordPoint();
		delay(20);
		delay(1980);
		steps++;
		imeReset(imeRB);
		imeReset(imeRF);
		imeReset(imeLB);
		imeReset(imeLF);
		if(joy1_channel5==3)
			done=1;
	}
	motorStopAll();
	record = fopen("red_1", "w");
	fputc(steps,record);
	fwrite(temp, sizeof(point), steps, record);
	fclose(record);
}


/*
 * Recording routine for BLUE_0
 */
void recordBlue_0()
{
	FILE *record;
	point temp[30];
	int done = 0;
	int steps = 0;
	imeReset(imeRB);
	imeReset(imeRF);
	imeReset(imeLB);
	imeReset(imeLF);

	while(!done)
	{
		temp[steps]=recordPoint();
		delay(20);
		delay(1980);
		steps++;
		imeReset(imeRB);
		imeReset(imeRF);
		imeReset(imeLB);
		imeReset(imeLF);
		if(joy1_channel5==3)
			done=1;
	}
	motorStopAll();
	record = fopen("blue_0", "w");
	fputc(steps,record);
	fwrite(temp, sizeof(point), steps, record);
	fclose(record);
}


/*
 * Recording routine for BLUE_1
 */
void recordBlue_1()
{
	FILE *record;
	point temp[30];
	int done = 0;
	int steps = 0;
	imeReset(imeRB);
	imeReset(imeRF);
	imeReset(imeLB);
	imeReset(imeLF);

	while(!done)
	{
		temp[steps]=recordPoint();
		delay(20);
		delay(1980);
		steps++;
		imeReset(imeRB);
		imeReset(imeRF);
		imeReset(imeLB);
		imeReset(imeLF);
		if(joy1_channel5==3)
			done=1;
	}
	motorStopAll();
	record = fopen("blue_1", "w");
	fputc(steps,record);
	fwrite(temp, sizeof(point), steps, record);
	fclose(record);
}
