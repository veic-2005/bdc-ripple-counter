/*
 * Author : A20687
 * Date: 12/04/2018
 * File Name: counting_ripples.c
 * Short Description: This file contains codes for processing  the input and facilitate counting of ripples.
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
#include <stdio.h>
#include "motorcontrol.h"
#include "math.h"
#include "mcc_generated_files/adcc.h"
#include "mcc_generated_files/ccp1.h"
#include "mcc_generated_files/cwg.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/tmr4.h"


#define POLE            3
#define GEAR_RATIO      250
#define RIPPLE_COUNT_PER_ANGLE ((float)(1*GEAR_RATIO* POLE)/180)

#define INITIAL_TIMER_VALUE     0x7FFF       
#define MAXIMUM_TIMER_VALUE     0xFFFF
#define PERIOD_TIMER1_VALUE   (MAXIMUM_TIMER_VALUE - INITIAL_TIMER_VALUE)

void ReadInput() 
{
    angleDesired = 10;
//            (ADCC_GetSingleConversion(getRippleChannel) * 45) >> 7;
//    printf("angleDesired = %d \n\r", angleDesired);
    if((angleDesired <= remainingAngle ) || (remainingAngle == 0))
    {
        expectedRippleCount = angleDesired *  round(RIPPLE_COUNT_PER_ANGLE);
    }
    else if(angleDesired > remainingAngle)
    {
        ExpectedRippleCountRemainingAngle();
    }
    CompareLoadValue();
    inputSet = 1;
}

void ExpectedRippleCountRemainingAngle()
{
    expectedRippleCount = remainingAngle * round(RIPPLE_COUNT_PER_ANGLE);
}

void ExpectedRippleCountToHome()
{
    expectedRippleCount = (totalAngleTurned * round(RIPPLE_COUNT_PER_ANGLE)) + 10;
    dummy = 1;
    
}

void ExpectedRippleCountToEndPoint()
{
    angleDesired = END_POINT - remainingAngle;
    expectedRippleCount = (angleDesired * round(RIPPLE_COUNT_PER_ANGLE)) + 10;
    dummy = 1;
}

void ExpectedRippleCountfromStall()
{
    
}

void CompareLoadValue()
{
    compareLoadValue = ((expectedRippleCount - 10 )>> 1) + INITIAL_TIMER_VALUE + 1;
}

void StartCounting()
{
    GetRippleLED_SetHigh();
    CCP1_SetCompareCount(compareLoadValue);
    TMR1_Reload();
    TMR4_Period8BitSet(PR2_VALUE);
    TMR1_StartTimer();
    StartMotor();
    StartStallTimer();
}
void Compare_ISR() 
{
    BrakingMechanism();
    GetRippleLED_SetLow();
    TMR4_StopTimer();
    TMR1_StopTimer();
    
    getCountDone = 1;
}

void GetAngleTurned()
{
    if(dummy)
    {
        dummy = 0;
        actualRippleCount = ((TMR1_ReadTimer()+ PERIOD_TIMER1_VALUE) << 1);
    }
    else
    {
        actualRippleCount = ((TMR1_ReadTimer()+ PERIOD_TIMER1_VALUE) << 1) + 10;
    }
    angleTurned = (actualRippleCount / round(RIPPLE_COUNT_PER_ANGLE));
    
    printf("actualRippleCount = %d \n\r ", actualRippleCount);
    printf( "AngleTurned = %d \n\r", angleTurned);
}
