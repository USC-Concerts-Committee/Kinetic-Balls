#include <math.h>


void controller (float t, struct params params, float &Y);


struct params {
    // ! MAX_EXTENSION CANNOT EXCEED 14mm
    float max_extension; // Max entension of lead screw (mm)
    float phase_shift; // Angle of radial movement
    float freq; // Period of one movement cycle (sec)
};


extern struct params p_array[4];