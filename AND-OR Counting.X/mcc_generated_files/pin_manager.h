/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1779
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()              PORTAbits.RA0
#define RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetPullup()             do { WPUAbits.WPUA0 = 1; } while(0)
#define RA0_ResetPullup()           do { WPUAbits.WPUA0 = 0; } while(0)
#define RA0_SetAnalogMode()         do { ANSELAbits.ANSA0 = 1; } while(0)
#define RA0_SetDigitalMode()        do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA1 procedures
#define RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()              PORTAbits.RA1
#define RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()             do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()           do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode()         do { ANSELAbits.ANSA1 = 1; } while(0)
#define RA1_SetDigitalMode()        do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set POT aliases
#define POT_TRIS                 TRISAbits.TRISA3
#define POT_LAT                  LATAbits.LATA3
#define POT_PORT                 PORTAbits.RA3
#define POT_WPU                  WPUAbits.WPUA3
#define POT_OD                   ODCONAbits.ODA3
#define POT_ANS                  ANSELAbits.ANSA3
#define POT_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define POT_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define POT_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define POT_GetValue()           PORTAbits.RA3
#define POT_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define POT_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define POT_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define POT_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define POT_SetPushPull()        do { ODCONAbits.ODA3 = 0; } while(0)
#define POT_SetOpenDrain()       do { ODCONAbits.ODA3 = 1; } while(0)
#define POT_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define POT_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set EndPointReachedLED aliases
#define EndPointReachedLED_TRIS                 TRISAbits.TRISA4
#define EndPointReachedLED_LAT                  LATAbits.LATA4
#define EndPointReachedLED_PORT                 PORTAbits.RA4
#define EndPointReachedLED_WPU                  WPUAbits.WPUA4
#define EndPointReachedLED_OD                   ODCONAbits.ODA4
#define EndPointReachedLED_ANS                  ANSELAbits.ANSA4
#define EndPointReachedLED_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define EndPointReachedLED_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define EndPointReachedLED_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define EndPointReachedLED_GetValue()           PORTAbits.RA4
#define EndPointReachedLED_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define EndPointReachedLED_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define EndPointReachedLED_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define EndPointReachedLED_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define EndPointReachedLED_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define EndPointReachedLED_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define EndPointReachedLED_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define EndPointReachedLED_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set HomeReachedLED aliases
#define HomeReachedLED_TRIS                 TRISAbits.TRISA5
#define HomeReachedLED_LAT                  LATAbits.LATA5
#define HomeReachedLED_PORT                 PORTAbits.RA5
#define HomeReachedLED_WPU                  WPUAbits.WPUA5
#define HomeReachedLED_OD                   ODCONAbits.ODA5
#define HomeReachedLED_ANS                  ANSELAbits.ANSA5
#define HomeReachedLED_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define HomeReachedLED_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define HomeReachedLED_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define HomeReachedLED_GetValue()           PORTAbits.RA5
#define HomeReachedLED_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define HomeReachedLED_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define HomeReachedLED_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define HomeReachedLED_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define HomeReachedLED_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define HomeReachedLED_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)
#define HomeReachedLED_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define HomeReachedLED_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set Stall_IndicatorLED aliases
#define Stall_IndicatorLED_TRIS                 TRISAbits.TRISA6
#define Stall_IndicatorLED_LAT                  LATAbits.LATA6
#define Stall_IndicatorLED_PORT                 PORTAbits.RA6
#define Stall_IndicatorLED_WPU                  WPUAbits.WPUA6
#define Stall_IndicatorLED_OD                   ODCONAbits.ODA6
#define Stall_IndicatorLED_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define Stall_IndicatorLED_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define Stall_IndicatorLED_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define Stall_IndicatorLED_GetValue()           PORTAbits.RA6
#define Stall_IndicatorLED_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define Stall_IndicatorLED_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define Stall_IndicatorLED_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define Stall_IndicatorLED_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define Stall_IndicatorLED_SetPushPull()        do { ODCONAbits.ODA6 = 0; } while(0)
#define Stall_IndicatorLED_SetOpenDrain()       do { ODCONAbits.ODA6 = 1; } while(0)

// get/set GetRippleLED aliases
#define GetRippleLED_TRIS                 TRISAbits.TRISA7
#define GetRippleLED_LAT                  LATAbits.LATA7
#define GetRippleLED_PORT                 PORTAbits.RA7
#define GetRippleLED_WPU                  WPUAbits.WPUA7
#define GetRippleLED_OD                   ODCONAbits.ODA7
#define GetRippleLED_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define GetRippleLED_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define GetRippleLED_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define GetRippleLED_GetValue()           PORTAbits.RA7
#define GetRippleLED_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define GetRippleLED_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define GetRippleLED_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define GetRippleLED_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define GetRippleLED_SetPushPull()        do { ODCONAbits.ODA7 = 0; } while(0)
#define GetRippleLED_SetOpenDrain()       do { ODCONAbits.ODA7 = 1; } while(0)

// get/set MotorSelect_Button aliases
#define MotorSelect_Button_TRIS                 TRISBbits.TRISB1
#define MotorSelect_Button_LAT                  LATBbits.LATB1
#define MotorSelect_Button_PORT                 PORTBbits.RB1
#define MotorSelect_Button_WPU                  WPUBbits.WPUB1
#define MotorSelect_Button_OD                   ODCONBbits.ODB1
#define MotorSelect_Button_ANS                  ANSELBbits.ANSB1
#define MotorSelect_Button_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define MotorSelect_Button_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define MotorSelect_Button_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define MotorSelect_Button_GetValue()           PORTBbits.RB1
#define MotorSelect_Button_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define MotorSelect_Button_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define MotorSelect_Button_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define MotorSelect_Button_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define MotorSelect_Button_SetPushPull()        do { ODCONBbits.ODB1 = 0; } while(0)
#define MotorSelect_Button_SetOpenDrain()       do { ODCONBbits.ODB1 = 1; } while(0)
#define MotorSelect_Button_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define MotorSelect_Button_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set D7 aliases
#define D7_TRIS                 TRISBbits.TRISB2
#define D7_LAT                  LATBbits.LATB2
#define D7_PORT                 PORTBbits.RB2
#define D7_WPU                  WPUBbits.WPUB2
#define D7_OD                   ODCONBbits.ODB2
#define D7_ANS                  ANSELBbits.ANSB2
#define D7_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define D7_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define D7_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define D7_GetValue()           PORTBbits.RB2
#define D7_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define D7_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define D7_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define D7_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define D7_SetPushPull()        do { ODCONBbits.ODB2 = 0; } while(0)
#define D7_SetOpenDrain()       do { ODCONBbits.ODB2 = 1; } while(0)
#define D7_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define D7_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set OverCurrentIndicator_LED aliases
#define OverCurrentIndicator_LED_TRIS                 TRISBbits.TRISB3
#define OverCurrentIndicator_LED_LAT                  LATBbits.LATB3
#define OverCurrentIndicator_LED_PORT                 PORTBbits.RB3
#define OverCurrentIndicator_LED_WPU                  WPUBbits.WPUB3
#define OverCurrentIndicator_LED_OD                   ODCONBbits.ODB3
#define OverCurrentIndicator_LED_ANS                  ANSELBbits.ANSB3
#define OverCurrentIndicator_LED_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define OverCurrentIndicator_LED_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define OverCurrentIndicator_LED_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define OverCurrentIndicator_LED_GetValue()           PORTBbits.RB3
#define OverCurrentIndicator_LED_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define OverCurrentIndicator_LED_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define OverCurrentIndicator_LED_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define OverCurrentIndicator_LED_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define OverCurrentIndicator_LED_SetPushPull()        do { ODCONBbits.ODB3 = 0; } while(0)
#define OverCurrentIndicator_LED_SetOpenDrain()       do { ODCONBbits.ODB3 = 1; } while(0)
#define OverCurrentIndicator_LED_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define OverCurrentIndicator_LED_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set Forward_Switch aliases
#define Forward_Switch_TRIS                 TRISBbits.TRISB4
#define Forward_Switch_LAT                  LATBbits.LATB4
#define Forward_Switch_PORT                 PORTBbits.RB4
#define Forward_Switch_WPU                  WPUBbits.WPUB4
#define Forward_Switch_OD                   ODCONBbits.ODB4
#define Forward_Switch_ANS                  ANSELBbits.ANSB4
#define Forward_Switch_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define Forward_Switch_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define Forward_Switch_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define Forward_Switch_GetValue()           PORTBbits.RB4
#define Forward_Switch_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define Forward_Switch_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define Forward_Switch_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define Forward_Switch_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define Forward_Switch_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define Forward_Switch_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define Forward_Switch_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define Forward_Switch_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)

// get/set Reverse_Switch aliases
#define Reverse_Switch_TRIS                 TRISCbits.TRISC5
#define Reverse_Switch_LAT                  LATCbits.LATC5
#define Reverse_Switch_PORT                 PORTCbits.RC5
#define Reverse_Switch_WPU                  WPUCbits.WPUC5
#define Reverse_Switch_OD                   ODCONCbits.ODC5
#define Reverse_Switch_ANS                  ANSELCbits.ANSC5
#define Reverse_Switch_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define Reverse_Switch_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define Reverse_Switch_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define Reverse_Switch_GetValue()           PORTCbits.RC5
#define Reverse_Switch_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define Reverse_Switch_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define Reverse_Switch_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define Reverse_Switch_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define Reverse_Switch_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define Reverse_Switch_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)
#define Reverse_Switch_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define Reverse_Switch_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RD0 procedures
#define RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define RD0_GetValue()              PORTDbits.RD0
#define RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define RD0_SetPullup()             do { WPUDbits.WPUD0 = 1; } while(0)
#define RD0_ResetPullup()           do { WPUDbits.WPUD0 = 0; } while(0)
#define RD0_SetAnalogMode()         do { ANSELDbits.ANSD0 = 1; } while(0)
#define RD0_SetDigitalMode()        do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set RD3 procedures
#define RD3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define RD3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define RD3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define RD3_GetValue()              PORTDbits.RD3
#define RD3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define RD3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define RD3_SetPullup()             do { WPUDbits.WPUD3 = 1; } while(0)
#define RD3_ResetPullup()           do { WPUDbits.WPUD3 = 0; } while(0)
#define RD3_SetAnalogMode()         do { ANSELDbits.ANSD3 = 1; } while(0)
#define RD3_SetDigitalMode()        do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set RD4 procedures
#define RD4_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define RD4_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define RD4_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define RD4_GetValue()              PORTDbits.RD4
#define RD4_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define RD4_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define RD4_SetPullup()             do { WPUDbits.WPUD4 = 1; } while(0)
#define RD4_ResetPullup()           do { WPUDbits.WPUD4 = 0; } while(0)
#define RD4_SetAnalogMode()         do { ANSELDbits.ANSD4 = 1; } while(0)
#define RD4_SetDigitalMode()        do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set RD5 procedures
#define RD5_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define RD5_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define RD5_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define RD5_GetValue()              PORTDbits.RD5
#define RD5_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define RD5_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define RD5_SetPullup()             do { WPUDbits.WPUD5 = 1; } while(0)
#define RD5_ResetPullup()           do { WPUDbits.WPUD5 = 0; } while(0)
#define RD5_SetAnalogMode()         do { ANSELDbits.ANSD5 = 1; } while(0)
#define RD5_SetDigitalMode()        do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set RD6 procedures
#define RD6_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define RD6_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define RD6_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define RD6_GetValue()              PORTDbits.RD6
#define RD6_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define RD6_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define RD6_SetPullup()             do { WPUDbits.WPUD6 = 1; } while(0)
#define RD6_ResetPullup()           do { WPUDbits.WPUD6 = 0; } while(0)
#define RD6_SetAnalogMode()         do { ANSELDbits.ANSD6 = 1; } while(0)
#define RD6_SetDigitalMode()        do { ANSELDbits.ANSD6 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF5 pin functionality
 * @Example
    IOCAF5_ISR();
 */
void IOCAF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_InterruptHandler);

*/
extern void (*IOCAF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_DefaultInterruptHandler);

*/
void IOCAF5_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/