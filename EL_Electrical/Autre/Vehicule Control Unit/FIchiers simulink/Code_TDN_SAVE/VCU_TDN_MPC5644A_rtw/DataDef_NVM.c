/******************************************************************************
 * Copyright (C),
 * File name:         DataDef_NVM.c
 *   <Author>         <Version>        <Date>
 *   HXL              0.2             2018-5-29
 * Description:
 * Develop pack:      CodeWarrior
 * Function List:
 *   1.
 * History:
 *   1. Date:         2018-5-7
 *      Author:       HXL
 *      Ver:          0.1
 *      Modification: Create
 *   2. *   Standards:
 ******************************************************************************/
#include "DataDef_NVM.h"

/**************************NVM Data Definition**********************************************************/
#define PUSH__UFNVMP
#include "EcoSectionDef.h"

__UFNVMP uint16_T nvmN_100[1U]= { 0.0 };

__UFNVMP uint16_T nvmN_lim[1U]= { 0.0 };

__UFNVMP int16_T nvmN_lim_pos[1U]= { 0.0 };

__UFNVMP int16_T nvmN_lim_neg[1U]= { 0.0 };

__UFNVMP int16_T nvmN_R_Acc[1U]= { 0.0 };

__UFNVMP int16_T nvmM_R_Acc[1U]= { 0.0 };

__UFNVMP int16_T nvmN_R_Dec[1U]= { 0.0 };

__UFNVMP int16_T nvmM_R_Dec[1U]= { 0.0 };

__UFNVMP int16_T nvmN_act_filt[1U]= { 0.0 };

__UFNVMP int16_T nvmSpeedRPMmax[1U]= { 0.0 };

__UFNVMP int16_T nvmI_max_eff[1U]= { 0.0 };

__UFNVMP int16_T nvmI_nom_eff[1U]= { 0.0 };

__UFNVMP int16_T nvmI_max_pk[1U]= { 0.0 };

__UFNVMP int16_T nvmI_device[1U]= { 0.0 };

__UFNVMP int16_T nvmI_200[1U]= { 0.0 };

__UFNVMP int16_T nvmVdc_bus[1U]= { 0.0 };

__UFNVMP int16_T nvmI_act_filt[1U]= { 0.0 };

__UFNVMP int16_T nvmI_cmd[1U]= { 0.0 };

__UFNVMP int16_T nvmT_IGBT[1U]= { 0.0 };

__UFNVMP int16_T nvmT_motor[1U]= { 0.0 };

__UFNVMP int16_T nvmT_air[1U]= { 0.0 };

__UFNVMP boolean_T nvmAPPS_FAULT[1U]= { 0.0 };

__UFNVMP float nvmAPPS_M[1U]= { 0.0 };

__UFNVMP uint16_T nvmAPPS_1[1U]= { 0.0 };

__UFNVMP uint16_T nvmAPPS_2[1U]= { 0.0 };

__UFNVMP int16_T nvmVdc_bus_V[1U]= { 0.0 };

__UFNVMP int16_T nvmI_act_filt_A[1U]= { 0.0 };

__UFNVMP int16_T nvmSpeed[1U]= { 0.0 };

__UFNVMP int16_T nvmN_act_filt_RPM[1U]= { 0.0 };

__UFNVMP int16_T nvmT_air_deg[1U]= { 0.0 };

__UFNVMP int16_T nvmT_motor_deg[1U]= { 0.0 };

__UFNVMP int16_T nvmT_IGBT_deg[1U]= { 0.0 };

__UFNVMP boolean_T nvmBATT_FAN_ON[1U]= { 0.0 };

__UFNVMP boolean_T nvmPUMP_ON[1U]= { 0.0 };

__UFNVMP boolean_T nvmFAN_ON[1U]= { 0.0 };

__UFNVMP boolean_T nvmBRK_CONTACTOR[1U]= { 0.0 };

__UFNVMP boolean_T nvmRDY_DRV_BUTTON[1U]= { 0.0 };

__UFNVMP boolean_T nvmRDY_DRV[1U]= { 0.0 };

__UFNVMP boolean_T nvmBRK_PDL_FAULT[1U]= { 0.0 };

#define POP__UFNVMP
#include "EcoSectionDef.h"
