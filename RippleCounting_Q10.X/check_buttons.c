/* 
 * Author : A20687
 * Date: 02/14/2019
 * File Name: check_buttons.c
 *  Short Description: This source file contains the code for checking the input buttons used in this application.
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
 */
#include "mcc_generated_files/device_config.h"
#include "mcc_generated_files/pin_manager.h"
#include "motorcontrol.h"

/**
 Section: Variable Declaration
 */
bool homeBtnPressed = 0;
bool endBtnPressed = 0;
bool forwardBtnPressed = 0;
bool reverseBtnPressed = 0;

void CheckForwardButton(void)
{
    if(Forward_Switch_PORT == LOW)
    {  
        __delay_ms(100);
        forwardBtnPressed = 1;
    }
    else if (Forward_Switch_PORT == HIGH)
    {
        if(forwardBtnPressed)
        {
            forwardBtnPressed = 0;
            Forward_Dir();
        }
    }
}

void CheckReverseButton()
{
    if(Reverse_Switch_PORT == LOW)
    {  
        __delay_ms(100);
        reverseBtnPressed = 1;
    }
    
    else if(Reverse_Switch_PORT == HIGH)
    {
        if(reverseBtnPressed)
        {
            reverseBtnPressed = 0;
            Reverse_Dir();
        }
    }
}

void CheckHomeButton()
{
    if(Home_Button_PORT == LOW)
    {  
        __delay_ms(100);
        homeBtnPressed = 1;
    }
    
    else if(Home_Button_PORT == HIGH)
    {
        if(homeBtnPressed)
        {
            homeBtnPressed = 0;
            
            if(reverseOrigin)
            {
                reverseOrigin = 0;
                ExpectedRippleCountRemainingAngle();
            }
            
            else
            {
                ExpectedRippleCountToHome();
            }
            CompareLoadValue();
            Reverse_Dir();
        }
    }
}

void CheckEndButton()
{
    if(End_Button_PORT == LOW)
    {  
        __delay_ms(100);
        endBtnPressed = 1;
    }
    
    else if(End_Button_PORT == HIGH)
    {
        if(endBtnPressed)
        {
            endBtnPressed = 0;
            
            if(reverseOrigin)
            {
                reverseOrigin = 0;
                ExpectedRippleCountToEndPoint();
            }
            else
            {
                ExpectedRippleCountRemainingAngle();
            }
            CompareLoadValue();
            Forward_Dir();
        }
    }
}
/**
 End of File
*/