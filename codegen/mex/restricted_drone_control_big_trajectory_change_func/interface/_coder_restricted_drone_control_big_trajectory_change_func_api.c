/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_restricted_drone_control_big_trajectory_change_func_api.c
 *
 * Code generation for function
 * '_coder_restricted_drone_control_big_trajectory_change_func_api'
 *
 */

/* Include files */
#include "_coder_restricted_drone_control_big_trajectory_change_func_api.h"
#include "restricted_drone_control_big_trajectory_change_func.h"
#include "restricted_drone_control_big_trajectory_change_func_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static const mxArray *emlrt_marshallOut(const real_T u);

/* Function Definitions */
static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

void c_restricted_drone_control_big_(const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Invoke the target function */
  i = restricted_drone_control_big_trajectory_change_func(&st);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(i);
}

/* End of code generation
 * (_coder_restricted_drone_control_big_trajectory_change_func_api.c) */
