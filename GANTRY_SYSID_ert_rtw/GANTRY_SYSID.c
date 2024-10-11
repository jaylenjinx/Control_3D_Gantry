/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GANTRY_SYSID.c
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

#include "GANTRY_SYSID.h"
#include "rtwtypes.h"
#include "GANTRY_SYSID_private.h"

/* Named constants for MATLAB Function: '<Root>/BiPolar Calibration' */
#define GANTRY_SYSID_CALL_EVENT        (-1)

/* Block signals (default storage) */
B_GANTRY_SYSID_T GANTRY_SYSID_B;

/* Block states (default storage) */
DW_GANTRY_SYSID_T GANTRY_SYSID_DW;

/* Real-time model */
static RT_MODEL_GANTRY_SYSID_T GANTRY_SYSID_M_;
RT_MODEL_GANTRY_SYSID_T *const GANTRY_SYSID_M = &GANTRY_SYSID_M_;

/*
 * System initialize for atomic system:
 *    '<Root>/BiPolar Calibration'
 *    '<Root>/BiPolar Calibration1'
 */
void GANTRY__BiPolarCalibration_Init(DW_BiPolarCalibration_GANTRY__T *localDW)
{
  localDW->sfEvent = GANTRY_SYSID_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<Root>/BiPolar Calibration'
 *    '<Root>/BiPolar Calibration1'
 */
void GANTRY_SYSID_BiPolarCalibration(real_T rtu_u, real_T *rty_y,
  DW_BiPolarCalibration_GANTRY__T *localDW)
{
  localDW->sfEvent = GANTRY_SYSID_CALL_EVENT;
  *rty_y = 2.72 * rtu_u + 61.6;
}

/* Model step function */
void GANTRY_SYSID_step(void)
{
  real_T y_g;

  /* MATLABSystem: '<Root>/Analog Input' */
  MW_AnalogIn_Start(GANTRY_SYSID_DW.obj_h5.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<Root>/Analog Input' */
  MW_AnalogInSingle_ReadResult(GANTRY_SYSID_DW.obj_h5.MW_ANALOGIN_HANDLE,
    &GANTRY_SYSID_B.trolley_position, 7);

  /* MATLABSystem: '<Root>/Analog Input1' */
  MW_AnalogIn_Start(GANTRY_SYSID_DW.obj_h.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<Root>/Analog Input1' */
  MW_AnalogInSingle_ReadResult(GANTRY_SYSID_DW.obj_h.MW_ANALOGIN_HANDLE,
    &GANTRY_SYSID_B.trolley_speed, 7);

  /* MATLABSystem: '<Root>/Analog Input2' */
  MW_AnalogIn_Start(GANTRY_SYSID_DW.obj_j.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<Root>/Analog Input2' */
  MW_AnalogInSingle_ReadResult(GANTRY_SYSID_DW.obj_j.MW_ANALOGIN_HANDLE,
    &GANTRY_SYSID_B.trolley_current, 7);

  /* MATLABSystem: '<Root>/Analog Input3' */
  MW_AnalogIn_Start(GANTRY_SYSID_DW.obj_b.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<Root>/Analog Input3' */
  MW_AnalogInSingle_ReadResult(GANTRY_SYSID_DW.obj_b.MW_ANALOGIN_HANDLE,
    &GANTRY_SYSID_B.load_angle, 7);

  /* MATLABSystem: '<Root>/Analog Input4' */
  MW_AnalogIn_Start(GANTRY_SYSID_DW.obj_o.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<Root>/Analog Input4' */
  MW_AnalogInSingle_ReadResult(GANTRY_SYSID_DW.obj_o.MW_ANALOGIN_HANDLE,
    &GANTRY_SYSID_B.hoist_position, 7);

  /* MATLABSystem: '<Root>/Analog Input5' */
  MW_AnalogIn_Start(GANTRY_SYSID_DW.obj.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<Root>/Analog Input5' */
  MW_AnalogInSingle_ReadResult(GANTRY_SYSID_DW.obj.MW_ANALOGIN_HANDLE,
    &GANTRY_SYSID_B.hoist_current, 7);

  /* MATLABSystem: '<Root>/Digital Read' */
  GANTRY_SYSID_B.btn = MW_digitalIO_read
    (GANTRY_SYSID_DW.obj_h0.MW_DIGITALIO_HANDLE);

  /* MATLAB Function: '<Root>/MATLAB Function' */
  if (GANTRY_SYSID_B.btn) {
    GANTRY_SYSID_DW.button_pressed = 1.0;
  }

  GANTRY_SYSID_B.t = 0.0;
  GANTRY_SYSID_B.h = 0.0;
  if (GANTRY_SYSID_DW.button_pressed == 1.0) {
    if (GANTRY_SYSID_DW.m == 0.0) {
      if (GANTRY_SYSID_DW.i < 200.0) {
        GANTRY_SYSID_B.h = 0.0;
      } else if (GANTRY_SYSID_DW.i < 800.0) {
        GANTRY_SYSID_B.h = -6.0;
      } else {
        GANTRY_SYSID_B.h = 0.0;
        GANTRY_SYSID_DW.m = 1.0;
        GANTRY_SYSID_DW.i = 0.0;
      }
    } else if (GANTRY_SYSID_DW.m == 1.0) {
      if (GANTRY_SYSID_DW.i < 200.0) {
        GANTRY_SYSID_B.t = 0.0;
      } else if (GANTRY_SYSID_DW.i < 600.0) {
        GANTRY_SYSID_B.t = -6.0;
      } else {
        GANTRY_SYSID_B.t = 0.0;
        GANTRY_SYSID_DW.m = 2.0;
        GANTRY_SYSID_DW.i = 0.0;
      }
    }

    GANTRY_SYSID_DW.i++;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* MATLAB Function: '<Root>/BiPolar Calibration' */
  GANTRY_SYSID_BiPolarCalibration(GANTRY_SYSID_B.t, &y_g,
    &GANTRY_SYSID_DW.sf_BiPolarCalibration);

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(GANTRY_SYSID_DW.obj_oh.MW_PWM_HANDLE, y_g);

  /* MATLAB Function: '<Root>/BiPolar Calibration1' */
  GANTRY_SYSID_BiPolarCalibration(GANTRY_SYSID_B.h, &y_g,
    &GANTRY_SYSID_DW.sf_BiPolarCalibration1);

  /* MATLABSystem: '<Root>/PWM Output1' */
  MW_PWM_SetDutyCycle(GANTRY_SYSID_DW.obj_m.MW_PWM_HANDLE, y_g);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  GANTRY_SYSID_M->Timing.taskTime0 =
    ((time_T)(++GANTRY_SYSID_M->Timing.clockTick0)) *
    GANTRY_SYSID_M->Timing.stepSize0;
}

/* Model initialize function */
void GANTRY_SYSID_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(GANTRY_SYSID_M, -1);
  GANTRY_SYSID_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  GANTRY_SYSID_M->Sizes.checksums[0] = (3136467641U);
  GANTRY_SYSID_M->Sizes.checksums[1] = (3587167258U);
  GANTRY_SYSID_M->Sizes.checksums[2] = (1209589326U);
  GANTRY_SYSID_M->Sizes.checksums[3] = (3201236428U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    GANTRY_SYSID_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(GANTRY_SYSID_M->extModeInfo,
      &GANTRY_SYSID_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(GANTRY_SYSID_M->extModeInfo,
                        GANTRY_SYSID_M->Sizes.checksums);
    rteiSetTPtr(GANTRY_SYSID_M->extModeInfo, rtmGetTPtr(GANTRY_SYSID_M));
  }

  /* SystemInitialize for MATLAB Function: '<Root>/BiPolar Calibration' */
  GANTRY__BiPolarCalibration_Init(&GANTRY_SYSID_DW.sf_BiPolarCalibration);

  /* SystemInitialize for MATLAB Function: '<Root>/BiPolar Calibration1' */
  GANTRY__BiPolarCalibration_Init(&GANTRY_SYSID_DW.sf_BiPolarCalibration1);

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  GANTRY_SYSID_DW.obj_h5.matlabCodegenIsDeleted = false;
  GANTRY_SYSID_DW.obj_h5.isInitialized = 1;
  GANTRY_SYSID_DW.obj_h5.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(PA_3);
  MW_AnalogIn_SetTriggerSource(GANTRY_SYSID_DW.obj_h5.MW_ANALOGIN_HANDLE,
    MW_ANALOGIN_SOFTWARE_TRIGGER, 0U);
  GANTRY_SYSID_DW.obj_h5.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  GANTRY_SYSID_DW.obj_h.matlabCodegenIsDeleted = false;
  GANTRY_SYSID_DW.obj_h.isInitialized = 1;
  GANTRY_SYSID_DW.obj_h.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(PF_7);
  MW_AnalogIn_SetTriggerSource(GANTRY_SYSID_DW.obj_h.MW_ANALOGIN_HANDLE,
    MW_ANALOGIN_SOFTWARE_TRIGGER, 0U);
  GANTRY_SYSID_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input2' */
  GANTRY_SYSID_DW.obj_j.matlabCodegenIsDeleted = false;
  GANTRY_SYSID_DW.obj_j.isInitialized = 1;
  GANTRY_SYSID_DW.obj_j.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(PF_8);
  MW_AnalogIn_SetTriggerSource(GANTRY_SYSID_DW.obj_j.MW_ANALOGIN_HANDLE,
    MW_ANALOGIN_SOFTWARE_TRIGGER, 0U);
  GANTRY_SYSID_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input3' */
  GANTRY_SYSID_DW.obj_b.matlabCodegenIsDeleted = false;
  GANTRY_SYSID_DW.obj_b.isInitialized = 1;
  GANTRY_SYSID_DW.obj_b.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(PF_9);
  MW_AnalogIn_SetTriggerSource(GANTRY_SYSID_DW.obj_b.MW_ANALOGIN_HANDLE,
    MW_ANALOGIN_SOFTWARE_TRIGGER, 0U);
  GANTRY_SYSID_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input4' */
  GANTRY_SYSID_DW.obj_o.matlabCodegenIsDeleted = false;
  GANTRY_SYSID_DW.obj_o.isInitialized = 1;
  GANTRY_SYSID_DW.obj_o.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(PF_4);
  MW_AnalogIn_SetTriggerSource(GANTRY_SYSID_DW.obj_o.MW_ANALOGIN_HANDLE,
    MW_ANALOGIN_SOFTWARE_TRIGGER, 0U);
  GANTRY_SYSID_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input5' */
  GANTRY_SYSID_DW.obj.matlabCodegenIsDeleted = false;
  GANTRY_SYSID_DW.obj.isInitialized = 1;
  GANTRY_SYSID_DW.obj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(PF_3);
  MW_AnalogIn_SetTriggerSource(GANTRY_SYSID_DW.obj.MW_ANALOGIN_HANDLE,
    MW_ANALOGIN_SOFTWARE_TRIGGER, 0U);
  GANTRY_SYSID_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Read' */
  GANTRY_SYSID_DW.obj_h0.matlabCodegenIsDeleted = false;
  GANTRY_SYSID_DW.obj_h0.isInitialized = 1;
  GANTRY_SYSID_DW.obj_h0.MW_DIGITALIO_HANDLE = MW_digitalIO_open(PC_13, 0);
  GANTRY_SYSID_DW.obj_h0.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM Output' */
  GANTRY_SYSID_DW.obj_oh.matlabCodegenIsDeleted = false;
  GANTRY_SYSID_DW.obj_oh.isInitialized = 1;
  GANTRY_SYSID_DW.obj_oh.MW_PWM_HANDLE = MW_PWM_Open(PA_6, 10000.0, 57.6);
  MW_PWM_Start(GANTRY_SYSID_DW.obj_oh.MW_PWM_HANDLE);
  GANTRY_SYSID_DW.obj_oh.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM Output1' */
  GANTRY_SYSID_DW.obj_m.matlabCodegenIsDeleted = false;
  GANTRY_SYSID_DW.obj_m.isInitialized = 1;
  GANTRY_SYSID_DW.obj_m.MW_PWM_HANDLE = MW_PWM_Open(PC_7, 10000.0, 57.6);
  MW_PWM_Start(GANTRY_SYSID_DW.obj_m.MW_PWM_HANDLE);
  GANTRY_SYSID_DW.obj_m.isSetupComplete = true;
}

/* Model terminate function */
void GANTRY_SYSID_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!GANTRY_SYSID_DW.obj_h5.matlabCodegenIsDeleted) {
    GANTRY_SYSID_DW.obj_h5.matlabCodegenIsDeleted = true;
    if ((GANTRY_SYSID_DW.obj_h5.isInitialized == 1) &&
        GANTRY_SYSID_DW.obj_h5.isSetupComplete) {
      MW_AnalogIn_Stop(GANTRY_SYSID_DW.obj_h5.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(GANTRY_SYSID_DW.obj_h5.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */
  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!GANTRY_SYSID_DW.obj_h.matlabCodegenIsDeleted) {
    GANTRY_SYSID_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((GANTRY_SYSID_DW.obj_h.isInitialized == 1) &&
        GANTRY_SYSID_DW.obj_h.isSetupComplete) {
      MW_AnalogIn_Stop(GANTRY_SYSID_DW.obj_h.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(GANTRY_SYSID_DW.obj_h.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */
  /* Terminate for MATLABSystem: '<Root>/Analog Input2' */
  if (!GANTRY_SYSID_DW.obj_j.matlabCodegenIsDeleted) {
    GANTRY_SYSID_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((GANTRY_SYSID_DW.obj_j.isInitialized == 1) &&
        GANTRY_SYSID_DW.obj_j.isSetupComplete) {
      MW_AnalogIn_Stop(GANTRY_SYSID_DW.obj_j.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(GANTRY_SYSID_DW.obj_j.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input2' */
  /* Terminate for MATLABSystem: '<Root>/Analog Input3' */
  if (!GANTRY_SYSID_DW.obj_b.matlabCodegenIsDeleted) {
    GANTRY_SYSID_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((GANTRY_SYSID_DW.obj_b.isInitialized == 1) &&
        GANTRY_SYSID_DW.obj_b.isSetupComplete) {
      MW_AnalogIn_Stop(GANTRY_SYSID_DW.obj_b.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(GANTRY_SYSID_DW.obj_b.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input3' */
  /* Terminate for MATLABSystem: '<Root>/Analog Input4' */
  if (!GANTRY_SYSID_DW.obj_o.matlabCodegenIsDeleted) {
    GANTRY_SYSID_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((GANTRY_SYSID_DW.obj_o.isInitialized == 1) &&
        GANTRY_SYSID_DW.obj_o.isSetupComplete) {
      MW_AnalogIn_Stop(GANTRY_SYSID_DW.obj_o.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(GANTRY_SYSID_DW.obj_o.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input4' */
  /* Terminate for MATLABSystem: '<Root>/Analog Input5' */
  if (!GANTRY_SYSID_DW.obj.matlabCodegenIsDeleted) {
    GANTRY_SYSID_DW.obj.matlabCodegenIsDeleted = true;
    if ((GANTRY_SYSID_DW.obj.isInitialized == 1) &&
        GANTRY_SYSID_DW.obj.isSetupComplete) {
      MW_AnalogIn_Stop(GANTRY_SYSID_DW.obj.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(GANTRY_SYSID_DW.obj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input5' */
  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  if (!GANTRY_SYSID_DW.obj_h0.matlabCodegenIsDeleted) {
    GANTRY_SYSID_DW.obj_h0.matlabCodegenIsDeleted = true;
    if ((GANTRY_SYSID_DW.obj_h0.isInitialized == 1) &&
        GANTRY_SYSID_DW.obj_h0.isSetupComplete) {
      MW_digitalIO_close(GANTRY_SYSID_DW.obj_h0.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  if (!GANTRY_SYSID_DW.obj_oh.matlabCodegenIsDeleted) {
    GANTRY_SYSID_DW.obj_oh.matlabCodegenIsDeleted = true;
    if ((GANTRY_SYSID_DW.obj_oh.isInitialized == 1) &&
        GANTRY_SYSID_DW.obj_oh.isSetupComplete) {
      MW_PWM_Stop(GANTRY_SYSID_DW.obj_oh.MW_PWM_HANDLE);
      MW_PWM_Close(GANTRY_SYSID_DW.obj_oh.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output1' */
  if (!GANTRY_SYSID_DW.obj_m.matlabCodegenIsDeleted) {
    GANTRY_SYSID_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((GANTRY_SYSID_DW.obj_m.isInitialized == 1) &&
        GANTRY_SYSID_DW.obj_m.isSetupComplete) {
      MW_PWM_Stop(GANTRY_SYSID_DW.obj_m.MW_PWM_HANDLE);
      MW_PWM_Close(GANTRY_SYSID_DW.obj_m.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
