/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'OutputCalibration'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri Oct 11 18:28:37 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "OutputCalibration.h"
#include "rtwtypes.h"
#include "xcp.h"
#include "ext_mode.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  __enable_irq();
  currentTime = (extmodeSimulationTime_T) OutputCalibration_M->Timing.taskTime0;
  OutputCalibration_step();

  /* Get model outputs here */

  /* Trigger External Mode event */
  extmodeEvent(0, currentTime);
  __disable_irq();
  OverrunFlag--;
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.005;
  float systemClock = 216;
  extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;

#ifndef USE_RTX
#if defined(MW_MULTI_TASKING_MODE) && (MW_MULTI_TASKING_MODE == 1)

  MW_ASM (" SVC #1");

#endif

  __disable_irq();

#endif

  ;
  stm32f7xx_init_board();
  SystemCoreClockUpdate();
  rtmSetErrorStatus(OutputCalibration_M, 0);

  /* Parse External Mode command line arguments */
  errorCode = extmodeParseArgs(0, NULL);
  if (errorCode != EXTMODE_SUCCESS) {
    return (errorCode);
  }

  OutputCalibration_initialize();
  __disable_irq();
  __enable_irq();

  /* External Mode initialization */
  errorCode = extmodeInit(OutputCalibration_M->extModeInfo, &rtmGetTFinal
    (OutputCalibration_M));
  if (errorCode != EXTMODE_SUCCESS) {
    /* Code to handle External Mode initialization errors
       may be added here */
  }

  if (errorCode == EXTMODE_SUCCESS) {
    /* Wait until a Start or Stop Request has been received from the Host */
    extmodeWaitForHostRequest(EXTMODE_WAIT_FOREVER);
    if (extmodeStopRequested()) {
      rtmSetStopRequested(OutputCalibration_M, true);
    }
  }

  __disable_irq();
  ARMCM_SysTick_Config(modelBaseRate);
  runModel =
    !extmodeSimulationComplete()&& !extmodeStopRequested()&&
    !rtmGetStopRequested(OutputCalibration_M);
  __enable_irq();
  __enable_irq();
  while (runModel) {
    /* Run External Mode background activities */
    errorCode = extmodeBackgroundRun();
    if (errorCode != EXTMODE_SUCCESS && errorCode != EXTMODE_EMPTY) {
      /* Code to handle External Mode background task errors
         may be added here */
    }

    stopRequested = !(
                      !extmodeSimulationComplete()&& !extmodeStopRequested()&&
                      !rtmGetStopRequested(OutputCalibration_M));
    runModel = !(stopRequested);
    if (stopRequested) {
      SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    }

    ;
  }

  /* Terminate model */
  OutputCalibration_terminate();

  /* External Mode reset */
  extmodeReset();

#ifndef USE_RTX

  (void)systemClock;

#endif

  ;
  __disable_irq();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
