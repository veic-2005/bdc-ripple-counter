

#include "mcc_generated_files/mcc.h"
#include "motorcontrol.h"
#include "math.h"
#include "stdlib.h"

#define MOTOR01_MODE   COG1CON0bits.MD
#define STEER          0x00;

#define MOTOR01_POLE     3
#define GEAR_RATIO_01    250
#define M1_RIPPLE_COUNT_PER_ANGLE ((float)(1*GEAR_RATIO_01* MOTOR01_POLE)/180)

void MotorDrive01() 
{
    if((angleDesired <= remainingAngle01 ) || (remainingAngle01 == 0))
    {
        expectedRippleCount = angleDesired * round(M1_RIPPLE_COUNT_PER_ANGLE);
    }
    else if(angleDesired > remainingAngle01)
    {
        expectedRippleCount = remainingAngle01 *  round(M1_RIPPLE_COUNT_PER_ANGLE);
    }
    CompareLoadValue();

    CheckForwardButton();
    CheckReverseButton();  

}

void Motor01Forward_Dir()
{   
    MOTOR01_MODE = FORWARD_DIR;
    forwardDirection = 1;

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

void Motor01Reverse_Dir()
{
    MOTOR01_MODE = REVERSE_DIR;
    reverseDirection = 1;

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

void Motor01Position()
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

void BrakingMechanism() 
{
    MOTOR01_MODE = STEER;
    COG1STR = 0xA0;     //CWGB and CWGD fully on (0xA0)
}