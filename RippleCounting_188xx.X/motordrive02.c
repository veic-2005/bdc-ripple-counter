/*
 * Author : A20687
 * Date: 02/14/2019
 * File Name: motordrive01.c
 * Short Description: This file contains codes for driving motor 1 in forward and reverse direction.
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
#include "mcc_generated_files/cwg2.h"
#include "mcc_generated_files/device_config.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/smt2.h"
#include "mcc_generated_files/tmr6.h"
#include "motorcontrol.h"
#include "motorposition.h"
#include "stdlib.h"
#include "lcd.h"

void MotorDrive02(void) 
{
    ReadMotor02PositionFromEEPROM();
    ReadInput();

    LCD_GoTo(1,7);
    LCD_WriteByte("D=   ");
    LCD_GoTo(1,8);
    LCD_WriteByte(angleDesired/100+'0');
    LCD_WriteByte((angleDesired/10)%10+'0');
    LCD_WriteByte((angleDesired/1)% 10+'0');
    
    if((angleDesired <= remainingAngle02) || (remainingAngle02 == 0))
    {
        expectedRippleCount = angleDesired * M2_RIPPLE_COUNT_PER_ANGLE;           
    }
    else if(angleDesired > remainingAngle02)
    {
        ExpectedRippleCountRemainingAngle();
    }
       
    CheckForwardButton();
    CheckReverseButton();
    
    if(ForwardBtnPressed)
    {
        MOTOR02_MODE = FORWARD_DIR;
        ForwardBtnPressed = 0;
        forwardDirection = 1;
    
        if(totalAngleTurned02 >= ENDPOINT)
        {
            StopMotor2();
        }
        else
        {   
            InitiateDrive02();
        }
    }
    else if(ReverseBtnPressed)
    {
        MOTOR02_MODE = REVERSE_DIR;
        ReverseBtnPressed = 0;
        reverseDirection = 1;
        
        if(totalAngleTurned02 <= HOME)
        {
           StopMotor2();
        }
        else
        {   
            InitiateDrive02();
        }
    }
    
    SMT2_SetInterruptHandler(SMT2_ISR);
    
    if(getCountDone02)
    {
        getCountDone02 = 0;
        Motor02Position();
    }
    
    if(motor02Stalled)
    {
        motor02Stalled = 0;
        Motor02Position();
        __delay_ms(5000);
        ResumeMotor02();
    }
}    

void ExpectedRippleCountRemainingAngle02(void)
{
    expectedRippleCount = remainingAngle02 * M2_RIPPLE_COUNT_PER_ANGLE;
}

void  ExpectedRippleCountToHome02(void)
{
    expectedRippleCount = totalAngleTurned02 * M2_RIPPLE_COUNT_PER_ANGLE;
}

void InitiateDrive02(void)
{
    SMT2_SetPeriod(expectedRippleCount); 
    TMR6_Period8BitSet(PR6_VALUE);
    SMT2_DataAcquisitionEnable();
    StartMotor2();
    StartStallTimer6();
}

void SMT2_ISR(void)
{
    BrakingMechanism02();
    SMT2_DataAcquisitionDisable();
    actualRippleCount02 = SMT2_GetTimerValue();
    SMT2_ManualTimerReset();
    TMR6_Stop();
    getCountDone02 = 1;
}

void Motor02Position(void)
{
    angleTurned02 = (abs(actualRippleCount02) / M2_RIPPLE_COUNT_PER_ANGLE);

    printf("actualRippleCount = %d \n\r ", actualRippleCount02);
    printf( "AngleTurned = %d \n\r", angleTurned02);
    
    LCD_GoTo(1,11);
    LCD_WriteByte("T=   ");
    LCD_GoTo(1,13);
    LCD_WriteByte(angleTurned02/100+'0');
    LCD_WriteByte((angleTurned02/10)%10+'0');
    LCD_WriteByte((angleTurned02/1)% 10+'0');
    
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
    CWG2STR = 0xA0;   
}
/**
 End of File
*/