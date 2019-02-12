
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/device_config.h"
#include "motorcontrol.h"


bool inputBtnPressed = 0;
bool BtnPress = 0;

void CheckForwardButton(void)
{
    if(FORWARD_BUTTON_PORT == LOW)
    {  
        __delay_ms(100);
        ForwardBtnPressed = 1;
    }
}


void CheckReverseButton()
{
    if(REVERSE_BUTTON_PORT == LOW)
    {  
        __delay_ms(100);
//        BtnPress = 1;
//    }
//    else if(REVERSE_BUTTON_PORT == HIGH)
//    {
//        if(BtnPress)
//        {
//            BtnPress = 0;
            ReverseBtnPressed = 1;
//        }
    }
}

void CheckInputButton(void)
{
    if(SET_ANGLE_PORT == LOW)
    {  
        __delay_ms(100);
         inputBtnPressed = 1;
    }
    else if(SET_ANGLE_PORT == HIGH)
    {
        if(inputBtnPressed)
        {
            inputBtnPressed = 0;
            MotorInput();
        }
    }
}
