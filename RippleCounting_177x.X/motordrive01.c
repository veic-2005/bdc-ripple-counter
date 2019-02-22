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
#include "mcc_generated_files/cog1.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/tmr4.h"
#include "rc_headers/lcd.h"
#include "rc_headers/motorcontrol.h"
#include "rc_headers/motorposition.h"
#include "math.h"
#include "stdlib.h"

/**
 * Section: Macro Declaration
 */
#define MOTOR01_MODE    COG1CON0bits.MD
#define MOTOR01_POLE      3
#define GEAR_RATIO_01     250
#define M1_RIPPLE_COUNT_PER_ANGLE (round((float)((GEAR_RATIO_01* MOTOR01_POLE)/180)))

/*
 Section: Function Declaration
 */
void Motor1AngleSetting(void);

void Motor1AngleSetting(void) 
{
    if((angleDesired <= remainingAngle01 ) || (remainingAngle01 == 0))
    {
        expectedRippleCount = angleDesired * M1_RIPPLE_COUNT_PER_ANGLE;           
    }
    else if(angleDesired > remainingAngle01)
    {
        ExpectedRippleCountRemainingAngle();
    }
    CompareLoadValue();
}

void ExpectedRippleCountRemainingAngle(void)
{
    expectedRippleCount = remainingAngle01 *  M1_RIPPLE_COUNT_PER_ANGLE;
}

void  ExpectedRippleCountToHome(void)
{
    expectedRippleCount = totalAngleTurned01 * M1_RIPPLE_COUNT_PER_ANGLE;
}

void Motor01Forward_Drive(void)
{   
    MOTOR01_MODE = FORWARD_DIR;
    
    forwardDirection = 1;
    motor01 = 1;
    
    if((totalAngleTurned01 >= ENDPOINT) || (angleDesired %5 != 0))
    {
        StopMotor1();
    }
    else
    {   
        Motor1AngleSetting();
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
    
    if((totalAngleTurned01 <= HOME) || (angleDesired %5 != 0))
    {
        StopMotor1();
    }
    else
    {   
        Motor1AngleSetting();
        LoadValues();
        TMR1_StartTimer();
        StartMotor1();
        StartStallTimer();
    }
}

void Motor01Position(void)
{
    angleTurned01 = (actualRippleCount / M1_RIPPLE_COUNT_PER_ANGLE);

    printf("actualRippleCount = %d \n\r ", actualRippleCount);
    printf( "AngleTurned = %d \n\r", angleTurned01);
    
    LCD_GoTo(0,8);
    LCD_WriteByte("AT=   ");
    LCD_GoTo(0,11);
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
        M1_ReversePosition();
    }
}

void BrakingMechanism(void) 
{
    MOTOR01_MODE = STEER;
    COG1STR = 0xA0; 
}
/**
 End of File
*/