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

#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/device_config.h"
#include "rc_headers/motorcontrol.h"

/**
 Section: Variable Declaration
 */
bool m1ForwardBtnPressed = 0;
bool m2ForwardBtnPressed = 0;
bool m1ReverseBtnPressed = 0;
bool m2ReverseBtnPressed = 0;

void CheckM1ForwardButton(void)
{
    if(M1_FORWARD_BUTTON_PORT == LOW)
    {  
        __delay_ms(100);
         m1ForwardBtnPressed = 1;
    }
    else if (M1_FORWARD_BUTTON_PORT == HIGH)
    {
        if(m1ForwardBtnPressed)
        {
            m1ForwardBtnPressed = 0;
            Motor01Forward_Drive();
        }
    }
}

void CheckM2ForwardButton(void)
{
    if(M2_FORWARD_BUTTON_PORT == LOW)
    {  
        __delay_ms(100);
        m2ForwardBtnPressed = 1;
    }
    else if (M2_FORWARD_BUTTON_PORT == HIGH)
    {
        if(m2ForwardBtnPressed)
        {
            m2ForwardBtnPressed = 0;
            Motor02Forward_Drive();
        }
    }
}

void CheckM1ReverseButton(void)
{
    if(M1_REVERSE_BUTTON_PORT == LOW)
    {  
        __delay_ms(100);
        m1ReverseBtnPressed = 1;
    }
    
    else if(M1_REVERSE_BUTTON_PORT == HIGH)
    {
        if(m1ReverseBtnPressed)
        {
            m1ReverseBtnPressed = 0;
            Motor01Reverse_Drive();
        }
    }
}

void CheckM2ReverseButton(void)
{
    if(M2_REVERSE_BUTTON_PORT == LOW)
    {  
        __delay_ms(100);
        m2ReverseBtnPressed = 1;
    }
    
    else if(M2_REVERSE_BUTTON_PORT == HIGH)
    {
        if(m2ReverseBtnPressed)
        {
            m2ReverseBtnPressed = 0;
            Motor02Reverse_Drive();
        }
    }
}
/**
 End of File
*/

