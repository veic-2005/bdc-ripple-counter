
#include "mcc_generated_files/mcc.h"
#include "Motor_Control.h"

void Direction03_ISR();
void Forward_ISR();
void Reverse_ISR();

void Motor_Drive03() {
//    if(labState == NOT_RUNNING){ 
    getPOTValue = ADCC_GetSingleConversion(POT);
    DesiredAngle = (float) ((getPOTValue * 45) / 128);

    //    ExpectedRippleCount01 = (RippleCountPerAngle * DesiredAngle);
    //    ExpectedRippleCount02 = ExpectedRippleCount01; 

    expRippleCount();

    printf("Desired Angle = %d", DesiredAngle);
    printf("\t\t Expected RippleNumber01 = %d ", ExpectedRippleCount01);
    printf("\t\t Expected RippleNumber02 = %d \n\r", ExpectedRippleCount02);
//    }

//    if (labState == RUNNING) {
        IOCAF5_SetInterruptHandler(Forward_ISR);
        IOCBF7_SetInterruptHandler(Reverse_ISR);

        //    rotateDirection = Reverse;

        if (Switch_Trigger == 1) {
            StartMotor1();
            StartMotor2();
            LED_D6_Toggle();
            TMR4_StartTimer();
            SMT1_DataAcquisitionEnable();
            SMT2_DataAcquisitionEnable();

            while ((actualRippleCount01 < ExpectedRippleCount01) || (actualRippleCount02 < ExpectedRippleCount02)) {
                actualRippleCount01 = SMT1_GetTimerValue();
                actualRippleCount02 = SMT2_GetTimerValue();
            }

            StopMotor1();
            StopMotor2();
            LED_D6_Toggle();
            SMT1_Resets();
            SMT2_Resets();
            printf("actual RippleCount01 = %d", actualRippleCount01);
            printf("\t\t actual RippleCount02 = %d \n\r", actualRippleCount02);

            buffer01 = (float) ((float) actualRippleCount01 / RippleCountPerAngle);
            buffer02 = (float) ((float) actualRippleCount02 / RippleCountPerAngle);

            Position_Retention();

            Switch_Trigger = 0;
        }
//    }
//    if (switchEvent) {
//        labState = NOT_RUNNING;
//    }
}

//void Direction03_ISR() {
//    rotateDirection ^= 1;
//    if (rotateDirection == Forward) {
//        CWG1CON0bits.MODE = Forward_Dir;
//        CWG2CON0bits.MODE = Forward_Dir;
//    } else if (rotateDirection == Reverse) {
//        CWG1CON0bits.MODE = Reverse_Dir;
//        CWG2CON0bits.MODE = Reverse_Dir;
//    }
//    Switch_Trigger = 1;
//}

void Forward_ISR() {
    CWG1CON0bits.MODE = Forward_Dir;
    CWG2CON0bits.MODE = Forward_Dir;
    Switch_Trigger = 1;
}

void Reverse_ISR() {
    CWG1CON0bits.MODE = Reverse_Dir;
    CWG2CON0bits.MODE = Reverse_Dir;
    Switch_Trigger = 1;
}