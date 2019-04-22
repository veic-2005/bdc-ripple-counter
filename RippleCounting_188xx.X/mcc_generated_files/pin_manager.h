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
        Device            :  PIC16F18877
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

// get/set POT aliases
#define POT_TRIS                 TRISAbits.TRISA0
#define POT_LAT                  LATAbits.LATA0
#define POT_PORT                 PORTAbits.RA0
#define POT_WPU                  WPUAbits.WPUA0
#define POT_OD                   ODCONAbits.ODCA0
#define POT_ANS                  ANSELAbits.ANSA0
#define POT_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define POT_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define POT_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define POT_GetValue()           PORTAbits.RA0
#define POT_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define POT_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define POT_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define POT_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define POT_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define POT_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define POT_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define POT_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set LCD_CHIP_SELECT aliases
#define LCD_CHIP_SELECT_TRIS                 TRISAbits.TRISA2
#define LCD_CHIP_SELECT_LAT                  LATAbits.LATA2
#define LCD_CHIP_SELECT_PORT                 PORTAbits.RA2
#define LCD_CHIP_SELECT_WPU                  WPUAbits.WPUA2
#define LCD_CHIP_SELECT_OD                   ODCONAbits.ODCA2
#define LCD_CHIP_SELECT_ANS                  ANSELAbits.ANSA2
#define LCD_CHIP_SELECT_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LCD_CHIP_SELECT_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LCD_CHIP_SELECT_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LCD_CHIP_SELECT_GetValue()           PORTAbits.RA2
#define LCD_CHIP_SELECT_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LCD_CHIP_SELECT_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LCD_CHIP_SELECT_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LCD_CHIP_SELECT_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LCD_CHIP_SELECT_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LCD_CHIP_SELECT_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LCD_CHIP_SELECT_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LCD_CHIP_SELECT_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set FORWARD_BUTTON aliases
#define FORWARD_BUTTON_TRIS                 TRISAbits.TRISA5
#define FORWARD_BUTTON_LAT                  LATAbits.LATA5
#define FORWARD_BUTTON_PORT                 PORTAbits.RA5
#define FORWARD_BUTTON_WPU                  WPUAbits.WPUA5
#define FORWARD_BUTTON_OD                   ODCONAbits.ODCA5
#define FORWARD_BUTTON_ANS                  ANSELAbits.ANSA5
#define FORWARD_BUTTON_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define FORWARD_BUTTON_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define FORWARD_BUTTON_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define FORWARD_BUTTON_GetValue()           PORTAbits.RA5
#define FORWARD_BUTTON_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define FORWARD_BUTTON_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define FORWARD_BUTTON_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define FORWARD_BUTTON_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define FORWARD_BUTTON_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define FORWARD_BUTTON_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define FORWARD_BUTTON_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define FORWARD_BUTTON_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set MOTOR_SELECT_BUTTON aliases
#define MOTOR_SELECT_BUTTON_TRIS                 TRISAbits.TRISA6
#define MOTOR_SELECT_BUTTON_LAT                  LATAbits.LATA6
#define MOTOR_SELECT_BUTTON_PORT                 PORTAbits.RA6
#define MOTOR_SELECT_BUTTON_WPU                  WPUAbits.WPUA6
#define MOTOR_SELECT_BUTTON_OD                   ODCONAbits.ODCA6
#define MOTOR_SELECT_BUTTON_ANS                  ANSELAbits.ANSA6
#define MOTOR_SELECT_BUTTON_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define MOTOR_SELECT_BUTTON_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define MOTOR_SELECT_BUTTON_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define MOTOR_SELECT_BUTTON_GetValue()           PORTAbits.RA6
#define MOTOR_SELECT_BUTTON_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define MOTOR_SELECT_BUTTON_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define MOTOR_SELECT_BUTTON_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define MOTOR_SELECT_BUTTON_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define MOTOR_SELECT_BUTTON_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define MOTOR_SELECT_BUTTON_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define MOTOR_SELECT_BUTTON_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define MOTOR_SELECT_BUTTON_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set SET_ANGLE_BUTTON aliases
#define SET_ANGLE_BUTTON_TRIS                 TRISAbits.TRISA7
#define SET_ANGLE_BUTTON_LAT                  LATAbits.LATA7
#define SET_ANGLE_BUTTON_PORT                 PORTAbits.RA7
#define SET_ANGLE_BUTTON_WPU                  WPUAbits.WPUA7
#define SET_ANGLE_BUTTON_OD                   ODCONAbits.ODCA7
#define SET_ANGLE_BUTTON_ANS                  ANSELAbits.ANSA7
#define SET_ANGLE_BUTTON_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define SET_ANGLE_BUTTON_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define SET_ANGLE_BUTTON_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define SET_ANGLE_BUTTON_GetValue()           PORTAbits.RA7
#define SET_ANGLE_BUTTON_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define SET_ANGLE_BUTTON_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define SET_ANGLE_BUTTON_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define SET_ANGLE_BUTTON_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define SET_ANGLE_BUTTON_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define SET_ANGLE_BUTTON_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define SET_ANGLE_BUTTON_SetAnalogMode()      do { ANSELAbits.ANSA7 = 1; } while(0)
#define SET_ANGLE_BUTTON_SetDigitalMode()     do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set REVERSE_BUTTON aliases
#define REVERSE_BUTTON_TRIS                 TRISBbits.TRISB0
#define REVERSE_BUTTON_LAT                  LATBbits.LATB0
#define REVERSE_BUTTON_PORT                 PORTBbits.RB0
#define REVERSE_BUTTON_WPU                  WPUBbits.WPUB0
#define REVERSE_BUTTON_OD                   ODCONBbits.ODCB0
#define REVERSE_BUTTON_ANS                  ANSELBbits.ANSB0
#define REVERSE_BUTTON_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define REVERSE_BUTTON_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define REVERSE_BUTTON_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define REVERSE_BUTTON_GetValue()           PORTBbits.RB0
#define REVERSE_BUTTON_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define REVERSE_BUTTON_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define REVERSE_BUTTON_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define REVERSE_BUTTON_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define REVERSE_BUTTON_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define REVERSE_BUTTON_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define REVERSE_BUTTON_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define REVERSE_BUTTON_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set HOME_LED aliases
#define HOME_LED_TRIS                 TRISBbits.TRISB2
#define HOME_LED_LAT                  LATBbits.LATB2
#define HOME_LED_PORT                 PORTBbits.RB2
#define HOME_LED_WPU                  WPUBbits.WPUB2
#define HOME_LED_OD                   ODCONBbits.ODCB2
#define HOME_LED_ANS                  ANSELBbits.ANSB2
#define HOME_LED_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define HOME_LED_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define HOME_LED_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define HOME_LED_GetValue()           PORTBbits.RB2
#define HOME_LED_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define HOME_LED_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define HOME_LED_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define HOME_LED_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define HOME_LED_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define HOME_LED_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define HOME_LED_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define HOME_LED_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set ENDPOINT_LED aliases
#define ENDPOINT_LED_TRIS                 TRISBbits.TRISB3
#define ENDPOINT_LED_LAT                  LATBbits.LATB3
#define ENDPOINT_LED_PORT                 PORTBbits.RB3
#define ENDPOINT_LED_WPU                  WPUBbits.WPUB3
#define ENDPOINT_LED_OD                   ODCONBbits.ODCB3
#define ENDPOINT_LED_ANS                  ANSELBbits.ANSB3
#define ENDPOINT_LED_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define ENDPOINT_LED_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define ENDPOINT_LED_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define ENDPOINT_LED_GetValue()           PORTBbits.RB3
#define ENDPOINT_LED_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define ENDPOINT_LED_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define ENDPOINT_LED_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define ENDPOINT_LED_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define ENDPOINT_LED_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define ENDPOINT_LED_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define ENDPOINT_LED_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define ENDPOINT_LED_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

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

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSB7 = 0; } while(0)

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

// get/set SCK1 aliases
#define SCK1_TRIS                 TRISCbits.TRISC3
#define SCK1_LAT                  LATCbits.LATC3
#define SCK1_PORT                 PORTCbits.RC3
#define SCK1_WPU                  WPUCbits.WPUC3
#define SCK1_OD                   ODCONCbits.ODCC3
#define SCK1_ANS                  ANSELCbits.ANSC3
#define SCK1_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SCK1_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SCK1_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SCK1_GetValue()           PORTCbits.RC3
#define SCK1_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SCK1_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SCK1_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SCK1_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SCK1_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SCK1_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define SCK1_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define SCK1_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set SDI1 aliases
#define SDI1_TRIS                 TRISCbits.TRISC4
#define SDI1_LAT                  LATCbits.LATC4
#define SDI1_PORT                 PORTCbits.RC4
#define SDI1_WPU                  WPUCbits.WPUC4
#define SDI1_OD                   ODCONCbits.ODCC4
#define SDI1_ANS                  ANSELCbits.ANSC4
#define SDI1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SDI1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SDI1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SDI1_GetValue()           PORTCbits.RC4
#define SDI1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SDI1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SDI1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SDI1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SDI1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SDI1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SDI1_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define SDI1_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set SDO1 aliases
#define SDO1_TRIS                 TRISCbits.TRISC5
#define SDO1_LAT                  LATCbits.LATC5
#define SDO1_PORT                 PORTCbits.RC5
#define SDO1_WPU                  WPUCbits.WPUC5
#define SDO1_OD                   ODCONCbits.ODCC5
#define SDO1_ANS                  ANSELCbits.ANSC5
#define SDO1_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SDO1_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SDO1_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SDO1_GetValue()           PORTCbits.RC5
#define SDO1_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SDO1_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SDO1_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SDO1_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SDO1_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define SDO1_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define SDO1_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define SDO1_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

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

// get/set STALL_LED aliases
#define STALL_LED_TRIS                 TRISDbits.TRISD0
#define STALL_LED_LAT                  LATDbits.LATD0
#define STALL_LED_PORT                 PORTDbits.RD0
#define STALL_LED_WPU                  WPUDbits.WPUD0
#define STALL_LED_OD                   ODCONDbits.ODCD0
#define STALL_LED_ANS                  ANSELDbits.ANSD0
#define STALL_LED_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define STALL_LED_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define STALL_LED_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define STALL_LED_GetValue()           PORTDbits.RD0
#define STALL_LED_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define STALL_LED_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define STALL_LED_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define STALL_LED_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define STALL_LED_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define STALL_LED_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define STALL_LED_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define STALL_LED_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

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



#endif // PIN_MANAGER_H
/**
 End of File
*/