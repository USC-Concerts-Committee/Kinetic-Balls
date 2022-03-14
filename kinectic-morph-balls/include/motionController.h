#include <math.h>
#include <vector>
#include <array>

void controller (float t, struct params params, float &Y);


struct params {
    // ! MAX_EXTENSION CANNOT EXCEED 14mm
    float max_extension = 14.0f; // Max entension of lead screw (mm)
    float phase_shift = M_PI/2; // Angle of radial movement
    float freq = 3.0f; // Period of one movement cycle (sec)
};


extern struct params p_array[4];