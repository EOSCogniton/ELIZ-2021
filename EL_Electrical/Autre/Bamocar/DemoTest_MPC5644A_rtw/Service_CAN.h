/******************************************************************************
 * Copyright (C),
 * File name:         Service_CAN.h
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

#ifndef _H_Service_CAN_H_
#define _H_Service_CAN_H_

/******************************************************************************
   Includes
 ******************************************************************************/
#include "Abstraction_CAN.h"
#include "EcoCoderTypeDef.h"

/******************************************************************************
   Exported Data Declarations
 ******************************************************************************/
extern CANDirectSlot_t CANDirectSlotMsgElemenA[1];
extern CANDirectSlot_t CANDirectSlotMsgElemenB[1];
extern CANDirectSlot_t CANDirectSlotMsgElemenC[1U];

#define ServiceCANDirectSlot0x100_0_can2 CANDirectSlotMsgElemenC[0]

/******************************************************************************
   Exported Function Declarations
 ******************************************************************************/
extern void F_Servece_CAN_Init(void);
extern ECO_U08 F_Servece_CAN_ReceiveDirect(CANDirectSlot_t *directslot,
  CANMsgElement_t *messageObj);
extern ECO_U08 F_Servece_CAN_Transmit(CanControllerIdType channel,
  CANMsgElement_t *messageObj);
extern ECO_U08 F_ASW_CAN_Tx(CanControllerIdType channel, ECO_BOOL remote,
  ECO_BOOL extended,ECO_U32 id,ECO_U08 length,ECO_U08 *data);
extern ECO_BOOL F_ASW_CAN_Rx(CANDirectSlot_t *directslot, ECO_BOOL *remote,
  ECO_BOOL *extended,ECO_U32 *id,ECO_U08 *length,ECO_U08 *data);

#endif                                 /* _H_Service_CAN_H_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
