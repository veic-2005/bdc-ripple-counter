
#include "mcc_generated_files/cwg2.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/memory.h"
#include "mcc_generated_files/pin_manager.h"
#include "motorcontrol.h"
#include "stdlib.h"

void StoreMotor02Position();

void M2_ForwardPosition(void)
{   
    if (totalAngleTurned02 < ENDPOINT)
    {
        totalAngleTurned02 += angleTurned02;
        remainingAngle02 = ENDPOINT - totalAngleTurned02;
    }
    else
    {
        StopMotor2();
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
    else
    {
        StopMotor2();
    }
    reverseOrigin = 1;
    
    printf("totalangleTurned02 =%d \n\r", totalAngleTurned02);
    StoreMotor02Position();
}

void StoreMotor02Position(){
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
    }
}
