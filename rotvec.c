#include <stdio.h>
#include <math.h>
#include "math3d.h"


void main(){
struct quat q = mkquat(0.24718, 0.31871, -0.29296, 0);
  q = qnormalize(q);
  float ang = 2*acosf(q.w);
  float axis[] = {q.x, q.y, q.z};
  float magnitude = sqrtf(q.x*q.x + q.y*q.y + q.z*q.z);
  float rv[] = {0.0f, 0.0f, 0.0f};
  for (int i = 0; i < 3; i++){
    rv[i] = (ang * axis[i]) / magnitude;
  }
  printf("%f, %f, %f", rv[0], rv[1], rv[2]);

  return;
}