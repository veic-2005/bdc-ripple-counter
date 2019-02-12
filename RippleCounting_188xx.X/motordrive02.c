

#include "mcc_generated_files/cwg2.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/smt2.h"
#include "mcc_generated_files/tmr6.h"
#include "motorcontrol.h"
#include "math.h"
#include "stdlib.h"

void InitiateDrive02(void);

void MotorDrive02() 
{
    ReadMotor02PositionFromEEPROM();
    ReadInput();
    
    if((angleDesired <= remainingAngle02) || (remainingAngle02 == 0))
    {
        expectedRippleCount = angleDesired * round(M2_RIPPLE_COUNT_PER_ANGLE);           
    }
    else if(angleDesired > remainingAngle02)
    {
        ExpectedRippleCountRemainingAngle();
    }
       
    CheckForwardButton();
    CheckReverseButton();
    
    if(ForwardBtnPressed)
    {
        MOTOR02_MODE = FORWARD_DIR;
        ForwardBtnPressed = 0;
        forwardDirection = 1;
    
        if(totalAngleTurned02 >= ENDPOINT)
        {
            StopMotor2();
        }
        else
        {   
            InitiateDrive02();
        }
    }
    else if(ReverseBtnPressed)
    {
        MOTOR02_MODE = REVERSE_DIR;
        ReverseBtnPressed = 0;
        reverseDirection = 1;
        
        if(totalAngleTurned02 <= HOME)
        {
           StopMotor2();
        }
        else
        {   
            InitiateDrive02();
        }
    }
    
    SMT2_SetInterruptHandler(SMT2_ISR);
    
    if(getCountDone02)
    {
        getCountDone02 = 0;
        
        SMT2_DataAcquisitionDisable();
        SMT2_ManualTimerReset();
        TMR6_Stop();
        
        Motor02Position();
    }
}

void ExpectedRippleCountRemainingAngle02(void)
{
    expectedRippleCount = remainingAngle02 *  round(M2_RIPPLE_COUNT_PER_ANGLE);
}

void  ExpectedRippleCountToHome02(void)
{
    expectedRippleCount = (totalAngleTurned02 * round(M2_RIPPLE_COUNT_PER_ANGLE));
}

void InitiateDrive02(void)
{
    SMT2_SetPeriod(expectedRippleCount); 
    TMR6_Period8BitSet(PR6_VALUE);
    SMT2_DataAcquisitionEnable();
    StartMotor2();
    StartStallTimer6();
}

void SMT2_ISR(void)
{
    BrakingMechanism02();
//    SMT2_DataAcquisitionDisable();
    actualRippleCount02 = SMT2_GetTimerValue();
//    SMT2_ManualTimerReset();
//    TMR6_Stop();
    getCountDone02 = 1;
}

void Motor02Position(void)
{
    angleTurned02 = (abs(actualRippleCount02) / round(M2_RIPPLE_COUNT_PER_ANGLE));

    printf("actualRippleCount = %d \n\r ", actualRippleCount02);
    printf( "AngleTurned = %d \n\r", angleTurned02);
    
    if(forwardDirection)
    {
        forwardDirection = 0;
        M2_ForwardPosition(); 
    }

    else if(reverseDirection)
    {
        reverseDirection = 0;
        M2_ReversePosition();
    }
}

void BrakingMechanism02(void) 
{
    MOTOR02_MODE = STEER;
    CWG2STR = 0xA0;     //CWGB and CWGD fully on (0xA0)
}