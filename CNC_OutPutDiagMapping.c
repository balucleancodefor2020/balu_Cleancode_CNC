/*
 * CNC_OutPutDiagMapping.c
 *
 *  Created on: Aug 7, 2020
 *      Author: BSR5COB
 * This file is to collect the inputs which 
 * Monitor unit is providing concerning the
 * CNC machine health
 Assumption made: PROC runs in 1 sec cycle
 */


/*AlertMsg g_CNC_OutPutMapping_Temp_Alert; Bit 0 of Diag_Buffer
AlertMsg g_CNC_OutPutMapping_PartDimenPositive_Alert; Bit 1 of Diag_Buffer
AlertMsg g_CNC_OutPutMapping_PartDimenNegative_Alert; Bit 2 of Diag_Buffer
AlertMsg g_CNC_OutPutMapping_Continuous6hr_Alert; Bit 3 of Diag_Buffer
AlertMsg g_CNC_OutPutMapping_SelfTest_NoData_Alert ; Bit 4 of Diag_Buffer
AlertMsg g_CNC_OutPutMapping_SelfTest_BoardNotOk_Alert; Bit 5 of Diag_Buffer
AlertMsg g_CNC_OutPutMapping_SelfTest_CfgCorrupted_Alert Bit 6 of Diag_Buffer
*/



#include <stdio.h>
#include "CNC_MonitorDataCollector.h"
#include "CNC_OutPutMappingElements.h"

//This will get the output Alert message and do the corresponding output mapping//
void CNC_OutPut_DiagMapping()
{

//fill the diagnostic buffer for sending Output 
//input is from mapping global variables
//int CNC_Dig_Buffer_OutPut = 0x00;
//#define DefaultDagBufferValue 0x00
CNC_Dig_Buffer_OutPut = DefaultDagBufferValue;

if(g_CNC_OutPutMapping_PartDimenPositive_Alert)
{
CNC_Dig_Buffer_OutPut = CNC_Dig_Buffer_OutPut || FirstDiagBitPosition;
}

if(g_CNC_OutPutMapping_PartDimenPositive_Alert)
{
CNC_Dig_Buffer_OutPut = CNC_Dig_Buffer_OutPut ||SecondDiagBitPosition;

}

if(g_CNC_OutPutMapping_PartDimenNegative_Alert)
{
CNC_Dig_Buffer_OutPut = CNC_Dig_Buffer_OutPut ||ThirdDiagBitPosition;

}

if(g_CNC_OutPutMapping_Continuous6hr_Alert)
{
CNC_Dig_Buffer_OutPut = CNC_Dig_Buffer_OutPut ||FourthDiagBitPosition;

}

if(g_CNC_OutPutMapping_SelfTest_NoData_Alert)
{
CNC_Dig_Buffer_OutPut = CNC_Dig_Buffer_OutPut ||FifthDiagBitPosition;

}

if(g_CNC_OutPutMapping_SelfTest_BoardNotOk_Alert)
{
CNC_Dig_Buffer_OutPut = CNC_Dig_Buffer_OutPut ||SixthDiagBitPosition;

}

if(g_CNC_OutPutMapping_SelfTest_CfgCorrupted_Alert)
{
CNC_Dig_Buffer_OutPut = CNC_Dig_Buffer_OutPut ||SeventhDiagBitPosition;

}

}