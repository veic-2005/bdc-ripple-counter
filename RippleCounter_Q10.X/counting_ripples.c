/*
 * Author : A20687
 * Date: 02/14/2019
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

/**
  Section: Included Files
 */
#include "mcc_generated_files/adcc.h"
#include "mcc_generated_files/ccp1.h"
#include "mcc_generated_files/cwg.h"
#include "mcc_generated_files/eusart1.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/tmr4.h"
#include "motorcontrol.h"
#include "math.h"

/**
 Section: Motor Specifications Definition
 */ 
#define POLE            3
#define GEAR_RATIO      256

/**
 * Section: Macro Declaration
 */
#define INITIAL_TIMER_VALUE     0x7FFF       
#define MAXIMUM_TIMER_VALUE     0xFFFF
#define PERIOD_TIMER1_VALUE   (MAXIMUM_TIMER_VALUE - INITIAL_TIMER_VALUE)

#define COMPENSATOR_VALUE   0x08
#define CALIBRATION_VALUE   0x06
#define PR4_VALUE           0xA2

/*
 Section: Variable Declaration
 */
float actualRippleCount;
uint16_t compareLoadValue = 0;
uint16_t expectedRippleCount = 0;
float rippleCountPerAngle = (float)((float)(POLE * GEAR_RATIO)/180);

void ReadInput(void) 
{
    angleDesired = (((ADCC_GetSingleConversion(getRippleChannel) + 1) * 45) >> 8);
    (angleDesired % 5 != 0)? printf("") :  
    printf("angleDesired = %d", angleDesired);  
        
    if((angleDesired <= remainingAngle ) || (remainingAngle == 0))
    {
        expectedRippleCount = (angleDesired *  rippleCountPerAngle);
    }
    else if(angleDesired > remainingAngle)
    {
        ExpectedRippleCountRemainingAngle();
    }
    printf("\t Expected Ripple Count = %d \r\n ", expectedRippleCount);
    CompareLoadValue();
    inputSet = 1;
}

void ExpectedRippleCountRemainingAngle(void)
{
    expectedRippleCount = remainingAngle * rippleCountPerAngle;
}

void ExpectedRippleCountToHome(void)
{
    expectedRippleCount = (totalAngleTurned * rippleCountPerAngle) + CALIBRATION_VALUE + COMPENSATOR_VALUE;
    dummy = 1;
    
}

void ExpectedRippleCountToEndPoint(void)
{
    angleDesired = END_POINT - remainingAngle;
    expectedRippleCount = (angleDesired * rippleCountPerAngle) + CALIBRATION_VALUE + COMPENSATOR_VALUE;
    dummy = 1;
}

void CompareLoadValue(void)
{
    compareLoadValue = ((expectedRippleCount - CALIBRATION_VALUE) >> 1) + INITIAL_TIMER_VALUE + 1;
}

void StartCounting(void)
{
    GetRippleLED_SetHigh();
    CCP1_SetCompareCount(compareLoadValue);
    TMR1_Reload();
    TMR4_Period8BitSet(PR4_VALUE);
    TMR1_StartTimer();
    StartMotor();
    StartStallTimer();
}
void Compare_ISR(void) 
{
    BrakingMechanism();
    GetRippleLED_SetLow();
    TMR4_StopTimer();
    TMR1_StopTimer();
    
    getCountDone = 1;
}

void Compare_Initialize(void)
{
    CCP1_CompareSetInterruptHandler(Compare_ISR);
}

void CCP1_CompareISR(void)
{
    PIR6bits.CCP1IF = 0;
        if(CCP1_CompareInterruptHandler)
    {
        CCP1_CompareInterruptHandler();
    }
}

void CCP1_CompareSetInterruptHandler(void (* CompareInterruptHandler)(void))
{
    CCP1_CompareInterruptHandler = CompareInterruptHandler;
}

void GetAngleTurned(void)
{    
    if(dummy)
    {
        dummy = 0;
        actualRippleCount = ((TMR1_ReadTimer()+ PERIOD_TIMER1_VALUE) << 1) - COMPENSATOR_VALUE - CALIBRATION_VALUE;
    }
    else
    {
        actualRippleCount = ((TMR1_ReadTimer()+ PERIOD_TIMER1_VALUE) << 1) + CALIBRATION_VALUE + 1;
    }
    angleTurned = (abs(actualRippleCount)/ rippleCountPerAngle);
    
    printf("actual Ripple Count = %d", actualRippleCount);
    printf("\t AngleTurned = %d \n\r", angleTurned);
}
/**
 End of File
*/