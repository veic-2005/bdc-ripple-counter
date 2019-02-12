

#include "mcc_generated_files/cwg1.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/tmr4.h"
#include "mcc_generated_files/smt1.h"
#include "motorcontrol.h"
#include "math.h"
#include "stdlib.h"


void InitiateDrive(void);

void MotorDrive01() 
{
    ReadMotor01PositionFromEEPROM();
    ReadInput();
    
    if((angleDesired <= remainingAngle01 ) || (remainingAngle01 == 0))
    {
        expectedRippleCount = angleDesired * round(M1_RIPPLE_COUNT_PER_ANGLE);           
    }
    else if(angleDesired > remainingAngle01)
    {
        ExpectedRippleCountRemainingAngle();
    }
       
    CheckForwardButton();
    CheckReverseButton();
    
    if(ForwardBtnPressed)
    {
        MOTOR01_MODE = FORWARD_DIR;
        ForwardBtnPressed = 0;
        forwardDirection = 1;
    
        if(totalAngleTurned01 >= ENDPOINT)
        {
            StopMotor1();
        }
        else
        {   
            InitiateDrive();
        }
    }
    else if(ReverseBtnPressed)
    {
        MOTOR01_MODE = REVERSE_DIR;
        ReverseBtnPressed = 0;
        reverseDirection = 1;
        
        if(totalAngleTurned01 <= HOME)
        {
           StopMotor1();
        }
        else
        {   
            InitiateDrive();
        }
    }
    
    SMT1_SetInterruptHandler(SMT1_ISR);
    
    if(getCountDone01)
    {
        getCountDone01 = 0;
        
        SMT1_DataAcquisitionDisable();
        SMT1_ManualTimerReset();
        TMR4_Stop();
                
        Motor01Position();
    }
}

void ExpectedRippleCountRemainingAngle(void)
{
    expectedRippleCount = remainingAngle01 *  round(M1_RIPPLE_COUNT_PER_ANGLE);
}

void  ExpectedRippleCountToHome(void)
{
    expectedRippleCount = (totalAngleTurned01 * round(M1_RIPPLE_COUNT_PER_ANGLE));
}

void InitiateDrive(void)
{
    SMT1_SetPeriod(expectedRippleCount); 
    TMR4_Period8BitSet(PR4_VALUE);
    SMT1_DataAcquisitionEnable();
    StartMotor1();
    StartStallTimer4();
}

void SMT1_ISR(void)
{
    BrakingMechanism();
//    SMT1_DataAcquisitionDisable();
    actualRippleCount01 = SMT1_GetTimerValue();
//    SMT1_ManualTimerReset();
//    TMR4_Stop();
    getCountDone01 = 1;
}

void Motor01Position(void)
{
    angleTurned01 = (actualRippleCount01 / round(M1_RIPPLE_COUNT_PER_ANGLE));

    printf("actualRippleCount01 = %d \n\r ", actualRippleCount01);
    printf( "AngleTurned01 = %d \n\r", angleTurned01);
    
    if(forwardDirection)
    {
        forwardDirection = 0;
        M1_ForwardPosition(); 
    }

    else if(reverseDirection)
    {
        reverseDirection = 0;
        M2_ReversePosition();
    }
}

void BrakingMechanism(void) 
{
    MOTOR01_MODE = STEER;
    CWG1STR = 0xA0;     //CWGB and CWGD fully on (0xA0)
}