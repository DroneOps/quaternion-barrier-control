#include "math3d.h"

#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

int main(){

  struct quat z_q = mkquat(0,0,1,0);
  struct quat orientation = mkquat(0.049229,-0.022698,0.0,0.99853);


  struct quat curr_thrust_force_vector = qqmul(orientation,z_q);
  curr_thrust_force_vector = qqmul(curr_thrust_force_vector,qinv(orientation));
  // curr_thrust_force_vector = qqmul(curr_thrust_force_vector,qinv(orientation));
  // printf("%f, %f, %f, %f", curr_thrust_force_vector.w, curr_thrust_force_vector.x,
  //  curr_thrust_force_vector.y, curr_thrust_force_vector.z);

  float c = 2.0f;
  float b = 1.0f;
  float a = b-c;
  printf("%f",a);

};