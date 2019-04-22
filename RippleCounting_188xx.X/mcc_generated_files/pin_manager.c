/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F18877
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB             :  MPLAB X 5.10

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
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

#include "pin_manager.h"





void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATE = 0x00;
    LATD = 0x00;
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISE = 0x07;
    TRISA = 0xFB;
    TRISB = 0x03;
    TRISC = 0x17;
    TRISD = 0xE2;

    /**
    ANSELx registers
    */
    ANSELD = 0x80;
    ANSELC = 0x24;
    ANSELB = 0x02;
    ANSELE = 0x07;
    ANSELA = 0x1B;

    /**
    WPUx registers
    */
    WPUD = 0x00;
    WPUE = 0x00;
    WPUB = 0x00;
    WPUA = 0x00;
    WPUC = 0x00;

    /**
    ODx registers
    */
    ODCONE = 0x00;
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;
    ODCOND = 0x00;

    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x07;





   
    
	
    SSP1CLKPPS = 0x13;   //RC3->MSSP1:SCK1;    
    RB6PPS = 0x07;   //RB6->CWG1:CWG1C;    
    RC3PPS = 0x14;   //RC3->MSSP1:SCK1;    
    RB7PPS = 0x08;   //RB7->CWG1:CWG1D;    
    RB5PPS = 0x06;   //RB5->CWG1:CWG1B;    
    RB4PPS = 0x05;   //RB4->CWG1:CWG1A;    
    T6AINPPS = 0x1E;   //RD6->TMR6:T6IN;    
    SSP1DATPPS = 0x14;   //RC4->MSSP1:SDI1;    
    RD2PPS = 0x1D;   //RD2->CWG2:CWG2B;    
    SMT2WINPPS = 0x1D;   //RD5->SMT2:SMT2WIN;    
    RD4PPS = 0x1F;   //RD4->CWG2:CWG2D;    
    SMT1WINPPS = 0x10;   //RC0->SMT1:SMT1WIN;    
    T4AINPPS = 0x11;   //RC1->TMR4:T4IN;    
    RD3PPS = 0x1E;   //RD3->CWG2:CWG2C;    
    SMT1SIGPPS = 0x11;   //RC1->SMT1:SMT1SIG;    
    RC5PPS = 0x15;   //RC5->MSSP1:SDO1;    
    RC6PPS = 0x10;   //RC6->EUSART:TX;    
    RC7PPS = 0x1C;   //RC7->CWG2:CWG2A;    
    SMT2SIGPPS = 0x1E;   //RD6->SMT2:SMT2SIG;    
}
  
void PIN_MANAGER_IOC(void)
{   
}

/**
 End of File
*/