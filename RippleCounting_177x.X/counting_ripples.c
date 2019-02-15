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
#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/ccp1.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/tmr4.h"
#include "interrupt_handlers.h"
#include "motorcontrol.h"
#include "math.h"
#include <stdlib.h>
#include "lcd.h"

/**
 Section: Macro Declaration
 */
#define INITIAL_TIMER_VALUE     0x7FFF       
#define MAXIMUM_TIMER_VALUE     0xFFFF
#define PERIOD_TIMER1_VALUE    (MAXIMUM_TIMER_VALUE - INITIAL_TIMER_VALUE)
#define PR2_VALUE               0x22
#define CALIBRATION_VALUE       0x8

/**
 Section: Variable Declaration
 */
uint16_t compareLoadValue;

void ReadInput(void) 
{
    angleDesired =  (((ADC_GetConversion(POT) + 1) * 45) >> 8); // for 180 degrees maximum incremental angle shift to the right by 8
    (angleDesired % 5 != 0)? printf("") :  
    printf("angleDesired = %d \t\r\n", angleDesired);  
    
    LCD_GoTo(1,0);
    LCD_WriteByte("AD = ");
    LCD_GoTo(1,5);
    LCD_WriteByte(angleDesired/100+'0');
    LCD_WriteByte((angleDesired/10)%10+'0');
    LCD_WriteByte((angleDesired/1)% 10+'0');
}

void CompareLoadValue(void)
{
    compareLoadValue = ((expectedRippleCount - CALIBRATION_VALUE)>> 1) + INITIAL_TIMER_VALUE + 1;
}

void LoadValues(void)
{
    CCP1_SetCompareCount(compareLoadValue);
    TMR1_Reload();
    TMR4_Period8BitSet(PR2_VALUE);
}

void Compare_ISR(void) 
{
    BrakingMechanism02();
    BrakingMechanism();
    TMR4_StopTimer();
    TMR1_StopTimer();
    
    getCountDone = 1;
}

uint16_t GetActualRippleCount(void)
{
    timer1Value = ((TMR1_ReadTimer()+ PERIOD_TIMER1_VALUE) << 1)+ CALIBRATION_VALUE; 
    return (abs(timer1Value));
}

void RetrieveRippleCount(void)
{
    CCP1_CompareSetInterruptHandler(Compare_ISR);
}
/**
 End of File
*/