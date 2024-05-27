
#include "math3d.h"
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>


typedef struct {
    float w, x, y, z;
} Quaternion;

Quaternion quaternion_exponential(Quaternion q) {
    float norm_v = sqrtf(q.x * q.x + q.y * q.y + q.z * q.z);
    float exp_scalar = expf(q.w) * cosf(norm_v);
    float exp_factor = (norm_v != 0) ? (expf(q.w) * sinf(norm_v) / norm_v) : 0;
    Quaternion result;
    result.w = exp_scalar;
    result.x = exp_factor * q.x;
    result.y = exp_factor * q.y;
    result.z = exp_factor * q.z;
    return result;
}

int main() {
    Quaternion quaternion = {0, 0.17397, 0.036821,  0.35933}; // Quaternion in the format [w, x, y, z]
    Quaternion exponential_quaternion = quaternion_exponential(quaternion);
    printf("Exponential of quaternion: (%f, %f, %f, %f)\n", 
           exponential_quaternion.w, 
           exponential_quaternion.x, 
           exponential_quaternion.y, 
           exponential_quaternion.z);
    return 0;
}



