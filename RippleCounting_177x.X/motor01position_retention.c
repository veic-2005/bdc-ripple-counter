
#include "mcc_generated_files/cog1.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/memory.h"
#include "mcc_generated_files/pin_manager.h"
#include "motorcontrol.h"

bool homeReached = 0;
bool endPointReached = 0;

void StoreMotor01Position();

void M1_ForwardPosition(void)
{   
    if (totalAngleTurned01 < ENDPOINT)
    {
        totalAngleTurned01 += angleTurned01;
        remainingAngle01 = ENDPOINT - totalAngleTurned01;
        
        if(remainingAngle01 == 0)
        {
            endPointReached = 1;
        }
    }
    else
    {
        StopMotor1();
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
    else
    {
        StopMotor1();
    }
    endPointReached = 0;
    reverseOrigin = 1;
    
    printf("totalangleTurned =%d \n\r", totalAngleTurned01);
    StoreMotor01Position();
}

void StoreMotor01Position(){
    uint16_t Buf[ERASE_FLASH_BLOCKSIZE];
    uint16_t write01P01 = totalAngleTurned01;
    FLASH_WriteWord(MOTOR01_ADDR00, Buf, write01P01);
    
}

void ReadMotor01PositionFromHEF(void) 
{
    uint16_t actualMotor01Position = FLASH_ReadWord(MOTOR01_ADDR00);
    
    if (actualMotor01Position < INITIAL_ADDRESS_VALUE) 
    {
        totalAngleTurned01 = actualMotor01Position;
        printf("actualMotor01Position = %d \n\r", actualMotor01Position);
    }
}
