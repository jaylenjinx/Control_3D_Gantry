/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GANTRY_SYSID_private.h
 *
 * Code generated for Simulink model 'GANTRY_SYSID'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri Oct 11 19:03:23 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef GANTRY_SYSID_private_h_
#define GANTRY_SYSID_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "GANTRY_SYSID.h"
#include "GANTRY_SYSID_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void GANTRY__BiPolarCalibration_Init(DW_BiPolarCalibration_GANTRY__T
  *localDW);
extern void GANTRY_SYSID_BiPolarCalibration(real_T rtu_u, real_T *rty_y,
  DW_BiPolarCalibration_GANTRY__T *localDW);

#endif                                 /* GANTRY_SYSID_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
