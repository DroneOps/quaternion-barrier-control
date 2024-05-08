/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rotvec.h
 *
 * Code generation for function 'rotvec'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void quaternionBase_rotvec(const emlrtStack *sp, real_T q_a, real_T q_b,
                           real_T q_c, real_T q_d, real_T rv[3]);

/* End of code generation (rotvec.h) */
