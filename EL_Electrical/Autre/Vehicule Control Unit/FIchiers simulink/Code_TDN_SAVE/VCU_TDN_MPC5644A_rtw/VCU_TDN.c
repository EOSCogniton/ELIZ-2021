/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VCU_TDN.c
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

#include "VCU_TDN.h"
#include "MultiWord2sLong.h"
#include "div_s16s32_floor.h"
#include "look1_is16lu32n32ys16D_604HKI8a.h"
#include "sMultiWordMul.h"
#include "sMultiWordShr.h"

TASK_Node nodeASW_H1ms1U;
TASK_Node nodeASW_H1ms2U;
TASK_Node nodeASW_H1ms3U;

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
#define PUSH__RWP
#include "EcoSectionDef.h"

/* Definition for custom storage class: Calibration */
__RWP const volatile int16_T T_IGBT_conversion_bp[39] = { 16245, 16308, 16387,
  16487, 16609, 16759, 16938, 17151, 17400, 17688, 18017, 18387, 18797, 19247,
  19733, 20250, 20793, 21357, 21933, 22515, 23097, 23671, 24232, 24775, 25296,
  25792, 26261, 26702, 27114, 27497, 27851, 28179, 28480, 28757, 29011, 29243,
  29456, 29650, 29827 } ;          /* Referenced by: '<S43>/1-D Lookup Table' */

__RWP const volatile int16_T T_IGBT_conversion_cur[39] = { -35, -30, -25, -20,
  -15, -10, -5, 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80,
  85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155 } ;
                                   /* Referenced by: '<S43>/1-D Lookup Table' */

__RWP const volatile int16_T T_air_conversion_bp[29] = { 8516, 8785, 9054, 9322,
  9590, 9857, 10122, 10386, 10647, 10907, 11163, 11418, 11669, 11917, 12163,
  12404, 12643, 12878, 13109, 13337, 13561, 13781, 13998, 14210, 14419, 14624,
  14825, 15022, 15215 } ;         /* Referenced by: '<S43>/1-D Lookup Table2' */

__RWP const volatile int16_T T_air_conversion_cur[29] = { -35, -30, -25, -20,
  -15, -10, -5, 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80,
  85, 90, 95, 100, 105 } ;        /* Referenced by: '<S43>/1-D Lookup Table2' */

__RWP const volatile int16_T T_motor_conversion_bp[39] = { 7414, 7687, 7962,
  8240, 8520, 8802, 9085, 9369, 9654, 9939, 10225, 10510, 10795, 11080, 11364,
  11646, 11927, 12207, 12485, 12762, 13036, 13308, 13578, 13846, 14111, 14373,
  14633, 14890, 15144, 15391, 15628, 15852, 16061, 16251, 16421, 16569, 16692,
  16789, 16857 } ;                /* Referenced by: '<S43>/1-D Lookup Table1' */

__RWP const volatile int16_T T_motor_conversion_cur[39] = { -35, -30, -25, -20,
  -15, -10, -5, 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80,
  85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155 } ;
                                  /* Referenced by: '<S43>/1-D Lookup Table1' */

__RWP const volatile int16_T Vdc_bus_V_bp[42] = { 0, 748, 1537, 2327, 3117, 3906,
  4696, 5485, 6275, 7065, 7854, 8644, 9434, 10223, 11013, 11802, 12592, 13382,
  14171, 14961, 15751, 16540, 17330, 18119, 18909, 19699, 20488, 21278, 22067,
  22857, 23647, 24436, 25226, 26016, 26805, 27595, 28384, 29174, 29964, 30753,
  31543, 31751 } ;                /* Referenced by: '<S41>/1-D Lookup Table2' */

__RWP const volatile int16_T Vdc_bus_V_cur[42] = { 0, 25, 50, 75, 100, 125, 150,
  175, 200, 225, 250, 275, 300, 325, 350, 375, 400, 425, 450, 475, 500, 525, 550,
  575, 600, 625, 650, 675, 700, 725, 750, 775, 800, 825, 850, 875, 900, 925, 950,
  975, 1000, 1025 } ;             /* Referenced by: '<S41>/1-D Lookup Table2' */

#define POP__RWP
#include "EcoSectionDef.h"
#define PUSH__MP
#include "EcoSectionDef.h"

/* Definition for custom storage class: Measurement */
__MP uint16_T APPS_1;                  /* '<S4>/APPS 1' */
__MP uint16_T APPS_2;                  /* '<S4>/APPS 2' */
__MP boolean_T APPS_FAULT;             /* '<S13>/Logical Operator1' */
__MP real32_T APPS_M;                  /* '<S14>/Gain3' */
__MP boolean_T BATT_FAN_ON;            /* '<S9>/Logical Operator4' */
__MP boolean_T BRK_CONTACTOR;          /* '<S10>/Brake contactor' */
__MP boolean_T BRK_PDL_FAULT;          /* '<S6>/Logical Operator1' */
__MP int16_T CURRENT_CH_1;             /* '<S65>/Data Type Conversion2' */
__MP int16_T CURRENT_CH_2;             /* '<S65>/Data Type Conversion3' */
__MP boolean_T FAN_ON;                 /* '<S9>/Logical Operator2' */
__MP real32_T FR_BRK_PRESSURE;         /* '<S65>/Data Type Conversion' */
__MP int16_T I_200;                    /* '<S67>/Data Type Conversion' */
__MP int16_T I_act_filt;               /* '<S68>/Data Type Conversion' */
__MP int16_T I_act_filt_A;             /* '<S41>/Data Type Conversion1' */
__MP int16_T I_cmd;                    /* '<S69>/Data Type Conversion' */
__MP int16_T I_device;                 /* '<S70>/Data Type Conversion' */
__MP int16_T I_max_eff;                /* '<S71>/Data Type Conversion' */
__MP int16_T I_max_pk;                 /* '<S72>/Data Type Conversion' */
__MP int16_T I_nom_eff;                /* '<S73>/Data Type Conversion' */
__MP int16_T M_R_Acc;                  /* '<S78>/Data Type Conversion1' */
__MP int16_T M_R_Dec;                  /* '<S79>/Data Type Conversion1' */
__MP uint16_T N_100;                   /* '<S74>/Data Type Conversion' */
__MP int16_T N_R_Acc;                  /* '<S78>/Data Type Conversion2' */
__MP int16_T N_R_Dec;                  /* '<S79>/Data Type Conversion2' */
__MP int16_T N_act_filt;               /* '<S80>/Data Type Conversion' */
__MP int16_T N_act_filt_RPM;           /* '<S42>/Data Type Conversion' */
__MP uint16_T N_lim;                   /* '<S75>/Data Type Conversion' */
__MP int16_T N_lim_neg;                /* '<S76>/Data Type Conversion' */
__MP int16_T N_lim_pos;                /* '<S77>/Data Type Conversion' */
__MP boolean_T PUMP_ON;                /* '<S9>/Logical Operator3' */
__MP boolean_T PwrM_flgKeyOnDelay;     /* '<S125>/debounce' */
__MP boolean_T PwrM_flgKeyOnRaw;       /* '<S118>/Switch' */
__MP boolean_T RDY_DRV;                /* '<S57>/Switch' */
__MP boolean_T RDY_DRV_BUTTON;         /* '<S10>/Logical Operator' */
__MP real32_T RR_BRAKE_PRESSURE;       /* '<S65>/Data Type Conversion1' */
__MP int16_T Speed;                    /* '<S42>/Data Type Conversion1' */
__MP int16_T SpeedRPMmax;              /* '<S81>/Data Type Conversion' */
__MP int16_T T_IGBT;                   /* '<S82>/Data Type Conversion' */
__MP int16_T T_IGBT_deg;               /* '<S43>/1-D Lookup Table' */
__MP int16_T T_air;                    /* '<S83>/Data Type Conversion' */
__MP int16_T T_air_deg;                /* '<S43>/1-D Lookup Table2' */
__MP int16_T T_motor;                  /* '<S84>/Data Type Conversion' */
__MP int16_T T_motor_deg;              /* '<S43>/1-D Lookup Table1' */
__MP int16_T Vdc_bus;                  /* '<S85>/Data Type Conversion' */
__MP int16_T Vdc_bus_V;                /* '<S41>/1-D Lookup Table2' */

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
void VCU_TDN_step0(void);
void VCU_TDN_step1(void);
void VCU_TDN_step2(void);
void VCU_TDN_step3(void);
void VCU_TDN_step4(void);
void VCU_TDN_step5(void);
void VCU_TDN_step6(void);
void VCU_TDN_step7(void);
void VCU_TDN_step8(void);
uint8_T EcoCoder_Target_Setting;
void ASW_H1ms1U(void)
{
  /* -- Call CAN RX Fcn-Call_0 -- */

  /* Output and update for function-call system: '<S1>/APPS and torque setpoint' */
  {
    int_T i;
    real32_T Gain2;

    /* Logic: '<S13>/Logical Operator1' incorporates:
     *  S-Function (sfix_udelay): '<S13>/Tapped Delay'
     */
    APPS_FAULT = DW_l.TappedDelay_X_i5[0];
    for (i = 0; i < 89; i++) {
      APPS_FAULT = (APPS_FAULT && DW_l.TappedDelay_X_i5[i + 1]);
    }

    /* End of Logic: '<S13>/Logical Operator1' */

    /* S-Function (EcoCoder_NVM_VarWrite): '<S13>/Write NVM' */
    nvmAPPS_FAULT[0]= ((&(APPS_FAULT)))[0];

    /* S-Function (ADC): '<S4>/APPS 1' */
    APPS_1 = F_Abstr_ADC_GetValue(ABS_ADC_6);

    /* S-Function (ADC): '<S4>/APPS 2' */
    APPS_2 = F_Abstr_ADC_GetValue(ABS_ADC_7);

    /* RelationalOperator: '<S17>/Compare' incorporates:
     *  Constant: '<S17>/Constant'
     *  Sum: '<S13>/Subtract'
     */
    B_n.Compare_g = ((uint16_T)(APPS_1 - APPS_2) >= 369);

    /* Gain: '<S14>/Gain1' incorporates:
     *  DataTypeConversion: '<S14>/Data Type Conversion2'
     *  Sum: '<S14>/Add'
     */
    Gain2 = (real32_T)(uint16_T)((uint32_T)APPS_1 + APPS_2) * 0.5F;

    /* DeadZone: '<S14>/Dead Zone1' */
    if (Gain2 > 5.0F) {
      Gain2 -= 5.0F;
    } else {
      Gain2 = 0.0F;
    }

    /* End of DeadZone: '<S14>/Dead Zone1' */

    /* Saturate: '<S14>/Saturation' */
    if (Gain2 > 4096.0F) {
      Gain2 = 4096.0F;
    }

    /* End of Saturate: '<S14>/Saturation' */

    /* Gain: '<S14>/Gain3' */
    APPS_M = 0.0244140625F * Gain2;

    /* S-Function (EcoCoder_NVM_VarWrite): '<S14>/Write NVM' */
    nvmAPPS_M[0]= ((&(APPS_M)))[0];

    /* Gain: '<S14>/Gain2' */
    Gain2 *= 7.99975586F;

    /* DataTypeConversion: '<S14>/Data Type Conversion1' */
    B_n.DataTypeConversion1 = (int16_T)(real32_T)floor(Gain2);

    /* S-Function (CoderCAN_PackBit2Data): '<S14>/Pack Signals To CAN Data1' incorporates:
     *  Constant: '<S14>/Constant1'
     */

    /* --------------- Start pack signal from message -----------------------------
       The number of signals is 2
       ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

    /**********Pack signal 1:startBit= 8U length = 16U byteOrder = LITTLEENDIAN dataType= int16_T**********/
    B_n.PackSignalsToCANData1[0] = (uint8_T)((uint8_T)((((uint8_T)49U) & 0xFF)));
    B_n.PackSignalsToCANData1[1] = (uint8_T)((uint8_T)((B_n.DataTypeConversion1
      & 0xFF)));
    B_n.PackSignalsToCANData1[2] = (uint8_T)((uint8_T)((B_n.DataTypeConversion1
      & 0xFF00)>>8U));
    B_n.PackSignalsToCANData1[3] = (uint8_T)(0);
    B_n.PackSignalsToCANData1[4] = (uint8_T)(0);
    B_n.PackSignalsToCANData1[5] = (uint8_T)(0);
    B_n.PackSignalsToCANData1[6] = (uint8_T)(0);
    B_n.PackSignalsToCANData1[7] = (uint8_T)(0);

    /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
       --------------------------------------------------------------------------------*/

    /* S-Function (CAN_TxData): '<S14>/Send CAN Data1' */
    F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData1[0]));

    /* S-Function (EcoCoder_NVM_VarWrite): '<S4>/Write NVM' */
    nvmAPPS_1[0]= ((&(APPS_1)))[0];

    /* S-Function (EcoCoder_NVM_VarWrite): '<S4>/Write NVM1' */
    nvmAPPS_2[0]= ((&(APPS_2)))[0];

    /* Update for S-Function (sfix_udelay): '<S13>/Tapped Delay' */
    for (i = 0; i < 89; i++) {
      DW_l.TappedDelay_X_i5[i] = DW_l.TappedDelay_X_i5[i + 1];
    }

    DW_l.TappedDelay_X_i5[89] = B_n.Compare_g;

    /* End of Update for S-Function (sfix_udelay): '<S13>/Tapped Delay' */
  }
}

void ASW_H1ms2U(void)
{
  /* -- Call CAN RX Fcn-Call_0 -- */

  /* Output and update for function-call system: '<S1>/Brake pedal plausibility check' */
  {
    int_T i;

    /* Logic: '<S6>/Logical Operator1' incorporates:
     *  S-Function (sfix_udelay): '<S6>/Tapped Delay'
     */
    BRK_PDL_FAULT = DW_l.TappedDelay_X[0];
    for (i = 0; i < 489; i++) {
      BRK_PDL_FAULT = (BRK_PDL_FAULT && DW_l.TappedDelay_X[i + 1]);
    }

    /* End of Logic: '<S6>/Logical Operator1' */

    /* S-Function (EcoCoder_NVM_VarWrite): '<S6>/Write NVM' */
    nvmBRK_PDL_FAULT[0]= ((&(BRK_PDL_FAULT)))[0];

    /* S-Function (ecocoder_nvm_read): '<S6>/Read NVM' */
    (&B_n.ReadNVM)[0] = nvmAPPS_M[0];

    /* S-Function (ecocoder_nvm_read): '<S6>/Read NVM1' */
    (&B_n.ReadNVM1_g)[0] = nvmBRK_CONTACTOR[0];

    /* Logic: '<S6>/Logical Operator' incorporates:
     *  Constant: '<S39>/Constant'
     *  RelationalOperator: '<S39>/Compare'
     */
    B_n.LogicalOperator_n = ((B_n.ReadNVM >= 5.0F) && B_n.ReadNVM1_g);

    /* Update for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
    for (i = 0; i < 489; i++) {
      DW_l.TappedDelay_X[i] = DW_l.TappedDelay_X[i + 1];
    }

    DW_l.TappedDelay_X[489] = B_n.LogicalOperator_n;

    /* End of Update for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
  }
}

void ASW_H1ms3U(void)
{
  /* -- Call CAN RX Fcn-Call_0 -- */

  /* Output and update for function-call system: '<S1>/Ready to drive' */
  {
    int_T i;
    boolean_T tmp;
    boolean_T LogicalOperator3;

    /* S-Function (DIO_In): '<S10>/Brake contactor' */
    BRK_CONTACTOR= F_Abstr_DI_GetValue(ABS_DI18);

    /* S-Function (EcoCoder_NVM_VarWrite): '<S10>/Write NVM' */
    nvmBRK_CONTACTOR[0]= ((&(BRK_CONTACTOR)))[0];

    /* S-Function (DIO_In): '<S10>/Ready to drive button' */
    B_n.Readytodrivebutton= F_Abstr_DI_GetValue(ABS_DI01);

    /* Logic: '<S10>/Logical Operator' */
    RDY_DRV_BUTTON = !B_n.Readytodrivebutton;

    /* S-Function (EcoCoder_NVM_VarWrite): '<S10>/Write NVM1' */
    nvmRDY_DRV_BUTTON[0]= ((&(RDY_DRV_BUTTON)))[0];

    /* Logic: '<S10>/Logical Operator2' incorporates:
     *  S-Function (sfix_udelay): '<S10>/Tapped Delay'
     */
    tmp = DW_l.TappedDelay_X_i[0];
    for (i = 0; i < 999; i++) {
      tmp = (tmp && DW_l.TappedDelay_X_i[i + 1]);
    }

    /* S-Function (ecocoder_nvm_read): '<S10>/Read NVM' */
    (&B_n.ReadNVM_my)[0] = nvmAPPS_FAULT[0];

    /* S-Function (ecocoder_nvm_read): '<S10>/Read NVM1' */
    (&B_n.ReadNVM1_d)[0] = nvmBRK_PDL_FAULT[0];

    /* Logic: '<S10>/Logical Operator3' */
    LogicalOperator3 = (B_n.ReadNVM_my || B_n.ReadNVM1_d);

    /* Outputs for Atomic SubSystem: '<S10>/SR Flip Flop' */
    /* Switch: '<S57>/Switch' incorporates:
     *  Constant: '<S57>/Constant2'
     *  Logic: '<S10>/Logical Operator2'
     *  UnitDelay: '<S57>/Unit Delay1'
     */
    if (LogicalOperator3) {
      RDY_DRV = false;
    } else {
      RDY_DRV = (tmp || RDY_DRV);
    }

    /* End of Switch: '<S57>/Switch' */
    /* End of Outputs for SubSystem: '<S10>/SR Flip Flop' */

    /* S-Function (EcoCoder_NVM_VarWrite): '<S10>/Write NVM2' */
    nvmRDY_DRV[0]= ((&(RDY_DRV)))[0];

    /* Outputs for Triggered SubSystem: '<S10>/Activate Ready to drive' incorporates:
     *  TriggerPort: '<S55>/Trigger'
     */
    /* Logic: '<S10>/Logical Operator2' */
    if (tmp && (PrevZCX_p.ActivateReadytodrive_Trig_ZCE != POS_ZCSIG)) {
      /* S-Function (DIO_Out): '<S55>/RFE' incorporates:
       *  Constant: '<S55>/Constant'
       */
      F_Abstr_HLSO_SwitchSet(LSO06,true);

      /* S-Function (DIO_Out): '<S55>/FRG//RUN' incorporates:
       *  Constant: '<S55>/Constant1'
       */
      F_Abstr_HLSO_SwitchSet(LSO07,true);

      /* S-Function (DIO_Out): '<S55>/Ready to drive LED' incorporates:
       *  Constant: '<S55>/Constant3'
       */
      F_Abstr_HLSO_SwitchSet(LSO08,true);

      /* S-Function (DIO_Out): '<S55>/Ready to drive sound' incorporates:
       *  Constant: '<S55>/Constant4'
       */
      F_Abstr_HLSO_SwitchSet(LSO10,true);

      /* S-Function (CoderCAN_PackBit2Data): '<S62>/Pack Signals To CAN Data' incorporates:
       *  Constant: '<S62>/Constant'
       *  Constant: '<S62>/Constant1'
       */

      /* --------------- Start pack signal from message -----------------------------
         The number of signals is 2
         ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

      /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

      /**********Pack signal 1:startBit= 8U length = 16U byteOrder = LITTLEENDIAN dataType= uint16_T**********/
      B_n.PackSignalsToCANData_n[0] = (uint8_T)((uint8_T)((((uint8_T)81U) & 0xFF)));
      B_n.PackSignalsToCANData_n[1] = (uint8_T)((uint8_T)((((uint16_T)0U) & 0xFF)));
      B_n.PackSignalsToCANData_n[2] = (uint8_T)((uint8_T)((((uint16_T)0U) &
        0xFF00)>>8U));
      B_n.PackSignalsToCANData_n[3] = (uint8_T)(0);
      B_n.PackSignalsToCANData_n[4] = (uint8_T)(0);
      B_n.PackSignalsToCANData_n[5] = (uint8_T)(0);
      B_n.PackSignalsToCANData_n[6] = (uint8_T)(0);
      B_n.PackSignalsToCANData_n[7] = (uint8_T)(0);

      /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
         --------------------------------------------------------------------------------*/

      /* S-Function (CAN_TxData): '<S62>/Send CAN Data' */
      F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)
                   (&B_n.PackSignalsToCANData_n[0]));
    }

    PrevZCX_p.ActivateReadytodrive_Trig_ZCE = tmp;

    /* End of Outputs for SubSystem: '<S10>/Activate Ready to drive' */

    /* Outputs for Triggered SubSystem: '<S10>/Deactivate Ready to drive' incorporates:
     *  TriggerPort: '<S56>/Trigger'
     */
    if (LogicalOperator3 && (PrevZCX_p.DeactivateReadytodrive_Trig_ZCE !=
         POS_ZCSIG)) {
      /* S-Function (DIO_Out): '<S56>/RFE' incorporates:
       *  Constant: '<S56>/Constant'
       */
      F_Abstr_HLSO_SwitchSet(LSO06,false);

      /* S-Function (DIO_Out): '<S56>/FRG//RUN' incorporates:
       *  Constant: '<S56>/Constant1'
       */
      F_Abstr_HLSO_SwitchSet(LSO07,false);

      /* S-Function (DIO_Out): '<S56>/Ready to drive LED' incorporates:
       *  Constant: '<S56>/Constant3'
       */
      F_Abstr_HLSO_SwitchSet(LSO08,false);

      /* S-Function (CoderCAN_PackBit2Data): '<S63>/Pack Signals To CAN Data' incorporates:
       *  Constant: '<S63>/Constant'
       *  Constant: '<S63>/Constant1'
       */

      /* --------------- Start pack signal from message -----------------------------
         The number of signals is 2
         ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

      /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

      /**********Pack signal 1:startBit= 8U length = 16U byteOrder = LITTLEENDIAN dataType= uint16_T**********/
      B_n.PackSignalsToCANData[0] = (uint8_T)((uint8_T)((((uint8_T)81U) & 0xFF)));
      B_n.PackSignalsToCANData[1] = (uint8_T)((uint8_T)((((uint16_T)4U) & 0xFF)));
      B_n.PackSignalsToCANData[2] = (uint8_T)((uint8_T)((((uint16_T)4U) & 0xFF00)>>
        8U));
      B_n.PackSignalsToCANData[3] = (uint8_T)(0);
      B_n.PackSignalsToCANData[4] = (uint8_T)(0);
      B_n.PackSignalsToCANData[5] = (uint8_T)(0);
      B_n.PackSignalsToCANData[6] = (uint8_T)(0);
      B_n.PackSignalsToCANData[7] = (uint8_T)(0);

      /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
         --------------------------------------------------------------------------------*/

      /* S-Function (CAN_TxData): '<S63>/Send CAN Data' */
      F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData
        [0]));
    }

    PrevZCX_p.DeactivateReadytodrive_Trig_ZCE = LogicalOperator3;

    /* End of Outputs for SubSystem: '<S10>/Deactivate Ready to drive' */

    /* Outputs for Triggered SubSystem: '<S10>/Stop RTD sound' incorporates:
     *  TriggerPort: '<S58>/Trigger'
     */
    /* Delay: '<S10>/Delay1' */
    if (DW_l.Delay1_DSTATE[0U] && (PrevZCX_p.StopRTDsound_Trig_ZCE != POS_ZCSIG))
    {
      /* S-Function (DIO_Out): '<S58>/Ready to drive sound' incorporates:
       *  Constant: '<S58>/Constant4'
       */
      F_Abstr_HLSO_SwitchSet(LSO10,false);
    }

    PrevZCX_p.StopRTDsound_Trig_ZCE = DW_l.Delay1_DSTATE[0];

    /* End of Delay: '<S10>/Delay1' */
    /* End of Outputs for SubSystem: '<S10>/Stop RTD sound' */

    /* Logic: '<S10>/Logical Operator1' */
    B_n.LogicalOperator1_p = (BRK_CONTACTOR && RDY_DRV_BUTTON);

    /* Update for S-Function (sfix_udelay): '<S10>/Tapped Delay' */
    for (i = 0; i < 999; i++) {
      DW_l.TappedDelay_X_i[i] = DW_l.TappedDelay_X_i[i + 1];
    }

    DW_l.TappedDelay_X_i[999] = B_n.LogicalOperator1_p;

    /* End of Update for S-Function (sfix_udelay): '<S10>/Tapped Delay' */

    /* Update for Delay: '<S10>/Delay1' incorporates:
     *  Logic: '<S10>/Logical Operator2'
     */
    for (i = 0; i < 1999; i++) {
      DW_l.Delay1_DSTATE[i] = DW_l.Delay1_DSTATE[i + 1];
    }

    DW_l.Delay1_DSTATE[1999] = tmp;

    /* End of Update for Delay: '<S10>/Delay1' */
  }
}

void flData2SigCnn1U()
{
  /*********************************Local variables definition part1**********************************************************/
  uint8_T flgDrtSlt0x181_0_0_1U= 0;
  uint8_T i;
  CANMsgElement_t messageObj;
  uint8_T *dataPtr_tmp= &(messageObj.data[0]);

  /*********************************Local variables definition part2**********************************************************/

  /*----------------Unsigned signal local variables definition----------------*/
  uint32_T uint32_temp= 0;

  /*********************************Read  data from CAN************************************************************************/
  flgDrtSlt0x181_0_0_1U= F_Servece_CAN_ReceiveDirect(&SvcCANDrtSlt0x181_0_0_1U,
    &messageObj);
  B_n.ReadCANMessage_o1= flgDrtSlt0x181_0_0_1U;
  if (1==flgDrtSlt0x181_0_0_1U) {
    /*********************************Start unpack data to signals***************************************************************/
    /*-------------------------------------The number of signals is 2--------------------------------------------------------*/
    /**-----Before traversing all signals------**/
    /*------search for multiplexor signal---------------------*/
    /**------After traversing all signals------**/
    /**-----Before traversing all signals------**/
    /*------search for standard and multiplexed signals------*/
    {
      /*--Order:1 startBit:0U length:8U byteOrder:LITTLEENDIAN(0U) dataType:uint8_T--*/
      /*--slope:1.0 offset:0.0 multiplex_type:0U multiplex_value:0U--*/
      uint32_temp = (uint8_T)(
        ((uint8_T)(dataPtr_tmp[0] ) )
        );
      B_n.ReadCANMessage_o2= (real_T)uint32_temp;
    }

    {
      /*--Order:2 startBit:8U length:32U byteOrder:LITTLEENDIAN(0U) dataType:uint32_T--*/
      /*--slope:1.0 offset:0.0 multiplex_type:0U multiplex_value:0U--*/
      uint32_temp = (uint32_T)(
        ((uint32_T)(dataPtr_tmp[1] ) )
        | ((uint32_T)(dataPtr_tmp[2] ) <<8U )
        | ((uint32_T)(dataPtr_tmp[3] ) <<16U )
        | ((uint32_T)(dataPtr_tmp[4] ) <<24U )
        );
      B_n.ReadCANMessage_o3= (real_T)uint32_temp;
    }

    /**------After traversing all signals------**/
  }
}

/* Model step function for TID0 */
void VCU_TDN_step0(void)               /* Sample time: [0.001s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void VCU_TDN_step1(void)               /* Sample time: [0.005s, 0.0s] */
{
  /* S-Function (EcoCoder_Task): '<S3>/Task_Call1' */

  /* -- Call CAN RX Fcn-Call_0 -- */

  /* Output and update for function-call system: '<S3>/Power Off Management' */
  {
    boolean_T UnitDelay7;
    boolean_T UnitDelay1_h;
    real_T MinMax1_o;
    boolean_T LogicalOperator_n;
    boolean_T LogicalOperator1_g;
    uint32_T PowerOffManagement_ELAPS_T;
    uint32_T PowerOffManagement_ELAPS_T_tmp_;

    /* Outputs for Enabled SubSystem: '<S116>/KeyCycle' incorporates:
     *  EnablePort: '<S119>/Enable'
     */
    PowerOffManagement_ELAPS_T_tmp_ = M->Timing.clockTick1;

    /* End of Outputs for SubSystem: '<S116>/KeyCycle' */
    PowerOffManagement_ELAPS_T = PowerOffManagement_ELAPS_T_tmp_ -
      DW_l.PowerOffManagement_PREV_T;
    DW_l.PowerOffManagement_PREV_T = PowerOffManagement_ELAPS_T_tmp_;

    /* UnitDelay: '<S116>/Unit Delay7' */
    UnitDelay7 = DW_l.UnitDelay7_DSTATE;

    /* Logic: '<S116>/Logical Operator' incorporates:
     *  Logic: '<S125>/Logical Operator2'
     *  UnitDelay: '<S116>/Unit Delay7'
     */
    UnitDelay1_h = !DW_l.UnitDelay7_DSTATE;

    /* Switch: '<S138>/Switch' incorporates:
     *  Constant: '<S116>/Parameter'
     *  Logic: '<S125>/Logical Operator5'
     *  RelationalOperator: '<S125>/edge'
     *  Sum: '<S138>/Sum1'
     *  UnitDelay: '<S116>/Unit Delay7'
     *  UnitDelay: '<S125>/Unit Delay'
     *  UnitDelay: '<S138>/Unit Delay'
     */
    if ((DW_l.UnitDelay7_DSTATE != DW_l.UnitDelay_DSTATE_n) && UnitDelay1_h) {
      DW_l.UnitDelay_DSTATE = 0.5;
    } else {
      /* SampleTimeMath: '<S139>/sample time1'
       *
       * About '<S139>/sample time1':
       *  y = K where K = ( w * Ts )
       */
      MinMax1_o = (real_T)PowerOffManagement_ELAPS_T * 0.005;

      /* MinMax: '<S139>/MinMax' */
      if (0.001 > MinMax1_o) {
        MinMax1_o = 0.001;
      }

      /* End of MinMax: '<S139>/MinMax' */
      DW_l.UnitDelay_DSTATE -= MinMax1_o;
    }

    /* End of Switch: '<S138>/Switch' */

    /* MinMax: '<S138>/MinMax1' */
    if (0.5 < DW_l.UnitDelay_DSTATE) {
      DW_l.UnitDelay_DSTATE = 0.5;
    }

    /* End of MinMax: '<S138>/MinMax1' */

    /* MinMax: '<S138>/MinMax' */
    if (DW_l.UnitDelay_DSTATE > 0.0) {
    } else {
      DW_l.UnitDelay_DSTATE = 0.0;
    }

    /* End of MinMax: '<S138>/MinMax' */

    /* Switch: '<S125>/debounce' incorporates:
     *  Constant: '<S138>/Constant2'
     *  RelationalOperator: '<S138>/Relational Operator2'
     *  UnitDelay: '<S116>/Unit Delay7'
     *  UnitDelay: '<S125>/Unit Delay1'
     *  UnitDelay: '<S138>/Unit Delay'
     */
    if (DW_l.UnitDelay_DSTATE == 0.0) {
      PwrM_flgKeyOnDelay = DW_l.UnitDelay7_DSTATE;
    } else {
      PwrM_flgKeyOnDelay = DW_l.UnitDelay1_DSTATE;
    }

    /* End of Switch: '<S125>/debounce' */

    /* Outputs for Enabled SubSystem: '<S116>/KeyCycle' incorporates:
     *  EnablePort: '<S119>/Enable'
     */
    if (PwrM_flgKeyOnDelay) {
      PowerOffManagement_ELAPS_T = PowerOffManagement_ELAPS_T_tmp_ -
        DW_l.KeyCycle_PREV_T;
      DW_l.KeyCycle_PREV_T = PowerOffManagement_ELAPS_T_tmp_;

      /* Switch: '<S134>/Switch' incorporates:
       *  Constant: '<S116>/Parameter3'
       *  Logic: '<S116>/Logical Operator'
       *  Logic: '<S132>/Logical Operator2'
       *  Logic: '<S132>/Logical Operator5'
       *  RelationalOperator: '<S132>/edge'
       *  Sum: '<S134>/Sum1'
       *  UnitDelay: '<S132>/Unit Delay'
       *  UnitDelay: '<S134>/Unit Delay'
       */
      if ((UnitDelay1_h != DW_l.UnitDelay_DSTATE_o) && (!UnitDelay1_h)) {
        MinMax1_o = 0.1;
      } else {
        /* SampleTimeMath: '<S135>/sample time1'
         *
         * About '<S135>/sample time1':
         *  y = K where K = ( w * Ts )
         */
        MinMax1_o = (real_T)PowerOffManagement_ELAPS_T * 0.005;

        /* MinMax: '<S135>/MinMax' */
        if (0.001 > MinMax1_o) {
          MinMax1_o = 0.001;
        }

        /* End of MinMax: '<S135>/MinMax' */
        MinMax1_o = DW_l.UnitDelay_DSTATE_h - MinMax1_o;
      }

      /* End of Switch: '<S134>/Switch' */

      /* MinMax: '<S134>/MinMax1' */
      if (0.1 < MinMax1_o) {
        MinMax1_o = 0.1;
      }

      /* End of MinMax: '<S134>/MinMax1' */

      /* MinMax: '<S134>/MinMax' */
      if (MinMax1_o > 0.0) {
        DW_l.UnitDelay_DSTATE_h = MinMax1_o;
      } else {
        DW_l.UnitDelay_DSTATE_h = 0.0;
      }

      /* End of MinMax: '<S134>/MinMax' */

      /* Switch: '<S132>/debounce' incorporates:
       *  Constant: '<S134>/Constant2'
       *  Logic: '<S116>/Logical Operator'
       *  RelationalOperator: '<S134>/Relational Operator2'
       *  UnitDelay: '<S132>/Unit Delay1'
       *  UnitDelay: '<S134>/Unit Delay'
       */
      if (DW_l.UnitDelay_DSTATE_h == 0.0) {
        DW_l.UnitDelay1_DSTATE_n = UnitDelay1_h;
      }

      /* End of Switch: '<S132>/debounce' */

      /* Switch: '<S136>/Switch' incorporates:
       *  Constant: '<S116>/Parameter2'
       *  Logic: '<S116>/Logical Operator'
       *  Logic: '<S133>/Logical Operator5'
       *  RelationalOperator: '<S133>/edge'
       *  Sum: '<S136>/Sum1'
       *  UnitDelay: '<S133>/Unit Delay'
       *  UnitDelay: '<S136>/Unit Delay'
       */
      if ((UnitDelay1_h != DW_l.UnitDelay_DSTATE_na) && UnitDelay1_h) {
        MinMax1_o = 0.1;
      } else {
        /* SampleTimeMath: '<S137>/sample time1'
         *
         * About '<S137>/sample time1':
         *  y = K where K = ( w * Ts )
         */
        MinMax1_o = (real_T)PowerOffManagement_ELAPS_T * 0.005;

        /* MinMax: '<S137>/MinMax' */
        if (0.001 > MinMax1_o) {
          MinMax1_o = 0.001;
        }

        /* End of MinMax: '<S137>/MinMax' */
        MinMax1_o = DW_l.UnitDelay_DSTATE_d - MinMax1_o;
      }

      /* End of Switch: '<S136>/Switch' */

      /* MinMax: '<S136>/MinMax1' */
      if (0.1 < MinMax1_o) {
        MinMax1_o = 0.1;
      }

      /* End of MinMax: '<S136>/MinMax1' */

      /* MinMax: '<S136>/MinMax' */
      if (MinMax1_o > 0.0) {
        DW_l.UnitDelay_DSTATE_d = MinMax1_o;
      } else {
        DW_l.UnitDelay_DSTATE_d = 0.0;
      }

      /* End of MinMax: '<S136>/MinMax' */

      /* Switch: '<S133>/debounce' incorporates:
       *  Constant: '<S136>/Constant2'
       *  Logic: '<S116>/Logical Operator'
       *  RelationalOperator: '<S136>/Relational Operator2'
       *  UnitDelay: '<S133>/Unit Delay1'
       *  UnitDelay: '<S136>/Unit Delay'
       */
      if (DW_l.UnitDelay_DSTATE_d == 0.0) {
        DW_l.UnitDelay1_DSTATE_j = UnitDelay1_h;
      }

      /* End of Switch: '<S133>/debounce' */

      /* Outputs for Atomic SubSystem: '<S119>/ER_xxxx' */
      /* Logic: '<S128>/Logical Operator' incorporates:
       *  Logic: '<S128>/Logical Operator1'
       *  UnitDelay: '<S128>/Unit Delay'
       *  UnitDelay: '<S133>/Unit Delay1'
       */
      LogicalOperator_n = (DW_l.UnitDelay1_DSTATE_j && (!DW_l.UnitDelay_DSTATE_k));

      /* Update for UnitDelay: '<S128>/Unit Delay' incorporates:
       *  UnitDelay: '<S133>/Unit Delay1'
       */
      DW_l.UnitDelay_DSTATE_k = DW_l.UnitDelay1_DSTATE_j;

      /* End of Outputs for SubSystem: '<S119>/ER_xxxx' */

      /* Outputs for Atomic SubSystem: '<S119>/ER_xxxx1' */
      /* Logic: '<S129>/Logical Operator1' incorporates:
       *  UnitDelay: '<S129>/Unit Delay'
       */
      LogicalOperator1_g = !DW_l.UnitDelay_DSTATE_m;

      /* Update for UnitDelay: '<S129>/Unit Delay' incorporates:
       *  Logic: '<S116>/Logical Operator'
       */
      DW_l.UnitDelay_DSTATE_m = UnitDelay1_h;

      /* Outputs for Atomic SubSystem: '<S119>/RSFF_xxxx' */
      /* Switch: '<S130>/Switch' incorporates:
       *  Constant: '<S130>/Constant2'
       *  Logic: '<S116>/Logical Operator'
       *  Logic: '<S129>/Logical Operator'
       *  Switch: '<S130>/Switch1'
       *  UnitDelay: '<S130>/Unit Delay1'
       */
      if (UnitDelay1_h && LogicalOperator1_g) {
        DW_l.UnitDelay1_DSTATE_i = false;
      } else {
        DW_l.UnitDelay1_DSTATE_i = (LogicalOperator_n ||
          DW_l.UnitDelay1_DSTATE_i);
      }

      /* End of Switch: '<S130>/Switch' */
      /* End of Outputs for SubSystem: '<S119>/RSFF_xxxx' */
      /* End of Outputs for SubSystem: '<S119>/ER_xxxx1' */

      /* Logic: '<S119>/LogicAND1' incorporates:
       *  Logic: '<S119>/LogicAND'
       *  Logic: '<S119>/LogicNOT'
       *  UnitDelay: '<S130>/Unit Delay1'
       *  UnitDelay: '<S132>/Unit Delay1'
       */
      B_n.LogicAND1 = ((!DW_l.UnitDelay1_DSTATE_n) && DW_l.UnitDelay1_DSTATE_i);

      /* If: '<S119>/If2' */
      if (B_n.LogicAND1) {
        /* Outputs for IfAction SubSystem: '<S119>/Reset_Action' incorporates:
         *  ActionPort: '<S131>/Action Port'
         */
        /* S-Function (ResetSW): '<S131>/ResetSW' */
        if (true==B_n.LogicAND1) {
          F_Abstr_SoftReset();
        }

        /* End of Outputs for SubSystem: '<S119>/Reset_Action' */
      }

      /* End of If: '<S119>/If2' */

      /* Update for UnitDelay: '<S132>/Unit Delay' incorporates:
       *  Logic: '<S116>/Logical Operator'
       */
      DW_l.UnitDelay_DSTATE_o = UnitDelay1_h;

      /* Update for UnitDelay: '<S133>/Unit Delay' incorporates:
       *  Logic: '<S116>/Logical Operator'
       */
      DW_l.UnitDelay_DSTATE_na = UnitDelay1_h;
    }

    /* End of Outputs for SubSystem: '<S116>/KeyCycle' */

    /* UnitDelay: '<S116>/Unit Delay1' */
    UnitDelay1_h = DW_l.UnitDelay1_DSTATE_g;

    /* Outputs for Triggered SubSystem: '<S116>/Shutdown Power' incorporates:
     *  TriggerPort: '<S120>/Trigger'
     */
    /* Logic: '<S116>/Logical Operator6' */
    LogicalOperator_n = !UnitDelay1_h;
    if (LogicalOperator_n && (PrevZCX_p.ShutdownPower_Trig_ZCE != 0)) {
      /* S-Function (ecocoder_power_shutdwn): '<S120>/Shutdown Power' */
      F_Abstr_Power_Turn(ABS_Power_PWR12V,0);
    }

    PrevZCX_p.ShutdownPower_Trig_ZCE = UnitDelay1_h;

    /* End of Outputs for SubSystem: '<S116>/Shutdown Power' */

    /* Logic: '<S116>/Logical Operator2' incorporates:
     *  Logic: '<S116>/Logical Operator3'
     *  Logic: '<S116>/Logical Operator5'
     *  Logic: '<S116>/Logical Operator7'
     *  UnitDelay: '<S116>/Unit Delay3'
     *  UnitDelay: '<S116>/Unit Delay4'
     */
    LogicalOperator_n = ((!DW_l.UnitDelay3_DSTATE) && LogicalOperator_n &&
                         (!PwrM_flgKeyOnDelay) && (!DW_l.UnitDelay4_DSTATE));

    /* Outputs for Enabled SubSystem: '<S116>/Shutdown Power Hold' incorporates:
     *  EnablePort: '<S121>/Enable'
     */
    if (LogicalOperator_n) {
      /* S-Function (ecocoder_power_shutdwn): '<S121>/Shutdown Power' */
      F_Abstr_Power_Turn(ABS_Power_PWR12V,0);
    }

    /* End of Outputs for SubSystem: '<S116>/Shutdown Power Hold' */

    /* Outputs for Triggered SubSystem: '<S116>/Software Reset' incorporates:
     *  TriggerPort: '<S122>/Trigger'
     */
    if (PrevZCX_p.SoftwareReset_Trig_ZCE != 0) {
      /* S-Function (ResetSW): '<S122>/ResetSW' incorporates:
       *  Constant: '<S122>/Constant'
       */
      if (true==true) {
        F_Abstr_SoftReset();
      }
    }

    PrevZCX_p.SoftwareReset_Trig_ZCE = 0U;

    /* End of Outputs for SubSystem: '<S116>/Software Reset' */

    /* Outputs for Triggered SubSystem: '<S116>/Store All NVM Data' incorporates:
     *  TriggerPort: '<S124>/Trigger'
     */
    /* Logic: '<S116>/Logical Operator4' */
    if ((!PwrM_flgKeyOnDelay) && (PrevZCX_p.StoreAllNVMData_Trig_ZCE != 0)) {
      /* S-Function (WriteBackData): '<S124>/Store NVM Data1' incorporates:
       *  Constant: '<S124>/Constant'
       */
      if (true==true) {
        F_Abstr_MemRam2Nvm();
      }
    }

    PrevZCX_p.StoreAllNVMData_Trig_ZCE = PwrM_flgKeyOnDelay;

    /* End of Logic: '<S116>/Logical Operator4' */
    /* End of Outputs for SubSystem: '<S116>/Store All NVM Data' */

    /* S-Function (DI_Key_In): '<S118>/SwitchInput_ReadKeyOn' */
    B_n.SwitchInput_ReadKeyOn= F_Abstr_DI_GetValue(ABS_DI_KEYON);

    /* Switch: '<S118>/Switch' */
    PwrM_flgKeyOnRaw = B_n.SwitchInput_ReadKeyOn;

    /* Update for UnitDelay: '<S116>/Unit Delay7' */
    DW_l.UnitDelay7_DSTATE = PwrM_flgKeyOnRaw;

    /* Update for UnitDelay: '<S125>/Unit Delay' */
    DW_l.UnitDelay_DSTATE_n = UnitDelay7;

    /* Update for UnitDelay: '<S125>/Unit Delay1' */
    DW_l.UnitDelay1_DSTATE = PwrM_flgKeyOnDelay;

    /* Update for UnitDelay: '<S116>/Unit Delay1' */
    DW_l.UnitDelay1_DSTATE_g = PwrM_flgKeyOnDelay;

    /* Update for UnitDelay: '<S116>/Unit Delay3' */
    DW_l.UnitDelay3_DSTATE = UnitDelay1_h;

    /* Update for UnitDelay: '<S116>/Unit Delay4' incorporates:
     *  UnitDelay: '<S116>/Unit Delay5'
     */
    DW_l.UnitDelay4_DSTATE = DW_l.UnitDelay5_DSTATE;

    /* Update for UnitDelay: '<S116>/Unit Delay2' */
    DW_l.UnitDelay2_DSTATE = LogicalOperator_n;

    /* Update for UnitDelay: '<S116>/Unit Delay5' incorporates:
     *  UnitDelay: '<S116>/Unit Delay6'
     */
    DW_l.UnitDelay5_DSTATE = DW_l.UnitDelay6_DSTATE;

    /* Update for UnitDelay: '<S116>/Unit Delay6' */
    DW_l.UnitDelay6_DSTATE = UnitDelay7;
  }

  /* End of Outputs for S-Function (EcoCoder_Task): '<S3>/Task_Call1' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void VCU_TDN_step2(void)               /* Sample time: [0.01s, 0.0s] */
{
  uint32_T DataTypeConversion_k;

  /* S-Function (ecodoer_readMsg_float): '<S64>/Read CAN Message' */
  flData2SigCnn1U();

  /* Outputs for Triggered SubSystem: '<S64>/Data saving' incorporates:
   *  TriggerPort: '<S66>/Trigger'
   */
  if (B_n.ReadCANMessage_o1 && (PrevZCX_p.Datasaving_Trig_ZCE != POS_ZCSIG)) {
    /* SwitchCase: '<S66>/Switch Case' */
    switch ((int32_T)B_n.ReadCANMessage_o2) {
     case 200:
      /* Outputs for IfAction SubSystem: '<S66>/N_100' incorporates:
       *  ActionPort: '<S74>/Action Port'
       */
      /* DataTypeConversion: '<S74>/Data Type Conversion' */
      N_100 = (uint16_T)B_n.ReadCANMessage_o3;

      /* S-Function (EcoCoder_NVM_VarWrite): '<S74>/Write NVM' */
      nvmN_100[0]= ((&(N_100)))[0];

      /* End of Outputs for SubSystem: '<S66>/N_100' */
      break;

     case 52:
      /* Outputs for IfAction SubSystem: '<S66>/N_Lim' incorporates:
       *  ActionPort: '<S75>/Action Port'
       */
      /* DataTypeConversion: '<S75>/Data Type Conversion' */
      N_lim = (uint16_T)B_n.ReadCANMessage_o3;

      /* S-Function (EcoCoder_NVM_VarWrite): '<S75>/Write NVM' */
      nvmN_lim[0]= ((&(N_lim)))[0];

      /* End of Outputs for SubSystem: '<S66>/N_Lim' */
      break;

     case 63:
      /* Outputs for IfAction SubSystem: '<S66>/N_Lim_pos' incorporates:
       *  ActionPort: '<S77>/Action Port'
       */
      /* DataTypeConversion: '<S77>/Data Type Conversion' */
      N_lim_pos = (int16_T)floor(B_n.ReadCANMessage_o3);

      /* S-Function (EcoCoder_NVM_VarWrite): '<S77>/Write NVM' */
      nvmN_lim_pos[0]= ((&(N_lim_pos)))[0];

      /* End of Outputs for SubSystem: '<S66>/N_Lim_pos' */
      break;

     case 62:
      /* Outputs for IfAction SubSystem: '<S66>/N_Lim_neg' incorporates:
       *  ActionPort: '<S76>/Action Port'
       */
      /* DataTypeConversion: '<S76>/Data Type Conversion' */
      N_lim_neg = (int16_T)floor(B_n.ReadCANMessage_o3);

      /* S-Function (EcoCoder_NVM_VarWrite): '<S76>/Write NVM' */
      nvmN_lim_neg[0]= ((&(N_lim_neg)))[0];

      /* End of Outputs for SubSystem: '<S66>/N_Lim_neg' */
      break;

     case 53:
      /* Outputs for IfAction SubSystem: '<S66>/N_R_Acc | M R_Acc' incorporates:
       *  ActionPort: '<S78>/Action Port'
       */
      /* DataTypeConversion: '<S78>/Data Type Conversion' */
      DataTypeConversion_k = (uint32_T)B_n.ReadCANMessage_o3;

      /* DataTypeConversion: '<S78>/Data Type Conversion2' incorporates:
       *  DataTypeConversion: '<S97>/Extract Desired Bits'
       */
      N_R_Acc = (int16_T)DataTypeConversion_k;

      /* S-Function (EcoCoder_NVM_VarWrite): '<S78>/Write NVM' */
      nvmN_R_Acc[0]= ((&(N_R_Acc)))[0];

      /* DataTypeConversion: '<S78>/Data Type Conversion1' incorporates:
       *  DataTypeConversion: '<S98>/Extract Desired Bits'
       */
      M_R_Acc = (int16_T)(DataTypeConversion_k >> 16);

      /* S-Function (EcoCoder_NVM_VarWrite): '<S78>/Write NVM1' */
      nvmM_R_Acc[0]= ((&(M_R_Acc)))[0];

      /* End of Outputs for SubSystem: '<S66>/N_R_Acc | M R_Acc' */
      break;

     case 237:
      /* Outputs for IfAction SubSystem: '<S66>/N_R_Dec | M_R_Dec' incorporates:
       *  ActionPort: '<S79>/Action Port'
       */
      /* DataTypeConversion: '<S79>/Data Type Conversion' */
      DataTypeConversion_k = (uint32_T)B_n.ReadCANMessage_o3;

      /* DataTypeConversion: '<S79>/Data Type Conversion2' incorporates:
       *  DataTypeConversion: '<S101>/Extract Desired Bits'
       */
      N_R_Dec = (int16_T)DataTypeConversion_k;

      /* S-Function (EcoCoder_NVM_VarWrite): '<S79>/Write NVM' */
      nvmN_R_Dec[0]= ((&(N_R_Dec)))[0];

      /* DataTypeConversion: '<S79>/Data Type Conversion1' incorporates:
       *  DataTypeConversion: '<S102>/Extract Desired Bits'
       */
      M_R_Dec = (int16_T)(DataTypeConversion_k >> 16);

      /* S-Function (EcoCoder_NVM_VarWrite): '<S79>/Write NVM1' */
      nvmM_R_Dec[0]= ((&(M_R_Dec)))[0];

      /* End of Outputs for SubSystem: '<S66>/N_R_Dec | M_R_Dec' */
      break;

     case 206:
      /* Outputs for IfAction SubSystem: '<S66>/N_act_filt' incorporates:
       *  ActionPort: '<S80>/Action Port'
       */
      /* DataTypeConversion: '<S80>/Data Type Conversion' */
      N_act_filt = (int16_T)floor(B_n.ReadCANMessage_o3);

      /* S-Function (EcoCoder_NVM_VarWrite): '<S80>/Write NVM' */
      nvmN_act_filt[0]= ((&(N_act_filt)))[0];

      /* End of Outputs for SubSystem: '<S66>/N_act_filt' */
      break;

     case 168:
      /* Outputs for IfAction SubSystem: '<S66>/SpeedRPMmax' incorporates:
       *  ActionPort: '<S81>/Action Port'
       */
      /* DataTypeConversion: '<S81>/Data Type Conversion' */
      SpeedRPMmax = (int16_T)floor(B_n.ReadCANMessage_o3);

      /* S-Function (EcoCoder_NVM_VarWrite): '<S81>/Write NVM' */
      nvmSpeedRPMmax[0]= ((&(SpeedRPMmax)))[0];

      /* End of Outputs for SubSystem: '<S66>/SpeedRPMmax' */
      break;

     case 77:
      /* Outputs for IfAction SubSystem: '<S66>/I_max_eff' incorporates:
       *  ActionPort: '<S71>/Action Port'
       */
      /* DataTypeConversion: '<S71>/Data Type Conversion' */
      I_max_eff = (int16_T)floor(B_n.ReadCANMessage_o3);

      /* S-Function (EcoCoder_NVM_VarWrite): '<S71>/Write NVM' */
      nvmI_max_eff[0]= ((&(I_max_eff)))[0];

      /* End of Outputs for SubSystem: '<S66>/I_max_eff' */
      break;

     case 78:
      /* Outputs for IfAction SubSystem: '<S66>/I_nom_eff' incorporates:
       *  ActionPort: '<S73>/Action Port'
       */
      /* DataTypeConversion: '<S73>/Data Type Conversion' */
      I_nom_eff = (int16_T)floor(B_n.ReadCANMessage_o3);

      /* S-Function (EcoCoder_NVM_VarWrite): '<S73>/Write NVM' */
      nvmI_nom_eff[0]= ((&(I_nom_eff)))[0];

      /* End of Outputs for SubSystem: '<S66>/I_nom_eff' */
      break;

     case 196:
      /* Outputs for IfAction SubSystem: '<S66>/I_max_pk' incorporates:
       *  ActionPort: '<S72>/Action Port'
       */
      /* DataTypeConversion: '<S72>/Data Type Conversion' */
      I_max_pk = (int16_T)floor(B_n.ReadCANMessage_o3);

      /* S-Function (EcoCoder_NVM_VarWrite): '<S72>/Write NVM' */
      nvmI_max_pk[0]= ((&(I_max_pk)))[0];

      /* End of Outputs for SubSystem: '<S66>/I_max_pk' */
      break;

     case 198:
      /* Outputs for IfAction SubSystem: '<S66>/I_device' incorporates:
       *  ActionPort: '<S70>/Action Port'
       */
      /* DataTypeConversion: '<S70>/Data Type Conversion' */
      I_device = (int16_T)floor(B_n.ReadCANMessage_o3);

      /* S-Function (EcoCoder_NVM_VarWrite): '<S70>/Write NVM' */
      nvmI_device[0]= ((&(I_device)))[0];

      /* End of Outputs for SubSystem: '<S66>/I_device' */
      break;

     case 217:
      /* Outputs for IfAction SubSystem: '<S66>/I_200' incorporates:
       *  ActionPort: '<S67>/Action Port'
       */
      /* DataTypeConversion: '<S67>/Data Type Conversion' */
      I_200 = (int16_T)floor(B_n.ReadCANMessage_o3);

      /* S-Function (EcoCoder_NVM_VarWrite): '<S67>/Write NVM' */
      nvmI_200[0]= ((&(I_200)))[0];

      /* End of Outputs for SubSystem: '<S66>/I_200' */
      break;

     case 235:
      /* Outputs for IfAction SubSystem: '<S66>/Vdc_bus' incorporates:
       *  ActionPort: '<S85>/Action Port'
       */
      /* DataTypeConversion: '<S85>/Data Type Conversion' */
      Vdc_bus = (int16_T)floor(B_n.ReadCANMessage_o3);

      /* S-Function (EcoCoder_NVM_VarWrite): '<S85>/Write NVM' */
      nvmVdc_bus[0]= ((&(Vdc_bus)))[0];

      /* End of Outputs for SubSystem: '<S66>/Vdc_bus' */
      break;

     case 95:
      /* Outputs for IfAction SubSystem: '<S66>/I_act_filt' incorporates:
       *  ActionPort: '<S68>/Action Port'
       */
      /* DataTypeConversion: '<S68>/Data Type Conversion' */
      I_act_filt = (int16_T)floor(B_n.ReadCANMessage_o3);

      /* S-Function (EcoCoder_NVM_VarWrite): '<S68>/Write NVM' */
      nvmI_act_filt[0]= ((&(I_act_filt)))[0];

      /* End of Outputs for SubSystem: '<S66>/I_act_filt' */
      break;

     case 38:
      /* Outputs for IfAction SubSystem: '<S66>/I_cmd' incorporates:
       *  ActionPort: '<S69>/Action Port'
       */
      /* DataTypeConversion: '<S69>/Data Type Conversion' */
      I_cmd = (int16_T)floor(B_n.ReadCANMessage_o3);

      /* S-Function (EcoCoder_NVM_VarWrite): '<S69>/Write NVM' */
      nvmI_cmd[0]= ((&(I_cmd)))[0];

      /* End of Outputs for SubSystem: '<S66>/I_cmd' */
      break;

     case 74:
      /* Outputs for IfAction SubSystem: '<S66>/T_IGBT' incorporates:
       *  ActionPort: '<S82>/Action Port'
       */
      /* DataTypeConversion: '<S82>/Data Type Conversion' */
      T_IGBT = (int16_T)floor(B_n.ReadCANMessage_o3);

      /* S-Function (EcoCoder_NVM_VarWrite): '<S82>/Write NVM' */
      nvmT_IGBT[0]= ((&(T_IGBT)))[0];

      /* End of Outputs for SubSystem: '<S66>/T_IGBT' */
      break;

     case 73:
      /* Outputs for IfAction SubSystem: '<S66>/T_motor' incorporates:
       *  ActionPort: '<S84>/Action Port'
       */
      /* DataTypeConversion: '<S84>/Data Type Conversion' */
      T_motor = (int16_T)floor(B_n.ReadCANMessage_o3);

      /* S-Function (EcoCoder_NVM_VarWrite): '<S84>/Write NVM' */
      nvmT_motor[0]= ((&(T_motor)))[0];

      /* End of Outputs for SubSystem: '<S66>/T_motor' */
      break;

     case 75:
      /* Outputs for IfAction SubSystem: '<S66>/T_air' incorporates:
       *  ActionPort: '<S83>/Action Port'
       */
      /* DataTypeConversion: '<S83>/Data Type Conversion' */
      T_air = (int16_T)floor(B_n.ReadCANMessage_o3);

      /* S-Function (EcoCoder_NVM_VarWrite): '<S83>/Write NVM' */
      nvmT_air[0]= ((&(T_air)))[0];

      /* End of Outputs for SubSystem: '<S66>/T_air' */
      break;
    }

    /* End of SwitchCase: '<S66>/Switch Case' */
  }

  PrevZCX_p.Datasaving_Trig_ZCE = B_n.ReadCANMessage_o1;

  /* End of Outputs for SubSystem: '<S64>/Data saving' */
}

/* Model step function for TID3 */
void VCU_TDN_step3(void)               /* Sample time: [0.02s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID4 */
void VCU_TDN_step4(void)               /* Sample time: [0.05s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID5 */
void VCU_TDN_step5(void)               /* Sample time: [0.1s, 0.0s] */
{
  /* S-Function (EcoCoder_Task): '<S1>/Task Trigger1' */

  /* -- Call CAN RX Fcn-Call_0 -- */

  /* Output and update for function-call system: '<S1>/Data processing' */
  {
    int64m_T tmp;
    int64m_T tmp_p;
    uint32_T tmp_e;
    uint32_T tmp_i;
    int64m_T tmp_m;

    /* S-Function (ecocoder_nvm_read): '<S41>/Read NVM3' */
    (&B_n.ReadNVM3)[0] = nvmVdc_bus[0];

    /* Lookup_n-D: '<S41>/1-D Lookup Table2' */
    Vdc_bus_V = look1_is16lu32n32ys16D_604HKI8a(B_n.ReadNVM3, ((const int16_T *)
      &(Vdc_bus_V_bp[0])), ((const int16_T *)&(Vdc_bus_V_cur[0])), 41U);

    /* S-Function (EcoCoder_NVM_VarWrite): '<S41>/Write NVM2' */
    nvmVdc_bus_V[0]= ((&(Vdc_bus_V)))[0];

    /* S-Function (ecocoder_nvm_read): '<S41>/Read NVM' */
    (&B_n.ReadNVM_m)[0] = nvmI_device[0];

    /* S-Function (ecocoder_nvm_read): '<S41>/Read NVM1' */
    (&B_n.ReadNVM1)[0] = nvmI_act_filt[0];

    /* S-Function (ecocoder_nvm_read): '<S41>/Read NVM2' */
    (&B_n.ReadNVM2)[0] = nvmI_200[0];

    /* Product: '<S41>/Product1' incorporates:
     *  Gain: '<S41>/Gain1'
     *  Product: '<S41>/Divide'
     */
    tmp_e = (uint32_T)(26214 * B_n.ReadNVM_m);
    tmp_i = (uint32_T)div_s16s32_floor(B_n.ReadNVM1, B_n.ReadNVM2);
    sMultiWordMul(&tmp_e, 1, &tmp_i, 1, &tmp_p.chunks[0U], 2);

    /* DataTypeConversion: '<S41>/Data Type Conversion1' */
    sMultiWordShr(&tmp_p.chunks[0U], 2, 17U, &tmp.chunks[0U], 2);
    I_act_filt_A = (int16_T)MultiWord2sLong(&tmp.chunks[0U]);

    /* S-Function (EcoCoder_NVM_VarWrite): '<S41>/Write NVM' */
    nvmI_act_filt_A[0]= ((&(I_act_filt_A)))[0];

    /* S-Function (ecocoder_nvm_read): '<S42>/Read NVM' */
    (&B_n.ReadNVM_p)[0] = nvmSpeedRPMmax[0];

    /* S-Function (ecocoder_nvm_read): '<S42>/Read NVM1' */
    (&B_n.ReadNVM1_k)[0] = nvmN_act_filt[0];

    /* Product: '<S42>/Product' incorporates:
     *  Gain: '<S42>/Gain'
     */
    tmp_e = (uint32_T)B_n.ReadNVM_p;
    tmp_i = (uint32_T)(16385 * B_n.ReadNVM1_k);
    sMultiWordMul(&tmp_e, 1, &tmp_i, 1, &tmp_m.chunks[0U], 2);

    /* DataTypeConversion: '<S42>/Data Type Conversion' */
    sMultiWordShr(&tmp_m.chunks[0U], 2, 29U, &tmp_p.chunks[0U], 2);
    N_act_filt_RPM = (int16_T)MultiWord2sLong(&tmp_p.chunks[0U]);

    /* DataTypeConversion: '<S42>/Data Type Conversion1' incorporates:
     *  Gain: '<S42>/Gain1'
     */
    Speed = (int16_T)((28760 * N_act_filt_RPM) >> 20);

    /* S-Function (EcoCoder_NVM_VarWrite): '<S42>/Write NVM' */
    nvmSpeed[0]= ((&(Speed)))[0];

    /* S-Function (EcoCoder_NVM_VarWrite): '<S42>/Write NVM1' */
    nvmN_act_filt_RPM[0]= ((&(N_act_filt_RPM)))[0];

    /* S-Function (ecocoder_nvm_read): '<S43>/Read NVM2' */
    (&B_n.ReadNVM2_a)[0] = nvmT_air[0];

    /* Lookup_n-D: '<S43>/1-D Lookup Table2' */
    T_air_deg = look1_is16lu32n32ys16D_604HKI8a(B_n.ReadNVM2_a, ((const int16_T *)
      &(T_air_conversion_bp[0])), ((const int16_T *)&(T_air_conversion_cur[0])),
      28U);

    /* S-Function (EcoCoder_NVM_VarWrite): '<S43>/Write NVM2' */
    nvmT_air_deg[0]= ((&(T_air_deg)))[0];

    /* S-Function (ecocoder_nvm_read): '<S43>/Read NVM1' */
    (&B_n.ReadNVM1_f)[0] = nvmT_motor[0];

    /* Lookup_n-D: '<S43>/1-D Lookup Table1' */
    T_motor_deg = look1_is16lu32n32ys16D_604HKI8a(B_n.ReadNVM1_f, ((const
      int16_T *)&(T_motor_conversion_bp[0])), ((const int16_T *)
      &(T_motor_conversion_cur[0])), 38U);

    /* S-Function (EcoCoder_NVM_VarWrite): '<S43>/Write NVM1' */
    nvmT_motor_deg[0]= ((&(T_motor_deg)))[0];

    /* S-Function (ecocoder_nvm_read): '<S43>/Read NVM' */
    (&B_n.ReadNVM_f)[0] = nvmT_IGBT[0];

    /* Lookup_n-D: '<S43>/1-D Lookup Table' */
    T_IGBT_deg = look1_is16lu32n32ys16D_604HKI8a(B_n.ReadNVM_f, ((const int16_T *)
      &(T_IGBT_conversion_bp[0])), ((const int16_T *)&(T_IGBT_conversion_cur[0])),
      38U);

    /* S-Function (EcoCoder_NVM_VarWrite): '<S43>/Write NVM' */
    nvmT_IGBT_deg[0]= ((&(T_IGBT_deg)))[0];
  }

  /* End of Outputs for S-Function (EcoCoder_Task): '<S1>/Task Trigger1' */

  /* S-Function (EcoCoder_Task): '<S1>/Task Trigger3' */

  /* -- Call CAN RX Fcn-Call_0 -- */

  /* Output and update for function-call system: '<S1>/Sending data to the dashboard' */

  /* S-Function (ecocoder_nvm_read): '<S12>/Read NVM' */
  (&B_n.ReadNVM_b)[0] = nvmSpeed[0];

  /* End of Outputs for S-Function (EcoCoder_Task): '<S1>/Task Trigger3' */

  /* S-Function (EcoCoder_Task): '<S11>/Task Trigger1' */

  /* -- Call CAN RX Fcn-Call_0 -- */

  /* Output and update for function-call system: '<S11>/Sensors' */

  /* S-Function (ADC): '<S65>/Current sensor channel 1' */
  B_n.Currentsensorchannel1 = F_Abstr_ADC_GetValue(ABS_ADC_15);

  /* DataTypeConversion: '<S65>/Data Type Conversion2' incorporates:
   *  Gain: '<S65>/Gain2'
   */
  CURRENT_CH_1 = (int16_T)B_n.Currentsensorchannel1;

  /* S-Function (ADC): '<S65>/Current sensor channel 2' */
  B_n.Currentsensorchannel2 = F_Abstr_ADC_GetValue(ABS_ADC_17);

  /* DataTypeConversion: '<S65>/Data Type Conversion3' incorporates:
   *  Gain: '<S65>/Gain3'
   */
  CURRENT_CH_2 = (int16_T)B_n.Currentsensorchannel2;

  /* S-Function (ADC): '<S65>/Front brake pressure' */
  B_n.Frontbrakepressure = F_Abstr_ADC_GetValue(ABS_ADC_8);

  /* DataTypeConversion: '<S65>/Data Type Conversion' incorporates:
   *  Gain: '<S65>/Gain'
   */
  FR_BRK_PRESSURE = (real32_T)B_n.Frontbrakepressure;

  /* S-Function (ADC): '<S65>/Rear brake pressure' */
  B_n.Rearbrakepressure = F_Abstr_ADC_GetValue(ABS_ADC_12);

  /* DataTypeConversion: '<S65>/Data Type Conversion1' incorporates:
   *  Gain: '<S65>/Gain1'
   */
  RR_BRAKE_PRESSURE = (real32_T)B_n.Rearbrakepressure;

  /* End of Outputs for S-Function (EcoCoder_Task): '<S11>/Task Trigger1' */
}

/* Model step function for TID6 */
void VCU_TDN_step6(void)               /* Sample time: [0.2s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID7 */
void VCU_TDN_step7(void)               /* Sample time: [0.5s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID8 */
void VCU_TDN_step8(void)               /* Sample time: [1.0s, 0.0s] */
{
  /* S-Function (EcoCoder_Task): '<S1>/Task Trigger2' */

  /* -- Call CAN RX Fcn-Call_0 -- */

  /* Output and update for function-call system: '<S1>/Pump and fans' */

  /* S-Function (DIO_In): '<S9>/Battery fan ON' */
  B_n.BatteryfanON= F_Abstr_DI_GetValue(ABS_DI09);

  /* Logic: '<S9>/Logical Operator4' */
  BATT_FAN_ON = !B_n.BatteryfanON;

  /* S-Function (EcoCoder_NVM_VarWrite): '<S9>/Write NVM2' */
  nvmBATT_FAN_ON[0]= ((&(BATT_FAN_ON)))[0];

  /* S-Function (DIO_In): '<S9>/Pump ON' */
  B_n.PumpON= F_Abstr_DI_GetValue(ABS_DI12);

  /* S-Function (DIO_In): '<S9>/Pump and Fan ON' */
  B_n.PumpandFanON= F_Abstr_DI_GetValue(ABS_DI12);

  /* Logic: '<S9>/Logical Operator2' */
  FAN_ON = !B_n.PumpandFanON;

  /* Logic: '<S9>/Logical Operator3' incorporates:
   *  Logic: '<S9>/Logical Operator1'
   */
  PUMP_ON = ((!B_n.PumpON) || FAN_ON);

  /* S-Function (EcoCoder_NVM_VarWrite): '<S9>/Write NVM' */
  nvmPUMP_ON[0]= ((&(PUMP_ON)))[0];

  /* S-Function (EcoCoder_NVM_VarWrite): '<S9>/Write NVM1' */
  nvmFAN_ON[0]= ((&(FAN_ON)))[0];

  /* S-Function (DIO_Out): '<S9>/Battery fan activation' */
  F_Abstr_HLSO_SwitchSet(LSO03,BATT_FAN_ON);

  /* S-Function (DIO_Out): '<S9>/Fan activation' */
  F_Abstr_HLSO_SwitchSet(LSO13,FAN_ON);

  /* S-Function (DIO_Out): '<S9>/Pump activation' */
  F_Abstr_HLSO_SwitchSet(LSO12,PUMP_ON);

  /* End of Outputs for S-Function (EcoCoder_Task): '<S1>/Task Trigger2' */
}

/* Model step wrapper function for compatibility with a static main program */
void VCU_TDN_step(int_T tid)
{
  switch (tid) {
   case 0 :
    VCU_TDN_step0();
    break;

   case 1 :
    VCU_TDN_step1();
    break;

   case 2 :
    VCU_TDN_step2();
    break;

   case 3 :
    VCU_TDN_step3();
    break;

   case 4 :
    VCU_TDN_step4();
    break;

   case 5 :
    VCU_TDN_step5();
    break;

   case 6 :
    VCU_TDN_step6();
    break;

   case 7 :
    VCU_TDN_step7();
    break;

   case 8 :
    VCU_TDN_step8();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void VCU_TDN_initialize(void)
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

  /* Start for S-Function (EcoCoder_Task): '<S3>/Task_Call' */

  /* -- Call CAN RX Fcn-Call_0 -- */

  /* Output and update for function-call system: '<S3>/Power On Init' */

  /* Outputs for Enabled SubSystem: '<S117>/Restore NVM Data' incorporates:
   *  EnablePort: '<S140>/Enable'
   */
  /* Logic: '<S140>/Logical Operator' incorporates:
   *  Logic: '<S140>/LogicNOT1'
   *  UnitDelay: '<S140>/Unit Delay'
   */
  B_n.LogicalOperator_e = !DW_l.UnitDelay_DSTATE_g;

  /* S-Function (WriteBackData): '<S140>/Restore NVM Data' */
  if (true==B_n.LogicalOperator_e) {
    F_Abstr_MemNvm2Ram();
  }

  /* Update for UnitDelay: '<S140>/Unit Delay' incorporates:
   *  Constant: '<S140>/Constant'
   */
  DW_l.UnitDelay_DSTATE_g = true;

  /* End of Outputs for SubSystem: '<S117>/Restore NVM Data' */

  /* End of Start for S-Function (EcoCoder_Task): '<S3>/Task_Call' */

  /* Start for S-Function (EcoCoder_Task): '<S1>/Task Trigger' incorporates:
   *  SubSystem: '<S1>/APPS and torque setpoint'
   */

  /* Start for function-call system: '<S1>/APPS and torque setpoint' */

  /* Start for S-Function (ADC): '<S4>/APPS 1' */
  F_Abstr_ADC_InitChannel(ABS_ADC_6);

  /* Start for S-Function (ADC): '<S4>/APPS 2' */
  F_Abstr_ADC_InitChannel(ABS_ADC_7);
  ASWTaskH_Insert(&nodeASW_H1ms1U,ASW_H1ms1U,0);

  /* End of Start for S-Function (EcoCoder_Task): '<S1>/Task Trigger' */

  /* Start for S-Function (EcoCoder_Task): '<S1>/Task Trigger5' incorporates:
   *  SubSystem: '<S1>/Initialization'
   */

  /* Start for function-call system: '<S1>/Initialization' */

  /* Start for S-Function (DIO_Out): '<S8>/RFE' incorporates:
   *  Constant: '<S8>/Constant'
   */
#ifndef IO_OPWM_LSO06_EN

  F_Abstr_HLSO_InitChannel(LSO06,1,0);

#endif

  /* Start for S-Function (DIO_Out): '<S8>/FRG//RUN' incorporates:
   *  Constant: '<S8>/Constant1'
   */
#ifndef IO_OPWM_LSO07_EN

  F_Abstr_HLSO_InitChannel(LSO07,1,0);

#endif

  /* -- Call CAN RX Fcn-Call_0 -- */

  /* Output and update for function-call system: '<S1>/Initialization' */

  /* S-Function (DIO_Out): '<S8>/RFE' incorporates:
   *  Constant: '<S8>/Constant'
   */
  F_Abstr_HLSO_SwitchSet(LSO06,false);

  /* S-Function (DIO_Out): '<S8>/FRG//RUN' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  F_Abstr_HLSO_SwitchSet(LSO07,false);

  /* S-Function (CoderCAN_PackBit2Data): '<S51>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S51>/Constant'
   *  Constant: '<S51>/Constant1'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 2
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 16U byteOrder = LITTLEENDIAN dataType= uint16_T**********/
  B_n.PackSignalsToCANData_o[0] = (uint8_T)((uint8_T)((((uint8_T)81U) & 0xFF)));
  B_n.PackSignalsToCANData_o[1] = (uint8_T)((uint8_T)((((uint16_T)4U) & 0xFF)));
  B_n.PackSignalsToCANData_o[2] = (uint8_T)((uint8_T)((((uint16_T)4U) & 0xFF00)>>
    8U));
  B_n.PackSignalsToCANData_o[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_o[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_o[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_o[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_o[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S51>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_o[0]));

  /* End of Start for S-Function (EcoCoder_Task): '<S1>/Task Trigger5' */

  /* Start for S-Function (EcoCoder_Task): '<S1>/Task Trigger4' */

  /* -- Call CAN RX Fcn-Call_0 -- */

  /* Output and update for function-call system: '<S1>/Asking data from the inverter' */

  /* S-Function (CoderCAN_PackBit2Data): '<S21>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S21>/Constant1'
   *  Constant: '<S5>/Constant1'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_l[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_l[1] = (uint8_T)((uint8_T)((((uint8_T)95U) & 0xFF)));
  B_n.PackSignalsToCANData_l[2] = (uint8_T)((uint8_T)((((uint8_T)100U) & 0xFF)));
  B_n.PackSignalsToCANData_l[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_l[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_l[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_l[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_l[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S21>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_l[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S22>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S22>/Constant1'
   *  Constant: '<S5>/Constant1'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_b[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_b[1] = (uint8_T)((uint8_T)((((uint8_T)38U) & 0xFF)));
  B_n.PackSignalsToCANData_b[2] = (uint8_T)((uint8_T)((((uint8_T)100U) & 0xFF)));
  B_n.PackSignalsToCANData_b[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_b[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_b[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_b[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_b[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S22>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_b[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S33>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S33>/Constant'
   *  Constant: '<S33>/Constant1'
   *  Constant: '<S5>/Constant1'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_ly[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_ly[1] = (uint8_T)((uint8_T)((((uint8_T)168U) & 0xFF)));
  B_n.PackSignalsToCANData_ly[2] = (uint8_T)((uint8_T)((((uint8_T)100U) & 0xFF)));
  B_n.PackSignalsToCANData_ly[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_ly[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_ly[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_ly[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_ly[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S33>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_ly[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S35>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S35>/Constant'
   *  Constant: '<S35>/Constant1'
   *  Constant: '<S5>/Constant1'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_e[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_e[1] = (uint8_T)((uint8_T)((((uint8_T)74U) & 0xFF)));
  B_n.PackSignalsToCANData_e[2] = (uint8_T)((uint8_T)((((uint8_T)100U) & 0xFF)));
  B_n.PackSignalsToCANData_e[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_e[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_e[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_e[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_e[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S35>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_e[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S36>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S36>/Constant'
   *  Constant: '<S36>/Constant1'
   *  Constant: '<S5>/Constant1'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_k[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_k[1] = (uint8_T)((uint8_T)((((uint8_T)75U) & 0xFF)));
  B_n.PackSignalsToCANData_k[2] = (uint8_T)((uint8_T)((((uint8_T)100U) & 0xFF)));
  B_n.PackSignalsToCANData_k[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_k[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_k[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_k[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_k[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S36>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_k[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S37>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   *  Constant: '<S5>/Constant1'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_g[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_g[1] = (uint8_T)((uint8_T)((((uint8_T)73U) & 0xFF)));
  B_n.PackSignalsToCANData_g[2] = (uint8_T)((uint8_T)((((uint8_T)100U) & 0xFF)));
  B_n.PackSignalsToCANData_g[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_g[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_g[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_g[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_g[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S37>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_g[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S38>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S38>/Constant1'
   *  Constant: '<S5>/Constant1'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_d[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_d[1] = (uint8_T)((uint8_T)((((uint8_T)235U) & 0xFF)));
  B_n.PackSignalsToCANData_d[2] = (uint8_T)((uint8_T)((((uint8_T)100U) & 0xFF)));
  B_n.PackSignalsToCANData_d[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_d[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_d[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_d[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_d[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S38>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_d[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S20>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S20>/Constant1'
   *  Constant: '<S5>/Constant2'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_i[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_i[1] = (uint8_T)((uint8_T)((((uint8_T)217U) & 0xFF)));
  B_n.PackSignalsToCANData_i[2] = (uint8_T)((uint8_T)((((uint8_T)0U) & 0xFF)));
  B_n.PackSignalsToCANData_i[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_i[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_i[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_i[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_i[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S20>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_i[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S23>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S23>/Constant'
   *  Constant: '<S23>/Constant1'
   *  Constant: '<S5>/Constant2'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_p[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_p[1] = (uint8_T)((uint8_T)((((uint8_T)198U) & 0xFF)));
  B_n.PackSignalsToCANData_p[2] = (uint8_T)((uint8_T)((((uint8_T)0U) & 0xFF)));
  B_n.PackSignalsToCANData_p[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_p[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_p[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_p[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_p[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S23>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_p[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S24>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S24>/Constant'
   *  Constant: '<S24>/Constant1'
   *  Constant: '<S5>/Constant2'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_h[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_h[1] = (uint8_T)((uint8_T)((((uint8_T)77U) & 0xFF)));
  B_n.PackSignalsToCANData_h[2] = (uint8_T)((uint8_T)((((uint8_T)0U) & 0xFF)));
  B_n.PackSignalsToCANData_h[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_h[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_h[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_h[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_h[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S24>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_h[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S25>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S25>/Constant'
   *  Constant: '<S25>/Constant1'
   *  Constant: '<S5>/Constant2'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_p0[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_p0[1] = (uint8_T)((uint8_T)((((uint8_T)196U) & 0xFF)));
  B_n.PackSignalsToCANData_p0[2] = (uint8_T)((uint8_T)((((uint8_T)0U) & 0xFF)));
  B_n.PackSignalsToCANData_p0[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_p0[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_p0[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_p0[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_p0[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S25>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_p0[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S26>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S26>/Constant'
   *  Constant: '<S26>/Constant1'
   *  Constant: '<S5>/Constant2'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_dk[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_dk[1] = (uint8_T)((uint8_T)((((uint8_T)78U) & 0xFF)));
  B_n.PackSignalsToCANData_dk[2] = (uint8_T)((uint8_T)((((uint8_T)0U) & 0xFF)));
  B_n.PackSignalsToCANData_dk[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_dk[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_dk[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_dk[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_dk[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S26>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_dk[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S27>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S27>/Constant1'
   *  Constant: '<S5>/Constant2'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_hy[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_hy[1] = (uint8_T)((uint8_T)((((uint8_T)200U) & 0xFF)));
  B_n.PackSignalsToCANData_hy[2] = (uint8_T)((uint8_T)((((uint8_T)0U) & 0xFF)));
  B_n.PackSignalsToCANData_hy[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_hy[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_hy[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_hy[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_hy[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S27>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_hy[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S28>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S28>/Constant1'
   *  Constant: '<S5>/Constant2'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_h4[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_h4[1] = (uint8_T)((uint8_T)((((uint8_T)52U) & 0xFF)));
  B_n.PackSignalsToCANData_h4[2] = (uint8_T)((uint8_T)((((uint8_T)0U) & 0xFF)));
  B_n.PackSignalsToCANData_h4[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_h4[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_h4[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_h4[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_h4[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S28>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_h4[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S29>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S29>/Constant1'
   *  Constant: '<S5>/Constant2'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_d0[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_d0[1] = (uint8_T)((uint8_T)((((uint8_T)62U) & 0xFF)));
  B_n.PackSignalsToCANData_d0[2] = (uint8_T)((uint8_T)((((uint8_T)0U) & 0xFF)));
  B_n.PackSignalsToCANData_d0[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_d0[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_d0[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_d0[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_d0[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S29>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_d0[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S30>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S30>/Constant'
   *  Constant: '<S30>/Constant1'
   *  Constant: '<S5>/Constant2'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_f[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_f[1] = (uint8_T)((uint8_T)((((uint8_T)63U) & 0xFF)));
  B_n.PackSignalsToCANData_f[2] = (uint8_T)((uint8_T)((((uint8_T)0U) & 0xFF)));
  B_n.PackSignalsToCANData_f[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_f[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_f[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_f[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_f[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S30>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_f[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S31>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S31>/Constant'
   *  Constant: '<S31>/Constant1'
   *  Constant: '<S5>/Constant2'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_ht[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_ht[1] = (uint8_T)((uint8_T)((((uint8_T)53U) & 0xFF)));
  B_n.PackSignalsToCANData_ht[2] = (uint8_T)((uint8_T)((((uint8_T)0U) & 0xFF)));
  B_n.PackSignalsToCANData_ht[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_ht[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_ht[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_ht[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_ht[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S31>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_ht[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S32>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S32>/Constant1'
   *  Constant: '<S5>/Constant2'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_m[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_m[1] = (uint8_T)((uint8_T)((((uint8_T)237U) & 0xFF)));
  B_n.PackSignalsToCANData_m[2] = (uint8_T)((uint8_T)((((uint8_T)0U) & 0xFF)));
  B_n.PackSignalsToCANData_m[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_m[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_m[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_m[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_m[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S32>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_m[0]));

  /* S-Function (CoderCAN_PackBit2Data): '<S34>/Pack Signals To CAN Data' incorporates:
   *  Constant: '<S34>/Constant'
   *  Constant: '<S34>/Constant1'
   *  Constant: '<S5>/Constant2'
   */

  /* --------------- Start pack signal from message -----------------------------
     The number of signals is 3
     ------------------------------------------------------------------------------------------------------------------------------------------------------------*/

  /**********Pack signal 0:startBit= 0U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 1:startBit= 8U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/

  /**********Pack signal 2:startBit= 16U length = 8U byteOrder = LITTLEENDIAN dataType= uint8_T**********/
  B_n.PackSignalsToCANData_fg[0] = (uint8_T)((uint8_T)((((uint8_T)61U) & 0xFF)));
  B_n.PackSignalsToCANData_fg[1] = (uint8_T)((uint8_T)((((uint8_T)206U) & 0xFF)));
  B_n.PackSignalsToCANData_fg[2] = (uint8_T)((uint8_T)((((uint8_T)0U) & 0xFF)));
  B_n.PackSignalsToCANData_fg[3] = (uint8_T)(0);
  B_n.PackSignalsToCANData_fg[4] = (uint8_T)(0);
  B_n.PackSignalsToCANData_fg[5] = (uint8_T)(0);
  B_n.PackSignalsToCANData_fg[6] = (uint8_T)(0);
  B_n.PackSignalsToCANData_fg[7] = (uint8_T)(0);

  /* --------------- End pack signal from message ------------------------------------------------------------------------------------------
     --------------------------------------------------------------------------------*/

  /* S-Function (CAN_TxData): '<S34>/Send CAN Data' */
  F_ASW_CAN_Tx(CAN_CTRL_A, 0, 0,513,3,(ECO_U08 *)(&B_n.PackSignalsToCANData_fg[0]));

  /* End of Start for S-Function (EcoCoder_Task): '<S1>/Task Trigger4' */

  /* Start for S-Function (EcoCoder_Task): '<S1>/Task Trigger7' */
  ASWTaskH_Insert(&nodeASW_H1ms2U,ASW_H1ms2U,0);

  /* End of Start for S-Function (EcoCoder_Task): '<S1>/Task Trigger7' */

  /* Start for S-Function (EcoCoder_Task): '<S1>/Task Trigger6' incorporates:
   *  SubSystem: '<S1>/Ready to drive'
   */

  /* Start for function-call system: '<S1>/Ready to drive' */

  /* Start for S-Function (DIO_In): '<S10>/Brake contactor' */
  F_Abstr_DI_InitChannel(ABS_DI18);

  /* Start for S-Function (DIO_In): '<S10>/Ready to drive button' */
  F_Abstr_DI_InitChannel(ABS_DI01);

  /* Start for Triggered SubSystem: '<S10>/Activate Ready to drive' */

  /* Start for S-Function (DIO_Out): '<S55>/RFE' incorporates:
   *  Constant: '<S55>/Constant'
   */
#ifndef IO_OPWM_LSO06_EN

  F_Abstr_HLSO_InitChannel(LSO06,1,0);

#endif

  /* Start for S-Function (DIO_Out): '<S55>/FRG//RUN' incorporates:
   *  Constant: '<S55>/Constant1'
   */
#ifndef IO_OPWM_LSO07_EN

  F_Abstr_HLSO_InitChannel(LSO07,1,0);

#endif

  /* Start for S-Function (DIO_Out): '<S55>/Ready to drive LED' incorporates:
   *  Constant: '<S55>/Constant3'
   */
#ifndef IO_OPWM_LSO08_EN

  F_Abstr_HLSO_InitChannel(LSO08,1,0);

#endif

  /* Start for S-Function (DIO_Out): '<S55>/Ready to drive sound' incorporates:
   *  Constant: '<S55>/Constant4'
   */
#ifndef IO_OPWM_LSO10_EN

  F_Abstr_HLSO_InitChannel(LSO10,1,0);

#endif

  /* End of Start for SubSystem: '<S10>/Activate Ready to drive' */

  /* Start for Triggered SubSystem: '<S10>/Deactivate Ready to drive' */

  /* Start for S-Function (DIO_Out): '<S56>/RFE' incorporates:
   *  Constant: '<S56>/Constant'
   */
#ifndef IO_OPWM_LSO06_EN

  F_Abstr_HLSO_InitChannel(LSO06,1,0);

#endif

  /* Start for S-Function (DIO_Out): '<S56>/FRG//RUN' incorporates:
   *  Constant: '<S56>/Constant1'
   */
#ifndef IO_OPWM_LSO07_EN

  F_Abstr_HLSO_InitChannel(LSO07,1,0);

#endif

  /* Start for S-Function (DIO_Out): '<S56>/Ready to drive LED' incorporates:
   *  Constant: '<S56>/Constant3'
   */
#ifndef IO_OPWM_LSO08_EN

  F_Abstr_HLSO_InitChannel(LSO08,1,0);

#endif

  /* End of Start for SubSystem: '<S10>/Deactivate Ready to drive' */

  /* Start for Triggered SubSystem: '<S10>/Stop RTD sound' */

  /* Start for S-Function (DIO_Out): '<S58>/Ready to drive sound' incorporates:
   *  Constant: '<S58>/Constant4'
   */
#ifndef IO_OPWM_LSO10_EN

  F_Abstr_HLSO_InitChannel(LSO10,1,0);

#endif

  /* End of Start for SubSystem: '<S10>/Stop RTD sound' */
  ASWTaskH_Insert(&nodeASW_H1ms3U,ASW_H1ms3U,0);

  /* End of Start for S-Function (EcoCoder_Task): '<S1>/Task Trigger6' */

  /* Start for S-Function (EcoCoder_Task): '<S2>/Task Trigger' */

  /* -- Call CAN RX Fcn-Call_0 -- */

  /* End of Start for S-Function (EcoCoder_Task): '<S2>/Task Trigger' */

  /* Start for S-Function (EcoCoder_Task): '<S3>/Task_Call1' incorporates:
   *  SubSystem: '<S3>/Power Off Management'
   */

  /* Start for function-call system: '<S3>/Power Off Management' */

  /* Start for S-Function (DI_Key_In): '<S118>/SwitchInput_ReadKeyOn' */
  F_Abstr_DI_InitChannel(ABS_DI_KEYON);

  /* End of Start for S-Function (EcoCoder_Task): '<S3>/Task_Call1' */

  /* Start for S-Function (EcoCoder_Task): '<S11>/Task Trigger1' incorporates:
   *  SubSystem: '<S11>/Sensors'
   */

  /* Start for function-call system: '<S11>/Sensors' */

  /* Start for S-Function (ADC): '<S65>/Current sensor channel 1' */
  F_Abstr_ADC_InitChannel(ABS_ADC_15);

  /* Start for S-Function (ADC): '<S65>/Current sensor channel 2' */
  F_Abstr_ADC_InitChannel(ABS_ADC_17);

  /* Start for S-Function (ADC): '<S65>/Front brake pressure' */
  F_Abstr_ADC_InitChannel(ABS_ADC_8);

  /* Start for S-Function (ADC): '<S65>/Rear brake pressure' */
  F_Abstr_ADC_InitChannel(ABS_ADC_12);

  /* End of Start for S-Function (EcoCoder_Task): '<S11>/Task Trigger1' */

  /* Start for S-Function (EcoCoder_Task): '<S1>/Task Trigger2' incorporates:
   *  SubSystem: '<S1>/Pump and fans'
   */

  /* Start for function-call system: '<S1>/Pump and fans' */

  /* Start for S-Function (DIO_In): '<S9>/Battery fan ON' */
  F_Abstr_DI_InitChannel(ABS_DI09);

  /* Start for S-Function (DIO_In): '<S9>/Pump ON' */
  F_Abstr_DI_InitChannel(ABS_DI12);

  /* Start for S-Function (DIO_In): '<S9>/Pump and Fan ON' */
  F_Abstr_DI_InitChannel(ABS_DI12);

  /* Start for S-Function (DIO_Out): '<S9>/Battery fan activation' */
#ifndef IO_OPWM_LSO03_EN

  F_Abstr_HLSO_InitChannel(LSO03,1,0);

#endif

  /* Start for S-Function (DIO_Out): '<S9>/Fan activation' */
#ifndef IO_OPWM_LSO13_EN

  F_Abstr_HLSO_InitChannel(LSO13,1,0);

#endif

  /* Start for S-Function (DIO_Out): '<S9>/Pump activation' */
#ifndef IO_OPWM_LSO12_EN

  F_Abstr_HLSO_InitChannel(LSO12,1,0);

#endif

  /* End of Start for S-Function (EcoCoder_Task): '<S1>/Task Trigger2' */
  PrevZCX_p.Datasaving_Trig_ZCE = POS_ZCSIG;
  PrevZCX_p.ActivateReadytodrive_Trig_ZCE = POS_ZCSIG;
  PrevZCX_p.DeactivateReadytodrive_Trig_ZCE = POS_ZCSIG;
  PrevZCX_p.StopRTDsound_Trig_ZCE = POS_ZCSIG;
  PrevZCX_p.ShutdownPower_Trig_ZCE = ZERO_ZCSIG;
  PrevZCX_p.SoftwareReset_Trig_ZCE = ZERO_ZCSIG;
  PrevZCX_p.StoreAllNVMData_Trig_ZCE = ZERO_ZCSIG;

  /* SystemInitialize for S-Function (EcoCoder_Task): '<S3>/Task_Call1' incorporates:
   *  SubSystem: '<S3>/Power Off Management'
   */

  /* System initialize for function-call system: '<S3>/Power Off Management' */
  DW_l.PowerOffManagement_PREV_T = M->Timing.clockTick1;

  /* InitializeConditions for UnitDelay: '<S116>/Unit Delay7' */
  DW_l.UnitDelay7_DSTATE = true;

  /* InitializeConditions for UnitDelay: '<S116>/Unit Delay4' */
  DW_l.UnitDelay4_DSTATE = true;

  /* InitializeConditions for UnitDelay: '<S116>/Unit Delay5' */
  DW_l.UnitDelay5_DSTATE = true;

  /* InitializeConditions for UnitDelay: '<S116>/Unit Delay6' */
  DW_l.UnitDelay6_DSTATE = true;

  /* SystemInitialize for Enabled SubSystem: '<S116>/KeyCycle' */
  /* SystemInitialize for Atomic SubSystem: '<S119>/ER_xxxx' */
  /* InitializeConditions for UnitDelay: '<S128>/Unit Delay' */
  DW_l.UnitDelay_DSTATE_k = true;

  /* End of SystemInitialize for SubSystem: '<S119>/ER_xxxx' */

  /* SystemInitialize for Atomic SubSystem: '<S119>/ER_xxxx1' */
  /* InitializeConditions for UnitDelay: '<S129>/Unit Delay' */
  DW_l.UnitDelay_DSTATE_m = true;

  /* End of SystemInitialize for SubSystem: '<S119>/ER_xxxx1' */
  /* End of SystemInitialize for SubSystem: '<S116>/KeyCycle' */

  /* End of SystemInitialize for S-Function (EcoCoder_Task): '<S3>/Task_Call1' */

  /* SystemInitialize for S-Function (EcoCoder_Task): '<S1>/Task Trigger' incorporates:
   *  SubSystem: '<S1>/APPS and torque setpoint'
   */

  /* System initialize for function-call system: '<S1>/APPS and torque setpoint' */

  /* InitializeConditions for S-Function (sfix_udelay): '<S13>/Tapped Delay' */
  memset(&DW_l.TappedDelay_X_i5[0], 0, 90U * sizeof(boolean_T));

  /* End of SystemInitialize for S-Function (EcoCoder_Task): '<S1>/Task Trigger' */

  /* SystemInitialize for S-Function (EcoCoder_Task): '<S1>/Task Trigger7' incorporates:
   *  SubSystem: '<S1>/Brake pedal plausibility check'
   */

  /* System initialize for function-call system: '<S1>/Brake pedal plausibility check' */

  /* InitializeConditions for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
  memset(&DW_l.TappedDelay_X[0], 0, 490U * sizeof(boolean_T));

  /* End of SystemInitialize for S-Function (EcoCoder_Task): '<S1>/Task Trigger7' */

  /* SystemInitialize for S-Function (EcoCoder_Task): '<S1>/Task Trigger6' incorporates:
   *  SubSystem: '<S1>/Ready to drive'
   */

  /* System initialize for function-call system: '<S1>/Ready to drive' */

  /* InitializeConditions for S-Function (sfix_udelay): '<S10>/Tapped Delay' */
  memset(&DW_l.TappedDelay_X_i[0], 0, 1000U * sizeof(boolean_T));

  /* End of SystemInitialize for S-Function (EcoCoder_Task): '<S1>/Task Trigger6' */
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
