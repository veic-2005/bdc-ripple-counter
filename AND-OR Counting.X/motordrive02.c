

#include "mcc_generated_files/mcc.h"
#include "math.h"
#include "motorcontrol.h"

#define MOTOR02_MODE    COG2CON0bits.MD
//#define STEER           0x00

#define MOTOR02_POLE     3
#define GEAR_RATIO_02    250
#define M2_RIPPLE_COUNT_PER_ANGLE ((float)(1*GEAR_RATIO_02* MOTOR02_POLE)/180)

void MotorDrive02() 
{
    if((angleDesired <= remainingAngle02 ) || (remainingAngle02 == 0))
    {
        expectedRippleCount = angleDesired * round(M2_RIPPLE_COUNT_PER_ANGLE);
    }
    else if(angleDesired > remainingAngle02)
    {
        expectedRippleCount = remainingAngle02 *  round(M2_RIPPLE_COUNT_PER_ANGLE);
    }
    CompareLoadValue();

    CheckForwardButton02();
    CheckReverseButton02();
}

void Motor02Forward_Dir()
{   
    MOTOR02_MODE = FORWARD_DIR;
    forwardDirection = 1;

    if(totalAngleTurned02 >= ENDPOINT)
    {
        StopMotor2();
    }
    else
    {   
        LoadValues();
        TMR1_StartTimer();
        StartMotor2();
        StartStallTimer();
    }
}

void Motor02Reverse_Dir()
{
    MOTOR02_MODE = REVERSE_DIR;
    reverseDirection = 1;

    if(totalAngleTurned02 <= HOME)
    {
        StopMotor2();
    }
    else
    {   
        LoadValues();
        TMR1_StartTimer();
        StartMotor2();
        StartStallTimer();
    }
}

void Motor02Position()
{
    angleTurned02 = (actualRippleCount / round(M2_RIPPLE_COUNT_PER_ANGLE));
    
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

void BrakingMechanism02() 
{
    MOTOR02_MODE = STEER;
    COG2STR = 0xA0;     //CWGB and CWGD fully on (0xA0)
}