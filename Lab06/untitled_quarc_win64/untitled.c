/*
 * untitled.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "untitled".
 *
 * Model version              : 1.0
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed Oct 19 22:38:51 2016
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"

/* Block signals (auto storage) */
B_untitled_T untitled_B;

/* Continuous states */
X_untitled_T untitled_X;

/* Block states (auto storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

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
  untitled_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  untitled_output();
  untitled_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  untitled_output();
  untitled_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  untitled_output();
  untitled_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = u0 / u1;
      if (fabs(u1_0 - rt_roundd_snf(u1_0)) <= DBL_EPSILON * fabs(u1_0)) {
        y = 0.0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Model output function */
void untitled_output(void)
{
  /* local block i/o variables */
  real_T rtb_Gain8;
  real_T rtb_HILReadAnalogTimebase1_o1;
  real_T rtb_HILReadAnalogTimebase1_o2;
  real_T rtb_HILReadEncoder1;
  real_T *lastU;
  real_T rtb_Gain7;
  real_T rtb_Add1;
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* set solver stop time */
    if (!(untitled_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&untitled_M->solverInfo,
                            ((untitled_M->Timing.clockTickH0 + 1) *
        untitled_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&untitled_M->solverInfo,
                            ((untitled_M->Timing.clockTick0 + 1) *
        untitled_M->Timing.stepSize0 + untitled_M->Timing.clockTickH0 *
        untitled_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(untitled_M)) {
    untitled_M->Timing.t[0] = rtsiGetT(&untitled_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(untitled_M)) {
    /* S-Function (hil_read_analog_timebase_block): '<Root>/HIL Read Analog Timebase1' */

    /* S-Function Block: untitled/HIL Read Analog Timebase1 (hil_read_analog_timebase_block) */
    {
      t_error result;
      result = hil_task_read_analog(untitled_DW.HILReadAnalogTimebase1_Task, 1,
        &untitled_DW.HILReadAnalogTimebase1_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
      }

      rtb_HILReadAnalogTimebase1_o1 = untitled_DW.HILReadAnalogTimebase1_Buffer
        [0];
      rtb_HILReadAnalogTimebase1_o2 = untitled_DW.HILReadAnalogTimebase1_Buffer
        [1];
    }
  }

  /* Integrator: '<Root>/Motor1' */
  rtb_Gain8 = untitled_X.Motor1_CSTATE;

  /* Gain: '<Root>/Gain7' */
  rtb_Gain7 = untitled_P.K1 * rtb_Gain8;

  /* Clock: '<S2>/Clock' */
  rtb_Gain8 = untitled_M->Timing.t[0];

  /* Sum: '<S2>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S2>/startTime'
   */
  rtb_Gain8 -= (0.0);

  /* Math: '<S2>/Math Function' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_Gain8 = rt_remd_snf(rtb_Gain8, untitled_P.Constant_Value);

  /* Lookup_n-D: '<S2>/Look-Up Table1' */
  rtb_Gain8 = look1_binlxpw(rtb_Gain8, untitled_P.LookUpTable1_bp01Data,
    untitled_P.RepeatingSequence_rep_seq_y, 4U);

  /* Gain: '<Root>/Gain8' */
  rtb_Gain8 *= untitled_P.Gain8_Gain;
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder1' */

    /* S-Function Block: untitled/HIL Read Encoder1 (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(untitled_DW.HILInitialize_Card,
        &untitled_P.HILReadEncoder1_channels, 1,
        &untitled_DW.HILReadEncoder1_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder1 = untitled_DW.HILReadEncoder1_Buffer;
      }
    }

    /* Gain: '<Root>/Encoder1' */
    untitled_B.Encoder1 = untitled_P.Encoder1_Gain * rtb_HILReadEncoder1;
  }

  /* Sum: '<Root>/Add4' */
  untitled_B.Add4 = rtb_Gain8 - untitled_B.Encoder1;

  /* Derivative: '<Root>/Derivative1' */
  if ((untitled_DW.TimeStampA >= untitled_M->Timing.t[0]) &&
      (untitled_DW.TimeStampB >= untitled_M->Timing.t[0])) {
    rtb_Add1 = 0.0;
  } else {
    rtb_Add1 = untitled_DW.TimeStampA;
    lastU = &untitled_DW.LastUAtTimeA;
    if (untitled_DW.TimeStampA < untitled_DW.TimeStampB) {
      if (untitled_DW.TimeStampB < untitled_M->Timing.t[0]) {
        rtb_Add1 = untitled_DW.TimeStampB;
        lastU = &untitled_DW.LastUAtTimeB;
      }
    } else {
      if (untitled_DW.TimeStampA >= untitled_M->Timing.t[0]) {
        rtb_Add1 = untitled_DW.TimeStampB;
        lastU = &untitled_DW.LastUAtTimeB;
      }
    }

    rtb_Add1 = (untitled_B.Encoder1 - *lastU) / (untitled_M->Timing.t[0] -
      rtb_Add1);
  }

  /* End of Derivative: '<Root>/Derivative1' */

  /* Sum: '<Root>/Add3' incorporates:
   *  Gain: '<Root>/Gain5'
   *  Gain: '<Root>/Gain6'
   */
  rtb_Add1 = (untitled_P.Kp * untitled_B.Add4 + rtb_Gain7) - untitled_P.Kd *
    rtb_Add1;

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_Add1 > untitled_P.Saturation1_UpperSat) {
    rtb_Add1 = untitled_P.Saturation1_UpperSat;
  } else {
    if (rtb_Add1 < untitled_P.Saturation1_LowerSat) {
      rtb_Add1 = untitled_P.Saturation1_LowerSat;
    }
  }

  /* Gain: '<Root>/Gain3' incorporates:
   *  Saturate: '<Root>/Saturation1'
   */
  untitled_B.Gain3 = untitled_P.Gain3_Gain * rtb_Add1;
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: untitled/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(untitled_DW.HILInitialize_Card,
        &untitled_P.HILWriteAnalog_channels, 1, &untitled_B.Gain3);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
      }
    }
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  untitled_B.TransferFcn = 0.0;
  untitled_B.TransferFcn += untitled_P.TransferFcn_C[0] *
    untitled_X.TransferFcn_CSTATE[0];
  untitled_B.TransferFcn += untitled_P.TransferFcn_C[1] *
    untitled_X.TransferFcn_CSTATE[1];
  if (rtmIsMajorTimeStep(untitled_M)) {
  }

  /* Sum: '<Root>/Add2' */
  untitled_B.Add2 = rtb_Gain8 - untitled_B.TransferFcn;

  /* Derivative: '<Root>/Derivative' */
  if ((untitled_DW.TimeStampA_i >= untitled_M->Timing.t[0]) &&
      (untitled_DW.TimeStampB_a >= untitled_M->Timing.t[0])) {
    rtb_Add1 = 0.0;
  } else {
    rtb_Add1 = untitled_DW.TimeStampA_i;
    lastU = &untitled_DW.LastUAtTimeA_f;
    if (untitled_DW.TimeStampA_i < untitled_DW.TimeStampB_a) {
      if (untitled_DW.TimeStampB_a < untitled_M->Timing.t[0]) {
        rtb_Add1 = untitled_DW.TimeStampB_a;
        lastU = &untitled_DW.LastUAtTimeB_d;
      }
    } else {
      if (untitled_DW.TimeStampA_i >= untitled_M->Timing.t[0]) {
        rtb_Add1 = untitled_DW.TimeStampB_a;
        lastU = &untitled_DW.LastUAtTimeB_d;
      }
    }

    rtb_Add1 = (untitled_B.TransferFcn - *lastU) / (untitled_M->Timing.t[0] -
      rtb_Add1);
  }

  /* End of Derivative: '<Root>/Derivative' */

  /* Sum: '<Root>/Add1' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain4'
   *  Integrator: '<Root>/Motor'
   */
  rtb_Gain7 = (untitled_P.K1 * untitled_X.Motor_CSTATE + untitled_P.Kp *
               untitled_B.Add2) - untitled_P.Kd * rtb_Add1;

  /* Saturate: '<Root>/Saturation2' */
  if (rtb_Gain7 > untitled_P.Saturation2_UpperSat) {
    untitled_B.Saturation2 = untitled_P.Saturation2_UpperSat;
  } else if (rtb_Gain7 < untitled_P.Saturation2_LowerSat) {
    untitled_B.Saturation2 = untitled_P.Saturation2_LowerSat;
  } else {
    untitled_B.Saturation2 = rtb_Gain7;
  }

  /* End of Saturate: '<Root>/Saturation2' */
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* Gain: '<Root>/Potentiometer1' */
    untitled_B.Potentiometer1 = untitled_P.Potentiometer1_Gain *
      rtb_HILReadAnalogTimebase1_o1;

    /* Gain: '<Root>/Tacometer1' */
    untitled_B.Tacometer1 = -69.813170079773172 / untitled_P.Kg *
      rtb_HILReadAnalogTimebase1_o2;
  }
}

/* Model update function */
void untitled_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/Derivative1' */
  if (untitled_DW.TimeStampA == (rtInf)) {
    untitled_DW.TimeStampA = untitled_M->Timing.t[0];
    lastU = &untitled_DW.LastUAtTimeA;
  } else if (untitled_DW.TimeStampB == (rtInf)) {
    untitled_DW.TimeStampB = untitled_M->Timing.t[0];
    lastU = &untitled_DW.LastUAtTimeB;
  } else if (untitled_DW.TimeStampA < untitled_DW.TimeStampB) {
    untitled_DW.TimeStampA = untitled_M->Timing.t[0];
    lastU = &untitled_DW.LastUAtTimeA;
  } else {
    untitled_DW.TimeStampB = untitled_M->Timing.t[0];
    lastU = &untitled_DW.LastUAtTimeB;
  }

  *lastU = untitled_B.Encoder1;

  /* End of Update for Derivative: '<Root>/Derivative1' */

  /* Update for Derivative: '<Root>/Derivative' */
  if (untitled_DW.TimeStampA_i == (rtInf)) {
    untitled_DW.TimeStampA_i = untitled_M->Timing.t[0];
    lastU = &untitled_DW.LastUAtTimeA_f;
  } else if (untitled_DW.TimeStampB_a == (rtInf)) {
    untitled_DW.TimeStampB_a = untitled_M->Timing.t[0];
    lastU = &untitled_DW.LastUAtTimeB_d;
  } else if (untitled_DW.TimeStampA_i < untitled_DW.TimeStampB_a) {
    untitled_DW.TimeStampA_i = untitled_M->Timing.t[0];
    lastU = &untitled_DW.LastUAtTimeA_f;
  } else {
    untitled_DW.TimeStampB_a = untitled_M->Timing.t[0];
    lastU = &untitled_DW.LastUAtTimeB_d;
  }

  *lastU = untitled_B.TransferFcn;

  /* End of Update for Derivative: '<Root>/Derivative' */
  if (rtmIsMajorTimeStep(untitled_M)) {
    rt_ertODEUpdateContinuousStates(&untitled_M->solverInfo);
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
  if (!(++untitled_M->Timing.clockTick0)) {
    ++untitled_M->Timing.clockTickH0;
  }

  untitled_M->Timing.t[0] = rtsiGetSolverStopTime(&untitled_M->solverInfo);

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
    if (!(++untitled_M->Timing.clockTick1)) {
      ++untitled_M->Timing.clockTickH1;
    }

    untitled_M->Timing.t[1] = untitled_M->Timing.clockTick1 *
      untitled_M->Timing.stepSize1 + untitled_M->Timing.clockTickH1 *
      untitled_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void untitled_derivatives(void)
{
  XDot_untitled_T *_rtXdot;
  _rtXdot = ((XDot_untitled_T *) untitled_M->ModelData.derivs);

  /* Derivatives for Integrator: '<Root>/Motor1' */
  _rtXdot->Motor1_CSTATE = untitled_B.Add4;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += untitled_P.TransferFcn_A[0] *
    untitled_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += untitled_P.TransferFcn_A[1] *
    untitled_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[1] += untitled_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += untitled_B.Saturation2;

  /* Derivatives for Integrator: '<Root>/Motor' */
  _rtXdot->Motor_CSTATE = untitled_B.Add2;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: untitled/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &untitled_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(untitled_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(untitled_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(untitled_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(untitled_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(untitled_M, _rt_error_message);
      return;
    }

    if ((untitled_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (untitled_P.HILInitialize_set_analog_inpu_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &untitled_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = untitled_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &untitled_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = untitled_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(untitled_DW.HILInitialize_Card,
        untitled_P.HILInitialize_analog_input_chan, 8U,
        &untitled_DW.HILInitialize_AIMinimums[0],
        &untitled_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if ((untitled_P.HILInitialize_set_analog_output && !is_switching) ||
        (untitled_P.HILInitialize_set_analog_outp_i && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &untitled_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = untitled_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &untitled_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = untitled_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(untitled_DW.HILInitialize_Card,
        untitled_P.HILInitialize_analog_output_cha, 8U,
        &untitled_DW.HILInitialize_AOMinimums[0],
        &untitled_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if ((untitled_P.HILInitialize_set_analog_outp_g && !is_switching) ||
        (untitled_P.HILInitialize_set_analog_outp_o && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &untitled_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = untitled_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(untitled_DW.HILInitialize_Card,
        untitled_P.HILInitialize_analog_output_cha, 8U,
        &untitled_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if (untitled_P.HILInitialize_set_analog_outp_d) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &untitled_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = untitled_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (untitled_DW.HILInitialize_Card,
         untitled_P.HILInitialize_analog_output_cha, 8U,
         &untitled_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if ((untitled_P.HILInitialize_set_encoder_param && !is_switching) ||
        (untitled_P.HILInitialize_set_encoder_par_c && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &untitled_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = untitled_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(untitled_DW.HILInitialize_Card,
        untitled_P.HILInitialize_encoder_channels, 8U,
        (t_encoder_quadrature_mode *)
        &untitled_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if ((untitled_P.HILInitialize_set_encoder_count && !is_switching) ||
        (untitled_P.HILInitialize_set_encoder_cou_d && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &untitled_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = untitled_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(untitled_DW.HILInitialize_Card,
        untitled_P.HILInitialize_encoder_channels, 8U,
        &untitled_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if ((untitled_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (untitled_P.HILInitialize_set_pwm_params__c && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &untitled_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = untitled_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(untitled_DW.HILInitialize_Card,
        untitled_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &untitled_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          untitled_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &untitled_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            untitled_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            untitled_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              untitled_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            untitled_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              p_HILInitialize_pwm_channels[i1];
            untitled_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              untitled_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(untitled_DW.HILInitialize_Card,
          &untitled_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &untitled_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(untitled_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(untitled_DW.HILInitialize_Card,
          &untitled_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &untitled_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(untitled_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &untitled_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = untitled_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &untitled_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = untitled_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &untitled_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = untitled_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(untitled_DW.HILInitialize_Card,
        untitled_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &untitled_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &untitled_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &untitled_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &untitled_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = untitled_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &untitled_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = untitled_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(untitled_DW.HILInitialize_Card,
        untitled_P.HILInitialize_pwm_channels, 8U,
        &untitled_DW.HILInitialize_POSortedFreqs[0],
        &untitled_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if ((untitled_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (untitled_P.HILInitialize_set_pwm_outputs_h && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &untitled_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = untitled_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(untitled_DW.HILInitialize_Card,
        untitled_P.HILInitialize_pwm_channels, 8U,
        &untitled_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if (untitled_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &untitled_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = untitled_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (untitled_DW.HILInitialize_Card, untitled_P.HILInitialize_pwm_channels,
         8U, &untitled_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_analog_timebase_block): '<Root>/HIL Read Analog Timebase1' */

  /* S-Function Block: untitled/HIL Read Analog Timebase1 (hil_read_analog_timebase_block) */
  {
    t_error result;
    result = hil_task_create_analog_reader(untitled_DW.HILInitialize_Card,
      untitled_P.HILReadAnalogTimebase1_samples_,
      untitled_P.HILReadAnalogTimebase1_channels, 2,
      &untitled_DW.HILReadAnalogTimebase1_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(untitled_M, _rt_error_message);
    }
  }

  /* InitializeConditions for Integrator: '<Root>/Motor1' */
  untitled_X.Motor1_CSTATE = untitled_P.Motor1_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  untitled_DW.TimeStampA = (rtInf);
  untitled_DW.TimeStampB = (rtInf);

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  untitled_X.TransferFcn_CSTATE[0] = 0.0;
  untitled_X.TransferFcn_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Motor' */
  untitled_X.Motor_CSTATE = untitled_P.Motor_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  untitled_DW.TimeStampA_i = (rtInf);
  untitled_DW.TimeStampB_a = (rtInf);
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: untitled/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(untitled_DW.HILInitialize_Card);
    hil_monitor_stop_all(untitled_DW.HILInitialize_Card);
    is_switching = false;
    if ((untitled_P.HILInitialize_set_analog_outp_l && !is_switching) ||
        (untitled_P.HILInitialize_set_analog_outp_a && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &untitled_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = untitled_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((untitled_P.HILInitialize_set_pwm_outputs_c && !is_switching) ||
        (untitled_P.HILInitialize_set_pwm_outputs_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &untitled_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = untitled_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(untitled_DW.HILInitialize_Card
                         , untitled_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , untitled_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &untitled_DW.HILInitialize_AOVoltages[0]
                         , &untitled_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(untitled_DW.HILInitialize_Card,
            untitled_P.HILInitialize_analog_output_cha, num_final_analog_outputs,
            &untitled_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(untitled_DW.HILInitialize_Card,
            untitled_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &untitled_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(untitled_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(untitled_DW.HILInitialize_Card);
    hil_monitor_delete_all(untitled_DW.HILInitialize_Card);
    hil_close(untitled_DW.HILInitialize_Card);
    untitled_DW.HILInitialize_Card = NULL;
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
  untitled_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  untitled_update();
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
  untitled_initialize();
}

void MdlTerminate(void)
{
  untitled_terminate();
}

/* Registration function */
RT_MODEL_untitled_T *untitled(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetdXPtr(&untitled_M->solverInfo, &untitled_M->ModelData.derivs);
    rtsiSetContStatesPtr(&untitled_M->solverInfo, (real_T **)
                         &untitled_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&untitled_M->solverInfo,
      &untitled_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&untitled_M->solverInfo,
      &untitled_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&untitled_M->solverInfo,
      &untitled_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&untitled_M->solverInfo,
      &untitled_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, (&rtmGetErrorStatus
      (untitled_M)));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  untitled_M->ModelData.intgData.y = untitled_M->ModelData.odeY;
  untitled_M->ModelData.intgData.f[0] = untitled_M->ModelData.odeF[0];
  untitled_M->ModelData.intgData.f[1] = untitled_M->ModelData.odeF[1];
  untitled_M->ModelData.intgData.f[2] = untitled_M->ModelData.odeF[2];
  untitled_M->ModelData.intgData.f[3] = untitled_M->ModelData.odeF[3];
  untitled_M->ModelData.contStates = ((real_T *) &untitled_X);
  rtsiSetSolverData(&untitled_M->solverInfo, (void *)
                    &untitled_M->ModelData.intgData);
  rtsiSetSolverName(&untitled_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = untitled_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    untitled_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    untitled_M->Timing.sampleTimes = (&untitled_M->Timing.sampleTimesArray[0]);
    untitled_M->Timing.offsetTimes = (&untitled_M->Timing.offsetTimesArray[0]);

    /* task periods */
    untitled_M->Timing.sampleTimes[0] = (0.0);
    untitled_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    untitled_M->Timing.offsetTimes[0] = (0.0);
    untitled_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = untitled_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    untitled_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(untitled_M, 40.0);
  untitled_M->Timing.stepSize0 = 0.001;
  untitled_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (2878326500U);
  untitled_M->Sizes.checksums[1] = (487328682U);
  untitled_M->Sizes.checksums[2] = (782736780U);
  untitled_M->Sizes.checksums[3] = (2462328483U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  untitled_M->solverInfoPtr = (&untitled_M->solverInfo);
  untitled_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&untitled_M->solverInfo, 0.001);
  rtsiSetSolverMode(&untitled_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  untitled_M->ModelData.blockIO = ((void *) &untitled_B);
  (void) memset(((void *) &untitled_B), 0,
                sizeof(B_untitled_T));

  /* parameters */
  untitled_M->ModelData.defaultParam = ((real_T *)&untitled_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &untitled_X;
    untitled_M->ModelData.contStates = (x);
    (void) memset((void *)&untitled_X, 0,
                  sizeof(X_untitled_T));
  }

  /* states (dwork) */
  untitled_M->ModelData.dwork = ((void *) &untitled_DW);
  (void) memset((void *)&untitled_DW, 0,
                sizeof(DW_untitled_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  untitled_M->Sizes.numContStates = (4);/* Number of continuous states */
  untitled_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  untitled_M->Sizes.numY = (0);        /* Number of model outputs */
  untitled_M->Sizes.numU = (0);        /* Number of model inputs */
  untitled_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  untitled_M->Sizes.numSampTimes = (2);/* Number of sample times */
  untitled_M->Sizes.numBlocks = (34);  /* Number of blocks */
  untitled_M->Sizes.numBlockIO = (8);  /* Number of block outputs */
  untitled_M->Sizes.numBlockPrms = (132);/* Sum of parameter "widths" */
  return untitled_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
