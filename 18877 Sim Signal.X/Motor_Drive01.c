

#include "mcc_generated_files/mcc.h"
#include "Motor_Control.h"

void Direction01_ISR();

void Motor_Drive01() {
    if (labState == NOT_RUNNING) {
        getPOTValue = ADCC_GetSingleConversion(POT);
        DesiredAngle = (float) ((getPOTValue * 45) / 128);

        ExpectedRippleCount01 = (RippleCountPerAngle * DesiredAngle);

        printf("Desired Angle = %d", DesiredAngle);
        printf("\t\t Expected RippleNumber01 = %d \n\r", ExpectedRippleCount01);

    }

    

    if (labState == RUNNING) {
        rotateDirection = Forward;
        IOCBF0_SetInterruptHandler(Direction01_ISR);
        if (Switch_Trigger == 1) {
            StartMotor1();
            LED_D6_Toggle();
            TMR4_StartTimer();
            SMT1_DataAcquisitionEnable();

            while (actualRippleCount01 < ExpectedRippleCount01) {
                actualRippleCount01 = SMT1_GetTimerValue();
            }

            StopMotor1();
            LED_D6_Toggle();
            SMT1_Resets();
            printf("actual RippleCount01 = %d \n\r", actualRippleCount01);

            buffer01 = (float) ((float) actualRippleCount01 / RippleCountPerAngle);
            Position_Retention();

            Switch_Trigger = 0;
        }
    }
    if(switchEvent){
        labState = NOT_RUNNING;
    }
}

void Direction01_ISR() {
    rotateDirection ^= 1;
    if (rotateDirection == Forward) {
        CWG1CON0bits.MODE = Forward_Dir;
    } else if (rotateDirection == Reverse) {
        CWG1CON0bits.MODE = Reverse_Dir;
    }
    Switch_Trigger = 1;
}

void SMT1_Resets() {
    SMT1_ManualTimerReset();
    SMT1_DataAcquisitionDisable();
}