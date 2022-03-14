#include <motionController.h>

struct params p_array[4] = {
    {14.0f, 0.0f, 3.0f},
    {12.0f, M_PI/6, 2.7f},
    {12.0f, M_PI/3, 2.4f},
    {10.0f, M_PI/2, 2.1f},
};


void controller (float t, struct params params, float &Y)
{
    Y = params.max_extension * (-1) * cosf(2 * M_PI * params.freq * t + params.phase_shift) + (params.max_extension) / 2;
}
