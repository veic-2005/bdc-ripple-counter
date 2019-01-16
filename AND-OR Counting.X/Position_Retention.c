
#include "mcc_generated_files/mcc.h"
#include "Motor_Control.h"

#define endpoint 360
#define home     0

void Position_Retention(){
    
    if (COG1CON0bits.MD == Forward_Dir) {
            
            if ((actualPosition01 <= endpoint) || (actualPosition02 <= endpoint)) {
                actualPosition01 += buffer01;
                actualPosition02 += buffer02;
                
                difference = endpoint-actualPosition01;
                
            } 
            else{
                COG1_AutoShutdownEventSet();
                COG2_AutoShutdownEventSet();
            }
    } else if (COG1CON0bits.MD == Reverse_Dir) {
            if ((actualPosition01 > home) || (actualPosition02 > home)) {
                actualPosition01 -= buffer01;
                actualPosition02 -= buffer02;
 
            }
            else {
                COG1_AutoShutdownEventSet();
                COG2_AutoShutdownEventSet();
            }
        }
    Store();
}

void expRippleCount(){
    if(difference != 0){
    ExpectedRippleCount = (RippleCountPerAngle * difference);
    ExpectedRippleCount02 = ExpectedRippleCount; 
    }
    else if(difference == 0){
    ExpectedRippleCount = (RippleCountPerAngle * DesiredAngle);
    ExpectedRippleCount02 = ExpectedRippleCount;  
    }
}

void Store(){
    uint16_t Buf[ERASE_FLASH_BLOCKSIZE];
    uint16_t write01P01 = actualPosition01;
    uint16_t write01P02 = actualPosition02;
    FLASH_WriteWord(Motor01Addr00, Buf, write01P01);
    FLASH_WriteWord(Motor02Addr00, Buf, write01P02);
    
}
