/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * exp.c
 *
 * Code generation for function 'exp'
 *
 */

/* Include files */
#include "exp.h"
#include "log.h"
#include "restricted_drone_control_big_trajectory_change_func_data.h"
#include "restricted_drone_control_big_trajectory_change_func_internal_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo u_emlrtRSI = {
    19,                   /* lineNo */
    "quaternionBase/exp", /* fcnName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/exp.m" /* pathName */
};

static emlrtECInfo g_emlrtECI = {
    2,                    /* nDims */
    24,                   /* lineNo */
    10,                   /* colNo */
    "quaternionBase/exp", /* fName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/exp.m" /* pName */
};

static emlrtECInfo h_emlrtECI = {
    2,                    /* nDims */
    27,                   /* lineNo */
    9,                    /* colNo */
    "quaternionBase/exp", /* fName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/exp.m" /* pName */
};

static emlrtECInfo i_emlrtECI = {
    -1,                   /* nDims */
    27,                   /* lineNo */
    1,                    /* colNo */
    "quaternionBase/exp", /* fName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/exp.m" /* pName */
};

static emlrtECInfo j_emlrtECI = {
    2,                    /* nDims */
    29,                   /* lineNo */
    9,                    /* colNo */
    "quaternionBase/exp", /* fName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/exp.m" /* pName */
};

static emlrtECInfo k_emlrtECI = {
    -1,                   /* nDims */
    29,                   /* lineNo */
    1,                    /* colNo */
    "quaternionBase/exp", /* fName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/exp.m" /* pName */
};

static emlrtECInfo l_emlrtECI = {
    2,                    /* nDims */
    31,                   /* lineNo */
    9,                    /* colNo */
    "quaternionBase/exp", /* fName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/exp.m" /* pName */
};

static emlrtECInfo m_emlrtECI = {
    -1,                   /* nDims */
    31,                   /* lineNo */
    1,                    /* colNo */
    "quaternionBase/exp", /* fName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/exp.m" /* pName */
};

/* Function Declarations */
static void binary_expand_op_7(real_T in1_data[], int32_T in1_size[2],
                               real_T in2, const int8_T in3[2]);

/* Function Definitions */
static void binary_expand_op_7(real_T in1_data[], int32_T in1_size[2],
                               real_T in2, const int8_T in3[2])
{
  real_T in2_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_1_1;
  if (in1_size[1] == 1) {
    loop_ub = in3[1];
  } else {
    loop_ub = in1_size[1];
  }
  stride_1_1 = (in1_size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    in2_data = in2 * in1_data[i * stride_1_1];
  }
  in1_size[0] = 1;
  in1_size[1] = loop_ub;
  for (i = 0; i < loop_ub; i++) {
    in1_data[0] = in2_data;
  }
}

void quaternionBase_exp(const emlrtStack *sp, quaternion *q)
{
  emlrtStack st;
  real_T expa;
  real_T tmp_data;
  real_T vnorm;
  real_T vscale_data;
  int32_T tmp_size[2];
  int32_T vscale_size[2];
  int32_T b_trueCount;
  int32_T i;
  int32_T k;
  int32_T trueCount;
  int8_T size_tmp[2];
  boolean_T b;
  boolean_T nz;
  st.prev = sp;
  st.tls = sp->tls;
  expa = muDoubleScalarExp(q->a);
  st.site = &u_emlrtRSI;
  vnorm = (q->b * q->b + q->c * q->c) + q->d * q->d;
  if (vnorm < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  vnorm = muDoubleScalarSqrt(vnorm);
  nz = (vnorm != 0.0);
  trueCount = 0;
  b_trueCount = 0;
  if (nz) {
    trueCount = 1;
    b_trueCount = 1;
  }
  size_tmp[0] = 1;
  size_tmp[1] = (int8_T)b_trueCount;
  vscale_size[1] = trueCount;
  if (trueCount - 1 >= 0) {
    vscale_data = vnorm;
  }
  for (k = 0; k < trueCount; k++) {
    vscale_data = muDoubleScalarSin(vscale_data);
  }
  k = trueCount - 1;
  vscale_size[0] = 1;
  for (i = 0; i <= k; i++) {
    vscale_data /= vnorm;
  }
  if ((b_trueCount != trueCount) && ((b_trueCount != 1) && (trueCount != 1))) {
    emlrtDimSizeImpxCheckR2021b(b_trueCount, 0, &g_emlrtECI, (emlrtConstCTX)sp);
  }
  if (b_trueCount == trueCount) {
    vscale_size[0] = 1;
    vscale_size[1] = b_trueCount;
    for (i = 0; i <= k; i++) {
      vscale_data *= expa;
    }
  } else {
    binary_expand_op_7((real_T *)&vscale_data, vscale_size, expa, size_tmp);
  }
  q->a = expa * muDoubleScalarCos(vnorm);
  trueCount = 0;
  if (nz) {
    trueCount = 1;
  }
  size_tmp[0] = 1;
  size_tmp[1] = (int8_T)trueCount;
  if ((trueCount != vscale_size[1]) &&
      ((trueCount != 1) && (vscale_size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(0, 0, &h_emlrtECI, (emlrtConstCTX)sp);
  }
  b_trueCount = 0;
  if (nz) {
    b_trueCount = 1;
  }
  if (trueCount == vscale_size[1]) {
    tmp_size[0] = 1;
    tmp_size[1] = trueCount;
    if (vscale_size[1] - 1 >= 0) {
      tmp_data = q->b * vscale_data;
    }
  } else {
    binary_expand_op_2((real_T *)&tmp_data, tmp_size, q, size_tmp,
                       (real_T *)&vscale_data, vscale_size);
  }
  if (b_trueCount != tmp_size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(b_trueCount, tmp_size[1], &i_emlrtECI,
                                    (emlrtConstCTX)sp);
  }
  expa = q->b;
  if (tmp_size[1] - 1 >= 0) {
    expa = tmp_data;
  }
  b = !nz;
  if (b) {
    expa = 0.0;
  }
  q->b = expa;
  trueCount = 0;
  if (nz) {
    trueCount = 1;
  }
  size_tmp[0] = 1;
  size_tmp[1] = (int8_T)trueCount;
  if ((trueCount != vscale_size[1]) &&
      ((trueCount != 1) && (vscale_size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(0, 0, &j_emlrtECI, (emlrtConstCTX)sp);
  }
  b_trueCount = 0;
  if (nz) {
    b_trueCount = 1;
  }
  if (trueCount == vscale_size[1]) {
    tmp_size[1] = trueCount;
    if (vscale_size[1] - 1 >= 0) {
      tmp_data = q->c * vscale_data;
    }
  } else {
    binary_expand_op_1((real_T *)&tmp_data, tmp_size, q, size_tmp,
                       (real_T *)&vscale_data, vscale_size);
  }
  if (b_trueCount != tmp_size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(b_trueCount, tmp_size[1], &k_emlrtECI,
                                    (emlrtConstCTX)sp);
  }
  expa = q->c;
  if (tmp_size[1] - 1 >= 0) {
    expa = tmp_data;
  }
  if (b) {
    expa = 0.0;
  }
  q->c = expa;
  trueCount = 0;
  if (nz) {
    trueCount = 1;
  }
  size_tmp[0] = 1;
  size_tmp[1] = (int8_T)trueCount;
  if ((trueCount != vscale_size[1]) &&
      ((trueCount != 1) && (vscale_size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(0, 0, &l_emlrtECI, (emlrtConstCTX)sp);
  }
  b_trueCount = 0;
  if (nz) {
    b_trueCount = 1;
  }
  if (trueCount == vscale_size[1]) {
    k = vscale_size[1] - 1;
    vscale_size[1] = trueCount;
    for (i = 0; i <= k; i++) {
      vscale_data *= q->d;
    }
  } else {
    binary_expand_op((real_T *)&vscale_data, vscale_size, q, size_tmp);
  }
  if (b_trueCount != vscale_size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(b_trueCount, vscale_size[1], &m_emlrtECI,
                                    (emlrtConstCTX)sp);
  }
  expa = q->d;
  if (vscale_size[1] - 1 >= 0) {
    expa = vscale_data;
  }
  if (b) {
    expa = 0.0;
  }
  q->d = expa;
}

/* End of code generation (exp.c) */
