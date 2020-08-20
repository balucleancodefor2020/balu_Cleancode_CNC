/*
 * CNC_MonitoringEventHandler.h
 *
 *  Created on: Aug 7, 2020
 *      Author: BSR5COB
 * This file is to collect the inputs which 
 * Monitor unit is providing concerning the
 * CNC machine health
 Assumption made: PROC runs in 1 sec cycle
 */

int g_CNC_LampIndication; 

int g_CNC_AccusticWarning;

enum 
{
  C_CNC_Lamp_Off_N = 0,
  C_CNC_Lamp_On_N,
  C_CNC_Lamp_0_5Hz_N,
  C_CNC_Lamp_Error_N,
  C_CNC_Lamp_3_3Hz_N,
  C_CNC_Lamp_Freeze_N
} CNC_Lamp_N;

enum 
{
  C_CNC_Accustic_Off_N = 0,
  C_CNC_Accustic_Chime_N,
  C_CNC_Accustic_Beep_N,
  C_CNC_Accustic_Freeze_N
} CNC_Accustic_N;