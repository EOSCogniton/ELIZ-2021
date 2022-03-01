/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LLD_InitConf.c
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

/******************************************************************************
   Includes
 ******************************************************************************/
#include "EcoCoderTypeDef.h"
#include "LLD_InitConf.h"
#include "Abstraction_HLSO.h"
#include "Abstraction_DI.h"
#include "Abstraction_ADC.h"
#include "Abstraction_IPWM.h"
#include "Abstraction_MCU.h"
#include "Abstraction_Sys.h"
#include "Service_CAN.h"
#include "ASW_IO_Init.h"
#include "ASW_Schedule.h"
#include "Service_LIN.h"
#ifdef STORAGE_CALIBRATION_INIT_BY_ASW
#include "Abstraction_Storage.h"
#endif

#include "VCU_TDN.h"

/******************************************************************************
 *   Function:           LLD_CAN_Isr_Ptr_Init
 *   Description:
 *   Input:
 *   Output:
 *   Return:
 *   Others:
 ******************************************************************************/
void LLD_CAN_Isr_Ptr_Init(void)
{

#ifdef CANA_Rx_Enable

  FP_CAN_Driver_RxMsg2Array_EventA = &F_CAN_ASW_RxMsg2Array_EventA;

#endif

#ifdef CANA_WakeUp_Enable

  CANA_WakeUp_Isr_Handler_Ptr = &CANA_WakeUp_Isr_Handler;

#endif

#ifdef CANB_Rx_Enable

  FP_CAN_Driver_RxMsg2Array_EventB = &F_CAN_ASW_RxMsg2Array_EventB;

#endif

#ifdef CANB_WakeUp_Enable

  CANB_WakeUp_Isr_Handler_Ptr = &CANB_WakeUp_Isr_Handler;

#endif

#ifdef CANC_Rx_Enable

  FP_CAN_Driver_RxMsg2Array_EventC = &F_CAN_ASW_RxMsg2Array_EventC;

#endif

#ifdef CANC_WakeUp_Enable

  CANC_WakeUp_Isr_Handler_Ptr = &CANC_WakeUp_Isr_Handler;

#endif

}

/******************************************************************************
 *   Function:           LLD_CAN_Init
 *   Description:
 *   Input:
 *   Output:
 *   Return:
 *   Others:
 ******************************************************************************/
void LLD_CAN_Init(void)
{
  F_Servece_CAN_Init();
  LLD_CAN_Isr_Ptr_Init();
}

/******************************************************************************
 *   Function:           MEM_NFNVM_Init
 *   Description:  20180517
 *   Input:
 *   Output:
 *   Return:
 *   Others:
 ******************************************************************************/
#define PUSH__UFNVMF
#include "EcoSectionDef.h"
#ifdef MEM_NFNVM_INT_EN

__UFNVMF ECO_U08 MEM_flgUnFixedNvmInitSet = ECO_MEM_NFNEM_INIT_SET;

#else

__UFNVMF ECO_U08 MEM_flgUnFixedNvmInitSet = 0;
                                 //0:Restore from factory default values in .mot

#endif

#define POP__UFNVMF
#include "EcoSectionDef.h"

ECO_U08 MEM_NFNVM_Init(void)
{
  ECO_U08 iLLDCAL= 0;
  iLLDCAL= MEM_flgUnFixedNvmInitSet;
  if (iLLDCAL) {
    return 1;
  } else {
    return 0;
  }
}

/******************************************************************************
 *   Function:           F_Abstr_Init
 *   Description:
 *   Input:
 *   Output:
 *   Return:
 *   Others:
 ******************************************************************************/
void F_Abstr_ECU_Init(void)
{

#ifdef SCIA_ENABLE_MD

  LLD_SCI_Init();

#endif

  LLD_CAN_Init();
  F_Service_LIN_Init();

  //F_Abstr_DO_Init();
  F_ASW_IO_init();

#ifdef ASW_WDG_EN

  F_Abstr_WD_Init();

#endif

#ifdef MEM_NVM_INT_EN

  MEM_NVM_Init();

#endif

  MEM_NFNVM_Init();

#ifdef ASW_DETECT_STACK_OVERFLOW_EN

  F_Abstr_EnableStackProtect();

#endif

}

void F_Abstr_CAL_Check()
{

#ifdef STORAGE_CALIBRATION_INIT_BY_ASW

  F_Abs_Storage_Calibration_Init();

#endif

  EcoCoder_CAB_ChecheFailedWhile();
}

/******************************************************************************
 *   Function:           F_BSW_ASW_Init
 *   Description:
 *   Input:
 *   Output:
 *   Return:
 *   Others:
 ******************************************************************************/
void F_BSW_ASW_Init(void)
{
  F_Abstr_MCU_INTC_DIS();
  F_Abstr_MCU_Init();
  F_Abstr_ECU_Init();
  F_Abstr_CAL_Check();
  ASW_Schedule_Init();
  F_Abstr_MCU_INTC_EN();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
