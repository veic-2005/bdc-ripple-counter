
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/device_config.h"
#include "motorcontrol.h"

bool m1ForwardBtnPressed = 0;
bool m2ForwardBtnPressed = 0;
bool m1ReverseBtnPressed = 0;
bool m2ReverseBtnPressed = 0;

void CheckM1ForwardButton(void)
{
    if(M1_FORWARD_BUTTON_PORT == LOW)
    {  
        __delay_ms(100);
         m1ForwardBtnPressed = 1;
    }
    else if (M1_FORWARD_BUTTON_PORT == HIGH)
    {
        if(m1ForwardBtnPressed)
        {
            m1ForwardBtnPressed = 0;
            Motor01Forward_Drive();
        }
    }
}

void CheckM2ForwardButton(void)
{
    if(M2_FORWARD_BUTTON_PORT == LOW)
    {  
        __delay_ms(100);
        m2ForwardBtnPressed = 1;
    }
    else if (M2_FORWARD_BUTTON_PORT == HIGH)
    {
        if(m2ForwardBtnPressed)
        {
            m2ForwardBtnPressed = 0;
            Motor02Forward_Drive();
        }
    }
}

void CheckM1ReverseButton()
{
    if(M1_REVERSE_BUTTON_PORT == LOW)
    {  
        __delay_ms(100);
        m1ReverseBtnPressed = 1;
    }
    
    else if(M1_REVERSE_BUTTON_PORT == HIGH)
    {
        if(m1ReverseBtnPressed)
        {
            m1ReverseBtnPressed = 0;
            Motor01Reverse_Drive();
        }
    }
}

void CheckM2ReverseButton()
{
    if(M2_REVERSE_BUTTON_PORT == LOW)
    {  
        __delay_ms(100);
        m2ReverseBtnPressed = 1;
    }
    
    else if(M2_REVERSE_BUTTON_PORT == HIGH)
    {
        if(m2ReverseBtnPressed)
        {
            m2ReverseBtnPressed = 0;
            Motor02Reverse_Drive();
        }
    }
}

