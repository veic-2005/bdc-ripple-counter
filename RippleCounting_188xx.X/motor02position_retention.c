/*
 * Author : A20687
 * Date: 02/14/2019
 * File Name: motor02position_retention.c
 * Short Description: This file contains codes for handling the position of motor 2.
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
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/memory.h"
#include "mcc_generated_files/pin_manager.h"
#include "motorcontrol.h"
#include "motorposition.h"
#include "stdlib.h"
#include "lcd.h"

/**
 * Macro Declaration 
 */
#define MOTOR02_ADDR00        0x7004
#define MOTOR02_ADDR01        0x7006

void StoreMotor02Position(void);

void M2_ForwardPosition(void)
{   
    if (totalAngleTurned02 < ENDPOINT)
    {
        totalAngleTurned02 += angleTurned02;
        remainingAngle02 = ENDPOINT - totalAngleTurned02;
    }
    
    reverseOrigin = 0;
    
    printf("totalangleTurned02 =%d \n\r", totalAngleTurned02);
    StoreMotor02Position();
}

void M2_ReversePosition(void)
{
    if (totalAngleTurned02 > HOME)   
    {
        totalAngleTurned02 -= angleTurned02;
        remainingAngle02 = totalAngleTurned02;
    }
    
    reverseOrigin = 1;
    
    printf("totalangleTurned02 =%d \n\r", totalAngleTurned02);
    StoreMotor02Position();
}

void StoreMotor02Position(void){
    uint8_t writeByteLSB = totalAngleTurned02;
    uint8_t writeByteMSB = totalAngleTurned02 >> 8;
    DATAEE_WriteByte(MOTOR02_ADDR00, writeByteLSB);
    DATAEE_WriteByte(MOTOR02_ADDR01, writeByteMSB); 
}

void ReadMotor02PositionFromEEPROM(void) 
{
    uint16_t readByteMSB = DATAEE_ReadByte(MOTOR02_ADDR01);
    uint8_t readByteLSB = DATAEE_ReadByte(MOTOR02_ADDR00);
    uint16_t actualMotor02Position = (readByteMSB << 8) + readByteLSB;
    
    if (actualMotor02Position < INITIAL_ADDRESS_VALUE) 
    {
        if(actualMotor02Position < 0)
        {
            totalAngleTurned02 = abs(actualMotor02Position);
        }
        else
        {
            totalAngleTurned02 = actualMotor02Position;
        }
        printf("actualMotor02Position = %d \n\r", actualMotor02Position);
        
        LCD_GoTo(1,0);
        LCD_WriteByte("M2=   ");
        LCD_GoTo(1,3);
        LCD_WriteByte(actualMotor02Position/100+'0');
        LCD_WriteByte((actualMotor02Position/10)%10+'0');
        LCD_WriteByte((actualMotor02Position/1)% 10+'0');
    }
}
/**
 End of File
*/