/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * div.c
 *
 * Code generation for function 'div'
 *
 */

/* Include files */
#include "div.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void binary_expand_op_3(real_T in1_data[], int32_T in1_size[2], real_T in2,
                        int32_T in3)
{
  real_T b_in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  if (in3 == 1) {
    loop_ub = in1_size[1];
  } else {
    loop_ub = in3;
  }
  stride_0_1 = (in1_size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data = in1_data[i * stride_0_1] / in2;
  }
  in1_size[0] = 1;
  in1_size[1] = loop_ub;
  for (i = 0; i < loop_ub; i++) {
    in1_data[0] = b_in1_data;
  }
}

/* End of code generation (div.c) */
