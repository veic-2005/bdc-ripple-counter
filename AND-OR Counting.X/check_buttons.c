
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/mcc.h"
#include "motorcontrol.h"

bool forwardBtnPressed = 0;
bool reverseBtnPressed = 0;

void Forward_Dir();
void Reverse_Dir();


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
            Motor01Forward_Dir();
        }
    }
}

void CheckForwardButton02(void)
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
            Motor02Forward_Dir();
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
            Motor01Reverse_Dir();
        }
    }
}

void CheckReverseButton02()
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
            Motor02Reverse_Dir();
        }
    }
}

