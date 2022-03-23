#include <Arduino.h>
#include <AccelStepper.h>
#include <TMCStepper.h>
#include <DistanceStepper.h>
#include <motionController.h>

#define motorInterfaceType 1

#define dirPin_0	2	
#define stepPin_0	3
#define dirPin_1 	4
#define stepPin_1 	5
#define dirPin_2 	6
#define stepPin_2 	7
#define dirPin_3	8
#define stepPin_3	9
#define dirPin_4	10
#define stepPin_4	11
#define dirPin_5	12
#define stepPin_5	13

#define dirPin_6	54
#define stepPin_6	55
#define dirPin_7	56
#define stepPin_7	57
#define dirPin_8	58
#define stepPin_8	59
#define dirPin_9	60
#define stepPin_9	61
#define dirPin_10	62
#define stepPin_10	63
#define dirPin_11	64
#define stepPin_11	65
#define dirPin_12	66
#define stepPin_12	67

#define MAX_SPEED 1000

DistanceStepper steppers[12];

float Y[12] = {0.0};

float t;
float start;

void setup()
{
	// create steppers array
	steppers[0] = DistanceStepper(motorInterfaceType, stepPin_0, dirPin_0);
	steppers[1] = DistanceStepper(motorInterfaceType, stepPin_1, dirPin_1);
	steppers[2] = DistanceStepper(motorInterfaceType, stepPin_2, dirPin_2);
	steppers[3] = DistanceStepper(motorInterfaceType, stepPin_3, dirPin_3);
	steppers[4] = DistanceStepper(motorInterfaceType, stepPin_4, dirPin_4);
	steppers[5] = DistanceStepper(motorInterfaceType, stepPin_5, dirPin_5);
	steppers[6] = DistanceStepper(motorInterfaceType, stepPin_6, dirPin_6);
	steppers[7] = DistanceStepper(motorInterfaceType, stepPin_7, dirPin_7);
	steppers[8] = DistanceStepper(motorInterfaceType, stepPin_8, dirPin_8);
	steppers[9] = DistanceStepper(motorInterfaceType, stepPin_9, dirPin_9);
	steppers[10] = DistanceStepper(motorInterfaceType, stepPin_10, dirPin_10);
	steppers[11] = DistanceStepper(motorInterfaceType, stepPin_11, dirPin_11);

	// compute initial distances of steppers
	computeDistances(0, motion, Y);

	// set max speeds of steppers and run each stepper sequentially (blocking) to
	// initial distance
	for (int i = 0; i < 12; i++) 
	{
		steppers[i].setMaxSpeed(MAX_SPEED);
		steppers[i].runToDistance(Y[i]);
	}

	start = millis() / 1000;	
}


void loop()
{
	float curr = millis() / 1000;
	t = curr - start;
	
	computeDistances(t, motion, Y);
	updateSteppers(steppers, Y);
}