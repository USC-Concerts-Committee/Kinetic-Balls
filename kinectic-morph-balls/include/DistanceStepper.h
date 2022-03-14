#ifndef DistanceStepper_h
#define DistanceStepper_h

#include <AccelStepper.h>

class DistanceStepper : public AccelStepper {
    private:
		int microSteps = 16;
		int stepsPerRotation = 200;
		float distancePerRotation = 8; //lead screw distance

    public:
		DistanceStepper(
			uint8_t interface = AccelStepper::DRIVER, 
			uint8_t StepPin = 2, 
			uint8_t DirPin = 3);

		float getCurrentPositionDistance();

		void moveToDistance(float distance);

		void moveRelative(float distance);
};

#endif
