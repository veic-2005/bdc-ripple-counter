/* 
 * Author : A20687
 * Date: 02/14/2019
 * File Name: safety_feature.c
 *  Short Description: This source file contains the code for addressing stall condition.
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
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/tmr4.h"
#include "mcc_generated_files/interrupt_manager.h"
#include "mcc_generated_files/pin_manager.h"
#include "rc_headers/motorcontrol.h"
#include "rc_headers/interrupt_handlers.h"
#include "rc_headers/safety_feature.h"
/*
 Section: Function Declaration
 */
void Stall_ISR(void);
void Overcurrent_ISR(void);

void StallDetection_Initialize(void) 
{
    TMR4_SetInterruptHandler(Stall_ISR);
}

void OvercurrentDetection_Initialize(void)
{
    CMP3_SetInterruptHandler(Overcurrent_ISR); 
}


void Stall_ISR(void)
{
    STALL_LED_SetHigh();
    BrakingMechanism();
    BrakingMechanism02();
    TMR4_StopTimer();
    TMR1_StopTimer();
    faultDetected = 1;
}

void Overcurrent_ISR(void)
{
    OVERCURRENT_LED_SetHigh();
    BrakingMechanism();
    BrakingMechanism02();
    TMR4_StopTimer();
    TMR1_StopTimer();
    faultDetected = 1;
}


void ResumeMotor(void)
{
    OVERCURRENT_LED_SetLow();
    STALL_LED_SetLow();
    
    if(motor01)
    {
        if(reverseOrigin)
        {
            ExpectedRippleCountRemainingAngle();
        }

        else
        {
            ExpectedRippleCountToHome();
        }
        angleDesired = 0;
        CompareLoadValue();
        Motor01Reverse_Drive();
    }
    else
    {
        if(reverseOrigin)
        {
            ExpectedRippleCountRemainingAngle02();
        }

        else
        {
            ExpectedRippleCountToHome02();
        }
        angleDesired = 0;
        CompareLoadValue();
        Motor02Reverse_Drive();
    }
}
/**
 End of File
*/