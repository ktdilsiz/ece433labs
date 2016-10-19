  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (motorlab6_P)
    ;%
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% motorlab6_P.Kg
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% motorlab6_P.Kp
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% motorlab6_P.DiscreteDerivative_ICPrevScaled
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% motorlab6_P.HILInitialize_analog_input_maxi
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% motorlab6_P.HILInitialize_analog_input_mini
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% motorlab6_P.HILInitialize_analog_output_max
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% motorlab6_P.HILInitialize_analog_output_min
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% motorlab6_P.HILInitialize_final_analog_outp
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% motorlab6_P.HILInitialize_final_pwm_outputs
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% motorlab6_P.HILInitialize_initial_analog_ou
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% motorlab6_P.HILInitialize_initial_pwm_outpu
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% motorlab6_P.HILInitialize_pwm_frequency
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% motorlab6_P.HILInitialize_pwm_leading_deadb
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% motorlab6_P.HILInitialize_pwm_trailing_dead
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% motorlab6_P.HILInitialize_set_other_outputs
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% motorlab6_P.HILInitialize_set_other_outpu_a
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% motorlab6_P.HILInitialize_set_other_outpu_c
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% motorlab6_P.HILInitialize_set_other_outpu_l
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% motorlab6_P.HILInitialize_watchdog_analog_o
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% motorlab6_P.HILInitialize_watchdog_pwm_outp
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% motorlab6_P.HILReadAnalogTimebase_clock
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% motorlab6_P.HILInitialize_hardware_clocks
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% motorlab6_P.HILInitialize_initial_encoder_c
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 4;
	
	  ;% motorlab6_P.HILInitialize_pwm_alignment
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 5;
	
	  ;% motorlab6_P.HILInitialize_pwm_configuration
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 6;
	
	  ;% motorlab6_P.HILInitialize_pwm_modes
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 7;
	
	  ;% motorlab6_P.HILInitialize_pwm_polarity
	  section.data(7).logicalSrcIdx = 26;
	  section.data(7).dtTransOffset = 8;
	
	  ;% motorlab6_P.HILInitialize_watchdog_digital_
	  section.data(8).logicalSrcIdx = 27;
	  section.data(8).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% motorlab6_P.HILInitialize_analog_input_chan
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% motorlab6_P.HILInitialize_analog_output_cha
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 8;
	
	  ;% motorlab6_P.HILReadAnalogTimebase_channels
	  section.data(3).logicalSrcIdx = 30;
	  section.data(3).dtTransOffset = 16;
	
	  ;% motorlab6_P.HILWriteAnalog_channels
	  section.data(4).logicalSrcIdx = 31;
	  section.data(4).dtTransOffset = 18;
	
	  ;% motorlab6_P.HILReadEncoder_channels
	  section.data(5).logicalSrcIdx = 32;
	  section.data(5).dtTransOffset = 19;
	
	  ;% motorlab6_P.HILInitialize_encoder_channels
	  section.data(6).logicalSrcIdx = 33;
	  section.data(6).dtTransOffset = 20;
	
	  ;% motorlab6_P.HILInitialize_pwm_channels
	  section.data(7).logicalSrcIdx = 34;
	  section.data(7).dtTransOffset = 28;
	
	  ;% motorlab6_P.HILInitialize_quadrature
	  section.data(8).logicalSrcIdx = 35;
	  section.data(8).dtTransOffset = 36;
	
	  ;% motorlab6_P.HILReadAnalogTimebase_samples_i
	  section.data(9).logicalSrcIdx = 36;
	  section.data(9).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% motorlab6_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% motorlab6_P.HILInitialize_final_digital_out
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 1;
	
	  ;% motorlab6_P.HILInitialize_initial_digital_o
	  section.data(3).logicalSrcIdx = 39;
	  section.data(3).dtTransOffset = 2;
	
	  ;% motorlab6_P.HILInitialize_set_analog_input_
	  section.data(4).logicalSrcIdx = 40;
	  section.data(4).dtTransOffset = 3;
	
	  ;% motorlab6_P.HILInitialize_set_analog_inpu_j
	  section.data(5).logicalSrcIdx = 41;
	  section.data(5).dtTransOffset = 4;
	
	  ;% motorlab6_P.HILInitialize_set_analog_output
	  section.data(6).logicalSrcIdx = 42;
	  section.data(6).dtTransOffset = 5;
	
	  ;% motorlab6_P.HILInitialize_set_analog_outp_j
	  section.data(7).logicalSrcIdx = 43;
	  section.data(7).dtTransOffset = 6;
	
	  ;% motorlab6_P.HILInitialize_set_analog_outp_c
	  section.data(8).logicalSrcIdx = 44;
	  section.data(8).dtTransOffset = 7;
	
	  ;% motorlab6_P.HILInitialize_set_analog_outp_b
	  section.data(9).logicalSrcIdx = 45;
	  section.data(9).dtTransOffset = 8;
	
	  ;% motorlab6_P.HILInitialize_set_analog_outp_p
	  section.data(10).logicalSrcIdx = 46;
	  section.data(10).dtTransOffset = 9;
	
	  ;% motorlab6_P.HILInitialize_set_analog_out_py
	  section.data(11).logicalSrcIdx = 47;
	  section.data(11).dtTransOffset = 10;
	
	  ;% motorlab6_P.HILInitialize_set_analog_outp_i
	  section.data(12).logicalSrcIdx = 48;
	  section.data(12).dtTransOffset = 11;
	
	  ;% motorlab6_P.HILInitialize_set_clock_frequen
	  section.data(13).logicalSrcIdx = 49;
	  section.data(13).dtTransOffset = 12;
	
	  ;% motorlab6_P.HILInitialize_set_clock_frequ_b
	  section.data(14).logicalSrcIdx = 50;
	  section.data(14).dtTransOffset = 13;
	
	  ;% motorlab6_P.HILInitialize_set_clock_params_
	  section.data(15).logicalSrcIdx = 51;
	  section.data(15).dtTransOffset = 14;
	
	  ;% motorlab6_P.HILInitialize_set_clock_param_h
	  section.data(16).logicalSrcIdx = 52;
	  section.data(16).dtTransOffset = 15;
	
	  ;% motorlab6_P.HILInitialize_set_digital_outpu
	  section.data(17).logicalSrcIdx = 53;
	  section.data(17).dtTransOffset = 16;
	
	  ;% motorlab6_P.HILInitialize_set_digital_out_i
	  section.data(18).logicalSrcIdx = 54;
	  section.data(18).dtTransOffset = 17;
	
	  ;% motorlab6_P.HILInitialize_set_digital_out_j
	  section.data(19).logicalSrcIdx = 55;
	  section.data(19).dtTransOffset = 18;
	
	  ;% motorlab6_P.HILInitialize_set_digital_out_e
	  section.data(20).logicalSrcIdx = 56;
	  section.data(20).dtTransOffset = 19;
	
	  ;% motorlab6_P.HILInitialize_set_digital_ou_il
	  section.data(21).logicalSrcIdx = 57;
	  section.data(21).dtTransOffset = 20;
	
	  ;% motorlab6_P.HILInitialize_set_digital_out_p
	  section.data(22).logicalSrcIdx = 58;
	  section.data(22).dtTransOffset = 21;
	
	  ;% motorlab6_P.HILInitialize_set_digital_out_a
	  section.data(23).logicalSrcIdx = 59;
	  section.data(23).dtTransOffset = 22;
	
	  ;% motorlab6_P.HILInitialize_set_encoder_count
	  section.data(24).logicalSrcIdx = 60;
	  section.data(24).dtTransOffset = 23;
	
	  ;% motorlab6_P.HILInitialize_set_encoder_cou_h
	  section.data(25).logicalSrcIdx = 61;
	  section.data(25).dtTransOffset = 24;
	
	  ;% motorlab6_P.HILInitialize_set_encoder_param
	  section.data(26).logicalSrcIdx = 62;
	  section.data(26).dtTransOffset = 25;
	
	  ;% motorlab6_P.HILInitialize_set_encoder_par_m
	  section.data(27).logicalSrcIdx = 63;
	  section.data(27).dtTransOffset = 26;
	
	  ;% motorlab6_P.HILInitialize_set_other_outpu_i
	  section.data(28).logicalSrcIdx = 64;
	  section.data(28).dtTransOffset = 27;
	
	  ;% motorlab6_P.HILInitialize_set_pwm_outputs_a
	  section.data(29).logicalSrcIdx = 65;
	  section.data(29).dtTransOffset = 28;
	
	  ;% motorlab6_P.HILInitialize_set_pwm_outputs_m
	  section.data(30).logicalSrcIdx = 66;
	  section.data(30).dtTransOffset = 29;
	
	  ;% motorlab6_P.HILInitialize_set_pwm_outputs_h
	  section.data(31).logicalSrcIdx = 67;
	  section.data(31).dtTransOffset = 30;
	
	  ;% motorlab6_P.HILInitialize_set_pwm_outputs_k
	  section.data(32).logicalSrcIdx = 68;
	  section.data(32).dtTransOffset = 31;
	
	  ;% motorlab6_P.HILInitialize_set_pwm_outputs_o
	  section.data(33).logicalSrcIdx = 69;
	  section.data(33).dtTransOffset = 32;
	
	  ;% motorlab6_P.HILInitialize_set_pwm_params_at
	  section.data(34).logicalSrcIdx = 70;
	  section.data(34).dtTransOffset = 33;
	
	  ;% motorlab6_P.HILInitialize_set_pwm_params__a
	  section.data(35).logicalSrcIdx = 71;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 26;
      section.data(26)  = dumData; %prealloc
      
	  ;% motorlab6_P.TransferFcn4_A
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
	  ;% motorlab6_P.TransferFcn4_C
	  section.data(2).logicalSrcIdx = 73;
	  section.data(2).dtTransOffset = 1;
	
	  ;% motorlab6_P.Saturation2_UpperSat
	  section.data(3).logicalSrcIdx = 74;
	  section.data(3).dtTransOffset = 2;
	
	  ;% motorlab6_P.Saturation2_LowerSat
	  section.data(4).logicalSrcIdx = 75;
	  section.data(4).dtTransOffset = 3;
	
	  ;% motorlab6_P.Gain1_Gain
	  section.data(5).logicalSrcIdx = 76;
	  section.data(5).dtTransOffset = 4;
	
	  ;% motorlab6_P.Encoder_Gain
	  section.data(6).logicalSrcIdx = 77;
	  section.data(6).dtTransOffset = 5;
	
	  ;% motorlab6_P.TSamp_WtEt
	  section.data(7).logicalSrcIdx = 78;
	  section.data(7).dtTransOffset = 6;
	
	  ;% motorlab6_P.TransferFcn5_A
	  section.data(8).logicalSrcIdx = 79;
	  section.data(8).dtTransOffset = 7;
	
	  ;% motorlab6_P.TransferFcn5_C
	  section.data(9).logicalSrcIdx = 80;
	  section.data(9).dtTransOffset = 9;
	
	  ;% motorlab6_P.TransferFcn1_A
	  section.data(10).logicalSrcIdx = 81;
	  section.data(10).dtTransOffset = 11;
	
	  ;% motorlab6_P.TransferFcn1_C
	  section.data(11).logicalSrcIdx = 82;
	  section.data(11).dtTransOffset = 12;
	
	  ;% motorlab6_P.TransferFcn3_A
	  section.data(12).logicalSrcIdx = 83;
	  section.data(12).dtTransOffset = 13;
	
	  ;% motorlab6_P.TransferFcn3_C
	  section.data(13).logicalSrcIdx = 84;
	  section.data(13).dtTransOffset = 14;
	
	  ;% motorlab6_P.Potentiometer_Gain
	  section.data(14).logicalSrcIdx = 85;
	  section.data(14).dtTransOffset = 15;
	
	  ;% motorlab6_P.Step2_Time
	  section.data(15).logicalSrcIdx = 86;
	  section.data(15).dtTransOffset = 16;
	
	  ;% motorlab6_P.Step2_Y0
	  section.data(16).logicalSrcIdx = 87;
	  section.data(16).dtTransOffset = 17;
	
	  ;% motorlab6_P.Step2_YFinal
	  section.data(17).logicalSrcIdx = 88;
	  section.data(17).dtTransOffset = 18;
	
	  ;% motorlab6_P.TransferFcn2_A
	  section.data(18).logicalSrcIdx = 89;
	  section.data(18).dtTransOffset = 19;
	
	  ;% motorlab6_P.TransferFcn2_C
	  section.data(19).logicalSrcIdx = 90;
	  section.data(19).dtTransOffset = 20;
	
	  ;% motorlab6_P.TransferFcn_A
	  section.data(20).logicalSrcIdx = 91;
	  section.data(20).dtTransOffset = 21;
	
	  ;% motorlab6_P.TransferFcn_C
	  section.data(21).logicalSrcIdx = 92;
	  section.data(21).dtTransOffset = 22;
	
	  ;% motorlab6_P.TransferFcn_D
	  section.data(22).logicalSrcIdx = 93;
	  section.data(22).dtTransOffset = 23;
	
	  ;% motorlab6_P.Saturation_UpperSat
	  section.data(23).logicalSrcIdx = 94;
	  section.data(23).dtTransOffset = 24;
	
	  ;% motorlab6_P.Saturation_LowerSat
	  section.data(24).logicalSrcIdx = 95;
	  section.data(24).dtTransOffset = 25;
	
	  ;% motorlab6_P.Saturation1_UpperSat
	  section.data(25).logicalSrcIdx = 96;
	  section.data(25).dtTransOffset = 26;
	
	  ;% motorlab6_P.Saturation1_LowerSat
	  section.data(26).logicalSrcIdx = 97;
	  section.data(26).dtTransOffset = 27;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% motorlab6_P.ManualSwitch1_CurrentSetting
	  section.data(1).logicalSrcIdx = 98;
	  section.data(1).dtTransOffset = 0;
	
	  ;% motorlab6_P.ManualSwitch_CurrentSetting
	  section.data(2).logicalSrcIdx = 99;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% motorlab6_P.HILReadAnalogTimebase_Active
	  section.data(1).logicalSrcIdx = 100;
	  section.data(1).dtTransOffset = 0;
	
	  ;% motorlab6_P.HILWriteAnalog_Active
	  section.data(2).logicalSrcIdx = 101;
	  section.data(2).dtTransOffset = 1;
	
	  ;% motorlab6_P.HILReadEncoder_Active
	  section.data(3).logicalSrcIdx = 102;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (motorlab6_B)
    ;%
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% motorlab6_B.Tacometer
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% motorlab6_B.Gain2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% motorlab6_B.Saturation2
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% motorlab6_B.Gain1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% motorlab6_B.Encoder
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% motorlab6_B.TSamp
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% motorlab6_B.DigitalFilter
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% motorlab6_B.TransferFcn5
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% motorlab6_B.TransferFcn1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% motorlab6_B.TransferFcn3
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% motorlab6_B.Potentiometer
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% motorlab6_B.Add1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% motorlab6_B.ManualSwitch1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% motorlab6_B.Add3
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% motorlab6_B.Add4
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% motorlab6_B.Saturation
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% motorlab6_B.Saturation1
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (motorlab6_DW)
    ;%
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% motorlab6_DW.UD_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% motorlab6_DW.DigitalFilter_FILT_STATES
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% motorlab6_DW.HILInitialize_AIMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% motorlab6_DW.HILInitialize_AIMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 11;
	
	  ;% motorlab6_DW.HILInitialize_AOMinimums
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 19;
	
	  ;% motorlab6_DW.HILInitialize_AOMaximums
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 27;
	
	  ;% motorlab6_DW.HILInitialize_AOVoltages
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 35;
	
	  ;% motorlab6_DW.HILInitialize_FilterFrequency
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 43;
	
	  ;% motorlab6_DW.HILInitialize_POSortedFreqs
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 51;
	
	  ;% motorlab6_DW.HILInitialize_POValues
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 59;
	
	  ;% motorlab6_DW.HILReadAnalogTimebase_Buffer
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 67;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% motorlab6_DW.HILReadAnalogTimebase_Task
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% motorlab6_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% motorlab6_DW.HILWriteAnalog_PWORK
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% motorlab6_DW.HILReadEncoder_PWORK
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
	  ;% motorlab6_DW.Omegalab1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 2;
	
	  ;% motorlab6_DW.Omegalab2_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 16;
	  section.data(4).dtTransOffset = 5;
	
	  ;% motorlab6_DW.Omegalab6_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 17;
	  section.data(5).dtTransOffset = 7;
	
	  ;% motorlab6_DW.Thetalab1_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 18;
	  section.data(6).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% motorlab6_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% motorlab6_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 3;
	
	  ;% motorlab6_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 11;
	
	  ;% motorlab6_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 19;
	
	  ;% motorlab6_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 27;
	
	  ;% motorlab6_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 24;
	  section.data(6).dtTransOffset = 35;
	
	  ;% motorlab6_DW.HILReadEncoder_Buffer
	  section.data(7).logicalSrcIdx = 25;
	  section.data(7).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% motorlab6_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2241213851;
  targMap.checksum1 = 2964355701;
  targMap.checksum2 = 3700503339;
  targMap.checksum3 = 3131954492;

