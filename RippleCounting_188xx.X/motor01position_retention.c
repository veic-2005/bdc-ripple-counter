
#include "mcc_generated_files/cwg1.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/memory.h"
#include "mcc_generated_files/pin_manager.h"
#include "motorcontrol.h"
#include "stdlib.h"

void StoreMotor01Position();

void M1_ForwardPosition(void)
{   
    if (totalAngleTurned01 < ENDPOINT)
    {
        totalAngleTurned01 += angleTurned01;
        remainingAngle01 = ENDPOINT - totalAngleTurned01;
    }
    else
    {
        StopMotor1();
    }
    reverseOrigin = 0;
    
    printf("totalangleTurned01 =%d \n\r", totalAngleTurned01);
    StoreMotor01Position();
}

void M1_ReversePosition(void)
{
    if (totalAngleTurned01 > HOME)   
    {
        totalAngleTurned01 -= angleTurned01;
        remainingAngle01 = totalAngleTurned01;
    }
    else
    {
        StopMotor1();
    }
    reverseOrigin = 1;
    
    printf("totalangleTurned01 =%d \n\r", totalAngleTurned01);
    StoreMotor01Position();
}

void StoreMotor01Position(){
    uint8_t writeByteLSB = totalAngleTurned01;
    uint8_t writeByteMSB = totalAngleTurned01 >> 8;
    DATAEE_WriteByte(MOTOR01_ADDR00, writeByteLSB);
    DATAEE_WriteByte(MOTOR01_ADDR01, writeByteMSB); 
}

void ReadMotor01PositionFromEEPROM(void) 
{
    uint16_t readByteMSB = DATAEE_ReadByte(MOTOR01_ADDR01);
    uint8_t readByteLSB = DATAEE_ReadByte(MOTOR01_ADDR00);
    uint16_t actualMotor01Position = (readByteMSB << 8) + readByteLSB;
    
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
    }
}
