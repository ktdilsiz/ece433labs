/*
 * Lab_Exam_2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Lab_Exam_2".
 *
 * Model version              : 1.1
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Thu Oct 20 12:14:19 2016
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Lab_Exam_2.h"
#include "Lab_Exam_2_private.h"
#include "Lab_Exam_2_dt.h"

/* Block signals (auto storage) */
B_Lab_Exam_2_T Lab_Exam_2_B;

/* Continuous states */
X_Lab_Exam_2_T Lab_Exam_2_X;

/* Block states (auto storage) */
DW_Lab_Exam_2_T Lab_Exam_2_DW;

/* Real-time model */
RT_MODEL_Lab_Exam_2_T Lab_Exam_2_M_;
RT_MODEL_Lab_Exam_2_T *const Lab_Exam_2_M = &Lab_Exam_2_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Lab_Exam_2_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  Lab_Exam_2_output();
  Lab_Exam_2_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  Lab_Exam_2_output();
  Lab_Exam_2_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  Lab_Exam_2_output();
  Lab_Exam_2_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Lab_Exam_2_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalogTimebase1_o1;
  real_T rtb_HILReadAnalogTimebase1_o2;
  real_T rtb_HILReadEncoder1;
  real_T *lastU;
  real_T rtb_Gain8;
  real_T rtb_Add1;
  if (rtmIsMajorTimeStep(Lab_Exam_2_M)) {
    /* set solver stop time */
    if (!(Lab_Exam_2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Lab_Exam_2_M->solverInfo,
                            ((Lab_Exam_2_M->Timing.clockTickH0 + 1) *
        Lab_Exam_2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Lab_Exam_2_M->solverInfo,
                            ((Lab_Exam_2_M->Timing.clockTick0 + 1) *
        Lab_Exam_2_M->Timing.stepSize0 + Lab_Exam_2_M->Timing.clockTickH0 *
        Lab_Exam_2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Lab_Exam_2_M)) {
    Lab_Exam_2_M->Timing.t[0] = rtsiGetT(&Lab_Exam_2_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Lab_Exam_2_M)) {
    /* S-Function (hil_read_analog_timebase_block): '<Root>/HIL Read Analog Timebase1' */

    /* S-Function Block: Lab_Exam_2/HIL Read Analog Timebase1 (hil_read_analog_timebase_block) */
    {
      t_error result;
      result = hil_task_read_analog(Lab_Exam_2_DW.HILReadAnalogTimebase1_Task, 1,
        &Lab_Exam_2_DW.HILReadAnalogTimebase1_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
      }

      rtb_HILReadAnalogTimebase1_o1 =
        Lab_Exam_2_DW.HILReadAnalogTimebase1_Buffer[0];
      rtb_HILReadAnalogTimebase1_o2 =
        Lab_Exam_2_DW.HILReadAnalogTimebase1_Buffer[1];
    }
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  rtb_Gain8 = Lab_Exam_2_P.SignalGenerator_Frequency * Lab_Exam_2_M->Timing.t[0];
  if (rtb_Gain8 - floor(rtb_Gain8) >= 0.5) {
    rtb_Gain8 = Lab_Exam_2_P.SignalGenerator_Amplitude;
  } else {
    rtb_Gain8 = -Lab_Exam_2_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Gain: '<Root>/Gain8' */
  rtb_Gain8 *= Lab_Exam_2_P.Gain8_Gain;
  if (rtmIsMajorTimeStep(Lab_Exam_2_M)) {
    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder1' */

    /* S-Function Block: Lab_Exam_2/HIL Read Encoder1 (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(Lab_Exam_2_DW.HILInitialize_Card,
        &Lab_Exam_2_P.HILReadEncoder1_channels, 1,
        &Lab_Exam_2_DW.HILReadEncoder1_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder1 = Lab_Exam_2_DW.HILReadEncoder1_Buffer;
      }
    }

    /* Gain: '<Root>/Encoder1' */
    Lab_Exam_2_B.Encoder1 = Lab_Exam_2_P.Encoder1_Gain * rtb_HILReadEncoder1;
  }

  /* Sum: '<Root>/Add4' */
  Lab_Exam_2_B.Add4 = rtb_Gain8 - Lab_Exam_2_B.Encoder1;

  /* Derivative: '<Root>/Derivative1' */
  if ((Lab_Exam_2_DW.TimeStampA >= Lab_Exam_2_M->Timing.t[0]) &&
      (Lab_Exam_2_DW.TimeStampB >= Lab_Exam_2_M->Timing.t[0])) {
    rtb_Add1 = 0.0;
  } else {
    rtb_Add1 = Lab_Exam_2_DW.TimeStampA;
    lastU = &Lab_Exam_2_DW.LastUAtTimeA;
    if (Lab_Exam_2_DW.TimeStampA < Lab_Exam_2_DW.TimeStampB) {
      if (Lab_Exam_2_DW.TimeStampB < Lab_Exam_2_M->Timing.t[0]) {
        rtb_Add1 = Lab_Exam_2_DW.TimeStampB;
        lastU = &Lab_Exam_2_DW.LastUAtTimeB;
      }
    } else {
      if (Lab_Exam_2_DW.TimeStampA >= Lab_Exam_2_M->Timing.t[0]) {
        rtb_Add1 = Lab_Exam_2_DW.TimeStampB;
        lastU = &Lab_Exam_2_DW.LastUAtTimeB;
      }
    }

    rtb_Add1 = (Lab_Exam_2_B.Encoder1 - *lastU) / (Lab_Exam_2_M->Timing.t[0] -
      rtb_Add1);
  }

  /* End of Derivative: '<Root>/Derivative1' */

  /* Sum: '<Root>/Add3' incorporates:
   *  Gain: '<Root>/Gain5'
   *  Gain: '<Root>/Gain6'
   *  Gain: '<Root>/Gain7'
   *  Integrator: '<Root>/Motor1'
   */
  rtb_Add1 = (Lab_Exam_2_P.K1 * Lab_Exam_2_X.Motor1_CSTATE + Lab_Exam_2_P.Kp *
              Lab_Exam_2_B.Add4) - Lab_Exam_2_P.Kd * rtb_Add1;

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_Add1 > Lab_Exam_2_P.Saturation1_UpperSat) {
    rtb_Add1 = Lab_Exam_2_P.Saturation1_UpperSat;
  } else {
    if (rtb_Add1 < Lab_Exam_2_P.Saturation1_LowerSat) {
      rtb_Add1 = Lab_Exam_2_P.Saturation1_LowerSat;
    }
  }

  /* Gain: '<Root>/Gain3' incorporates:
   *  Saturate: '<Root>/Saturation1'
   */
  Lab_Exam_2_B.Gain3 = Lab_Exam_2_P.Gain3_Gain * rtb_Add1;
  if (rtmIsMajorTimeStep(Lab_Exam_2_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: Lab_Exam_2/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(Lab_Exam_2_DW.HILInitialize_Card,
        &Lab_Exam_2_P.HILWriteAnalog_channels, 1, &Lab_Exam_2_B.Gain3);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
      }
    }
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  Lab_Exam_2_B.TransferFcn = 0.0;
  Lab_Exam_2_B.TransferFcn += Lab_Exam_2_P.TransferFcn_C[0] *
    Lab_Exam_2_X.TransferFcn_CSTATE[0];
  Lab_Exam_2_B.TransferFcn += Lab_Exam_2_P.TransferFcn_C[1] *
    Lab_Exam_2_X.TransferFcn_CSTATE[1];
  if (rtmIsMajorTimeStep(Lab_Exam_2_M)) {
  }

  /* Sum: '<Root>/Add2' */
  Lab_Exam_2_B.Add2 = rtb_Gain8 - Lab_Exam_2_B.TransferFcn;

  /* Derivative: '<Root>/Derivative' */
  if ((Lab_Exam_2_DW.TimeStampA_i >= Lab_Exam_2_M->Timing.t[0]) &&
      (Lab_Exam_2_DW.TimeStampB_a >= Lab_Exam_2_M->Timing.t[0])) {
    rtb_Add1 = 0.0;
  } else {
    rtb_Add1 = Lab_Exam_2_DW.TimeStampA_i;
    lastU = &Lab_Exam_2_DW.LastUAtTimeA_f;
    if (Lab_Exam_2_DW.TimeStampA_i < Lab_Exam_2_DW.TimeStampB_a) {
      if (Lab_Exam_2_DW.TimeStampB_a < Lab_Exam_2_M->Timing.t[0]) {
        rtb_Add1 = Lab_Exam_2_DW.TimeStampB_a;
        lastU = &Lab_Exam_2_DW.LastUAtTimeB_d;
      }
    } else {
      if (Lab_Exam_2_DW.TimeStampA_i >= Lab_Exam_2_M->Timing.t[0]) {
        rtb_Add1 = Lab_Exam_2_DW.TimeStampB_a;
        lastU = &Lab_Exam_2_DW.LastUAtTimeB_d;
      }
    }

    rtb_Add1 = (Lab_Exam_2_B.TransferFcn - *lastU) / (Lab_Exam_2_M->Timing.t[0]
      - rtb_Add1);
  }

  /* End of Derivative: '<Root>/Derivative' */

  /* Sum: '<Root>/Add1' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain4'
   *  Integrator: '<Root>/Motor'
   */
  rtb_Gain8 = (Lab_Exam_2_P.K1 * Lab_Exam_2_X.Motor_CSTATE + Lab_Exam_2_P.Kp *
               Lab_Exam_2_B.Add2) - Lab_Exam_2_P.Kd * rtb_Add1;

  /* Saturate: '<Root>/Saturation2' */
  if (rtb_Gain8 > Lab_Exam_2_P.Saturation2_UpperSat) {
    Lab_Exam_2_B.Saturation2 = Lab_Exam_2_P.Saturation2_UpperSat;
  } else if (rtb_Gain8 < Lab_Exam_2_P.Saturation2_LowerSat) {
    Lab_Exam_2_B.Saturation2 = Lab_Exam_2_P.Saturation2_LowerSat;
  } else {
    Lab_Exam_2_B.Saturation2 = rtb_Gain8;
  }

  /* End of Saturate: '<Root>/Saturation2' */
  if (rtmIsMajorTimeStep(Lab_Exam_2_M)) {
    /* Gain: '<Root>/Potentiometer1' */
    Lab_Exam_2_B.Potentiometer1 = Lab_Exam_2_P.Potentiometer1_Gain *
      rtb_HILReadAnalogTimebase1_o1;

    /* Gain: '<Root>/Tacometer1' */
    Lab_Exam_2_B.Tacometer1 = -69.813170079773172 / Lab_Exam_2_P.Kg *
      rtb_HILReadAnalogTimebase1_o2;
  }

  /* S-Function (sfun_tstart): '<S2>/startTime' */

  /* S-Function Block (sfun_tstart): <S2>/startTime */
  Lab_Exam_2_B.startTime = (0.0);
}

/* Model update function */
void Lab_Exam_2_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/Derivative1' */
  if (Lab_Exam_2_DW.TimeStampA == (rtInf)) {
    Lab_Exam_2_DW.TimeStampA = Lab_Exam_2_M->Timing.t[0];
    lastU = &Lab_Exam_2_DW.LastUAtTimeA;
  } else if (Lab_Exam_2_DW.TimeStampB == (rtInf)) {
    Lab_Exam_2_DW.TimeStampB = Lab_Exam_2_M->Timing.t[0];
    lastU = &Lab_Exam_2_DW.LastUAtTimeB;
  } else if (Lab_Exam_2_DW.TimeStampA < Lab_Exam_2_DW.TimeStampB) {
    Lab_Exam_2_DW.TimeStampA = Lab_Exam_2_M->Timing.t[0];
    lastU = &Lab_Exam_2_DW.LastUAtTimeA;
  } else {
    Lab_Exam_2_DW.TimeStampB = Lab_Exam_2_M->Timing.t[0];
    lastU = &Lab_Exam_2_DW.LastUAtTimeB;
  }

  *lastU = Lab_Exam_2_B.Encoder1;

  /* End of Update for Derivative: '<Root>/Derivative1' */

  /* Update for Derivative: '<Root>/Derivative' */
  if (Lab_Exam_2_DW.TimeStampA_i == (rtInf)) {
    Lab_Exam_2_DW.TimeStampA_i = Lab_Exam_2_M->Timing.t[0];
    lastU = &Lab_Exam_2_DW.LastUAtTimeA_f;
  } else if (Lab_Exam_2_DW.TimeStampB_a == (rtInf)) {
    Lab_Exam_2_DW.TimeStampB_a = Lab_Exam_2_M->Timing.t[0];
    lastU = &Lab_Exam_2_DW.LastUAtTimeB_d;
  } else if (Lab_Exam_2_DW.TimeStampA_i < Lab_Exam_2_DW.TimeStampB_a) {
    Lab_Exam_2_DW.TimeStampA_i = Lab_Exam_2_M->Timing.t[0];
    lastU = &Lab_Exam_2_DW.LastUAtTimeA_f;
  } else {
    Lab_Exam_2_DW.TimeStampB_a = Lab_Exam_2_M->Timing.t[0];
    lastU = &Lab_Exam_2_DW.LastUAtTimeB_d;
  }

  *lastU = Lab_Exam_2_B.TransferFcn;

  /* End of Update for Derivative: '<Root>/Derivative' */
  if (rtmIsMajorTimeStep(Lab_Exam_2_M)) {
    rt_ertODEUpdateContinuousStates(&Lab_Exam_2_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Lab_Exam_2_M->Timing.clockTick0)) {
    ++Lab_Exam_2_M->Timing.clockTickH0;
  }

  Lab_Exam_2_M->Timing.t[0] = rtsiGetSolverStopTime(&Lab_Exam_2_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Lab_Exam_2_M->Timing.clockTick1)) {
      ++Lab_Exam_2_M->Timing.clockTickH1;
    }

    Lab_Exam_2_M->Timing.t[1] = Lab_Exam_2_M->Timing.clockTick1 *
      Lab_Exam_2_M->Timing.stepSize1 + Lab_Exam_2_M->Timing.clockTickH1 *
      Lab_Exam_2_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Lab_Exam_2_derivatives(void)
{
  XDot_Lab_Exam_2_T *_rtXdot;
  _rtXdot = ((XDot_Lab_Exam_2_T *) Lab_Exam_2_M->ModelData.derivs);

  /* Derivatives for Integrator: '<Root>/Motor1' */
  _rtXdot->Motor1_CSTATE = Lab_Exam_2_B.Add4;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += Lab_Exam_2_P.TransferFcn_A[0] *
    Lab_Exam_2_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += Lab_Exam_2_P.TransferFcn_A[1] *
    Lab_Exam_2_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[1] += Lab_Exam_2_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += Lab_Exam_2_B.Saturation2;

  /* Derivatives for Integrator: '<Root>/Motor' */
  _rtXdot->Motor_CSTATE = Lab_Exam_2_B.Add2;
}

/* Model initialize function */
void Lab_Exam_2_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Lab_Exam_2/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &Lab_Exam_2_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(Lab_Exam_2_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Lab_Exam_2_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
      return;
    }

    if ((Lab_Exam_2_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (Lab_Exam_2_P.HILInitialize_set_analog_inpu_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &Lab_Exam_2_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = Lab_Exam_2_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &Lab_Exam_2_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = Lab_Exam_2_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(Lab_Exam_2_DW.HILInitialize_Card,
        Lab_Exam_2_P.HILInitialize_analog_input_chan, 8U,
        &Lab_Exam_2_DW.HILInitialize_AIMinimums[0],
        &Lab_Exam_2_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
        return;
      }
    }

    if ((Lab_Exam_2_P.HILInitialize_set_analog_output && !is_switching) ||
        (Lab_Exam_2_P.HILInitialize_set_analog_outp_i && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &Lab_Exam_2_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = Lab_Exam_2_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &Lab_Exam_2_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = Lab_Exam_2_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(Lab_Exam_2_DW.HILInitialize_Card,
        Lab_Exam_2_P.HILInitialize_analog_output_cha, 8U,
        &Lab_Exam_2_DW.HILInitialize_AOMinimums[0],
        &Lab_Exam_2_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
        return;
      }
    }

    if ((Lab_Exam_2_P.HILInitialize_set_analog_outp_g && !is_switching) ||
        (Lab_Exam_2_P.HILInitialize_set_analog_outp_o && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Lab_Exam_2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Lab_Exam_2_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(Lab_Exam_2_DW.HILInitialize_Card,
        Lab_Exam_2_P.HILInitialize_analog_output_cha, 8U,
        &Lab_Exam_2_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
        return;
      }
    }

    if (Lab_Exam_2_P.HILInitialize_set_analog_outp_d) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Lab_Exam_2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Lab_Exam_2_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (Lab_Exam_2_DW.HILInitialize_Card,
         Lab_Exam_2_P.HILInitialize_analog_output_cha, 8U,
         &Lab_Exam_2_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
        return;
      }
    }

    if ((Lab_Exam_2_P.HILInitialize_set_encoder_param && !is_switching) ||
        (Lab_Exam_2_P.HILInitialize_set_encoder_par_c && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &Lab_Exam_2_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = Lab_Exam_2_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(Lab_Exam_2_DW.HILInitialize_Card,
        Lab_Exam_2_P.HILInitialize_encoder_channels, 8U,
        (t_encoder_quadrature_mode *)
        &Lab_Exam_2_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
        return;
      }
    }

    if ((Lab_Exam_2_P.HILInitialize_set_encoder_count && !is_switching) ||
        (Lab_Exam_2_P.HILInitialize_set_encoder_cou_d && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &Lab_Exam_2_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = Lab_Exam_2_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(Lab_Exam_2_DW.HILInitialize_Card,
        Lab_Exam_2_P.HILInitialize_encoder_channels, 8U,
        &Lab_Exam_2_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
        return;
      }
    }

    if ((Lab_Exam_2_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (Lab_Exam_2_P.HILInitialize_set_pwm_params__c && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &Lab_Exam_2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = Lab_Exam_2_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(Lab_Exam_2_DW.HILInitialize_Card,
        Lab_Exam_2_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &Lab_Exam_2_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          Lab_Exam_2_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &Lab_Exam_2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            Lab_Exam_2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            Lab_Exam_2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              Lab_Exam_2_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            Lab_Exam_2_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              p_HILInitialize_pwm_channels[i1];
            Lab_Exam_2_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              Lab_Exam_2_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(Lab_Exam_2_DW.HILInitialize_Card,
          &Lab_Exam_2_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &Lab_Exam_2_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(Lab_Exam_2_DW.HILInitialize_Card,
          &Lab_Exam_2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &Lab_Exam_2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &Lab_Exam_2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = Lab_Exam_2_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &Lab_Exam_2_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = Lab_Exam_2_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &Lab_Exam_2_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = Lab_Exam_2_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(Lab_Exam_2_DW.HILInitialize_Card,
        Lab_Exam_2_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &Lab_Exam_2_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &Lab_Exam_2_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &Lab_Exam_2_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &Lab_Exam_2_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = Lab_Exam_2_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &Lab_Exam_2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Lab_Exam_2_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(Lab_Exam_2_DW.HILInitialize_Card,
        Lab_Exam_2_P.HILInitialize_pwm_channels, 8U,
        &Lab_Exam_2_DW.HILInitialize_POSortedFreqs[0],
        &Lab_Exam_2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
        return;
      }
    }

    if ((Lab_Exam_2_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (Lab_Exam_2_P.HILInitialize_set_pwm_outputs_h && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Lab_Exam_2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Lab_Exam_2_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(Lab_Exam_2_DW.HILInitialize_Card,
        Lab_Exam_2_P.HILInitialize_pwm_channels, 8U,
        &Lab_Exam_2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
        return;
      }
    }

    if (Lab_Exam_2_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &Lab_Exam_2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Lab_Exam_2_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (Lab_Exam_2_DW.HILInitialize_Card,
         Lab_Exam_2_P.HILInitialize_pwm_channels, 8U,
         &Lab_Exam_2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_analog_timebase_block): '<Root>/HIL Read Analog Timebase1' */

  /* S-Function Block: Lab_Exam_2/HIL Read Analog Timebase1 (hil_read_analog_timebase_block) */
  {
    t_error result;
    result = hil_task_create_analog_reader(Lab_Exam_2_DW.HILInitialize_Card,
      Lab_Exam_2_P.HILReadAnalogTimebase1_samples_,
      Lab_Exam_2_P.HILReadAnalogTimebase1_channels, 2,
      &Lab_Exam_2_DW.HILReadAnalogTimebase1_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
    }
  }

  /* InitializeConditions for Integrator: '<Root>/Motor1' */
  Lab_Exam_2_X.Motor1_CSTATE = Lab_Exam_2_P.Motor1_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  Lab_Exam_2_DW.TimeStampA = (rtInf);
  Lab_Exam_2_DW.TimeStampB = (rtInf);

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  Lab_Exam_2_X.TransferFcn_CSTATE[0] = 0.0;
  Lab_Exam_2_X.TransferFcn_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Motor' */
  Lab_Exam_2_X.Motor_CSTATE = Lab_Exam_2_P.Motor_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  Lab_Exam_2_DW.TimeStampA_i = (rtInf);
  Lab_Exam_2_DW.TimeStampB_a = (rtInf);
}

/* Model terminate function */
void Lab_Exam_2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Lab_Exam_2/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(Lab_Exam_2_DW.HILInitialize_Card);
    hil_monitor_stop_all(Lab_Exam_2_DW.HILInitialize_Card);
    is_switching = false;
    if ((Lab_Exam_2_P.HILInitialize_set_analog_outp_l && !is_switching) ||
        (Lab_Exam_2_P.HILInitialize_set_analog_outp_a && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Lab_Exam_2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Lab_Exam_2_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((Lab_Exam_2_P.HILInitialize_set_pwm_outputs_c && !is_switching) ||
        (Lab_Exam_2_P.HILInitialize_set_pwm_outputs_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Lab_Exam_2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Lab_Exam_2_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(Lab_Exam_2_DW.HILInitialize_Card
                         , Lab_Exam_2_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , Lab_Exam_2_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &Lab_Exam_2_DW.HILInitialize_AOVoltages[0]
                         , &Lab_Exam_2_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(Lab_Exam_2_DW.HILInitialize_Card,
            Lab_Exam_2_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs, &Lab_Exam_2_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(Lab_Exam_2_DW.HILInitialize_Card,
            Lab_Exam_2_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &Lab_Exam_2_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Lab_Exam_2_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Lab_Exam_2_DW.HILInitialize_Card);
    hil_monitor_delete_all(Lab_Exam_2_DW.HILInitialize_Card);
    hil_close(Lab_Exam_2_DW.HILInitialize_Card);
    Lab_Exam_2_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Lab_Exam_2_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Lab_Exam_2_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Lab_Exam_2_initialize();
}

void MdlTerminate(void)
{
  Lab_Exam_2_terminate();
}

/* Registration function */
RT_MODEL_Lab_Exam_2_T *Lab_Exam_2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Lab_Exam_2_M, 0,
                sizeof(RT_MODEL_Lab_Exam_2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Lab_Exam_2_M->solverInfo,
                          &Lab_Exam_2_M->Timing.simTimeStep);
    rtsiSetTPtr(&Lab_Exam_2_M->solverInfo, &rtmGetTPtr(Lab_Exam_2_M));
    rtsiSetStepSizePtr(&Lab_Exam_2_M->solverInfo,
                       &Lab_Exam_2_M->Timing.stepSize0);
    rtsiSetdXPtr(&Lab_Exam_2_M->solverInfo, &Lab_Exam_2_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Lab_Exam_2_M->solverInfo, (real_T **)
                         &Lab_Exam_2_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Lab_Exam_2_M->solverInfo,
      &Lab_Exam_2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Lab_Exam_2_M->solverInfo,
      &Lab_Exam_2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Lab_Exam_2_M->solverInfo,
      &Lab_Exam_2_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Lab_Exam_2_M->solverInfo,
      &Lab_Exam_2_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Lab_Exam_2_M->solverInfo, (&rtmGetErrorStatus
      (Lab_Exam_2_M)));
    rtsiSetRTModelPtr(&Lab_Exam_2_M->solverInfo, Lab_Exam_2_M);
  }

  rtsiSetSimTimeStep(&Lab_Exam_2_M->solverInfo, MAJOR_TIME_STEP);
  Lab_Exam_2_M->ModelData.intgData.y = Lab_Exam_2_M->ModelData.odeY;
  Lab_Exam_2_M->ModelData.intgData.f[0] = Lab_Exam_2_M->ModelData.odeF[0];
  Lab_Exam_2_M->ModelData.intgData.f[1] = Lab_Exam_2_M->ModelData.odeF[1];
  Lab_Exam_2_M->ModelData.intgData.f[2] = Lab_Exam_2_M->ModelData.odeF[2];
  Lab_Exam_2_M->ModelData.intgData.f[3] = Lab_Exam_2_M->ModelData.odeF[3];
  Lab_Exam_2_M->ModelData.contStates = ((real_T *) &Lab_Exam_2_X);
  rtsiSetSolverData(&Lab_Exam_2_M->solverInfo, (void *)
                    &Lab_Exam_2_M->ModelData.intgData);
  rtsiSetSolverName(&Lab_Exam_2_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Lab_Exam_2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Lab_Exam_2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Lab_Exam_2_M->Timing.sampleTimes = (&Lab_Exam_2_M->Timing.sampleTimesArray[0]);
    Lab_Exam_2_M->Timing.offsetTimes = (&Lab_Exam_2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Lab_Exam_2_M->Timing.sampleTimes[0] = (0.0);
    Lab_Exam_2_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Lab_Exam_2_M->Timing.offsetTimes[0] = (0.0);
    Lab_Exam_2_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Lab_Exam_2_M, &Lab_Exam_2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Lab_Exam_2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Lab_Exam_2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Lab_Exam_2_M, 10.0);
  Lab_Exam_2_M->Timing.stepSize0 = 0.001;
  Lab_Exam_2_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  Lab_Exam_2_M->Sizes.checksums[0] = (1733475534U);
  Lab_Exam_2_M->Sizes.checksums[1] = (1763591983U);
  Lab_Exam_2_M->Sizes.checksums[2] = (3301546970U);
  Lab_Exam_2_M->Sizes.checksums[3] = (2150509221U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Lab_Exam_2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Lab_Exam_2_M->extModeInfo,
      &Lab_Exam_2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Lab_Exam_2_M->extModeInfo, Lab_Exam_2_M->Sizes.checksums);
    rteiSetTPtr(Lab_Exam_2_M->extModeInfo, rtmGetTPtr(Lab_Exam_2_M));
  }

  Lab_Exam_2_M->solverInfoPtr = (&Lab_Exam_2_M->solverInfo);
  Lab_Exam_2_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Lab_Exam_2_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Lab_Exam_2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Lab_Exam_2_M->ModelData.blockIO = ((void *) &Lab_Exam_2_B);
  (void) memset(((void *) &Lab_Exam_2_B), 0,
                sizeof(B_Lab_Exam_2_T));

  /* parameters */
  Lab_Exam_2_M->ModelData.defaultParam = ((real_T *)&Lab_Exam_2_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Lab_Exam_2_X;
    Lab_Exam_2_M->ModelData.contStates = (x);
    (void) memset((void *)&Lab_Exam_2_X, 0,
                  sizeof(X_Lab_Exam_2_T));
  }

  /* states (dwork) */
  Lab_Exam_2_M->ModelData.dwork = ((void *) &Lab_Exam_2_DW);
  (void) memset((void *)&Lab_Exam_2_DW, 0,
                sizeof(DW_Lab_Exam_2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Lab_Exam_2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  Lab_Exam_2_M->Sizes.numContStates = (4);/* Number of continuous states */
  Lab_Exam_2_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Lab_Exam_2_M->Sizes.numY = (0);      /* Number of model outputs */
  Lab_Exam_2_M->Sizes.numU = (0);      /* Number of model inputs */
  Lab_Exam_2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Lab_Exam_2_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Lab_Exam_2_M->Sizes.numBlocks = (30);/* Number of blocks */
  Lab_Exam_2_M->Sizes.numBlockIO = (9);/* Number of block outputs */
  Lab_Exam_2_M->Sizes.numBlockPrms = (123);/* Sum of parameter "widths" */
  return Lab_Exam_2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
