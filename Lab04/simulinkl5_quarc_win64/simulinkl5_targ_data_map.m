  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
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
    ;% Auto data (simulinkl5_P)
    ;%
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% simulinkl5_P.Beq
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% simulinkl5_P.Jeq
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% simulinkl5_P.Ka
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% simulinkl5_P.Kb
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% simulinkl5_P.Kg
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% simulinkl5_P.Rm
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% simulinkl5_P.HILInitialize_analog_input_maxi
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% simulinkl5_P.HILInitialize_analog_input_mini
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% simulinkl5_P.HILInitialize_analog_output_max
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% simulinkl5_P.HILInitialize_analog_output_min
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% simulinkl5_P.HILInitialize_final_analog_outp
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% simulinkl5_P.HILInitialize_final_pwm_outputs
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% simulinkl5_P.HILInitialize_initial_analog_ou
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% simulinkl5_P.HILInitialize_initial_pwm_outpu
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% simulinkl5_P.HILInitialize_pwm_frequency
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% simulinkl5_P.HILInitialize_pwm_leading_deadb
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% simulinkl5_P.HILInitialize_pwm_trailing_dead
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% simulinkl5_P.HILInitialize_set_other_outputs
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% simulinkl5_P.HILInitialize_set_other_outpu_m
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% simulinkl5_P.HILInitialize_set_other_outpu_o
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% simulinkl5_P.HILInitialize_set_other_outpu_d
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% simulinkl5_P.HILInitialize_watchdog_analog_o
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% simulinkl5_P.HILInitialize_watchdog_pwm_outp
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% simulinkl5_P.HILReadAnalogTimebase_clock
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% simulinkl5_P.HILInitialize_hardware_clocks
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 1;
	
	  ;% simulinkl5_P.HILInitialize_initial_encoder_c
	  section.data(3).logicalSrcIdx = 25;
	  section.data(3).dtTransOffset = 4;
	
	  ;% simulinkl5_P.HILInitialize_pwm_alignment
	  section.data(4).logicalSrcIdx = 26;
	  section.data(4).dtTransOffset = 5;
	
	  ;% simulinkl5_P.HILInitialize_pwm_configuration
	  section.data(5).logicalSrcIdx = 27;
	  section.data(5).dtTransOffset = 6;
	
	  ;% simulinkl5_P.HILInitialize_pwm_modes
	  section.data(6).logicalSrcIdx = 28;
	  section.data(6).dtTransOffset = 7;
	
	  ;% simulinkl5_P.HILInitialize_pwm_polarity
	  section.data(7).logicalSrcIdx = 29;
	  section.data(7).dtTransOffset = 8;
	
	  ;% simulinkl5_P.HILInitialize_watchdog_digital_
	  section.data(8).logicalSrcIdx = 30;
	  section.data(8).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% simulinkl5_P.HILInitialize_analog_input_chan
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
	  ;% simulinkl5_P.HILInitialize_analog_output_cha
	  section.data(2).logicalSrcIdx = 32;
	  section.data(2).dtTransOffset = 8;
	
	  ;% simulinkl5_P.HILReadAnalogTimebase_channels
	  section.data(3).logicalSrcIdx = 33;
	  section.data(3).dtTransOffset = 16;
	
	  ;% simulinkl5_P.HILWriteAnalog_channels
	  section.data(4).logicalSrcIdx = 34;
	  section.data(4).dtTransOffset = 18;
	
	  ;% simulinkl5_P.HILReadEncoder_channels
	  section.data(5).logicalSrcIdx = 35;
	  section.data(5).dtTransOffset = 19;
	
	  ;% simulinkl5_P.HILInitialize_encoder_channels
	  section.data(6).logicalSrcIdx = 36;
	  section.data(6).dtTransOffset = 20;
	
	  ;% simulinkl5_P.HILInitialize_pwm_channels
	  section.data(7).logicalSrcIdx = 37;
	  section.data(7).dtTransOffset = 28;
	
	  ;% simulinkl5_P.HILInitialize_quadrature
	  section.data(8).logicalSrcIdx = 38;
	  section.data(8).dtTransOffset = 36;
	
	  ;% simulinkl5_P.HILReadAnalogTimebase_samples_i
	  section.data(9).logicalSrcIdx = 39;
	  section.data(9).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% simulinkl5_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% simulinkl5_P.HILInitialize_final_digital_out
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 1;
	
	  ;% simulinkl5_P.HILInitialize_initial_digital_o
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 2;
	
	  ;% simulinkl5_P.HILInitialize_set_analog_input_
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 3;
	
	  ;% simulinkl5_P.HILInitialize_set_analog_inpu_h
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 4;
	
	  ;% simulinkl5_P.HILInitialize_set_analog_output
	  section.data(6).logicalSrcIdx = 45;
	  section.data(6).dtTransOffset = 5;
	
	  ;% simulinkl5_P.HILInitialize_set_analog_outp_o
	  section.data(7).logicalSrcIdx = 46;
	  section.data(7).dtTransOffset = 6;
	
	  ;% simulinkl5_P.HILInitialize_set_analog_outp_d
	  section.data(8).logicalSrcIdx = 47;
	  section.data(8).dtTransOffset = 7;
	
	  ;% simulinkl5_P.HILInitialize_set_analog_outp_g
	  section.data(9).logicalSrcIdx = 48;
	  section.data(9).dtTransOffset = 8;
	
	  ;% simulinkl5_P.HILInitialize_set_analog_outp_i
	  section.data(10).logicalSrcIdx = 49;
	  section.data(10).dtTransOffset = 9;
	
	  ;% simulinkl5_P.HILInitialize_set_analog_out_da
	  section.data(11).logicalSrcIdx = 50;
	  section.data(11).dtTransOffset = 10;
	
	  ;% simulinkl5_P.HILInitialize_set_analog_out_ob
	  section.data(12).logicalSrcIdx = 51;
	  section.data(12).dtTransOffset = 11;
	
	  ;% simulinkl5_P.HILInitialize_set_clock_frequen
	  section.data(13).logicalSrcIdx = 52;
	  section.data(13).dtTransOffset = 12;
	
	  ;% simulinkl5_P.HILInitialize_set_clock_frequ_g
	  section.data(14).logicalSrcIdx = 53;
	  section.data(14).dtTransOffset = 13;
	
	  ;% simulinkl5_P.HILInitialize_set_clock_params_
	  section.data(15).logicalSrcIdx = 54;
	  section.data(15).dtTransOffset = 14;
	
	  ;% simulinkl5_P.HILInitialize_set_clock_param_f
	  section.data(16).logicalSrcIdx = 55;
	  section.data(16).dtTransOffset = 15;
	
	  ;% simulinkl5_P.HILInitialize_set_digital_outpu
	  section.data(17).logicalSrcIdx = 56;
	  section.data(17).dtTransOffset = 16;
	
	  ;% simulinkl5_P.HILInitialize_set_digital_out_k
	  section.data(18).logicalSrcIdx = 57;
	  section.data(18).dtTransOffset = 17;
	
	  ;% simulinkl5_P.HILInitialize_set_digital_out_g
	  section.data(19).logicalSrcIdx = 58;
	  section.data(19).dtTransOffset = 18;
	
	  ;% simulinkl5_P.HILInitialize_set_digital_out_f
	  section.data(20).logicalSrcIdx = 59;
	  section.data(20).dtTransOffset = 19;
	
	  ;% simulinkl5_P.HILInitialize_set_digital_out_l
	  section.data(21).logicalSrcIdx = 60;
	  section.data(21).dtTransOffset = 20;
	
	  ;% simulinkl5_P.HILInitialize_set_digital_out_p
	  section.data(22).logicalSrcIdx = 61;
	  section.data(22).dtTransOffset = 21;
	
	  ;% simulinkl5_P.HILInitialize_set_digital_ou_p1
	  section.data(23).logicalSrcIdx = 62;
	  section.data(23).dtTransOffset = 22;
	
	  ;% simulinkl5_P.HILInitialize_set_encoder_count
	  section.data(24).logicalSrcIdx = 63;
	  section.data(24).dtTransOffset = 23;
	
	  ;% simulinkl5_P.HILInitialize_set_encoder_cou_h
	  section.data(25).logicalSrcIdx = 64;
	  section.data(25).dtTransOffset = 24;
	
	  ;% simulinkl5_P.HILInitialize_set_encoder_param
	  section.data(26).logicalSrcIdx = 65;
	  section.data(26).dtTransOffset = 25;
	
	  ;% simulinkl5_P.HILInitialize_set_encoder_par_p
	  section.data(27).logicalSrcIdx = 66;
	  section.data(27).dtTransOffset = 26;
	
	  ;% simulinkl5_P.HILInitialize_set_other_outpu_h
	  section.data(28).logicalSrcIdx = 67;
	  section.data(28).dtTransOffset = 27;
	
	  ;% simulinkl5_P.HILInitialize_set_pwm_outputs_a
	  section.data(29).logicalSrcIdx = 68;
	  section.data(29).dtTransOffset = 28;
	
	  ;% simulinkl5_P.HILInitialize_set_pwm_outputs_i
	  section.data(30).logicalSrcIdx = 69;
	  section.data(30).dtTransOffset = 29;
	
	  ;% simulinkl5_P.HILInitialize_set_pwm_outputs_c
	  section.data(31).logicalSrcIdx = 70;
	  section.data(31).dtTransOffset = 30;
	
	  ;% simulinkl5_P.HILInitialize_set_pwm_outputs_p
	  section.data(32).logicalSrcIdx = 71;
	  section.data(32).dtTransOffset = 31;
	
	  ;% simulinkl5_P.HILInitialize_set_pwm_outputs_o
	  section.data(33).logicalSrcIdx = 72;
	  section.data(33).dtTransOffset = 32;
	
	  ;% simulinkl5_P.HILInitialize_set_pwm_params_at
	  section.data(34).logicalSrcIdx = 73;
	  section.data(34).dtTransOffset = 33;
	
	  ;% simulinkl5_P.HILInitialize_set_pwm_params__g
	  section.data(35).logicalSrcIdx = 74;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% simulinkl5_P.SignalGenerator_Amplitude
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
	  ;% simulinkl5_P.SignalGenerator_Frequency
	  section.data(2).logicalSrcIdx = 76;
	  section.data(2).dtTransOffset = 1;
	
	  ;% simulinkl5_P.Bias_Bias
	  section.data(3).logicalSrcIdx = 77;
	  section.data(3).dtTransOffset = 2;
	
	  ;% simulinkl5_P.Gain1_Gain
	  section.data(4).logicalSrcIdx = 78;
	  section.data(4).dtTransOffset = 3;
	
	  ;% simulinkl5_P.Motor_IC
	  section.data(5).logicalSrcIdx = 79;
	  section.data(5).dtTransOffset = 4;
	
	  ;% simulinkl5_P.Motor2_IC
	  section.data(6).logicalSrcIdx = 80;
	  section.data(6).dtTransOffset = 5;
	
	  ;% simulinkl5_P.Potentiometer_Gain
	  section.data(7).logicalSrcIdx = 81;
	  section.data(7).dtTransOffset = 6;
	
	  ;% simulinkl5_P.Encoder_Gain
	  section.data(8).logicalSrcIdx = 82;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% simulinkl5_P.HILReadAnalogTimebase_Active
	  section.data(1).logicalSrcIdx = 83;
	  section.data(1).dtTransOffset = 0;
	
	  ;% simulinkl5_P.HILWriteAnalog_Active
	  section.data(2).logicalSrcIdx = 84;
	  section.data(2).dtTransOffset = 1;
	
	  ;% simulinkl5_P.HILReadEncoder_Active
	  section.data(3).logicalSrcIdx = 85;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
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
    ;% Auto data (simulinkl5_B)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% simulinkl5_B.Bias
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% simulinkl5_B.Gain1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% simulinkl5_B.Motor
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% simulinkl5_B.Motor2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% simulinkl5_B.Tacometer
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% simulinkl5_B.Potentiometer
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% simulinkl5_B.Encoder
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% simulinkl5_B.Add2
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
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
    nTotSects     = 7;
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
    ;% Auto data (simulinkl5_DW)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% simulinkl5_DW.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% simulinkl5_DW.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 8;
	
	  ;% simulinkl5_DW.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 16;
	
	  ;% simulinkl5_DW.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 24;
	
	  ;% simulinkl5_DW.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 32;
	
	  ;% simulinkl5_DW.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 40;
	
	  ;% simulinkl5_DW.HILInitialize_POSortedFreqs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 48;
	
	  ;% simulinkl5_DW.HILInitialize_POValues
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 56;
	
	  ;% simulinkl5_DW.HILReadAnalogTimebase_Buffer
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 64;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% simulinkl5_DW.HILReadAnalogTimebase_Task
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% simulinkl5_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% simulinkl5_DW.HILWriteAnalog_PWORK
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% simulinkl5_DW.ThetaFile_PWORK.FilePtr
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
	  ;% simulinkl5_DW.ThetaFile1_PWORK.FilePtr
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 2;
	
	  ;% simulinkl5_DW.VsimFile_PWORK.FilePtr
	  section.data(4).logicalSrcIdx = 14;
	  section.data(4).dtTransOffset = 3;
	
	  ;% simulinkl5_DW.WScope_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 15;
	  section.data(5).dtTransOffset = 4;
	
	  ;% simulinkl5_DW.Wscope_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 16;
	  section.data(6).dtTransOffset = 5;
	
	  ;% simulinkl5_DW.WsimFile1_PWORK.FilePtr
	  section.data(7).logicalSrcIdx = 17;
	  section.data(7).dtTransOffset = 7;
	
	  ;% simulinkl5_DW.HILReadEncoder_PWORK
	  section.data(8).logicalSrcIdx = 18;
	  section.data(8).dtTransOffset = 8;
	
	  ;% simulinkl5_DW.thetaScope1_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 19;
	  section.data(9).dtTransOffset = 9;
	
	  ;% simulinkl5_DW.thetascope_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 20;
	  section.data(10).dtTransOffset = 10;
	
	  ;% simulinkl5_DW.thetascope2_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 21;
	  section.data(11).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% simulinkl5_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% simulinkl5_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 3;
	
	  ;% simulinkl5_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 11;
	
	  ;% simulinkl5_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 25;
	  section.data(4).dtTransOffset = 19;
	
	  ;% simulinkl5_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 26;
	  section.data(5).dtTransOffset = 27;
	
	  ;% simulinkl5_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 27;
	  section.data(6).dtTransOffset = 35;
	
	  ;% simulinkl5_DW.HILReadEncoder_Buffer
	  section.data(7).logicalSrcIdx = 28;
	  section.data(7).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% simulinkl5_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% simulinkl5_DW.ThetaFile_IWORK.Count
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
	  ;% simulinkl5_DW.ThetaFile1_IWORK.Count
	  section.data(2).logicalSrcIdx = 31;
	  section.data(2).dtTransOffset = 1;
	
	  ;% simulinkl5_DW.VsimFile_IWORK.Count
	  section.data(3).logicalSrcIdx = 32;
	  section.data(3).dtTransOffset = 2;
	
	  ;% simulinkl5_DW.WsimFile1_IWORK.Count
	  section.data(4).logicalSrcIdx = 33;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
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


  targMap.checksum0 = 248499780;
  targMap.checksum1 = 576780723;
  targMap.checksum2 = 3777780011;
  targMap.checksum3 = 3839900616;

