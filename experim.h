/********************************************************************\

  Name:         experim.h
  Created by:   ODBedit program

  Contents:     This file contains C structures for the "Experiment"
                tree in the ODB and the "/Analyzer/Parameters" tree.

                Additionally, it contains the "Settings" subtree for
                all items listed under "/Equipment" as well as their
                event definition.

                It can be used by the frontend and analyzer to work
                with these information.

                All C structures are accompanied with a string represen-
                tation which can be used in the db_create_record function
                to setup an ODB structure which matches the C structure.

  Created on:   Wed Jan 31 14:32:04 2018

\********************************************************************/

#define EXP_PARAM_DEFINED

typedef struct {
  char      comment[80];
  INT       ndigitizers;
  struct {
    char      caendigitizersys[32];
    char      caencommsys[32];
    char      caenupgradersys[32];
    char      caenvmelibsys[32];
    char      caena3818sys[32];
    char      caendigitizersys_compile[32];
    char      caencommsys_compile[32];
    char      caenupgradersys_compile[32];
    char      caenvmelibsys_compile[32];
    char      caenva3818sys_compile[32];

  } library_information;
  struct {
    char      comment[64];
    BOOL      enabled;
    char      linktype[32];
    DWORD     vmebaseaddress;
    INT       linknum;
    INT       conetnum;
    char      acqmode[32];
    struct {
      char      type[32];
      INT       serial_number;
      INT       roc_major_version;
      INT       roc_minor_version;
      INT       roc_build;
      INT       amc_major_version;
      INT       amc_minor_version;
      INT       amc_build;
      INT       nchannels;
    } digitizer_information;
    struct {
      DWORD     register_0x8000;
      DWORD     register_0x800c;
      DWORD     register_0x8100;
      DWORD     register_0x810c;
      DWORD     register_0x8110;
      DWORD     register_0x811c;
      DWORD     register_0x8138;
      DWORD     register_0x8144;
      DWORD     register_0x8170;
      DWORD     register_0x817c;
      DWORD     register_0x81a0;
      DWORD     register_0xef00;
    } general_board_registers;
    struct {
      struct {
	DWORD     register_0x8180;
	DWORD     register_0x8184;
	DWORD     register_0x8188;
	DWORD     register_0x818c;
	DWORD     register_0x8190;
	DWORD     register_0x8194;
	DWORD     register_0x8198;
	DWORD     register_0x819c;
      } trigger_validation_registers;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_0;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_1;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_2;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_3;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_4;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_5;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_6;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_7;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_8;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_9;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_10;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_11;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_12;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_13;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_14;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_15;
    } caen_x725_x730_settings;
  } digitizer_0;
  struct {
    char      comment[64];
    BOOL      enabled;
    char      linktype[32];
    DWORD     vmebaseaddress;
    INT       linknum;
    INT       conetnum;
    char      acqmode[32];
    struct {
      char      type[32];
      INT       serial_number;
      INT       roc_major_version;
      INT       roc_minor_version;
      INT       roc_build;
      INT       amc_major_version;
      INT       amc_minor_version;
      INT       amc_build;
      INT       nchannels;
    } digitizer_information;
    struct {
      DWORD     register_0x8000;
      DWORD     register_0x800c;
      DWORD     register_0x8100;
      DWORD     register_0x810c;
      DWORD     register_0x8110;
      DWORD     register_0x811c;
      DWORD     register_0x8138;
      DWORD     register_0x8144;
      DWORD     register_0x8170;
      DWORD     register_0x817c;
      DWORD     register_0x81a0;
      DWORD     register_0xef00;
    } general_board_registers;
    struct {
      struct {
	DWORD     register_0x8180;
	DWORD     register_0x8184;
	DWORD     register_0x8188;
	DWORD     register_0x818c;
	DWORD     register_0x8190;
	DWORD     register_0x8194;
	DWORD     register_0x8198;
	DWORD     register_0x819c;
      } trigger_validation_registers;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_0;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_1;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_2;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_3;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_4;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_5;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_6;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_7;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_8;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_9;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_10;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_11;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_12;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_13;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_14;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_15;
    } caen_x725_x730_settings;
  } digitizer_1;
  struct {
    char      comment[64];
    BOOL      enabled;
    char      linktype[32];
    DWORD     vmebaseaddress;
    INT       linknum;
    INT       conetnum;
    char      acqmode[32];
    struct {
      char      type[32];
      INT       serial_number;
      INT       roc_major_version;
      INT       roc_minor_version;
       INT       roc_build;
     INT       amc_major_version;
      INT       amc_minor_version;
       INT       amc_build;
     INT       nchannels;
    } digitizer_information;
    struct {
      DWORD     register_0x8000;
      DWORD     register_0x800c;
      DWORD     register_0x8100;
      DWORD     register_0x810c;
      DWORD     register_0x8110;
      DWORD     register_0x811c;
      DWORD     register_0x8138;
      DWORD     register_0x8144;
      DWORD     register_0x8170;
      DWORD     register_0x817c;
      DWORD     register_0x81a0;
      DWORD     register_0xef00;
    } general_board_registers;
    struct {
      struct {
	DWORD     register_0x8180;
	DWORD     register_0x8184;
	DWORD     register_0x8188;
	DWORD     register_0x818c;
	DWORD     register_0x8190;
	DWORD     register_0x8194;
	DWORD     register_0x8198;
	DWORD     register_0x819c;
      } trigger_validation_registers;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_0;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_1;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_2;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_3;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_4;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_5;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_6;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_7;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_8;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_9;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_10;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_11;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_12;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_13;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_14;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_15;
    } caen_x725_x730_settings;
  } digitizer_2;
  struct {
    char      comment[64];
    BOOL      enabled;
    char      linktype[32];
    DWORD     vmebaseaddress;
    INT       linknum;
    INT       conetnum;
    char      acqmode[32];
    struct {
      char      type[32];
      INT       serial_number;
      INT       roc_major_version;
      INT       roc_minor_version;
      INT       roc_build;
      INT       amc_major_version;
      INT       amc_minor_version;
      INT       amc_build;
     INT       nchannels;
    } digitizer_information;
    struct {
      DWORD     register_0x8000;
      DWORD     register_0x800c;
      DWORD     register_0x8100;
      DWORD     register_0x810c;
      DWORD     register_0x8110;
      DWORD     register_0x811c;
      DWORD     register_0x8138;
      DWORD     register_0x8144;
      DWORD     register_0x8170;
      DWORD     register_0x817c;
      DWORD     register_0x81a0;
      DWORD     register_0xef00;
    } general_board_registers;
    struct {
      struct {
	DWORD     register_0x8180;
	DWORD     register_0x8184;
	DWORD     register_0x8188;
	DWORD     register_0x818c;
	DWORD     register_0x8190;
	DWORD     register_0x8194;
	DWORD     register_0x8198;
	DWORD     register_0x819c;
      } trigger_validation_registers;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_0;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_1;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_2;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_3;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_4;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_5;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_6;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_7;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_8;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_9;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_10;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_11;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_12;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_13;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_14;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_15;
    } caen_x725_x730_settings;
  } digitizer_3;
  struct {
    char      comment[64];
    BOOL      enabled;
    char      linktype[32];
    DWORD     vmebaseaddress;
    INT       linknum;
    INT       conetnum;
    char      acqmode[32];
    struct {
      char      type[32];
      INT       serial_number;
      INT       roc_major_version;
      INT       roc_minor_version;
      INT       roc_build;
      INT       amc_major_version;
      INT       amc_minor_version;
      INT       amc_build;
      INT       nchannels;
    } digitizer_information;
    struct {
      DWORD     register_0x8000;
      DWORD     register_0x800c;
      DWORD     register_0x8100;
      DWORD     register_0x810c;
      DWORD     register_0x8110;
      DWORD     register_0x811c;
      DWORD     register_0x8138;
      DWORD     register_0x8144;
      DWORD     register_0x8170;
      DWORD     register_0x817c;
      DWORD     register_0x81a0;
      DWORD     register_0xef00;
    } general_board_registers;
    struct {
      struct {
	DWORD     register_0x8180;
	DWORD     register_0x8184;
	DWORD     register_0x8188;
	DWORD     register_0x818c;
	DWORD     register_0x8190;
	DWORD     register_0x8194;
	DWORD     register_0x8198;
	DWORD     register_0x819c;
      } trigger_validation_registers;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_0;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_1;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_2;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_3;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_4;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_5;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_6;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_7;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_8;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_9;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_10;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_11;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_12;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_13;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_14;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_15;
    } caen_x725_x730_settings;
  } digitizer_4;

  struct {
    char      comment[64];
    BOOL      enabled;
    char      linktype[32];
    DWORD     vmebaseaddress;
    INT       linknum;
    INT       conetnum;
    char      acqmode[32];
    struct {
      char      type[32];
      INT       serial_number;
      INT       roc_major_version;
      INT       roc_minor_version;
       INT       roc_build;
     INT       amc_major_version;
      INT       amc_minor_version;
      INT       amc_build;
      INT       nchannels;
    } digitizer_information;
    struct {
      DWORD     register_0x8000;
      DWORD     register_0x800c;
      DWORD     register_0x8100;
      DWORD     register_0x810c;
      DWORD     register_0x8110;
      DWORD     register_0x811c;
      DWORD     register_0x8138;
      DWORD     register_0x8144;
      DWORD     register_0x8170;
      DWORD     register_0x817c;
      DWORD     register_0x81a0;
      DWORD     register_0xef00;
    } general_board_registers;
    struct {
      struct {
	DWORD     register_0x8180;
	DWORD     register_0x8184;
	DWORD     register_0x8188;
	DWORD     register_0x818c;
	DWORD     register_0x8190;
	DWORD     register_0x8194;
	DWORD     register_0x8198;
	DWORD     register_0x819c;
      } trigger_validation_registers;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_0;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_1;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_2;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_3;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_4;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_5;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_6;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_7;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_8;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_9;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_10;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_11;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_12;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_13;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_14;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_15;
    } caen_x725_x730_settings;
  } digitizer_5;

  struct {
    char      comment[64];
    BOOL      enabled;
    char      linktype[32];
    DWORD     vmebaseaddress;
    INT       linknum;
    INT       conetnum;
    char      acqmode[32];
    struct {
      char      type[32];
      INT       serial_number;
      INT       roc_major_version;
      INT       roc_minor_version;
      INT       roc_build;
      INT       amc_major_version;
      INT       amc_minor_version;
      INT       amc_build;
      INT       nchannels;
    } digitizer_information;
    struct {
      DWORD     register_0x8000;
      DWORD     register_0x800c;
      DWORD     register_0x8100;
      DWORD     register_0x810c;
      DWORD     register_0x8110;
      DWORD     register_0x811c;
      DWORD     register_0x8138;
      DWORD     register_0x8144;
      DWORD     register_0x8170;
      DWORD     register_0x817c;
      DWORD     register_0x81a0;
      DWORD     register_0xef00;
    } general_board_registers;
    struct {
      struct {
	DWORD     register_0x8180;
	DWORD     register_0x8184;
	DWORD     register_0x8188;
	DWORD     register_0x818c;
	DWORD     register_0x8190;
	DWORD     register_0x8194;
	DWORD     register_0x8198;
	DWORD     register_0x819c;
      } trigger_validation_registers;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_0;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_1;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_2;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_3;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_4;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_5;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_6;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_7;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_8;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_9;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_10;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_11;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_12;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_13;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_14;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_15;
    } caen_x725_x730_settings;
  } digitizer_6;

  struct {
    char      comment[64];
    BOOL      enabled;
    char      linktype[32];
    DWORD     vmebaseaddress;
    INT       linknum;
    INT       conetnum;
    char      acqmode[32];
    struct {
      char      type[32];
      INT       serial_number;
      INT       roc_major_version;
      INT       roc_minor_version;
      INT       roc_build;
      INT       amc_major_version;
      INT       amc_minor_version;
      INT       amc_build;
      INT       nchannels;
    } digitizer_information;
    struct {
      DWORD     register_0x8000;
      DWORD     register_0x800c;
      DWORD     register_0x8100;
      DWORD     register_0x810c;
      DWORD     register_0x8110;
      DWORD     register_0x811c;
      DWORD     register_0x8138;
      DWORD     register_0x8144;
      DWORD     register_0x8170;
      DWORD     register_0x817c;
      DWORD     register_0x81a0;
      DWORD     register_0xef00;
    } general_board_registers;
    struct {
      struct {
	DWORD     register_0x8180;
	DWORD     register_0x8184;
	DWORD     register_0x8188;
	DWORD     register_0x818c;
	DWORD     register_0x8190;
	DWORD     register_0x8194;
	DWORD     register_0x8198;
	DWORD     register_0x819c;
      } trigger_validation_registers;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_0;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_1;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_2;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_3;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_4;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_5;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_6;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_7;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_8;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_9;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_10;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_11;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_12;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_13;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_14;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_15;
    } caen_x725_x730_settings;
  } digitizer_7;

  struct {
    char      comment[64];
    BOOL      enabled;
    char      linktype[32];
    DWORD     vmebaseaddress;
    INT       linknum;
    INT       conetnum;
    char      acqmode[32];
    struct {
      char      type[32];
      INT       serial_number;
      INT       roc_major_version;
      INT       roc_minor_version;
      INT       roc_build;
      INT       amc_major_version;
      INT       amc_minor_version;
      INT       amc_build;
      INT       nchannels;
    } digitizer_information;
    struct {
      DWORD     register_0x8000;
      DWORD     register_0x800c;
      DWORD     register_0x8100;
      DWORD     register_0x810c;
      DWORD     register_0x8110;
      DWORD     register_0x811c;
      DWORD     register_0x8138;
      DWORD     register_0x8144;
      DWORD     register_0x8170;
      DWORD     register_0x817c;
      DWORD     register_0x81a0;
      DWORD     register_0xef00;
    } general_board_registers;
    struct {
      struct {
	DWORD     register_0x8180;
	DWORD     register_0x8184;
	DWORD     register_0x8188;
	DWORD     register_0x818c;
	DWORD     register_0x8190;
	DWORD     register_0x8194;
	DWORD     register_0x8198;
	DWORD     register_0x819c;
      } trigger_validation_registers;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_0;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_1;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_2;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_3;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_4;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_5;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_6;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_7;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_8;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_9;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_10;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_11;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_12;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_13;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_14;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_15;
    } caen_x725_x730_settings;
  } digitizer_8;

  struct {
    char      comment[64];
    BOOL      enabled;
    char      linktype[32];
    DWORD     vmebaseaddress;
    INT       linknum;
    INT       conetnum;
    char      acqmode[32];
    struct {
      char      type[32];
      INT       serial_number;
      INT       roc_major_version;
      INT       roc_minor_version;
       INT       roc_build;
     INT       amc_major_version;
      INT       amc_minor_version;
      INT       amc_build;
      INT       nchannels;
    } digitizer_information;
    struct {
      DWORD     register_0x8000;
      DWORD     register_0x800c;
      DWORD     register_0x8100;
      DWORD     register_0x810c;
      DWORD     register_0x8110;
      DWORD     register_0x811c;
      DWORD     register_0x8138;
      DWORD     register_0x8144;
      DWORD     register_0x8170;
      DWORD     register_0x817c;
      DWORD     register_0x81a0;
      DWORD     register_0xef00;
    } general_board_registers;
    struct {
      struct {
	DWORD     register_0x8180;
	DWORD     register_0x8184;
	DWORD     register_0x8188;
	DWORD     register_0x818c;
	DWORD     register_0x8190;
	DWORD     register_0x8194;
	DWORD     register_0x8198;
	DWORD     register_0x819c;
      } trigger_validation_registers;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_0;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_1;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_2;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_3;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_4;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_5;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_6;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_7;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_8;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_9;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_10;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_11;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_12;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_13;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_14;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_15;
    } caen_x725_x730_settings;
  } digitizer_9;

  struct {
    char      comment[64];
    BOOL      enabled;
    char      linktype[32];
    DWORD     vmebaseaddress;
    INT       linknum;
    INT       conetnum;
    char      acqmode[32];
    struct {
      char      type[32];
      INT       serial_number;
      INT       roc_major_version;
      INT       roc_minor_version;
      INT       roc_build;
      INT       amc_major_version;
      INT       amc_minor_version;
      INT       amc_build;
      INT       nchannels;
    } digitizer_information;
    struct {
      DWORD     register_0x8000;
      DWORD     register_0x800c;
      DWORD     register_0x8100;
      DWORD     register_0x810c;
      DWORD     register_0x8110;
      DWORD     register_0x811c;
      DWORD     register_0x8138;
      DWORD     register_0x8144;
      DWORD     register_0x8170;
      DWORD     register_0x817c;
      DWORD     register_0x81a0;
      DWORD     register_0xef00;
    } general_board_registers;
    struct {
      struct{
	DWORD     register_0x8180;
	DWORD     register_0x8184;
	DWORD     register_0x8188;
	DWORD     register_0x818c;
	DWORD     register_0x8190;
	DWORD     register_0x8194;
	DWORD     register_0x8198;
	DWORD     register_0x819c;
      } trigger_validation_registers;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_0;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_1;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_2;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_3;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_4;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_5;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_6;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_7;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_8;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_9;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_10;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_11;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_12;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_13;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_14;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_15;
    } caen_x725_x730_settings;
  } digitizer_10;

  struct {
    char      comment[64];
    BOOL      enabled;
    char      linktype[32];
    DWORD     vmebaseaddress;
    INT       linknum;
    INT       conetnum;
    char      acqmode[32];
    struct {
      char      type[32];
      INT       serial_number;
      INT       roc_major_version;
      INT       roc_minor_version;
      INT       roc_build;
      INT       amc_major_version;
      INT       amc_minor_version;
      INT       amc_build;
      INT       nchannels;
    } digitizer_information;
    struct {
      DWORD     register_0x8000;
      DWORD     register_0x800c;
      DWORD     register_0x8100;
      DWORD     register_0x810c;
      DWORD     register_0x8110;
      DWORD     register_0x811c;
      DWORD     register_0x8138;
      DWORD     register_0x8144;
      DWORD     register_0x8170;
      DWORD     register_0x817c;
      DWORD     register_0x81a0;
      DWORD     register_0xef00;
    } general_board_registers;
    struct {
      struct {
	DWORD     register_0x8180;
	DWORD     register_0x8184;
	DWORD     register_0x8188;
	DWORD     register_0x818c;
	DWORD     register_0x8190;
	DWORD     register_0x8194;
	DWORD     register_0x8198;
	DWORD     register_0x819c;
      } trigger_validation_registers;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_0;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_1;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_2;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_3;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_4;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_5;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_6;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_7;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_8;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_9;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_10;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_11;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_12;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_13;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_14;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_15;
    } caen_x725_x730_settings;
  } digitizer_11;

  struct {
    char      comment[64];
    BOOL      enabled;
    char      linktype[32];
    DWORD     vmebaseaddress;
    INT       linknum;
    INT       conetnum;
    char      acqmode[32];
    struct {
      char      type[32];
      INT       serial_number;
      INT       roc_major_version;
      INT       roc_minor_version;
      INT       roc_build;
      INT       amc_major_version;
      INT       amc_minor_version;
      INT       amc_build;
      INT       nchannels;
    } digitizer_information;
    struct {
      DWORD     register_0x8000;
      DWORD     register_0x800c;
      DWORD     register_0x8100;
      DWORD     register_0x810c;
      DWORD     register_0x8110;
      DWORD     register_0x811c;
      DWORD     register_0x8138;
      DWORD     register_0x8144;
      DWORD     register_0x8170;
      DWORD     register_0x817c;
      DWORD     register_0x81a0;
      DWORD     register_0xef00;
    } general_board_registers;
    struct {
      struct {
	DWORD     register_0x8180;
	DWORD     register_0x8184;
	DWORD     register_0x8188;
	DWORD     register_0x818c;
	DWORD     register_0x8190;
	DWORD     register_0x8194;
	DWORD     register_0x8198;
	DWORD     register_0x819c;
      } trigger_validation_registers;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_0;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_1;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_2;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_3;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_4;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_5;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_6;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_7;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_8;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_9;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_10;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_11;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_12;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_13;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_14;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_15;
    } caen_x725_x730_settings;
  } digitizer_12;

  struct {
    char      comment[64];
    BOOL      enabled;
    char      linktype[32];
    DWORD     vmebaseaddress;
    INT       linknum;
    INT       conetnum;
    char      acqmode[32];
    struct {
      char      type[32];
      INT       serial_number;
      INT       roc_major_version;
      INT       roc_minor_version;
      INT       roc_build;
      INT       amc_major_version;
      INT       amc_minor_version;
      INT       amc_build;
      INT       nchannels;
    } digitizer_information;
    struct {
      DWORD     register_0x8000;
      DWORD     register_0x800c;
      DWORD     register_0x8100;
      DWORD     register_0x810c;
      DWORD     register_0x8110;
      DWORD     register_0x811c;
      DWORD     register_0x8138;
      DWORD     register_0x8144;
      DWORD     register_0x8170;
      DWORD     register_0x817c;
      DWORD     register_0x81a0;
      DWORD     register_0xef00;
    } general_board_registers;
    struct {
      struct {
	DWORD     register_0x8180;
	DWORD     register_0x8184;
	DWORD     register_0x8188;
	DWORD     register_0x818c;
	DWORD     register_0x8190;
	DWORD     register_0x8194;
	DWORD     register_0x8198;
	DWORD     register_0x819c;
      } trigger_validation_registers;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_0;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_1;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_2;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_3;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_4;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_5;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_6;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_7;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_8;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_9;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_10;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_11;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_12;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_13;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_14;
      struct {
	BOOL      enabled;
	char      pulsepolarity[32];
	float     adc_range;
	WORD      trigger_threshold;
	WORD      dc_offset;
	WORD      waveform_record_length;
	WORD      waveform_pre_trigger_length;
	WORD      nevents_per_aggregate;
	WORD      veto_width;
	WORD      veto_width_multiplier;
	WORD      shaped_trigger_width;
	WORD      trigger_hold_off_width;
	struct {
	  WORD    short_gate;
	  WORD    long_gate;
	  WORD    gate_offset;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1n84;
	  DWORD   register_0x1n3c; 
	  WORD    charge_zero_suppression_threshold;
	  WORD    psd_threshold;
	  WORD    pur_gap_threshold;
	  WORD    fixed_baseline;
	  WORD    baseline_freeze;
	} dpp_psd_params;
	struct {
	  WORD    tf_rise_time;
	  WORD    tf_flat_time;
	  WORD    peaking_time;
	  WORD    decay_time;
	  WORD    fine_gain;
	  WORD    rc_cr2;
	  WORD    input_rise_time;
	  WORD    rise_time_vw;
	  WORD    trig_holdoff;
	  WORD    peak_holdoff;
	  DWORD   register_0x1n80;
	  DWORD   register_0x1na0; 
	} dpp_pha_params;
      } channel_15;
    } caen_x725_x730_settings;
  } digitizer_13;
} EXP_PARAM;

#define EXP_PARAM_STR(_name) const char *_name[] = {			\
    "[.]",								\
    "Comment = STRING : [80] caen2018 frontend",			\
    "NDigitizers = INT : 11",						\
    "",									\
    "[CAEN_Library_Information]",					\
    "CAENdigitizersys = STRING : [32] NULL",				\
    "CAENcommsys = STRING : [32] NULL",					\
    "CAENupgradersys = STRING : [32] NULL",				\
    "CAENvmelibsys = STRING : [32] NULL",				\
     "CAENa3818sys = STRING : [32] NULL",				\
   "CAENdigitizersys_Compile = STRING : [32] NULL",			\
    "CAENcommsys_Compile = STRING : [32] NULL",				\
    "CAENupgradersys_Compile = STRING : [32] NULL",			\
    "CAENvmelibsys_Compile = STRING : [32] NULL",			\
    "CAENa3818sys_Compile = STRING : [32] NULL",			\
    "",									\
    "[Digitizer_0]",							\
    "Comment = STRING : [64] VX1730B with DPP-PSD firmware 136.10",	\
    "Enabled = BOOL : y",						\
    "LinkType = STRING : [32] CAEN_DGTZ_PCIE_OpticalLink",		\
    "VMEBaseAddress = DWORD : 0",					\
    "LinkNum = INT : 0",						\
    "ConetNum = INT : 0",						\
    "AcqMode = STRING : [32] CAEN_DGTZ_DPP_ACQ_MODE_Mixed",		\
    "",									\
    "[Digitizer_0/Digitizer_Information]",				\
    "Type = STRING : [32] VX1730B",					\
    "Serial_Number = INT : 89",						\
    "ROC_Major_Version = INT : 4",					\
    "ROC_Minor_Version = INT : 11",					\
    "ROC_Build = INT : 0",						\
   "AMC_Major_Version = INT : 136",					\
    "AMC_Minor_Version = INT : 10",					\
    "AMC_Build = INT : 0",						\
   "NChannels = INT : 16",						\
    "",									\
    "[Digitizer_0/General_Board_Registers]",				\
    "Register_0x8000 = DWORD : 0x000F0110",				\
    "Register_0x800C = DWORD : 0x0000000A",				\
    "Register_0x8100 = DWORD : 0x00000000",				\
    "Register_0x810C = DWORD : 0x80000000",				\
    "Register_0x8110 = DWORD : 0x0000FFFF",				\
    "Register_0x811C = DWORD : 0x00000D04",				\
    "Register_0x8138 = DWORD : 0x00000000",				\
    "Register_0x8144 = DWORD : 0x00000000",				\
    "Register_0x8170 = DWORD : 0x00000000",				\
    "Register_0x817C = DWORD : 0x00000000",				\
    "Register_0x81A0 = DWORD : 0x00000222",				\
    "Register_0xEF00 = DWORD : 0x00000010",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Trigger_Validation_Registers]", \
    "Register_0x8180 = DWORD : 0x20000000",				\
    "Register_0x8184 = DWORD : 0x20000000",				\
    "Register_0x8188 = DWORD : 0x20000000",				\
    "Register_0x818C = DWORD : 0x20000000",				\
    "Register_0x8190 = DWORD : 0x20000000",				\
    "Register_0x8194 = DWORD : 0x20000000",				\
    "Register_0x8198 = DWORD : 0x20000000",				\
    "Register_0x819C = DWORD : 0x20000000",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_0]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_0/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_0/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_1]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_1/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_1/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_2]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_2/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_2/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_3]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_3/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_3/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_4]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_4/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_4/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_5]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_5/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_5/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_6]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_6/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_6/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_7]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_7/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_7/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_8]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_8/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_8/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_9]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_9/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_9/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_10]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_10/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_10/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_11]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_11/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_11/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_12]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_12/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_12/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_13]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_13/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_13/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_14]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_14/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_14/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_15]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_15/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_0/CAEN_x725_x730_Settings/Channel_15/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_1]",							\
    "Comment = STRING : [64] VX1730B with DPP-PSD firmware 136.10",	\
    "Enabled = BOOL : y",						\
    "LinkType = STRING : [32] CAEN_DGTZ_PCIE_OpticalLink",		\
    "VMEBaseAddress = DWORD : 0",					\
    "LinkNum = INT : 0",						\
    "ConetNum = INT : 1",						\
    "AcqMode = STRING : [32] CAEN_DGTZ_DPP_ACQ_MODE_Mixed",		\
    "",									\
    "[Digitizer_1/Digitizer_Information]",				\
    "Type = STRING : [32] VX1730B",					\
    "Serial_Number = INT : 89",						\
    "ROC_Major_Version = INT : 4",					\
    "ROC_Minor_Version = INT : 11",					\
    "ROC_Build = INT : 0",						\
    "AMC_Major_Version = INT : 136",					\
    "AMC_Minor_Version = INT : 10",					\
    "AMC_Build = INT : 0",						\
    "NChannels = INT : 16",						\
    "",									\
    "[Digitizer_1/General_Board_Registers]",				\
    "Register_0x8000 = DWORD : 0x000F0110",				\
    "Register_0x800C = DWORD : 0x0000000A",				\
    "Register_0x8100 = DWORD : 0x00000007",				\
    "Register_0x810C = DWORD : 0x80000000",				\
    "Register_0x8110 = DWORD : 0x0000FFFF",				\
    "Register_0x811C = DWORD : 0x00000D04",				\
    "Register_0x8138 = DWORD : 0x00000000",				\
    "Register_0x8144 = DWORD : 0x00000000",				\
    "Register_0x8170 = DWORD : 0x00000000",				\
    "Register_0x817C = DWORD : 0x00000000",				\
    "Register_0x81A0 = DWORD : 0x00000222",				\
    "Register_0xEF00 = DWORD : 0x00000010",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Trigger_Validation_Registers]", \
    "Register_0x8180 = DWORD : 0x20000000",				\
    "Register_0x8184 = DWORD : 0x20000000",				\
    "Register_0x8188 = DWORD : 0x20000000",				\
    "Register_0x818C = DWORD : 0x20000000",				\
    "Register_0x8190 = DWORD : 0x20000000",				\
    "Register_0x8194 = DWORD : 0x20000000",				\
    "Register_0x8198 = DWORD : 0x20000000",				\
    "Register_0x819C = DWORD : 0x20000000",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_0]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_0/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_0/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_1]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_1/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_1/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_2]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_2/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_2/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_3]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_3/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_3/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_4]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_4/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_4/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_5]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_5/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_5/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_6]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_6/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_6/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_7]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_7/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_7/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_8]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_8/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_8/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_9]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_9/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_9/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_10]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_10/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_10/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_11]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_11/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_11/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_12]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_12/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_12/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_13]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_13/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_13/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_14]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_14/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_14/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_15]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_15/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_1/CAEN_x725_x730_Settings/Channel_15/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_2]",							\
    "Comment = STRING : [64] VX1730B with DPP-PSD firmware 136.10",	\
    "Enabled = BOOL : y",						\
    "LinkType = STRING : [32] CAEN_DGTZ_PCIE_OpticalLink",		\
    "VMEBaseAddress = DWORD : 0",					\
    "LinkNum = INT : 1",						\
    "ConetNum = INT : 0",						\
    "AcqMode = STRING : [32] CAEN_DGTZ_DPP_ACQ_MODE_Mixed",		\
    "",									\
    "[Digitizer_2/Digitizer_Information]",				\
    "Type = STRING : [32] VX1730B",					\
    "Serial_Number = INT : 89",						\
    "ROC_Major_Version = INT : 4",					\
    "ROC_Minor_Version = INT : 11",					\
    "ROC_Build = INT : 0",						\
    "AMC_Major_Version = INT : 136",					\
    "AMC_Minor_Version = INT : 10",					\
    "AMC_Build = INT : 0",						\
    "NChannels = INT : 16",						\
    "",									\
    "[Digitizer_2/General_Board_Registers]",				\
    "Register_0x8000 = DWORD : 0x000F0110",				\
    "Register_0x800C = DWORD : 0x0000000A",				\
    "Register_0x8100 = DWORD : 0x00000007",				\
    "Register_0x810C = DWORD : 0x80000000",				\
    "Register_0x8110 = DWORD : 0x0000FFFF",				\
    "Register_0x811C = DWORD : 0x00000D04",				\
    "Register_0x8138 = DWORD : 0x00000000",				\
    "Register_0x8144 = DWORD : 0x00000000",				\
    "Register_0x8170 = DWORD : 0x00000000",				\
    "Register_0x817C = DWORD : 0x00000000",				\
    "Register_0x81A0 = DWORD : 0x00000222",				\
    "Register_0xEF00 = DWORD : 0x00000010",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Trigger_Validation_Registers]", \
    "Register_0x8180 = DWORD : 0x20000000",				\
    "Register_0x8184 = DWORD : 0x20000000",				\
    "Register_0x8188 = DWORD : 0x20000000",				\
    "Register_0x818C = DWORD : 0x20000000",				\
    "Register_0x8190 = DWORD : 0x20000000",				\
    "Register_0x8194 = DWORD : 0x20000000",				\
    "Register_0x8198 = DWORD : 0x20000000",				\
    "Register_0x819C = DWORD : 0x20000000",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_0]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_0/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_0/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_1]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_1/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_1/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_2]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_2/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_2/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_3]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_3/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_3/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_4]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_4/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_4/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_5]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_5/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_5/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_6]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_6/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_6/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_7]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_7/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_7/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_8]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_8/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_8/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_9]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_9/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_9/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_10]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_10/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_10/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_11]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_11/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_11/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_12]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_12/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_12/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_13]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_13/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_13/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_14]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_14/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_14/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_15]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_15/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_2/CAEN_x725_x730_Settings/Channel_15/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_3]",							\
    "Comment = STRING : [64] VX1730B with DPP-PSD firmware 136.10",	\
    "Enabled = BOOL : y",						\
    "LinkType = STRING : [32] CAEN_DGTZ_PCIE_OpticalLink",		\
    "VMEBaseAddress = DWORD : 0",					\
    "LinkNum = INT : 1",						\
    "ConetNum = INT : 1",						\
    "AcqMode = STRING : [32] CAEN_DGTZ_DPP_ACQ_MODE_Mixed",		\
    "",									\
    "[Digitizer_3/Digitizer_Information]",				\
    "Type = STRING : [32] VX1730B",					\
    "Serial_Number = INT : 89",						\
    "ROC_Major_Version = INT : 4",					\
    "ROC_Minor_Version = INT : 11",					\
    "ROC_Build = INT : 0",						\
    "AMC_Major_Version = INT : 136",					\
    "AMC_Minor_Version = INT : 10",					\
    "AMC_Build = INT : 0",						\
    "NChannels = INT : 16",						\
    "",									\
    "[Digitizer_3/General_Board_Registers]",				\
    "Register_0x8000 = DWORD : 0x000F0110",				\
    "Register_0x800C = DWORD : 0x0000000A",				\
    "Register_0x8100 = DWORD : 0x00000007",				\
    "Register_0x810C = DWORD : 0x80000000",				\
    "Register_0x8110 = DWORD : 0x0000FFFF",				\
    "Register_0x811C = DWORD : 0x00000D04",				\
    "Register_0x8138 = DWORD : 0x00000000",				\
    "Register_0x8144 = DWORD : 0x00000000",				\
    "Register_0x8170 = DWORD : 0x00000000",				\
    "Register_0x817C = DWORD : 0x00000000",				\
    "Register_0x81A0 = DWORD : 0x00000222",				\
    "Register_0xEF00 = DWORD : 0x00000010",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Trigger_Validation_Registers]", \
    "Register_0x8180 = DWORD : 0x20000000",				\
    "Register_0x8184 = DWORD : 0x20000000",				\
    "Register_0x8188 = DWORD : 0x20000000",				\
    "Register_0x818C = DWORD : 0x20000000",				\
    "Register_0x8190 = DWORD : 0x20000000",				\
    "Register_0x8194 = DWORD : 0x20000000",				\
    "Register_0x8198 = DWORD : 0x20000000",				\
    "Register_0x819C = DWORD : 0x20000000",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_0]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_0/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_0/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_1]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_1/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_1/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_2]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_2/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_2/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_3]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_3/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_3/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_4]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_4/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_4/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_5]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_5/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_5/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_6]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_6/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_6/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_7]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_7/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_7/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_8]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_8/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_8/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_9]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_9/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_9/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_10]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_10/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_10/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_11]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_11/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_11/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_12]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_12/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_12/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_13]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_13/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_13/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_14]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_14/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_14/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_15]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_15/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_3/CAEN_x725_x730_Settings/Channel_15/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_4]",							\
    "Comment = STRING : [64] VX1730B with DPP-PSD firmware 136.10",	\
    "Enabled = BOOL : y",						\
    "LinkType = STRING : [32] CAEN_DGTZ_PCIE_OpticalLink",		\
    "VMEBaseAddress = DWORD : 0",					\
    "LinkNum = INT : 2",						\
    "ConetNum = INT : 0",						\
    "AcqMode = STRING : [32] CAEN_DGTZ_DPP_ACQ_MODE_Mixed",		\
    "",									\
    "[Digitizer_4/Digitizer_Information]",				\
    "Type = STRING : [32] VX1730B",					\
    "Serial_Number = INT : 89",						\
    "ROC_Major_Version = INT : 4",					\
    "ROC_Minor_Version = INT : 11",					\
     "ROC_Build = INT : 0",						\
   "AMC_Major_Version = INT : 136",					\
    "AMC_Minor_Version = INT : 10",					\
     "AMC_Build = INT : 0",						\
   "NChannels = INT : 16",						\
    "",									\
    "[Digitizer_4/General_Board_Registers]",				\
    "Register_0x8000 = DWORD : 0x000F0110",				\
    "Register_0x800C = DWORD : 0x0000000A",				\
    "Register_0x8100 = DWORD : 0x00000007",				\
    "Register_0x810C = DWORD : 0x80000000",				\
    "Register_0x8110 = DWORD : 0x0000FFFF",				\
    "Register_0x811C = DWORD : 0x00000D04",				\
    "Register_0x8138 = DWORD : 0x00000000",				\
    "Register_0x8144 = DWORD : 0x00000000",				\
    "Register_0x8170 = DWORD : 0x00000000",				\
    "Register_0x817C = DWORD : 0x00000000",				\
    "Register_0x81A0 = DWORD : 0x00000222",				\
    "Register_0xEF00 = DWORD : 0x00000010",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Trigger_Validation_Registers]", \
    "Register_0x8180 = DWORD : 0x20000000",				\
    "Register_0x8184 = DWORD : 0x20000000",				\
    "Register_0x8188 = DWORD : 0x20000000",				\
    "Register_0x818C = DWORD : 0x20000000",				\
    "Register_0x8190 = DWORD : 0x20000000",				\
    "Register_0x8194 = DWORD : 0x20000000",				\
    "Register_0x8198 = DWORD : 0x20000000",				\
    "Register_0x819C = DWORD : 0x20000000",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_0]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_0/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_0/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_1]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_1/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_1/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_2]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_2/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_2/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_3]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_3/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_3/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_4]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_4/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_4/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_5]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_5/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_5/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_6]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_6/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_6/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_7]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_7/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_7/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_8]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_8/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_8/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_9]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_9/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_9/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_10]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_10/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_10/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_11]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_11/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_11/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_12]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_12/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_12/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_13]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_13/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_13/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_14]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_14/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_14/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_15]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_15/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_4/CAEN_x725_x730_Settings/Channel_15/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_5]",							\
    "Comment = STRING : [64] VX1730B with DPP-PSD firmware 136.10",	\
    "Enabled = BOOL : y",						\
    "LinkType = STRING : [32] CAEN_DGTZ_PCIE_OpticalLink",		\
    "VMEBaseAddress = DWORD : 0",					\
    "LinkNum = INT : 2",						\
    "ConetNum = INT : 1",						\
    "AcqMode = STRING : [32] CAEN_DGTZ_DPP_ACQ_MODE_Mixed",		\
    "",									\
    "[Digitizer_5/Digitizer_Information]",				\
    "Type = STRING : [32] VX1730B",					\
    "Serial_Number = INT : 89",						\
    "ROC_Major_Version = INT : 4",					\
    "ROC_Minor_Version = INT : 11",					\
    "ROC_Build = INT : 0",						\
    "AMC_Major_Version = INT : 136",					\
    "AMC_Minor_Version = INT : 10",					\
    "AMC_Build = INT : 0",						\
    "NChannels = INT : 16",						\
    "",									\
    "[Digitizer_5/General_Board_Registers]",				\
    "Register_0x8000 = DWORD : 0x000F0110",				\
    "Register_0x800C = DWORD : 0x0000000A",				\
    "Register_0x8100 = DWORD : 0x00000007",				\
    "Register_0x810C = DWORD : 0x80000000",				\
    "Register_0x8110 = DWORD : 0x0000FFFF",				\
    "Register_0x811C = DWORD : 0x00000D04",				\
    "Register_0x8138 = DWORD : 0x00000000",				\
    "Register_0x8144 = DWORD : 0x00000000",				\
    "Register_0x8170 = DWORD : 0x00000000",				\
    "Register_0x817C = DWORD : 0x00000000",				\
    "Register_0x81A0 = DWORD : 0x00000222",				\
    "Register_0xEF00 = DWORD : 0x00000010",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Trigger_Validation_Registers]", \
    "Register_0x8180 = DWORD : 0x20000000",				\
    "Register_0x8184 = DWORD : 0x20000000",				\
    "Register_0x8188 = DWORD : 0x20000000",				\
    "Register_0x818C = DWORD : 0x20000000",				\
    "Register_0x8190 = DWORD : 0x20000000",				\
    "Register_0x8194 = DWORD : 0x20000000",				\
    "Register_0x8198 = DWORD : 0x20000000",				\
    "Register_0x819C = DWORD : 0x20000000",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_0]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_0/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_0/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_1]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_1/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_1/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_2]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_2/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_2/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_3]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_3/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_3/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_4]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_4/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_4/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_5]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_5/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_5/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_6]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_6/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_6/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_7]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_7/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_7/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_8]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_8/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_8/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_9]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_9/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_9/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_10]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_10/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_10/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_11]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_11/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_11/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_12]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_12/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_12/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_13]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_13/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_13/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_14]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_14/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_14/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_15]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_15/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_5/CAEN_x725_x730_Settings/Channel_15/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_6]",							\
    "Comment = STRING : [64] VX1730B with DPP-PSD firmware 136.10",	\
    "Enabled = BOOL : y",						\
    "LinkType = STRING : [32] CAEN_DGTZ_PCIE_OpticalLink",		\
    "VMEBaseAddress = DWORD : 0",					\
    "LinkNum = INT : 3",						\
    "ConetNum = INT : 0",						\
    "AcqMode = STRING : [32] CAEN_DGTZ_DPP_ACQ_MODE_Mixed",		\
    "",									\
    "[Digitizer_6/Digitizer_Information]",				\
    "Type = STRING : [32] VX1730B",					\
    "Serial_Number = INT : 89",						\
    "ROC_Major_Version = INT : 4",					\
    "ROC_Minor_Version = INT : 11",					\
    "ROC_Build = INT : 0",						\
    "AMC_Major_Version = INT : 136",					\
    "AMC_Minor_Version = INT : 10",					\
    "AMC_Build = INT : 0",						\
    "NChannels = INT : 16",						\
    "",									\
    "[Digitizer_6/General_Board_Registers]",				\
    "Register_0x8000 = DWORD : 0x000F0110",				\
    "Register_0x800C = DWORD : 0x0000000A",				\
    "Register_0x8100 = DWORD : 0x00000007",				\
    "Register_0x810C = DWORD : 0x80000000",				\
    "Register_0x8110 = DWORD : 0x0000FFFF",				\
    "Register_0x811C = DWORD : 0x00000D04",				\
    "Register_0x8138 = DWORD : 0x00000000",				\
    "Register_0x8144 = DWORD : 0x00000000",				\
    "Register_0x8170 = DWORD : 0x00000000",				\
    "Register_0x817C = DWORD : 0x00000000",				\
    "Register_0x81A0 = DWORD : 0x00000222",				\
    "Register_0xEF00 = DWORD : 0x00000010",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Trigger_Validation_Registers]", \
    "Register_0x8180 = DWORD : 0x20000000",				\
    "Register_0x8184 = DWORD : 0x20000000",				\
    "Register_0x8188 = DWORD : 0x20000000",				\
    "Register_0x818C = DWORD : 0x20000000",				\
    "Register_0x8190 = DWORD : 0x20000000",				\
    "Register_0x8194 = DWORD : 0x20000000",				\
    "Register_0x8198 = DWORD : 0x20000000",				\
    "Register_0x819C = DWORD : 0x20000000",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_0]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_0/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_0/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_1]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_1/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_1/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_2]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_2/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_2/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_3]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_3/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_3/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_4]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_4/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_4/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_5]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_5/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_5/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_6]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_6/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_6/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_7]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_7/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_7/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_8]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_8/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_8/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_9]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_9/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_9/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_10]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_10/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_10/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_11]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_11/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_11/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_12]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_12/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_12/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_13]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_13/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_13/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_14]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_14/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_14/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_15]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_15/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_6/CAEN_x725_x730_Settings/Channel_15/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_7]",							\
    "Comment = STRING : [64] VX1730B with DPP-PSD firmware 136.10",	\
    "Enabled = BOOL : y",						\
    "LinkType = STRING : [32] CAEN_DGTZ_PCIE_OpticalLink",		\
    "VMEBaseAddress = DWORD : 0",					\
    "LinkNum = INT : 3",						\
    "ConetNum = INT : 1",						\
    "AcqMode = STRING : [32] CAEN_DGTZ_DPP_ACQ_MODE_Mixed",		\
    "",									\
    "[Digitizer_7/Digitizer_Information]",				\
    "Type = STRING : [32] VX1730B",					\
    "Serial_Number = INT : 89",						\
    "ROC_Major_Version = INT : 4",					\
    "ROC_Minor_Version = INT : 11",					\
    "ROC_Build = INT : 0",						\
    "AMC_Major_Version = INT : 136",					\
    "AMC_Minor_Version = INT : 10",					\
    "AMC_Build = INT : 0",						\
    "NChannels = INT : 16",						\
    "",									\
    "[Digitizer_7/General_Board_Registers]",				\
    "Register_0x8000 = DWORD : 0x000F0110",				\
    "Register_0x800C = DWORD : 0x0000000A",				\
    "Register_0x8100 = DWORD : 0x00000007",				\
    "Register_0x810C = DWORD : 0x80000000",				\
    "Register_0x8110 = DWORD : 0x0000FFFF",				\
    "Register_0x811C = DWORD : 0x00000D04",				\
    "Register_0x8138 = DWORD : 0x00000000",				\
    "Register_0x8144 = DWORD : 0x00000000",				\
    "Register_0x8170 = DWORD : 0x00000000",				\
    "Register_0x817C = DWORD : 0x00000000",				\
    "Register_0x81A0 = DWORD : 0x00000222",				\
    "Register_0xEF00 = DWORD : 0x00000010",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Trigger_Validation_Registers]", \
    "Register_0x8180 = DWORD : 0x20000000",				\
    "Register_0x8184 = DWORD : 0x20000000",				\
    "Register_0x8188 = DWORD : 0x20000000",				\
    "Register_0x818C = DWORD : 0x20000000",				\
    "Register_0x8190 = DWORD : 0x20000000",				\
    "Register_0x8194 = DWORD : 0x20000000",				\
    "Register_0x8198 = DWORD : 0x20000000",				\
    "Register_0x819C = DWORD : 0x20000000",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_0]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_0/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_0/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_1]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_1/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_1/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_2]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_2/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_2/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_3]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_3/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_3/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_4]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_4/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_4/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_5]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_5/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_5/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_6]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_6/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_6/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_7]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_7/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_7/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_8]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_8/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_8/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_9]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_9/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_9/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_10]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_10/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_10/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_11]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_11/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_11/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_12]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_12/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_12/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_13]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_13/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_13/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_14]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_14/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_14/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_15]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_15/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_7/CAEN_x725_x730_Settings/Channel_15/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_8]",							\
    "Comment = STRING : [64] VX1730B with DPP-PSD firmware 136.10",	\
    "Enabled = BOOL : y",						\
    "LinkType = STRING : [32] CAEN_DGTZ_PCIE_OpticalLink",		\
    "VMEBaseAddress = DWORD : 0",					\
    "LinkNum = INT : 4",						\
    "ConetNum = INT : 0",						\
    "AcqMode = STRING : [32] CAEN_DGTZ_DPP_ACQ_MODE_Mixed",		\
    "",									\
    "[Digitizer_8/Digitizer_Information]",				\
    "Type = STRING : [32] VX1730B",					\
    "Serial_Number = INT : 89",						\
    "ROC_Major_Version = INT : 4",					\
    "ROC_Minor_Version = INT : 11",					\
     "ROC_Build = INT : 0",						\
   "AMC_Major_Version = INT : 136",					\
    "AMC_Minor_Version = INT : 10",					\
    "AMC_Build = INT : 0",						\
    "NChannels = INT : 16",						\
    "",									\
    "[Digitizer_8/General_Board_Registers]",				\
    "Register_0x8000 = DWORD : 0x000F0110",				\
    "Register_0x800C = DWORD : 0x0000000A",				\
    "Register_0x8100 = DWORD : 0x00000007",				\
    "Register_0x810C = DWORD : 0x80000000",				\
    "Register_0x8110 = DWORD : 0x0000FFFF",				\
    "Register_0x811C = DWORD : 0x00000D04",				\
    "Register_0x8138 = DWORD : 0x00000000",				\
    "Register_0x8144 = DWORD : 0x00000000",				\
    "Register_0x8170 = DWORD : 0x00000000",				\
    "Register_0x817C = DWORD : 0x00000000",				\
    "Register_0x81A0 = DWORD : 0x00000222",				\
    "Register_0xEF00 = DWORD : 0x00000010",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Trigger_Validation_Registers]", \
    "Register_0x8180 = DWORD : 0x20000000",				\
    "Register_0x8184 = DWORD : 0x20000000",				\
    "Register_0x8188 = DWORD : 0x20000000",				\
    "Register_0x818C = DWORD : 0x20000000",				\
    "Register_0x8190 = DWORD : 0x20000000",				\
    "Register_0x8194 = DWORD : 0x20000000",				\
    "Register_0x8198 = DWORD : 0x20000000",				\
    "Register_0x819C = DWORD : 0x20000000",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_0]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_0/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_0/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_1]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_1/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_1/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_2]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_2/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_2/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_3]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_3/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_3/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_4]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_4/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_4/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_5]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_5/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_5/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_6]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_6/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_6/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_7]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_7/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_7/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_8]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_8/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_8/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_9]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_9/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_9/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_10]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_10/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_10/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_11]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_11/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_11/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_12]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_12/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_12/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_13]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_13/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_13/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_14]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_14/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_14/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_15]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_15/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_8/CAEN_x725_x730_Settings/Channel_15/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_9]",							\
    "Comment = STRING : [64] VX1730B with DPP-PSD firmware 136.10",	\
    "Enabled = BOOL : y",						\
    "LinkType = STRING : [32] CAEN_DGTZ_PCIE_OpticalLink",		\
    "VMEBaseAddress = DWORD : 0",					\
    "LinkNum = INT : 4",						\
    "ConetNum = INT : 1",						\
    "AcqMode = STRING : [32] CAEN_DGTZ_DPP_ACQ_MODE_Mixed",		\
    "",									\
    "[Digitizer_9/Digitizer_Information]",				\
    "Type = STRING : [32] VX1730B",					\
    "Serial_Number = INT : 89",						\
    "ROC_Major_Version = INT : 4",					\
    "ROC_Minor_Version = INT : 11",					\
    "ROC_Build = INT : 0",						\
    "AMC_Major_Version = INT : 136",					\
    "AMC_Minor_Version = INT : 10",					\
    "AMC_Build = INT : 0",						\
    "NChannels = INT : 16",						\
    "",									\
    "[Digitizer_9/General_Board_Registers]",				\
    "Register_0x8000 = DWORD : 0x000F0110",				\
    "Register_0x800C = DWORD : 0x0000000A",				\
    "Register_0x8100 = DWORD : 0x00000007",				\
    "Register_0x810C = DWORD : 0x80000000",				\
    "Register_0x8110 = DWORD : 0x0000FFFF",				\
    "Register_0x811C = DWORD : 0x00000D04",				\
    "Register_0x8138 = DWORD : 0x00000000",				\
    "Register_0x8144 = DWORD : 0x00000000",				\
    "Register_0x8170 = DWORD : 0x00000000",				\
    "Register_0x817C = DWORD : 0x00000000",				\
    "Register_0x81A0 = DWORD : 0x00000222",				\
    "Register_0xEF00 = DWORD : 0x00000010",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Trigger_Validation_Registers]", \
    "Register_0x8180 = DWORD : 0x20000000",				\
    "Register_0x8184 = DWORD : 0x20000000",				\
    "Register_0x8188 = DWORD : 0x20000000",				\
    "Register_0x818C = DWORD : 0x20000000",				\
    "Register_0x8190 = DWORD : 0x20000000",				\
    "Register_0x8194 = DWORD : 0x20000000",				\
    "Register_0x8198 = DWORD : 0x20000000",				\
    "Register_0x819C = DWORD : 0x20000000",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_0]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_0/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_0/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_1]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_1/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_1/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_2]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_2/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_2/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_3]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_3/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_3/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_4]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_4/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_4/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_5]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_5/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_5/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_6]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_6/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_6/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_7]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_7/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_7/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_8]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_8/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_8/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_9]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_9/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_9/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_10]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_10/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_10/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_11]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_11/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_11/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_12]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_12/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_12/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_13]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_13/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_13/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_14]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_14/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_14/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_15]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_15/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_9/CAEN_x725_x730_Settings/Channel_15/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_10]",							\
    "Comment = STRING : [64] VX1730B with DPP-PSD firmware 136.10",	\
    "Enabled = BOOL : y",						\
    "LinkType = STRING : [32] CAEN_DGTZ_PCIE_OpticalLink",		\
    "VMEBaseAddress = DWORD : 0",					\
    "LinkNum = INT : 5",						\
    "ConetNum = INT : 0",						\
    "AcqMode = STRING : [32] CAEN_DGTZ_DPP_ACQ_MODE_Mixed",		\
    "",									\
    "[Digitizer_10/Digitizer_Information]",				\
    "Type = STRING : [32] VX1730B",					\
    "Serial_Number = INT : 89",						\
    "ROC_Major_Version = INT : 4",					\
    "ROC_Minor_Version = INT : 11",					\
    "ROC_Build = INT : 0",						\
    "AMC_Major_Version = INT : 136",					\
    "AMC_Minor_Version = INT : 10",					\
    "AMC_Build = INT : 0",						\
    "NChannels = INT : 16",						\
    "",									\
    "[Digitizer_10/General_Board_Registers]",				\
    "Register_0x8000 = DWORD : 0x000F0110",				\
    "Register_0x800C = DWORD : 0x00000009",				\
    "Register_0x8100 = DWORD : 0x00000007",				\
    "Register_0x810C = DWORD : 0x80000000",				\
    "Register_0x8110 = DWORD : 0x0000FFFF",				\
    "Register_0x811C = DWORD : 0x00000104",				\
    "Register_0x8138 = DWORD : 0x00000000",				\
    "Register_0x8144 = DWORD : 0x00000000",				\
    "Register_0x8170 = DWORD : 0x00000000",				\
    "Register_0x817C = DWORD : 0x00000000",				\
    "Register_0x81A0 = DWORD : 0x00000222",				\
    "Register_0xEF00 = DWORD : 0x00000010",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Trigger_Validation_Registers]", \
    "Register_0x8180 = DWORD : 0x20000000",				\
    "Register_0x8184 = DWORD : 0x20000000",				\
    "Register_0x8188 = DWORD : 0x20000000",				\
    "Register_0x818C = DWORD : 0x20000000",				\
    "Register_0x8190 = DWORD : 0x20000000",				\
    "Register_0x8194 = DWORD : 0x20000000",				\
    "Register_0x8198 = DWORD : 0x20000000",				\
    "Register_0x819C = DWORD : 0x20000000",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_0]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_0/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00210002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_0/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_1]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_1/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00210002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_1/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_2]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_2/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00210002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_2/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_3]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_3/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00210002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_3/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_4]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_4/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00210002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_4/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_5]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_5/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00210002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_5/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_6]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_6/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00210002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_6/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_7]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_7/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00210002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_7/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_8]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_8/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00210002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_8/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_9]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_9/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00210002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_9/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_10]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_10/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00210002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_10/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_11]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_11/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00210002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_11/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_12]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_12/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00210002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_12/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_13]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_13/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00210002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_13/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_14]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_14/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00210002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_14/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_15]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_15/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00210002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_10/CAEN_x725_x730_Settings/Channel_15/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_11]",							\
    "Comment = STRING : [64] VX1730B with DPP-PSD firmware 136.10",	\
    "Enabled = BOOL : y",						\
    "LinkType = STRING : [32] CAEN_DGTZ_PCIE_OpticalLink",		\
    "VMEBaseAddress = DWORD : 0",					\
    "LinkNum = INT : 5",						\
    "ConetNum = INT : 1",						\
    "AcqMode = STRING : [32] CAEN_DGTZ_DPP_ACQ_MODE_Mixed",		\
    "",									\
    "[Digitizer_11/Digitizer_Information]",				\
    "Type = STRING : [32] VX1730B",					\
    "Serial_Number = INT : 89",						\
    "ROC_Major_Version = INT : 4",					\
    "ROC_Minor_Version = INT : 11",					\
    "ROC_Build = INT : 0",						\
    "AMC_Major_Version = INT : 136",					\
    "AMC_Minor_Version = INT : 10",					\
    "AMC_Build = INT : 0",						\
    "NChannels = INT : 16",						\
    "",									\
    "[Digitizer_11/General_Board_Registers]",				\
    "Register_0x8000 = DWORD : 0x000F0110",				\
    "Register_0x800C = DWORD : 0x0000000A",				\
    "Register_0x8100 = DWORD : 0x00000007",				\
    "Register_0x810C = DWORD : 0x80000000",				\
    "Register_0x8110 = DWORD : 0x0000FFFF",				\
    "Register_0x811C = DWORD : 0x00000D04",				\
    "Register_0x8138 = DWORD : 0x00000000",				\
    "Register_0x8144 = DWORD : 0x00000000",				\
    "Register_0x8170 = DWORD : 0x00000000",				\
    "Register_0x817C = DWORD : 0x00000000",				\
    "Register_0x81A0 = DWORD : 0x00000222",				\
    "Register_0xEF00 = DWORD : 0x00000010",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Trigger_Validation_Registers]", \
    "Register_0x8180 = DWORD : 0x20000000",				\
    "Register_0x8184 = DWORD : 0x20000000",				\
    "Register_0x8188 = DWORD : 0x20000000",				\
    "Register_0x818C = DWORD : 0x20000000",				\
    "Register_0x8190 = DWORD : 0x20000000",				\
    "Register_0x8194 = DWORD : 0x20000000",				\
    "Register_0x8198 = DWORD : 0x20000000",				\
    "Register_0x819C = DWORD : 0x20000000",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_0]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_0/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_0/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_1]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_1/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_1/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_2]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_2/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_2/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_3]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_3/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_3/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_4]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_4/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_4/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_5]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_5/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_5/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_6]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_6/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_6/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_7]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_7/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_7/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_8]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_8/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_8/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_9]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_9/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_9/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_10]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_10/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_10/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_11]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_11/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_11/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_12]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_12/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_12/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_13]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_13/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_13/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_14]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_14/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_14/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_15]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_15/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_11/CAEN_x725_x730_Settings/Channel_15/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_12]",							\
    "Comment = STRING : [64] VX1730B with DPP-PSD firmware 136.10",	\
    "Enabled = BOOL : y",						\
    "LinkType = STRING : [32] CAEN_DGTZ_PCIE_OpticalLink",		\
    "VMEBaseAddress = DWORD : 0",					\
    "LinkNum = INT : 6",						\
    "ConetNum = INT : 0",						\
    "AcqMode = STRING : [32] CAEN_DGTZ_DPP_ACQ_MODE_Mixed",		\
    "",									\
    "[Digitizer_12/Digitizer_Information]",				\
    "Type = STRING : [32] VX1730B",					\
    "Serial_Number = INT : 89",						\
    "ROC_Major_Version = INT : 4",					\
    "ROC_Minor_Version = INT : 11",					\
    "ROC_Build = INT : 0",						\
    "AMC_Major_Version = INT : 136",					\
    "AMC_Minor_Version = INT : 10",					\
    "AMC_Build = INT : 0",						\
    "NChannels = INT : 16",						\
    "",									\
    "[Digitizer_12/General_Board_Registers]",				\
    "Register_0x8000 = DWORD : 0x000F0110",				\
    "Register_0x800C = DWORD : 0x0000000A",				\
    "Register_0x8100 = DWORD : 0x00000007",				\
    "Register_0x810C = DWORD : 0x80000000",				\
    "Register_0x8110 = DWORD : 0x0000FFFF",				\
    "Register_0x811C = DWORD : 0x00000D04",				\
    "Register_0x8138 = DWORD : 0x00000000",				\
    "Register_0x8144 = DWORD : 0x00000000",				\
    "Register_0x8170 = DWORD : 0x00000000",				\
    "Register_0x817C = DWORD : 0x00000000",				\
    "Register_0x81A0 = DWORD : 0x00000222",				\
    "Register_0xEF00 = DWORD : 0x00000010",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Trigger_Validation_Registers]", \
    "Register_0x8180 = DWORD : 0x20000000",				\
    "Register_0x8184 = DWORD : 0x20000000",				\
    "Register_0x8188 = DWORD : 0x20000000",				\
    "Register_0x818C = DWORD : 0x20000000",				\
    "Register_0x8190 = DWORD : 0x20000000",				\
    "Register_0x8194 = DWORD : 0x20000000",				\
    "Register_0x8198 = DWORD : 0x20000000",				\
    "Register_0x819C = DWORD : 0x20000000",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_0]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_0/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_0/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_1]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_1/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_1/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_2]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_2/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_2/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_3]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_3/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_3/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_4]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_4/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_4/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_5]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_5/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_5/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_6]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_6/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_6/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_7]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_7/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_7/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_8]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_8/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_8/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_9]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_9/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_9/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_10]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_10/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_10/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_11]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_11/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_11/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_12]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_12/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_12/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_13]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_13/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_13/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_14]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_14/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_14/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_15]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_15/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_12/CAEN_x725_x730_Settings/Channel_15/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 10",					\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_13]",							\
    "Comment = STRING : [64] VX1730B with DPP-PSD firmware 136.10",	\
    "Enabled = BOOL : y",						\
    "LinkType = STRING : [32] CAEN_DGTZ_PCIE_OpticalLink",		\
    "VMEBaseAddress = DWORD : 0",					\
    "LinkNum = INT : 6",						\
    "ConetNum = INT : 1",						\
    "AcqMode = STRING : [32] CAEN_DGTZ_DPP_ACQ_MODE_Mixed",		\
    "",									\
    "[Digitizer_13/Digitizer_Information]",				\
    "Type = STRING : [32] VX1730B",					\
    "Serial_Number = INT : 89",						\
    "ROC_Major_Version = INT : 4",					\
    "ROC_Minor_Version = INT : 11",					\
    "ROC_Build = INT : 0",						\
    "AMC_Major_Version = INT : 136",					\
    "AMC_Minor_Version = INT : 10",					\
    "AMC_Build = INT : 0",						\
    "NChannels = INT : 16",						\
    "",									\
    "[Digitizer_13/General_Board_Registers]",				\
    "Register_0x8000 = DWORD : 0x004F0115",				\
    "Register_0x800C = DWORD : 0x0000000A",				\
    "Register_0x8100 = DWORD : 0x00000007",				\
    "Register_0x810C = DWORD : 0x80000000",				\
    "Register_0x8110 = DWORD : 0x80000000",				\
    "Register_0x811C = DWORD : 0x00000D04",				\
    "Register_0x8138 = DWORD : 0x00000000",				\
    "Register_0x8144 = DWORD : 0x00000000",				\
    "Register_0x8170 = DWORD : 0x00000000",				\
    "Register_0x817C = DWORD : 0x00000000",				\
    "Register_0x81A0 = DWORD : 0x00000222",				\
    "Register_0xEF00 = DWORD : 0x00000010",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Trigger_Validation_Registers]", \
    "Register_0x8180 = DWORD : 0x20000000",				\
    "Register_0x8184 = DWORD : 0x20000000",				\
    "Register_0x8188 = DWORD : 0x20000000",				\
    "Register_0x818C = DWORD : 0x20000000",				\
    "Register_0x8190 = DWORD : 0x20000000",				\
    "Register_0x8194 = DWORD : 0x20000000",				\
    "Register_0x8198 = DWORD : 0x20000000",				\
    "Register_0x819C = DWORD : 0x20000000",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_0]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_0/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_0/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 0x00443014",				\
    "Register_0x1nA0 = DWORD : 10",					\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_1]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_1/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_1/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 0x00443014",				\
    "Register_0x1nA0 = DWORD : 0x00000004",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_2]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_2/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_2/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 0x00443014",				\
    "Register_0x1nA0 = DWORD : 0x00000004",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_3]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_3/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_3/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 0x00443014",				\
    "Register_0x1nA0 = DWORD : 0x00000004",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_4]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_4/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_4/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 0x00443014",				\
    "Register_0x1nA0 = DWORD : 0x00000004",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_5]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_5/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_5/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 0x00443014",				\
    "Register_0x1nA0 = DWORD : 0x00000004",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_6]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_6/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_6/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 0x00443014",				\
    "Register_0x1nA0 = DWORD : 0x00000004",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_7]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_7/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_7/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 0x00443014",				\
    "Register_0x1nA0 = DWORD : 0x00000004",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_8]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_8/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_8/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 0x00443014",				\
    "Register_0x1nA0 = DWORD : 0x00000004",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_9]",			\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_9/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_9/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 0x00443014",				\
    "Register_0x1nA0 = DWORD : 0x00000004",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_10]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_10/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_10/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 0x00443014",				\
    "Register_0x1nA0 = DWORD : 0x00000004",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_11]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_11/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_11/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 0x00443014",				\
    "Register_0x1nA0 = DWORD : 0x00000004",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_12]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_12/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_12/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 0x00443014",				\
    "Register_0x1nA0 = DWORD : 0x00000004",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_13]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_13/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_13/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 0x00443014",				\
    "Register_0x1nA0 = DWORD : 0x00000004",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_14]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_14/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_14/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 0x00443014",				\
    "Register_0x1nA0 = DWORD : 0x00000004",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_15]",		\
    "Enabled = BOOL : y",						\
    "PulsePolarity = STRING : [32] Negative",				\
    "ADC_Range = FLOAT : 2.0",						\
    "Trigger_Threshold = WORD : 114",					\
    "DC_Offset = WORD : 6553",						\
    "Waveform_Record_Length = WORD : 40",				\
    "Waveform_Pre-Trigger_Length = WORD : 16",				\
    "NEvents_per_Aggregate = WORD : 73",				\
    "Veto_Width = WORD : 0",						\
    "Veto_Width_Multiplier = WORD : 0",					\
    "Shaped_Trigger_Width = WORD : 4",					\
    "Trigger_Hold-Off_Width = WORD : 1",				\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_15/DPP_PSD_Params]",	\
    "Short_Gate = WORD : 11",						\
    "Long_Gate = WORD : 500",						\
    "Gate_Offset = WORD : 16",						\
    "Register_0x1n80 = DWORD : 0x00250002",				\
    "Register_0x1n84 = DWORD : 0x00004207",				\
    "Register_0x1n3C = DWORD : 0x00000210",				\
    "Charge_Zero_Suppression = WORD : 65535",				\
    "PSD_Threshold = WORD : 0",						\
    "PUR-GAP_Threshold = WORD : 0",					\
    "Fixed_Baseline = WORD : 0",					\
    "Baseline_Freeze = WORD : 2",					\
    "",									\
    "[Digitizer_13/CAEN_x725_x730_Settings/Channel_15/DPP_PHA_Params]",	\
    "TF_Rise_Time = WORD : 10",						\
    "TF_Flat_Time = WORD : 10",						\
    "Peaking_Time = WORD : 10",						\
    "Decay_Time = WORD : 10",						\
    "Fine_Gain = WORD : 10",						\
    "RC_CR2 = WORD : 10",						\
    "Input_Rise_Time = WORD : 10",					\
    "Rise_Time_Val_Win = WORD : 10",					\
    "Trigger_HoldOff = WORD : 10",					\
    "Peak_HoldOff = WORD : 10",						\
    "Register_0x1n80 = DWORD : 0x00443014",				\
    "Register_0x1nA0 = DWORD : 0x00000004",				\
    "",									\
    NULL }

#ifndef EXCL_DIGITIZER

#define DIGITIZER_COMMON_DEFINED

typedef struct {
  WORD      event_id;
  WORD      trigger_mask;
  char      buffer[32];
  INT       type;
  INT       source;
  char      format[8];
  BOOL      enabled;
  INT       read_on;
  INT       period;
  double    event_limit;
  DWORD     num_subevents;
  INT       log_history;
  char      frontend_host[32];
  char      frontend_name[32];
  char      frontend_file_name[256];
  char      status[256];
  char      status_color[32];
  BOOL      hidden;
} DIGITIZER_1COMMON;

#define DIGITIZER_COMMON_STR(_name) const char *_name[] = {		\
    "[.]",								\
    "Event ID = WORD : 1",						\
    "Trigger mask = WORD : 0",						\
    "Buffer = STRING : [32] SYSTEM",					\
    "Type = INT : 2",							\
    "Source = INT : 0",							\
    "Format = STRING : [8] MIDAS",					\
    "Enabled = BOOL : y",						\
    "Read on = INT : 1",						\
    "Period = INT : 50",						\
    "Event limit = DOUBLE : 0",						\
    "Num subevents = DWORD : 0",					\
    "Log history = INT : 0",						\
    "Frontend host = STRING : [32] localhost",				\
    "Frontend name = STRING : [32] caen2018 VX1730 Frontend",		\
    "Frontend file name = STRING : [256] caen2018_dpp_frontend.cpp",	\
    "Status = STRING : [256] caen2018 VX1730 Frontend@localhost",	\
    "Status color = STRING : [32] greenLight",				\
    "Hidden = BOOL : n",						\
    "",									\
    NULL }

#endif

#ifndef EXCL_DIAGNOSTICS

#define DIAGNOSTICS_COMMON_DEFINED

typedef struct {
  WORD      event_id;
  WORD      trigger_mask;
  char      buffer[32];
  INT       type;
  INT       source;
  char      format[8];
  BOOL      enabled;
  INT       read_on;
  INT       period;
  double    event_limit;
  DWORD     num_subevents;
  INT       log_history;
  char      frontend_host[32];
  char      frontend_name[32];
  char      frontend_file_name[256];
  char      status[256];
  char      status_color[32];
  BOOL      hidden;
} DIAGNOSTICS_COMMON;

#define DIAGNOSTICS_COMMON_STR(_name) const char *_name[] = {		\
    "[.]",								\
    "Event ID = WORD : 8",						\
    "Trigger mask = WORD : 0",						\
    "Buffer = STRING : [32] SYSTEM",					\
    "Type = INT : 1",							\
    "Source = INT : 0",							\
    "Format = STRING : [8] MIDAS",					\
    "Enabled = BOOL : y",						\
    "Read on = INT : 121",						\
    "Period = INT : 10000",						\
    "Event limit = DOUBLE : 0",						\
    "Num subevents = DWORD : 0",					\
    "Log history = INT : 0",						\
    "Frontend host = STRING : [32] localhost",				\
    "Frontend name = STRING : [32] caen2018 VX1730 Frontend",		\
    "Frontend file name = STRING : [256] caen2018_dpp_frontend.cpp",	\
    "Status = STRING : [256] caen2018 VX1730 Frontend@localhost",	\
    "Status color = STRING : [32] greenLight",				\
    "Hidden = BOOL : n",						\
    "",									\
    NULL }

#endif

