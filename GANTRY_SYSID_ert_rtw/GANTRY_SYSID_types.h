/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GANTRY_SYSID_types.h
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

#ifndef GANTRY_SYSID_types_h_
#define GANTRY_SYSID_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Custom Type definition for MATLABSystem: '<Root>/PWM Output1' */
#include "MW_SVD.h"
#ifndef struct_tag_Y9X8vOuujEYZFkYgC3qBoC
#define struct_tag_Y9X8vOuujEYZFkYgC3qBoC

struct tag_Y9X8vOuujEYZFkYgC3qBoC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_ANALOGIN_HANDLE;
};

#endif                                 /* struct_tag_Y9X8vOuujEYZFkYgC3qBoC */

#ifndef typedef_mbed_AnalogInput_GANTRY_SYSID_T
#define typedef_mbed_AnalogInput_GANTRY_SYSID_T

typedef struct tag_Y9X8vOuujEYZFkYgC3qBoC mbed_AnalogInput_GANTRY_SYSID_T;

#endif                             /* typedef_mbed_AnalogInput_GANTRY_SYSID_T */

#ifndef struct_tag_Ozp2eEnpu3F9WqhX1DgjQF
#define struct_tag_Ozp2eEnpu3F9WqhX1DgjQF

struct tag_Ozp2eEnpu3F9WqhX1DgjQF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /* struct_tag_Ozp2eEnpu3F9WqhX1DgjQF */

#ifndef typedef_mbed_DigitalRead_GANTRY_SYSID_T
#define typedef_mbed_DigitalRead_GANTRY_SYSID_T

typedef struct tag_Ozp2eEnpu3F9WqhX1DgjQF mbed_DigitalRead_GANTRY_SYSID_T;

#endif                             /* typedef_mbed_DigitalRead_GANTRY_SYSID_T */

#ifndef struct_tag_KO2oCVWkPUpA7C295Xa4DE
#define struct_tag_KO2oCVWkPUpA7C295Xa4DE

struct tag_KO2oCVWkPUpA7C295Xa4DE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_KO2oCVWkPUpA7C295Xa4DE */

#ifndef typedef_mbed_PWMOutput_GANTRY_SYSID_T
#define typedef_mbed_PWMOutput_GANTRY_SYSID_T

typedef struct tag_KO2oCVWkPUpA7C295Xa4DE mbed_PWMOutput_GANTRY_SYSID_T;

#endif                               /* typedef_mbed_PWMOutput_GANTRY_SYSID_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_GANTRY_SYSID_T RT_MODEL_GANTRY_SYSID_T;

#endif                                 /* GANTRY_SYSID_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
