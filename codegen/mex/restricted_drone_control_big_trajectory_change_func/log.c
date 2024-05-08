/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * log.c
 *
 * Code generation for function 'log'
 *
 */

/* Include files */
#include "log.h"
#include "div.h"
#include "restricted_drone_control_big_trajectory_change_func_data.h"
#include "restricted_drone_control_big_trajectory_change_func_internal_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo o_emlrtRSI = {
    18,                   /* lineNo */
    "quaternionBase/log", /* fcnName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    19,                   /* lineNo */
    "quaternionBase/log", /* fcnName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    24,                   /* lineNo */
    "quaternionBase/log", /* fcnName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" /* pathName */
};

static emlrtRSInfo r_emlrtRSI = {
    26,                   /* lineNo */
    "quaternionBase/log", /* fcnName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" /* pathName */
};

static emlrtECInfo emlrtECI = {
    -1,                   /* nDims */
    31,                   /* lineNo */
    1,                    /* colNo */
    "quaternionBase/log", /* fName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    2,                    /* nDims */
    31,                   /* lineNo */
    9,                    /* colNo */
    "quaternionBase/log", /* fName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" /* pName */
};

static emlrtECInfo c_emlrtECI = {
    -1,                   /* nDims */
    29,                   /* lineNo */
    1,                    /* colNo */
    "quaternionBase/log", /* fName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" /* pName */
};

static emlrtECInfo d_emlrtECI = {
    2,                    /* nDims */
    29,                   /* lineNo */
    9,                    /* colNo */
    "quaternionBase/log", /* fName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" /* pName */
};

static emlrtECInfo e_emlrtECI = {
    -1,                   /* nDims */
    27,                   /* lineNo */
    1,                    /* colNo */
    "quaternionBase/log", /* fName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" /* pName */
};

static emlrtECInfo f_emlrtECI = {
    2,                    /* nDims */
    27,                   /* lineNo */
    9,                    /* colNo */
    "quaternionBase/log", /* fName */
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" /* pName */
};

/* Function Definitions */
void binary_expand_op(real_T in1_data[], int32_T in1_size[2],
                      const quaternion *in2, const int8_T in3[2])
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
    in2_data = in2->d * in1_data[i * stride_1_1];
  }
  in1_size[0] = 1;
  in1_size[1] = loop_ub;
  for (i = 0; i < loop_ub; i++) {
    in1_data[0] = in2_data;
  }
}

void binary_expand_op_1(real_T in1_data[], int32_T in1_size[2],
                        const quaternion *in2, const int8_T in3[2],
                        const real_T in4_data[], const int32_T in4_size[2])
{
  int32_T i;
  int32_T loop_ub;
  int32_T stride_1_1;
  in1_size[0] = 1;
  if (in4_size[1] == 1) {
    loop_ub = in3[1];
  } else {
    loop_ub = in4_size[1];
  }
  in1_size[1] = loop_ub;
  stride_1_1 = (in4_size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = in2->c * in4_data[i * stride_1_1];
  }
}

void binary_expand_op_2(real_T in1_data[], int32_T in1_size[2],
                        const quaternion *in2, const int8_T in3[2],
                        const real_T in4_data[], const int32_T in4_size[2])
{
  int32_T i;
  int32_T loop_ub;
  int32_T stride_1_1;
  in1_size[0] = 1;
  if (in4_size[1] == 1) {
    loop_ub = in3[1];
  } else {
    loop_ub = in4_size[1];
  }
  in1_size[1] = loop_ub;
  stride_1_1 = (in4_size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = in2->b * in4_data[i * stride_1_1];
  }
}

void quaternionBase_log(const emlrtStack *sp, quaternion *q)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T qnorm;
  real_T tmp_data;
  real_T vnorm;
  real_T vscale_data;
  int32_T tmp_size[2];
  int32_T vscale_size[2];
  int32_T k;
  int32_T loop_ub;
  int32_T trueCount;
  int8_T size_tmp[2];
  boolean_T nz;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &o_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  st.site = &o_emlrtRSI;
  st.site = &o_emlrtRSI;
  st.site = &o_emlrtRSI;
  vnorm = (q->b * q->b + q->c * q->c) + q->d * q->d;
  if (vnorm < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  vnorm = muDoubleScalarSqrt(vnorm);
  st.site = &p_emlrtRSI;
  st.site = &p_emlrtRSI;
  st.site = &p_emlrtRSI;
  qnorm = q->a * q->a + vnorm * vnorm;
  if (qnorm < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  qnorm = muDoubleScalarSqrt(qnorm);
  nz = (vnorm != 0.0);
  st.site = &q_emlrtRSI;
  vscale_size[0] = 1;
  trueCount = 0;
  if (nz) {
    trueCount = 1;
  }
  vscale_size[1] = trueCount;
  if (nz) {
    vscale_data = q->a / qnorm;
  }
  st.site = &q_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  p = false;
  for (k = 0; k < trueCount; k++) {
    if (p || ((vscale_data < -1.0) || (vscale_data > 1.0))) {
      p = true;
    }
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &b_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "acos");
  }
  for (k = 0; k < trueCount; k++) {
    vscale_data = muDoubleScalarAcos(vscale_data);
  }
  k = 0;
  if (nz) {
    k = 1;
  }
  if (trueCount == k) {
    loop_ub = trueCount - 1;
    vscale_size[0] = 1;
    for (trueCount = 0; trueCount <= loop_ub; trueCount++) {
      vscale_data /= vnorm;
    }
  } else {
    binary_expand_op_3((real_T *)&vscale_data, vscale_size, vnorm, k);
  }
  st.site = &r_emlrtRSI;
  q->a = muDoubleScalarLog(qnorm);
  trueCount = 0;
  if (nz) {
    trueCount = 1;
  }
  size_tmp[0] = 1;
  size_tmp[1] = (int8_T)trueCount;
  if ((trueCount != vscale_size[1]) &&
      ((trueCount != 1) && (vscale_size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(0, 0, &f_emlrtECI, (emlrtConstCTX)sp);
  }
  k = 0;
  if (nz) {
    k = 1;
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
  if (k != tmp_size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(k, tmp_size[1], &e_emlrtECI,
                                    (emlrtConstCTX)sp);
  }
  vnorm = q->b;
  if (tmp_size[1] - 1 >= 0) {
    vnorm = tmp_data;
  }
  p = !nz;
  if (p) {
    vnorm = 0.0;
  }
  q->b = vnorm;
  trueCount = 0;
  if (nz) {
    trueCount = 1;
  }
  size_tmp[0] = 1;
  size_tmp[1] = (int8_T)trueCount;
  if ((trueCount != vscale_size[1]) &&
      ((trueCount != 1) && (vscale_size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(0, 0, &d_emlrtECI, (emlrtConstCTX)sp);
  }
  k = 0;
  if (nz) {
    k = 1;
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
  if (k != tmp_size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(k, tmp_size[1], &c_emlrtECI,
                                    (emlrtConstCTX)sp);
  }
  vnorm = q->c;
  if (tmp_size[1] - 1 >= 0) {
    vnorm = tmp_data;
  }
  if (p) {
    vnorm = 0.0;
  }
  q->c = vnorm;
  trueCount = 0;
  if (nz) {
    trueCount = 1;
  }
  size_tmp[0] = 1;
  size_tmp[1] = (int8_T)trueCount;
  if ((trueCount != vscale_size[1]) &&
      ((trueCount != 1) && (vscale_size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(0, 0, &b_emlrtECI, (emlrtConstCTX)sp);
  }
  k = 0;
  if (nz) {
    k = 1;
  }
  if (trueCount == vscale_size[1]) {
    loop_ub = vscale_size[1] - 1;
    vscale_size[1] = trueCount;
    for (trueCount = 0; trueCount <= loop_ub; trueCount++) {
      vscale_data *= q->d;
    }
  } else {
    binary_expand_op((real_T *)&vscale_data, vscale_size, q, size_tmp);
  }
  if (k != vscale_size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(k, vscale_size[1], &emlrtECI,
                                    (emlrtConstCTX)sp);
  }
  vnorm = q->d;
  if (vscale_size[1] - 1 >= 0) {
    vnorm = vscale_data;
  }
  if (p) {
    vnorm = 0.0;
  }
  q->d = vnorm;
}

/* End of code generation (log.c) */
