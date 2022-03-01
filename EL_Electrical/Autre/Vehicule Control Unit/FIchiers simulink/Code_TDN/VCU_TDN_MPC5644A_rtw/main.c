/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main.c
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

#include "LLD_InitConf.h"

/******************************************************************************
 * Copyright (C),
 * File name:         main.h
 *   <Author>         <Version>        <Date>
 *   HXL              0.2             2015-5-28
 * Description:
 * Develop pack:      CodeWarrior
 * Function List:
 *   1.
 * History:
 *   1. Date:         2015-5-15
 *      Author:       HXL
 *      Ver:          0.1
 *      Modification: Create
 *   2. *   Standards:
 ******************************************************************************/
/******************************************************************************
   Includes
 ******************************************************************************/
#include "LLD_InitConf.h"
#include "os_main.h"

/*******************************************************************************
 *
 *******************************************************************************/

/******************************************************************************
   Pubilc Functions
 ******************************************************************************/
int main(void)
{
  F_BSW_ASW_Init();
  F_OS_Init();
  F_OS_LStart();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
