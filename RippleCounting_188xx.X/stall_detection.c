/*
 * Author : A20687
 * Date: 02/14/2019
 * File Name: stall_detection.c
 * Short Description: This file contains codes for addressing the stall condition.
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
/*
 Section: Include File
 */

#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/smt1.h"
#include "mcc_generated_files/smt2.h"
#include "mcc_generated_files/tmr4.h"
#include "mcc_generated_files/tmr6.h"
#include "motorcontrol.h"

/*
 Section: ISR declaration for stall detection
 */
void StallM1_ISR(void);
void StallM2_ISR(void);

void StallDetection(void)
{
    TMR4_SetInterruptHandler(StallM1_ISR);
    TMR6_SetInterruptHandler(StallM2_ISR);
}


void StallM1_ISR(void)
{
    STALL_LED_SetHigh();
    BrakingMechanism();
    SMT1_DataAcquisitionDisable();
    actualRippleCount01 = SMT1_GetTimerValue();
    SMT1_ManualTimerReset();
    TMR4_StopTimer();
    motor01Stalled = 1;
}

void StallM2_ISR(void)
{
    STALL_LED_SetHigh();
    BrakingMechanism02();
    SMT2_DataAcquisitionDisable();
    actualRippleCount02 = SMT2_GetTimerValue();
    SMT2_ManualTimerReset();
    TMR4_StopTimer();
    motor02Stalled = 1;
}

void ResumeMotor01(void)
{
    MOTOR01_MODE = REVERSE_DIR;
    STALL_LED_SetLow();
    
    if(reverseOrigin)
    {
        ExpectedRippleCountRemainingAngle();
    }

    else
    {
        ExpectedRippleCountToHome();
    }

    InitiateDrive01();
}

void ResumeMotor02(void)
{
    MOTOR02_MODE = REVERSE_DIR;
    STALL_LED_SetLow();
    
    if(reverseOrigin)
    {
        ExpectedRippleCountRemainingAngle02();
    }

    else
    {
        ExpectedRippleCountToHome02();
    }

    InitiateDrive02();
}
/**
 End of File
*/