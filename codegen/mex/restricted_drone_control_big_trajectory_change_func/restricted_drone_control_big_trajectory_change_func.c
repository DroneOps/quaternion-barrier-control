/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * restricted_drone_control_big_trajectory_change_func.c
 *
 * Code generation for function
 * 'restricted_drone_control_big_trajectory_change_func'
 *
 */

/* Include files */
#include "restricted_drone_control_big_trajectory_change_func.h"
#include "exp.h"
#include "log.h"
#include "mldivide.h"
#include "normalize.h"
#include "restricted_drone_control_big_trajectory_change_func_data.h"
#include "restricted_drone_control_big_trajectory_change_func_internal_types.h"
#include "rotvec.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    176,                                                   /* lineNo */
    "restricted_drone_control_big_trajectory_change_func", /* fcnName */
    "/home/paco/Research/Quadrotor_State_Restricted_Control/"
    "quaternion-barrier-control/restricted_drone_control_big_trajectory_change"
    "_func.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    167,                                                   /* lineNo */
    "restricted_drone_control_big_trajectory_change_func", /* fcnName */
    "/home/paco/Research/Quadrotor_State_Restricted_Control/"
    "quaternion-barrier-control/restricted_drone_control_big_trajectory_change"
    "_func.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    166,                                                   /* lineNo */
    "restricted_drone_control_big_trajectory_change_func", /* fcnName */
    "/home/paco/Research/Quadrotor_State_Restricted_Control/"
    "quaternion-barrier-control/restricted_drone_control_big_trajectory_change"
    "_func.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    141,                                                   /* lineNo */
    "restricted_drone_control_big_trajectory_change_func", /* fcnName */
    "/home/paco/Research/Quadrotor_State_Restricted_Control/"
    "quaternion-barrier-control/restricted_drone_control_big_trajectory_change"
    "_func.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    139,                                                   /* lineNo */
    "restricted_drone_control_big_trajectory_change_func", /* fcnName */
    "/home/paco/Research/Quadrotor_State_Restricted_Control/"
    "quaternion-barrier-control/restricted_drone_control_big_trajectory_change"
    "_func.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    138,                                                   /* lineNo */
    "restricted_drone_control_big_trajectory_change_func", /* fcnName */
    "/home/paco/Research/Quadrotor_State_Restricted_Control/"
    "quaternion-barrier-control/restricted_drone_control_big_trajectory_change"
    "_func.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    135,                                                   /* lineNo */
    "restricted_drone_control_big_trajectory_change_func", /* fcnName */
    "/home/paco/Research/Quadrotor_State_Restricted_Control/"
    "quaternion-barrier-control/restricted_drone_control_big_trajectory_change"
    "_func.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    134,                                                   /* lineNo */
    "restricted_drone_control_big_trajectory_change_func", /* fcnName */
    "/home/paco/Research/Quadrotor_State_Restricted_Control/"
    "quaternion-barrier-control/restricted_drone_control_big_trajectory_change"
    "_func.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    107,                                                   /* lineNo */
    "restricted_drone_control_big_trajectory_change_func", /* fcnName */
    "/home/paco/Research/Quadrotor_State_Restricted_Control/"
    "quaternion-barrier-control/restricted_drone_control_big_trajectory_change"
    "_func.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    25,                                                    /* lineNo */
    "restricted_drone_control_big_trajectory_change_func", /* fcnName */
    "/home/paco/Research/Quadrotor_State_Restricted_Control/"
    "quaternion-barrier-control/restricted_drone_control_big_trajectory_change"
    "_func.m" /* pathName */
};

static emlrtMCInfo emlrtMCI = {
    142,                                                   /* lineNo */
    9,                                                     /* colNo */
    "restricted_drone_control_big_trajectory_change_func", /* fName */
    "/home/paco/Research/Quadrotor_State_Restricted_Control/"
    "quaternion-barrier-control/restricted_drone_control_big_trajectory_change"
    "_func.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    1,                                                     /* iFirst */
    15000,                                                 /* iLast */
    171,                                                   /* lineNo */
    22,                                                    /* colNo */
    "plot_position",                                       /* aName */
    "restricted_drone_control_big_trajectory_change_func", /* fName */
    "/home/paco/Research/Quadrotor_State_Restricted_Control/"
    "quaternion-barrier-control/restricted_drone_control_big_trajectory_change"
    "_func.m", /* pName */
    3          /* checkKind */
};

static emlrtRSInfo fb_emlrtRSI = {
    142,                                                   /* lineNo */
    "restricted_drone_control_big_trajectory_change_func", /* fcnName */
    "/home/paco/Research/Quadrotor_State_Restricted_Control/"
    "quaternion-barrier-control/restricted_drone_control_big_trajectory_change"
    "_func.m" /* pathName */
};

/* Function Declarations */
static void disp(const emlrtStack *sp, const mxArray *m, emlrtMCInfo *location);

/* Function Definitions */
static void disp(const emlrtStack *sp, const mxArray *m, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = m;
  emlrtCallMATLABR2012b((emlrtConstCTX)sp, 0, NULL, 1, &pArray, "disp", true,
                        location);
}

real_T restricted_drone_control_big_trajectory_change_func(const emlrtStack *sp)
{
  static const real_T a[9] = {1.66E-5, 8.3E-7, 7.2E-7, 8.3E-7, 1.66E-5,
                              1.8E-6,  7.2E-7, 1.8E-6, 2.93E-5};
  static const int32_T iv[2] = {1, 19};
  static const char_T u[19] = {'I', 'n', 'v', 'e', 'r', 't', 'i', 'n', 'g', ' ',
                               'r', 'e', 'f', 'e', 'r', 'e', 'n', 'c', 'e'};
  __m128d r;
  ptrdiff_t b_incx_t;
  ptrdiff_t b_incy_t;
  ptrdiff_t b_n_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack st;
  const mxArray *m;
  const mxArray *y;
  quaternion desired_orientation;
  quaternion orientation;
  real_T varargin_1[4];
  real_T a_tmp_data[3];
  real_T ang_kd[3];
  real_T ang_kp[3];
  real_T angular_velocity[3];
  real_T angular_velocity_error[3];
  real_T b_angular_velocity[3];
  real_T b_data[3];
  real_T b_unusedExpr[3];
  real_T desired_position[3];
  real_T orientation_error_vector[3];
  real_T position[3];
  real_T position_error[3];
  real_T position_error_prev[3];
  real_T trans_kd_dot[3];
  real_T unusedExpr[3];
  real_T velocity[3];
  real_T velocity_error[3];
  real_T i;
  real_T orientation_error_a;
  real_T orientation_error_b;
  real_T orientation_error_c;
  real_T orientation_error_d;
  real_T t;
  real_T trans_kd_idx_0;
  real_T trans_kd_idx_1;
  real_T trans_kd_idx_2;
  real_T trans_kp_idx_0;
  real_T trans_kp_idx_1;
  real_T trans_kp_idx_2;
  int32_T l;
  st.prev = sp;
  st.tls = sp->tls;
  /*  Drone parameters */
  /*  kg */
  /* from bitcraze */
  /*  Simulation parameters */
  /*  seconds */
  i = 1.0;
  t = 0.0;
  /*  Initialize state variables */
  position[0] = 0.0;
  position[1] = 0.0;
  position[2] = 0.0;
  orientation.a = 1.0;
  orientation.b = 0.0;
  orientation.c = 0.0;
  orientation.d = 0.0;
  st.site = &k_emlrtRSI;
  quaternionBase_normalize(&st, &orientation);
  /*  Control Variables */
  /* Translational control gains */
  /* Rotational control gains */
  /* Adaptive and restriction control gains and constants */
  /* lambda 1 affects the proportional gain both related to the reference */
  /*  and the restriction */
  /*  lambda 2 affects the rate of change of said gain; the lower it is, the */
  /*  faster it can change, this is reflected as the trajectory gets near the */
  /*  restriction, as it rejects it more strongly. However it looses */
  /*  controlablity when it reaches a certain distance from the restriction. */
  /*  Said distance would be lower if this number was higher, but this would */
  /*  also imply  */
  /*  lambda 3 affects velocity and 4 affects its rate of change */
  /*  so on can be inferred for alph, however, restrictions are only related */
  /*  to position. */
  /*  Desired variables */
  /*  Error */
  orientation_error_a = orientation.a;
  orientation_error_b = orientation.b;
  orientation_error_c = orientation.c;
  orientation_error_d = orientation.d;
  velocity[0] = 0.0;
  angular_velocity[0] = 0.0;
  trans_kp_idx_0 = 4.0;
  trans_kd_idx_0 = 3.75;
  ang_kp[0] = 150.0;
  ang_kd[0] = 50.0;
  position_error[0] = 0.7;
  velocity[1] = 0.0;
  angular_velocity[1] = 0.0;
  trans_kp_idx_1 = 4.0;
  trans_kd_idx_1 = 3.75;
  ang_kp[1] = 150.0;
  ang_kd[1] = 50.0;
  position_error[1] = 0.7;
  velocity[2] = 0.0;
  angular_velocity[2] = 0.0;
  trans_kp_idx_2 = 4.0;
  trans_kd_idx_2 = 3.75;
  ang_kp[2] = 150.0;
  ang_kd[2] = 50.0;
  position_error[2] = -0.0;
  /*  Auxiliary variables for plotting  */
  /*  Simulation loop */
  r = _mm_set1_pd(0.001);
  a_tmp_data[0] = 0.0;
  a_tmp_data[1] = 0.0;
  a_tmp_data[2] = 1.0;
  n_t = (ptrdiff_t)3;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  b_n_t = (ptrdiff_t)3;
  b_incx_t = (ptrdiff_t)1;
  b_incy_t = (ptrdiff_t)1;
  while (t < 15.0) {
    __m128d r1;
    __m128d r2;
    __m128d r3;
    __m128d r4;
    __m128d r5;
    real_T absxk;
    real_T b_r;
    real_T b_t;
    real_T b_xa_tmp;
    real_T b_xb_tmp;
    real_T c;
    real_T c_xa_tmp;
    real_T d_xa_tmp;
    real_T orientation_error_b_tmp;
    real_T orientation_error_c_tmp;
    real_T orientation_error_d_tmp;
    real_T orientation_error_prev_b;
    real_T orientation_error_prev_c;
    real_T scale;
    real_T xa_tmp;
    real_T xb_tmp;
    if (t < 2.0) {
      desired_position[0] = -0.7;
      desired_position[1] = -0.7;
      desired_position[2] = 0.0;
    } else if (t < 6.0) {
      desired_position[0] = 1.5;
      desired_position[1] = 0.0;
      desired_position[2] = 0.0;
    } else if (t < 9.0) {
      desired_position[0] = 0.0;
      desired_position[1] = 1.5;
      desired_position[2] = 0.0;
    } else {
      desired_position[0] = 0.0;
      desired_position[1] = 0.0;
      desired_position[2] = 0.0;
    }
    /*  desired_position = [t;t;t]; */
    r1 = _mm_loadu_pd(&position_error[0]);
    _mm_storeu_pd(&position_error_prev[0], r1);
    r2 = _mm_loadu_pd(&position[0]);
    r3 = _mm_loadu_pd(&desired_position[0]);
    r2 = _mm_sub_pd(r2, r3);
    _mm_storeu_pd(&position_error[0], r2);
    _mm_storeu_pd(&velocity_error[0], _mm_div_pd(_mm_sub_pd(r2, r1), r));
    absxk = position_error[2];
    orientation_error_prev_c = absxk;
    position_error_prev[2] = absxk;
    absxk = position[2] - desired_position[2];
    position_error[2] = absxk;
    velocity_error[2] = (absxk - orientation_error_prev_c) / 0.001;
    st.site = &j_emlrtRSI;
    b_r = (position[0] * position[0] + position[1] * position[1]) +
          position[2] * position[2];
    if (b_r < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    b_r = muDoubleScalarSqrt(b_r);
    /* position relative to the origin */
    t += 0.001;
    /*  Estimate translational control gains */
    absxk = position_error[0];
    orientation_error_prev_c =
        0.05 * velocity_error[0] + 0.005 * (3.75 - trans_kd_idx_0);
    b_r = -1.25 / (2.25 - b_r * b_r);
    trans_kp_idx_0 += (b_r * absxk * muDoubleScalarSign(absxk) +
                       0.005 * (4.0 - trans_kp_idx_0)) *
                      0.001;
    trans_kd_idx_0 += orientation_error_prev_c * 0.001;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    absxk = position_error[1];
    orientation_error_prev_c =
        0.05 * velocity_error[1] + 0.005 * (3.75 - trans_kd_idx_1);
    trans_kp_idx_1 += (b_r * absxk * muDoubleScalarSign(absxk) +
                       0.005 * (4.0 - trans_kp_idx_1)) *
                      0.001;
    trans_kd_idx_1 += orientation_error_prev_c * 0.001;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    absxk = position_error[2];
    orientation_error_prev_c =
        0.05 * velocity_error[2] + 0.005 * (3.75 - trans_kd_idx_2);
    trans_kp_idx_2 += (b_r * absxk * muDoubleScalarSign(absxk) +
                       0.005 * (4.0 - trans_kp_idx_2)) *
                      0.001;
    trans_kd_idx_2 += orientation_error_prev_c * 0.001;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    /*  Translational Control */
    scale = 3.3121686421112381E-170;
    absxk = velocity_error[0];
    absxk =
        -0.027 * (trans_kp_idx_0 * position_error[0] + trans_kd_idx_0 * absxk);
    velocity_error[0] = absxk;
    absxk = muDoubleScalarAbs(absxk);
    if (absxk > 3.3121686421112381E-170) {
      b_r = 1.0;
      scale = absxk;
    } else {
      b_t = absxk / 3.3121686421112381E-170;
      b_r = b_t * b_t;
    }
    desired_position[0] = 0.0;
    absxk = velocity_error[1];
    absxk =
        -0.027 * (trans_kp_idx_1 * position_error[1] + trans_kd_idx_1 * absxk);
    velocity_error[1] = absxk;
    absxk = muDoubleScalarAbs(absxk);
    if (absxk > scale) {
      b_t = scale / absxk;
      b_r = b_r * b_t * b_t + 1.0;
      scale = absxk;
    } else {
      b_t = absxk / scale;
      b_r += b_t * b_t;
    }
    desired_position[1] = 0.0;
    absxk = velocity_error[2];
    absxk =
        -0.027 *
        ((trans_kp_idx_2 * position_error[2] + trans_kd_idx_2 * absxk) - 9.81);
    velocity_error[2] = absxk;
    absxk = muDoubleScalarAbs(absxk);
    if (absxk > scale) {
      b_t = scale / absxk;
      b_r = b_r * b_t * b_t + 1.0;
      scale = absxk;
    } else {
      b_t = absxk / scale;
      b_r += b_t * b_t;
    }
    desired_position[2] = 0.0;
    b_r = scale * muDoubleScalarSqrt(b_r);
    if (b_r != 0.0) {
      r1 = _mm_loadu_pd(&velocity_error[0]);
      _mm_storeu_pd(&desired_position[0], _mm_div_pd(r1, _mm_set1_pd(b_r)));
      desired_position[2] = velocity_error[2] / b_r;
      /* Fu */
    }
    xa_tmp = orientation.a * 0.0;
    b_xa_tmp = orientation.b * 0.0;
    c_xa_tmp = orientation.c * 0.0;
    d_xa_tmp = (xa_tmp - b_xa_tmp) - c_xa_tmp;
    b_r = d_xa_tmp - orientation.d;
    xb_tmp = orientation.d * 0.0;
    b_xb_tmp = xa_tmp + b_xa_tmp;
    absxk = (b_xb_tmp + orientation.c) - xb_tmp;
    b_t = ((xa_tmp - orientation.b) + c_xa_tmp) + xb_tmp;
    scale = ((orientation.a + b_xa_tmp) - c_xa_tmp) + xb_tmp;
    /* Fth */
    b_data[0] = ((b_r * -orientation.b + absxk * orientation.a) +
                 b_t * -orientation.d) -
                scale * -orientation.c;
    b_data[1] = ((b_r * -orientation.c - absxk * -orientation.d) +
                 b_t * orientation.a) +
                scale * -orientation.b;
    b_data[2] = ((b_r * -orientation.d + absxk * -orientation.c) -
                 b_t * -orientation.b) +
                scale * orientation.a;
    c = ddot(&n_t, &a_tmp_data[0], &incx_t, &b_data[0], &incy_t);
    /*  Orientation Control */
    b_data[0] = desired_position[0];
    b_data[1] = desired_position[1];
    b_data[2] = desired_position[2];
    b_r = ddot(&b_n_t, &a_tmp_data[0], &b_incx_t, &b_data[0], &b_incy_t);
    varargin_1[1] = 0.0 * desired_position[2] - desired_position[1];
    varargin_1[2] = desired_position[0] - 0.0 * desired_position[2];
    varargin_1[3] = 0.0 * desired_position[1] - 0.0 * desired_position[0];
    desired_orientation.a = b_r;
    desired_orientation.b = varargin_1[1];
    desired_orientation.c = varargin_1[2];
    desired_orientation.d = varargin_1[3];
    st.site = &h_emlrtRSI;
    quaternionBase_log(&st, &desired_orientation);
    desired_orientation.a *= 0.5;
    desired_orientation.b *= 0.5;
    desired_orientation.c *= 0.5;
    desired_orientation.d *= 0.5;
    st.site = &h_emlrtRSI;
    quaternionBase_exp(&st, &desired_orientation);
    st.site = &g_emlrtRSI;
    quaternionBase_normalize(&st, &desired_orientation);
    b_r = orientation_error_a;
    orientation_error_prev_b = orientation_error_b;
    orientation_error_prev_c = orientation_error_c;
    absxk = orientation_error_d;
    orientation_error_a = ((orientation.a * desired_orientation.a -
                            orientation.b * -desired_orientation.b) -
                           orientation.c * -desired_orientation.c) -
                          orientation.d * -desired_orientation.d;
    orientation_error_b_tmp = orientation.a * -desired_orientation.b;
    orientation_error_b =
        ((orientation_error_b_tmp + orientation.b * desired_orientation.a) +
         orientation.c * -desired_orientation.d) -
        orientation.d * -desired_orientation.c;
    orientation_error_c_tmp = orientation.a * -desired_orientation.c;
    orientation_error_c =
        ((orientation_error_c_tmp - orientation.b * -desired_orientation.d) +
         orientation.c * desired_orientation.a) +
        orientation.d * -desired_orientation.b;
    orientation_error_d_tmp = orientation.a * -desired_orientation.d;
    orientation_error_d =
        ((orientation_error_d_tmp + orientation.b * -desired_orientation.c) -
         orientation.c * -desired_orientation.b) +
        orientation.d * desired_orientation.a;
    st.site = &f_emlrtRSI;
    quaternionBase_rotvec(&st, orientation_error_a, orientation_error_b,
                          orientation_error_c, orientation_error_d,
                          orientation_error_vector);
    /* Euler angle representation */
    st.site = &e_emlrtRSI;
    quaternionBase_rotvec(&st,
                          ((orientation_error_a * b_r -
                            orientation_error_b * -orientation_error_prev_b) -
                           orientation_error_c * -orientation_error_prev_c) -
                              orientation_error_d * -absxk,
                          ((orientation_error_a * -orientation_error_prev_b +
                            orientation_error_b * b_r) +
                           orientation_error_c * -absxk) -
                              orientation_error_d * -orientation_error_prev_c,
                          ((orientation_error_a * -orientation_error_prev_c -
                            orientation_error_b * -absxk) +
                           orientation_error_c * b_r) +
                              orientation_error_d * -orientation_error_prev_b,
                          ((orientation_error_a * -absxk +
                            orientation_error_b * -orientation_error_prev_c) -
                           orientation_error_c * -orientation_error_prev_b) +
                              orientation_error_d * b_r,
                          angular_velocity_error);
    r1 = _mm_loadu_pd(&angular_velocity_error[0]);
    _mm_storeu_pd(&angular_velocity_error[0], _mm_div_pd(r1, r));
    angular_velocity_error[2] /= 0.001;
    st.site = &d_emlrtRSI;
    quaternionBase_rotvec(&st, orientation_error_a, orientation_error_b,
                          orientation_error_c, orientation_error_d,
                          desired_position);
    scale = 3.3121686421112381E-170;
    absxk = muDoubleScalarAbs(desired_position[0]);
    if (absxk > 3.3121686421112381E-170) {
      b_r = 1.0;
      scale = absxk;
    } else {
      b_t = absxk / 3.3121686421112381E-170;
      b_r = b_t * b_t;
    }
    absxk = muDoubleScalarAbs(desired_position[1]);
    if (absxk > scale) {
      b_t = scale / absxk;
      b_r = b_r * b_t * b_t + 1.0;
      scale = absxk;
    } else {
      b_t = absxk / scale;
      b_r += b_t * b_t;
    }
    absxk = muDoubleScalarAbs(desired_position[2]);
    if (absxk > scale) {
      b_t = scale / absxk;
      b_r = b_r * b_t * b_t + 1.0;
      scale = absxk;
    } else {
      b_t = absxk / scale;
      b_r += b_t * b_t;
    }
    b_r = scale * muDoubleScalarSqrt(b_r);
    if (b_r > 3.1415926535897931) {
      y = NULL;
      m = emlrtCreateCharArray(2, &iv[0]);
      emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 19, m, &u[0]);
      emlrtAssign(&y, m);
      st.site = &fb_emlrtRSI;
      disp(&st, y, &emlrtMCI);
      desired_orientation.a = -desired_orientation.a;
      desired_orientation.b = -desired_orientation.b;
      desired_orientation.c = -desired_orientation.c;
      desired_orientation.d = -desired_orientation.d;
      orientation_error_a = ((desired_orientation.a * orientation.a -
                              desired_orientation.b * -orientation.b) -
                             desired_orientation.c * -orientation.c) -
                            desired_orientation.d * -orientation.d;
      orientation_error_b =
          ((desired_orientation.a * -orientation.b + orientation_error_b_tmp) +
           desired_orientation.c * -orientation.d) -
          desired_orientation.d * -orientation.c;
      orientation_error_c = ((desired_orientation.a * -orientation.c -
                              desired_orientation.b * -orientation.d) +
                             orientation_error_c_tmp) +
                            desired_orientation.d * -orientation.b;
      orientation_error_d = ((desired_orientation.a * -orientation.d +
                              desired_orientation.b * -orientation.c) -
                             desired_orientation.c * -orientation.b) +
                            orientation_error_d_tmp;
    } else {
      st.site = &d_emlrtRSI;
      quaternionBase_rotvec(&st, orientation_error_a, orientation_error_b,
                            orientation_error_c, orientation_error_d,
                            unusedExpr);
    }
    /*  Estimate rotational control gains */
    absxk = ang_kp[0];
    orientation_error_prev_c =
        6.0 * orientation_error_vector[0] + 0.005 * (150.0 - absxk);
    b_r = ang_kd[0];
    orientation_error_prev_b =
        8.0 * angular_velocity_error[0] + 0.005 * (50.0 - b_r);
    absxk += orientation_error_prev_c * 0.001;
    ang_kp[0] = absxk;
    b_r += orientation_error_prev_b * 0.001;
    ang_kd[0] = b_r;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    absxk = ang_kp[1];
    orientation_error_prev_c =
        6.0 * orientation_error_vector[1] + 0.005 * (150.0 - absxk);
    b_r = ang_kd[1];
    orientation_error_prev_b =
        8.0 * angular_velocity_error[1] + 0.005 * (50.0 - b_r);
    absxk += orientation_error_prev_c * 0.001;
    ang_kp[1] = absxk;
    b_r += orientation_error_prev_b * 0.001;
    ang_kd[1] = b_r;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    absxk = ang_kp[2];
    orientation_error_prev_c =
        6.0 * orientation_error_vector[2] + 0.005 * (150.0 - absxk);
    b_r = ang_kd[2];
    orientation_error_prev_b =
        8.0 * angular_velocity_error[2] + 0.005 * (50.0 - b_r);
    absxk += orientation_error_prev_c * 0.001;
    ang_kp[2] = absxk;
    b_r += orientation_error_prev_b * 0.001;
    ang_kd[2] = b_r;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
    /*  Update orientation and position */
    b_r = muDoubleScalarAbs(velocity_error[2] / c) / 0.027;
    scale = muDoubleScalarAbs(velocity_error[2] / c) / 0.027;
    orientation_error_prev_b = d_xa_tmp - orientation.d * b_r;
    orientation_error_c_tmp = (b_xb_tmp + orientation.c * b_r) - xb_tmp;
    orientation_error_d_tmp =
        ((xa_tmp - orientation.b * b_r) + c_xa_tmp) + xb_tmp;
    orientation_error_b_tmp =
        ((orientation.a * b_r + b_xa_tmp) - c_xa_tmp) + xb_tmp;
    b_r = velocity[0];
    absxk = velocity[1];
    b_t = velocity[2];
    velocity[0] = b_r + (((orientation_error_prev_b * -orientation.b +
                           orientation_error_c_tmp * orientation.a) +
                          orientation_error_d_tmp * -orientation.d) -
                         orientation_error_b_tmp * -orientation.c) *
                            0.001;
    velocity[1] = absxk + (((orientation_error_prev_b * -orientation.c -
                             orientation_error_c_tmp * -orientation.d) +
                            orientation_error_d_tmp * orientation.a) +
                           orientation_error_b_tmp * -orientation.b) *
                              0.001;
    velocity[2] =
        b_t +
        (((((d_xa_tmp - orientation.d * scale) * -orientation.d +
            ((b_xb_tmp + orientation.c * scale) - xb_tmp) * -orientation.c) -
           (((xa_tmp - orientation.b * scale) + c_xa_tmp) + xb_tmp) *
               -orientation.b) +
          (((orientation.a * scale + b_xa_tmp) - c_xa_tmp) + xb_tmp) *
              orientation.a) -
         9.81) *
            0.001;
    r1 = _mm_loadu_pd(&a[0]);
    r1 = _mm_mul_pd(r1, _mm_set1_pd(angular_velocity[0]));
    r2 = _mm_loadu_pd(&a[3]);
    r2 = _mm_mul_pd(r2, _mm_set1_pd(angular_velocity[1]));
    r1 = _mm_add_pd(r1, r2);
    r2 = _mm_loadu_pd(&a[6]);
    r2 = _mm_mul_pd(r2, _mm_set1_pd(angular_velocity[2]));
    r1 = _mm_add_pd(r1, r2);
    _mm_storeu_pd(&desired_position[0], r1);
    r1 = _mm_loadu_pd(&velocity[0]);
    r1 = _mm_mul_pd(r1, _mm_set1_pd(0.001));
    r2 = _mm_loadu_pd(&position[0]);
    r1 = _mm_add_pd(r2, r1);
    _mm_storeu_pd(&position[0], r1);
    r1 = _mm_loadu_pd(&angular_velocity[0]);
    _mm_storeu_pd(&varargin_1[1], r1);
    absxk = angular_velocity[0] * a[2];
    absxk += angular_velocity[1] * a[5];
    absxk += angular_velocity[2] * a[8];
    desired_position[2] = absxk;
    position[2] += velocity[2] * 0.001;
    varargin_1[3] = angular_velocity[2];
    orientation_error_c_tmp = 0.5 * varargin_1[1];
    orientation_error_d_tmp = 0.5 * varargin_1[2];
    orientation_error_b_tmp = 0.5 * varargin_1[3];
    orientation_error_prev_c =
        orientation.b +
        0.001 * (((b_xa_tmp + orientation_error_c_tmp * orientation.a) +
                  orientation_error_d_tmp * orientation.d) -
                 orientation_error_b_tmp * orientation.c);
    orientation_error_prev_b =
        orientation.c +
        0.001 * (((c_xa_tmp - orientation_error_c_tmp * orientation.d) +
                  orientation_error_d_tmp * orientation.a) +
                 orientation_error_b_tmp * orientation.b);
    b_r = orientation.d +
          0.001 * (((xb_tmp + orientation_error_c_tmp * orientation.c) -
                    orientation_error_d_tmp * orientation.b) +
                   orientation_error_b_tmp * orientation.a);
    orientation.a +=
        0.001 * (((xa_tmp - orientation_error_c_tmp * orientation.b) -
                  orientation_error_d_tmp * orientation.c) -
                 orientation_error_b_tmp * orientation.d);
    orientation.b = orientation_error_prev_c;
    orientation.c = orientation_error_prev_b;
    orientation.d = b_r;
    st.site = &c_emlrtRSI;
    quaternionBase_normalize(&st, &orientation);
    b_r = desired_position[2];
    orientation_error_prev_b = desired_position[1];
    orientation_error_prev_c = desired_position[0];
    absxk = desired_position[2];
    b_t = desired_position[1];
    scale = desired_position[0];
    b_angular_velocity[0] = angular_velocity[1] * b_r -
                            orientation_error_prev_b * angular_velocity[2];
    b_angular_velocity[1] = orientation_error_prev_c * angular_velocity[2] -
                            angular_velocity[0] * absxk;
    b_angular_velocity[2] =
        angular_velocity[0] * b_t - scale * angular_velocity[1];
    r1 = _mm_loadu_pd(&ang_kp[0]);
    r2 = _mm_loadu_pd(&orientation_error_vector[0]);
    r3 = _mm_loadu_pd(&ang_kd[0]);
    r4 = _mm_loadu_pd(&angular_velocity_error[0]);
    r5 = _mm_loadu_pd(&b_angular_velocity[0]);
    _mm_storeu_pd(
        &orientation_error_vector[0],
        _mm_add_pd(_mm_sub_pd(_mm_mul_pd(_mm_mul_pd(r1, _mm_set1_pd(-1.0)), r2),
                              _mm_mul_pd(r3, r4)),
                   r5));
    orientation_error_vector[2] = (-ang_kp[2] * orientation_error_vector[2] -
                                   ang_kd[2] * angular_velocity_error[2]) +
                                  b_angular_velocity[2];
    b_r = desired_position[2];
    orientation_error_prev_b = desired_position[1];
    orientation_error_prev_c = desired_position[0];
    absxk = desired_position[2];
    b_t = desired_position[1];
    scale = desired_position[0];
    b_angular_velocity[0] = angular_velocity[1] * b_r -
                            orientation_error_prev_b * angular_velocity[2];
    b_angular_velocity[1] = orientation_error_prev_c * angular_velocity[2] -
                            angular_velocity[0] * absxk;
    b_angular_velocity[2] =
        angular_velocity[0] * b_t - scale * angular_velocity[1];
    r1 = _mm_loadu_pd(&a[0]);
    r1 = _mm_mul_pd(r1, _mm_set1_pd(orientation_error_vector[0]));
    r2 = _mm_loadu_pd(&a[3]);
    r2 = _mm_mul_pd(r2, _mm_set1_pd(orientation_error_vector[1]));
    r1 = _mm_add_pd(r1, r2);
    r2 = _mm_loadu_pd(&a[6]);
    r2 = _mm_mul_pd(r2, _mm_set1_pd(orientation_error_vector[2]));
    r1 = _mm_add_pd(r1, r2);
    r2 = _mm_loadu_pd(&b_angular_velocity[0]);
    r1 = _mm_sub_pd(r1, r2);
    _mm_storeu_pd(&trans_kd_dot[0], r1);
    absxk = orientation_error_vector[0] * a[2];
    absxk += orientation_error_vector[1] * a[5];
    absxk += orientation_error_vector[2] * a[8];
    absxk -= b_angular_velocity[2];
    trans_kd_dot[2] = absxk;
    st.site = &b_emlrtRSI;
    mldivide(&st, a, trans_kd_dot, desired_position);
    r1 = _mm_loadu_pd(&desired_position[0]);
    r2 = _mm_loadu_pd(&angular_velocity[0]);
    _mm_storeu_pd(&angular_velocity[0], _mm_add_pd(r2, _mm_mul_pd(r1, r)));
    angular_velocity[2] += desired_position[2] * 0.001;
    /*  Update plotting matrix */
    if (((int32_T)i < 1) || ((int32_T)i > 15000)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)i, 1, 15000, &emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    st.site = &emlrtRSI;
    quaternionBase_rotvec(&st, orientation_error_a, orientation_error_b,
                          orientation_error_c, orientation_error_d,
                          b_unusedExpr);
    /*  Reset adaptive control when a great change in trajectory occurs */
    for (l = 0; l < 3; l++) {
      if (muDoubleScalarAbs(position_error[l]) >
          muDoubleScalarAbs(position_error_prev[l]) + 0.2) {
        trans_kp_idx_0 = 4.0;
        trans_kd_idx_0 = 3.75;
        trans_kp_idx_1 = 4.0;
        trans_kd_idx_1 = 3.75;
        trans_kp_idx_2 = 4.0;
        trans_kd_idx_2 = 3.75;
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  %% Plotting */
  /*  figure; */
  /*  set(gcf,"Color",[1,1,1]) */
  /*  set(gcf,"Position",[50,50,1920,1080]) */
  /*  plot3(plot_position(1, :), plot_position(2, :), plot_position(3,
   * :),'LineWidth',2.5); */
  /*  hold on */
  /*  plot3(plot_desired_position(1, :), plot_desired_position(2, :),
   * plot_desired_position(3, :), 'r-.', 'LineWidth',2.5); */
  /*  [sx,sy,sz] = sphere(30); */
  /*  s =
   * surf(sx*restriction_radius,sy*restriction_radius,sz*restriction_radius); */
  /*  s.FaceAlpha = 0.5; */
  /*  s.EdgeColor = 'none'; */
  /*  xlabel('Coord. X [m]','FontSize',24); */
  /*  ylabel('Coord. Y [m]','FontSize',24); */
  /*  zlabel('Coord. Z [m]','FontSize',24); */
  /*  legend('Position ', 'Reference ', 'FontSize', 24) */
  /*  axis([-3 3 -3 3 -3 3]) */
  /*  grid off; */
  /*  print('../Plots/3D_Trajectory', '-depsc2') */
  /*   */
  /*  figure; */
  /*  set(gcf,"Color",[1,1,1]) */
  /*  set(gcf,"Position",[50,50,1920,1080]) */
  /*  plot(time, plot_attitude(1, :), 'k','LineWidth',2.5); */
  /*  hold on */
  /*  plot(time, plot_attitude(2, :), 'r','LineWidth',2.5); */
  /*  plot(time, plot_attitude(3, :), 'g','LineWidth',2.5); */
  /*  plot(time, plot_attitude(4, :), 'b','LineWidth',2.5); */
  /*  plot(time, plot_desired_attitude(1, :), 'k-.','LineWidth',2.5); */
  /*  plot(time, plot_desired_attitude(2, :), 'r-.','LineWidth',2.5); */
  /*  plot(time, plot_desired_attitude(3, :), 'g-.','LineWidth',2.5); */
  /*  plot(time, plot_desired_attitude(4, :), 'b-.','LineWidth',2.5); */
  /*  legend('q_0','q_1','q_2','q_3','q_{r0}','q_{r1}','q_{r2}','q_{r3}','FontSize',22);
   */
  /*  xlabel('Time [s]', 'FontSize',24); */
  /*  ylabel('Attitude Quaternion', 'FontSize',24); */
  /*  grid off; */
  /*  box("off"); */
  /*  print('../Plots/Attitude', '-depsc2') */
  /*   */
  /*  figure; */
  /*  set(gcf,"Color",[1,1,1]) */
  /*  set(gcf,"Position",[50,50,1920,1080]) */
  /*  plot(time,plot_position(1, :), 'k','LineWidth',2.5); */
  /*  hold on */
  /*  plot(time,plot_position(2, :), 'b','LineWidth',2.5); */
  /*  plot(time,plot_position(3, :), 'r','LineWidth',2.5); */
  /*  plot(time,plot_desired_position(1, :), 'k-.','LineWidth',2.5); */
  /*  plot(time,plot_desired_position(2, :), 'b-.','LineWidth',2.5); */
  /*  plot(time,plot_desired_position(3, :), 'r-.','LineWidth',2.5); */
  /*  ylim([-5 5]) */
  /*  legend('p_0','p_1','p_2', 'FontSize',24) */
  /*  xlabel('Time [s]','FontSize',24); */
  /*  ylabel('Position [m]','FontSize',24); */
  /*  grid off; */
  /*  box("off"); */
  /*  print('../Plots/Position', '-depsc2') */
  return i;
}

/* End of code generation
 * (restricted_drone_control_big_trajectory_change_func.c) */
