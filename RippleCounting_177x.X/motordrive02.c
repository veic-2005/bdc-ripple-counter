/*
 * Author : A20687
 * Date: 02/14/2019
 * File Name: motordrive02.c
 * Short Description: This file contains codes for driving motor 2 in forward and reverse direction.
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

/**
  Section: Included Files
 */

#include "mcc_generated_files/cog3.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/tmr4.h"
#include "math.h"
#include "motorcontrol.h"

/**
 * Section: Macro Declaration
 */
#define MOTOR02_MODE        COG3CON0bits.MD
#define MOTOR02_POLE            3
#define GEAR_RATIO_02           250
#define M2_RIPPLE_COUNT_PER_ANGLE (round((1*GEAR_RATIO_02* MOTOR02_POLE)/180))

void Motor2AngleSetting(void);

void Motor2AngleSetting(void) 
{
    if((angleDesired <= remainingAngle02 ) || (remainingAngle02 == 0))
    {
        expectedRippleCount = angleDesired * M2_RIPPLE_COUNT_PER_ANGLE;
    }
    else if(angleDesired > remainingAngle02)
    {
        ExpectedRippleCountRemainingAngle02();
    }
    CompareLoadValue();
}

void ExpectedRippleCountRemainingAngle02(void)
{
    expectedRippleCount = remainingAngle02 * M2_RIPPLE_COUNT_PER_ANGLE;
}

void  ExpectedRippleCountToHome02(void)
{
    expectedRippleCount = totalAngleTurned02 * M2_RIPPLE_COUNT_PER_ANGLE;
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
    angleTurned02 = (actualRippleCount / M2_RIPPLE_COUNT_PER_ANGLE);
    
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
    COG3STR = 0xA0;
}
/**
 End of File
*/