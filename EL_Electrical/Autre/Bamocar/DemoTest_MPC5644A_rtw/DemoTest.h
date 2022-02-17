/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DemoTest.h
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

#ifndef RTW_HEADER_DemoTest_h_
#define RTW_HEADER_DemoTest_h_
#include <string.h>
#include "Abstraction_Sys.h"
#include "Abstraction_Sys.h"
#include "Abstraction_Power.h"
#include "Abstraction_DI.h"
#include "ASW_Schedule.h"
#include "ASW_Schedule.h"
#include "ASW_Schedule.h"
#ifndef DemoTest_COMMON_INCLUDES_
# define DemoTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* DemoTest_COMMON_INCLUDES_ */

/* Model Code Variants */
#include "EcoCoderTypeDef.h"
#include "EcoSectionDef.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmCounterLimit
# define rtmCounterLimit(rtm, idx)     ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define DemoTest_M                     (M)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals (default storage) */
typedef struct {
  boolean_T SwitchInput_ReadKeyOn;     /* '<S6>/SwitchInput_ReadKeyOn' */
  boolean_T LogicAND1;                 /* '<S7>/LogicAND1' */
  boolean_T LogicalOperator_e;         /* '<S28>/Logical Operator' */
} BlockIO;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S26>/Unit Delay' */
  real_T UnitDelay_DSTATE_b;           /* '<S22>/Unit Delay' */
  real_T UnitDelay_DSTATE_l;           /* '<S24>/Unit Delay' */
  uint32_T PowerOffManagement_PREV_T;  /* '<S2>/Power Off Management' */
  uint32_T KeyCycle_PREV_T;            /* '<S4>/KeyCycle' */
  boolean_T UnitDelay7_DSTATE;         /* '<S4>/Unit Delay7' */
  boolean_T UnitDelay_DSTATE_n;        /* '<S13>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S13>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_e;       /* '<S4>/Unit Delay1' */
  boolean_T UnitDelay3_DSTATE;         /* '<S4>/Unit Delay3' */
  boolean_T UnitDelay4_DSTATE;         /* '<S4>/Unit Delay4' */
  boolean_T UnitDelay2_DSTATE;         /* '<S4>/Unit Delay2' */
  boolean_T UnitDelay5_DSTATE;         /* '<S4>/Unit Delay5' */
  boolean_T UnitDelay6_DSTATE;         /* '<S4>/Unit Delay6' */
  boolean_T UnitDelay_DSTATE_d;        /* '<S20>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_a;       /* '<S20>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_p;        /* '<S21>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_m;       /* '<S21>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_ey;      /* '<S18>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_a;        /* '<S17>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_k;        /* '<S16>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_aq;       /* '<S28>/Unit Delay' */
  boolean_T Task_Call_DWORK0;          /* '<S2>/Task_Call' */
  boolean_T TaskTrigger_DWORK0;        /* '<S1>/Task Trigger' */
} D_Work;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState StoreAllNVMData_Trig_ZCE; /* '<S4>/Store All NVM Data' */
  ZCSigState SoftwareReset_Trig_ZCE;   /* '<S4>/Software Reset' */
  ZCSigState ShutdownPower_Trig_ZCE;   /* '<S4>/Shutdown Power' */
} PrevZCSigStates;

/* Real-time Model Data Structure */
struct tag_RTM {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick1;
    struct {
      uint16_T TID[9];
      uint16_T cLimit[9];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern BlockIO B;

/* Block states (default storage) */
extern D_Work DWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates PrevZCSigState;

/* Model entry point functions */
void DemoTest_initialize(void);
void DemoTest_step(int_T tid);

/* Exported data declaration */
#define PUSH__MP
#include "EcoSectionDef.h"

/* Declaration for custom storage class: Measurement */
extern __MP boolean_T PwrM_flgKeyOnDelay;/* '<S13>/debounce' */
extern __MP boolean_T PwrM_flgKeyOnRaw;/* '<S6>/Switch' */

#define POP__MP
#include "EcoSectionDef.h"

/* Real-time Model object */
extern RT_MODEL *const M;
extern void DemoTest_step0(void);      /* Sample time: [0.001s, 0.0s] */
extern void DemoTest_step1(void);      /* Sample time: [0.005s, 0.0s] */
extern void DemoTest_step2(void);      /* Sample time: [0.01s, 0.0s]  */
extern void DemoTest_step3(void);      /* Sample time: [0.02s, 0.0s]  */
extern void DemoTest_step4(void);      /* Sample time: [0.05s, 0.0s]  */
extern void DemoTest_step5(void);      /* Sample time: [0.1s, 0.0s]   */
extern void DemoTest_step6(void);      /* Sample time: [0.2s, 0.0s]   */
extern void DemoTest_step7(void);      /* Sample time: [0.5s, 0.0s]   */
extern void DemoTest_step8(void);      /* Sample time: [1.0s, 0.0s]   */
extern uint8_T EcoCoder_Target_Setting;
extern uint8_T EcoCoder_CAB_ChecheFailedWhile(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'DemoTest'
 * '<S1>'   : 'DemoTest/EcoCoder Target Definition'
 * '<S2>'   : 'DemoTest/Power Management Example'
 * '<S3>'   : 'DemoTest/EcoCoder Target Definition/FunctionNull'
 * '<S4>'   : 'DemoTest/Power Management Example/Power Off Management'
 * '<S5>'   : 'DemoTest/Power Management Example/Power On Init'
 * '<S6>'   : 'DemoTest/Power Management Example/Power Off Management/Get flgKeyOn'
 * '<S7>'   : 'DemoTest/Power Management Example/Power Off Management/KeyCycle'
 * '<S8>'   : 'DemoTest/Power Management Example/Power Off Management/Shutdown Power'
 * '<S9>'   : 'DemoTest/Power Management Example/Power Off Management/Shutdown Power Hold'
 * '<S10>'  : 'DemoTest/Power Management Example/Power Off Management/Software Reset'
 * '<S11>'  : 'DemoTest/Power Management Example/Power Off Management/Software Reset Hold'
 * '<S12>'  : 'DemoTest/Power Management Example/Power Off Management/Store All NVM Data'
 * '<S13>'  : 'DemoTest/Power Management Example/Power Off Management/TOfD_xxxx1'
 * '<S14>'  : 'DemoTest/Power Management Example/Power Off Management/Write and Read Measurement'
 * '<S15>'  : 'DemoTest/Power Management Example/Power Off Management/Write and Read Measurement1'
 * '<S16>'  : 'DemoTest/Power Management Example/Power Off Management/KeyCycle/ER_xxxx'
 * '<S17>'  : 'DemoTest/Power Management Example/Power Off Management/KeyCycle/ER_xxxx1'
 * '<S18>'  : 'DemoTest/Power Management Example/Power Off Management/KeyCycle/RSFF_xxxx'
 * '<S19>'  : 'DemoTest/Power Management Example/Power Off Management/KeyCycle/Reset_Action'
 * '<S20>'  : 'DemoTest/Power Management Example/Power Off Management/KeyCycle/TOfD_xxxx'
 * '<S21>'  : 'DemoTest/Power Management Example/Power Off Management/KeyCycle/edgeDbncRise'
 * '<S22>'  : 'DemoTest/Power Management Example/Power Off Management/KeyCycle/TOfD_xxxx/DebounceTimer'
 * '<S23>'  : 'DemoTest/Power Management Example/Power Off Management/KeyCycle/TOfD_xxxx/DebounceTimer/dt'
 * '<S24>'  : 'DemoTest/Power Management Example/Power Off Management/KeyCycle/edgeDbncRise/DebounceTimer'
 * '<S25>'  : 'DemoTest/Power Management Example/Power Off Management/KeyCycle/edgeDbncRise/DebounceTimer/dt'
 * '<S26>'  : 'DemoTest/Power Management Example/Power Off Management/TOfD_xxxx1/DebounceTimer'
 * '<S27>'  : 'DemoTest/Power Management Example/Power Off Management/TOfD_xxxx1/DebounceTimer/dt'
 * '<S28>'  : 'DemoTest/Power Management Example/Power On Init/Restore NVM Data'
 */
#endif                                 /* RTW_HEADER_DemoTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
