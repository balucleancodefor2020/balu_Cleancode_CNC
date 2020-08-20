/*#define Fun_CNC_Set_Temperature() 40
#define Fun_CNC_Set_PartDimension 10000
#define Fun_CNC_Set_SelfTestCode() 0xFF
#define Fun_CNC_Set_OperationalTimer() 100
#define Fun_CNC_Set_PowerSequence() 3
#define Fun_CNC_Set_PowerStatus() ON                              
*/
#include <stdio.h>
#include "CNC_MonitorDataCollector.h"
#include "CNC_OutPutMappingElements.h"
#include "CNC_Monitordata_stub_inputs.h"


void CNC_Test()
{
/*set inputs;*/
Fun_CNC_Set_Temperature();

Fun_CNC_Set_PartDimension();

Fun_CNC_Set_SelfTestCode();

Fun_CNC_Set_OperationalTimer();

Fun_CNC_Set_PowerSequence();

PROC_CNC_Evaluation_Cyclic_1Sec();



}