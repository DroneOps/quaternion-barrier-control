/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * normalize.c
 *
 * Code generation for function 'normalize'
 *
 */

/* Include files */
#include "normalize.h"
#include "restricted_drone_control_big_trajectory_change_func_data.h"
#include "restricted_drone_control_big_trajectory_change_func_internal_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = {
    10,                         /* lineNo */
    "quaternionBase/normalize", /* fcnName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/normalize.m" /* pathName
                                                                      */
};

/* Function Definitions */
void quaternionBase_normalize(const emlrtStack *sp, quaternion *q)
{
  emlrtStack st;
  real_T n;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &l_emlrtRSI;
  n = ((q->a * q->a + q->b * q->b) + q->c * q->c) + q->d * q->d;
  if (n < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  n = muDoubleScalarSqrt(n);
  q->a /= n;
  q->b /= n;
  q->c /= n;
  q->d /= n;
}

/* End of code generation (normalize.c) */
