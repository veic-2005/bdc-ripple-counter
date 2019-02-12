


#include "mcc_generated_files/cwg1.h"
#include "mcc_generated_files/cwg2.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/smt1.h"
#include "mcc_generated_files/smt2.h"
#include "mcc_generated_files/tmr6.h"
#include "mcc_generated_files/tmr4.h"
#include "motorcontrol.h"
#include "math.h"
#include "stdlib.h"

bool getCountDone = 0; 
void InitiateDrive03(void);

void DualMotorDrive() 
{
    ReadMotor01PositionFromEEPROM();
    ReadMotor02PositionFromEEPROM();
    ReadInput();
    CheckInputButton();
    CheckForwardButton();
    CheckReverseButton();
    
    if(ForwardBtnPressed)
    {
        MOTOR01_MODE = FORWARD_DIR;
        MOTOR02_MODE = FORWARD_DIR;
        
        ForwardBtnPressed = 0;
        forwardDirection = 1;
    
        if((totalAngleTurned01 >= ENDPOINT) || (totalAngleTurned02 >= ENDPOINT))
        {
            StopMotor1();
            StopMotor2();
        }
        else
        {   
            InitiateDrive03();
        }
    }
    else if(ReverseBtnPressed)
    {
        MOTOR01_MODE = REVERSE_DIR;
        MOTOR02_MODE = REVERSE_DIR;
        
        ReverseBtnPressed = 0;
        reverseDirection = 1;
        
        if((totalAngleTurned01 <= HOME) || (totalAngleTurned02 <= HOME))
        {
           StopMotor1();
           StopMotor2();
        }
        else
        {   
            InitiateDrive03();
        }
    }
    
    SMT1_SetInterruptHandler(SMT1_ISR);
    SMT2_SetInterruptHandler(SMT2_ISR);
    
    if(getCountDone01 && getCountDone02)
    {
        getCountDone = 1;
        
        SMT1_DataAcquisitionDisable();
        SMT1_ManualTimerReset();
        TMR4_Stop();
        
        SMT2_DataAcquisitionDisable();
        SMT2_ManualTimerReset();
        TMR6_Stop();

    }
    if(getCountDone)
    {
        Motor01Position();
        Motor02Position();
    }
}

void InitiateDrive03(void)
{
    SMT1_DataAcquisitionEnable();
    SMT2_DataAcquisitionEnable();
    StartMotor1();
    StartMotor2();
    StartStallTimer4();
    StartStallTimer6();
}
