/*
 * CNC_OutPutDriver.c
 *
 *  Created on: Aug 7, 2020
 *      Author: BSR5COB
 *Assumption made: PROC runs in 1 sec cycle
 */

/*enum
{
  C_CNC_Text_None_N                     = 0,
  C_CNC_Text_Temp_N               = 1,
  C_CNC_Text_PartDimension = 2,
  C_CNC_Text_Continuous_Operation 3,
  C_CNC_Text_SelfTest  4
  
} CNC_AlertGroupText_N;
*/

#include <stdio.h>
#include "CNC_MonitorDataCollector.h"
#include "CNC_OutPutMappingElements.h"

void CNC_Fun_OutPutDriver()
{
/*here at a time one alert is taken care so priority needs to added;*/
//get oupt diag buffer and send with associated display text//

//NetworkInterfaceDisplay CNC_MonitorOutPut_Display_Text;

//NetworkInterfaceDiag CNC_MonitorOutPut_DiagBuffer;

if(g_CNC_OutPutMapping_PartDimenPositive_Alert ||g_CNC_OutPutMapping_PartDimenNegative_Alert)
{
CNC_MonitorOutPut_Display_Text = C_CNC_Text_PartDimension;
}
else if (g_CNC_OutPutMapping_Continuous6hr_Alert)
{
CNC_MonitorOutPut_Display_Text = C_CNC_Text_Continuous_Operation;
}
else if (g_CNC_OutPutMapping_SelfTest_NoData_Alert)

{
CNC_MonitorOutPut_Display_Text = C_CNC_Text_SelfTest;
}

//Array[] = {CNC_MonitorOutPut_Display_Text,CNC_Dig_Buffer_OutPut,g_CNC_LampIndication,g_CNC_AccusticWarning} ;//this can be used for next level , or some send messages.//

}