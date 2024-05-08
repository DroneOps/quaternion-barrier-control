/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rotvec.c
 *
 * Code generation for function 'rotvec'
 *
 */

/* Include files */
#include "rotvec.h"
#include "normalize.h"
#include "restricted_drone_control_big_trajectory_change_func_data.h"
#include "restricted_drone_control_big_trajectory_change_func_internal_types.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = {
    14,                      /* lineNo */
    "quaternionBase/rotvec", /* fcnName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/rotvec.m" /* pathName */
};

static emlrtRSInfo x_emlrtRSI = {
    16,                      /* lineNo */
    "quaternionBase/rotvec", /* fcnName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/rotvec.m" /* pathName */
};

static emlrtRSInfo y_emlrtRSI = {
    18,                      /* lineNo */
    "quaternionBase/rotvec", /* fcnName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/rotvec.m" /* pathName */
};

/* Function Definitions */
void quaternionBase_rotvec(const emlrtStack *sp, real_T q_a, real_T q_b,
                           real_T q_c, real_T q_d, real_T rv[3])
{
  __m128d r;
  emlrtStack st;
  quaternion qn;
  real_T m[4];
  real_T y[3];
  real_T ang;
  real_T mag;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  qn.a = q_a;
  qn.b = q_b;
  qn.c = q_c;
  qn.d = q_d;
  st.site = &w_emlrtRSI;
  quaternionBase_normalize(&st, &qn);
  m[0] = qn.a;
  m[1] = qn.b;
  m[2] = qn.c;
  m[3] = qn.d;
  st.site = &x_emlrtRSI;
  p = ((m[0] < -1.0) || (m[0] > 1.0));
  if (p) {
    emlrtErrorWithMessageIdR2018a(
        &st, &b_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "acos");
  }
  ang = 2.0 * muDoubleScalarAcos(m[0]);
  r = _mm_loadu_pd(&m[1]);
  _mm_storeu_pd(&y[0], _mm_mul_pd(r, r));
  mag = m[3];
  y[2] = mag * mag;
  mag = sumColumnB(y);
  st.site = &y_emlrtRSI;
  if (mag < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  mag = muDoubleScalarSqrt(mag);
  rv[0] = 0.0;
  rv[1] = 0.0;
  rv[2] = 0.0;
  if (mag > 2.2204460492503131E-15) {
    r = _mm_loadu_pd(&m[1]);
    _mm_storeu_pd(
        &rv[0], _mm_div_pd(_mm_mul_pd(_mm_set1_pd(ang), r), _mm_set1_pd(mag)));
    rv[2] = ang * m[3] / mag;
  }
}

/* End of code generation (rotvec.c) */
