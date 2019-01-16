#include "mcc_generated_files/mcc.h"
#include "Motor_Control.h"

uint16_t readMotor01;
uint16_t readMotor02; 

void OverCurrent_Detection01(){
    readMotor01 = ADCC_GetSingleConversion(Motor01_OCchannel);
    if(readMotor01 > 2){
    CWG1_AutoShutdownEventSet(); 
    OverCurrentIndicator_LED_SetHigh();
    }
}
void OverCurrent_Detection02(){
    readMotor02 = ADCC_GetSingleConversion(Motor02_OCchannel);
    if(readMotor02 > 2){
    CWG2_AutoShutdownEventSet(); 
    OverCurrentIndicator_LED_SetHigh();
    }
}
