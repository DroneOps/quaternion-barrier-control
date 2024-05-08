/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_restricted_drone_control_big_trajectory_change_func_mex.c
 *
 * Code generation for function
 * '_coder_restricted_drone_control_big_trajectory_change_func_mex'
 *
 */

/* Include files */
#include "_coder_restricted_drone_control_big_trajectory_change_func_mex.h"
#include "_coder_restricted_drone_control_big_trajectory_change_func_api.h"
#include "restricted_drone_control_big_trajectory_change_func_data.h"
#include "restricted_drone_control_big_trajectory_change_func_initialize.h"
#include "restricted_drone_control_big_trajectory_change_func_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  (void)prhs;
  mexAtExit(&restricted_drone_control_big_trajectory_change_func_atexit);
  /* Module initialization. */
  restricted_drone_control_big_trajectory_change_func_initialize();
  /* Dispatch the entry-point. */
  restricted_drone_control_big_trajectory_change_func_mexFunction(nlhs, plhs,
                                                                  nrhs);
  /* Module termination. */
  restricted_drone_control_big_trajectory_change_func_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

void restricted_drone_control_big_trajectory_change_func_mexFunction(
    int32_T nlhs, mxArray *plhs[1], int32_T nrhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        51,
                        "restricted_drone_control_big_trajectory_change_func");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 51,
                        "restricted_drone_control_big_trajectory_change_func");
  }
  /* Call the function. */
  c_restricted_drone_control_big_(&outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/* End of code generation
 * (_coder_restricted_drone_control_big_trajectory_change_func_mex.c) */
