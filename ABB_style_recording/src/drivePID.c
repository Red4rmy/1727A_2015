#include "main.h"

float Kp=1;
float Ki=0;
float Kd=0;

void driveToPID(int targetRB,int targetLB,int targetRF, int targetLF)
{



	// Integral definition for each of the IMEs
	int integralRB=0;
	int integralLB=0;
	int integralRF=0;
	int integralLF=0;

	// Derivative definition for each of the IME's
	int derivativeRB=0;
	int derivativeLB=0;
	int derivativeRF=0;
	int derivativeLF=0;

	// Definition of Output speeds for each motor
	int speedRB;
	int speedLB;
	int speedRF;
	int speedLF;

	// Definition of errors for each IME's
	float errorRB=targetRB;
	float errorLB=targetLB;
	float errorRF=targetRF;
	float errorLF=targetLF;

	// Definitions of previous errors for each IME
	int previous_errorRB= errorRB;
	int previous_errorLB= errorLB;
	int previous_errorRF= errorRF;
	int previous_errorLF= errorLF;
	while (errorRB!=0 && errorLB!=0 && errorRF!=0 && errorLF!=0)
	{


		//CALCULATIONS FOR RIGHT BACK MOTOR POWER.
		errorRB = targetRB-RBcount;
		integralRB = integralRB + errorRB;
		if (errorRB == 0)
		{
			integralRB = 0;
		}
		if(abs(errorRB)>40)
		{
			integralRB = 0;
		}
		derivativeRB = errorRB - previous_errorRB;
		previous_errorRB = errorRB;
		speedRB = Kp*errorRB + Ki*integralRB + Kd*derivativeRB;


		//CALCULATIONS FOR LEFT BACK MOTOR POWER.
		errorLB = targetLB-LBcount;
		integralLB = integralLB + errorLB;
		if (errorLB == 0)
		{
			integralLB = 0;
		}
		if(abs(errorLB)>40)
		{
			integralLB = 0;;
		}
		derivativeLB = errorLB - previous_errorLB;
		previous_errorLB = errorLB;
		speedLB = Kp*errorLB + Ki*integralLB + Kd*derivativeLB;



		//CALCULATIONS FOR RIGHT FRONT MOTOR POWER.
		errorRF = targetRF-RFcount;
		integralRF = integralRF + errorRF;
		if (errorRF == 0)
		{
			integralRF = 0;
		}
		if(abs(errorRF)>40)
		{
			integralRF = 0;
		}
		derivativeRF = errorRF - previous_errorRF;
		previous_errorRF = errorRF;
		speedRF = Kp*errorRF + Ki*integralRF + Kd*derivativeRF;


		//CALCULATIONS FOR LEFT FRONT MOTOR POWER.
		errorLF = targetLF-LFcount;
		integralLF = integralLF + errorLF;
		if (errorLF == 0)
		{
			integralLF = 0;
		}
		if(abs(errorLF)>40)
		{
			integralLF = 0;;
		}
		derivativeLF = errorLF - previous_errorLF;
		previous_errorLF = errorLF;
		speedLF = Kp*errorLF + Ki*integralLF + Kd*derivativeLF;



		//ASSIGN MOTOR OUTPUTS.
		motorSet(RB,speedRB);
		motorSet(LB,speedLB);
		motorSet(RF,speedRF);
		motorSet(LF,speedLF);

		delay(20);
	}
}
