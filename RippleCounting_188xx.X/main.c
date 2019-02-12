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
        Device            :  PIC16F18877
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

#include <stdint.h>

#include "mcc_generated_files/mcc.h"
#include "motorcontrol.h"

#define SWITCH_S1_TTL()    do { INLVLBbits.INLVLB0 = 0; } while(0)

void CheckMotorSelectorButton(void);

bool BtnPressed = 0;

/*
                         Main application
 */
void main(void)
{
    SWITCH_S1_TTL();
    SYSTEM_Initialize();
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
     
    printf("Start \n\r");
    
    while (1)
    {
        CheckMotorSelectorButton();
        
        switch(selectMotor)
        {
            case 1: MotorDrive01();     break;
            case 2: MotorDrive02();     break;
            case 3: DualMotorDrive();   break;
        }
        
        if(switchEvent)
        {
            NextMotor();
        }
    }
}

void CheckMotorSelectorButton(void)
{
    if(MOTOR_SELECT_PORT == LOW)
    {  
        __delay_ms(100);
        BtnPressed = 1;
    }
    else if (MOTOR_SELECT_PORT == HIGH)
    {
        if(BtnPressed)
        {
            BtnPressed = 0;
            switchEvent = 1;
        }
    }
}

void NextMotor()
{
    switchEvent = 0;
    selectMotor++;
    if(selectMotor > 3)
    {
        selectMotor = 1;
    }
}
/**
 End of File
*/