
#include "mcc_generated_files/pin_manager.h"
#include "motorcontrol.h"

bool homeBtnPressed = 0;
bool endBtnPressed = 0;
bool forwardBtnPressed = 0;
bool reverseBtnPressed = 0;

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
            Forward_Dir();
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
            Reverse_Dir();
        }
    }
}

void CheckHomeButton()
{
    if(Home_Button_PORT == LOW)
    {  
        __delay_ms(100);
        homeBtnPressed = 1;
    }
    
    else if(Home_Button_PORT == HIGH)
    {
        if(homeBtnPressed)
        {
            homeBtnPressed = 0;
            
            if(reverseOrigin)
            {
                reverseOrigin = 0;
                ExpectedRippleCountRemainingAngle();
            }
            
            else
            {
                ExpectedRippleCountToHome();
            }
            CompareLoadValue();
            Reverse_Dir();
        }
    }
}

void CheckEndButton()
{
    if(End_Button_PORT == LOW)
    {  
        __delay_ms(100);
        endBtnPressed = 1;
    }
    
    else if(End_Button_PORT == HIGH)
    {
        if(endBtnPressed)
        {
            endBtnPressed = 0;
            
            if(reverseOrigin)
            {
                reverseOrigin = 0;
                ExpectedRippleCountToEndPoint();
            }
            else
            {
                ExpectedRippleCountRemainingAngle();
            }
            CompareLoadValue();
            Forward_Dir();
        }
    }
}
