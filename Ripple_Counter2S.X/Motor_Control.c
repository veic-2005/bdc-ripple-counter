#include "mcc_generated_files/mcc.h"
#include "function.h"

void Motor_Control() {
    getPOTValue = ADCC_GetSingleConversion(POT);
    DesiredAngle = (float) ((getPOTValue * 45) / 128);
    
    printf("Desired Angle = %d \t\r", DesiredAngle);

    ExpectedRippleCount = (RippleCountPerAngle * DesiredAngle);
 
    printf("\t\t\t Expected RippleNumber = %d \n\r", ExpectedRippleCount);


    IOCAF5_SetInterruptHandler(Forward_IOC);
    IOCBF0_SetInterruptHandler(Reverse_IOC);
    
    if (Switch_Trigger == 1) {
        CWG1CON0bits.CWG1EN = 1;                //On the CWG
        CaptureIndicator_LED_Toggle();
        TMR4_StartTimer();
        SMT1_DataAcquisitionEnable();

        while (actualRippleCount <= ExpectedRippleCount) {
            actualRippleCount = SMT1_GetTimerValue();
        }

        CWG1CON0bits.CWG1EN = 0;
        actualRippleCount = SMT1_GetTimerValue();
        CaptureIndicator_LED_Toggle();
        printf("actual RippleCount = %d \t\r", actualRippleCount);
        Reset_Timers();

        buffer = (float) ((float) actualRippleCount / RippleCountPerAngle);
        Position_Retention();

        Switch_Trigger = 0;
    }
}



void Forward_IOC() {
    CWG1CON0bits.MODE = Forward; //Forward Direction
    Switch_Trigger = 1;
}

void Reverse_IOC() {
    CWG1CON0bits.MODE = Reverse;
    Switch_Trigger = 1;
}

void Reset_Timers() {
    TMR4_StopTimer();
    SMT1_ManualTimerReset();
    SMT1_DataAcquisitionDisable();
}
