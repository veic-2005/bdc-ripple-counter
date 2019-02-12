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

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/tmr4.h"
#include "mcc_generated_files/cmp3.h"
#include "mcc_generated_files/cog1.h"
#include "mcc_generated_files/cog3.h"

#include "motorcontrol.h"

void Stall_ISR();
void Overcurrent_ISR();

void StallDetection() 
{
    TMR4_SetInterruptHandler(Stall_ISR);
}

void OvercurrentDetection(void)
{
    CMP3_SetInterruptHandler(Overcurrent_ISR); 
}


void Stall_ISR()
{
    STALL_LED_SetHigh();
    BrakingMechanism();
    BrakingMechanism02();
    TMR4_StopTimer();
    TMR1_StopTimer();
    faultDetected = 1;
}

void Overcurrent_ISR()
{
    OVERCURRENT_LED_SetHigh();
    BrakingMechanism();
    BrakingMechanism02();
    TMR1_StopTimer();
    faultDetected = 1;
}


void ResumeMotor()
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
        CompareLoadValue();
        Motor02Reverse_Drive();
    }
}