
#include "mcc_generated_files/mcc.h"
#include "Motor_Control.h"

#define endpoint 360
#define home     0

void Position_Retention(){
    
    if (CWG1CON0bits.MODE == Forward_Dir) {
            
            if ((actualPosition01 <= endpoint) || (actualPosition02 <= endpoint)) {
                actualPosition01 += buffer01;
                actualPosition02 += buffer02;
                
                difference = endpoint-actualPosition01;
                
            } 
            else{
                CWG1_AutoShutdownEventSet();
                CWG2_AutoShutdownEventSet();
            }
    } else if (CWG1CON0bits.MODE == Reverse_Dir) {
            if ((actualPosition01 > home) || (actualPosition02 > home)) {
                actualPosition01 -= buffer01;
                actualPosition02 -= buffer02;
 
            }
            else {
                CWG1_AutoShutdownEventSet();
                CWG2_AutoShutdownEventSet();
            }
        }    
}

void expRippleCount(){
    if(difference != 0){
    ExpectedRippleCount01 = (RippleCountPerAngle * difference);
    ExpectedRippleCount02 = ExpectedRippleCount01; 
    }
    else if(difference == 0){
    ExpectedRippleCount01 = (RippleCountPerAngle * DesiredAngle);
    ExpectedRippleCount02 = ExpectedRippleCount01;  
    }
}

void Store(){
    uint8_t write01P01 = actualPosition01;
    uint8_t write02P01 = actualPosition01 >> 8;
    uint8_t write01P02 = actualPosition02;
    uint8_t write02P02 = actualPosition02 >> 8;
    DATAEE_WriteByte(Motor01Addr00,write01P01);       
    DATAEE_WriteByte(Motor01Addr01, write02P01);
    DATAEE_WriteByte(Motor02Addr00,write01P02);       
    DATAEE_WriteByte(Motor02Addr01, write02P02);
}
