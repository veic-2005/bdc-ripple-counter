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
        Device            :  PIC16F18877
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

// get/set Motor01_OCchannel aliases
#define Motor01_OCchannel_TRIS                 TRISAbits.TRISA4
#define Motor01_OCchannel_LAT                  LATAbits.LATA4
#define Motor01_OCchannel_PORT                 PORTAbits.RA4
#define Motor01_OCchannel_WPU                  WPUAbits.WPUA4
#define Motor01_OCchannel_OD                   ODCONAbits.ODCA4
#define Motor01_OCchannel_ANS                  ANSELAbits.ANSA4
#define Motor01_OCchannel_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define Motor01_OCchannel_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define Motor01_OCchannel_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define Motor01_OCchannel_GetValue()           PORTAbits.RA4
#define Motor01_OCchannel_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define Motor01_OCchannel_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define Motor01_OCchannel_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define Motor01_OCchannel_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define Motor01_OCchannel_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define Motor01_OCchannel_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define Motor01_OCchannel_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define Motor01_OCchannel_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set SWITCH_S1 aliases
#define SWITCH_S1_TRIS                 TRISAbits.TRISA5
#define SWITCH_S1_LAT                  LATAbits.LATA5
#define SWITCH_S1_PORT                 PORTAbits.RA5
#define SWITCH_S1_WPU                  WPUAbits.WPUA5
#define SWITCH_S1_OD                   ODCONAbits.ODCA5
#define SWITCH_S1_ANS                  ANSELAbits.ANSA5
#define SWITCH_S1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SWITCH_S1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SWITCH_S1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SWITCH_S1_GetValue()           PORTAbits.RA5
#define SWITCH_S1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SWITCH_S1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SWITCH_S1_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define SWITCH_S1_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define SWITCH_S1_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define SWITCH_S1_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define SWITCH_S1_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define SWITCH_S1_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set POT aliases
#define POT_TRIS                 TRISAbits.TRISA6
#define POT_LAT                  LATAbits.LATA6
#define POT_PORT                 PORTAbits.RA6
#define POT_WPU                  WPUAbits.WPUA6
#define POT_OD                   ODCONAbits.ODCA6
#define POT_ANS                  ANSELAbits.ANSA6
#define POT_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define POT_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define POT_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define POT_GetValue()           PORTAbits.RA6
#define POT_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define POT_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define POT_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define POT_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define POT_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define POT_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define POT_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define POT_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set Motor02_OCchannel aliases
#define Motor02_OCchannel_TRIS                 TRISAbits.TRISA7
#define Motor02_OCchannel_LAT                  LATAbits.LATA7
#define Motor02_OCchannel_PORT                 PORTAbits.RA7
#define Motor02_OCchannel_WPU                  WPUAbits.WPUA7
#define Motor02_OCchannel_OD                   ODCONAbits.ODCA7
#define Motor02_OCchannel_ANS                  ANSELAbits.ANSA7
#define Motor02_OCchannel_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define Motor02_OCchannel_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define Motor02_OCchannel_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define Motor02_OCchannel_GetValue()           PORTAbits.RA7
#define Motor02_OCchannel_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define Motor02_OCchannel_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define Motor02_OCchannel_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define Motor02_OCchannel_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define Motor02_OCchannel_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define Motor02_OCchannel_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define Motor02_OCchannel_SetAnalogMode()      do { ANSELAbits.ANSA7 = 1; } while(0)
#define Motor02_OCchannel_SetDigitalMode()     do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set SWITCH_S2 aliases
#define SWITCH_S2_TRIS                 TRISBbits.TRISB0
#define SWITCH_S2_LAT                  LATBbits.LATB0
#define SWITCH_S2_PORT                 PORTBbits.RB0
#define SWITCH_S2_WPU                  WPUBbits.WPUB0
#define SWITCH_S2_OD                   ODCONBbits.ODCB0
#define SWITCH_S2_ANS                  ANSELBbits.ANSB0
#define SWITCH_S2_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define SWITCH_S2_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define SWITCH_S2_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define SWITCH_S2_GetValue()           PORTBbits.RB0
#define SWITCH_S2_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define SWITCH_S2_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define SWITCH_S2_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define SWITCH_S2_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define SWITCH_S2_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define SWITCH_S2_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define SWITCH_S2_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define SWITCH_S2_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set LED_D6 aliases
#define LED_D6_TRIS                 TRISBbits.TRISB1
#define LED_D6_LAT                  LATBbits.LATB1
#define LED_D6_PORT                 PORTBbits.RB1
#define LED_D6_WPU                  WPUBbits.WPUB1
#define LED_D6_OD                   ODCONBbits.ODCB1
#define LED_D6_ANS                  ANSELBbits.ANSB1
#define LED_D6_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define LED_D6_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define LED_D6_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define LED_D6_GetValue()           PORTBbits.RB1
#define LED_D6_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define LED_D6_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define LED_D6_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define LED_D6_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define LED_D6_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define LED_D6_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define LED_D6_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define LED_D6_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set Stall_Indicator_LED aliases
#define Stall_Indicator_LED_TRIS                 TRISBbits.TRISB2
#define Stall_Indicator_LED_LAT                  LATBbits.LATB2
#define Stall_Indicator_LED_PORT                 PORTBbits.RB2
#define Stall_Indicator_LED_WPU                  WPUBbits.WPUB2
#define Stall_Indicator_LED_OD                   ODCONBbits.ODCB2
#define Stall_Indicator_LED_ANS                  ANSELBbits.ANSB2
#define Stall_Indicator_LED_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define Stall_Indicator_LED_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define Stall_Indicator_LED_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define Stall_Indicator_LED_GetValue()           PORTBbits.RB2
#define Stall_Indicator_LED_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define Stall_Indicator_LED_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define Stall_Indicator_LED_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define Stall_Indicator_LED_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define Stall_Indicator_LED_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define Stall_Indicator_LED_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define Stall_Indicator_LED_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define Stall_Indicator_LED_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set OverCurrentIndicator_LED aliases
#define OverCurrentIndicator_LED_TRIS                 TRISBbits.TRISB3
#define OverCurrentIndicator_LED_LAT                  LATBbits.LATB3
#define OverCurrentIndicator_LED_PORT                 PORTBbits.RB3
#define OverCurrentIndicator_LED_WPU                  WPUBbits.WPUB3
#define OverCurrentIndicator_LED_OD                   ODCONBbits.ODCB3
#define OverCurrentIndicator_LED_ANS                  ANSELBbits.ANSB3
#define OverCurrentIndicator_LED_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define OverCurrentIndicator_LED_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define OverCurrentIndicator_LED_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define OverCurrentIndicator_LED_GetValue()           PORTBbits.RB3
#define OverCurrentIndicator_LED_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define OverCurrentIndicator_LED_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define OverCurrentIndicator_LED_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define OverCurrentIndicator_LED_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define OverCurrentIndicator_LED_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define OverCurrentIndicator_LED_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define OverCurrentIndicator_LED_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define OverCurrentIndicator_LED_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

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

// get/set S3 aliases
#define S3_TRIS                 TRISBbits.TRISB7
#define S3_LAT                  LATBbits.LATB7
#define S3_PORT                 PORTBbits.RB7
#define S3_WPU                  WPUBbits.WPUB7
#define S3_OD                   ODCONBbits.ODCB7
#define S3_ANS                  ANSELBbits.ANSB7
#define S3_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define S3_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define S3_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define S3_GetValue()           PORTBbits.RB7
#define S3_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define S3_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define S3_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define S3_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define S3_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define S3_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define S3_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define S3_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSC5 = 0; } while(0)

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

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

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

// get/set RD1 procedures
#define RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RD1_GetValue()              PORTDbits.RD1
#define RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RD1_SetPullup()             do { WPUDbits.WPUD1 = 1; } while(0)
#define RD1_ResetPullup()           do { WPUDbits.WPUD1 = 0; } while(0)
#define RD1_SetAnalogMode()         do { ANSELDbits.ANSD1 = 1; } while(0)
#define RD1_SetDigitalMode()        do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set RD2 procedures
#define RD2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define RD2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define RD2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define RD2_GetValue()              PORTDbits.RD2
#define RD2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define RD2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define RD2_SetPullup()             do { WPUDbits.WPUD2 = 1; } while(0)
#define RD2_ResetPullup()           do { WPUDbits.WPUD2 = 0; } while(0)
#define RD2_SetAnalogMode()         do { ANSELDbits.ANSD2 = 1; } while(0)
#define RD2_SetDigitalMode()        do { ANSELDbits.ANSD2 = 0; } while(0)

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

// get/set RD7 procedures
#define RD7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define RD7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define RD7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define RD7_GetValue()              PORTDbits.RD7
#define RD7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define RD7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define RD7_SetPullup()             do { WPUDbits.WPUD7 = 1; } while(0)
#define RD7_ResetPullup()           do { WPUDbits.WPUD7 = 0; } while(0)
#define RD7_SetAnalogMode()         do { ANSELDbits.ANSD7 = 1; } while(0)
#define RD7_SetDigitalMode()        do { ANSELDbits.ANSD7 = 0; } while(0)

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


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF0 pin functionality
 * @Example
    IOCBF0_ISR();
 */
void IOCBF0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF0_SetInterruptHandler() method.
    This handler is called every time the IOCBF0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(IOCBF0_InterruptHandler);

*/
extern void (*IOCBF0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF0_SetInterruptHandler() method.
    This handler is called every time the IOCBF0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(IOCBF0_DefaultInterruptHandler);

*/
void IOCBF0_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF7 pin functionality
 * @Example
    IOCBF7_ISR();
 */
void IOCBF7_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF7 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF7 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF7_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF7_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF7 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF7_SetInterruptHandler() method.
    This handler is called every time the IOCBF7 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF7_SetInterruptHandler(IOCBF7_InterruptHandler);

*/
extern void (*IOCBF7_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF7 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF7_SetInterruptHandler() method.
    This handler is called every time the IOCBF7 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF7_SetInterruptHandler(IOCBF7_DefaultInterruptHandler);

*/
void IOCBF7_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/