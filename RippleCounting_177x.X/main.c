/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1779
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "motorcontrol.h"
#include "lcd.h"

void CheckMotorSelectorButton();
void nextMotor();
/*
                         Main application
 */
void main(void) {
    SYSTEM_Initialize();
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    LCD_Initialize();
    
    StallDetection();
    OvercurrentDetection();
    
    CCP1_CompareSetInterruptHandler(Compare_ISR);
            
    while (1) 
    {
        ReadInput();
        ReadMotor01PositionFromHEF();
        ReadMotor02PositionFromHEF();

        CheckM1ForwardButton();
        CheckM1ReverseButton(); 
        CheckM2ForwardButton();
        CheckM2ReverseButton();
      
        if(getCountDone)
        {
            actualRippleCount = GetActualRippleCount();
            
            if(motor01)
            {
               getCountDone = 0;
               Motor01Position();
            }
            else
            {
               getCountDone = 0;
               Motor02Position();
            }
        }
        
        if(faultDetected)
        {
            faultDetected = 0;
            GetActualRippleCount();
           
            if(motor01)
            {
               Motor01Position();
            }
            else
            {
               Motor02Position(); 
            }
            __delay_ms(5000);
            ResumeMotor();
        }
    }
 }

/**
 End of File
 */