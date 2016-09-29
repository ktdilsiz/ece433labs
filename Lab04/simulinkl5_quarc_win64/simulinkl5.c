/*
 * simulinkl5.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "simulinkl5".
 *
 * Model version              : 1.1
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Thu Sep 29 14:39:45 2016
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "simulinkl5.h"
#include "simulinkl5_private.h"
#include "simulinkl5_dt.h"

/* Block signals (auto storage) */
B_simulinkl5_T simulinkl5_B;

/* Continuous states */
X_simulinkl5_T simulinkl5_X;

/* Block states (auto storage) */
DW_simulinkl5_T simulinkl5_DW;

/* Real-time model */
RT_MODEL_simulinkl5_T simulinkl5_M_;
RT_MODEL_simulinkl5_T *const simulinkl5_M = &simulinkl5_M_;

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
  simulinkl5_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  simulinkl5_output();
  simulinkl5_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  simulinkl5_output();
  simulinkl5_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  simulinkl5_output();
  simulinkl5_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void simulinkl5_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalogTimebase_o1;
  real_T rtb_TmpSignalConversionAtThetaF[3];
  real_T rtb_HILReadEncoder;
  real_T temp;
  if (rtmIsMajorTimeStep(simulinkl5_M)) {
    /* set solver stop time */
    if (!(simulinkl5_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&simulinkl5_M->solverInfo,
                            ((simulinkl5_M->Timing.clockTickH0 + 1) *
        simulinkl5_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&simulinkl5_M->solverInfo,
                            ((simulinkl5_M->Timing.clockTick0 + 1) *
        simulinkl5_M->Timing.stepSize0 + simulinkl5_M->Timing.clockTickH0 *
        simulinkl5_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(simulinkl5_M)) {
    simulinkl5_M->Timing.t[0] = rtsiGetT(&simulinkl5_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(simulinkl5_M)) {
    /* S-Function (hil_read_analog_timebase_block): '<Root>/HIL Read Analog Timebase' */

    /* S-Function Block: simulinkl5/HIL Read Analog Timebase (hil_read_analog_timebase_block) */
    {
      t_error result;
      result = hil_task_read_analog(simulinkl5_DW.HILReadAnalogTimebase_Task, 1,
        &simulinkl5_DW.HILReadAnalogTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
      }

      rtb_HILReadAnalogTimebase_o1 = simulinkl5_DW.HILReadAnalogTimebase_Buffer
        [0];
      rtb_HILReadEncoder = simulinkl5_DW.HILReadAnalogTimebase_Buffer[1];
    }
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  temp = simulinkl5_P.SignalGenerator_Frequency * simulinkl5_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    temp = simulinkl5_P.SignalGenerator_Amplitude;
  } else {
    temp = -simulinkl5_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Bias: '<Root>/Bias' */
  simulinkl5_B.Bias = temp + simulinkl5_P.Bias_Bias;

  /* Gain: '<Root>/Gain1' */
  simulinkl5_B.Gain1 = simulinkl5_P.Gain1_Gain * simulinkl5_B.Bias;
  if (rtmIsMajorTimeStep(simulinkl5_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: simulinkl5/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(simulinkl5_DW.HILInitialize_Card,
        &simulinkl5_P.HILWriteAnalog_channels, 1, &simulinkl5_B.Gain1);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
      }
    }
  }

  /* Integrator: '<Root>/Motor' */
  simulinkl5_B.Motor = simulinkl5_X.Motor_CSTATE;
  if (rtmIsMajorTimeStep(simulinkl5_M)) {
    /* ToFile: '<Root>/ThetaFile' */
    {
      if (!(++simulinkl5_DW.ThetaFile_IWORK.Decimation % 1) &&
          (simulinkl5_DW.ThetaFile_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) simulinkl5_DW.ThetaFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          simulinkl5_DW.ThetaFile_IWORK.Decimation = 0;
          u[0] = simulinkl5_M->Timing.t[1];
          u[1] = simulinkl5_B.Motor;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(simulinkl5_M,
                              "Error writing to MAT-file ThetaSim.mat");
            return;
          }

          if (((++simulinkl5_DW.ThetaFile_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file ThetaSim.mat.\n");
          }
        }
      }
    }
  }

  /* Integrator: '<Root>/Motor2' */
  simulinkl5_B.Motor2 = simulinkl5_X.Motor2_CSTATE;
  if (rtmIsMajorTimeStep(simulinkl5_M)) {
    /* SignalConversion: '<Root>/TmpSignal ConversionAtThetaFile1Inport1' */
    rtb_TmpSignalConversionAtThetaF[0] = simulinkl5_B.Bias;
    rtb_TmpSignalConversionAtThetaF[1] = simulinkl5_B.Motor2;
    rtb_TmpSignalConversionAtThetaF[2] = simulinkl5_B.Motor;

    /* ToFile: '<Root>/ThetaFile1' */
    {
      if (!(++simulinkl5_DW.ThetaFile1_IWORK.Decimation % 1) &&
          (simulinkl5_DW.ThetaFile1_IWORK.Count*4)+1 < 100000000 ) {
        FILE *fp = (FILE *) simulinkl5_DW.ThetaFile1_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[4];
          simulinkl5_DW.ThetaFile1_IWORK.Decimation = 0;
          u[0] = simulinkl5_M->Timing.t[1];
          u[1] = rtb_TmpSignalConversionAtThetaF[0];
          u[2] = rtb_TmpSignalConversionAtThetaF[1];
          u[3] = rtb_TmpSignalConversionAtThetaF[2];
          if (fwrite(u, sizeof(real_T), 4, fp) != 4) {
            rtmSetErrorStatus(simulinkl5_M,
                              "Error writing to MAT-file DataSim.mat");
            return;
          }

          if (((++simulinkl5_DW.ThetaFile1_IWORK.Count)*4)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file DataSim.mat.\n");
          }
        }
      }
    }

    /* ToFile: '<Root>/VsimFile' */
    {
      if (!(++simulinkl5_DW.VsimFile_IWORK.Decimation % 1) &&
          (simulinkl5_DW.VsimFile_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) simulinkl5_DW.VsimFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          simulinkl5_DW.VsimFile_IWORK.Decimation = 0;
          u[0] = simulinkl5_M->Timing.t[1];
          u[1] = simulinkl5_B.Bias;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(simulinkl5_M, "Error writing to MAT-file Vsim.mat");
            return;
          }

          if (((++simulinkl5_DW.VsimFile_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file Vsim.mat.\n");
          }
        }
      }
    }

    /* Gain: '<Root>/Tacometer' */
    simulinkl5_B.Tacometer = -69.813170079773172 / simulinkl5_P.Kg *
      rtb_HILReadEncoder;

    /* ToFile: '<Root>/WsimFile1' */
    {
      if (!(++simulinkl5_DW.WsimFile1_IWORK.Decimation % 1) &&
          (simulinkl5_DW.WsimFile1_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) simulinkl5_DW.WsimFile1_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          simulinkl5_DW.WsimFile1_IWORK.Decimation = 0;
          u[0] = simulinkl5_M->Timing.t[1];
          u[1] = simulinkl5_B.Motor2;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(simulinkl5_M, "Error writing to MAT-file Wsim.mat");
            return;
          }

          if (((++simulinkl5_DW.WsimFile1_IWORK.Count)*2)+1 >= 100000000) {
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
    simulinkl5_B.Potentiometer = simulinkl5_P.Potentiometer_Gain *
      rtb_HILReadAnalogTimebase_o1;

    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: simulinkl5/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(simulinkl5_DW.HILInitialize_Card,
        &simulinkl5_P.HILReadEncoder_channels, 1,
        &simulinkl5_DW.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder = simulinkl5_DW.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<Root>/Encoder' */
    simulinkl5_B.Encoder = simulinkl5_P.Encoder_Gain * rtb_HILReadEncoder;
  }

  /* Sum: '<Root>/Add2' incorporates:
   *  Gain: '<Root>/Gain3'
   *  Gain: '<Root>/Gain4'
   */
  simulinkl5_B.Add2 = simulinkl5_P.Ka / simulinkl5_P.Rm * simulinkl5_B.Bias -
    (simulinkl5_P.Ka * simulinkl5_P.Kb / simulinkl5_P.Rm + simulinkl5_P.Beq /
     simulinkl5_P.Jeq) * simulinkl5_B.Motor2;
}

/* Model update function */
void simulinkl5_update(void)
{
  if (rtmIsMajorTimeStep(simulinkl5_M)) {
    rt_ertODEUpdateContinuousStates(&simulinkl5_M->solverInfo);
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
  if (!(++simulinkl5_M->Timing.clockTick0)) {
    ++simulinkl5_M->Timing.clockTickH0;
  }

  simulinkl5_M->Timing.t[0] = rtsiGetSolverStopTime(&simulinkl5_M->solverInfo);

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
    if (!(++simulinkl5_M->Timing.clockTick1)) {
      ++simulinkl5_M->Timing.clockTickH1;
    }

    simulinkl5_M->Timing.t[1] = simulinkl5_M->Timing.clockTick1 *
      simulinkl5_M->Timing.stepSize1 + simulinkl5_M->Timing.clockTickH1 *
      simulinkl5_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void simulinkl5_derivatives(void)
{
  XDot_simulinkl5_T *_rtXdot;
  _rtXdot = ((XDot_simulinkl5_T *) simulinkl5_M->ModelData.derivs);

  /* Derivatives for Integrator: '<Root>/Motor' */
  _rtXdot->Motor_CSTATE = simulinkl5_B.Motor2;

  /* Derivatives for Integrator: '<Root>/Motor2' */
  _rtXdot->Motor2_CSTATE = simulinkl5_B.Add2;
}

/* Model initialize function */
void simulinkl5_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: simulinkl5/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &simulinkl5_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(simulinkl5_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(simulinkl5_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
      return;
    }

    if ((simulinkl5_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (simulinkl5_P.HILInitialize_set_analog_inpu_h && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &simulinkl5_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = simulinkl5_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &simulinkl5_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = simulinkl5_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(simulinkl5_DW.HILInitialize_Card,
        simulinkl5_P.HILInitialize_analog_input_chan, 8U,
        &simulinkl5_DW.HILInitialize_AIMinimums[0],
        &simulinkl5_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
        return;
      }
    }

    if ((simulinkl5_P.HILInitialize_set_analog_output && !is_switching) ||
        (simulinkl5_P.HILInitialize_set_analog_outp_o && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &simulinkl5_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = simulinkl5_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &simulinkl5_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = simulinkl5_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(simulinkl5_DW.HILInitialize_Card,
        simulinkl5_P.HILInitialize_analog_output_cha, 8U,
        &simulinkl5_DW.HILInitialize_AOMinimums[0],
        &simulinkl5_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
        return;
      }
    }

    if ((simulinkl5_P.HILInitialize_set_analog_outp_d && !is_switching) ||
        (simulinkl5_P.HILInitialize_set_analog_outp_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &simulinkl5_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = simulinkl5_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(simulinkl5_DW.HILInitialize_Card,
        simulinkl5_P.HILInitialize_analog_output_cha, 8U,
        &simulinkl5_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
        return;
      }
    }

    if (simulinkl5_P.HILInitialize_set_analog_out_ob) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &simulinkl5_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = simulinkl5_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (simulinkl5_DW.HILInitialize_Card,
         simulinkl5_P.HILInitialize_analog_output_cha, 8U,
         &simulinkl5_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
        return;
      }
    }

    if ((simulinkl5_P.HILInitialize_set_encoder_param && !is_switching) ||
        (simulinkl5_P.HILInitialize_set_encoder_par_p && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &simulinkl5_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = simulinkl5_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(simulinkl5_DW.HILInitialize_Card,
        simulinkl5_P.HILInitialize_encoder_channels, 8U,
        (t_encoder_quadrature_mode *)
        &simulinkl5_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
        return;
      }
    }

    if ((simulinkl5_P.HILInitialize_set_encoder_count && !is_switching) ||
        (simulinkl5_P.HILInitialize_set_encoder_cou_h && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &simulinkl5_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = simulinkl5_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(simulinkl5_DW.HILInitialize_Card,
        simulinkl5_P.HILInitialize_encoder_channels, 8U,
        &simulinkl5_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
        return;
      }
    }

    if ((simulinkl5_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (simulinkl5_P.HILInitialize_set_pwm_params__g && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &simulinkl5_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = simulinkl5_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(simulinkl5_DW.HILInitialize_Card,
        simulinkl5_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &simulinkl5_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          simulinkl5_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &simulinkl5_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            simulinkl5_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            simulinkl5_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              simulinkl5_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            simulinkl5_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              p_HILInitialize_pwm_channels[i1];
            simulinkl5_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              simulinkl5_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(simulinkl5_DW.HILInitialize_Card,
          &simulinkl5_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &simulinkl5_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(simulinkl5_DW.HILInitialize_Card,
          &simulinkl5_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &simulinkl5_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &simulinkl5_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = simulinkl5_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &simulinkl5_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = simulinkl5_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &simulinkl5_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = simulinkl5_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(simulinkl5_DW.HILInitialize_Card,
        simulinkl5_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &simulinkl5_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &simulinkl5_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &simulinkl5_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &simulinkl5_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = simulinkl5_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &simulinkl5_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = simulinkl5_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(simulinkl5_DW.HILInitialize_Card,
        simulinkl5_P.HILInitialize_pwm_channels, 8U,
        &simulinkl5_DW.HILInitialize_POSortedFreqs[0],
        &simulinkl5_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
        return;
      }
    }

    if ((simulinkl5_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (simulinkl5_P.HILInitialize_set_pwm_outputs_i && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &simulinkl5_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = simulinkl5_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(simulinkl5_DW.HILInitialize_Card,
        simulinkl5_P.HILInitialize_pwm_channels, 8U,
        &simulinkl5_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
        return;
      }
    }

    if (simulinkl5_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &simulinkl5_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = simulinkl5_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (simulinkl5_DW.HILInitialize_Card,
         simulinkl5_P.HILInitialize_pwm_channels, 8U,
         &simulinkl5_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_analog_timebase_block): '<Root>/HIL Read Analog Timebase' */

  /* S-Function Block: simulinkl5/HIL Read Analog Timebase (hil_read_analog_timebase_block) */
  {
    t_error result;
    result = hil_task_create_analog_reader(simulinkl5_DW.HILInitialize_Card,
      simulinkl5_P.HILReadAnalogTimebase_samples_i,
      simulinkl5_P.HILReadAnalogTimebase_channels, 2,
      &simulinkl5_DW.HILReadAnalogTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
    }
  }

  /* Start for ToFile: '<Root>/ThetaFile' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "ThetaSim.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(simulinkl5_M, "Error creating .mat file ThetaSim.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"Tdata")) {
      rtmSetErrorStatus(simulinkl5_M,
                        "Error writing mat file header to file ThetaSim.mat");
      return;
    }

    simulinkl5_DW.ThetaFile_IWORK.Count = 0;
    simulinkl5_DW.ThetaFile_IWORK.Decimation = -1;
    simulinkl5_DW.ThetaFile_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/ThetaFile1' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "DataSim.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(simulinkl5_M, "Error creating .mat file DataSim.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,4,0,"data")) {
      rtmSetErrorStatus(simulinkl5_M,
                        "Error writing mat file header to file DataSim.mat");
      return;
    }

    simulinkl5_DW.ThetaFile1_IWORK.Count = 0;
    simulinkl5_DW.ThetaFile1_IWORK.Decimation = -1;
    simulinkl5_DW.ThetaFile1_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/VsimFile' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "Vsim.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(simulinkl5_M, "Error creating .mat file Vsim.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"Vdata")) {
      rtmSetErrorStatus(simulinkl5_M,
                        "Error writing mat file header to file Vsim.mat");
      return;
    }

    simulinkl5_DW.VsimFile_IWORK.Count = 0;
    simulinkl5_DW.VsimFile_IWORK.Decimation = -1;
    simulinkl5_DW.VsimFile_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/WsimFile1' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "Wsim.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(simulinkl5_M, "Error creating .mat file Wsim.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"Wdata")) {
      rtmSetErrorStatus(simulinkl5_M,
                        "Error writing mat file header to file Wsim.mat");
      return;
    }

    simulinkl5_DW.WsimFile1_IWORK.Count = 0;
    simulinkl5_DW.WsimFile1_IWORK.Decimation = -1;
    simulinkl5_DW.WsimFile1_PWORK.FilePtr = fp;
  }

  /* InitializeConditions for Integrator: '<Root>/Motor' */
  simulinkl5_X.Motor_CSTATE = simulinkl5_P.Motor_IC;

  /* InitializeConditions for Integrator: '<Root>/Motor2' */
  simulinkl5_X.Motor2_CSTATE = simulinkl5_P.Motor2_IC;
}

/* Model terminate function */
void simulinkl5_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: simulinkl5/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(simulinkl5_DW.HILInitialize_Card);
    hil_monitor_stop_all(simulinkl5_DW.HILInitialize_Card);
    is_switching = false;
    if ((simulinkl5_P.HILInitialize_set_analog_out_da && !is_switching) ||
        (simulinkl5_P.HILInitialize_set_analog_outp_i && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &simulinkl5_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = simulinkl5_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((simulinkl5_P.HILInitialize_set_pwm_outputs_p && !is_switching) ||
        (simulinkl5_P.HILInitialize_set_pwm_outputs_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &simulinkl5_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = simulinkl5_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(simulinkl5_DW.HILInitialize_Card
                         , simulinkl5_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , simulinkl5_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &simulinkl5_DW.HILInitialize_AOVoltages[0]
                         , &simulinkl5_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(simulinkl5_DW.HILInitialize_Card,
            simulinkl5_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs, &simulinkl5_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(simulinkl5_DW.HILInitialize_Card,
            simulinkl5_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &simulinkl5_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(simulinkl5_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(simulinkl5_DW.HILInitialize_Card);
    hil_monitor_delete_all(simulinkl5_DW.HILInitialize_Card);
    hil_close(simulinkl5_DW.HILInitialize_Card);
    simulinkl5_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<Root>/ThetaFile' */
  {
    FILE *fp = (FILE *) simulinkl5_DW.ThetaFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "ThetaSim.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(simulinkl5_M, "Error closing MAT-file ThetaSim.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(simulinkl5_M, "Error reopening MAT-file ThetaSim.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, simulinkl5_DW.ThetaFile_IWORK.Count,
           "Tdata")) {
        rtmSetErrorStatus(simulinkl5_M,
                          "Error writing header for Tdata to MAT-file ThetaSim.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(simulinkl5_M, "Error closing MAT-file ThetaSim.mat");
        return;
      }

      simulinkl5_DW.ThetaFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/ThetaFile1' */
  {
    FILE *fp = (FILE *) simulinkl5_DW.ThetaFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "DataSim.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(simulinkl5_M, "Error closing MAT-file DataSim.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(simulinkl5_M, "Error reopening MAT-file DataSim.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 4, simulinkl5_DW.ThetaFile1_IWORK.Count,
           "data")) {
        rtmSetErrorStatus(simulinkl5_M,
                          "Error writing header for data to MAT-file DataSim.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(simulinkl5_M, "Error closing MAT-file DataSim.mat");
        return;
      }

      simulinkl5_DW.ThetaFile1_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/VsimFile' */
  {
    FILE *fp = (FILE *) simulinkl5_DW.VsimFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "Vsim.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(simulinkl5_M, "Error closing MAT-file Vsim.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(simulinkl5_M, "Error reopening MAT-file Vsim.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, simulinkl5_DW.VsimFile_IWORK.Count,
           "Vdata")) {
        rtmSetErrorStatus(simulinkl5_M,
                          "Error writing header for Vdata to MAT-file Vsim.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(simulinkl5_M, "Error closing MAT-file Vsim.mat");
        return;
      }

      simulinkl5_DW.VsimFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/WsimFile1' */
  {
    FILE *fp = (FILE *) simulinkl5_DW.WsimFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "Wsim.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(simulinkl5_M, "Error closing MAT-file Wsim.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(simulinkl5_M, "Error reopening MAT-file Wsim.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, simulinkl5_DW.WsimFile1_IWORK.Count,
           "Wdata")) {
        rtmSetErrorStatus(simulinkl5_M,
                          "Error writing header for Wdata to MAT-file Wsim.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(simulinkl5_M, "Error closing MAT-file Wsim.mat");
        return;
      }

      simulinkl5_DW.WsimFile1_PWORK.FilePtr = (NULL);
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
  simulinkl5_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  simulinkl5_update();
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
  simulinkl5_initialize();
}

void MdlTerminate(void)
{
  simulinkl5_terminate();
}

/* Registration function */
RT_MODEL_simulinkl5_T *simulinkl5(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)simulinkl5_M, 0,
                sizeof(RT_MODEL_simulinkl5_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&simulinkl5_M->solverInfo,
                          &simulinkl5_M->Timing.simTimeStep);
    rtsiSetTPtr(&simulinkl5_M->solverInfo, &rtmGetTPtr(simulinkl5_M));
    rtsiSetStepSizePtr(&simulinkl5_M->solverInfo,
                       &simulinkl5_M->Timing.stepSize0);
    rtsiSetdXPtr(&simulinkl5_M->solverInfo, &simulinkl5_M->ModelData.derivs);
    rtsiSetContStatesPtr(&simulinkl5_M->solverInfo, (real_T **)
                         &simulinkl5_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&simulinkl5_M->solverInfo,
      &simulinkl5_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&simulinkl5_M->solverInfo,
      &simulinkl5_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&simulinkl5_M->solverInfo,
      &simulinkl5_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&simulinkl5_M->solverInfo,
      &simulinkl5_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&simulinkl5_M->solverInfo, (&rtmGetErrorStatus
      (simulinkl5_M)));
    rtsiSetRTModelPtr(&simulinkl5_M->solverInfo, simulinkl5_M);
  }

  rtsiSetSimTimeStep(&simulinkl5_M->solverInfo, MAJOR_TIME_STEP);
  simulinkl5_M->ModelData.intgData.y = simulinkl5_M->ModelData.odeY;
  simulinkl5_M->ModelData.intgData.f[0] = simulinkl5_M->ModelData.odeF[0];
  simulinkl5_M->ModelData.intgData.f[1] = simulinkl5_M->ModelData.odeF[1];
  simulinkl5_M->ModelData.intgData.f[2] = simulinkl5_M->ModelData.odeF[2];
  simulinkl5_M->ModelData.intgData.f[3] = simulinkl5_M->ModelData.odeF[3];
  simulinkl5_M->ModelData.contStates = ((real_T *) &simulinkl5_X);
  rtsiSetSolverData(&simulinkl5_M->solverInfo, (void *)
                    &simulinkl5_M->ModelData.intgData);
  rtsiSetSolverName(&simulinkl5_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = simulinkl5_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    simulinkl5_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    simulinkl5_M->Timing.sampleTimes = (&simulinkl5_M->Timing.sampleTimesArray[0]);
    simulinkl5_M->Timing.offsetTimes = (&simulinkl5_M->Timing.offsetTimesArray[0]);

    /* task periods */
    simulinkl5_M->Timing.sampleTimes[0] = (0.0);
    simulinkl5_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    simulinkl5_M->Timing.offsetTimes[0] = (0.0);
    simulinkl5_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(simulinkl5_M, &simulinkl5_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = simulinkl5_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    simulinkl5_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(simulinkl5_M, 10.0);
  simulinkl5_M->Timing.stepSize0 = 0.001;
  simulinkl5_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  simulinkl5_M->Sizes.checksums[0] = (248499780U);
  simulinkl5_M->Sizes.checksums[1] = (576780723U);
  simulinkl5_M->Sizes.checksums[2] = (3777780011U);
  simulinkl5_M->Sizes.checksums[3] = (3839900616U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    simulinkl5_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(simulinkl5_M->extModeInfo,
      &simulinkl5_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(simulinkl5_M->extModeInfo, simulinkl5_M->Sizes.checksums);
    rteiSetTPtr(simulinkl5_M->extModeInfo, rtmGetTPtr(simulinkl5_M));
  }

  simulinkl5_M->solverInfoPtr = (&simulinkl5_M->solverInfo);
  simulinkl5_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&simulinkl5_M->solverInfo, 0.001);
  rtsiSetSolverMode(&simulinkl5_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  simulinkl5_M->ModelData.blockIO = ((void *) &simulinkl5_B);
  (void) memset(((void *) &simulinkl5_B), 0,
                sizeof(B_simulinkl5_T));

  /* parameters */
  simulinkl5_M->ModelData.defaultParam = ((real_T *)&simulinkl5_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &simulinkl5_X;
    simulinkl5_M->ModelData.contStates = (x);
    (void) memset((void *)&simulinkl5_X, 0,
                  sizeof(X_simulinkl5_T));
  }

  /* states (dwork) */
  simulinkl5_M->ModelData.dwork = ((void *) &simulinkl5_DW);
  (void) memset((void *)&simulinkl5_DW, 0,
                sizeof(DW_simulinkl5_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    simulinkl5_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  simulinkl5_M->Sizes.numContStates = (2);/* Number of continuous states */
  simulinkl5_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  simulinkl5_M->Sizes.numY = (0);      /* Number of model outputs */
  simulinkl5_M->Sizes.numU = (0);      /* Number of model inputs */
  simulinkl5_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  simulinkl5_M->Sizes.numSampTimes = (2);/* Number of sample times */
  simulinkl5_M->Sizes.numBlocks = (30);/* Number of blocks */
  simulinkl5_M->Sizes.numBlockIO = (8);/* Number of block outputs */
  simulinkl5_M->Sizes.numBlockPrms = (117);/* Sum of parameter "widths" */
  return simulinkl5_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
