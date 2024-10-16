/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: OutputCalibration.c
 *
 * Code generated for Simulink model 'OutputCalibration'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Oct 16 11:57:03 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "OutputCalibration.h"
#include "OutputCalibration_private.h"

/* Block signals (default storage) */
B_OutputCalibration_T OutputCalibration_B;

/* Block states (default storage) */
DW_OutputCalibration_T OutputCalibration_DW;

/* Real-time model */
static RT_MODEL_OutputCalibration_T OutputCalibration_M_;
RT_MODEL_OutputCalibration_T *const OutputCalibration_M = &OutputCalibration_M_;

/* Model step function */
void OutputCalibration_step(void)
{
  /* MATLABSystem: '<Root>/Digital Read' */
  OutputCalibration_B.btn = MW_digitalIO_read
    (OutputCalibration_DW.obj.MW_DIGITALIO_HANDLE);

  /* MATLAB Function: '<Root>/MATLAB Function' */
  if (OutputCalibration_B.btn && (OutputCalibration_DW.db == 0.0)) {
    OutputCalibration_DW.db = 1.0;
    OutputCalibration_DW.m += 10.0;
  }

  if (OutputCalibration_DW.db == 1.0) {
    if (OutputCalibration_DW.i > 200.0) {
      OutputCalibration_DW.db = 0.0;
      OutputCalibration_DW.i = 0.0;
    } else {
      OutputCalibration_DW.i++;
    }
  }

  OutputCalibration_B.v = OutputCalibration_DW.m;

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(OutputCalibration_DW.obj_o.MW_PWM_HANDLE,
                      OutputCalibration_B.v);

  /* MATLABSystem: '<Root>/PWM Output1' */
  MW_PWM_SetDutyCycle(OutputCalibration_DW.obj_p.MW_PWM_HANDLE,
                      OutputCalibration_B.v);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  OutputCalibration_M->Timing.taskTime0 =
    ((time_T)(++OutputCalibration_M->Timing.clockTick0)) *
    OutputCalibration_M->Timing.stepSize0;
}

/* Model initialize function */
void OutputCalibration_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(OutputCalibration_M, -1);
  OutputCalibration_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  OutputCalibration_M->Sizes.checksums[0] = (1227804786U);
  OutputCalibration_M->Sizes.checksums[1] = (4007940911U);
  OutputCalibration_M->Sizes.checksums[2] = (3553038413U);
  OutputCalibration_M->Sizes.checksums[3] = (3599499608U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    OutputCalibration_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(OutputCalibration_M->extModeInfo,
      &OutputCalibration_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(OutputCalibration_M->extModeInfo,
                        OutputCalibration_M->Sizes.checksums);
    rteiSetTPtr(OutputCalibration_M->extModeInfo, rtmGetTPtr(OutputCalibration_M));
  }

  /* Start for MATLABSystem: '<Root>/Digital Read' */
  OutputCalibration_DW.obj.matlabCodegenIsDeleted = false;
  OutputCalibration_DW.obj.isInitialized = 1;
  OutputCalibration_DW.obj.MW_DIGITALIO_HANDLE = MW_digitalIO_open(PC_13, 0);
  OutputCalibration_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM Output' */
  OutputCalibration_DW.obj_o.matlabCodegenIsDeleted = false;
  OutputCalibration_DW.obj_o.isInitialized = 1;
  OutputCalibration_DW.obj_o.MW_PWM_HANDLE = MW_PWM_Open(PA_6, 10000.0, 57.6);
  MW_PWM_Start(OutputCalibration_DW.obj_o.MW_PWM_HANDLE);
  OutputCalibration_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM Output1' */
  OutputCalibration_DW.obj_p.matlabCodegenIsDeleted = false;
  OutputCalibration_DW.obj_p.isInitialized = 1;
  OutputCalibration_DW.obj_p.MW_PWM_HANDLE = MW_PWM_Open(PC_7, 10000.0, 57.6);
  MW_PWM_Start(OutputCalibration_DW.obj_p.MW_PWM_HANDLE);
  OutputCalibration_DW.obj_p.isSetupComplete = true;
}

/* Model terminate function */
void OutputCalibration_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  if (!OutputCalibration_DW.obj.matlabCodegenIsDeleted) {
    OutputCalibration_DW.obj.matlabCodegenIsDeleted = true;
    if ((OutputCalibration_DW.obj.isInitialized == 1) &&
        OutputCalibration_DW.obj.isSetupComplete) {
      MW_digitalIO_close(OutputCalibration_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  if (!OutputCalibration_DW.obj_o.matlabCodegenIsDeleted) {
    OutputCalibration_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((OutputCalibration_DW.obj_o.isInitialized == 1) &&
        OutputCalibration_DW.obj_o.isSetupComplete) {
      MW_PWM_Stop(OutputCalibration_DW.obj_o.MW_PWM_HANDLE);
      MW_PWM_Close(OutputCalibration_DW.obj_o.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output1' */
  if (!OutputCalibration_DW.obj_p.matlabCodegenIsDeleted) {
    OutputCalibration_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((OutputCalibration_DW.obj_p.isInitialized == 1) &&
        OutputCalibration_DW.obj_p.isSetupComplete) {
      MW_PWM_Stop(OutputCalibration_DW.obj_p.MW_PWM_HANDLE);
      MW_PWM_Close(OutputCalibration_DW.obj_p.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
