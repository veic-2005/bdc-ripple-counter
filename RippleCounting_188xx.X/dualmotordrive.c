/* 
 * Author : A20687
 * Date: 02/14/2019
 * File Name: dualmotordrive.c
 *  Short Description: This file contains codes for driving motors 1 and 2 in forward and reverse direction.
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
#include "mcc_generated_files/cwg1.h"
#include "mcc_generated_files/cwg2.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/smt1.h"
#include "mcc_generated_files/smt2.h"
#include "mcc_generated_files/tmr6.h"
#include "mcc_generated_files/tmr4.h"
#include "motorcontrol.h"
#include "motorposition.h"
#include "stdlib.h"

/*
 Section: Variable Declaration
 */
bool getCountDone = 0; 

/*
 Section; Function Declaration
 */
void InitiateDrive03(void);

void DualMotorDrive(void) 
{
    ReadMotor01PositionFromEEPROM();
    ReadMotor02PositionFromEEPROM();
    ReadInput();
    CheckInputButton();
    CheckForwardButton();
    CheckReverseButton();
    
    if(ForwardBtnPressed)
    {
        MOTOR01_MODE = FORWARD_DIR;
        MOTOR02_MODE = FORWARD_DIR;
        
        ForwardBtnPressed = 0;
        forwardDirection = 1;
    
        if((totalAngleTurned01 >= ENDPOINT) || (totalAngleTurned02 >= ENDPOINT) || (angleDesired %5 != 0))
        {
            StopMotor1();
            StopMotor2();
        }
        else
        {   
            InitiateDrive03();
        }
    }
    else if(ReverseBtnPressed)
    {
        MOTOR01_MODE = REVERSE_DIR;
        MOTOR02_MODE = REVERSE_DIR;
        
        ReverseBtnPressed = 0;
        reverseDirection = 1;
        
        if((totalAngleTurned01 <= HOME) || (totalAngleTurned02 <= HOME) ||(angleDesired %5 != 0))
        {
           StopMotor1();
           StopMotor2();
        }
        else
        {   
            InitiateDrive03();
        }
    }
    
    SMT1_SetInterruptHandler(SMT1_ISR);
    SMT2_SetInterruptHandler(SMT2_ISR);
    
    if(getCountDone01 && getCountDone02)
    {
        getCountDone = 1;
        Motor01Position();
        Motor02Position();

    }
}

void InitiateDrive03(void)
{
    SMT1_DataAcquisitionEnable();
    SMT2_DataAcquisitionEnable();
    StartMotor1();
    StartMotor2();
    StartStallTimer4();
    StartStallTimer6();
}
/**
 End of File
*/