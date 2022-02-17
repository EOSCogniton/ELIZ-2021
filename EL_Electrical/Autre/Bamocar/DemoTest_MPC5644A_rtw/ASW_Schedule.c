/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ASW_Schedule.c
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

#include "ASW_Schedule.h"
#include "DemoTest.h"
#ifndef NULL
#define NULL                           (void *)(0)
#endif

TASK_List TaskHList[4];
uint8_T flgTaskCteate= 0;
void ASWTaskH_Create(void)
{
  uint8_T i;
  for (i=0;i<NUM_TASKH_CHANNEL;i++) {
    TaskHList[i].prear= NULL;
    TaskHList[i].phead= NULL;
  }
}

void ASWTaskH_Insert(pTASK_Node pNode,asw_task_ptr pTask_s,uint8_T channelTask)
{
  pNode->pTask= pTask_s;
  if (0==flgTaskCteate) {
    ASWTaskH_Create();
    flgTaskCteate= 1;
  }

  if (NULL==TaskHList[channelTask].phead) {
    TaskHList[channelTask].phead= pNode;
  } else {
    TaskHList[channelTask].prear->next= pNode;
  }

  pNode->next= NULL;
  TaskHList[channelTask].prear= pNode;
}

void ASWTaskH_Traversing(uint8_T channelTask)
{
  pTASK_Node pNode;
  if (0==flgTaskCteate) {
    return;
  }

  if (NULL==TaskHList[channelTask].phead) {
    return;
  } else {
    for (pNode=TaskHList[channelTask].phead;pNode!=NULL;pNode=pNode->next) {
      pNode->pTask();
    }
  }
}

void ASWTaskH1ms_Traversing(void)
{
  ASWTaskH_Traversing(0);
}

void ASWTaskH5ms_Traversing(void)
{
  ASWTaskH_Traversing(1);
}

void ASWTaskH10ms_Traversing(void)
{
  ASWTaskH_Traversing(2);
}

void ASWTaskH20ms_Traversing(void)
{
  ASWTaskH_Traversing(3);
}

void ASWTask_Create(void)
{
  FP_OS_ASW_H1ms = &ASWTaskH1ms_Traversing;
  FP_OS_ASW_H5ms = &ASWTaskH5ms_Traversing;
  FP_OS_ASW_H10ms = &ASWTaskH10ms_Traversing;
  FP_OS_ASW_H20ms = &ASWTaskH20ms_Traversing;
}

/******************************************************************************
 *   Function:           ASW_L1ms_Step
 *   Description:
 *   Input:
 *   Output:
 *   Return:
 *   Others:
 ******************************************************************************/

/******************************************************************************
 *   Function:           ASW_Schedule_init
 *   Description:
 *   Input:
 *   Output:
 *   Return:
 *   Others:
 ******************************************************************************/
void ASW_Schedule_Nop(void)
{
}

void ASW_Schedule_Init(void)
{
  DemoTest_initialize();

  /**********************************************************/
  FP_OS_ASW_L1ms = &ASW_Schedule_Nop;
  FP_OS_ASW_L5ms = &ASW_Schedule_Nop;
  FP_OS_ASW_L10ms = &ASW_Schedule_Nop;
  FP_OS_ASW_L20ms = &ASW_Schedule_Nop;
  FP_OS_ASW_L50ms = &ASW_Schedule_Nop;
  FP_OS_ASW_L100ms = &ASW_Schedule_Nop;
  FP_OS_ASW_L200ms = &ASW_Schedule_Nop;
  FP_OS_ASW_L500ms = &ASW_Schedule_Nop;
  FP_OS_ASW_L1000ms = &ASW_Schedule_Nop;

  /**********************************************************/
  /**********************************************************/
  FP_OS_ASW_L1ms = &DemoTest_step0;    /* Sample time: 1ms */
  FP_OS_ASW_L5ms = &DemoTest_step1;    /* Sample time: 5ms */
  FP_OS_ASW_L10ms = &DemoTest_step2;   /* Sample time: 10ms  */
  FP_OS_ASW_L20ms = &DemoTest_step3;   /* Sample time: 20ms  */
  FP_OS_ASW_L50ms = &DemoTest_step4;   /* Sample time: 50ms  */
  FP_OS_ASW_L100ms = &DemoTest_step5;  /* Sample time: 100ms  */
  FP_OS_ASW_L200ms = &DemoTest_step6;  /* Sample time: 200ms */
  FP_OS_ASW_L500ms = &DemoTest_step7;  /* Sample time: 500ms   */
  FP_OS_ASW_L1000ms = &DemoTest_step8; /* Sample time: 1000ms */

  /**********************************************************/
  ASWTask_Create();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
