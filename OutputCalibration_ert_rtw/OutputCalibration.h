/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: OutputCalibration.h
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

#ifndef OutputCalibration_h_
#define OutputCalibration_h_
#ifndef OutputCalibration_COMMON_INCLUDES_
#define OutputCalibration_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_MbedPinInterface.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* OutputCalibration_COMMON_INCLUDES_ */

#include "OutputCalibration_types.h"
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

/* Block signals (default storage) */
typedef struct {
  real_T v;                            /* '<Root>/MATLAB Function' */
  boolean_T btn;                       /* '<Root>/Digital Read' */
} B_OutputCalibration_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  mbed_DigitalRead_OutputCalibr_T obj; /* '<Root>/Digital Read' */
  mbed_PWMOutput_OutputCalibrat_T obj_p;/* '<Root>/PWM Output1' */
  mbed_PWMOutput_OutputCalibrat_T obj_o;/* '<Root>/PWM Output' */
  real_T m;                            /* '<Root>/MATLAB Function' */
  real_T db;                           /* '<Root>/MATLAB Function' */
  real_T i;                            /* '<Root>/MATLAB Function' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_OutputCalibration_T;

/* Real-time Model Data Structure */
struct tag_RTM_OutputCalibration_T {
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
extern B_OutputCalibration_T OutputCalibration_B;

/* Block states (default storage) */
extern DW_OutputCalibration_T OutputCalibration_DW;

/* Model entry point functions */
extern void OutputCalibration_initialize(void);
extern void OutputCalibration_step(void);
extern void OutputCalibration_terminate(void);

/* Real-time Model object */
extern RT_MODEL_OutputCalibration_T *const OutputCalibration_M;
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
 * '<Root>' : 'OutputCalibration'
 * '<S1>'   : 'OutputCalibration/MATLAB Function'
 */
#endif                                 /* OutputCalibration_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
