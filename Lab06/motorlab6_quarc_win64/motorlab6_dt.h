/*
 * motorlab6_dt.h
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
  { (char_T *)(&motorlab6_B.Tacometer), 0, 0, 17 }
  ,

  { (char_T *)(&motorlab6_DW.UD_DSTATE), 0, 0, 69 },

  { (char_T *)(&motorlab6_DW.HILReadAnalogTimebase_Task), 14, 0, 1 },

  { (char_T *)(&motorlab6_DW.HILInitialize_Card), 15, 0, 1 },

  { (char_T *)(&motorlab6_DW.HILWriteAnalog_PWORK), 11, 0, 11 },

  { (char_T *)(&motorlab6_DW.HILInitialize_ClockModes[0]), 6, 0, 44 },

  { (char_T *)(&motorlab6_DW.HILInitialize_POSortedChans[0]), 7, 0, 8 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&motorlab6_P.Kg), 0, 0, 20 },

  { (char_T *)(&motorlab6_P.HILReadAnalogTimebase_clock), 6, 0, 10 },

  { (char_T *)(&motorlab6_P.HILInitialize_analog_input_chan[0]), 7, 0, 38 },

  { (char_T *)(&motorlab6_P.HILInitialize_active), 8, 0, 35 },

  { (char_T *)(&motorlab6_P.TransferFcn4_A), 0, 0, 28 },

  { (char_T *)(&motorlab6_P.ManualSwitch1_CurrentSetting), 3, 0, 2 },

  { (char_T *)(&motorlab6_P.HILReadAnalogTimebase_Active), 8, 0, 3 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] motorlab6_dt.h */
