/******************************************************************************
 * Copyright (C),
 * File name:         Service_CAN.c
 *   <Author>         <Version>        <Date>
 *   HXL              0.3             2018-5-29
 * Description:
 * Develop pack:      CodeWarrior
 * Function List:
 *   1.
 * History:
 *   1. Date:         2015-5-15
 *      Author:       HXL
 *      Ver:          0.1
 *      Modification: Create
 *   2. Date:         2015-5-28
 *      Author:       HXL
 *      Ver:          0.2
 *      Modification: Create
 *   Standards:
 ******************************************************************************/
/******************************************************************************
   Includes
 ******************************************************************************/
#include <string.h>
#include "Service_CAN.h"
#include "LLD_InitConf.h"
#include "EcoCoderTypeDef.h"

//#include "ccp_driver.h"
#include "ECOCCP_Main.h"
#include "Abstraction_Sys.h"
#include "MCAL_FLASH.h"
#include "VCU_TDN.h"
#include "os_main.h"

/*******************************************************************************
 * Private Variable Definitions
 *******************************************************************************/
#define NUM_CANTx_CHANNEL              3

CANMsgElement_t canMsgElement0[30];
CANMsgElement_t canMsgElement1[30];
CANMsgElement_t canMsgElement2[30];
CANMsgElementPrt_t canMsgElementPrt[NUM_CANTx_CHANNEL]= {
  { canMsgElement0, 30 },

  { canMsgElement1, 30 },

  { canMsgElement2, 30 },
};

CANMsgQueue_t canMsgQueue[NUM_CANTx_CHANNEL];

/***********************************Direct Read List Start**************************************************/
#define NUM_CANRx_CHANNEL              3

CANDirectSlot_t CANDirectSlotMsgElemenA[1U];
CANDirectSlot_t CANDirectSlotMsgElemenB[1U];
CANDirectSlot_t CANDirectSlotMsgElemenC[1];
CANDirectSlotElementPrt_t CANDirectSlotMsgElementPrt[NUM_CANRx_CHANNEL]= {
  { CANDirectSlotMsgElemenA, 1U },

  { CANDirectSlotMsgElemenB, 1U },

  { CANDirectSlotMsgElemenC, 0U },
};

CANDirectSlot_Queue_t CANDirectSlot_Queue[NUM_CANRx_CHANNEL];

/***********************************Direct Read List End**************************************************/
void F_Servece_CAN_Update_H1ms(void)
{
  CANMsgElement_t messageObj;
  if (1==F_Servece_CAN_ReceiveDirect(&ServiceCANDirectSlot0x100_0_can1,
       &messageObj)) {
    F_ECOCCP_CcpMainFunction((CCP_CANMsgElement_t*)&messageObj);
  }
}

void F_Servece_CAN_Update_L1ms(void)
{
  static ECOCCP_U16 DAQ_cnt1= 0;
  static ECOCCP_U16 DAQ_cnt2= 0;
  DAQ_cnt1++;
  if (DAQ_cnt1>=20) {
    F_ECOCCP_CcpDaqEvent(ECOCCP_EVENT_CHANNEL_1);
    DAQ_cnt1= 0;
  }

  DAQ_cnt2++;
  if (DAQ_cnt2>=100) {
    F_ECOCCP_CcpDaqEvent(ECOCCP_EVENT_CHANNEL_2);
    DAQ_cnt2= 0;
  }
}

void F_Servece_CAN_Update_5ms(void)
{
}

void F_Servece_CAN_Update_10ms(void)
{
}

void F_Servece_CAN_Update_20ms(void)
{
}

void F_Servece_CAN_Update_100ms(void)
{
}

#define PUSH__ADDR_EPK
#include "EcoSectionDef.h"

__ADDR_EPK __attribute__ ((__used__)) ECO_U08 ASW_CCP_EPKData[]= {
  "2022-03-01 18:01:38" };

#define POP__ADDR_EPK
#include "EcoSectionDef.h"

ECOCCP_U08 ASW_CCP_CAL_FLSBuffer[MCAL_FLASH_PAGESIZE+7]= { 0 };

static ECOCCP_ODT_t ASW_CCP_odt[0+32+48+0+1];
static ECOCCP_U08 ASW_CCP_OdtEntryList[0+32+48+0+1];
void F_CCP21_ProCtrl(ECOCCP_U08 en)
{
  if (1==en) {
    F_Abstr_SWT_Resume();
    F_OS_ASWTaskCtrl(1);
  } else if (0==en) {
    F_Abstr_SWT_Pause();
    F_OS_ASWTaskCtrl(0);
  }
}

/******************************************************************************
   Pubilc Functions
 ******************************************************************************/
void call_back_null(void)
{
  return;
}

void F_Servece_CAN_Init(void)
{
  ECOCCP_Config_t ccpConfigTmp;

  {
    CANDeviceSetting_t canSettingTmp;
    memset((void *)&canSettingTmp,0,sizeof(CANDeviceSetting_t));
    canSettingTmp.enChannel= 1;
    canSettingTmp.enIDFilter= 0;
    canSettingTmp.rxID= 0x100;
    canSettingTmp.rxIDMask= 0x7FF;
    canSettingTmp.extened= 0;
    canSettingTmp.baudrate= 500;
    F_Abstr_CANDevice_Init(CAN_CTRL_A,&canSettingTmp);
  }

  {
    CANDeviceSetting_t canSettingTmp;
    memset((void *)&canSettingTmp,0,sizeof(CANDeviceSetting_t));
    canSettingTmp.enChannel= 1;
    canSettingTmp.enIDFilter= 0;
    canSettingTmp.rxID= 0x100;
    canSettingTmp.rxIDMask= 0x7FF;
    canSettingTmp.extened= 0;
    canSettingTmp.baudrate= 500;
    F_Abstr_CANDevice_Init(CAN_CTRL_B,&canSettingTmp);
  }

  {
    CANDeviceSetting_t canSettingTmp;
    memset((void *)&canSettingTmp,0,sizeof(CANDeviceSetting_t));
    canSettingTmp.enChannel= 1;
    canSettingTmp.enIDFilter= 0;
    canSettingTmp.rxID= 0x100;
    canSettingTmp.rxIDMask= 0x7FF;
    canSettingTmp.extened= 0;
    canSettingTmp.baudrate= 500;
    F_Abstr_CANDevice_Init(CAN_CTRL_C,&canSettingTmp);
  }

  F_Abstr_CAN_Init(canMsgQueue,canMsgElementPrt,NUM_CANTx_CHANNEL);

  /**************************SvcCANDrtSlt0x181_0_0_1U*************************************/
  SvcCANDrtSlt0x181_0_0_1U.messageObj.id= 0x181;
  SvcCANDrtSlt0x181_0_0_1U.messageObj.extended= 0;
  SvcCANDrtSlt0x181_0_0_1U.messageObj.length= 6;
  SvcCANDrtSlt0x181_0_0_1U.messageObj.remote= 0;
  SvcCANDrtSlt0x181_0_0_1U.ready= 0;
  SvcCANDrtSlt0x181_0_0_1U.read= 0;
  SvcCANDrtSlt0x181_0_0_1U.write= 0;

  /*************************************************************************/

  /**************************ServiceCANDirectSlot0x100_0_can1*************************************/
  ServiceCANDirectSlot0x100_0_can1.messageObj.id= 0x100;
  ServiceCANDirectSlot0x100_0_can1.messageObj.extended= 0;
  ServiceCANDirectSlot0x100_0_can1.messageObj.length= 8;
  ServiceCANDirectSlot0x100_0_can1.messageObj.remote= 0;
  ServiceCANDirectSlot0x100_0_can1.ready= 0;
  ServiceCANDirectSlot0x100_0_can1.read= 0;
  ServiceCANDirectSlot0x100_0_can1.write= 0;

  /*************************************************************************/
  F_Abstr_CANRx_Init(CANDirectSlot_Queue,CANDirectSlotMsgElementPrt,
                     NUM_CANRx_CHANNEL);

  /**************CCP******************************/
  ccpConfigTmp.en= 1;
  ccpConfigTmp.stCALSeedKey = 0x11;
  ccpConfigTmp.stDAQSeedKey = 0x22;
  ccpConfigTmp.stPGMSeedKey = 0x33;
  ccpConfigTmp.unLock= 1001;
  ccpConfigTmp.can_channel= 1;
  ccpConfigTmp.stationAddr= 0x112;
  ccpConfigTmp.idCro= 0x100;
  ccpConfigTmp.idDto= 0x101;
  ccpConfigTmp.idDaq[0]= 0x101;
  ccpConfigTmp.idDaq[1]= 0x101;
  ccpConfigTmp.idDaq[2]= 0x101;
  ccpConfigTmp.idDaq[3]= 0x102;
  ccpConfigTmp.pidDaq[0]= 0x0;
  ccpConfigTmp.pidDaq[1]= 0x3C;
  ccpConfigTmp.pidDaq[2]= 0x78;
  ccpConfigTmp.pidDaq[3]= 0x0;
  ccpConfigTmp.lenDaq[0]= 0;
  ccpConfigTmp.lenDaq[1]= 32;
  ccpConfigTmp.lenDaq[2]= 48;
  ccpConfigTmp.lenDaq[3]= 0;
  ccpConfigTmp.lenDaqMax= 48;
  (ccpConfigTmp.ccp21ConfigMem).codeRomStart= 0x01000200;
  (ccpConfigTmp.ccp21ConfigMem).calRomStart= 0x00FD0000;
  (ccpConfigTmp.ccp21ConfigMem).calRamStart= 0x40000000;
  (ccpConfigTmp.ccp21ConfigMem).daqRamStart= 0x40000000;
  (ccpConfigTmp.ccp21ConfigMem).calMaxLength= 0x8000;
  (ccpConfigTmp.ccp21ConfigMem).daqMaxLength= 0x00060000;
  (ccpConfigTmp.ccp21ConfigMem).calMinWriteSize= MCAL_FLASH_PAGESIZE;
  (ccpConfigTmp.ccp21ConfigMem).calBuff= ASW_CCP_CAL_FLSBuffer;
  (ccpConfigTmp.ccp21ConfigMem).cntBuff= 0;
  (ccpConfigTmp.ccp21ConfigMem).EPKIDAddr= (ECOCCP_U32)ASW_CCP_EPKData;//0x01000100
  (ccpConfigTmp.ccp21ConfigMem).EPKLength= (ECOCCP_U08)(sizeof(ASW_CCP_EPKData)/
    sizeof(ASW_CCP_EPKData[0]));
  (ccpConfigTmp.ccp21ConfigMem).EPKLengthMax= (ECOCCP_U08)0xFF;
  (ccpConfigTmp.ccp21ConfigMem).bootIDAddr= 0x2010;
  (ccpConfigTmp.ccp21ConfigMem).calLength= 0x8000;//Calibration_Data_Length;
  (ccpConfigTmp.ccp21ConfigMem).odt= ASW_CCP_odt;
  (ccpConfigTmp.ccp21ConfigMem).OdtEntryList= ASW_CCP_OdtEntryList;

#ifdef ECO_CCP_SET_SEED_EN

  FP_CcpSetSeedTrigger= &EcoCoder_CCP_SetSeed_Trigger;

#endif

  //ccpConfigTmp.ccpCfg=&ASW_CCP21Cfg;
  FP_CcpTaskCtrl= &F_CCP21_ProCtrl;
  FP_CcpFlash_Program= &Mcal_Flash_ProgramFlash;
  FP_CcpFlash_ClearMemory= &Mcal_Flash_EraseFlash;
  FP_CcpCAN_SendMsg= (FType_CcpCAN_SendMsg)&F_Abstr_CAN_Transmit2Queue;
  F_ECOCCP_CcpInit(&ccpConfigTmp);

#ifdef CCP_EV2106B01_EN

  //Task_Enable=1;
#endif

  //CCP_vInit();
#ifdef FLASH_ONLINE_EN

  FLASH_ONLINE_Init();

#endif

  FP_OS_COM_SERVE_H1ms = F_Servece_CAN_Update_H1ms;
  FP_OS_COM_SERVE_L1ms = F_Servece_CAN_Update_L1ms;
  FP_OS_COM_SERVE_H5ms = F_Servece_CAN_Update_5ms;
  FP_OS_COM_SERVE_H10ms = F_Servece_CAN_Update_10ms;
  FP_OS_COM_SERVE_L20ms = F_Servece_CAN_Update_20ms;
  FP_OS_COM_SERVE_L100ms = F_Servece_CAN_Update_100ms;
}

ECO_U08 F_Servece_CAN_ReceiveDirect(CANDirectSlot_t *directslot, CANMsgElement_t
  *messageObj)
{
  return F_Abstr_CAN_ReceiveDirect(directslot,messageObj);
}

ECO_U08 F_Servece_CAN_Transmit(CanControllerIdType channel, CANMsgElement_t
  *messageObj)
{
  return F_Abstr_CAN_Transmit2Queue(channel,messageObj);
}

ECO_U08 F_ASW_CAN_Tx(CanControllerIdType channel, ECO_BOOL remote, ECO_BOOL
                     extended,ECO_U32 id,ECO_U08 length,ECO_U08 *data)
{
  CANMsgElement_t messageObj;
  ECO_U08 i;
  messageObj.remote= remote;
  messageObj.extended= extended;
  messageObj.id= id;
  messageObj.length= length;
  for (i=0;i<length;i++) {
    messageObj.data[i]= data[i];
  }

  return F_Abstr_CAN_Transmit2Queue(channel,&messageObj);
}

ECO_BOOL F_ASW_CAN_Rx(CANDirectSlot_t *directslot, ECO_BOOL *remote, ECO_BOOL
                      *extended,ECO_U32 *id,ECO_U08 *length,ECO_U08 *data)
{
  CANMsgElement_t messageObj;
  ECO_BOOL flgSlotStr= 0;
  ECO_U08 i;
  flgSlotStr= F_Servece_CAN_ReceiveDirect(directslot, &messageObj);
  if (1==flgSlotStr) {
    *remote= messageObj.remote;
    *extended= messageObj.extended;
    *id= messageObj.id;
    *length= messageObj.length;
    for (i=0;i<8;i++) {
      data[i]= messageObj.data[i];
    }
  }

  return flgSlotStr;
}
