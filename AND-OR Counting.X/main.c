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

void CheckMotorSelectorButton();
void nextMotor();
/*
                         Main application
 */
void main(void) {
    SYSTEM_Initialize();
    D7_SetLow();
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    StallDetection();
    OvercurrentDetectionMotor01();
    OvercurrentDetectionMotor02();
    
    CCP1_CompareSetInterruptHandler(Compare_ISR);
            
    while (1) 
    {
        ReadInput();
        CheckMotorSelectorButton();

        if(motorNumber) 
        {
            MotorDrive01();
        }
        else
        {
            MotorDrive02();
        }
        
        if(getCountDone)
        {
            getCountDone = 0;
            GetActualRippleCount();
           
            if(motorNumber)
            {
               Motor01Position();
            }
            else
            {
               Motor02Position(); 
            }
        }
        
//        if(motorStalled)
//        {
//            motorStalled = 0;
//            GetActualRippleCount();
//           
//            if(motorNumber)
//            {
//               Motor01Position();
//            }
//            else if
//            {
//               Motor02Position(); 
//            }
//            __delay_ms(5000);
//            ResumeMotor();
//        }
    }
 }

void CheckMotorSelectorButton(void)
{
    if( MotorSelect_Button_PORT == LOW)
    {  
        __delay_ms(100);
        motorSelectorPressed = 1;    
    }
    
    else if( MotorSelect_Button_PORT == HIGH)
    {
        if(motorSelectorPressed)
        {
            motorSelectorPressed = 0;
            nextMotor();
        }                                                   
    }
}

void nextMotor(void) {
    motorNumber = ~motorNumber;      
}
/**
 End of File
 */