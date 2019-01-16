

#include "mcc_generated_files/mcc.h"
#include "Motor_Control.h"

void Direction01_ISR();

void Motor_Drive01() {
if (motorState == NOT_RUNNING) {
        getPOTValue = ADC_GetConversion(POT);
        DesiredAngle = (float) ((getPOTValue * 45) / 128);

        expRippleCount();

        printf("Desired Angle = %d", DesiredAngle);
        printf("\t\t Expected RippleNumber01 = %d \n\r", ExpectedRippleCount);
}

    if (motorState == RUNNING) {
        IOCBF0_SetInterruptHandler(Direction01_ISR);

        rotateDirection = Reverse;

        if (Switch_Trigger == 1) {
            StartMotor1();
            D7_Toggle();
            TMR4_StartTimer();
            CLC4CONbits.EN = 1;

            while (actualRippleCount <= ExpectedRippleCount) {
                if (PIR3bits.CLC4IF == 1) {
                    PIR3bits.CLC4IF = 0;
                    actualRippleCount++;
                }
            }

            StopMotor1();
            D7_Toggle();
            printf("actual RippleCount01 = %d \n\r", actualRippleCount);

            buffer01 = (float) ((float) actualRippleCount / RippleCountPerAngle);
            Position_Retention();

            Switch_Trigger = 0;
        }
    }
    if(switchEvent){
        motorState = NOT_RUNNING;
    }
}

void Direction01_ISR() {
    rotateDirection ^= 1;
    if (rotateDirection == Forward) {
        COG1CON0bits.MD = Forward_Dir;
    } else if (rotateDirection == Reverse) {
        COG1CON0bits.MD = Reverse_Dir;
    }
    Switch_Trigger = 1;
}
