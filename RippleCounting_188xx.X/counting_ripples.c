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

/**
  Section: Included Files
 */
#include "mcc_generated_files/adcc.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/smt1.h"
#include "mcc_generated_files/smt2.h"
#include "mcc_generated_files/tmr4.h"
#include "mcc_generated_files/tmr6.h"
#include "motorcontrol.h"
#include "motorposition.h"
#include "lcd.h"

/*
 Section: Variable Declaration
*/
bool motorSelected = 0;

void ReadInput(void) 
{
    angleDesired =  (((ADCC_GetSingleConversion(POT) + 1) * 45) >> 8);
    (angleDesired % 5 != 0)? printf("") :  
    printf("angleDesired = %d \t\r\n", angleDesired); 
}

void MotorInput(void)
{
    motorSelected = ~motorSelected;
    
    if(motorSelected)
    {
        if((angleDesired <= remainingAngle01 ) || (remainingAngle01 == 0))
        {
            expectedRippleCount = angleDesired * m1RippleCountPerAngle;           
        }
        else if(angleDesired > remainingAngle01)
        {
            ExpectedRippleCountRemainingAngle();
        }
        
        SMT1_SetPeriod(expectedRippleCount); 
        TMR4_Period8BitSet(PR4_VALUE);
        
        LCD_GoTo(0,7);
        LCD_WriteByte("D=   ");
        LCD_GoTo(0,8);
        LCD_WriteByte(angleDesired/100+'0');
        LCD_WriteByte((angleDesired/10)%10+'0');
        LCD_WriteByte((angleDesired/1)% 10+'0');
    }
    else
    {
        if((angleDesired <= remainingAngle02) || (remainingAngle02 == 0))
        {
            expectedRippleCount = angleDesired * m2RippleCountPerAngle;           
        }
        else if(angleDesired > remainingAngle02)
        {
            ExpectedRippleCountRemainingAngle();
        }
        SMT2_SetPeriod(expectedRippleCount); 
        TMR6_Period8BitSet(PR6_VALUE);
        
        LCD_GoTo(1,7);
        LCD_WriteByte("D=   ");
        LCD_GoTo(1,8);
        LCD_WriteByte(angleDesired/100+'0');
        LCD_WriteByte((angleDesired/10)%10+'0');
        LCD_WriteByte((angleDesired/1)% 10+'0');
    }
}
/**
 End of File
*/
