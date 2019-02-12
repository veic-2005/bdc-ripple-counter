


#include "mcc_generated_files/cog3.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/tmr4.h"
#include "math.h"
#include "motorcontrol.h"

#define MOTOR02_MODE    COG3CON0bits.MD

#define MOTOR02_POLE     3
#define GEAR_RATIO_02    250
#define M2_RIPPLE_COUNT_PER_ANGLE ((float)(1*GEAR_RATIO_02* MOTOR02_POLE)/180)

void Motor2AngleSetting();

void Motor2AngleSetting() 
{
    if((angleDesired <= remainingAngle02 ) || (remainingAngle02 == 0))
    {
        expectedRippleCount = angleDesired * round(M2_RIPPLE_COUNT_PER_ANGLE);
    }
    else if(angleDesired > remainingAngle02)
    {
        ExpectedRippleCountRemainingAngle02();
    }
    CompareLoadValue();
}

void ExpectedRippleCountRemainingAngle02()
{
    expectedRippleCount = remainingAngle02 * round(M2_RIPPLE_COUNT_PER_ANGLE);
}

void  ExpectedRippleCountToHome02(void)
{
    expectedRippleCount = (totalAngleTurned02 * round(M2_RIPPLE_COUNT_PER_ANGLE));
}

void Motor02Forward_Drive(void)
{   
    MOTOR02_MODE = FORWARD_DIR;
    forwardDirection = 1;
    motor01 = 0;
    
    if(totalAngleTurned02 >= ENDPOINT)
    {
        StopMotor2();
    }
    else
    {   Motor2AngleSetting();
        LoadValues();
        TMR1_StartTimer();
        StartMotor2();
        StartStallTimer();
    }
}
                
void Motor02Reverse_Drive(void)
{
    MOTOR02_MODE = REVERSE_DIR;
    
    reverseDirection = 1;
    motor01 = 0;
    
    if(totalAngleTurned02 <= HOME)
    {
        StopMotor2();
    }
    else
    {   
        Motor2AngleSetting();
        LoadValues();
        TMR1_StartTimer();
        StartMotor2();
        StartStallTimer();
    }
}

void Motor02Position(void)
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

void BrakingMechanism02(void) 
{
    MOTOR02_MODE = STEER;
    COG3STR = 0xA0;     //CWGB and CWGD fully on (0xA0)
}