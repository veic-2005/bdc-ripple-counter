
#include "mcc_generated_files/mcc.h"
#include "Motor_Control.h"

void OverCurrent_Detection(){
    COG1_AutoShutdownEventSet();
    COG2_AutoShutdownEventSet();
    Store();
    OverCurrentIndicator_LED_SetHigh();
    }