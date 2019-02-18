/*
 * Author : A20687
 * Date: 02/14/2019
 * File Name: motor01position_retention.c
 * Short Description: This file contains codes for handling the position of motor 1.
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
#include "mcc_generated_files/cog1.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/memory.h"
#include "mcc_generated_files/pin_manager.h"
#include "rc_headers/lcd.h"
#include "rc_headers/motorcontrol.h"
#include "rc_headers/motorposition.h"
#include "stdlib.h"

/**
 Section: Macro Declaration
 */
#define MOTOR01_ADDR00        0x3F80

/*
 Section: Variable Declaration
 */
bool homeReached = 0;
bool endPointReached = 0;

void StoreMotor01Position(void);

void M1_ForwardPosition(void)
{   
    if (totalAngleTurned01 < ENDPOINT)
    {
        totalAngleTurned01 += angleTurned01;
        remainingAngle01 = ENDPOINT - totalAngleTurned01;
    }
    
    homeReached = 0;
    reverseOrigin = 0;
    
    printf("totalangleTurned =%d \n\r", totalAngleTurned01);
    StoreMotor01Position();
}

void M1_ReversePosition(void)
{
    if (totalAngleTurned01 > HOME)   
    {
        totalAngleTurned01 -= angleTurned01;
        remainingAngle01 = totalAngleTurned01;
        
        if(remainingAngle01 == 0)
        {
            homeReached = 1;
        }
    }
    endPointReached = 0;
    reverseOrigin = 1;
    
    printf("totalangleTurned =%d \n\r", totalAngleTurned01);
    StoreMotor01Position();
}

void StoreMotor01Position(void){
    uint16_t Buf[ERASE_FLASH_BLOCKSIZE];
    uint16_t write01P01 = totalAngleTurned01;
    FLASH_WriteWord(MOTOR01_ADDR00, Buf, write01P01);  
}

void ReadMotor01PositionFromHEF(void) 
{
    uint16_t actualMotor01Position = FLASH_ReadWord(MOTOR01_ADDR00);
    
    if (actualMotor01Position < INITIAL_ADDRESS_VALUE) 
    {
        if(actualMotor01Position < 0)
        {
            totalAngleTurned01 = abs(actualMotor01Position);
        }
        else
        {
            totalAngleTurned01 = actualMotor01Position;
        }
        printf("actualMotor01Position = %d \n\r", actualMotor01Position);
        
        LCD_GoTo(1,0);
        LCD_WriteByte("M1 Position=   ");
        LCD_GoTo(1,12);
        LCD_WriteByte(actualMotor01Position/100+'0');
        LCD_WriteByte((actualMotor01Position/10)%10+'0');
        LCD_WriteByte((actualMotor01Position/1)% 10+'0');
    }
}
/**
 End of File
*/