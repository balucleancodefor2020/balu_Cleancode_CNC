/*
 * CNC_MonitorDataCollector.c
 *
 *  Created on: Aug 7, 2020
 *      Author: BSR5COB
 * This file is to collect the inputs which 
 * Monitor unit is providing concerning the
 * CNC machine health
 Assumption made: PROC runs in 1 sec cycle
 */

//***mainly function calls to get the input data****
//****//
//Operating temperature: Temperature around the CNC machine in Celsius. 
//Reported every half-hour. Need to alert if it goes beyond 35 degrees.

//#include "CNC_MonitorDataCollector.h"

#include <stdio.h>
#include "CNC_MonitorDataCollector.h"
#include "CNC_OutPutMappingElements.h"
#include "CNC_Monitordata_stub_inputs.h"



/*TOD: Seperating EACH Scenario to seperate Funs 
*
*Allso add wrapper for Testing
*
*
*/
void FUN_CNC_MonitorDataColloction()
{
//Operating temperature: Temperature around the CNC machine in Celsius. 
//Reported every half-hour. 
//Need to alert if it goes beyond 35 degrees
//below can be made as FUN Call//
float l_Temperature;
Sourrounding_Temp_Arround_CNC = (float)GetSourroundingTempCNC(l_Temperature);

//Part Dimension received//
CNC_ActualPartDimention_in_mm = (float)FUN_CNC_GetPartDimention();

CNC_ActualRunningimervalue = FUN_CNC_GetActualRunningTimer();

//Duration of continuous operation//
//Duration of continuous operation: Reported in minutes. 
//Updated once every 15 minutes. 
//More than 6 hours of continuous operation requires attention.



//Self-test status-code, reported at startup
//Code 0xFF Meaning All ok
//Code 0x00 Meaning No data (examples: no power, no connection to the data-collector)
//Code 0x01 Meaning Controller board in the machine is not ok
//Code 0x02 Meaning Configuration data in the machine is corrupted

FUN_GetStartUpInfo();//RETURNS ON,OFF

CheckPowerSequence();//ON to OFF, Stays @OFF, Stays@ON, OFF to ON

//now only validate Selftest codes//
CNC_SelfTestCode = FUN_CNC_Get_SelfTestCode();


}




