/*
 * lab7.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab7".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed Oct 19 21:59:49 2016
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab7.h"
#include "lab7_private.h"
#include "lab7_dt.h"

/* Block signals (auto storage) */
B_lab7_T lab7_B;

/* Continuous states */
X_lab7_T lab7_X;

/* Block states (auto storage) */
DW_lab7_T lab7_DW;

/* Real-time model */
RT_MODEL_lab7_T lab7_M_;
RT_MODEL_lab7_T *const lab7_M = &lab7_M_;

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
  lab7_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  lab7_output();
  lab7_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  lab7_output();
  lab7_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  lab7_output();
  lab7_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void lab7_output(void)
{
  /* local block i/o variables */
  real_T rtb_Add1;
  real_T rtb_HILReadAnalogTimebase1_o1;
  real_T rtb_HILReadAnalogTimebase1_o2;
  real_T rtb_HILReadEncoder1;
  real_T *lastU;
  real_T rtb_Motor;
  if (rtmIsMajorTimeStep(lab7_M)) {
    /* set solver stop time */
    if (!(lab7_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&lab7_M->solverInfo, ((lab7_M->Timing.clockTickH0 +
        1) * lab7_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&lab7_M->solverInfo, ((lab7_M->Timing.clockTick0 + 1)
        * lab7_M->Timing.stepSize0 + lab7_M->Timing.clockTickH0 *
        lab7_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab7_M)) {
    lab7_M->Timing.t[0] = rtsiGetT(&lab7_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(lab7_M)) {
    /* S-Function (hil_read_analog_timebase_block): '<Root>/HIL Read Analog Timebase1' */

    /* S-Function Block: lab7/HIL Read Analog Timebase1 (hil_read_analog_timebase_block) */
    {
      t_error result;
      result = hil_task_read_analog(lab7_DW.HILReadAnalogTimebase1_Task, 1,
        &lab7_DW.HILReadAnalogTimebase1_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab7_M, _rt_error_message);
      }

      rtb_HILReadAnalogTimebase1_o1 = lab7_DW.HILReadAnalogTimebase1_Buffer[0];
      rtb_HILReadAnalogTimebase1_o2 = lab7_DW.HILReadAnalogTimebase1_Buffer[1];
    }
  }

  /* Clock: '<S1>/Clock' */
  rtb_Add1 = lab7_M->Timing.t[0];

  /* Step: '<S1>/Step' */
  if (lab7_M->Timing.t[0] < lab7_P.Ramp_start) {
    rtb_Motor = lab7_P.Step_Y0;
  } else {
    rtb_Motor = lab7_P.Ramp_slope;
  }

  /* End of Step: '<S1>/Step' */

  /* Sum: '<S1>/Output' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Product: '<S1>/Product'
   *  Sum: '<S1>/Sum'
   */
  rtb_Add1 = (rtb_Add1 - lab7_P.Ramp_start) * rtb_Motor + lab7_P.Ramp_X0;
  if (rtmIsMajorTimeStep(lab7_M)) {
    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder1' */

    /* S-Function Block: lab7/HIL Read Encoder1 (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(lab7_DW.HILInitialize_Card,
        &lab7_P.HILReadEncoder1_channels, 1, &lab7_DW.HILReadEncoder1_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab7_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder1 = lab7_DW.HILReadEncoder1_Buffer;
      }
    }

    /* Gain: '<Root>/Encoder1' */
    lab7_B.Encoder1 = lab7_P.Encoder1_Gain * rtb_HILReadEncoder1;
  }

  /* Sum: '<Root>/Add4' */
  lab7_B.Add4 = rtb_Add1 - lab7_B.Encoder1;

  /* Derivative: '<Root>/Derivative1' */
  if ((lab7_DW.TimeStampA >= lab7_M->Timing.t[0]) && (lab7_DW.TimeStampB >=
       lab7_M->Timing.t[0])) {
    rtb_Motor = 0.0;
  } else {
    rtb_Motor = lab7_DW.TimeStampA;
    lastU = &lab7_DW.LastUAtTimeA;
    if (lab7_DW.TimeStampA < lab7_DW.TimeStampB) {
      if (lab7_DW.TimeStampB < lab7_M->Timing.t[0]) {
        rtb_Motor = lab7_DW.TimeStampB;
        lastU = &lab7_DW.LastUAtTimeB;
      }
    } else {
      if (lab7_DW.TimeStampA >= lab7_M->Timing.t[0]) {
        rtb_Motor = lab7_DW.TimeStampB;
        lastU = &lab7_DW.LastUAtTimeB;
      }
    }

    rtb_Motor = (lab7_B.Encoder1 - *lastU) / (lab7_M->Timing.t[0] - rtb_Motor);
  }

  /* End of Derivative: '<Root>/Derivative1' */

  /* Sum: '<Root>/Add3' incorporates:
   *  Gain: '<Root>/Gain5'
   *  Gain: '<Root>/Gain6'
   *  Gain: '<Root>/Gain7'
   *  Integrator: '<Root>/Motor1'
   */
  rtb_Motor = (lab7_P.K1 * lab7_X.Motor1_CSTATE + lab7_P.Kp * lab7_B.Add4) -
    lab7_P.Kd * rtb_Motor;

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_Motor > lab7_P.Saturation1_UpperSat) {
    rtb_Motor = lab7_P.Saturation1_UpperSat;
  } else {
    if (rtb_Motor < lab7_P.Saturation1_LowerSat) {
      rtb_Motor = lab7_P.Saturation1_LowerSat;
    }
  }

  /* Gain: '<Root>/Gain3' incorporates:
   *  Saturate: '<Root>/Saturation1'
   */
  lab7_B.Gain3 = lab7_P.Gain3_Gain * rtb_Motor;
  if (rtmIsMajorTimeStep(lab7_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: lab7/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(lab7_DW.HILInitialize_Card,
        &lab7_P.HILWriteAnalog_channels, 1, &lab7_B.Gain3);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab7_M, _rt_error_message);
      }
    }
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  lab7_B.TransferFcn = 0.0;
  lab7_B.TransferFcn += lab7_P.TransferFcn_C[0] * lab7_X.TransferFcn_CSTATE[0];
  lab7_B.TransferFcn += lab7_P.TransferFcn_C[1] * lab7_X.TransferFcn_CSTATE[1];
  if (rtmIsMajorTimeStep(lab7_M)) {
  }

  /* Sum: '<Root>/Add2' */
  lab7_B.Add2 = rtb_Add1 - lab7_B.TransferFcn;

  /* Derivative: '<Root>/Derivative' */
  if ((lab7_DW.TimeStampA_n >= lab7_M->Timing.t[0]) && (lab7_DW.TimeStampB_m >=
       lab7_M->Timing.t[0])) {
    rtb_Add1 = 0.0;
  } else {
    rtb_Motor = lab7_DW.TimeStampA_n;
    lastU = &lab7_DW.LastUAtTimeA_d;
    if (lab7_DW.TimeStampA_n < lab7_DW.TimeStampB_m) {
      if (lab7_DW.TimeStampB_m < lab7_M->Timing.t[0]) {
        rtb_Motor = lab7_DW.TimeStampB_m;
        lastU = &lab7_DW.LastUAtTimeB_p;
      }
    } else {
      if (lab7_DW.TimeStampA_n >= lab7_M->Timing.t[0]) {
        rtb_Motor = lab7_DW.TimeStampB_m;
        lastU = &lab7_DW.LastUAtTimeB_p;
      }
    }

    rtb_Add1 = (lab7_B.TransferFcn - *lastU) / (lab7_M->Timing.t[0] - rtb_Motor);
  }

  /* End of Derivative: '<Root>/Derivative' */

  /* Sum: '<Root>/Add1' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain4'
   *  Integrator: '<Root>/Motor'
   */
  rtb_Add1 = (lab7_P.K1 * lab7_X.Motor_CSTATE + lab7_P.Kp * lab7_B.Add2) -
    lab7_P.Kd * rtb_Add1;

  /* Saturate: '<Root>/Saturation2' */
  if (rtb_Add1 > lab7_P.Saturation2_UpperSat) {
    lab7_B.Saturation2 = lab7_P.Saturation2_UpperSat;
  } else if (rtb_Add1 < lab7_P.Saturation2_LowerSat) {
    lab7_B.Saturation2 = lab7_P.Saturation2_LowerSat;
  } else {
    lab7_B.Saturation2 = rtb_Add1;
  }

  /* End of Saturate: '<Root>/Saturation2' */
  if (rtmIsMajorTimeStep(lab7_M)) {
    /* Gain: '<Root>/Potentiometer1' */
    lab7_B.Potentiometer1 = lab7_P.Potentiometer1_Gain *
      rtb_HILReadAnalogTimebase1_o1;

    /* Gain: '<Root>/Tacometer1' */
    lab7_B.Tacometer1 = -69.813170079773172 / lab7_P.Kg *
      rtb_HILReadAnalogTimebase1_o2;
  }
}

/* Model update function */
void lab7_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/Derivative1' */
  if (lab7_DW.TimeStampA == (rtInf)) {
    lab7_DW.TimeStampA = lab7_M->Timing.t[0];
    lastU = &lab7_DW.LastUAtTimeA;
  } else if (lab7_DW.TimeStampB == (rtInf)) {
    lab7_DW.TimeStampB = lab7_M->Timing.t[0];
    lastU = &lab7_DW.LastUAtTimeB;
  } else if (lab7_DW.TimeStampA < lab7_DW.TimeStampB) {
    lab7_DW.TimeStampA = lab7_M->Timing.t[0];
    lastU = &lab7_DW.LastUAtTimeA;
  } else {
    lab7_DW.TimeStampB = lab7_M->Timing.t[0];
    lastU = &lab7_DW.LastUAtTimeB;
  }

  *lastU = lab7_B.Encoder1;

  /* End of Update for Derivative: '<Root>/Derivative1' */

  /* Update for Derivative: '<Root>/Derivative' */
  if (lab7_DW.TimeStampA_n == (rtInf)) {
    lab7_DW.TimeStampA_n = lab7_M->Timing.t[0];
    lastU = &lab7_DW.LastUAtTimeA_d;
  } else if (lab7_DW.TimeStampB_m == (rtInf)) {
    lab7_DW.TimeStampB_m = lab7_M->Timing.t[0];
    lastU = &lab7_DW.LastUAtTimeB_p;
  } else if (lab7_DW.TimeStampA_n < lab7_DW.TimeStampB_m) {
    lab7_DW.TimeStampA_n = lab7_M->Timing.t[0];
    lastU = &lab7_DW.LastUAtTimeA_d;
  } else {
    lab7_DW.TimeStampB_m = lab7_M->Timing.t[0];
    lastU = &lab7_DW.LastUAtTimeB_p;
  }

  *lastU = lab7_B.TransferFcn;

  /* End of Update for Derivative: '<Root>/Derivative' */
  if (rtmIsMajorTimeStep(lab7_M)) {
    rt_ertODEUpdateContinuousStates(&lab7_M->solverInfo);
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
  if (!(++lab7_M->Timing.clockTick0)) {
    ++lab7_M->Timing.clockTickH0;
  }

  lab7_M->Timing.t[0] = rtsiGetSolverStopTime(&lab7_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++lab7_M->Timing.clockTick1)) {
      ++lab7_M->Timing.clockTickH1;
    }

    lab7_M->Timing.t[1] = lab7_M->Timing.clockTick1 * lab7_M->Timing.stepSize1 +
      lab7_M->Timing.clockTickH1 * lab7_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void lab7_derivatives(void)
{
  XDot_lab7_T *_rtXdot;
  _rtXdot = ((XDot_lab7_T *) lab7_M->ModelData.derivs);

  /* Derivatives for Integrator: '<Root>/Motor1' */
  _rtXdot->Motor1_CSTATE = lab7_B.Add4;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += lab7_P.TransferFcn_A[0] *
    lab7_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += lab7_P.TransferFcn_A[1] *
    lab7_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[1] += lab7_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += lab7_B.Saturation2;

  /* Derivatives for Integrator: '<Root>/Motor' */
  _rtXdot->Motor_CSTATE = lab7_B.Add2;
}

/* Model initialize function */
void lab7_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lab7/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &lab7_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab7_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(lab7_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab7_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(lab7_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab7_M, _rt_error_message);
      return;
    }

    if ((lab7_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (lab7_P.HILInitialize_set_analog_inpu_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &lab7_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = lab7_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &lab7_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = lab7_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(lab7_DW.HILInitialize_Card,
        lab7_P.HILInitialize_analog_input_chan, 8U,
        &lab7_DW.HILInitialize_AIMinimums[0], &lab7_DW.HILInitialize_AIMaximums
        [0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab7_M, _rt_error_message);
        return;
      }
    }

    if ((lab7_P.HILInitialize_set_analog_output && !is_switching) ||
        (lab7_P.HILInitialize_set_analog_outp_f && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &lab7_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = lab7_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &lab7_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = lab7_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(lab7_DW.HILInitialize_Card,
        lab7_P.HILInitialize_analog_output_cha, 8U,
        &lab7_DW.HILInitialize_AOMinimums[0], &lab7_DW.HILInitialize_AOMaximums
        [0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab7_M, _rt_error_message);
        return;
      }
    }

    if ((lab7_P.HILInitialize_set_analog_outp_g && !is_switching) ||
        (lab7_P.HILInitialize_set_analog_outp_h && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab7_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab7_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(lab7_DW.HILInitialize_Card,
        lab7_P.HILInitialize_analog_output_cha, 8U,
        &lab7_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab7_M, _rt_error_message);
        return;
      }
    }

    if (lab7_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab7_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab7_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (lab7_DW.HILInitialize_Card, lab7_P.HILInitialize_analog_output_cha, 8U,
         &lab7_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab7_M, _rt_error_message);
        return;
      }
    }

    if ((lab7_P.HILInitialize_set_encoder_param && !is_switching) ||
        (lab7_P.HILInitialize_set_encoder_par_j && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes = &lab7_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = lab7_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(lab7_DW.HILInitialize_Card,
        lab7_P.HILInitialize_encoder_channels, 8U, (t_encoder_quadrature_mode *)
        &lab7_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab7_M, _rt_error_message);
        return;
      }
    }

    if ((lab7_P.HILInitialize_set_encoder_count && !is_switching) ||
        (lab7_P.HILInitialize_set_encoder_cou_l && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts = &lab7_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = lab7_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(lab7_DW.HILInitialize_Card,
        lab7_P.HILInitialize_encoder_channels, 8U,
        &lab7_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab7_M, _rt_error_message);
        return;
      }
    }

    if ((lab7_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (lab7_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &lab7_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = lab7_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(lab7_DW.HILInitialize_Card,
        lab7_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &lab7_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab7_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          lab7_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &lab7_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            lab7_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            lab7_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              lab7_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            lab7_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              p_HILInitialize_pwm_channels[i1];
            lab7_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              lab7_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(lab7_DW.HILInitialize_Card,
          &lab7_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &lab7_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab7_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(lab7_DW.HILInitialize_Card,
          &lab7_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &lab7_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab7_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &lab7_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = lab7_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &lab7_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = lab7_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &lab7_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = lab7_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(lab7_DW.HILInitialize_Card,
        lab7_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &lab7_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &lab7_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &lab7_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab7_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &lab7_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = lab7_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &lab7_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab7_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(lab7_DW.HILInitialize_Card,
        lab7_P.HILInitialize_pwm_channels, 8U,
        &lab7_DW.HILInitialize_POSortedFreqs[0],
        &lab7_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab7_M, _rt_error_message);
        return;
      }
    }

    if ((lab7_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (lab7_P.HILInitialize_set_pwm_outputs_l && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &lab7_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab7_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(lab7_DW.HILInitialize_Card,
        lab7_P.HILInitialize_pwm_channels, 8U, &lab7_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab7_M, _rt_error_message);
        return;
      }
    }

    if (lab7_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &lab7_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab7_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state(lab7_DW.HILInitialize_Card,
        lab7_P.HILInitialize_pwm_channels, 8U, &lab7_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab7_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_analog_timebase_block): '<Root>/HIL Read Analog Timebase1' */

  /* S-Function Block: lab7/HIL Read Analog Timebase1 (hil_read_analog_timebase_block) */
  {
    t_error result;
    result = hil_task_create_analog_reader(lab7_DW.HILInitialize_Card,
      lab7_P.HILReadAnalogTimebase1_samples_,
      lab7_P.HILReadAnalogTimebase1_channels, 2,
      &lab7_DW.HILReadAnalogTimebase1_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab7_M, _rt_error_message);
    }
  }

  /* InitializeConditions for Integrator: '<Root>/Motor1' */
  lab7_X.Motor1_CSTATE = lab7_P.Motor1_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  lab7_DW.TimeStampA = (rtInf);
  lab7_DW.TimeStampB = (rtInf);

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  lab7_X.TransferFcn_CSTATE[0] = 0.0;
  lab7_X.TransferFcn_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Motor' */
  lab7_X.Motor_CSTATE = lab7_P.Motor_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  lab7_DW.TimeStampA_n = (rtInf);
  lab7_DW.TimeStampB_m = (rtInf);
}

/* Model terminate function */
void lab7_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lab7/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(lab7_DW.HILInitialize_Card);
    hil_monitor_stop_all(lab7_DW.HILInitialize_Card);
    is_switching = false;
    if ((lab7_P.HILInitialize_set_analog_outp_a && !is_switching) ||
        (lab7_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab7_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab7_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((lab7_P.HILInitialize_set_pwm_outputs_p && !is_switching) ||
        (lab7_P.HILInitialize_set_pwm_output_ab && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &lab7_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab7_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(lab7_DW.HILInitialize_Card
                         , lab7_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , lab7_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &lab7_DW.HILInitialize_AOVoltages[0]
                         , &lab7_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(lab7_DW.HILInitialize_Card,
            lab7_P.HILInitialize_analog_output_cha, num_final_analog_outputs,
            &lab7_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(lab7_DW.HILInitialize_Card,
            lab7_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &lab7_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab7_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(lab7_DW.HILInitialize_Card);
    hil_monitor_delete_all(lab7_DW.HILInitialize_Card);
    hil_close(lab7_DW.HILInitialize_Card);
    lab7_DW.HILInitialize_Card = NULL;
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
  lab7_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  lab7_update();
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
  lab7_initialize();
}

void MdlTerminate(void)
{
  lab7_terminate();
}

/* Registration function */
RT_MODEL_lab7_T *lab7(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lab7_M, 0,
                sizeof(RT_MODEL_lab7_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab7_M->solverInfo, &lab7_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab7_M->solverInfo, &rtmGetTPtr(lab7_M));
    rtsiSetStepSizePtr(&lab7_M->solverInfo, &lab7_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab7_M->solverInfo, &lab7_M->ModelData.derivs);
    rtsiSetContStatesPtr(&lab7_M->solverInfo, (real_T **)
                         &lab7_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&lab7_M->solverInfo, &lab7_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab7_M->solverInfo,
      &lab7_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab7_M->solverInfo,
      &lab7_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab7_M->solverInfo,
      &lab7_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab7_M->solverInfo, (&rtmGetErrorStatus(lab7_M)));
    rtsiSetRTModelPtr(&lab7_M->solverInfo, lab7_M);
  }

  rtsiSetSimTimeStep(&lab7_M->solverInfo, MAJOR_TIME_STEP);
  lab7_M->ModelData.intgData.y = lab7_M->ModelData.odeY;
  lab7_M->ModelData.intgData.f[0] = lab7_M->ModelData.odeF[0];
  lab7_M->ModelData.intgData.f[1] = lab7_M->ModelData.odeF[1];
  lab7_M->ModelData.intgData.f[2] = lab7_M->ModelData.odeF[2];
  lab7_M->ModelData.intgData.f[3] = lab7_M->ModelData.odeF[3];
  lab7_M->ModelData.contStates = ((real_T *) &lab7_X);
  rtsiSetSolverData(&lab7_M->solverInfo, (void *)&lab7_M->ModelData.intgData);
  rtsiSetSolverName(&lab7_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab7_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    lab7_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab7_M->Timing.sampleTimes = (&lab7_M->Timing.sampleTimesArray[0]);
    lab7_M->Timing.offsetTimes = (&lab7_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab7_M->Timing.sampleTimes[0] = (0.0);
    lab7_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    lab7_M->Timing.offsetTimes[0] = (0.0);
    lab7_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(lab7_M, &lab7_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab7_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    lab7_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab7_M, 4.0);
  lab7_M->Timing.stepSize0 = 0.002;
  lab7_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  lab7_M->Sizes.checksums[0] = (263058820U);
  lab7_M->Sizes.checksums[1] = (892302248U);
  lab7_M->Sizes.checksums[2] = (912819785U);
  lab7_M->Sizes.checksums[3] = (3201622611U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    lab7_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lab7_M->extModeInfo,
      &lab7_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lab7_M->extModeInfo, lab7_M->Sizes.checksums);
    rteiSetTPtr(lab7_M->extModeInfo, rtmGetTPtr(lab7_M));
  }

  lab7_M->solverInfoPtr = (&lab7_M->solverInfo);
  lab7_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&lab7_M->solverInfo, 0.002);
  rtsiSetSolverMode(&lab7_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  lab7_M->ModelData.blockIO = ((void *) &lab7_B);
  (void) memset(((void *) &lab7_B), 0,
                sizeof(B_lab7_T));

  /* parameters */
  lab7_M->ModelData.defaultParam = ((real_T *)&lab7_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &lab7_X;
    lab7_M->ModelData.contStates = (x);
    (void) memset((void *)&lab7_X, 0,
                  sizeof(X_lab7_T));
  }

  /* states (dwork) */
  lab7_M->ModelData.dwork = ((void *) &lab7_DW);
  (void) memset((void *)&lab7_DW, 0,
                sizeof(DW_lab7_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lab7_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  lab7_M->Sizes.numContStates = (4);   /* Number of continuous states */
  lab7_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  lab7_M->Sizes.numY = (0);            /* Number of model outputs */
  lab7_M->Sizes.numU = (0);            /* Number of model inputs */
  lab7_M->Sizes.sysDirFeedThru = (0);  /* The model is not direct feedthrough */
  lab7_M->Sizes.numSampTimes = (2);    /* Number of sample times */
  lab7_M->Sizes.numBlocks = (34);      /* Number of blocks */
  lab7_M->Sizes.numBlockIO = (8);      /* Number of block outputs */
  lab7_M->Sizes.numBlockPrms = (124);  /* Sum of parameter "widths" */
  return lab7_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
