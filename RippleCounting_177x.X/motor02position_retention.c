
#include "mcc_generated_files/cog3.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/memory.h"
#include "mcc_generated_files/pin_manager.h"
#include "motorcontrol.h"

bool homeReached = 0;
bool endPointReached = 0;

void StoreMotor02Position();

void M2_ForwardPosition(void)
{   
    if (totalAngleTurned02 < ENDPOINT)
    {
        totalAngleTurned02 += angleTurned02;
        remainingAngle02 = ENDPOINT - totalAngleTurned02;
        
        if(remainingAngle02 == 0)
        {
            endPointReached = 1;
        }
    }
    else
    {
        StopMotor2();
    }
    
    homeReached = 0;
    reverseOrigin = 0;
    
    printf("totalangleTurned =%d \n\r", totalAngleTurned02);
    StoreMotor02Position();
}

void M2_ReversePosition(void)
{
    if (totalAngleTurned02 > HOME)   
    {
        totalAngleTurned02 -= angleTurned02;
        remainingAngle02 = totalAngleTurned02;
        
        if(remainingAngle01 == 0)
        {
            homeReached = 1;
        }
    }
    else
    {
        StopMotor2();
    }
    endPointReached = 0;
    reverseOrigin = 1;
    
    printf("totalangleTurned =%d \n\r", totalAngleTurned02);
    StoreMotor02Position();
}


void StoreMotor02Position(){
    uint16_t Buf[ERASE_FLASH_BLOCKSIZE];
    uint16_t write01P02 = totalAngleTurned02;
    FLASH_WriteWord(MOTOR02_ADDR00, Buf, write01P02);
}

void ReadMotor02PositionFromHEF(void) 
{
    uint16_t actualMotor02Position = FLASH_ReadWord(MOTOR02_ADDR00);
    
    if (actualMotor02Position < INITIAL_ADDRESS_VALUE) 
    {
        totalAngleTurned02 = actualMotor02Position;
        printf("actualMotor02Position = %d \n\r", actualMotor02Position);
    }
}