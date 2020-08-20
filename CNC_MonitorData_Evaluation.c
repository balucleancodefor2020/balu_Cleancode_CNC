/*
 * CNC_MonitorData_Evaluation.c
 *
 *  Created on: Aug 7, 2020
 *      Author: BSR5COB
 *Assumption made: PROC runs in 1 sec cycle
 */

//***mainly function calls to get the input data****
//****//
//Operating temperature: Temperature around the CNC machine in Celsius. 
//Reported every half-hour. Need to alert if it goes beyond 35 degrees.

//#include "CNC_MonitorDataCollector.h"

#include <stdio.h>
#include "CNC_MonitorDataCollector.h"
#include "CNC_OutPutMappingElements.h"

void FUN_CNC_MonitorDataEvaluation()
{
g_CNC_OutPutMapping_Temp_Alert = 0;
g_CNC_OutPutMapping_PartDimenPositive_Alert = 0;
g_CNC_OutPutMapping_PartDimenNegative_Alert = 0;
g_CNC_OutPutMapping_Continuous6hr_Alert = 0;
g_CNC_OutPutMapping_SelfTest_NoData_Alert = 0 ;
g_CNC_OutPutMapping_SelfTest_BoardNotOk_Alert = 0;
g_CNC_OutPutMapping_SelfTest_CfgCorrupted_Alert = 0;
//Operating temperature: Temperature around the CNC machine in Celsius. 
//Reported every half-hour. 
//Need to alert if it goes beyond 35 degrees
//below can be made as FUN Call//
//Used Global Variables and need to Rest during start up.//


//***Temp Alert Starts Here***//
if(halfhourresetthreshold >=half_hour_restart_Counter )
{
  half_hour_restart_Counter++;
}
else 
{
	if(Sourrounding_Temp_Arround_CNC > Temp_AlertValue_35DegreeCe)
	{
	 //Aleret with diagnostic code;//
	 g_CNC_OutPutMapping_Temp_Alert = C_Active;
	}

half_hour_restart_Counter = Reset_Value;

}

//***Temp Alert Ends Here***//



//******************************************************************//
//Part-dimension variation satrts here//
//float Part_Dimen_Variation_in_mm ;

Part_Dimen_Variation_in_mm =  CNC_ActualPartDimention_in_mm - CNC_Ref_PartDimenin_micrometer;


if (Part_Dimen_Variation_in_mm > 0)
{

 if ((CNC_ActualPartDimention_in_mm - PartDime_Positive_Tolerancein_micrometer) > CNC_Value_Zero)
 {
 //PartDimension_Alertisrequiredforpositevalue
	 g_CNC_OutPutMapping_PartDimenPositive_Alert = C_Active;
 }
 else 
 {
   //noactionrequired;
 }
//positive tolerance
}

else if (Part_Dimen_Variation_in_mm < 0)
{
//negative tolerance

	if ((PartDime_Negative_Tolerancein_micrometer -CNC_ActualPartDimention_in_mm) < CNC_Value_Zero)
	{
	//PartDimension_Alertisrequiredfornegaitevalue
		g_CNC_OutPutMapping_PartDimenNegative_Alert = C_Active;
	}
	else
	{
	//no action required
	}

}
else 
{
	//no action required
}


//***Part Dimen Alert Ends Here***//



//Duration of continuous operation//
//Duration of continuous operation: Reported in minutes. 
//Updated once every 15 minutes. 
//More than 6 hours of continuous operation requires attention.

//***Continuous Hr monitor starts here***//
CNC_Continuous15Min_Duration++;
if(CNC_15MinutesTimerReference<=CNC_Continuous15Min_Duration)
{
	CNC_Timer_UpConterinEvery15minutes++;
    
    CNC_Continuous15Min_Duration = Reset_Value;

	if (CNC_ContinuousTimerThreshold < CNC_ActualRunningimervalue)
	{
	 //Timingalertrequired;
		g_CNC_OutPutMapping_Continuous6hr_Alert = C_Active;
	}

}
//***Continuous Hr monitor Ends here***//




//***Self TEST Monitor starts here***//

//Self-test status-code, reported at startup
//Code 0xFF Meaning All ok
//Code 0x00 Meaning No data (examples: no power, no connection to the data-collector)
//Code 0x01 Meaning Controller board in the machine is not ok
//Code 0x02 Meaning Configuration data in the machine is corrupted





if(CNC_PowerSequnceData == CNC_Power_OFF_to_ON )
{
//now only validate Selftest codes//


	switch (CNC_SelfTestCode)
	{
	case CNC_SelfTest_AllOk:
	{
	//fill diagnostic data and no warning required;
	g_CNC_OutPutMapping_SelfTest_NoData_Alert = C_Not_Active;
	g_CNC_OutPutMapping_SelfTest_BoardNotOk_Alert = C_Not_Active;
	g_CNC_OutPutMapping_SelfTest_CfgCorrupted_Alert = C_Not_Active;
	break;
	}

	case CNC_Selftest_NoData:
	{
	// alert and fill diagnostic data
	g_CNC_OutPutMapping_SelfTest_NoData_Alert = C_Active;
	break;
	}
	case CNC_SelfTest_BoardNotOk:
	{
	 //alert and fill diagnostic data;
	g_CNC_OutPutMapping_SelfTest_BoardNotOk_Alert = C_Active;
	break;
	}
	case CNC_SelfTest_CfgCorrupted:
	{
	// alert and fill diagnostic data;
	g_CNC_OutPutMapping_SelfTest_CfgCorrupted_Alert = C_Active;
	break;
	}
	}
}
 	 
//***Self TEST Monitor starts here***//

}




