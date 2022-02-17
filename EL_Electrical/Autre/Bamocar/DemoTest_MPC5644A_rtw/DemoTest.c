/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DemoTest.c
 *
 * Code generated for Simulink model 'DemoTest'.
 *
 * Model version                  : 1.1491
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Feb  3 17:32:00 2022
 *
 * Target selection: MPC5644A.tlc
 * Embedded hardware selection: Freescale->MPC55xx
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DemoTest.h"

/* Exported data definition */
#define PUSH__MP
#include "EcoSectionDef.h"

/* Definition for custom storage class: Measurement */
__MP boolean_T PwrM_flgKeyOnDelay;     /* '<S13>/debounce' */
__MP boolean_T PwrM_flgKeyOnRaw;       /* '<S6>/Switch' */

#define POP__MP
#include "EcoSectionDef.h"

/* Block signals (default storage) */
BlockIO B;

/* Block states (default storage) */
D_Work DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates PrevZCSigState;

/* Real-time model */
RT_MODEL M_;
RT_MODEL *const M = &M_;
void DemoTest_step0(void);
void DemoTest_step1(void);
void DemoTest_step2(void);
void DemoTest_step3(void);
void DemoTest_step4(void);
void DemoTest_step5(void);
void DemoTest_step6(void);
void DemoTest_step7(void);
void DemoTest_step8(void);
uint8_T EcoCoder_Target_Setting;

/* Model step function for TID0 */
void DemoTest_step0(void)              /* Sample time: [0.001s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void DemoTest_step1(void)              /* Sample time: [0.005s, 0.0s] */
{
  /* S-Function (EcoCoder_Task): '<S2>/Task_Call1' */

  /* -- Call CAN RX Fcn-Call_0 -- */

  /* Output and update for function-call system: '<S2>/Power Off Management' */
  {
    boolean_T UnitDelay7;
    boolean_T UnitDelay1_o;
    real_T MinMax1_j;
    boolean_T LogicalOperator_k;
    boolean_T LogicalOperator1_m;
    uint32_T PowerOffManagement_ELAPS_T;
    uint32_T PowerOffManagement_ELAPS_T_tmp_;

    /* Outputs for Enabled SubSystem: '<S4>/KeyCycle' incorporates:
     *  EnablePort: '<S7>/Enable'
     */
    PowerOffManagement_ELAPS_T_tmp_ = M->Timing.clockTick1;

    /* End of Outputs for SubSystem: '<S4>/KeyCycle' */
    PowerOffManagement_ELAPS_T = PowerOffManagement_ELAPS_T_tmp_ -
      DWork.PowerOffManagement_PREV_T;
    DWork.PowerOffManagement_PREV_T = PowerOffManagement_ELAPS_T_tmp_;

    /* UnitDelay: '<S4>/Unit Delay7' */
    UnitDelay7 = DWork.UnitDelay7_DSTATE;

    /* Logic: '<S13>/Logical Operator2' incorporates:
     *  Logic: '<S4>/Logical Operator'
     *  UnitDelay: '<S4>/Unit Delay7'
     */
    UnitDelay1_o = !DWork.UnitDelay7_DSTATE;

    /* Switch: '<S26>/Switch' incorporates:
     *  Constant: '<S4>/Parameter'
     *  Logic: '<S13>/Logical Operator2'
     *  Logic: '<S13>/Logical Operator5'
     *  RelationalOperator: '<S13>/edge'
     *  Sum: '<S26>/Sum1'
     *  UnitDelay: '<S13>/Unit Delay'
     *  UnitDelay: '<S26>/Unit Delay'
     *  UnitDelay: '<S4>/Unit Delay7'
     */
    if ((DWork.UnitDelay7_DSTATE != DWork.UnitDelay_DSTATE_n) && UnitDelay1_o) {
      DWork.UnitDelay_DSTATE = 0.5;
    } else {
      /* SampleTimeMath: '<S27>/sample time1'
       *
       * About '<S27>/sample time1':
       *  y = K where K = ( w * Ts )
       */
      MinMax1_j = (real_T)PowerOffManagement_ELAPS_T * 0.005;

      /* MinMax: '<S27>/MinMax' */
      if (0.001 > MinMax1_j) {
        MinMax1_j = 0.001;
      }

      /* End of MinMax: '<S27>/MinMax' */
      DWork.UnitDelay_DSTATE -= MinMax1_j;
    }

    /* End of Switch: '<S26>/Switch' */

    /* MinMax: '<S26>/MinMax1' */
    if (0.5 < DWork.UnitDelay_DSTATE) {
      DWork.UnitDelay_DSTATE = 0.5;
    }

    /* End of MinMax: '<S26>/MinMax1' */

    /* MinMax: '<S26>/MinMax' */
    if (DWork.UnitDelay_DSTATE > 0.0) {
    } else {
      DWork.UnitDelay_DSTATE = 0.0;
    }

    /* End of MinMax: '<S26>/MinMax' */

    /* Switch: '<S13>/debounce' incorporates:
     *  Constant: '<S26>/Constant2'
     *  RelationalOperator: '<S26>/Relational Operator2'
     *  UnitDelay: '<S13>/Unit Delay1'
     *  UnitDelay: '<S26>/Unit Delay'
     *  UnitDelay: '<S4>/Unit Delay7'
     */
    if (DWork.UnitDelay_DSTATE == 0.0) {
      PwrM_flgKeyOnDelay = DWork.UnitDelay7_DSTATE;
    } else {
      PwrM_flgKeyOnDelay = DWork.UnitDelay1_DSTATE;
    }

    /* End of Switch: '<S13>/debounce' */

    /* Outputs for Enabled SubSystem: '<S4>/KeyCycle' incorporates:
     *  EnablePort: '<S7>/Enable'
     */
    if (PwrM_flgKeyOnDelay) {
      PowerOffManagement_ELAPS_T = PowerOffManagement_ELAPS_T_tmp_ -
        DWork.KeyCycle_PREV_T;
      DWork.KeyCycle_PREV_T = PowerOffManagement_ELAPS_T_tmp_;

      /* Switch: '<S22>/Switch' incorporates:
       *  Constant: '<S4>/Parameter3'
       *  Logic: '<S20>/Logical Operator2'
       *  Logic: '<S20>/Logical Operator5'
       *  RelationalOperator: '<S20>/edge'
       *  Sum: '<S22>/Sum1'
       *  UnitDelay: '<S20>/Unit Delay'
       *  UnitDelay: '<S22>/Unit Delay'
       */
      if ((UnitDelay1_o != DWork.UnitDelay_DSTATE_d) && (!UnitDelay1_o)) {
        MinMax1_j = 0.1;
      } else {
        /* SampleTimeMath: '<S23>/sample time1'
         *
         * About '<S23>/sample time1':
         *  y = K where K = ( w * Ts )
         */
        MinMax1_j = (real_T)PowerOffManagement_ELAPS_T * 0.005;

        /* MinMax: '<S23>/MinMax' */
        if (0.001 > MinMax1_j) {
          MinMax1_j = 0.001;
        }

        /* End of MinMax: '<S23>/MinMax' */
        MinMax1_j = DWork.UnitDelay_DSTATE_b - MinMax1_j;
      }

      /* End of Switch: '<S22>/Switch' */

      /* MinMax: '<S22>/MinMax1' */
      if (0.1 < MinMax1_j) {
        MinMax1_j = 0.1;
      }

      /* End of MinMax: '<S22>/MinMax1' */

      /* MinMax: '<S22>/MinMax' */
      if (MinMax1_j > 0.0) {
        DWork.UnitDelay_DSTATE_b = MinMax1_j;
      } else {
        DWork.UnitDelay_DSTATE_b = 0.0;
      }

      /* End of MinMax: '<S22>/MinMax' */

      /* Switch: '<S20>/debounce' incorporates:
       *  Constant: '<S22>/Constant2'
       *  RelationalOperator: '<S22>/Relational Operator2'
       *  UnitDelay: '<S20>/Unit Delay1'
       *  UnitDelay: '<S22>/Unit Delay'
       */
      if (DWork.UnitDelay_DSTATE_b == 0.0) {
        DWork.UnitDelay1_DSTATE_a = UnitDelay1_o;
      }

      /* End of Switch: '<S20>/debounce' */

      /* Switch: '<S24>/Switch' incorporates:
       *  Constant: '<S4>/Parameter2'
       *  Logic: '<S21>/Logical Operator5'
       *  RelationalOperator: '<S21>/edge'
       *  Sum: '<S24>/Sum1'
       *  UnitDelay: '<S21>/Unit Delay'
       *  UnitDelay: '<S24>/Unit Delay'
       */
      if ((UnitDelay1_o != DWork.UnitDelay_DSTATE_p) && UnitDelay1_o) {
        MinMax1_j = 0.1;
      } else {
        /* SampleTimeMath: '<S25>/sample time1'
         *
         * About '<S25>/sample time1':
         *  y = K where K = ( w * Ts )
         */
        MinMax1_j = (real_T)PowerOffManagement_ELAPS_T * 0.005;

        /* MinMax: '<S25>/MinMax' */
        if (0.001 > MinMax1_j) {
          MinMax1_j = 0.001;
        }

        /* End of MinMax: '<S25>/MinMax' */
        MinMax1_j = DWork.UnitDelay_DSTATE_l - MinMax1_j;
      }

      /* End of Switch: '<S24>/Switch' */

      /* MinMax: '<S24>/MinMax1' */
      if (0.1 < MinMax1_j) {
        MinMax1_j = 0.1;
      }

      /* End of MinMax: '<S24>/MinMax1' */

      /* MinMax: '<S24>/MinMax' */
      if (MinMax1_j > 0.0) {
        DWork.UnitDelay_DSTATE_l = MinMax1_j;
      } else {
        DWork.UnitDelay_DSTATE_l = 0.0;
      }

      /* End of MinMax: '<S24>/MinMax' */

      /* Switch: '<S21>/debounce' incorporates:
       *  Constant: '<S24>/Constant2'
       *  RelationalOperator: '<S24>/Relational Operator2'
       *  UnitDelay: '<S21>/Unit Delay1'
       *  UnitDelay: '<S24>/Unit Delay'
       */
      if (DWork.UnitDelay_DSTATE_l == 0.0) {
        DWork.UnitDelay1_DSTATE_m = UnitDelay1_o;
      }

      /* End of Switch: '<S21>/debounce' */

      /* Outputs for Atomic SubSystem: '<S7>/ER_xxxx' */
      /* Logic: '<S16>/Logical Operator' incorporates:
       *  Logic: '<S16>/Logical Operator1'
       *  UnitDelay: '<S16>/Unit Delay'
       *  UnitDelay: '<S21>/Unit Delay1'
       */
      LogicalOperator_k = (DWork.UnitDelay1_DSTATE_m &&
                           (!DWork.UnitDelay_DSTATE_k));

      /* Update for UnitDelay: '<S16>/Unit Delay' incorporates:
       *  UnitDelay: '<S21>/Unit Delay1'
       */
      DWork.UnitDelay_DSTATE_k = DWork.UnitDelay1_DSTATE_m;

      /* End of Outputs for SubSystem: '<S7>/ER_xxxx' */

      /* Outputs for Atomic SubSystem: '<S7>/ER_xxxx1' */
      /* Logic: '<S17>/Logical Operator1' incorporates:
       *  UnitDelay: '<S17>/Unit Delay'
       */
      LogicalOperator1_m = !DWork.UnitDelay_DSTATE_a;

      /* Update for UnitDelay: '<S17>/Unit Delay' */
      DWork.UnitDelay_DSTATE_a = UnitDelay1_o;

      /* Outputs for Atomic SubSystem: '<S7>/RSFF_xxxx' */
      /* Switch: '<S18>/Switch' incorporates:
       *  Constant: '<S18>/Constant2'
       *  Logic: '<S17>/Logical Operator'
       *  Switch: '<S18>/Switch1'
       *  UnitDelay: '<S18>/Unit Delay1'
       */
      if (UnitDelay1_o && LogicalOperator1_m) {
        DWork.UnitDelay1_DSTATE_ey = false;
      } else {
        DWork.UnitDelay1_DSTATE_ey = (LogicalOperator_k ||
          DWork.UnitDelay1_DSTATE_ey);
      }

      /* End of Switch: '<S18>/Switch' */
      /* End of Outputs for SubSystem: '<S7>/RSFF_xxxx' */
      /* End of Outputs for SubSystem: '<S7>/ER_xxxx1' */

      /* Logic: '<S7>/LogicAND1' incorporates:
       *  Logic: '<S7>/LogicAND'
       *  Logic: '<S7>/LogicNOT'
       *  UnitDelay: '<S18>/Unit Delay1'
       *  UnitDelay: '<S20>/Unit Delay1'
       */
      B.LogicAND1 = ((!DWork.UnitDelay1_DSTATE_a) && DWork.UnitDelay1_DSTATE_ey);

      /* If: '<S7>/If2' */
      if (B.LogicAND1) {
        /* Outputs for IfAction SubSystem: '<S7>/Reset_Action' incorporates:
         *  ActionPort: '<S19>/Action Port'
         */
        /* S-Function (ResetSW): '<S19>/ResetSW' */
        if (true==B.LogicAND1) {
          F_Abstr_SoftReset();
        }

        /* End of Outputs for SubSystem: '<S7>/Reset_Action' */
      }

      /* End of If: '<S7>/If2' */

      /* Update for UnitDelay: '<S20>/Unit Delay' */
      DWork.UnitDelay_DSTATE_d = UnitDelay1_o;

      /* Update for UnitDelay: '<S21>/Unit Delay' */
      DWork.UnitDelay_DSTATE_p = UnitDelay1_o;
    }

    /* End of Outputs for SubSystem: '<S4>/KeyCycle' */

    /* UnitDelay: '<S4>/Unit Delay1' */
    UnitDelay1_o = DWork.UnitDelay1_DSTATE_e;

    /* Outputs for Triggered SubSystem: '<S4>/Shutdown Power' incorporates:
     *  TriggerPort: '<S8>/Trigger'
     */
    /* Logic: '<S4>/Logical Operator6' */
    LogicalOperator_k = !UnitDelay1_o;
    if (LogicalOperator_k && (PrevZCSigState.ShutdownPower_Trig_ZCE != 0)) {
      /* S-Function (ecocoder_power_shutdwn): '<S8>/Shutdown Power' */
      F_Abstr_Power_Turn(ABS_Power_PWR12V,0);
    }

    PrevZCSigState.ShutdownPower_Trig_ZCE = UnitDelay1_o;

    /* End of Outputs for SubSystem: '<S4>/Shutdown Power' */

    /* Logic: '<S4>/Logical Operator2' incorporates:
     *  Logic: '<S4>/Logical Operator3'
     *  Logic: '<S4>/Logical Operator5'
     *  Logic: '<S4>/Logical Operator7'
     *  UnitDelay: '<S4>/Unit Delay3'
     *  UnitDelay: '<S4>/Unit Delay4'
     */
    LogicalOperator_k = ((!DWork.UnitDelay3_DSTATE) && LogicalOperator_k &&
                         (!PwrM_flgKeyOnDelay) && (!DWork.UnitDelay4_DSTATE));

    /* Outputs for Enabled SubSystem: '<S4>/Shutdown Power Hold' incorporates:
     *  EnablePort: '<S9>/Enable'
     */
    if (LogicalOperator_k) {
      /* S-Function (ecocoder_power_shutdwn): '<S9>/Shutdown Power' */
      F_Abstr_Power_Turn(ABS_Power_PWR12V,0);
    }

    /* End of Outputs for SubSystem: '<S4>/Shutdown Power Hold' */

    /* Outputs for Triggered SubSystem: '<S4>/Software Reset' incorporates:
     *  TriggerPort: '<S10>/Trigger'
     */
    if (PrevZCSigState.SoftwareReset_Trig_ZCE != 0) {
      /* S-Function (ResetSW): '<S10>/ResetSW' incorporates:
       *  Constant: '<S10>/Constant'
       */
      if (true==true) {
        F_Abstr_SoftReset();
      }
    }

    PrevZCSigState.SoftwareReset_Trig_ZCE = 0U;

    /* End of Outputs for SubSystem: '<S4>/Software Reset' */

    /* Outputs for Triggered SubSystem: '<S4>/Store All NVM Data' incorporates:
     *  TriggerPort: '<S12>/Trigger'
     */
    /* Logic: '<S4>/Logical Operator4' */
    if ((!PwrM_flgKeyOnDelay) && (PrevZCSigState.StoreAllNVMData_Trig_ZCE != 0))
    {
      /* S-Function (WriteBackData): '<S12>/Store NVM Data1' incorporates:
       *  Constant: '<S12>/Constant'
       */
      if (true==true) {
        F_Abstr_MemRam2Nvm();
      }
    }

    PrevZCSigState.StoreAllNVMData_Trig_ZCE = PwrM_flgKeyOnDelay;

    /* End of Logic: '<S4>/Logical Operator4' */
    /* End of Outputs for SubSystem: '<S4>/Store All NVM Data' */

    /* S-Function (DI_Key_In): '<S6>/SwitchInput_ReadKeyOn' */
    B.SwitchInput_ReadKeyOn= F_Abstr_DI_GetValue(ABS_DI_KEYON);

    /* Switch: '<S6>/Switch' */
    PwrM_flgKeyOnRaw = B.SwitchInput_ReadKeyOn;

    /* Update for UnitDelay: '<S4>/Unit Delay7' */
    DWork.UnitDelay7_DSTATE = PwrM_flgKeyOnRaw;

    /* Update for UnitDelay: '<S13>/Unit Delay' */
    DWork.UnitDelay_DSTATE_n = UnitDelay7;

    /* Update for UnitDelay: '<S13>/Unit Delay1' */
    DWork.UnitDelay1_DSTATE = PwrM_flgKeyOnDelay;

    /* Update for UnitDelay: '<S4>/Unit Delay1' */
    DWork.UnitDelay1_DSTATE_e = PwrM_flgKeyOnDelay;

    /* Update for UnitDelay: '<S4>/Unit Delay3' */
    DWork.UnitDelay3_DSTATE = UnitDelay1_o;

    /* Update for UnitDelay: '<S4>/Unit Delay4' incorporates:
     *  UnitDelay: '<S4>/Unit Delay5'
     */
    DWork.UnitDelay4_DSTATE = DWork.UnitDelay5_DSTATE;

    /* Update for UnitDelay: '<S4>/Unit Delay2' */
    DWork.UnitDelay2_DSTATE = LogicalOperator_k;

    /* Update for UnitDelay: '<S4>/Unit Delay5' incorporates:
     *  UnitDelay: '<S4>/Unit Delay6'
     */
    DWork.UnitDelay5_DSTATE = DWork.UnitDelay6_DSTATE;

    /* Update for UnitDelay: '<S4>/Unit Delay6' */
    DWork.UnitDelay6_DSTATE = UnitDelay7;
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
void DemoTest_step2(void)              /* Sample time: [0.01s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID3 */
void DemoTest_step3(void)              /* Sample time: [0.02s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID4 */
void DemoTest_step4(void)              /* Sample time: [0.05s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID5 */
void DemoTest_step5(void)              /* Sample time: [0.1s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID6 */
void DemoTest_step6(void)              /* Sample time: [0.2s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID7 */
void DemoTest_step7(void)              /* Sample time: [0.5s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID8 */
void DemoTest_step8(void)              /* Sample time: [1.0s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step wrapper function for compatibility with a static main program */
void DemoTest_step(int_T tid)
{
  switch (tid) {
   case 0 :
    DemoTest_step0();
    break;

   case 1 :
    DemoTest_step1();
    break;

   case 2 :
    DemoTest_step2();
    break;

   case 3 :
    DemoTest_step3();
    break;

   case 4 :
    DemoTest_step4();
    break;

   case 5 :
    DemoTest_step5();
    break;

   case 6 :
    DemoTest_step6();
    break;

   case 7 :
    DemoTest_step7();
    break;

   case 8 :
    DemoTest_step8();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void DemoTest_initialize(void)
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
  (void) memset(((void *) &B), 0,
                sizeof(BlockIO));

  /* states (dwork) */
  (void) memset((void *)&DWork, 0,
                sizeof(D_Work));

  /* Start for S-Function (EcoCoder_Task): '<S2>/Task_Call' */

  /* -- Call CAN RX Fcn-Call_0 -- */

  /* Output and update for function-call system: '<S2>/Power On Init' */

  /* Outputs for Enabled SubSystem: '<S5>/Restore NVM Data' incorporates:
   *  EnablePort: '<S28>/Enable'
   */
  /* Logic: '<S28>/Logical Operator' incorporates:
   *  Logic: '<S28>/LogicNOT1'
   *  UnitDelay: '<S28>/Unit Delay'
   */
  B.LogicalOperator_e = !DWork.UnitDelay_DSTATE_aq;

  /* S-Function (WriteBackData): '<S28>/Restore NVM Data' */
  if (true==B.LogicalOperator_e) {
    F_Abstr_MemNvm2Ram();
  }

  /* Update for UnitDelay: '<S28>/Unit Delay' incorporates:
   *  Constant: '<S28>/Constant'
   */
  DWork.UnitDelay_DSTATE_aq = true;

  /* End of Outputs for SubSystem: '<S5>/Restore NVM Data' */

  /* End of Start for S-Function (EcoCoder_Task): '<S2>/Task_Call' */

  /* Start for S-Function (EcoCoder_Task): '<S1>/Task Trigger' */

  /* -- Call CAN RX Fcn-Call_0 -- */

  /* End of Start for S-Function (EcoCoder_Task): '<S1>/Task Trigger' */

  /* Start for S-Function (EcoCoder_Task): '<S2>/Task_Call1' incorporates:
   *  SubSystem: '<S2>/Power Off Management'
   */

  /* Start for function-call system: '<S2>/Power Off Management' */

  /* Start for S-Function (DI_Key_In): '<S6>/SwitchInput_ReadKeyOn' */
  F_Abstr_DI_InitChannel(ABS_DI_KEYON);

  /* End of Start for S-Function (EcoCoder_Task): '<S2>/Task_Call1' */
  PrevZCSigState.ShutdownPower_Trig_ZCE = ZERO_ZCSIG;
  PrevZCSigState.SoftwareReset_Trig_ZCE = ZERO_ZCSIG;
  PrevZCSigState.StoreAllNVMData_Trig_ZCE = ZERO_ZCSIG;

  /* SystemInitialize for S-Function (EcoCoder_Task): '<S2>/Task_Call1' incorporates:
   *  SubSystem: '<S2>/Power Off Management'
   */

  /* System initialize for function-call system: '<S2>/Power Off Management' */
  DWork.PowerOffManagement_PREV_T = M->Timing.clockTick1;

  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay7' */
  DWork.UnitDelay7_DSTATE = true;

  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay4' */
  DWork.UnitDelay4_DSTATE = true;

  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay5' */
  DWork.UnitDelay5_DSTATE = true;

  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay6' */
  DWork.UnitDelay6_DSTATE = true;

  /* SystemInitialize for Enabled SubSystem: '<S4>/KeyCycle' */
  /* SystemInitialize for Atomic SubSystem: '<S7>/ER_xxxx' */
  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay' */
  DWork.UnitDelay_DSTATE_k = true;

  /* End of SystemInitialize for SubSystem: '<S7>/ER_xxxx' */

  /* SystemInitialize for Atomic SubSystem: '<S7>/ER_xxxx1' */
  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
  DWork.UnitDelay_DSTATE_a = true;

  /* End of SystemInitialize for SubSystem: '<S7>/ER_xxxx1' */
  /* End of SystemInitialize for SubSystem: '<S4>/KeyCycle' */

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
