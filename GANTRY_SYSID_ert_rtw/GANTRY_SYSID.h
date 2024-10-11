/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GANTRY_SYSID.h
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

#ifndef GANTRY_SYSID_h_
#define GANTRY_SYSID_h_
#ifndef GANTRY_SYSID_COMMON_INCLUDES_
#define GANTRY_SYSID_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_AnalogIn.h"
#include "MW_MbedPinInterface.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* GANTRY_SYSID_COMMON_INCLUDES_ */

#include "GANTRY_SYSID_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>/BiPolar Calibration' */
typedef struct {
  int32_T sfEvent;                     /* '<Root>/BiPolar Calibration' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/BiPolar Calibration' */
} DW_BiPolarCalibration_GANTRY__T;

/* Block signals (default storage) */
typedef struct {
  real_T t;                            /* '<Root>/MATLAB Function' */
  real_T h;                            /* '<Root>/MATLAB Function' */
  real_T hoist_current;                /* '<Root>/Analog Input5' */
  real_T hoist_position;               /* '<Root>/Analog Input4' */
  real_T load_angle;                   /* '<Root>/Analog Input3' */
  real_T trolley_current;              /* '<Root>/Analog Input2' */
  real_T trolley_speed;                /* '<Root>/Analog Input1' */
  real_T trolley_position;             /* '<Root>/Analog Input' */
  boolean_T btn;                       /* '<Root>/Digital Read' */
} B_GANTRY_SYSID_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  mbed_AnalogInput_GANTRY_SYSID_T obj; /* '<Root>/Analog Input5' */
  mbed_AnalogInput_GANTRY_SYSID_T obj_o;/* '<Root>/Analog Input4' */
  mbed_AnalogInput_GANTRY_SYSID_T obj_b;/* '<Root>/Analog Input3' */
  mbed_AnalogInput_GANTRY_SYSID_T obj_j;/* '<Root>/Analog Input2' */
  mbed_AnalogInput_GANTRY_SYSID_T obj_h;/* '<Root>/Analog Input1' */
  mbed_AnalogInput_GANTRY_SYSID_T obj_h5;/* '<Root>/Analog Input' */
  mbed_DigitalRead_GANTRY_SYSID_T obj_h0;/* '<Root>/Digital Read' */
  mbed_PWMOutput_GANTRY_SYSID_T obj_m; /* '<Root>/PWM Output1' */
  mbed_PWMOutput_GANTRY_SYSID_T obj_oh;/* '<Root>/PWM Output' */
  real_T i;                            /* '<Root>/MATLAB Function' */
  real_T m;                            /* '<Root>/MATLAB Function' */
  real_T button_pressed;               /* '<Root>/MATLAB Function' */
  DW_BiPolarCalibration_GANTRY__T sf_BiPolarCalibration1;/* '<Root>/BiPolar Calibration1' */
  DW_BiPolarCalibration_GANTRY__T sf_BiPolarCalibration;/* '<Root>/BiPolar Calibration' */
} DW_GANTRY_SYSID_T;

/* Real-time Model Data Structure */
struct tag_RTM_GANTRY_SYSID_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_GANTRY_SYSID_T GANTRY_SYSID_B;

/* Block states (default storage) */
extern DW_GANTRY_SYSID_T GANTRY_SYSID_DW;

/* Model entry point functions */
extern void GANTRY_SYSID_initialize(void);
extern void GANTRY_SYSID_step(void);
extern void GANTRY_SYSID_terminate(void);

/* Real-time Model object */
extern RT_MODEL_GANTRY_SYSID_T *const GANTRY_SYSID_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'GANTRY_SYSID'
 * '<S1>'   : 'GANTRY_SYSID/BiPolar Calibration'
 * '<S2>'   : 'GANTRY_SYSID/BiPolar Calibration1'
 * '<S3>'   : 'GANTRY_SYSID/MATLAB Function'
 */
#endif                                 /* GANTRY_SYSID_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
