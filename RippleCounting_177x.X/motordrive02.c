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
#include "rc_headers/lcd.h"
#include "rc_headers/motorcontrol.h"
#include "rc_headers/motorposition.h"
#include "stdlib.h"
#include "math.h"

/**
 * Section: Macro Declaration
 */
#define MOTOR02_MODE        COG3CON0bits.MD
#define MOTOR02_POLE            3
#define GEAR_RATIO_02           250

/*
 Section: Function Declaration
 */
void Motor2AngleSetting(void);
/*
 Section: Variable Declaration
 */
float m2RippleCountPerAngle = (float)((float)(MOTOR02_POLE * GEAR_RATIO_02)/180);

void Motor2AngleSetting(void) 
{
    if((angleDesired <= remainingAngle02 ) || (remainingAngle02 == 0))
    {
        expectedRippleCount = angleDesired * round(m2RippleCountPerAngle);
    }
    else if(angleDesired > remainingAngle02)
    {
        ExpectedRippleCountRemainingAngle02();
    }
    CompareLoadValue();
}

void ExpectedRippleCountRemainingAngle02(void)
{
    expectedRippleCount = remainingAngle02 * round(m2RippleCountPerAngle);
}

void  ExpectedRippleCountToHome02(void)
{
    expectedRippleCount = totalAngleTurned02 * round(m2RippleCountPerAngle);
}

void Motor02Forward_Drive(void)
{   
    MOTOR02_MODE = FORWARD_DIR;
    forwardDirection = 1;
    motor01 = 0;
    
    if((totalAngleTurned02 >= ENDPOINT) || (angleDesired %5 != 0))
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
    
    if((totalAngleTurned02 <= HOME) || (angleDesired %5 != 0))
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
    angleTurned02 = (abs(actualRippleCount) / round(m2RippleCountPerAngle));
    
    printf("actualRippleCount = %d \n\r ", actualRippleCount);
    printf( "AngleTurned02 = %d \n\r", angleTurned02);
    
    LCD_GoTo(0,8);
    LCD_WriteByte("AT=   ");
    LCD_GoTo(0,11);
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
    COG3STR = 0xA0;
}
/**
 End of File
*/