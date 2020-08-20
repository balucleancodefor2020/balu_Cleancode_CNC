/*
 * CNC_Process.c
 *
 *  Created on: Aug 7, 2020
 *      Author: BSR5COB
 * This file is to collect the inputs which 
 * Monitor unit is providing concerning the
 * CNC machine health
 Assumption made: PROC runs in 1 sec cycle
 */

void PROC_CNC_Evaluation_Init();

void PROC_CNC_Evaluation_Cyclic_1Sec()
{
FUN_CNC_MonitorDataColloction();
FUN_CNC_MonitorDataEvaluation();
CNC_OutPut_DiagMapping();
Fun_CNC_MonitoringEventHandler();
CNC_Fun_OutPutDriver();
}