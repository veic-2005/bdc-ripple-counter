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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F1779
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB 	          :  MPLAB X 5.10	
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

/**
  Section: Included Files
*/

#include <xc.h>

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

// get/set LCD_CHIP_SELECT aliases
#define LCD_CHIP_SELECT_TRIS                 TRISAbits.TRISA2
#define LCD_CHIP_SELECT_LAT                  LATAbits.LATA2
#define LCD_CHIP_SELECT_PORT                 PORTAbits.RA2
#define LCD_CHIP_SELECT_WPU                  WPUAbits.WPUA2
#define LCD_CHIP_SELECT_OD                   ODCONAbits.ODA2
#define LCD_CHIP_SELECT_ANS                  ANSELAbits.ANSA2
#define LCD_CHIP_SELECT_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LCD_CHIP_SELECT_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LCD_CHIP_SELECT_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LCD_CHIP_SELECT_GetValue()           PORTAbits.RA2
#define LCD_CHIP_SELECT_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LCD_CHIP_SELECT_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LCD_CHIP_SELECT_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LCD_CHIP_SELECT_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LCD_CHIP_SELECT_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define LCD_CHIP_SELECT_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define LCD_CHIP_SELECT_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LCD_CHIP_SELECT_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RA3 procedures
#define RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RA3_GetValue()              PORTAbits.RA3
#define RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define RA3_SetPullup()             do { WPUAbits.WPUA3 = 1; } while(0)
#define RA3_ResetPullup()           do { WPUAbits.WPUA3 = 0; } while(0)
#define RA3_SetAnalogMode()         do { ANSELAbits.ANSA3 = 1; } while(0)
#define RA3_SetDigitalMode()        do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set OPA1 aliases
#define OPA1_TRIS                 TRISAbits.TRISA4
#define OPA1_LAT                  LATAbits.LATA4
#define OPA1_PORT                 PORTAbits.RA4
#define OPA1_WPU                  WPUAbits.WPUA4
#define OPA1_OD                   ODCONAbits.ODA4
#define OPA1_ANS                  ANSELAbits.ANSA4
#define OPA1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define OPA1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define OPA1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define OPA1_GetValue()           PORTAbits.RA4
#define OPA1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define OPA1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define OPA1_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define OPA1_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define OPA1_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define OPA1_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define OPA1_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define OPA1_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set M1_FORWARD_BUTTON aliases
#define M1_FORWARD_BUTTON_TRIS                 TRISAbits.TRISA5
#define M1_FORWARD_BUTTON_LAT                  LATAbits.LATA5
#define M1_FORWARD_BUTTON_PORT                 PORTAbits.RA5
#define M1_FORWARD_BUTTON_WPU                  WPUAbits.WPUA5
#define M1_FORWARD_BUTTON_OD                   ODCONAbits.ODA5
#define M1_FORWARD_BUTTON_ANS                  ANSELAbits.ANSA5
#define M1_FORWARD_BUTTON_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define M1_FORWARD_BUTTON_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define M1_FORWARD_BUTTON_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define M1_FORWARD_BUTTON_GetValue()           PORTAbits.RA5
#define M1_FORWARD_BUTTON_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define M1_FORWARD_BUTTON_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define M1_FORWARD_BUTTON_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define M1_FORWARD_BUTTON_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define M1_FORWARD_BUTTON_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define M1_FORWARD_BUTTON_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)
#define M1_FORWARD_BUTTON_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define M1_FORWARD_BUTTON_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set C1OUT aliases
#define C1OUT_TRIS                 TRISAbits.TRISA6
#define C1OUT_LAT                  LATAbits.LATA6
#define C1OUT_PORT                 PORTAbits.RA6
#define C1OUT_WPU                  WPUAbits.WPUA6
#define C1OUT_OD                   ODCONAbits.ODA6
#define C1OUT_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define C1OUT_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define C1OUT_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define C1OUT_GetValue()           PORTAbits.RA6
#define C1OUT_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define C1OUT_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define C1OUT_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define C1OUT_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define C1OUT_SetPushPull()        do { ODCONAbits.ODA6 = 0; } while(0)
#define C1OUT_SetOpenDrain()       do { ODCONAbits.ODA6 = 1; } while(0)

// get/set COG3C aliases
#define COG3C_TRIS                 TRISAbits.TRISA7
#define COG3C_LAT                  LATAbits.LATA7
#define COG3C_PORT                 PORTAbits.RA7
#define COG3C_WPU                  WPUAbits.WPUA7
#define COG3C_OD                   ODCONAbits.ODA7
#define COG3C_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define COG3C_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define COG3C_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define COG3C_GetValue()           PORTAbits.RA7
#define COG3C_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define COG3C_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define COG3C_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define COG3C_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define COG3C_SetPushPull()        do { ODCONAbits.ODA7 = 0; } while(0)
#define COG3C_SetOpenDrain()       do { ODCONAbits.ODA7 = 1; } while(0)

// get/set M1_REVERSE_BUTTON aliases
#define M1_REVERSE_BUTTON_TRIS                 TRISBbits.TRISB0
#define M1_REVERSE_BUTTON_LAT                  LATBbits.LATB0
#define M1_REVERSE_BUTTON_PORT                 PORTBbits.RB0
#define M1_REVERSE_BUTTON_WPU                  WPUBbits.WPUB0
#define M1_REVERSE_BUTTON_OD                   ODCONBbits.ODB0
#define M1_REVERSE_BUTTON_ANS                  ANSELBbits.ANSB0
#define M1_REVERSE_BUTTON_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define M1_REVERSE_BUTTON_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define M1_REVERSE_BUTTON_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define M1_REVERSE_BUTTON_GetValue()           PORTBbits.RB0
#define M1_REVERSE_BUTTON_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define M1_REVERSE_BUTTON_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define M1_REVERSE_BUTTON_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define M1_REVERSE_BUTTON_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define M1_REVERSE_BUTTON_SetPushPull()        do { ODCONBbits.ODB0 = 0; } while(0)
#define M1_REVERSE_BUTTON_SetOpenDrain()       do { ODCONBbits.ODB0 = 1; } while(0)
#define M1_REVERSE_BUTTON_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define M1_REVERSE_BUTTON_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set OPA1IN1 aliases
#define OPA1IN1_TRIS                 TRISBbits.TRISB1
#define OPA1IN1_LAT                  LATBbits.LATB1
#define OPA1IN1_PORT                 PORTBbits.RB1
#define OPA1IN1_WPU                  WPUBbits.WPUB1
#define OPA1IN1_OD                   ODCONBbits.ODB1
#define OPA1IN1_ANS                  ANSELBbits.ANSB1
#define OPA1IN1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define OPA1IN1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define OPA1IN1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define OPA1IN1_GetValue()           PORTBbits.RB1
#define OPA1IN1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define OPA1IN1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define OPA1IN1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define OPA1IN1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define OPA1IN1_SetPushPull()        do { ODCONBbits.ODB1 = 0; } while(0)
#define OPA1IN1_SetOpenDrain()       do { ODCONBbits.ODB1 = 1; } while(0)
#define OPA1IN1_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define OPA1IN1_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set OVERCURRENT_LED aliases
#define OVERCURRENT_LED_TRIS                 TRISBbits.TRISB2
#define OVERCURRENT_LED_LAT                  LATBbits.LATB2
#define OVERCURRENT_LED_PORT                 PORTBbits.RB2
#define OVERCURRENT_LED_WPU                  WPUBbits.WPUB2
#define OVERCURRENT_LED_OD                   ODCONBbits.ODB2
#define OVERCURRENT_LED_ANS                  ANSELBbits.ANSB2
#define OVERCURRENT_LED_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define OVERCURRENT_LED_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define OVERCURRENT_LED_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define OVERCURRENT_LED_GetValue()           PORTBbits.RB2
#define OVERCURRENT_LED_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define OVERCURRENT_LED_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define OVERCURRENT_LED_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define OVERCURRENT_LED_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define OVERCURRENT_LED_SetPushPull()        do { ODCONBbits.ODB2 = 0; } while(0)
#define OVERCURRENT_LED_SetOpenDrain()       do { ODCONBbits.ODB2 = 1; } while(0)
#define OVERCURRENT_LED_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define OVERCURRENT_LED_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set M2_REVERSE_BUTTON aliases
#define M2_REVERSE_BUTTON_TRIS                 TRISBbits.TRISB5
#define M2_REVERSE_BUTTON_LAT                  LATBbits.LATB5
#define M2_REVERSE_BUTTON_PORT                 PORTBbits.RB5
#define M2_REVERSE_BUTTON_WPU                  WPUBbits.WPUB5
#define M2_REVERSE_BUTTON_OD                   ODCONBbits.ODB5
#define M2_REVERSE_BUTTON_ANS                  ANSELBbits.ANSB5
#define M2_REVERSE_BUTTON_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define M2_REVERSE_BUTTON_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define M2_REVERSE_BUTTON_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define M2_REVERSE_BUTTON_GetValue()           PORTBbits.RB5
#define M2_REVERSE_BUTTON_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define M2_REVERSE_BUTTON_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define M2_REVERSE_BUTTON_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define M2_REVERSE_BUTTON_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define M2_REVERSE_BUTTON_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define M2_REVERSE_BUTTON_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define M2_REVERSE_BUTTON_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define M2_REVERSE_BUTTON_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

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

// get/set M2_FORWARD_BUTTON aliases
#define M2_FORWARD_BUTTON_TRIS                 TRISCbits.TRISC2
#define M2_FORWARD_BUTTON_LAT                  LATCbits.LATC2
#define M2_FORWARD_BUTTON_PORT                 PORTCbits.RC2
#define M2_FORWARD_BUTTON_WPU                  WPUCbits.WPUC2
#define M2_FORWARD_BUTTON_OD                   ODCONCbits.ODC2
#define M2_FORWARD_BUTTON_ANS                  ANSELCbits.ANSC2
#define M2_FORWARD_BUTTON_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define M2_FORWARD_BUTTON_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define M2_FORWARD_BUTTON_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define M2_FORWARD_BUTTON_GetValue()           PORTCbits.RC2
#define M2_FORWARD_BUTTON_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define M2_FORWARD_BUTTON_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define M2_FORWARD_BUTTON_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define M2_FORWARD_BUTTON_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define M2_FORWARD_BUTTON_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define M2_FORWARD_BUTTON_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define M2_FORWARD_BUTTON_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define M2_FORWARD_BUTTON_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set SCK aliases
#define SCK_TRIS                 TRISCbits.TRISC3
#define SCK_LAT                  LATCbits.LATC3
#define SCK_PORT                 PORTCbits.RC3
#define SCK_WPU                  WPUCbits.WPUC3
#define SCK_OD                   ODCONCbits.ODC3
#define SCK_ANS                  ANSELCbits.ANSC3
#define SCK_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SCK_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SCK_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SCK_GetValue()           PORTCbits.RC3
#define SCK_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SCK_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SCK_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SCK_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SCK_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define SCK_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define SCK_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define SCK_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set SDI aliases
#define SDI_TRIS                 TRISCbits.TRISC4
#define SDI_LAT                  LATCbits.LATC4
#define SDI_PORT                 PORTCbits.RC4
#define SDI_WPU                  WPUCbits.WPUC4
#define SDI_OD                   ODCONCbits.ODC4
#define SDI_ANS                  ANSELCbits.ANSC4
#define SDI_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SDI_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SDI_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SDI_GetValue()           PORTCbits.RC4
#define SDI_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SDI_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SDI_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SDI_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SDI_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define SDI_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)
#define SDI_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define SDI_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set SDO aliases
#define SDO_TRIS                 TRISCbits.TRISC5
#define SDO_LAT                  LATCbits.LATC5
#define SDO_PORT                 PORTCbits.RC5
#define SDO_WPU                  WPUCbits.WPUC5
#define SDO_OD                   ODCONCbits.ODC5
#define SDO_ANS                  ANSELCbits.ANSC5
#define SDO_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SDO_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SDO_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SDO_GetValue()           PORTCbits.RC5
#define SDO_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SDO_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SDO_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SDO_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SDO_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define SDO_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)
#define SDO_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define SDO_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

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

// get/set STALL_LED aliases
#define STALL_LED_TRIS                 TRISDbits.TRISD3
#define STALL_LED_LAT                  LATDbits.LATD3
#define STALL_LED_PORT                 PORTDbits.RD3
#define STALL_LED_WPU                  WPUDbits.WPUD3
#define STALL_LED_OD                   ODCONDbits.ODD3
#define STALL_LED_ANS                  ANSELDbits.ANSD3
#define STALL_LED_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define STALL_LED_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define STALL_LED_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define STALL_LED_GetValue()           PORTDbits.RD3
#define STALL_LED_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define STALL_LED_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define STALL_LED_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define STALL_LED_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define STALL_LED_SetPushPull()        do { ODCONDbits.ODD3 = 0; } while(0)
#define STALL_LED_SetOpenDrain()       do { ODCONDbits.ODD3 = 1; } while(0)
#define STALL_LED_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define STALL_LED_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

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

// get/set POT aliases
#define POT_TRIS                 TRISEbits.TRISE0
#define POT_LAT                  LATEbits.LATE0
#define POT_PORT                 PORTEbits.RE0
#define POT_WPU                  WPUEbits.WPUE0
#define POT_OD                   ODCONEbits.ODE0
#define POT_ANS                  ANSELEbits.ANSE0
#define POT_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define POT_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define POT_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define POT_GetValue()           PORTEbits.RE0
#define POT_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define POT_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define POT_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define POT_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define POT_SetPushPull()        do { ODCONEbits.ODE0 = 0; } while(0)
#define POT_SetOpenDrain()       do { ODCONEbits.ODE0 = 1; } while(0)
#define POT_SetAnalogMode()      do { ANSELEbits.ANSE0 = 1; } while(0)
#define POT_SetDigitalMode()     do { ANSELEbits.ANSE0 = 0; } while(0)

// get/set RE1 procedures
#define RE1_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define RE1_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define RE1_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define RE1_GetValue()              PORTEbits.RE1
#define RE1_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define RE1_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define RE1_SetPullup()             do { WPUEbits.WPUE1 = 1; } while(0)
#define RE1_ResetPullup()           do { WPUEbits.WPUE1 = 0; } while(0)
#define RE1_SetAnalogMode()         do { ANSELEbits.ANSE1 = 1; } while(0)
#define RE1_SetDigitalMode()        do { ANSELEbits.ANSE1 = 0; } while(0)

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



#endif // PIN_MANAGER_H
/**
 End of File
*/