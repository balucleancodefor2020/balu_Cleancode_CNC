/*
 * CNC_MonitorDataCollector.h
 *
 *  Created on: Aug 7, 2020
 *      Author: BSR5COB
 * This file is to collect the inputs which 
 * Monitor unit is providing concerning the
 * CNC machine health
 Assumption made: PROC runs in 1 sec cycle
 */

//#include "CNC_OutPutMappingElements.h"

#define halfhourresetthreshold 0x708
#define Reset_Value 0x0
#define CNC_Value_Zero 0
float Part_Dimen_Variation_in_mm ;


float half_hour_restart_Counter;
float Sourrounding_Temp_Arround_CNC;

#define Temp_AlertValue_35DegreeCe 35


//******************************************************************//
float CNC_ActualPartDimention_in_mm;
//Part-dimension variation satrts here//
#define CNC_Ref_PartDimenin_micrometer  10000 
#define PartDime_Negative_Tolerancein_micrometer 9950
#define PartDime_Positive_Tolerancein_micrometer 10050

enum 
{CNC_PartDime_positive_type = 2,
 CNC_PartDime_negative_type = 1,
 CNC_PartDime_no_tolerance_type = 0
}CNC_PartDime_Tolerance_Type;



//***Part Dimen Alert Ends Here***//
double CNC_Continuous15Min_Duration;
double CNC_Timer_UpConterinEvery15minutes;
double CNC_ActualRunningimervalue;
#define CNC_ContinuousTimerThreshold 0x5460
#define CNC_15MinutesTimerReference 0x384

enum SelfTestStatus
{
CNC_SelfTest_AllOk = 0,
CNC_Selftest_NoData = 1,
CNC_SelfTest_BoardNotOk = 2,
CNC_SelfTest_CfgCorrupted = 3
}CNC_SelfTestCode;

int CNC_PowerSequnceData;
enum Powersequence
{
CNC_Power_OFF = 0,
CNC_Power_ON = 1,
CNC_Power_ON_to_OFF = 2,
CNC_Power_OFF_to_ON = 3
}CNC_PowerSequence;

float GetSourroundingTempCNC();
void FUN_CNC_MonitorDataColloction();
void FUN_CNC_MonitorDataEvaluation();
void CNC_OutPut_DiagMapping();
void Fun_CNC_MonitoringEventHandler( CNC_MonitorOutPut_Display_Text);
void CNC_Fun_OutPutDriver();