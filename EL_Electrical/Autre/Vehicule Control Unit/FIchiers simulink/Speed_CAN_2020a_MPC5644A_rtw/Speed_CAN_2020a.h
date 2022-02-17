/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Speed_CAN_2020a.h
 *
 * Code generated for Simulink model 'Speed_CAN_2020a'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Feb 17 17:47:26 2022
 *
 * Target selection: MPC5644A.tlc
 * Embedded hardware selection: Freescale->MPC55xx
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Speed_CAN_2020a_h_
#define RTW_HEADER_Speed_CAN_2020a_h_
#include <math.h>
#include <string.h>
#include "Abstraction_Sys.h"
#include "Abstraction_Sys.h"
#include "Abstraction_Power.h"
#include "Abstraction_DI.h"
#include "Abstraction_ADC.h"
#include "Service_CAN.h"
#include "Service_CAN.h"
#include "ASW_Schedule.h"
#include "ASW_Schedule.h"
#include "ASW_Schedule.h"
#include "ASW_Schedule.h"
#include "ASW_Schedule.h"
#include "ASW_Schedule.h"
#ifndef Speed_CAN_2020a_COMMON_INCLUDES_
# define Speed_CAN_2020a_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* Speed_CAN_2020a_COMMON_INCLUDES_ */

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

#define Speed_CAN_2020a_M              (M)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals (default storage) */
typedef struct {
  uint32_T ReceiveCANMessage_o4;       /* '<S32>/Receive CAN Message' */
  uint16_T ReadADCValue;               /* '<S30>/Read ADC Value' */
  int16_T DataTypeConversion2;         /* '<S30>/Data Type Conversion2' */
  uint8_T ReceiveCANMessage_o5;        /* '<S32>/Receive CAN Message' */
  uint8_T ReceiveCANMessage_o6[8];     /* '<S32>/Receive CAN Message' */
  uint8_T UnpackCANDataToSignals_o1;   /* '<S32>/Unpack CAN Data To Signals' */
  uint8_T UnpackCANDataToSignals_o3;   /* '<S32>/Unpack CAN Data To Signals' */
  uint8_T PackSignalsToCANData[8];     /* '<S31>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_o[8];   /* '<S30>/Pack Signals To CAN Data' */
  boolean_T ReceiveCANMessage_o1;      /* '<S32>/Receive CAN Message' */
  boolean_T ReceiveCANMessage_o2;      /* '<S32>/Receive CAN Message' */
  boolean_T ReceiveCANMessage_o3;      /* '<S32>/Receive CAN Message' */
  boolean_T SwitchInput_ReadKeyOn;     /* '<S7>/SwitchInput_ReadKeyOn' */
  boolean_T LogicAND1;                 /* '<S8>/LogicAND1' */
  boolean_T LogicalOperator_e;         /* '<S29>/Logical Operator' */
} B;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S27>/Unit Delay' */
  real_T UnitDelay_DSTATE_h;           /* '<S23>/Unit Delay' */
  real_T UnitDelay_DSTATE_d;           /* '<S25>/Unit Delay' */
  uint32_T PowerOffManagement_PREV_T;  /* '<S2>/Power Off Management' */
  uint32_T KeyCycle_PREV_T;            /* '<S5>/KeyCycle' */
  boolean_T UnitDelay7_DSTATE;         /* '<S5>/Unit Delay7' */
  boolean_T UnitDelay_DSTATE_n;        /* '<S14>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S14>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_g;       /* '<S5>/Unit Delay1' */
  boolean_T UnitDelay3_DSTATE;         /* '<S5>/Unit Delay3' */
  boolean_T UnitDelay4_DSTATE;         /* '<S5>/Unit Delay4' */
  boolean_T UnitDelay2_DSTATE;         /* '<S5>/Unit Delay2' */
  boolean_T UnitDelay5_DSTATE;         /* '<S5>/Unit Delay5' */
  boolean_T UnitDelay6_DSTATE;         /* '<S5>/Unit Delay6' */
  boolean_T UnitDelay_DSTATE_o;        /* '<S21>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_n;       /* '<S21>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_na;       /* '<S22>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_j;       /* '<S22>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_i;       /* '<S19>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_m;        /* '<S18>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_k;        /* '<S17>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_g;        /* '<S29>/Unit Delay' */
  boolean_T Task_Call_DWORK0;          /* '<S2>/Task_Call' */
  boolean_T TaskTrigger1_DWORK0;       /* '<S3>/Task Trigger1' */
  boolean_T TaskTrigger_DWORK0;        /* '<S1>/Task Trigger' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState StoreAllNVMData_Trig_ZCE; /* '<S5>/Store All NVM Data' */
  ZCSigState SoftwareReset_Trig_ZCE;   /* '<S5>/Software Reset' */
  ZCSigState ShutdownPower_Trig_ZCE;   /* '<S5>/Shutdown Power' */
} PrevZCX;

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
extern B B_n;

/* Block states (default storage) */
extern DW DW_l;

/* Zero-crossing (trigger) state */
extern PrevZCX PrevZCX_p;

/* Model entry point functions */
void Speed_CAN_2020a_initialize(void);
void Speed_CAN_2020a_step(int_T tid);

/* Exported data declaration */
#define PUSH__MP
#include "EcoSectionDef.h"

/* Declaration for custom storage class: Measurement */
extern __MP boolean_T PwrM_flgKeyOnDelay;/* '<S14>/debounce' */
extern __MP boolean_T PwrM_flgKeyOnRaw;/* '<S7>/Switch' */
extern __MP int16_T vitesse;           /* '<S32>/Unpack CAN Data To Signals' */

#define POP__MP
#include "EcoSectionDef.h"

/* Real-time Model object */
extern RT_MODEL *const M;
extern void Speed_CAN_2020a_step0(void);/* Sample time: [0.001s, 0.0s] */
extern void Speed_CAN_2020a_step1(void);/* Sample time: [0.005s, 0.0s] */
extern void Speed_CAN_2020a_step2(void);/* Sample time: [0.01s, 0.0s]  */
extern void Speed_CAN_2020a_step3(void);/* Sample time: [0.02s, 0.0s]  */
extern void Speed_CAN_2020a_step4(void);/* Sample time: [0.05s, 0.0s]  */
extern void Speed_CAN_2020a_step5(void);/* Sample time: [0.1s, 0.0s]   */
extern void Speed_CAN_2020a_step6(void);/* Sample time: [0.2s, 0.0s]   */
extern void Speed_CAN_2020a_step7(void);/* Sample time: [0.5s, 0.0s]   */
extern void Speed_CAN_2020a_step8(void);/* Sample time: [1.0s, 0.0s]   */
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
 * '<Root>' : 'Speed_CAN_2020a'
 * '<S1>'   : 'Speed_CAN_2020a/EcoCoder Target Definition'
 * '<S2>'   : 'Speed_CAN_2020a/Power Management Example'
 * '<S3>'   : 'Speed_CAN_2020a/Speed CAN'
 * '<S4>'   : 'Speed_CAN_2020a/EcoCoder Target Definition/FunctionNull'
 * '<S5>'   : 'Speed_CAN_2020a/Power Management Example/Power Off Management'
 * '<S6>'   : 'Speed_CAN_2020a/Power Management Example/Power On Init'
 * '<S7>'   : 'Speed_CAN_2020a/Power Management Example/Power Off Management/Get flgKeyOn'
 * '<S8>'   : 'Speed_CAN_2020a/Power Management Example/Power Off Management/KeyCycle'
 * '<S9>'   : 'Speed_CAN_2020a/Power Management Example/Power Off Management/Shutdown Power'
 * '<S10>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/Shutdown Power Hold'
 * '<S11>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/Software Reset'
 * '<S12>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/Software Reset Hold'
 * '<S13>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/Store All NVM Data'
 * '<S14>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/TOfD_xxxx1'
 * '<S15>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/Write and Read Measurement'
 * '<S16>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/Write and Read Measurement1'
 * '<S17>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/KeyCycle/ER_xxxx'
 * '<S18>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/KeyCycle/ER_xxxx1'
 * '<S19>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/KeyCycle/RSFF_xxxx'
 * '<S20>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/KeyCycle/Reset_Action'
 * '<S21>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/KeyCycle/TOfD_xxxx'
 * '<S22>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/KeyCycle/edgeDbncRise'
 * '<S23>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/KeyCycle/TOfD_xxxx/DebounceTimer'
 * '<S24>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/KeyCycle/TOfD_xxxx/DebounceTimer/dt'
 * '<S25>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/KeyCycle/edgeDbncRise/DebounceTimer'
 * '<S26>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/KeyCycle/edgeDbncRise/DebounceTimer/dt'
 * '<S27>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/TOfD_xxxx1/DebounceTimer'
 * '<S28>'  : 'Speed_CAN_2020a/Power Management Example/Power Off Management/TOfD_xxxx1/DebounceTimer/dt'
 * '<S29>'  : 'Speed_CAN_2020a/Power Management Example/Power On Init/Restore NVM Data'
 * '<S30>'  : 'Speed_CAN_2020a/Speed CAN/Subsystem'
 * '<S31>'  : 'Speed_CAN_2020a/Speed CAN/Subsystem1'
 * '<S32>'  : 'Speed_CAN_2020a/Speed CAN/Subsystem2'
 * '<S33>'  : 'Speed_CAN_2020a/Speed CAN/Subsystem2/Write Measurement'
 */
#endif                                 /* RTW_HEADER_Speed_CAN_2020a_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
