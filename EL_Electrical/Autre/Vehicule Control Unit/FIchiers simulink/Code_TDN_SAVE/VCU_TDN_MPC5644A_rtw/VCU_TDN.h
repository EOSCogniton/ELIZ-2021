/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VCU_TDN.h
 *
 * Code generated for Simulink model 'VCU_TDN'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Mar  1 18:01:29 2022
 *
 * Target selection: MPC5644A.tlc
 * Embedded hardware selection: Freescale->MPC55xx
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_VCU_TDN_h_
#define RTW_HEADER_VCU_TDN_h_
#include <math.h>
#include <string.h>
#include "DataDef_NVM.h"
#include "Abstraction_ADC.h"
#include "Service_CAN.h"
#include "DataDef_NVM.h"
#include "Abstraction_DI.h"
#include "Abstraction_HLSO.h"
#include "Abstraction_Sys.h"
#include "Abstraction_Sys.h"
#include "Abstraction_Power.h"
#include "Abstraction_DI.h"
#include "ASW_Schedule.h"
#include "ASW_Schedule.h"
#include "ASW_Schedule.h"
#include "ASW_Schedule.h"
#include "ASW_Schedule.h"
#include "ASW_Schedule.h"
#include "ASW_Schedule.h"
#include "ASW_Schedule.h"
#include "Service_CAN.h"
#include "ASW_Schedule.h"
#include "ASW_Schedule.h"
#include "ASW_Schedule.h"
#include "ASW_Schedule.h"
#ifndef VCU_TDN_COMMON_INCLUDES_
# define VCU_TDN_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* VCU_TDN_COMMON_INCLUDES_ */

/* Shared type includes */
#include "multiword_types.h"

/* Model Code Variants */
#include "EcoCoderTypeDef.h"
#include "EcoSectionDef.h"
#define MEM_NFNVM_INT_EN
#define ECO_MEM_NFNEM_INIT_SET         0

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

#define VCU_TDN_M                      (M)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals (default storage) */
typedef struct {
  real_T ReadCANMessage_o2;            /* '<S64>/Read CAN Message' */
  real_T ReadCANMessage_o3;            /* '<S64>/Read CAN Message' */
  real32_T ReadNVM;                    /* '<S6>/Read NVM' */
  uint16_T Currentsensorchannel1;      /* '<S65>/Current sensor channel 1' */
  uint16_T Currentsensorchannel2;      /* '<S65>/Current sensor channel 2' */
  uint16_T Frontbrakepressure;         /* '<S65>/Front brake pressure' */
  uint16_T Rearbrakepressure;          /* '<S65>/Rear brake pressure' */
  int16_T ReadNVM_b;                   /* '<S12>/Read NVM' */
  int16_T ReadNVM3;                    /* '<S41>/Read NVM3' */
  int16_T ReadNVM_m;                   /* '<S41>/Read NVM' */
  int16_T ReadNVM1;                    /* '<S41>/Read NVM1' */
  int16_T ReadNVM2;                    /* '<S41>/Read NVM2' */
  int16_T ReadNVM_p;                   /* '<S42>/Read NVM' */
  int16_T ReadNVM1_k;                  /* '<S42>/Read NVM1' */
  int16_T ReadNVM2_a;                  /* '<S43>/Read NVM2' */
  int16_T ReadNVM1_f;                  /* '<S43>/Read NVM1' */
  int16_T ReadNVM_f;                   /* '<S43>/Read NVM' */
  int16_T DataTypeConversion1;         /* '<S14>/Data Type Conversion1' */
  uint8_T PackSignalsToCANData[8];     /* '<S63>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_n[8];   /* '<S62>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_o[8];   /* '<S51>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_l[8];   /* '<S21>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_b[8];   /* '<S22>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_ly[8];  /* '<S33>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_e[8];   /* '<S35>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_k[8];   /* '<S36>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_g[8];   /* '<S37>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_d[8];   /* '<S38>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_i[8];   /* '<S20>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_p[8];   /* '<S23>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_h[8];   /* '<S24>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_p0[8];  /* '<S25>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_dk[8];  /* '<S26>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_hy[8];  /* '<S27>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_h4[8];  /* '<S28>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_d0[8];  /* '<S29>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_f[8];   /* '<S30>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_ht[8];  /* '<S31>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_m[8];   /* '<S32>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData_fg[8];  /* '<S34>/Pack Signals To CAN Data' */
  uint8_T PackSignalsToCANData1[8];    /* '<S14>/Pack Signals To CAN Data1' */
  boolean_T ReadCANMessage_o1;         /* '<S64>/Read CAN Message' */
  boolean_T SwitchInput_ReadKeyOn;     /* '<S118>/SwitchInput_ReadKeyOn' */
  boolean_T LogicAND1;                 /* '<S119>/LogicAND1' */
  boolean_T LogicalOperator_e;         /* '<S140>/Logical Operator' */
  boolean_T ReadNVM1_g;                /* '<S6>/Read NVM1' */
  boolean_T LogicalOperator_n;         /* '<S6>/Logical Operator' */
  boolean_T Readytodrivebutton;        /* '<S10>/Ready to drive button' */
  boolean_T ReadNVM_my;                /* '<S10>/Read NVM' */
  boolean_T ReadNVM1_d;                /* '<S10>/Read NVM1' */
  boolean_T LogicalOperator1_p;        /* '<S10>/Logical Operator1' */
  boolean_T BatteryfanON;              /* '<S9>/Battery fan ON' */
  boolean_T PumpON;                    /* '<S9>/Pump ON' */
  boolean_T PumpandFanON;              /* '<S9>/Pump and Fan ON' */
  boolean_T Compare_g;                 /* '<S17>/Compare' */
} B;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S138>/Unit Delay' */
  real_T UnitDelay_DSTATE_h;           /* '<S134>/Unit Delay' */
  real_T UnitDelay_DSTATE_d;           /* '<S136>/Unit Delay' */
  real32_T ReadNVM_DWORK0;             /* '<S6>/Read NVM' */
  real32_T WriteNVM_DWORK0;            /* '<S14>/Write NVM' */
  uint32_T PowerOffManagement_PREV_T;  /* '<S3>/Power Off Management' */
  uint32_T KeyCycle_PREV_T;            /* '<S116>/KeyCycle' */
  int16_T ReadNVM_DWORK0_l;            /* '<S12>/Read NVM' */
  int16_T ReadNVM3_DWORK0;             /* '<S41>/Read NVM3' */
  int16_T WriteNVM2_DWORK0;            /* '<S41>/Write NVM2' */
  int16_T ReadNVM_DWORK0_e;            /* '<S41>/Read NVM' */
  int16_T ReadNVM1_DWORK0;             /* '<S41>/Read NVM1' */
  int16_T ReadNVM2_DWORK0;             /* '<S41>/Read NVM2' */
  int16_T WriteNVM_DWORK0_g;           /* '<S41>/Write NVM' */
  int16_T ReadNVM_DWORK0_i;            /* '<S42>/Read NVM' */
  int16_T ReadNVM1_DWORK0_p;           /* '<S42>/Read NVM1' */
  int16_T WriteNVM_DWORK0_gb;          /* '<S42>/Write NVM' */
  int16_T WriteNVM1_DWORK0;            /* '<S42>/Write NVM1' */
  int16_T ReadNVM2_DWORK0_k;           /* '<S43>/Read NVM2' */
  int16_T WriteNVM2_DWORK0_o;          /* '<S43>/Write NVM2' */
  int16_T ReadNVM1_DWORK0_c;           /* '<S43>/Read NVM1' */
  int16_T WriteNVM1_DWORK0_f;          /* '<S43>/Write NVM1' */
  int16_T ReadNVM_DWORK0_o;            /* '<S43>/Read NVM' */
  int16_T WriteNVM_DWORK0_c;           /* '<S43>/Write NVM' */
  int16_T WriteNVM_DWORK0_b;           /* '<S83>/Write NVM' */
  int16_T WriteNVM_DWORK0_o;           /* '<S84>/Write NVM' */
  int16_T WriteNVM_DWORK0_f;           /* '<S82>/Write NVM' */
  int16_T WriteNVM_DWORK0_a;           /* '<S69>/Write NVM' */
  int16_T WriteNVM_DWORK0_l;           /* '<S68>/Write NVM' */
  int16_T WriteNVM_DWORK0_j;           /* '<S85>/Write NVM' */
  int16_T WriteNVM_DWORK0_am;          /* '<S67>/Write NVM' */
  int16_T WriteNVM_DWORK0_p;           /* '<S70>/Write NVM' */
  int16_T WriteNVM_DWORK0_af;          /* '<S72>/Write NVM' */
  int16_T WriteNVM_DWORK0_jx;          /* '<S73>/Write NVM' */
  int16_T WriteNVM_DWORK0_e;           /* '<S71>/Write NVM' */
  int16_T WriteNVM_DWORK0_ap;          /* '<S81>/Write NVM' */
  int16_T WriteNVM_DWORK0_h;           /* '<S80>/Write NVM' */
  int16_T WriteNVM_DWORK0_b2;          /* '<S79>/Write NVM' */
  int16_T WriteNVM1_DWORK0_a;          /* '<S79>/Write NVM1' */
  int16_T WriteNVM_DWORK0_h2;          /* '<S78>/Write NVM' */
  int16_T WriteNVM1_DWORK0_d;          /* '<S78>/Write NVM1' */
  int16_T WriteNVM_DWORK0_d;           /* '<S76>/Write NVM' */
  int16_T WriteNVM_DWORK0_dx;          /* '<S77>/Write NVM' */
  uint16_T WriteNVM_DWORK0_dt;         /* '<S4>/Write NVM' */
  uint16_T WriteNVM1_DWORK0_e;         /* '<S4>/Write NVM1' */
  uint16_T WriteNVM_DWORK0_fd;         /* '<S75>/Write NVM' */
  uint16_T WriteNVM_DWORK0_gn;         /* '<S74>/Write NVM' */
  boolean_T UnitDelay7_DSTATE;         /* '<S116>/Unit Delay7' */
  boolean_T UnitDelay_DSTATE_n;        /* '<S125>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S125>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_g;       /* '<S116>/Unit Delay1' */
  boolean_T UnitDelay3_DSTATE;         /* '<S116>/Unit Delay3' */
  boolean_T UnitDelay4_DSTATE;         /* '<S116>/Unit Delay4' */
  boolean_T UnitDelay2_DSTATE;         /* '<S116>/Unit Delay2' */
  boolean_T UnitDelay5_DSTATE;         /* '<S116>/Unit Delay5' */
  boolean_T UnitDelay6_DSTATE;         /* '<S116>/Unit Delay6' */
  boolean_T UnitDelay_DSTATE_o;        /* '<S132>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_n;       /* '<S132>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_na;       /* '<S133>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_j;       /* '<S133>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_i;       /* '<S130>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_m;        /* '<S129>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_k;        /* '<S128>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_g;        /* '<S140>/Unit Delay' */
  boolean_T TappedDelay_X[490];        /* '<S6>/Tapped Delay' */
  boolean_T TappedDelay_X_i[1000];     /* '<S10>/Tapped Delay' */
  boolean_T Delay1_DSTATE[2000];       /* '<S10>/Delay1' */
  boolean_T TappedDelay_X_i5[90];      /* '<S13>/Tapped Delay' */
  boolean_T Task_Call_DWORK0;          /* '<S3>/Task_Call' */
  boolean_T TaskTrigger5_DWORK0;       /* '<S1>/Task Trigger5' */
  boolean_T TaskTrigger4_DWORK0;       /* '<S1>/Task Trigger4' */
  boolean_T TaskTrigger_DWORK0;        /* '<S2>/Task Trigger' */
  boolean_T WriteNVM_DWORK0_fc;        /* '<S6>/Write NVM' */
  boolean_T ReadNVM1_DWORK0_a;         /* '<S6>/Read NVM1' */
  boolean_T WriteNVM_DWORK0_g2;        /* '<S10>/Write NVM' */
  boolean_T WriteNVM1_DWORK0_c;        /* '<S10>/Write NVM1' */
  boolean_T ReadNVM_DWORK0_a;          /* '<S10>/Read NVM' */
  boolean_T ReadNVM1_DWORK0_n;         /* '<S10>/Read NVM1' */
  boolean_T WriteNVM2_DWORK0_e;        /* '<S10>/Write NVM2' */
  boolean_T WriteNVM2_DWORK0_k;        /* '<S9>/Write NVM2' */
  boolean_T WriteNVM_DWORK0_hn;        /* '<S9>/Write NVM' */
  boolean_T WriteNVM1_DWORK0_cc;       /* '<S9>/Write NVM1' */
  boolean_T WriteNVM_DWORK0_lw;        /* '<S13>/Write NVM' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState StoreAllNVMData_Trig_ZCE; /* '<S116>/Store All NVM Data' */
  ZCSigState SoftwareReset_Trig_ZCE;   /* '<S116>/Software Reset' */
  ZCSigState ShutdownPower_Trig_ZCE;   /* '<S116>/Shutdown Power' */
  ZCSigState StopRTDsound_Trig_ZCE;    /* '<S10>/Stop RTD sound' */
  ZCSigState DeactivateReadytodrive_Trig_ZCE;/* '<S10>/Deactivate Ready to drive' */
  ZCSigState ActivateReadytodrive_Trig_ZCE;/* '<S10>/Activate Ready to drive' */
  ZCSigState Datasaving_Trig_ZCE;      /* '<S64>/Data saving' */
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

extern void flData2SigCnn1U();

/* Block signals (default storage) */
extern B B_n;

/* Block states (default storage) */
extern DW DW_l;

/* Zero-crossing (trigger) state */
extern PrevZCX PrevZCX_p;

/* Model entry point functions */
void VCU_TDN_initialize(void);
void VCU_TDN_step(int_T tid);

/* Exported data declaration */
#define PUSH__RWP
#include "EcoSectionDef.h"

/* Declaration for custom storage class: Calibration */
extern __RWP const volatile int16_T T_IGBT_conversion_bp[39];
                                   /* Referenced by: '<S43>/1-D Lookup Table' */
extern __RWP const volatile int16_T T_IGBT_conversion_cur[39];
                                   /* Referenced by: '<S43>/1-D Lookup Table' */
extern __RWP const volatile int16_T T_air_conversion_bp[29];
                                  /* Referenced by: '<S43>/1-D Lookup Table2' */
extern __RWP const volatile int16_T T_air_conversion_cur[29];
                                  /* Referenced by: '<S43>/1-D Lookup Table2' */
extern __RWP const volatile int16_T T_motor_conversion_bp[39];
                                  /* Referenced by: '<S43>/1-D Lookup Table1' */
extern __RWP const volatile int16_T T_motor_conversion_cur[39];
                                  /* Referenced by: '<S43>/1-D Lookup Table1' */
extern __RWP const volatile int16_T Vdc_bus_V_bp[42];
                                  /* Referenced by: '<S41>/1-D Lookup Table2' */
extern __RWP const volatile int16_T Vdc_bus_V_cur[42];
                                  /* Referenced by: '<S41>/1-D Lookup Table2' */

#define POP__RWP
#include "EcoSectionDef.h"
#define PUSH__MP
#include "EcoSectionDef.h"

/* Declaration for custom storage class: Measurement */
extern __MP uint16_T APPS_1;           /* '<S4>/APPS 1' */
extern __MP uint16_T APPS_2;           /* '<S4>/APPS 2' */
extern __MP boolean_T APPS_FAULT;      /* '<S13>/Logical Operator1' */
extern __MP real32_T APPS_M;           /* '<S14>/Gain3' */
extern __MP boolean_T BATT_FAN_ON;     /* '<S9>/Logical Operator4' */
extern __MP boolean_T BRK_CONTACTOR;   /* '<S10>/Brake contactor' */
extern __MP boolean_T BRK_PDL_FAULT;   /* '<S6>/Logical Operator1' */
extern __MP int16_T CURRENT_CH_1;      /* '<S65>/Data Type Conversion2' */
extern __MP int16_T CURRENT_CH_2;      /* '<S65>/Data Type Conversion3' */
extern __MP boolean_T FAN_ON;          /* '<S9>/Logical Operator2' */
extern __MP real32_T FR_BRK_PRESSURE;  /* '<S65>/Data Type Conversion' */
extern __MP int16_T I_200;             /* '<S67>/Data Type Conversion' */
extern __MP int16_T I_act_filt;        /* '<S68>/Data Type Conversion' */
extern __MP int16_T I_act_filt_A;      /* '<S41>/Data Type Conversion1' */
extern __MP int16_T I_cmd;             /* '<S69>/Data Type Conversion' */
extern __MP int16_T I_device;          /* '<S70>/Data Type Conversion' */
extern __MP int16_T I_max_eff;         /* '<S71>/Data Type Conversion' */
extern __MP int16_T I_max_pk;          /* '<S72>/Data Type Conversion' */
extern __MP int16_T I_nom_eff;         /* '<S73>/Data Type Conversion' */
extern __MP int16_T M_R_Acc;           /* '<S78>/Data Type Conversion1' */
extern __MP int16_T M_R_Dec;           /* '<S79>/Data Type Conversion1' */
extern __MP uint16_T N_100;            /* '<S74>/Data Type Conversion' */
extern __MP int16_T N_R_Acc;           /* '<S78>/Data Type Conversion2' */
extern __MP int16_T N_R_Dec;           /* '<S79>/Data Type Conversion2' */
extern __MP int16_T N_act_filt;        /* '<S80>/Data Type Conversion' */
extern __MP int16_T N_act_filt_RPM;    /* '<S42>/Data Type Conversion' */
extern __MP uint16_T N_lim;            /* '<S75>/Data Type Conversion' */
extern __MP int16_T N_lim_neg;         /* '<S76>/Data Type Conversion' */
extern __MP int16_T N_lim_pos;         /* '<S77>/Data Type Conversion' */
extern __MP boolean_T PUMP_ON;         /* '<S9>/Logical Operator3' */
extern __MP boolean_T PwrM_flgKeyOnDelay;/* '<S125>/debounce' */
extern __MP boolean_T PwrM_flgKeyOnRaw;/* '<S118>/Switch' */
extern __MP boolean_T RDY_DRV;         /* '<S57>/Switch' */
extern __MP boolean_T RDY_DRV_BUTTON;  /* '<S10>/Logical Operator' */
extern __MP real32_T RR_BRAKE_PRESSURE;/* '<S65>/Data Type Conversion1' */
extern __MP int16_T Speed;             /* '<S42>/Data Type Conversion1' */
extern __MP int16_T SpeedRPMmax;       /* '<S81>/Data Type Conversion' */
extern __MP int16_T T_IGBT;            /* '<S82>/Data Type Conversion' */
extern __MP int16_T T_IGBT_deg;        /* '<S43>/1-D Lookup Table' */
extern __MP int16_T T_air;             /* '<S83>/Data Type Conversion' */
extern __MP int16_T T_air_deg;         /* '<S43>/1-D Lookup Table2' */
extern __MP int16_T T_motor;           /* '<S84>/Data Type Conversion' */
extern __MP int16_T T_motor_deg;       /* '<S43>/1-D Lookup Table1' */
extern __MP int16_T Vdc_bus;           /* '<S85>/Data Type Conversion' */
extern __MP int16_T Vdc_bus_V;         /* '<S41>/1-D Lookup Table2' */

#define POP__MP
#include "EcoSectionDef.h"

extern ;                         // uint16_T nvmAPPS_1;  /* synthesized block */
extern ;                         // uint16_T nvmAPPS_2;  /* synthesized block */
extern ;                    // boolean_T nvmAPPS_FAULT;  /* synthesized block */
extern ;                         // real32_T nvmAPPS_M;  /* synthesized block */
extern ;                   // boolean_T nvmBATT_FAN_ON;  /* synthesized block */
extern ;                 // boolean_T nvmBRK_CONTACTOR;  /* synthesized block */
extern ;                 // boolean_T nvmBRK_PDL_FAULT;  /* synthesized block */
extern ;                        // boolean_T nvmFAN_ON;  /* synthesized block */
extern ;                           // int16_T nvmI_200;  /* synthesized block */
extern ;                      // int16_T nvmI_act_filt;  /* synthesized block */
extern ;                    // int16_T nvmI_act_filt_A;  /* synthesized block */
extern ;                           // int16_T nvmI_cmd;  /* synthesized block */
extern ;                        // int16_T nvmI_device;  /* synthesized block */
extern ;                       // int16_T nvmI_max_eff;  /* synthesized block */
extern ;                        // int16_T nvmI_max_pk;  /* synthesized block */
extern ;                       // int16_T nvmI_nom_eff;  /* synthesized block */
extern ;                         // int16_T nvmM_R_Acc;  /* synthesized block */
extern ;                         // int16_T nvmM_R_Dec;  /* synthesized block */
extern ;                          // uint16_T nvmN_100;  /* synthesized block */
extern ;                         // int16_T nvmN_R_Acc;  /* synthesized block */
extern ;                         // int16_T nvmN_R_Dec;  /* synthesized block */
extern ;                      // int16_T nvmN_act_filt;  /* synthesized block */
extern ;                  // int16_T nvmN_act_filt_RPM;  /* synthesized block */
extern ;                          // uint16_T nvmN_lim;  /* synthesized block */
extern ;                       // int16_T nvmN_lim_neg;  /* synthesized block */
extern ;                       // int16_T nvmN_lim_pos;  /* synthesized block */
extern ;                       // boolean_T nvmPUMP_ON;  /* synthesized block */
extern ;                       // boolean_T nvmRDY_DRV;  /* synthesized block */
extern ;                // boolean_T nvmRDY_DRV_BUTTON;  /* synthesized block */
extern ;                           // int16_T nvmSpeed;  /* synthesized block */
extern ;                     // int16_T nvmSpeedRPMmax;  /* synthesized block */
extern ;                          // int16_T nvmT_IGBT;  /* synthesized block */
extern ;                      // int16_T nvmT_IGBT_deg;  /* synthesized block */
extern ;                           // int16_T nvmT_air;  /* synthesized block */
extern ;                       // int16_T nvmT_air_deg;  /* synthesized block */
extern ;                         // int16_T nvmT_motor;  /* synthesized block */
extern ;                     // int16_T nvmT_motor_deg;  /* synthesized block */
extern ;                         // int16_T nvmVdc_bus;  /* synthesized block */
extern ;                       // int16_T nvmVdc_bus_V;  /* synthesized block */

/* Real-time Model object */
extern RT_MODEL *const M;
extern void VCU_TDN_step0(void);       /* Sample time: [0.001s, 0.0s] */
extern void VCU_TDN_step1(void);       /* Sample time: [0.005s, 0.0s] */
extern void VCU_TDN_step2(void);       /* Sample time: [0.01s, 0.0s]  */
extern void VCU_TDN_step3(void);       /* Sample time: [0.02s, 0.0s]  */
extern void VCU_TDN_step4(void);       /* Sample time: [0.05s, 0.0s]  */
extern void VCU_TDN_step5(void);       /* Sample time: [0.1s, 0.0s]   */
extern void VCU_TDN_step6(void);       /* Sample time: [0.2s, 0.0s]   */
extern void VCU_TDN_step7(void);       /* Sample time: [0.5s, 0.0s]   */
extern void VCU_TDN_step8(void);       /* Sample time: [1.0s, 0.0s]   */
extern uint8_T EcoCoder_Target_Setting;
extern void ASW_H1ms1U(void);
extern TASK_Node nodeASW_H1ms1U;
extern void ASW_H1ms2U(void);
extern TASK_Node nodeASW_H1ms2U;
extern void ASW_H1ms3U(void);
extern TASK_Node nodeASW_H1ms3U;
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
 * '<Root>' : 'VCU_TDN'
 * '<S1>'   : 'VCU_TDN/Code'
 * '<S2>'   : 'VCU_TDN/EcoCoder Target Definition'
 * '<S3>'   : 'VCU_TDN/Power Management Example'
 * '<S4>'   : 'VCU_TDN/Code/APPS and torque setpoint'
 * '<S5>'   : 'VCU_TDN/Code/Asking data from the inverter'
 * '<S6>'   : 'VCU_TDN/Code/Brake pedal plausibility check'
 * '<S7>'   : 'VCU_TDN/Code/Data processing'
 * '<S8>'   : 'VCU_TDN/Code/Initialization'
 * '<S9>'   : 'VCU_TDN/Code/Pump and fans'
 * '<S10>'  : 'VCU_TDN/Code/Ready to drive'
 * '<S11>'  : 'VCU_TDN/Code/Receiving data'
 * '<S12>'  : 'VCU_TDN/Code/Sending data to the dashboard'
 * '<S13>'  : 'VCU_TDN/Code/APPS and torque setpoint/APPS Fault detection'
 * '<S14>'  : 'VCU_TDN/Code/APPS and torque setpoint/Throttle setpoint for the inverter'
 * '<S15>'  : 'VCU_TDN/Code/APPS and torque setpoint/Write and Read Measurement'
 * '<S16>'  : 'VCU_TDN/Code/APPS and torque setpoint/Write and Read Measurement1'
 * '<S17>'  : 'VCU_TDN/Code/APPS and torque setpoint/APPS Fault detection/Compare To Constant'
 * '<S18>'  : 'VCU_TDN/Code/APPS and torque setpoint/APPS Fault detection/Write Measurement'
 * '<S19>'  : 'VCU_TDN/Code/APPS and torque setpoint/Throttle setpoint for the inverter/Write Measurement'
 * '<S20>'  : 'VCU_TDN/Code/Asking data from the inverter/I_200'
 * '<S21>'  : 'VCU_TDN/Code/Asking data from the inverter/I_act_filt'
 * '<S22>'  : 'VCU_TDN/Code/Asking data from the inverter/I_cmd'
 * '<S23>'  : 'VCU_TDN/Code/Asking data from the inverter/I_device'
 * '<S24>'  : 'VCU_TDN/Code/Asking data from the inverter/I_max_eff'
 * '<S25>'  : 'VCU_TDN/Code/Asking data from the inverter/I_max_pk'
 * '<S26>'  : 'VCU_TDN/Code/Asking data from the inverter/I_nom_eff'
 * '<S27>'  : 'VCU_TDN/Code/Asking data from the inverter/N_100'
 * '<S28>'  : 'VCU_TDN/Code/Asking data from the inverter/N_Lim'
 * '<S29>'  : 'VCU_TDN/Code/Asking data from the inverter/N_Lim_neg'
 * '<S30>'  : 'VCU_TDN/Code/Asking data from the inverter/N_Lim_pos'
 * '<S31>'  : 'VCU_TDN/Code/Asking data from the inverter/N_R_Acc | M_R_Acc'
 * '<S32>'  : 'VCU_TDN/Code/Asking data from the inverter/N_R_Dec | M_R_Dec'
 * '<S33>'  : 'VCU_TDN/Code/Asking data from the inverter/N_act_filt'
 * '<S34>'  : 'VCU_TDN/Code/Asking data from the inverter/SpeedRPMmax'
 * '<S35>'  : 'VCU_TDN/Code/Asking data from the inverter/T_IGBT'
 * '<S36>'  : 'VCU_TDN/Code/Asking data from the inverter/T_air'
 * '<S37>'  : 'VCU_TDN/Code/Asking data from the inverter/T_motor'
 * '<S38>'  : 'VCU_TDN/Code/Asking data from the inverter/Vdc_bus'
 * '<S39>'  : 'VCU_TDN/Code/Brake pedal plausibility check/Compare To Constant'
 * '<S40>'  : 'VCU_TDN/Code/Brake pedal plausibility check/Write Measurement'
 * '<S41>'  : 'VCU_TDN/Code/Data processing/Electrical'
 * '<S42>'  : 'VCU_TDN/Code/Data processing/Speed'
 * '<S43>'  : 'VCU_TDN/Code/Data processing/Temperature'
 * '<S44>'  : 'VCU_TDN/Code/Data processing/Electrical/Write and Read Measurement1'
 * '<S45>'  : 'VCU_TDN/Code/Data processing/Electrical/Write and Read Measurement3'
 * '<S46>'  : 'VCU_TDN/Code/Data processing/Speed/Write and Read Measurement'
 * '<S47>'  : 'VCU_TDN/Code/Data processing/Speed/Write and Read Measurement1'
 * '<S48>'  : 'VCU_TDN/Code/Data processing/Temperature/Write and Read Measurement1'
 * '<S49>'  : 'VCU_TDN/Code/Data processing/Temperature/Write and Read Measurement2'
 * '<S50>'  : 'VCU_TDN/Code/Data processing/Temperature/Write and Read Measurement3'
 * '<S51>'  : 'VCU_TDN/Code/Initialization/Disabling the inverter'
 * '<S52>'  : 'VCU_TDN/Code/Pump and fans/Write and Read Measurement'
 * '<S53>'  : 'VCU_TDN/Code/Pump and fans/Write and Read Measurement1'
 * '<S54>'  : 'VCU_TDN/Code/Pump and fans/Write and Read Measurement2'
 * '<S55>'  : 'VCU_TDN/Code/Ready to drive/Activate Ready to drive'
 * '<S56>'  : 'VCU_TDN/Code/Ready to drive/Deactivate Ready to drive'
 * '<S57>'  : 'VCU_TDN/Code/Ready to drive/SR Flip Flop'
 * '<S58>'  : 'VCU_TDN/Code/Ready to drive/Stop RTD sound'
 * '<S59>'  : 'VCU_TDN/Code/Ready to drive/Write and Read Measurement'
 * '<S60>'  : 'VCU_TDN/Code/Ready to drive/Write and Read Measurement1'
 * '<S61>'  : 'VCU_TDN/Code/Ready to drive/Write and Read Measurement2'
 * '<S62>'  : 'VCU_TDN/Code/Ready to drive/Activate Ready to drive/Enabling the inverter'
 * '<S63>'  : 'VCU_TDN/Code/Ready to drive/Deactivate Ready to drive/Disabling the inverter'
 * '<S64>'  : 'VCU_TDN/Code/Receiving data/Inverter'
 * '<S65>'  : 'VCU_TDN/Code/Receiving data/Sensors'
 * '<S66>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving'
 * '<S67>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/I_200'
 * '<S68>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/I_act_filt'
 * '<S69>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/I_cmd'
 * '<S70>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/I_device'
 * '<S71>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/I_max_eff'
 * '<S72>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/I_max_pk'
 * '<S73>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/I_nom_eff'
 * '<S74>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_100'
 * '<S75>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_Lim'
 * '<S76>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_Lim_neg'
 * '<S77>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_Lim_pos'
 * '<S78>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_R_Acc | M R_Acc'
 * '<S79>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_R_Dec | M_R_Dec'
 * '<S80>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_act_filt'
 * '<S81>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/SpeedRPMmax'
 * '<S82>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/T_IGBT'
 * '<S83>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/T_air'
 * '<S84>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/T_motor'
 * '<S85>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/Vdc_bus'
 * '<S86>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/I_200/Write and Read Measurement'
 * '<S87>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/I_act_filt/Write and Read Measurement'
 * '<S88>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/I_cmd/Write and Read Measurement'
 * '<S89>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/I_device/Write and Read Measurement'
 * '<S90>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/I_max_eff/Write and Read Measurement'
 * '<S91>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/I_max_pk/Write and Read Measurement'
 * '<S92>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/I_nom_eff/Write and Read Measurement'
 * '<S93>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_100/Write and Read Measurement'
 * '<S94>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_Lim/Write and Read Measurement'
 * '<S95>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_Lim_neg/Write and Read Measurement'
 * '<S96>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_Lim_pos/Write and Read Measurement'
 * '<S97>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_R_Acc | M R_Acc/Extract Bits'
 * '<S98>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_R_Acc | M R_Acc/Extract Bits1'
 * '<S99>'  : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_R_Acc | M R_Acc/Write and Read Measurement'
 * '<S100>' : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_R_Acc | M R_Acc/Write and Read Measurement1'
 * '<S101>' : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_R_Dec | M_R_Dec/Extract Bits'
 * '<S102>' : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_R_Dec | M_R_Dec/Extract Bits1'
 * '<S103>' : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_R_Dec | M_R_Dec/Write and Read Measurement'
 * '<S104>' : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_R_Dec | M_R_Dec/Write and Read Measurement1'
 * '<S105>' : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/N_act_filt/Write and Read Measurement'
 * '<S106>' : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/SpeedRPMmax/Write and Read Measurement'
 * '<S107>' : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/T_IGBT/Write and Read Measurement'
 * '<S108>' : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/T_air/Write and Read Measurement'
 * '<S109>' : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/T_motor/Write and Read Measurement'
 * '<S110>' : 'VCU_TDN/Code/Receiving data/Inverter/Data saving/Vdc_bus/Write and Read Measurement'
 * '<S111>' : 'VCU_TDN/Code/Receiving data/Sensors/Write Measurement'
 * '<S112>' : 'VCU_TDN/Code/Receiving data/Sensors/Write Measurement1'
 * '<S113>' : 'VCU_TDN/Code/Receiving data/Sensors/Write Measurement2'
 * '<S114>' : 'VCU_TDN/Code/Receiving data/Sensors/Write Measurement3'
 * '<S115>' : 'VCU_TDN/EcoCoder Target Definition/FunctionNull'
 * '<S116>' : 'VCU_TDN/Power Management Example/Power Off Management'
 * '<S117>' : 'VCU_TDN/Power Management Example/Power On Init'
 * '<S118>' : 'VCU_TDN/Power Management Example/Power Off Management/Get flgKeyOn'
 * '<S119>' : 'VCU_TDN/Power Management Example/Power Off Management/KeyCycle'
 * '<S120>' : 'VCU_TDN/Power Management Example/Power Off Management/Shutdown Power'
 * '<S121>' : 'VCU_TDN/Power Management Example/Power Off Management/Shutdown Power Hold'
 * '<S122>' : 'VCU_TDN/Power Management Example/Power Off Management/Software Reset'
 * '<S123>' : 'VCU_TDN/Power Management Example/Power Off Management/Software Reset Hold'
 * '<S124>' : 'VCU_TDN/Power Management Example/Power Off Management/Store All NVM Data'
 * '<S125>' : 'VCU_TDN/Power Management Example/Power Off Management/TOfD_xxxx1'
 * '<S126>' : 'VCU_TDN/Power Management Example/Power Off Management/Write and Read Measurement'
 * '<S127>' : 'VCU_TDN/Power Management Example/Power Off Management/Write and Read Measurement1'
 * '<S128>' : 'VCU_TDN/Power Management Example/Power Off Management/KeyCycle/ER_xxxx'
 * '<S129>' : 'VCU_TDN/Power Management Example/Power Off Management/KeyCycle/ER_xxxx1'
 * '<S130>' : 'VCU_TDN/Power Management Example/Power Off Management/KeyCycle/RSFF_xxxx'
 * '<S131>' : 'VCU_TDN/Power Management Example/Power Off Management/KeyCycle/Reset_Action'
 * '<S132>' : 'VCU_TDN/Power Management Example/Power Off Management/KeyCycle/TOfD_xxxx'
 * '<S133>' : 'VCU_TDN/Power Management Example/Power Off Management/KeyCycle/edgeDbncRise'
 * '<S134>' : 'VCU_TDN/Power Management Example/Power Off Management/KeyCycle/TOfD_xxxx/DebounceTimer'
 * '<S135>' : 'VCU_TDN/Power Management Example/Power Off Management/KeyCycle/TOfD_xxxx/DebounceTimer/dt'
 * '<S136>' : 'VCU_TDN/Power Management Example/Power Off Management/KeyCycle/edgeDbncRise/DebounceTimer'
 * '<S137>' : 'VCU_TDN/Power Management Example/Power Off Management/KeyCycle/edgeDbncRise/DebounceTimer/dt'
 * '<S138>' : 'VCU_TDN/Power Management Example/Power Off Management/TOfD_xxxx1/DebounceTimer'
 * '<S139>' : 'VCU_TDN/Power Management Example/Power Off Management/TOfD_xxxx1/DebounceTimer/dt'
 * '<S140>' : 'VCU_TDN/Power Management Example/Power On Init/Restore NVM Data'
 */
#endif                                 /* RTW_HEADER_VCU_TDN_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
