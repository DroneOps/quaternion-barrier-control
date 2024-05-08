/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * log.h
 *
 * Code generation for function 'log'
 *
 */

#pragma once

/* Include files */
#include "restricted_drone_control_big_trajectory_change_func_internal_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void binary_expand_op(real_T in1_data[], int32_T in1_size[2],
                      const quaternion *in2, const int8_T in3[2]);

void binary_expand_op_1(real_T in1_data[], int32_T in1_size[2],
                        const quaternion *in2, const int8_T in3[2],
                        const real_T in4_data[], const int32_T in4_size[2]);

void binary_expand_op_2(real_T in1_data[], int32_T in1_size[2],
                        const quaternion *in2, const int8_T in3[2],
                        const real_T in4_data[], const int32_T in4_size[2]);

void quaternionBase_log(const emlrtStack *sp, quaternion *q);

/* End of code generation (log.h) */
