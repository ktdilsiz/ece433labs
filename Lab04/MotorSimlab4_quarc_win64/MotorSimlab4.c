/*
 * MotorSimlab4.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MotorSimlab4".
 *
 * Model version              : 1.6
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Thu Sep 29 13:53:24 2016
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorSimlab4.h"
#include "MotorSimlab4_private.h"
#include "MotorSimlab4_dt.h"

/* Block signals (auto storage) */
B_MotorSimlab4_T MotorSimlab4_B;

/* Continuous states */
X_MotorSimlab4_T MotorSimlab4_X;

/* Block states (auto storage) */
DW_MotorSimlab4_T MotorSimlab4_DW;

/* Real-time model */
RT_MODEL_MotorSimlab4_T MotorSimlab4_M_;
RT_MODEL_MotorSimlab4_T *const MotorSimlab4_M = &MotorSimlab4_M_;

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  MotorSimlab4_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  MotorSimlab4_output();
  MotorSimlab4_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  MotorSimlab4_output();
  MotorSimlab4_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  MotorSimlab4_output();
  MotorSimlab4_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void MotorSimlab4_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalogTimebase_o1;
  real_T rtb_HILReadEncoder;
  real_T temp;
  if (rtmIsMajorTimeStep(MotorSimlab4_M)) {
    /* set solver stop time */
    if (!(MotorSimlab4_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&MotorSimlab4_M->solverInfo,
                            ((MotorSimlab4_M->Timing.clockTickH0 + 1) *
        MotorSimlab4_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&MotorSimlab4_M->solverInfo,
                            ((MotorSimlab4_M->Timing.clockTick0 + 1) *
        MotorSimlab4_M->Timing.stepSize0 + MotorSimlab4_M->Timing.clockTickH0 *
        MotorSimlab4_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(MotorSimlab4_M)) {
    MotorSimlab4_M->Timing.t[0] = rtsiGetT(&MotorSimlab4_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(MotorSimlab4_M)) {
    /* S-Function (hil_read_analog_timebase_block): '<Root>/HIL Read Analog Timebase' */

    /* S-Function Block: MotorSimlab4/HIL Read Analog Timebase (hil_read_analog_timebase_block) */
    {
      t_error result;
      result = hil_task_read_analog(MotorSimlab4_DW.HILReadAnalogTimebase_Task,
        1, &MotorSimlab4_DW.HILReadAnalogTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
      }

      rtb_HILReadAnalogTimebase_o1 =
        MotorSimlab4_DW.HILReadAnalogTimebase_Buffer[0];
      rtb_HILReadEncoder = MotorSimlab4_DW.HILReadAnalogTimebase_Buffer[1];
    }
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  temp = MotorSimlab4_P.SignalGenerator_Frequency * MotorSimlab4_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    temp = MotorSimlab4_P.SignalGenerator_Amplitude;
  } else {
    temp = -MotorSimlab4_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Bias: '<Root>/Bias' */
  MotorSimlab4_B.Bias = temp + MotorSimlab4_P.Bias_Bias;

  /* Gain: '<Root>/Gain1' */
  MotorSimlab4_B.Gain1 = MotorSimlab4_P.Gain1_Gain * MotorSimlab4_B.Bias;
  if (rtmIsMajorTimeStep(MotorSimlab4_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: MotorSimlab4/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(MotorSimlab4_DW.HILInitialize_Card,
        &MotorSimlab4_P.HILWriteAnalog_channels, 1, &MotorSimlab4_B.Gain1);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
      }
    }
  }

  /* Integrator: '<Root>/Motor' */
  MotorSimlab4_B.Motor = MotorSimlab4_X.Motor_CSTATE;
  if (rtmIsMajorTimeStep(MotorSimlab4_M)) {
    /* ToFile: '<Root>/ThetaFile' */
    {
      if (!(++MotorSimlab4_DW.ThetaFile_IWORK.Decimation % 1) &&
          (MotorSimlab4_DW.ThetaFile_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) MotorSimlab4_DW.ThetaFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          MotorSimlab4_DW.ThetaFile_IWORK.Decimation = 0;
          u[0] = MotorSimlab4_M->Timing.t[1];
          u[1] = MotorSimlab4_B.Motor;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(MotorSimlab4_M,
                              "Error writing to MAT-file ThetaSim.mat");
            return;
          }

          if (((++MotorSimlab4_DW.ThetaFile_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file ThetaSim.mat.\n");
          }
        }
      }
    }

    /* ToFile: '<Root>/VsimFile' */
    {
      if (!(++MotorSimlab4_DW.VsimFile_IWORK.Decimation % 1) &&
          (MotorSimlab4_DW.VsimFile_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) MotorSimlab4_DW.VsimFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          MotorSimlab4_DW.VsimFile_IWORK.Decimation = 0;
          u[0] = MotorSimlab4_M->Timing.t[1];
          u[1] = MotorSimlab4_B.Bias;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(MotorSimlab4_M,
                              "Error writing to MAT-file Vsim.mat");
            return;
          }

          if (((++MotorSimlab4_DW.VsimFile_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file Vsim.mat.\n");
          }
        }
      }
    }
  }

  /* Integrator: '<Root>/Motor2' */
  MotorSimlab4_B.Motor2 = MotorSimlab4_X.Motor2_CSTATE;
  if (rtmIsMajorTimeStep(MotorSimlab4_M)) {
    /* Gain: '<Root>/Tacometer' */
    MotorSimlab4_B.Tacometer = -69.813170079773172 / MotorSimlab4_P.Kg *
      rtb_HILReadEncoder;

    /* ToFile: '<Root>/WsimFile1' */
    {
      if (!(++MotorSimlab4_DW.WsimFile1_IWORK.Decimation % 1) &&
          (MotorSimlab4_DW.WsimFile1_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) MotorSimlab4_DW.WsimFile1_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          MotorSimlab4_DW.WsimFile1_IWORK.Decimation = 0;
          u[0] = MotorSimlab4_M->Timing.t[1];
          u[1] = MotorSimlab4_B.Motor2;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(MotorSimlab4_M,
                              "Error writing to MAT-file Wsim.mat");
            return;
          }

          if (((++MotorSimlab4_DW.WsimFile1_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file Wsim.mat.\n");
          }
        }
      }
    }

    /* Gain: '<Root>/Potentiometer' */
    MotorSimlab4_B.Potentiometer = MotorSimlab4_P.Potentiometer_Gain *
      rtb_HILReadAnalogTimebase_o1;

    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: MotorSimlab4/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(MotorSimlab4_DW.HILInitialize_Card,
        &MotorSimlab4_P.HILReadEncoder_channels, 1,
        &MotorSimlab4_DW.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder = MotorSimlab4_DW.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<Root>/Encoder' */
    MotorSimlab4_B.Encoder = MotorSimlab4_P.Encoder_Gain * rtb_HILReadEncoder;
  }

  /* Sum: '<Root>/Add2' incorporates:
   *  Gain: '<Root>/Gain3'
   *  Gain: '<Root>/Gain4'
   */
  MotorSimlab4_B.Add2 = MotorSimlab4_P.Ka / MotorSimlab4_P.Rm *
    MotorSimlab4_B.Bias - (MotorSimlab4_P.Ka * MotorSimlab4_P.Kb /
    MotorSimlab4_P.Rm + MotorSimlab4_P.Beq / MotorSimlab4_P.Jeq) *
    MotorSimlab4_B.Motor2;
}

/* Model update function */
void MotorSimlab4_update(void)
{
  if (rtmIsMajorTimeStep(MotorSimlab4_M)) {
    rt_ertODEUpdateContinuousStates(&MotorSimlab4_M->solverInfo);
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
  if (!(++MotorSimlab4_M->Timing.clockTick0)) {
    ++MotorSimlab4_M->Timing.clockTickH0;
  }

  MotorSimlab4_M->Timing.t[0] = rtsiGetSolverStopTime
    (&MotorSimlab4_M->solverInfo);

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
    if (!(++MotorSimlab4_M->Timing.clockTick1)) {
      ++MotorSimlab4_M->Timing.clockTickH1;
    }

    MotorSimlab4_M->Timing.t[1] = MotorSimlab4_M->Timing.clockTick1 *
      MotorSimlab4_M->Timing.stepSize1 + MotorSimlab4_M->Timing.clockTickH1 *
      MotorSimlab4_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void MotorSimlab4_derivatives(void)
{
  XDot_MotorSimlab4_T *_rtXdot;
  _rtXdot = ((XDot_MotorSimlab4_T *) MotorSimlab4_M->ModelData.derivs);

  /* Derivatives for Integrator: '<Root>/Motor' */
  _rtXdot->Motor_CSTATE = MotorSimlab4_B.Motor2;

  /* Derivatives for Integrator: '<Root>/Motor2' */
  _rtXdot->Motor2_CSTATE = MotorSimlab4_B.Add2;
}

/* Model initialize function */
void MotorSimlab4_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: MotorSimlab4/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &MotorSimlab4_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(MotorSimlab4_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(MotorSimlab4_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
      return;
    }

    if ((MotorSimlab4_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (MotorSimlab4_P.HILInitialize_set_analog_inpu_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &MotorSimlab4_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = MotorSimlab4_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &MotorSimlab4_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = MotorSimlab4_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(MotorSimlab4_DW.HILInitialize_Card,
        MotorSimlab4_P.HILInitialize_analog_input_chan, 8U,
        &MotorSimlab4_DW.HILInitialize_AIMinimums[0],
        &MotorSimlab4_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
        return;
      }
    }

    if ((MotorSimlab4_P.HILInitialize_set_analog_output && !is_switching) ||
        (MotorSimlab4_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &MotorSimlab4_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = MotorSimlab4_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &MotorSimlab4_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = MotorSimlab4_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(MotorSimlab4_DW.HILInitialize_Card,
        MotorSimlab4_P.HILInitialize_analog_output_cha, 8U,
        &MotorSimlab4_DW.HILInitialize_AOMinimums[0],
        &MotorSimlab4_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
        return;
      }
    }

    if ((MotorSimlab4_P.HILInitialize_set_analog_outp_c && !is_switching) ||
        (MotorSimlab4_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &MotorSimlab4_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = MotorSimlab4_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(MotorSimlab4_DW.HILInitialize_Card,
        MotorSimlab4_P.HILInitialize_analog_output_cha, 8U,
        &MotorSimlab4_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
        return;
      }
    }

    if (MotorSimlab4_P.HILInitialize_set_analog_outp_i) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &MotorSimlab4_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = MotorSimlab4_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (MotorSimlab4_DW.HILInitialize_Card,
         MotorSimlab4_P.HILInitialize_analog_output_cha, 8U,
         &MotorSimlab4_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
        return;
      }
    }

    if ((MotorSimlab4_P.HILInitialize_set_encoder_param && !is_switching) ||
        (MotorSimlab4_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &MotorSimlab4_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = MotorSimlab4_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (MotorSimlab4_DW.HILInitialize_Card,
         MotorSimlab4_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &MotorSimlab4_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
        return;
      }
    }

    if ((MotorSimlab4_P.HILInitialize_set_encoder_count && !is_switching) ||
        (MotorSimlab4_P.HILInitialize_set_encoder_cou_h && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &MotorSimlab4_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            MotorSimlab4_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(MotorSimlab4_DW.HILInitialize_Card,
        MotorSimlab4_P.HILInitialize_encoder_channels, 8U,
        &MotorSimlab4_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
        return;
      }
    }

    if ((MotorSimlab4_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (MotorSimlab4_P.HILInitialize_set_pwm_params__a && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &MotorSimlab4_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = MotorSimlab4_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(MotorSimlab4_DW.HILInitialize_Card,
        MotorSimlab4_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &MotorSimlab4_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          MotorSimlab4_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &MotorSimlab4_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            MotorSimlab4_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            MotorSimlab4_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              MotorSimlab4_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            MotorSimlab4_DW.HILInitialize_POSortedChans[7U - num_frequency_modes]
              = p_HILInitialize_pwm_channels[i1];
            MotorSimlab4_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes]
              = MotorSimlab4_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(MotorSimlab4_DW.HILInitialize_Card,
          &MotorSimlab4_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &MotorSimlab4_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(MotorSimlab4_DW.HILInitialize_Card,
          &MotorSimlab4_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &MotorSimlab4_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &MotorSimlab4_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = MotorSimlab4_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &MotorSimlab4_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = MotorSimlab4_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &MotorSimlab4_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = MotorSimlab4_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(MotorSimlab4_DW.HILInitialize_Card,
        MotorSimlab4_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &MotorSimlab4_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &MotorSimlab4_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &MotorSimlab4_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &MotorSimlab4_DW.HILInitialize_POSortedFreqs
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = MotorSimlab4_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &MotorSimlab4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = MotorSimlab4_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(MotorSimlab4_DW.HILInitialize_Card,
        MotorSimlab4_P.HILInitialize_pwm_channels, 8U,
        &MotorSimlab4_DW.HILInitialize_POSortedFreqs[0],
        &MotorSimlab4_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
        return;
      }
    }

    if ((MotorSimlab4_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (MotorSimlab4_P.HILInitialize_set_pwm_outputs_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &MotorSimlab4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = MotorSimlab4_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(MotorSimlab4_DW.HILInitialize_Card,
        MotorSimlab4_P.HILInitialize_pwm_channels, 8U,
        &MotorSimlab4_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
        return;
      }
    }

    if (MotorSimlab4_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &MotorSimlab4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = MotorSimlab4_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (MotorSimlab4_DW.HILInitialize_Card,
         MotorSimlab4_P.HILInitialize_pwm_channels, 8U,
         &MotorSimlab4_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_analog_timebase_block): '<Root>/HIL Read Analog Timebase' */

  /* S-Function Block: MotorSimlab4/HIL Read Analog Timebase (hil_read_analog_timebase_block) */
  {
    t_error result;
    result = hil_task_create_analog_reader(MotorSimlab4_DW.HILInitialize_Card,
      MotorSimlab4_P.HILReadAnalogTimebase_samples_i,
      MotorSimlab4_P.HILReadAnalogTimebase_channels, 2,
      &MotorSimlab4_DW.HILReadAnalogTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
    }
  }

  /* Start for ToFile: '<Root>/ThetaFile' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "ThetaSim.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(MotorSimlab4_M, "Error creating .mat file ThetaSim.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"Tdata")) {
      rtmSetErrorStatus(MotorSimlab4_M,
                        "Error writing mat file header to file ThetaSim.mat");
      return;
    }

    MotorSimlab4_DW.ThetaFile_IWORK.Count = 0;
    MotorSimlab4_DW.ThetaFile_IWORK.Decimation = -1;
    MotorSimlab4_DW.ThetaFile_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/VsimFile' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "Vsim.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(MotorSimlab4_M, "Error creating .mat file Vsim.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"Vdata")) {
      rtmSetErrorStatus(MotorSimlab4_M,
                        "Error writing mat file header to file Vsim.mat");
      return;
    }

    MotorSimlab4_DW.VsimFile_IWORK.Count = 0;
    MotorSimlab4_DW.VsimFile_IWORK.Decimation = -1;
    MotorSimlab4_DW.VsimFile_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/WsimFile1' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "Wsim.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(MotorSimlab4_M, "Error creating .mat file Wsim.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"Wdata")) {
      rtmSetErrorStatus(MotorSimlab4_M,
                        "Error writing mat file header to file Wsim.mat");
      return;
    }

    MotorSimlab4_DW.WsimFile1_IWORK.Count = 0;
    MotorSimlab4_DW.WsimFile1_IWORK.Decimation = -1;
    MotorSimlab4_DW.WsimFile1_PWORK.FilePtr = fp;
  }

  /* InitializeConditions for Integrator: '<Root>/Motor' */
  MotorSimlab4_X.Motor_CSTATE = MotorSimlab4_P.Motor_IC;

  /* InitializeConditions for Integrator: '<Root>/Motor2' */
  MotorSimlab4_X.Motor2_CSTATE = MotorSimlab4_P.Motor2_IC;
}

/* Model terminate function */
void MotorSimlab4_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: MotorSimlab4/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(MotorSimlab4_DW.HILInitialize_Card);
    hil_monitor_stop_all(MotorSimlab4_DW.HILInitialize_Card);
    is_switching = false;
    if ((MotorSimlab4_P.HILInitialize_set_analog_out_py && !is_switching) ||
        (MotorSimlab4_P.HILInitialize_set_analog_outp_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &MotorSimlab4_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = MotorSimlab4_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((MotorSimlab4_P.HILInitialize_set_pwm_outputs_k && !is_switching) ||
        (MotorSimlab4_P.HILInitialize_set_pwm_outputs_h && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &MotorSimlab4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = MotorSimlab4_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(MotorSimlab4_DW.HILInitialize_Card
                         , MotorSimlab4_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , MotorSimlab4_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &MotorSimlab4_DW.HILInitialize_AOVoltages[0]
                         , &MotorSimlab4_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(MotorSimlab4_DW.HILInitialize_Card,
            MotorSimlab4_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs, &MotorSimlab4_DW.HILInitialize_AOVoltages
            [0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(MotorSimlab4_DW.HILInitialize_Card,
            MotorSimlab4_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &MotorSimlab4_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(MotorSimlab4_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(MotorSimlab4_DW.HILInitialize_Card);
    hil_monitor_delete_all(MotorSimlab4_DW.HILInitialize_Card);
    hil_close(MotorSimlab4_DW.HILInitialize_Card);
    MotorSimlab4_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<Root>/ThetaFile' */
  {
    FILE *fp = (FILE *) MotorSimlab4_DW.ThetaFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "ThetaSim.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(MotorSimlab4_M, "Error closing MAT-file ThetaSim.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(MotorSimlab4_M,
                          "Error reopening MAT-file ThetaSim.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, MotorSimlab4_DW.ThetaFile_IWORK.Count,
           "Tdata")) {
        rtmSetErrorStatus(MotorSimlab4_M,
                          "Error writing header for Tdata to MAT-file ThetaSim.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(MotorSimlab4_M, "Error closing MAT-file ThetaSim.mat");
        return;
      }

      MotorSimlab4_DW.ThetaFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/VsimFile' */
  {
    FILE *fp = (FILE *) MotorSimlab4_DW.VsimFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "Vsim.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(MotorSimlab4_M, "Error closing MAT-file Vsim.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(MotorSimlab4_M, "Error reopening MAT-file Vsim.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, MotorSimlab4_DW.VsimFile_IWORK.Count,
           "Vdata")) {
        rtmSetErrorStatus(MotorSimlab4_M,
                          "Error writing header for Vdata to MAT-file Vsim.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(MotorSimlab4_M, "Error closing MAT-file Vsim.mat");
        return;
      }

      MotorSimlab4_DW.VsimFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/WsimFile1' */
  {
    FILE *fp = (FILE *) MotorSimlab4_DW.WsimFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "Wsim.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(MotorSimlab4_M, "Error closing MAT-file Wsim.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(MotorSimlab4_M, "Error reopening MAT-file Wsim.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, MotorSimlab4_DW.WsimFile1_IWORK.Count,
           "Wdata")) {
        rtmSetErrorStatus(MotorSimlab4_M,
                          "Error writing header for Wdata to MAT-file Wsim.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(MotorSimlab4_M, "Error closing MAT-file Wsim.mat");
        return;
      }

      MotorSimlab4_DW.WsimFile1_PWORK.FilePtr = (NULL);
    }
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
  MotorSimlab4_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  MotorSimlab4_update();
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
  MotorSimlab4_initialize();
}

void MdlTerminate(void)
{
  MotorSimlab4_terminate();
}

/* Registration function */
RT_MODEL_MotorSimlab4_T *MotorSimlab4(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)MotorSimlab4_M, 0,
                sizeof(RT_MODEL_MotorSimlab4_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&MotorSimlab4_M->solverInfo,
                          &MotorSimlab4_M->Timing.simTimeStep);
    rtsiSetTPtr(&MotorSimlab4_M->solverInfo, &rtmGetTPtr(MotorSimlab4_M));
    rtsiSetStepSizePtr(&MotorSimlab4_M->solverInfo,
                       &MotorSimlab4_M->Timing.stepSize0);
    rtsiSetdXPtr(&MotorSimlab4_M->solverInfo, &MotorSimlab4_M->ModelData.derivs);
    rtsiSetContStatesPtr(&MotorSimlab4_M->solverInfo, (real_T **)
                         &MotorSimlab4_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&MotorSimlab4_M->solverInfo,
      &MotorSimlab4_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&MotorSimlab4_M->solverInfo,
      &MotorSimlab4_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&MotorSimlab4_M->solverInfo,
      &MotorSimlab4_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&MotorSimlab4_M->solverInfo,
      &MotorSimlab4_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&MotorSimlab4_M->solverInfo, (&rtmGetErrorStatus
      (MotorSimlab4_M)));
    rtsiSetRTModelPtr(&MotorSimlab4_M->solverInfo, MotorSimlab4_M);
  }

  rtsiSetSimTimeStep(&MotorSimlab4_M->solverInfo, MAJOR_TIME_STEP);
  MotorSimlab4_M->ModelData.intgData.y = MotorSimlab4_M->ModelData.odeY;
  MotorSimlab4_M->ModelData.intgData.f[0] = MotorSimlab4_M->ModelData.odeF[0];
  MotorSimlab4_M->ModelData.intgData.f[1] = MotorSimlab4_M->ModelData.odeF[1];
  MotorSimlab4_M->ModelData.intgData.f[2] = MotorSimlab4_M->ModelData.odeF[2];
  MotorSimlab4_M->ModelData.intgData.f[3] = MotorSimlab4_M->ModelData.odeF[3];
  MotorSimlab4_M->ModelData.contStates = ((real_T *) &MotorSimlab4_X);
  rtsiSetSolverData(&MotorSimlab4_M->solverInfo, (void *)
                    &MotorSimlab4_M->ModelData.intgData);
  rtsiSetSolverName(&MotorSimlab4_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = MotorSimlab4_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    MotorSimlab4_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    MotorSimlab4_M->Timing.sampleTimes =
      (&MotorSimlab4_M->Timing.sampleTimesArray[0]);
    MotorSimlab4_M->Timing.offsetTimes =
      (&MotorSimlab4_M->Timing.offsetTimesArray[0]);

    /* task periods */
    MotorSimlab4_M->Timing.sampleTimes[0] = (0.0);
    MotorSimlab4_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    MotorSimlab4_M->Timing.offsetTimes[0] = (0.0);
    MotorSimlab4_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(MotorSimlab4_M, &MotorSimlab4_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = MotorSimlab4_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    MotorSimlab4_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(MotorSimlab4_M, 6000.0);
  MotorSimlab4_M->Timing.stepSize0 = 0.001;
  MotorSimlab4_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  MotorSimlab4_M->Sizes.checksums[0] = (3923191368U);
  MotorSimlab4_M->Sizes.checksums[1] = (2303068652U);
  MotorSimlab4_M->Sizes.checksums[2] = (2280971573U);
  MotorSimlab4_M->Sizes.checksums[3] = (922087767U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    MotorSimlab4_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(MotorSimlab4_M->extModeInfo,
      &MotorSimlab4_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(MotorSimlab4_M->extModeInfo,
                        MotorSimlab4_M->Sizes.checksums);
    rteiSetTPtr(MotorSimlab4_M->extModeInfo, rtmGetTPtr(MotorSimlab4_M));
  }

  MotorSimlab4_M->solverInfoPtr = (&MotorSimlab4_M->solverInfo);
  MotorSimlab4_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&MotorSimlab4_M->solverInfo, 0.001);
  rtsiSetSolverMode(&MotorSimlab4_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  MotorSimlab4_M->ModelData.blockIO = ((void *) &MotorSimlab4_B);
  (void) memset(((void *) &MotorSimlab4_B), 0,
                sizeof(B_MotorSimlab4_T));

  /* parameters */
  MotorSimlab4_M->ModelData.defaultParam = ((real_T *)&MotorSimlab4_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &MotorSimlab4_X;
    MotorSimlab4_M->ModelData.contStates = (x);
    (void) memset((void *)&MotorSimlab4_X, 0,
                  sizeof(X_MotorSimlab4_T));
  }

  /* states (dwork) */
  MotorSimlab4_M->ModelData.dwork = ((void *) &MotorSimlab4_DW);
  (void) memset((void *)&MotorSimlab4_DW, 0,
                sizeof(DW_MotorSimlab4_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    MotorSimlab4_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  MotorSimlab4_M->Sizes.numContStates = (2);/* Number of continuous states */
  MotorSimlab4_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  MotorSimlab4_M->Sizes.numY = (0);    /* Number of model outputs */
  MotorSimlab4_M->Sizes.numU = (0);    /* Number of model inputs */
  MotorSimlab4_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  MotorSimlab4_M->Sizes.numSampTimes = (2);/* Number of sample times */
  MotorSimlab4_M->Sizes.numBlocks = (28);/* Number of blocks */
  MotorSimlab4_M->Sizes.numBlockIO = (8);/* Number of block outputs */
  MotorSimlab4_M->Sizes.numBlockPrms = (117);/* Sum of parameter "widths" */
  return MotorSimlab4_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
