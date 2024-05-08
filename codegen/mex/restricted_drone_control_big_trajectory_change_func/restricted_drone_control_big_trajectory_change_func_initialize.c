/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * restricted_drone_control_big_trajectory_change_func_initialize.c
 *
 * Code generation for function
 * 'restricted_drone_control_big_trajectory_change_func_initialize'
 *
 */

/* Include files */
#include "restricted_drone_control_big_trajectory_change_func_initialize.h"
#include "_coder_restricted_drone_control_big_trajectory_change_func_mex.h"
#include "restricted_drone_control_big_trajectory_change_func_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void restricted_drone_control_big_trajectory_change_func_once(void);

/* Function Definitions */
static void restricted_drone_control_big_trajectory_change_func_once(void)
{
  mex_InitInfAndNan();
}

void restricted_drone_control_big_trajectory_change_func_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    restricted_drone_control_big_trajectory_change_func_once();
  }
}

/* End of code generation
 * (restricted_drone_control_big_trajectory_change_func_initialize.c) */
