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
        Device            :  PIC18F46Q10
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

// get/set getRippleChannel aliases
#define getRippleChannel_TRIS                 TRISAbits.TRISA0
#define getRippleChannel_LAT                  LATAbits.LATA0
#define getRippleChannel_PORT                 PORTAbits.RA0
#define getRippleChannel_WPU                  WPUAbits.WPUA0
#define getRippleChannel_OD                   ODCONAbits.ODCA0
#define getRippleChannel_ANS                  ANSELAbits.ANSELA0
#define getRippleChannel_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define getRippleChannel_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define getRippleChannel_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define getRippleChannel_GetValue()           PORTAbits.RA0
#define getRippleChannel_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define getRippleChannel_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define getRippleChannel_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define getRippleChannel_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define getRippleChannel_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define getRippleChannel_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define getRippleChannel_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define getRippleChannel_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSELA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set EndPointReachedLED aliases
#define EndPointReachedLED_TRIS                 TRISAbits.TRISA4
#define EndPointReachedLED_LAT                  LATAbits.LATA4
#define EndPointReachedLED_PORT                 PORTAbits.RA4
#define EndPointReachedLED_WPU                  WPUAbits.WPUA4
#define EndPointReachedLED_OD                   ODCONAbits.ODCA4
#define EndPointReachedLED_ANS                  ANSELAbits.ANSELA4
#define EndPointReachedLED_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define EndPointReachedLED_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define EndPointReachedLED_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define EndPointReachedLED_GetValue()           PORTAbits.RA4
#define EndPointReachedLED_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define EndPointReachedLED_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define EndPointReachedLED_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define EndPointReachedLED_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define EndPointReachedLED_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define EndPointReachedLED_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define EndPointReachedLED_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define EndPointReachedLED_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set HomeReachedLED aliases
#define HomeReachedLED_TRIS                 TRISAbits.TRISA5
#define HomeReachedLED_LAT                  LATAbits.LATA5
#define HomeReachedLED_PORT                 PORTAbits.RA5
#define HomeReachedLED_WPU                  WPUAbits.WPUA5
#define HomeReachedLED_OD                   ODCONAbits.ODCA5
#define HomeReachedLED_ANS                  ANSELAbits.ANSELA5
#define HomeReachedLED_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define HomeReachedLED_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define HomeReachedLED_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define HomeReachedLED_GetValue()           PORTAbits.RA5
#define HomeReachedLED_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define HomeReachedLED_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define HomeReachedLED_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define HomeReachedLED_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define HomeReachedLED_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define HomeReachedLED_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define HomeReachedLED_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define HomeReachedLED_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set Stall_IndicatorLED aliases
#define Stall_IndicatorLED_TRIS                 TRISAbits.TRISA6
#define Stall_IndicatorLED_LAT                  LATAbits.LATA6
#define Stall_IndicatorLED_PORT                 PORTAbits.RA6
#define Stall_IndicatorLED_WPU                  WPUAbits.WPUA6
#define Stall_IndicatorLED_OD                   ODCONAbits.ODCA6
#define Stall_IndicatorLED_ANS                  ANSELAbits.ANSELA6
#define Stall_IndicatorLED_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define Stall_IndicatorLED_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define Stall_IndicatorLED_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define Stall_IndicatorLED_GetValue()           PORTAbits.RA6
#define Stall_IndicatorLED_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define Stall_IndicatorLED_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define Stall_IndicatorLED_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define Stall_IndicatorLED_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define Stall_IndicatorLED_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define Stall_IndicatorLED_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define Stall_IndicatorLED_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define Stall_IndicatorLED_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set GetRippleLED aliases
#define GetRippleLED_TRIS                 TRISAbits.TRISA7
#define GetRippleLED_LAT                  LATAbits.LATA7
#define GetRippleLED_PORT                 PORTAbits.RA7
#define GetRippleLED_WPU                  WPUAbits.WPUA7
#define GetRippleLED_OD                   ODCONAbits.ODCA7
#define GetRippleLED_ANS                  ANSELAbits.ANSELA7
#define GetRippleLED_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define GetRippleLED_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define GetRippleLED_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define GetRippleLED_GetValue()           PORTAbits.RA7
#define GetRippleLED_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define GetRippleLED_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define GetRippleLED_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define GetRippleLED_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define GetRippleLED_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define GetRippleLED_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define GetRippleLED_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define GetRippleLED_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSELB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set Home_Button aliases
#define Home_Button_TRIS                 TRISBbits.TRISB1
#define Home_Button_LAT                  LATBbits.LATB1
#define Home_Button_PORT                 PORTBbits.RB1
#define Home_Button_WPU                  WPUBbits.WPUB1
#define Home_Button_OD                   ODCONBbits.ODCB1
#define Home_Button_ANS                  ANSELBbits.ANSELB1
#define Home_Button_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define Home_Button_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define Home_Button_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define Home_Button_GetValue()           PORTBbits.RB1
#define Home_Button_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define Home_Button_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define Home_Button_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define Home_Button_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define Home_Button_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define Home_Button_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define Home_Button_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define Home_Button_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set End_Button aliases
#define End_Button_TRIS                 TRISBbits.TRISB2
#define End_Button_LAT                  LATBbits.LATB2
#define End_Button_PORT                 PORTBbits.RB2
#define End_Button_WPU                  WPUBbits.WPUB2
#define End_Button_OD                   ODCONBbits.ODCB2
#define End_Button_ANS                  ANSELBbits.ANSELB2
#define End_Button_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define End_Button_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define End_Button_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define End_Button_GetValue()           PORTBbits.RB2
#define End_Button_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define End_Button_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define End_Button_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define End_Button_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define End_Button_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define End_Button_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define End_Button_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define End_Button_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set Forward_Switch aliases
#define Forward_Switch_TRIS                 TRISBbits.TRISB4
#define Forward_Switch_LAT                  LATBbits.LATB4
#define Forward_Switch_PORT                 PORTBbits.RB4
#define Forward_Switch_WPU                  WPUBbits.WPUB4
#define Forward_Switch_OD                   ODCONBbits.ODCB4
#define Forward_Switch_ANS                  ANSELBbits.ANSELB4
#define Forward_Switch_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define Forward_Switch_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define Forward_Switch_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define Forward_Switch_GetValue()           PORTBbits.RB4
#define Forward_Switch_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define Forward_Switch_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define Forward_Switch_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define Forward_Switch_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define Forward_Switch_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define Forward_Switch_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define Forward_Switch_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define Forward_Switch_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set Reverse_Switch aliases
#define Reverse_Switch_TRIS                 TRISCbits.TRISC5
#define Reverse_Switch_LAT                  LATCbits.LATC5
#define Reverse_Switch_PORT                 PORTCbits.RC5
#define Reverse_Switch_WPU                  WPUCbits.WPUC5
#define Reverse_Switch_OD                   ODCONCbits.ODCC5
#define Reverse_Switch_ANS                  ANSELCbits.ANSELC5
#define Reverse_Switch_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define Reverse_Switch_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define Reverse_Switch_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define Reverse_Switch_GetValue()           PORTCbits.RC5
#define Reverse_Switch_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define Reverse_Switch_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define Reverse_Switch_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define Reverse_Switch_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define Reverse_Switch_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define Reverse_Switch_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define Reverse_Switch_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define Reverse_Switch_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RD1 procedures
#define RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RD1_GetValue()              PORTDbits.RD1
#define RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RD1_SetPullup()             do { WPUDbits.WPUD1 = 1; } while(0)
#define RD1_ResetPullup()           do { WPUDbits.WPUD1 = 0; } while(0)
#define RD1_SetAnalogMode()         do { ANSELDbits.ANSELD1 = 1; } while(0)
#define RD1_SetDigitalMode()        do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set RD2 procedures
#define RD2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define RD2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define RD2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define RD2_GetValue()              PORTDbits.RD2
#define RD2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define RD2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define RD2_SetPullup()             do { WPUDbits.WPUD2 = 1; } while(0)
#define RD2_ResetPullup()           do { WPUDbits.WPUD2 = 0; } while(0)
#define RD2_SetAnalogMode()         do { ANSELDbits.ANSELD2 = 1; } while(0)
#define RD2_SetDigitalMode()        do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set RD3 procedures
#define RD3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define RD3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define RD3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define RD3_GetValue()              PORTDbits.RD3
#define RD3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define RD3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define RD3_SetPullup()             do { WPUDbits.WPUD3 = 1; } while(0)
#define RD3_ResetPullup()           do { WPUDbits.WPUD3 = 0; } while(0)
#define RD3_SetAnalogMode()         do { ANSELDbits.ANSELD3 = 1; } while(0)
#define RD3_SetDigitalMode()        do { ANSELDbits.ANSELD3 = 0; } while(0)

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