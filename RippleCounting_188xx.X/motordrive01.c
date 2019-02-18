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
#include "mcc_generated_files/cwg1.h"
#include "mcc_generated_files/device_config.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/tmr4.h"
#include "mcc_generated_files/smt1.h"
#include "motorcontrol.h"
#include "motorposition.h"
#include "lcd.h"
#include "stdlib.h"

void MotorDrive01(void) 
{
    ReadMotor01PositionFromEEPROM();
    ReadInput();
    
    LCD_GoTo(0,7);
    LCD_WriteByte("D=   ");
    LCD_GoTo(0,8);
    LCD_WriteByte(angleDesired/100+'0');
    LCD_WriteByte((angleDesired/10)%10+'0');
    LCD_WriteByte((angleDesired/1)% 10+'0');
        
    if((angleDesired <= remainingAngle01 ) || (remainingAngle01 == 0))
    {
        expectedRippleCount = angleDesired * M1_RIPPLE_COUNT_PER_ANGLE;           
    }
    else if(angleDesired > remainingAngle01)
    {
        ExpectedRippleCountRemainingAngle();
    }
       
    CheckForwardButton();
    CheckReverseButton();
    
    if(ForwardBtnPressed)
    {
        MOTOR01_MODE = FORWARD_DIR;
        ForwardBtnPressed = 0;
        forwardDirection = 1;
    
        if((totalAngleTurned01 >= ENDPOINT) || (angleDesired %5 != 0))
        {
            StopMotor1();
        }
        else
        {   
            InitiateDrive01();
        }
    }
    else if(ReverseBtnPressed)
    {
        MOTOR01_MODE = REVERSE_DIR;
        ReverseBtnPressed = 0;
        reverseDirection = 1;
        
        if((totalAngleTurned01 <= HOME)|| (angleDesired %5 != 0))
        {
           StopMotor1();
        }
        else
        {   
            InitiateDrive01();
        }
    }
    
    SMT1_SetInterruptHandler(SMT1_ISR);
    
    if(getCountDone01)
    {
        getCountDone01 = 0;              
        Motor01Position();
    }
    if(motor01Stalled)
    {
        motor01Stalled = 0;
        Motor01Position();
        __delay_ms(5000);
        ResumeMotor01();
    }
}

void ExpectedRippleCountRemainingAngle(void)
{
    expectedRippleCount = remainingAngle01 *  M1_RIPPLE_COUNT_PER_ANGLE;
}

void  ExpectedRippleCountToHome(void)
{
    expectedRippleCount = (totalAngleTurned01 * M1_RIPPLE_COUNT_PER_ANGLE);
}

void InitiateDrive01(void)
{
    SMT1_SetPeriod(expectedRippleCount); 
    TMR4_Period8BitSet(PR4_VALUE);
    SMT1_DataAcquisitionEnable();
    StartMotor1();
    StartStallTimer4();
}

void SMT1_ISR(void)
{
    BrakingMechanism();
    SMT1_DataAcquisitionDisable();
    actualRippleCount01 = SMT1_GetTimerValue();
    SMT1_ManualTimerReset();
    TMR4_Stop();
    getCountDone01 = 1;
}

void Motor01Position(void)
{
    angleTurned01 = (actualRippleCount01 / M1_RIPPLE_COUNT_PER_ANGLE);

    printf("actualRippleCount01 = %d \n\r ", actualRippleCount01);
    printf( "AngleTurned01 = %d \n\r", angleTurned01);
    
    LCD_GoTo(0,11);
    LCD_WriteByte("T=   ");
    LCD_GoTo(0,13);
    LCD_WriteByte(angleTurned01/100+'0');
    LCD_WriteByte((angleTurned01/10)%10+'0');
    LCD_WriteByte((angleTurned01/1)% 10+'0');
    
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
    CWG1STR = 0xA0;     
}
/**
 End of File
*/