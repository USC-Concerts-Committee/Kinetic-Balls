#define _USE_MATH_DEFINES
#include <math.h>
#include <DistanceStepper.h>

typedef struct
{
    // ! MAX_EXTENSION CANNOT EXCEED 14mm
    float max_extension; // Max entension of lead screw (mm)
    float phase_shift; // Angle of radial movement
    float freq; // Period of one movement cycle (sec)
} MotionParams;


extern MotionParams motion[12];

void computeDistances (float t, MotionParams[], float (&Y)[12]);
void updateSteppers (DistanceStepper(&Steppers)[12], float(&Y)[12]);