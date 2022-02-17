/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Calibration_2020a.c
 *
 * Code generated for Simulink model 'Calibration_2020a'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Feb 15 17:49:35 2022
 *
 * Target selection: MPC5644A.tlc
 * Embedded hardware selection: Freescale->MPC55xx
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Calibration_2020a.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Exported data definition */
#define PUSH__MP
#include "EcoSectionDef.h"

/* Definition for custom storage class: Measurement */
__MP boolean_T PwrM_flgKeyOnDelay;     /* '<S14>/debounce' */
__MP boolean_T PwrM_flgKeyOnRaw;       /* '<S7>/Switch' */
__MP real32_T tension2;                /* '<S31>/Gain' */
__MP uint16_T tension3;                /* '<S30>/Read ADC Value' */

#define POP__MP
#include "EcoSectionDef.h"

/* Block signals (default storage) */
B B_n;

/* Block states (default storage) */
DW DW_l;

/* Previous zero-crossings (trigger) states */
PrevZCX PrevZCX_p;

/* Real-time model */
RT_MODEL M_;
RT_MODEL *const M = &M_;
void Calibration_2020a_step0(void);
void Calibration_2020a_step1(void);
void Calibration_2020a_step2(void);
void Calibration_2020a_step3(void);
void Calibration_2020a_step4(void);
void Calibration_2020a_step5(void);
void Calibration_2020a_step6(void);
void Calibration_2020a_step7(void);
void Calibration_2020a_step8(void);
uint8_T EcoCoder_Target_Setting;

/* Model step function for TID0 */
void Calibration_2020a_step0(void)     /* Sample time: [0.001s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void Calibration_2020a_step1(void)     /* Sample time: [0.005s, 0.0s] */
{
  /* S-Function (EcoCoder_Task): '<S2>/Task_Call1' */

  /* -- Call CAN RX Fcn-Call_0 -- */

  /* Output and update for function-call system: '<S2>/Power Off Management' */
  {
    boolean_T UnitDelay7;
    boolean_T UnitDelay1_h;
    real_T MinMax1_o;
    boolean_T LogicalOperator_n;
    boolean_T LogicalOperator1_g;
    uint32_T PowerOffManagement_ELAPS_T;
    uint32_T PowerOffManagement_ELAPS_T_tmp_;

    /* Outputs for Enabled SubSystem: '<S5>/KeyCycle' incorporates:
     *  EnablePort: '<S8>/Enable'
     */
    PowerOffManagement_ELAPS_T_tmp_ = M->Timing.clockTick1;

    /* End of Outputs for SubSystem: '<S5>/KeyCycle' */
    PowerOffManagement_ELAPS_T = PowerOffManagement_ELAPS_T_tmp_ -
      DW_l.PowerOffManagement_PREV_T;
    DW_l.PowerOffManagement_PREV_T = PowerOffManagement_ELAPS_T_tmp_;

    /* UnitDelay: '<S5>/Unit Delay7' */
    UnitDelay7 = DW_l.UnitDelay7_DSTATE;

    /* Logic: '<S14>/Logical Operator2' incorporates:
     *  Logic: '<S5>/Logical Operator'
     *  UnitDelay: '<S5>/Unit Delay7'
     */
    UnitDelay1_h = !DW_l.UnitDelay7_DSTATE;

    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S5>/Parameter'
     *  Logic: '<S14>/Logical Operator2'
     *  Logic: '<S14>/Logical Operator5'
     *  RelationalOperator: '<S14>/edge'
     *  Sum: '<S27>/Sum1'
     *  UnitDelay: '<S14>/Unit Delay'
     *  UnitDelay: '<S27>/Unit Delay'
     *  UnitDelay: '<S5>/Unit Delay7'
     */
    if ((DW_l.UnitDelay7_DSTATE != DW_l.UnitDelay_DSTATE_n) && UnitDelay1_h) {
      DW_l.UnitDelay_DSTATE = 0.5;
    } else {
      /* SampleTimeMath: '<S28>/sample time1'
       *
       * About '<S28>/sample time1':
       *  y = K where K = ( w * Ts )
       */
      MinMax1_o = (real_T)PowerOffManagement_ELAPS_T * 0.005;

      /* MinMax: '<S28>/MinMax' */
      if (0.001 > MinMax1_o) {
        MinMax1_o = 0.001;
      }

      /* End of MinMax: '<S28>/MinMax' */
      DW_l.UnitDelay_DSTATE -= MinMax1_o;
    }

    /* End of Switch: '<S27>/Switch' */

    /* MinMax: '<S27>/MinMax1' */
    if (0.5 < DW_l.UnitDelay_DSTATE) {
      DW_l.UnitDelay_DSTATE = 0.5;
    }

    /* End of MinMax: '<S27>/MinMax1' */

    /* MinMax: '<S27>/MinMax' */
    if (DW_l.UnitDelay_DSTATE > 0.0) {
    } else {
      DW_l.UnitDelay_DSTATE = 0.0;
    }

    /* End of MinMax: '<S27>/MinMax' */

    /* Switch: '<S14>/debounce' incorporates:
     *  Constant: '<S27>/Constant2'
     *  RelationalOperator: '<S27>/Relational Operator2'
     *  UnitDelay: '<S14>/Unit Delay1'
     *  UnitDelay: '<S27>/Unit Delay'
     *  UnitDelay: '<S5>/Unit Delay7'
     */
    if (DW_l.UnitDelay_DSTATE == 0.0) {
      PwrM_flgKeyOnDelay = DW_l.UnitDelay7_DSTATE;
    } else {
      PwrM_flgKeyOnDelay = DW_l.UnitDelay1_DSTATE;
    }

    /* End of Switch: '<S14>/debounce' */

    /* Outputs for Enabled SubSystem: '<S5>/KeyCycle' incorporates:
     *  EnablePort: '<S8>/Enable'
     */
    if (PwrM_flgKeyOnDelay) {
      PowerOffManagement_ELAPS_T = PowerOffManagement_ELAPS_T_tmp_ -
        DW_l.KeyCycle_PREV_T;
      DW_l.KeyCycle_PREV_T = PowerOffManagement_ELAPS_T_tmp_;

      /* Switch: '<S23>/Switch' incorporates:
       *  Constant: '<S5>/Parameter3'
       *  Logic: '<S21>/Logical Operator2'
       *  Logic: '<S21>/Logical Operator5'
       *  RelationalOperator: '<S21>/edge'
       *  Sum: '<S23>/Sum1'
       *  UnitDelay: '<S21>/Unit Delay'
       *  UnitDelay: '<S23>/Unit Delay'
       */
      if ((UnitDelay1_h != DW_l.UnitDelay_DSTATE_o) && (!UnitDelay1_h)) {
        MinMax1_o = 0.1;
      } else {
        /* SampleTimeMath: '<S24>/sample time1'
         *
         * About '<S24>/sample time1':
         *  y = K where K = ( w * Ts )
         */
        MinMax1_o = (real_T)PowerOffManagement_ELAPS_T * 0.005;

        /* MinMax: '<S24>/MinMax' */
        if (0.001 > MinMax1_o) {
          MinMax1_o = 0.001;
        }

        /* End of MinMax: '<S24>/MinMax' */
        MinMax1_o = DW_l.UnitDelay_DSTATE_h - MinMax1_o;
      }

      /* End of Switch: '<S23>/Switch' */

      /* MinMax: '<S23>/MinMax1' */
      if (0.1 < MinMax1_o) {
        MinMax1_o = 0.1;
      }

      /* End of MinMax: '<S23>/MinMax1' */

      /* MinMax: '<S23>/MinMax' */
      if (MinMax1_o > 0.0) {
        DW_l.UnitDelay_DSTATE_h = MinMax1_o;
      } else {
        DW_l.UnitDelay_DSTATE_h = 0.0;
      }

      /* End of MinMax: '<S23>/MinMax' */

      /* Switch: '<S21>/debounce' incorporates:
       *  Constant: '<S23>/Constant2'
       *  RelationalOperator: '<S23>/Relational Operator2'
       *  UnitDelay: '<S21>/Unit Delay1'
       *  UnitDelay: '<S23>/Unit Delay'
       */
      if (DW_l.UnitDelay_DSTATE_h == 0.0) {
        DW_l.UnitDelay1_DSTATE_n = UnitDelay1_h;
      }

      /* End of Switch: '<S21>/debounce' */

      /* Switch: '<S25>/Switch' incorporates:
       *  Constant: '<S5>/Parameter2'
       *  Logic: '<S22>/Logical Operator5'
       *  RelationalOperator: '<S22>/edge'
       *  Sum: '<S25>/Sum1'
       *  UnitDelay: '<S22>/Unit Delay'
       *  UnitDelay: '<S25>/Unit Delay'
       */
      if ((UnitDelay1_h != DW_l.UnitDelay_DSTATE_na) && UnitDelay1_h) {
        MinMax1_o = 0.1;
      } else {
        /* SampleTimeMath: '<S26>/sample time1'
         *
         * About '<S26>/sample time1':
         *  y = K where K = ( w * Ts )
         */
        MinMax1_o = (real_T)PowerOffManagement_ELAPS_T * 0.005;

        /* MinMax: '<S26>/MinMax' */
        if (0.001 > MinMax1_o) {
          MinMax1_o = 0.001;
        }

        /* End of MinMax: '<S26>/MinMax' */
        MinMax1_o = DW_l.UnitDelay_DSTATE_d - MinMax1_o;
      }

      /* End of Switch: '<S25>/Switch' */

      /* MinMax: '<S25>/MinMax1' */
      if (0.1 < MinMax1_o) {
        MinMax1_o = 0.1;
      }

      /* End of MinMax: '<S25>/MinMax1' */

      /* MinMax: '<S25>/MinMax' */
      if (MinMax1_o > 0.0) {
        DW_l.UnitDelay_DSTATE_d = MinMax1_o;
      } else {
        DW_l.UnitDelay_DSTATE_d = 0.0;
      }

      /* End of MinMax: '<S25>/MinMax' */

      /* Switch: '<S22>/debounce' incorporates:
       *  Constant: '<S25>/Constant2'
       *  RelationalOperator: '<S25>/Relational Operator2'
       *  UnitDelay: '<S22>/Unit Delay1'
       *  UnitDelay: '<S25>/Unit Delay'
       */
      if (DW_l.UnitDelay_DSTATE_d == 0.0) {
        DW_l.UnitDelay1_DSTATE_j = UnitDelay1_h;
      }

      /* End of Switch: '<S22>/debounce' */

      /* Outputs for Atomic SubSystem: '<S8>/ER_xxxx' */
      /* Logic: '<S17>/Logical Operator' incorporates:
       *  Logic: '<S17>/Logical Operator1'
       *  UnitDelay: '<S17>/Unit Delay'
       *  UnitDelay: '<S22>/Unit Delay1'
       */
      LogicalOperator_n = (DW_l.UnitDelay1_DSTATE_j && (!DW_l.UnitDelay_DSTATE_k));

      /* Update for UnitDelay: '<S17>/Unit Delay' incorporates:
       *  UnitDelay: '<S22>/Unit Delay1'
       */
      DW_l.UnitDelay_DSTATE_k = DW_l.UnitDelay1_DSTATE_j;

      /* End of Outputs for SubSystem: '<S8>/ER_xxxx' */

      /* Outputs for Atomic SubSystem: '<S8>/ER_xxxx1' */
      /* Logic: '<S18>/Logical Operator1' incorporates:
       *  UnitDelay: '<S18>/Unit Delay'
       */
      LogicalOperator1_g = !DW_l.UnitDelay_DSTATE_m;

      /* Update for UnitDelay: '<S18>/Unit Delay' */
      DW_l.UnitDelay_DSTATE_m = UnitDelay1_h;

      /* Outputs for Atomic SubSystem: '<S8>/RSFF_xxxx' */
      /* Switch: '<S19>/Switch' incorporates:
       *  Constant: '<S19>/Constant2'
       *  Logic: '<S18>/Logical Operator'
       *  Switch: '<S19>/Switch1'
       *  UnitDelay: '<S19>/Unit Delay1'
       */
      if (UnitDelay1_h && LogicalOperator1_g) {
        DW_l.UnitDelay1_DSTATE_i = false;
      } else {
        DW_l.UnitDelay1_DSTATE_i = (LogicalOperator_n ||
          DW_l.UnitDelay1_DSTATE_i);
      }

      /* End of Switch: '<S19>/Switch' */
      /* End of Outputs for SubSystem: '<S8>/RSFF_xxxx' */
      /* End of Outputs for SubSystem: '<S8>/ER_xxxx1' */

      /* Logic: '<S8>/LogicAND1' incorporates:
       *  Logic: '<S8>/LogicAND'
       *  Logic: '<S8>/LogicNOT'
       *  UnitDelay: '<S19>/Unit Delay1'
       *  UnitDelay: '<S21>/Unit Delay1'
       */
      B_n.LogicAND1 = ((!DW_l.UnitDelay1_DSTATE_n) && DW_l.UnitDelay1_DSTATE_i);

      /* If: '<S8>/If2' */
      if (B_n.LogicAND1) {
        /* Outputs for IfAction SubSystem: '<S8>/Reset_Action' incorporates:
         *  ActionPort: '<S20>/Action Port'
         */
        /* S-Function (ResetSW): '<S20>/ResetSW' */
        if (true==B_n.LogicAND1) {
          F_Abstr_SoftReset();
        }

        /* End of Outputs for SubSystem: '<S8>/Reset_Action' */
      }

      /* End of If: '<S8>/If2' */

      /* Update for UnitDelay: '<S21>/Unit Delay' */
      DW_l.UnitDelay_DSTATE_o = UnitDelay1_h;

      /* Update for UnitDelay: '<S22>/Unit Delay' */
      DW_l.UnitDelay_DSTATE_na = UnitDelay1_h;
    }

    /* End of Outputs for SubSystem: '<S5>/KeyCycle' */

    /* UnitDelay: '<S5>/Unit Delay1' */
    UnitDelay1_h = DW_l.UnitDelay1_DSTATE_g;

    /* Outputs for Triggered SubSystem: '<S5>/Shutdown Power' incorporates:
     *  TriggerPort: '<S9>/Trigger'
     */
    /* Logic: '<S5>/Logical Operator6' */
    LogicalOperator_n = !UnitDelay1_h;
    if (LogicalOperator_n && (PrevZCX_p.ShutdownPower_Trig_ZCE != 0)) {
      /* S-Function (ecocoder_power_shutdwn): '<S9>/Shutdown Power' */
      F_Abstr_Power_Turn(ABS_Power_PWR12V,0);
    }

    PrevZCX_p.ShutdownPower_Trig_ZCE = UnitDelay1_h;

    /* End of Outputs for SubSystem: '<S5>/Shutdown Power' */

    /* Logic: '<S5>/Logical Operator2' incorporates:
     *  Logic: '<S5>/Logical Operator3'
     *  Logic: '<S5>/Logical Operator5'
     *  Logic: '<S5>/Logical Operator7'
     *  UnitDelay: '<S5>/Unit Delay3'
     *  UnitDelay: '<S5>/Unit Delay4'
     */
    LogicalOperator_n = ((!DW_l.UnitDelay3_DSTATE) && LogicalOperator_n &&
                         (!PwrM_flgKeyOnDelay) && (!DW_l.UnitDelay4_DSTATE));

    /* Outputs for Enabled SubSystem: '<S5>/Shutdown Power Hold' incorporates:
     *  EnablePort: '<S10>/Enable'
     */
    if (LogicalOperator_n) {
      /* S-Function (ecocoder_power_shutdwn): '<S10>/Shutdown Power' */
      F_Abstr_Power_Turn(ABS_Power_PWR12V,0);
    }

    /* End of Outputs for SubSystem: '<S5>/Shutdown Power Hold' */

    /* Outputs for Triggered SubSystem: '<S5>/Software Reset' incorporates:
     *  TriggerPort: '<S11>/Trigger'
     */
    if (PrevZCX_p.SoftwareReset_Trig_ZCE != 0) {
      /* S-Function (ResetSW): '<S11>/ResetSW' incorporates:
       *  Constant: '<S11>/Constant'
       */
      if (true==true) {
        F_Abstr_SoftReset();
      }
    }

    PrevZCX_p.SoftwareReset_Trig_ZCE = 0U;

    /* End of Outputs for SubSystem: '<S5>/Software Reset' */

    /* Outputs for Triggered SubSystem: '<S5>/Store All NVM Data' incorporates:
     *  TriggerPort: '<S13>/Trigger'
     */
    /* Logic: '<S5>/Logical Operator4' */
    if ((!PwrM_flgKeyOnDelay) && (PrevZCX_p.StoreAllNVMData_Trig_ZCE != 0)) {
      /* S-Function (WriteBackData): '<S13>/Store NVM Data1' incorporates:
       *  Constant: '<S13>/Constant'
       */
      if (true==true) {
        F_Abstr_MemRam2Nvm();
      }
    }

    PrevZCX_p.StoreAllNVMData_Trig_ZCE = PwrM_flgKeyOnDelay;

    /* End of Logic: '<S5>/Logical Operator4' */
    /* End of Outputs for SubSystem: '<S5>/Store All NVM Data' */

    /* S-Function (DI_Key_In): '<S7>/SwitchInput_ReadKeyOn' */
    B_n.SwitchInput_ReadKeyOn= F_Abstr_DI_GetValue(ABS_DI_KEYON);

    /* Switch: '<S7>/Switch' */
    PwrM_flgKeyOnRaw = B_n.SwitchInput_ReadKeyOn;

    /* Update for UnitDelay: '<S5>/Unit Delay7' */
    DW_l.UnitDelay7_DSTATE = PwrM_flgKeyOnRaw;

    /* Update for UnitDelay: '<S14>/Unit Delay' */
    DW_l.UnitDelay_DSTATE_n = UnitDelay7;

    /* Update for UnitDelay: '<S14>/Unit Delay1' */
    DW_l.UnitDelay1_DSTATE = PwrM_flgKeyOnDelay;

    /* Update for UnitDelay: '<S5>/Unit Delay1' */
    DW_l.UnitDelay1_DSTATE_g = PwrM_flgKeyOnDelay;

    /* Update for UnitDelay: '<S5>/Unit Delay3' */
    DW_l.UnitDelay3_DSTATE = UnitDelay1_h;

    /* Update for UnitDelay: '<S5>/Unit Delay4' incorporates:
     *  UnitDelay: '<S5>/Unit Delay5'
     */
    DW_l.UnitDelay4_DSTATE = DW_l.UnitDelay5_DSTATE;

    /* Update for UnitDelay: '<S5>/Unit Delay2' */
    DW_l.UnitDelay2_DSTATE = LogicalOperator_n;

    /* Update for UnitDelay: '<S5>/Unit Delay5' incorporates:
     *  UnitDelay: '<S5>/Unit Delay6'
     */
    DW_l.UnitDelay5_DSTATE = DW_l.UnitDelay6_DSTATE;

    /* Update for UnitDelay: '<S5>/Unit Delay6' */
    DW_l.UnitDelay6_DSTATE = UnitDelay7;
  }

  /* End of Outputs for S-Function (EcoCoder_Task): '<S2>/Task_Call1' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void Calibration_2020a_step2(void)     /* Sample time: [0.01s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID3 */
void Calibration_2020a_step3(void)     /* Sample time: [0.02s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID4 */
void Calibration_2020a_step4(void)     /* Sample time: [0.05s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID5 */
void Calibration_2020a_step5(void)     /* Sample time: [0.1s, 0.0s] */
{
  /* S-Function (EcoCoder_Task): '<S3>/Task Trigger' */

  /* -- Call CAN RX Fcn-Call_0 -- */

  /* Output and update for function-call system: '<S3>/Subsystem' */

  /* S-Function (ADC): '<S30>/Read ADC Value' */
  tension3 = F_Abstr_ADC_GetValue(ABS_ADC_19);

  /* S-Function (ADC): '<S31>/ADC2Volt' */
  B_n.ADC2Volt = F_Abstr_ADC_GetValue(ABS_ADC_19);

  /* Gain: '<S31>/Gain' */
  tension2 = 0.00122100115F * (real32_T)B_n.ADC2Volt;

  /* End of Outputs for S-Function (EcoCoder_Task): '<S3>/Task Trigger' */
}

/* Model step function for TID6 */
void Calibration_2020a_step6(void)     /* Sample time: [0.2s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID7 */
void Calibration_2020a_step7(void)     /* Sample time: [0.5s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID8 */
void Calibration_2020a_step8(void)     /* Sample time: [1.0s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step wrapper function for compatibility with a static main program */
void Calibration_2020a_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Calibration_2020a_step0();
    break;

   case 1 :
    Calibration_2020a_step1();
    break;

   case 2 :
    Calibration_2020a_step2();
    break;

   case 3 :
    Calibration_2020a_step3();
    break;

   case 4 :
    Calibration_2020a_step4();
    break;

   case 5 :
    Calibration_2020a_step5();
    break;

   case 6 :
    Calibration_2020a_step6();
    break;

   case 7 :
    Calibration_2020a_step7();
    break;

   case 8 :
    Calibration_2020a_step8();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Calibration_2020a_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)M, 0,
                sizeof(RT_MODEL));
  (M)->Timing.TaskCounters.cLimit[0] = 1;
  (M)->Timing.TaskCounters.cLimit[1] = 5;
  (M)->Timing.TaskCounters.cLimit[2] = 10;
  (M)->Timing.TaskCounters.cLimit[3] = 20;
  (M)->Timing.TaskCounters.cLimit[4] = 50;
  (M)->Timing.TaskCounters.cLimit[5] = 100;
  (M)->Timing.TaskCounters.cLimit[6] = 200;
  (M)->Timing.TaskCounters.cLimit[7] = 500;
  (M)->Timing.TaskCounters.cLimit[8] = 1000;

  /* block I/O */
  (void) memset(((void *) &B_n), 0,
                sizeof(B));

  /* states (dwork) */
  (void) memset((void *)&DW_l, 0,
                sizeof(DW));

  /* Start for S-Function (EcoCoder_Task): '<S2>/Task_Call' */

  /* -- Call CAN RX Fcn-Call_0 -- */

  /* Output and update for function-call system: '<S2>/Power On Init' */

  /* Outputs for Enabled SubSystem: '<S6>/Restore NVM Data' incorporates:
   *  EnablePort: '<S29>/Enable'
   */
  /* Logic: '<S29>/Logical Operator' incorporates:
   *  Logic: '<S29>/LogicNOT1'
   *  UnitDelay: '<S29>/Unit Delay'
   */
  B_n.LogicalOperator_e = !DW_l.UnitDelay_DSTATE_g;

  /* S-Function (WriteBackData): '<S29>/Restore NVM Data' */
  if (true==B_n.LogicalOperator_e) {
    F_Abstr_MemNvm2Ram();
  }

  /* Update for UnitDelay: '<S29>/Unit Delay' incorporates:
   *  Constant: '<S29>/Constant'
   */
  DW_l.UnitDelay_DSTATE_g = true;

  /* End of Outputs for SubSystem: '<S6>/Restore NVM Data' */

  /* End of Start for S-Function (EcoCoder_Task): '<S2>/Task_Call' */

  /* Start for S-Function (EcoCoder_Task): '<S1>/Task Trigger' */

  /* -- Call CAN RX Fcn-Call_0 -- */

  /* End of Start for S-Function (EcoCoder_Task): '<S1>/Task Trigger' */

  /* Start for S-Function (EcoCoder_Task): '<S2>/Task_Call1' incorporates:
   *  SubSystem: '<S2>/Power Off Management'
   */

  /* Start for function-call system: '<S2>/Power Off Management' */

  /* Start for S-Function (DI_Key_In): '<S7>/SwitchInput_ReadKeyOn' */
  F_Abstr_DI_InitChannel(ABS_DI_KEYON);

  /* End of Start for S-Function (EcoCoder_Task): '<S2>/Task_Call1' */

  /* Start for S-Function (EcoCoder_Task): '<S3>/Task Trigger' incorporates:
   *  SubSystem: '<S3>/Subsystem'
   */

  /* Start for function-call system: '<S3>/Subsystem' */

  /* Start for S-Function (ADC): '<S30>/Read ADC Value' */
  F_Abstr_ADC_InitChannel(ABS_ADC_19);

  /* Start for S-Function (ADC): '<S31>/ADC2Volt' */
  F_Abstr_ADC_InitChannel(ABS_ADC_19);

  /* End of Start for S-Function (EcoCoder_Task): '<S3>/Task Trigger' */
  PrevZCX_p.ShutdownPower_Trig_ZCE = ZERO_ZCSIG;
  PrevZCX_p.SoftwareReset_Trig_ZCE = ZERO_ZCSIG;
  PrevZCX_p.StoreAllNVMData_Trig_ZCE = ZERO_ZCSIG;

  /* SystemInitialize for S-Function (EcoCoder_Task): '<S2>/Task_Call1' incorporates:
   *  SubSystem: '<S2>/Power Off Management'
   */

  /* System initialize for function-call system: '<S2>/Power Off Management' */
  DW_l.PowerOffManagement_PREV_T = M->Timing.clockTick1;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay7' */
  DW_l.UnitDelay7_DSTATE = true;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay4' */
  DW_l.UnitDelay4_DSTATE = true;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay5' */
  DW_l.UnitDelay5_DSTATE = true;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay6' */
  DW_l.UnitDelay6_DSTATE = true;

  /* SystemInitialize for Enabled SubSystem: '<S5>/KeyCycle' */
  /* SystemInitialize for Atomic SubSystem: '<S8>/ER_xxxx' */
  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
  DW_l.UnitDelay_DSTATE_k = true;

  /* End of SystemInitialize for SubSystem: '<S8>/ER_xxxx' */

  /* SystemInitialize for Atomic SubSystem: '<S8>/ER_xxxx1' */
  /* InitializeConditions for UnitDelay: '<S18>/Unit Delay' */
  DW_l.UnitDelay_DSTATE_m = true;

  /* End of SystemInitialize for SubSystem: '<S8>/ER_xxxx1' */
  /* End of SystemInitialize for SubSystem: '<S5>/KeyCycle' */

  /* End of SystemInitialize for S-Function (EcoCoder_Task): '<S2>/Task_Call1' */
}

#define PUSH__RWP
#include "EcoSectionDef.h"

__RWP const volatile uint8_T EcoCoder_dataCheckeEn1_val = 0x11;
__RWP const volatile uint8_T EcoCoder_dataCheckeEn2_val = 0x22;
__RWP const volatile uint8_T EcoCoder_dataCheckeEn3_val = 0x33;
__RWP const volatile uint8_T EcoCoder_dataCheckeEn4_val = 0x44;
__RWP const volatile uint8_T EcoCoder_dataCheckeEn5_val = 0x55;
__RWP const volatile uint8_T EcoCoder_dataCheckeEn6_val = 0x66;
__RWP const volatile uint8_T EcoCoder_dataCheckeEn7_val = 0x77;
__RWP const volatile uint8_T EcoCoder_dataCheckeEn8_val = 0x88;

#define POP__RWP
#include "EcoSectionDef.h"

uint8_T EcoCoder_CAB_ChecheFailedWhile(void)
{
  uint8_T iLLDCAL_T= 0;
  iLLDCAL_T= ((0x11!=EcoCoder_dataCheckeEn1_val)||(0x22!=
    EcoCoder_dataCheckeEn2_val)||(0x33!=EcoCoder_dataCheckeEn3_val)||(0x44!=
    EcoCoder_dataCheckeEn4_val)||(0x55!=EcoCoder_dataCheckeEn5_val)||(0x66!=
    EcoCoder_dataCheckeEn6_val)||(0x77!=EcoCoder_dataCheckeEn7_val)||(0x88!=
    EcoCoder_dataCheckeEn8_val));

#ifdef ECO_CAB_DATA_CHECKE_EN

  while (iLLDCAL_T) {
    EcoCoder_CAB_ChecheFailedCALL();
  }

#endif

  return iLLDCAL_T;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
