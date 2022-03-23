#include <motionController.h>


MotionParams motion[12] = {
    {14.0f, 0.0f, 3.0f},
    {14.0f, 0.0f, 3.0f},
    {14.0f, 0.0f, 3.0f},
    {12.0f, M_PI/6, 2.7f},
    {12.0f, M_PI/6, 2.7f},
    {12.0f, M_PI/6, 2.7f},
    {12.0f, M_PI/3, 2.4f},
    {12.0f, M_PI/3, 2.4f},
    {12.0f, M_PI/3, 2.4f},
    {10.0f, M_PI/2, 2.1f},
    {10.0f, M_PI/2, 2.1f},
    {10.0f, M_PI/2, 2.1f}
};

void computeDistances (float t, MotionParams motion[], float (&Y)[12])
{
    for (int i = 0; i < 12; i++) {
        Y[i] = motion[i].max_extension * (-1) 
                * cosf(2 * M_PI * motion[i].freq * t + motion[i].phase_shift) 
                + (motion[i].max_extension) / 2;
    }
}

void updateSteppers (DistanceStepper(&Steppers)[12], float(&Y)[12])
{
    for (int i = 0; i < 12; i++) \
    {
        Steppers[i].moveToDistance(Y[i]);
    }

    for (int i = 0; i < 12; i++) \
    {
        Steppers[i].run();
    }

}
    
