/*
 * CNC_MonitoringEventHandler.c
 *
 *  Created on: Aug 7, 2020
 *      Author: BSR5COB
 *Assumption made: PROC runs in 1 sec cycle
 */

//***mainly function calls to get the input data****
//****//
//Operating temperature: Temperature around the CNC machine in Celsius. 
//Reported every half-hour. Need to alert if it goes beyond 35 degrees.



#include <stdio.h>
#include "CNC_MonitorDataCollector.h"
#include "CNC_OutPutMappingElements.h"
#include "CNC_MonitoringEventHandler.h"

/*
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
*/

void Fun_CNC_MonitoringEventHandler( CNC_MonitorOutPut_Display_Text)
{
int l_AccusticWarning;

int l_LampIndication;

l_AccusticWarning = 0;

l_LampIndication = 0;

	if(CNC_MonitorOutPut_Display_Text)
	{
	l_AccusticWarning = C_CNC_Accustic_Beep_N;

	l_LampIndication = C_CNC_Lamp_On_N;

	
	}
	else 
	{
	l_AccusticWarning = C_CNC_Accustic_Off_N;

	l_LampIndication = C_CNC_Lamp_Off_N;
	}

g_CNC_LampIndication = l_LampIndication;

g_CNC_AccusticWarning = l_AccusticWarning;
}