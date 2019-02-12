

#include "mcc_generated_files/cog1.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/tmr4.h"
#include "motorcontrol.h"
#include "math.h"
#include "stdlib.h"

#define MOTOR01_POLE     3
#define GEAR_RATIO_01    250
#define M1_RIPPLE_COUNT_PER_ANGLE ((float)(1*GEAR_RATIO_01* MOTOR01_POLE)/180)

void Motor1AngleSetting();

void Motor1AngleSetting() 
{
    if((angleDesired <= remainingAngle01 ) || (remainingAngle01 == 0))
    {
        expectedRippleCount = angleDesired * round(M1_RIPPLE_COUNT_PER_ANGLE);           
    }
    else if(angleDesired > remainingAngle01)
    {
        ExpectedRippleCountRemainingAngle();
    }
    CompareLoadValue();
}

void ExpectedRippleCountRemainingAngle(void)
{
    expectedRippleCount = remainingAngle01 *  round(M1_RIPPLE_COUNT_PER_ANGLE);
}

void  ExpectedRippleCountToHome(void)
{
    expectedRippleCount = (totalAngleTurned01 * round(M1_RIPPLE_COUNT_PER_ANGLE));
}

void Motor01Forward_Drive(void)
{   
    MOTOR01_MODE = FORWARD_DIR;
    
    forwardDirection = 1;
    motor01 = 1;
    
    if(totalAngleTurned01 >= ENDPOINT)
    {
        StopMotor1();
    }
    else
    {           
        LoadValues();
        TMR1_StartTimer();
        StartMotor1();
        StartStallTimer();
    }
}

void Motor01Reverse_Drive(void)
{
    MOTOR01_MODE = REVERSE_DIR;
    
    reverseDirection = 1;
    motor01 = 1;
    
    if(totalAngleTurned01 <= HOME)
    {
        StopMotor1();
    }
    else
    {   
        LoadValues();
        TMR1_StartTimer();
        StartMotor1();
        StartStallTimer();
    }
}

void Motor01Position(void)
{
    angleTurned01 = (actualRippleCount / round(M1_RIPPLE_COUNT_PER_ANGLE));

    printf("actualRippleCount = %d \n\r ", actualRippleCount);
    printf( "AngleTurned = %d \n\r", angleTurned01);
    
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
    COG1STR = 0xA0;     //CWGB and CWGD fully on (0xA0)
}