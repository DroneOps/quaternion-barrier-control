/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include "mldivide.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ab_emlrtRSI = {
    20,         /* lineNo */
    "mldivide", /* fcnName */
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/mldivide.m" /* pathName
                                                                      */
};

static emlrtRSInfo bb_emlrtRSI = {
    42,      /* lineNo */
    "mldiv", /* fcnName */
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/mldivide.m" /* pathName
                                                                      */
};

static emlrtRSInfo cb_emlrtRSI = {
    61,        /* lineNo */
    "lusolve", /* fcnName */
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
};

static emlrtRSInfo db_emlrtRSI = {
    293,          /* lineNo */
    "lusolve3x3", /* fcnName */
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
};

static emlrtRSInfo eb_emlrtRSI = {
    90,              /* lineNo */
    "warn_singular", /* fcnName */
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
};

/* Function Definitions */
void mldivide(const emlrtStack *sp, const real_T A[9], const real_T B[3],
              real_T Y[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T b_A[9];
  real_T d;
  int32_T r2;
  int32_T r3;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ab_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &bb_emlrtRSI;
  c_st.site = &cb_emlrtRSI;
  memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
  r2 = 1;
  r3 = 2;
  b_A[1] = A[1] / A[0];
  b_A[2] = A[2] / A[0];
  b_A[4] = A[4] - b_A[1] * A[3];
  b_A[5] = A[5] - b_A[2] * A[3];
  b_A[7] = A[7] - b_A[1] * A[6];
  b_A[8] = A[8] - b_A[2] * A[6];
  if (muDoubleScalarAbs(b_A[5]) > muDoubleScalarAbs(b_A[4])) {
    r2 = 2;
    r3 = 1;
  }
  b_A[r3 + 3] /= b_A[r2 + 3];
  b_A[r3 + 6] -= b_A[r3 + 3] * b_A[r2 + 6];
  d = b_A[r2 + 3];
  if ((d == 0.0) || (b_A[r3 + 6] == 0.0)) {
    d_st.site = &db_emlrtRSI;
    e_st.site = &eb_emlrtRSI;
    warning(&e_st);
  }
  Y[1] = B[r2] - B[0] * b_A[r2];
  Y[2] = (B[r3] - B[0] * b_A[r3]) - Y[1] * b_A[r3 + 3];
  Y[2] /= b_A[r3 + 6];
  Y[0] = B[0] - Y[2] * b_A[6];
  Y[1] -= Y[2] * b_A[r2 + 6];
  Y[1] /= d;
  Y[0] -= Y[1] * b_A[3];
  Y[0] /= b_A[0];
}

/* End of code generation (mldivide.c) */
