#include "DistanceStepper.h"

//DistanceStepper::DistanceStepper() {};

DistanceStepper::DistanceStepper (
    uint8_t interface,
    uint8_t StepPin,
    uint8_t DirPin):
    AccelStepper(interface, StepPin, DirPin) {}

float DistanceStepper::getCurrentPositionDistance()
{
    return currentPosition() / (microSteps * stepsPerRotation / distancePerRotation);
}

void DistanceStepper::moveToDistance(float distance)
{
    moveTo(distance * microSteps * stepsPerRotation / distancePerRotation);
}

void DistanceStepper::moveRelative(float distance)
{
    move(distance * microSteps * stepsPerRotation / distancePerRotation);
}

void DistanceStepper::runToDistance(float distance)
{
    runToNewPosition(distance * microSteps * stepsPerRotation / distancePerRotation);
}