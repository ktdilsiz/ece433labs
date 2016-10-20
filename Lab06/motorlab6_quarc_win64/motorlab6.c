/*
 * motorlab6.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "motorlab6".
 *
 * Model version              : 1.3
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed Oct 19 21:28:19 2016
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motorlab6.h"
#include "motorlab6_private.h"
#include "motorlab6_dt.h"

/* Block signals (auto storage) */
B_motorlab6_T motorlab6_B;

/* Continuous states */
X_motorlab6_T motorlab6_X;

/* Block states (auto storage) */
DW_motorlab6_T motorlab6_DW;

/* Real-time model */
RT_MODEL_motorlab6_T motorlab6_M_;
RT_MODEL_motorlab6_T *const motorlab6_M = &motorlab6_M_;

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
  int_T nXc = 7;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  motorlab6_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  motorlab6_output();
  motorlab6_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  motorlab6_output();
  motorlab6_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  motorlab6_output();
  motorlab6_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void motorlab6_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalogTimebase_o1;
  real_T rtb_Diff;
  real_T rtb_Add2;
  real_T rtb_Step2;
  real_T tmp;
  if (rtmIsMajorTimeStep(motorlab6_M)) {
    /* set solver stop time */
    if (!(motorlab6_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&motorlab6_M->solverInfo,
                            ((motorlab6_M->Timing.clockTickH0 + 1) *
        motorlab6_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&motorlab6_M->solverInfo,
                            ((motorlab6_M->Timing.clockTick0 + 1) *
        motorlab6_M->Timing.stepSize0 + motorlab6_M->Timing.clockTickH0 *
        motorlab6_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(motorlab6_M)) {
    motorlab6_M->Timing.t[0] = rtsiGetT(&motorlab6_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(motorlab6_M)) {
    /* S-Function (hil_read_analog_timebase_block): '<Root>/HIL Read Analog Timebase' */

    /* S-Function Block: motorlab6/HIL Read Analog Timebase (hil_read_analog_timebase_block) */
    {
      t_error result;
      result = hil_task_read_analog(motorlab6_DW.HILReadAnalogTimebase_Task, 1,
        &motorlab6_DW.HILReadAnalogTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(motorlab6_M, _rt_error_message);
      }

      rtb_HILReadAnalogTimebase_o1 = motorlab6_DW.HILReadAnalogTimebase_Buffer[0];
      rtb_Diff = motorlab6_DW.HILReadAnalogTimebase_Buffer[1];
    }

    /* Gain: '<Root>/Tacometer' */
    motorlab6_B.Tacometer = -69.813170079773172 / motorlab6_P.Kg * rtb_Diff;

    /* Gain: '<Root>/Gain2' */
    motorlab6_B.Gain2 = motorlab6_P.Kp * motorlab6_B.Tacometer;
  }

  /* Sum: '<Root>/Add5' incorporates:
   *  TransferFcn: '<Root>/Transfer Fcn4'
   */
  rtb_Step2 = motorlab6_P.TransferFcn4_C * motorlab6_X.TransferFcn4_CSTATE -
    motorlab6_B.Gain2;

  /* Saturate: '<Root>/Saturation2' */
  if (rtb_Step2 > motorlab6_P.Saturation2_UpperSat) {
    motorlab6_B.Saturation2 = motorlab6_P.Saturation2_UpperSat;
  } else if (rtb_Step2 < motorlab6_P.Saturation2_LowerSat) {
    motorlab6_B.Saturation2 = motorlab6_P.Saturation2_LowerSat;
  } else {
    motorlab6_B.Saturation2 = rtb_Step2;
  }

  /* End of Saturate: '<Root>/Saturation2' */

  /* Gain: '<Root>/Gain1' */
  motorlab6_B.Gain1 = motorlab6_P.Gain1_Gain * motorlab6_B.Saturation2;
  if (rtmIsMajorTimeStep(motorlab6_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: motorlab6/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(motorlab6_DW.HILInitialize_Card,
        &motorlab6_P.HILWriteAnalog_channels, 1, &motorlab6_B.Gain1);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(motorlab6_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: motorlab6/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(motorlab6_DW.HILInitialize_Card,
        &motorlab6_P.HILReadEncoder_channels, 1,
        &motorlab6_DW.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(motorlab6_M, _rt_error_message);
      } else {
        rtb_Diff = motorlab6_DW.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<Root>/Encoder' */
    motorlab6_B.Encoder = motorlab6_P.Encoder_Gain * rtb_Diff;

    /* SampleTimeMath: '<S2>/TSamp'
     *
     * About '<S2>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    motorlab6_B.TSamp = motorlab6_B.Encoder * motorlab6_P.TSamp_WtEt;

    /* Sum: '<S2>/Diff' incorporates:
     *  UnitDelay: '<S2>/UD'
     */
    rtb_Diff = motorlab6_B.TSamp - motorlab6_DW.UD_DSTATE;

    /* S-Function (sdspbiquad): '<S1>/Digital Filter' */
    rtb_Step2 = (0.0018201287110544873 * rtb_Diff - -1.8757455717092213 *
                 motorlab6_DW.DigitalFilter_FILT_STATES[0]) -
      0.88302608655343917 * motorlab6_DW.DigitalFilter_FILT_STATES[1];
    motorlab6_B.DigitalFilter = (2.0 * motorlab6_DW.DigitalFilter_FILT_STATES[0]
      + rtb_Step2) + motorlab6_DW.DigitalFilter_FILT_STATES[1];
    motorlab6_DW.DigitalFilter_FILT_STATES[1] =
      motorlab6_DW.DigitalFilter_FILT_STATES[0];
    motorlab6_DW.DigitalFilter_FILT_STATES[0] = rtb_Step2;
  }

  /* TransferFcn: '<Root>/Transfer Fcn5' */
  motorlab6_B.TransferFcn5 = 0.0;
  motorlab6_B.TransferFcn5 += motorlab6_P.TransferFcn5_C[0] *
    motorlab6_X.TransferFcn5_CSTATE[0];
  motorlab6_B.TransferFcn5 += motorlab6_P.TransferFcn5_C[1] *
    motorlab6_X.TransferFcn5_CSTATE[1];
  if (rtmIsMajorTimeStep(motorlab6_M)) {
  }

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  motorlab6_B.TransferFcn1 = 0.0;
  motorlab6_B.TransferFcn1 += motorlab6_P.TransferFcn1_C *
    motorlab6_X.TransferFcn1_CSTATE;

  /* TransferFcn: '<Root>/Transfer Fcn3' */
  motorlab6_B.TransferFcn3 = 0.0;
  motorlab6_B.TransferFcn3 += motorlab6_P.TransferFcn3_C *
    motorlab6_X.TransferFcn3_CSTATE;
  if (rtmIsMajorTimeStep(motorlab6_M)) {
    /* Gain: '<Root>/Potentiometer' */
    motorlab6_B.Potentiometer = motorlab6_P.Potentiometer_Gain *
      rtb_HILReadAnalogTimebase_o1;
  }

  /* Step: '<Root>/Step2' */
  if (motorlab6_M->Timing.t[0] < motorlab6_P.Step2_Time) {
    rtb_Step2 = motorlab6_P.Step2_Y0;
  } else {
    rtb_Step2 = motorlab6_P.Step2_YFinal;
  }

  /* End of Step: '<Root>/Step2' */

  /* Sum: '<Root>/Add1' */
  motorlab6_B.Add1 = rtb_Step2 - motorlab6_B.TransferFcn3;

  /* Sum: '<Root>/Add2' incorporates:
   *  Gain: '<Root>/Gain8'
   *  TransferFcn: '<Root>/Transfer Fcn2'
   */
  rtb_Add2 = motorlab6_P.TransferFcn2_C * motorlab6_X.TransferFcn2_CSTATE -
    motorlab6_P.Kp * motorlab6_B.TransferFcn3;
  if (rtmIsMajorTimeStep(motorlab6_M)) {
    /* ManualSwitch: '<Root>/Manual Switch1' */
    if (motorlab6_P.ManualSwitch1_CurrentSetting == 1) {
      motorlab6_B.ManualSwitch1 = motorlab6_B.Tacometer;
    } else {
      motorlab6_B.ManualSwitch1 = motorlab6_B.DigitalFilter;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch1' */
  }

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (motorlab6_P.ManualSwitch_CurrentSetting == 1) {
    tmp = motorlab6_B.ManualSwitch1;
  } else {
    tmp = motorlab6_B.TransferFcn5;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Sum: '<Root>/Add3' */
  motorlab6_B.Add3 = rtb_Step2 - tmp;

  /* Sum: '<Root>/Add4' */
  motorlab6_B.Add4 = rtb_Step2 - motorlab6_B.TransferFcn1;

  /* TransferFcn: '<Root>/Transfer Fcn' */
  rtb_Step2 = motorlab6_P.TransferFcn_C * motorlab6_X.TransferFcn_CSTATE +
    motorlab6_P.TransferFcn_D * motorlab6_B.Add4;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Step2 > motorlab6_P.Saturation_UpperSat) {
    motorlab6_B.Saturation = motorlab6_P.Saturation_UpperSat;
  } else if (rtb_Step2 < motorlab6_P.Saturation_LowerSat) {
    motorlab6_B.Saturation = motorlab6_P.Saturation_LowerSat;
  } else {
    motorlab6_B.Saturation = rtb_Step2;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_Add2 > motorlab6_P.Saturation1_UpperSat) {
    motorlab6_B.Saturation1 = motorlab6_P.Saturation1_UpperSat;
  } else if (rtb_Add2 < motorlab6_P.Saturation1_LowerSat) {
    motorlab6_B.Saturation1 = motorlab6_P.Saturation1_LowerSat;
  } else {
    motorlab6_B.Saturation1 = rtb_Add2;
  }

  /* End of Saturate: '<Root>/Saturation1' */
}

/* Model update function */
void motorlab6_update(void)
{
  if (rtmIsMajorTimeStep(motorlab6_M)) {
    /* Update for UnitDelay: '<S2>/UD' */
    motorlab6_DW.UD_DSTATE = motorlab6_B.TSamp;
  }

  if (rtmIsMajorTimeStep(motorlab6_M)) {
    rt_ertODEUpdateContinuousStates(&motorlab6_M->solverInfo);
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
  if (!(++motorlab6_M->Timing.clockTick0)) {
    ++motorlab6_M->Timing.clockTickH0;
  }

  motorlab6_M->Timing.t[0] = rtsiGetSolverStopTime(&motorlab6_M->solverInfo);

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
    if (!(++motorlab6_M->Timing.clockTick1)) {
      ++motorlab6_M->Timing.clockTickH1;
    }

    motorlab6_M->Timing.t[1] = motorlab6_M->Timing.clockTick1 *
      motorlab6_M->Timing.stepSize1 + motorlab6_M->Timing.clockTickH1 *
      motorlab6_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void motorlab6_derivatives(void)
{
  XDot_motorlab6_T *_rtXdot;
  _rtXdot = ((XDot_motorlab6_T *) motorlab6_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn4' */
  _rtXdot->TransferFcn4_CSTATE = 0.0;
  _rtXdot->TransferFcn4_CSTATE += motorlab6_P.TransferFcn4_A *
    motorlab6_X.TransferFcn4_CSTATE;
  _rtXdot->TransferFcn4_CSTATE += motorlab6_B.Add3;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn5' */
  _rtXdot->TransferFcn5_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn5_CSTATE[0] += motorlab6_P.TransferFcn5_A[0] *
    motorlab6_X.TransferFcn5_CSTATE[0];
  _rtXdot->TransferFcn5_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn5_CSTATE[0] += motorlab6_P.TransferFcn5_A[1] *
    motorlab6_X.TransferFcn5_CSTATE[1];
  _rtXdot->TransferFcn5_CSTATE[1] += motorlab6_X.TransferFcn5_CSTATE[0];
  _rtXdot->TransferFcn5_CSTATE[0] += motorlab6_B.Encoder;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += motorlab6_P.TransferFcn1_A *
    motorlab6_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += motorlab6_B.Saturation;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE = 0.0;
  _rtXdot->TransferFcn3_CSTATE += motorlab6_P.TransferFcn3_A *
    motorlab6_X.TransferFcn3_CSTATE;
  _rtXdot->TransferFcn3_CSTATE += motorlab6_B.Saturation1;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += motorlab6_P.TransferFcn2_A *
    motorlab6_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += motorlab6_B.Add1;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += motorlab6_P.TransferFcn_A *
    motorlab6_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += motorlab6_B.Add4;
}

/* Model initialize function */
void motorlab6_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: motorlab6/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &motorlab6_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(motorlab6_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(motorlab6_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(motorlab6_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(motorlab6_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(motorlab6_M, _rt_error_message);
      return;
    }

    if ((motorlab6_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (motorlab6_P.HILInitialize_set_analog_inpu_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &motorlab6_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = motorlab6_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &motorlab6_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = motorlab6_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(motorlab6_DW.HILInitialize_Card,
        motorlab6_P.HILInitialize_analog_input_chan, 8U,
        &motorlab6_DW.HILInitialize_AIMinimums[0],
        &motorlab6_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(motorlab6_M, _rt_error_message);
        return;
      }
    }

    if ((motorlab6_P.HILInitialize_set_analog_output && !is_switching) ||
        (motorlab6_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &motorlab6_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = motorlab6_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &motorlab6_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = motorlab6_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(motorlab6_DW.HILInitialize_Card,
        motorlab6_P.HILInitialize_analog_output_cha, 8U,
        &motorlab6_DW.HILInitialize_AOMinimums[0],
        &motorlab6_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(motorlab6_M, _rt_error_message);
        return;
      }
    }

    if ((motorlab6_P.HILInitialize_set_analog_outp_c && !is_switching) ||
        (motorlab6_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &motorlab6_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = motorlab6_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(motorlab6_DW.HILInitialize_Card,
        motorlab6_P.HILInitialize_analog_output_cha, 8U,
        &motorlab6_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(motorlab6_M, _rt_error_message);
        return;
      }
    }

    if (motorlab6_P.HILInitialize_set_analog_outp_i) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &motorlab6_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = motorlab6_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (motorlab6_DW.HILInitialize_Card,
         motorlab6_P.HILInitialize_analog_output_cha, 8U,
         &motorlab6_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(motorlab6_M, _rt_error_message);
        return;
      }
    }

    if ((motorlab6_P.HILInitialize_set_encoder_param && !is_switching) ||
        (motorlab6_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &motorlab6_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = motorlab6_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(motorlab6_DW.HILInitialize_Card,
        motorlab6_P.HILInitialize_encoder_channels, 8U,
        (t_encoder_quadrature_mode *)
        &motorlab6_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(motorlab6_M, _rt_error_message);
        return;
      }
    }

    if ((motorlab6_P.HILInitialize_set_encoder_count && !is_switching) ||
        (motorlab6_P.HILInitialize_set_encoder_cou_h && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &motorlab6_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = motorlab6_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(motorlab6_DW.HILInitialize_Card,
        motorlab6_P.HILInitialize_encoder_channels, 8U,
        &motorlab6_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(motorlab6_M, _rt_error_message);
        return;
      }
    }

    if ((motorlab6_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (motorlab6_P.HILInitialize_set_pwm_params__a && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &motorlab6_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = motorlab6_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(motorlab6_DW.HILInitialize_Card,
        motorlab6_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &motorlab6_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(motorlab6_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          motorlab6_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &motorlab6_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            motorlab6_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            motorlab6_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              motorlab6_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            motorlab6_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              p_HILInitialize_pwm_channels[i1];
            motorlab6_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              motorlab6_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(motorlab6_DW.HILInitialize_Card,
          &motorlab6_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &motorlab6_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(motorlab6_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(motorlab6_DW.HILInitialize_Card,
          &motorlab6_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &motorlab6_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(motorlab6_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &motorlab6_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = motorlab6_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &motorlab6_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = motorlab6_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &motorlab6_DW.HILInitialize_POPolarityVals
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = motorlab6_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(motorlab6_DW.HILInitialize_Card,
        motorlab6_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &motorlab6_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &motorlab6_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &motorlab6_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(motorlab6_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &motorlab6_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = motorlab6_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &motorlab6_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = motorlab6_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(motorlab6_DW.HILInitialize_Card,
        motorlab6_P.HILInitialize_pwm_channels, 8U,
        &motorlab6_DW.HILInitialize_POSortedFreqs[0],
        &motorlab6_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(motorlab6_M, _rt_error_message);
        return;
      }
    }

    if ((motorlab6_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (motorlab6_P.HILInitialize_set_pwm_outputs_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &motorlab6_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = motorlab6_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(motorlab6_DW.HILInitialize_Card,
        motorlab6_P.HILInitialize_pwm_channels, 8U,
        &motorlab6_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(motorlab6_M, _rt_error_message);
        return;
      }
    }

    if (motorlab6_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &motorlab6_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = motorlab6_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (motorlab6_DW.HILInitialize_Card, motorlab6_P.HILInitialize_pwm_channels,
         8U, &motorlab6_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(motorlab6_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_analog_timebase_block): '<Root>/HIL Read Analog Timebase' */

  /* S-Function Block: motorlab6/HIL Read Analog Timebase (hil_read_analog_timebase_block) */
  {
    t_error result;
    result = hil_task_create_analog_reader(motorlab6_DW.HILInitialize_Card,
      motorlab6_P.HILReadAnalogTimebase_samples_i,
      motorlab6_P.HILReadAnalogTimebase_channels, 2,
      &motorlab6_DW.HILReadAnalogTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(motorlab6_M, _rt_error_message);
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn4' */
  motorlab6_X.TransferFcn4_CSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S2>/UD' */
  motorlab6_DW.UD_DSTATE = motorlab6_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for S-Function (sdspbiquad): '<S1>/Digital Filter' */
  motorlab6_DW.DigitalFilter_FILT_STATES[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn5' */
  motorlab6_X.TransferFcn5_CSTATE[0] = 0.0;

  /* InitializeConditions for S-Function (sdspbiquad): '<S1>/Digital Filter' */
  motorlab6_DW.DigitalFilter_FILT_STATES[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn5' */
  motorlab6_X.TransferFcn5_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  motorlab6_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn3' */
  motorlab6_X.TransferFcn3_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
  motorlab6_X.TransferFcn2_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  motorlab6_X.TransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void motorlab6_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: motorlab6/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(motorlab6_DW.HILInitialize_Card);
    hil_monitor_stop_all(motorlab6_DW.HILInitialize_Card);
    is_switching = false;
    if ((motorlab6_P.HILInitialize_set_analog_out_py && !is_switching) ||
        (motorlab6_P.HILInitialize_set_analog_outp_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &motorlab6_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = motorlab6_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((motorlab6_P.HILInitialize_set_pwm_outputs_k && !is_switching) ||
        (motorlab6_P.HILInitialize_set_pwm_outputs_h && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &motorlab6_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = motorlab6_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(motorlab6_DW.HILInitialize_Card
                         , motorlab6_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , motorlab6_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &motorlab6_DW.HILInitialize_AOVoltages[0]
                         , &motorlab6_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(motorlab6_DW.HILInitialize_Card,
            motorlab6_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs, &motorlab6_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(motorlab6_DW.HILInitialize_Card,
            motorlab6_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &motorlab6_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(motorlab6_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(motorlab6_DW.HILInitialize_Card);
    hil_monitor_delete_all(motorlab6_DW.HILInitialize_Card);
    hil_close(motorlab6_DW.HILInitialize_Card);
    motorlab6_DW.HILInitialize_Card = NULL;
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
  motorlab6_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  motorlab6_update();
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
  motorlab6_initialize();
}

void MdlTerminate(void)
{
  motorlab6_terminate();
}

/* Registration function */
RT_MODEL_motorlab6_T *motorlab6(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)motorlab6_M, 0,
                sizeof(RT_MODEL_motorlab6_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&motorlab6_M->solverInfo,
                          &motorlab6_M->Timing.simTimeStep);
    rtsiSetTPtr(&motorlab6_M->solverInfo, &rtmGetTPtr(motorlab6_M));
    rtsiSetStepSizePtr(&motorlab6_M->solverInfo, &motorlab6_M->Timing.stepSize0);
    rtsiSetdXPtr(&motorlab6_M->solverInfo, &motorlab6_M->ModelData.derivs);
    rtsiSetContStatesPtr(&motorlab6_M->solverInfo, (real_T **)
                         &motorlab6_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&motorlab6_M->solverInfo,
      &motorlab6_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&motorlab6_M->solverInfo,
      &motorlab6_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&motorlab6_M->solverInfo,
      &motorlab6_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&motorlab6_M->solverInfo,
      &motorlab6_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&motorlab6_M->solverInfo, (&rtmGetErrorStatus
      (motorlab6_M)));
    rtsiSetRTModelPtr(&motorlab6_M->solverInfo, motorlab6_M);
  }

  rtsiSetSimTimeStep(&motorlab6_M->solverInfo, MAJOR_TIME_STEP);
  motorlab6_M->ModelData.intgData.y = motorlab6_M->ModelData.odeY;
  motorlab6_M->ModelData.intgData.f[0] = motorlab6_M->ModelData.odeF[0];
  motorlab6_M->ModelData.intgData.f[1] = motorlab6_M->ModelData.odeF[1];
  motorlab6_M->ModelData.intgData.f[2] = motorlab6_M->ModelData.odeF[2];
  motorlab6_M->ModelData.intgData.f[3] = motorlab6_M->ModelData.odeF[3];
  motorlab6_M->ModelData.contStates = ((real_T *) &motorlab6_X);
  rtsiSetSolverData(&motorlab6_M->solverInfo, (void *)
                    &motorlab6_M->ModelData.intgData);
  rtsiSetSolverName(&motorlab6_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = motorlab6_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    motorlab6_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    motorlab6_M->Timing.sampleTimes = (&motorlab6_M->Timing.sampleTimesArray[0]);
    motorlab6_M->Timing.offsetTimes = (&motorlab6_M->Timing.offsetTimesArray[0]);

    /* task periods */
    motorlab6_M->Timing.sampleTimes[0] = (0.0);
    motorlab6_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    motorlab6_M->Timing.offsetTimes[0] = (0.0);
    motorlab6_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(motorlab6_M, &motorlab6_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = motorlab6_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    motorlab6_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(motorlab6_M, 7.0);
  motorlab6_M->Timing.stepSize0 = 0.001;
  motorlab6_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  motorlab6_M->Sizes.checksums[0] = (2241213851U);
  motorlab6_M->Sizes.checksums[1] = (2964355701U);
  motorlab6_M->Sizes.checksums[2] = (3700503339U);
  motorlab6_M->Sizes.checksums[3] = (3131954492U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    motorlab6_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(motorlab6_M->extModeInfo,
      &motorlab6_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(motorlab6_M->extModeInfo, motorlab6_M->Sizes.checksums);
    rteiSetTPtr(motorlab6_M->extModeInfo, rtmGetTPtr(motorlab6_M));
  }

  motorlab6_M->solverInfoPtr = (&motorlab6_M->solverInfo);
  motorlab6_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&motorlab6_M->solverInfo, 0.001);
  rtsiSetSolverMode(&motorlab6_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  motorlab6_M->ModelData.blockIO = ((void *) &motorlab6_B);
  (void) memset(((void *) &motorlab6_B), 0,
                sizeof(B_motorlab6_T));

  /* parameters */
  motorlab6_M->ModelData.defaultParam = ((real_T *)&motorlab6_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &motorlab6_X;
    motorlab6_M->ModelData.contStates = (x);
    (void) memset((void *)&motorlab6_X, 0,
                  sizeof(X_motorlab6_T));
  }

  /* states (dwork) */
  motorlab6_M->ModelData.dwork = ((void *) &motorlab6_DW);
  (void) memset((void *)&motorlab6_DW, 0,
                sizeof(DW_motorlab6_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    motorlab6_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  motorlab6_M->Sizes.numContStates = (7);/* Number of continuous states */
  motorlab6_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  motorlab6_M->Sizes.numY = (0);       /* Number of model outputs */
  motorlab6_M->Sizes.numU = (0);       /* Number of model inputs */
  motorlab6_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  motorlab6_M->Sizes.numSampTimes = (2);/* Number of sample times */
  motorlab6_M->Sizes.numBlocks = (35); /* Number of blocks */
  motorlab6_M->Sizes.numBlockIO = (17);/* Number of block outputs */
  motorlab6_M->Sizes.numBlockPrms = (136);/* Sum of parameter "widths" */
  return motorlab6_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
