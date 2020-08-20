/*
 * CNC_OutPutMapping.c
 *
 *  Created on: Aug 7, 2020
 *      Author: BSR5COB
 * This file is to collect the inputs which 
 * Monitor unit is providing concerning the
 * CNC machine health
 Assumption made: PROC runs in 1 sec cycle
 */


#define DefaultDagBufferValue 0x00//(1 byte of information with bit position of above Diag messages)
#define FirstDiagBitPosition  0x01
#define SecondDiagBitPosition  0x02
#define ThirdDiagBitPosition  0x04
#define FourthDiagBitPosition  0x08
#define FifthDiagBitPosition  0x10
#define SixthDiagBitPosition  0x20
#define SeventhDiagBitPosition  0x40
/****************************************************************************/
/*CNC Outputs Diag nostic message groups                             */
/****************************************************************************/
enum
{
  C_CNC_Text_None_N   = 0,
  C_CNC_Text_Temp_N = 1,
  C_CNC_Text_PartDimension = 2,
  C_CNC_Text_Continuous_Operation = 3,
  C_CNC_Text_SelfTest  = 4  
} CNC_AlertGroupText_N;

enum
{
C_Not_Active = 0,
C_Active = 1
}AlertMsg;

//use the global variable interfaces from Alerting//
int g_CNC_OutPutMapping_Temp_Alert;
int g_CNC_OutPutMapping_PartDimenPositive_Alert;
int g_CNC_OutPutMapping_PartDimenNegative_Alert;
int g_CNC_OutPutMapping_Continuous6hr_Alert;
int g_CNC_OutPutMapping_SelfTest_NoData_Alert ;
int g_CNC_OutPutMapping_SelfTest_BoardNotOk_Alert;
int g_CNC_OutPutMapping_SelfTest_CfgCorrupted_Alert ;

int CNC_Dig_Buffer_OutPut;
int CNC_MonitorOutPut_Display_Text;
int Array[2];









