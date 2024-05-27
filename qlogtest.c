#include <stdio.h>
#include <math.h>

typedef struct {
    float w, x, y, z;
} Quaternion;

float norm(Quaternion q) {
    return sqrtf(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
}

Quaternion quaternion_log(Quaternion q) {
    float norm_v = sqrtf(q.x * q.x + q.y * q.y + q.z * q.z);
    float norm_q = norm(q);
    float log_scalar = logf(norm_q);
    float log_factor = (norm_v != 0) ? acosf(q.w / norm_q) / norm_v : 0;
    Quaternion result;
    result.w = log_scalar;
    result.x = log_factor * q.x;
    result.y = log_factor * q.y;
    result.z = log_factor * q.z;
    return result;
}

int main() {
    Quaternion quaternion = {0, 0.14038, 0.20243, 0.19096}; // Quaternion in the format [w, x, y, z]
    Quaternion logarithm_quaternion = quaternion_log(quaternion);
    printf("Logarithm of quaternion: (%f, %f, %f, %f)\n", 
           logarithm_quaternion.w, 
           logarithm_quaternion.x, 
           logarithm_quaternion.y, 
           logarithm_quaternion.z);
    return 0;
}
