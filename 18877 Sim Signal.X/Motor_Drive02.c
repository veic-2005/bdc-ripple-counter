
#include "mcc_generated_files/mcc.h"
#include "Motor_Control.h"

void Direction02_ISR();

void Motor_Drive02() {
    if (labState == NOT_RUNNING) {
        getPOTValue = ADCC_GetSingleConversion(POT);
        DesiredAngle = (float) ((getPOTValue * 45) / 128);

        ExpectedRippleCount01 = (RippleCountPerAngle * DesiredAngle);
        ExpectedRippleCount02 = ExpectedRippleCount01;

        printf("Desired Angle = %d", DesiredAngle);
        printf("\t\t Expected RippleNumber02 = %d \n\r", ExpectedRippleCount02);
    }

    if (labState == RUNNING) {
        IOCBF0_SetInterruptHandler(Direction02_ISR);

        rotateDirection = Forward;

        if (Switch_Trigger == 1) {
            StartMotor2();
            LED_D6_Toggle();
            TMR4_StartTimer();
            SMT2_DataAcquisitionEnable();

            while (actualRippleCount02 < ExpectedRippleCount02) {
                actualRippleCount02 = SMT2_GetTimerValue();
            }

            StopMotor2();
            LED_D6_Toggle();
            SMT2_Resets();
            printf("actual RippleCount02 = %d \n\r", actualRippleCount02);

            buffer02 = (float) ((float) actualRippleCount02 / RippleCountPerAngle);
            //        Position_Retention();

            Switch_Trigger = 0;
        }
    }
    if (switchEvent) {
        labState = NOT_RUNNING;
    }
}

void Direction02_ISR() {
    rotateDirection ^= 1;
    if (rotateDirection == Forward) {
        CWG2CON0bits.MODE = Forward_Dir;
    } else if (rotateDirection == Reverse) {
        CWG2CON0bits.MODE = Reverse_Dir;
    }
    Switch_Trigger = 1;
}

void SMT2_Resets() {
    SMT2_ManualTimerReset();
    SMT2_DataAcquisitionDisable();
}
