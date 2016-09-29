/*
 * MotorSimlab4_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_task),
  sizeof(t_card)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_task",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&MotorSimlab4_B.Bias), 0, 0, 8 }
  ,

  { (char_T *)(&MotorSimlab4_DW.HILInitialize_AIMinimums[0]), 0, 0, 66 },

  { (char_T *)(&MotorSimlab4_DW.HILReadAnalogTimebase_Task), 14, 0, 1 },

  { (char_T *)(&MotorSimlab4_DW.HILInitialize_Card), 15, 0, 1 },

  { (char_T *)(&MotorSimlab4_DW.HILWriteAnalog_PWORK), 11, 0, 13 },

  { (char_T *)(&MotorSimlab4_DW.HILInitialize_ClockModes[0]), 6, 0, 44 },

  { (char_T *)(&MotorSimlab4_DW.HILInitialize_POSortedChans[0]), 7, 0, 8 },

  { (char_T *)(&MotorSimlab4_DW.ThetaFile_IWORK.Count), 10, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&MotorSimlab4_P.Beq), 0, 0, 23 },

  { (char_T *)(&MotorSimlab4_P.HILReadAnalogTimebase_clock), 6, 0, 10 },

  { (char_T *)(&MotorSimlab4_P.HILInitialize_analog_input_chan[0]), 7, 0, 38 },

  { (char_T *)(&MotorSimlab4_P.HILInitialize_active), 8, 0, 35 },

  { (char_T *)(&MotorSimlab4_P.SignalGenerator_Amplitude), 0, 0, 8 },

  { (char_T *)(&MotorSimlab4_P.HILReadAnalogTimebase_Active), 8, 0, 3 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] MotorSimlab4_dt.h */
