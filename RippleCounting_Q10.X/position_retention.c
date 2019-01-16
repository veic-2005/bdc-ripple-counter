/*
 * Author : A20687
 * Date: 12/04/2018
 * File Name: position_retention.c
 * Short Description: This file contains codes for processing  the position of the motor, storing and retrieving of it from the EEPROM.
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

#include "mcc_generated_files/cwg.h"
#include "mcc_generated_files/eusart1.h"
#include "mcc_generated_files/memory.h"
#include "motorcontrol.h"
#include "mcc_generated_files/pin_manager.h"

void ForwardPosition()
{   
    if (totalAngleTurned < END_POINT)
    {
        totalAngleTurned += angleTurned;
        remainingAngle = END_POINT - totalAngleTurned;
        
        if(remainingAngle == 0)
        {
            EndPointReachedLED_SetHigh();
            endPointReached = 1;
        }
    }
    else
    {
        StopMotor();
    }
    
    homeReached = 0;
    reverseOrigin = 0;
    HomeReachedLED_SetLow();
    
    printf("totalangleTurned =%d \n\r", totalAngleTurned);
    StorePosition();
}

void ReversePosition()
{
    if (totalAngleTurned > HOME)   
    {
        totalAngleTurned -= angleTurned;
        remainingAngle = totalAngleTurned;
        
        if(remainingAngle == 0)
        {
            HomeReachedLED_SetHigh();
            homeReached = 1;
        }
    }
    else
    {
        StopMotor();
    }
    
        
    endPointReached = 0;
    reverseOrigin = 1;
    EndPointReachedLED_SetLow();

    printf("totalangleTurned =%d \n\r", totalAngleTurned);
    StorePosition();
}

void StorePosition()
{   
    uint8_t writeByteLSB = totalAngleTurned;
    uint8_t writeByteMSB = totalAngleTurned >> 8;
    DATAEE_WriteByte(MOTOR_ADDR00, writeByteLSB);
    DATAEE_WriteByte(MOTOR_ADDR01, writeByteMSB);
}

void ReadMotorPositionFromEEPROM() 
{
    uint16_t readByteMSB = DATAEE_ReadByte(MOTOR_ADDR01);
    uint8_t readByteLSB = DATAEE_ReadByte(MOTOR_ADDR00);
    uint16_t actualPosition = (readByteMSB << 8) + readByteLSB;
    
    if (actualPosition < INITIAL_ADDRESS_VALUE) 
    {
        totalAngleTurned = actualPosition;
        printf("actualPosition = %d \n\r", actualPosition);
    }
}

void MotorPosition()
{
  if(forwardDirection)
  {
    forwardDirection = 0;
    ForwardPosition(); 
  }

  else if(reverseDirection)
  {
    reverseDirection = 0;
    ReversePosition();
  }  
}

