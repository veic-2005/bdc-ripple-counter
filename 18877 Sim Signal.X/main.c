/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F18877
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "Motor_Control.h"

#define SWITCH_S1_TTL()    do { INLVLBbits.INLVLB0 =0; } while(0)

void checkButtonS3(void);
void nextMotor(void);

/*
                         Main application
 */

void main(void) {
    SWITCH_S1_TTL();
    
    SYSTEM_Initialize();
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    
    TMR4_SetInterruptHandler(MotorStall_Detection);
    TMR1_SetInterruptHandler(OverCurrent_Detection01);
    TMR3_SetInterruptHandler(OverCurrent_Detection02);
       
    while (1) {
        positionMemory = ((DATAEE_ReadByte(Motor01Addr00) | (DATAEE_ReadByte(Motor01Addr01)) << 8));
        positionMemory02 = ((DATAEE_ReadByte(Motor02Addr00) | (DATAEE_ReadByte(Motor02Addr01)) << 8));
        printf("Position = %u \n\r", positionMemory);
        printf("Position02 = %u \n\r", positionMemory02);
        
        if((positionMemory < maxValue) && (positionMemory02 < maxValue)){
        actualPosition01 = positionMemory;
        actualPosition02 = positionMemory02;
        }
        
//        checkButtonS3();
//        switch(labNumber){
        
//            case 1:     Motor_Drive01();    break;
//            case 2:     Motor_Drive02();    break;
//            case 3:     
                Motor_Drive03();   
//                break;
        }
//        if(switchEvent){
//            nextMotor();
//        }
//    }
}

void checkButtonS3(void){
    if(btnState == NOT_PRESSED){
        if(S3_PORT == LOW){  
            __delay_ms(100);
            btnState = PRESSED;
        }
    }else if(S3_PORT == HIGH){
            btnState = NOT_PRESSED;   
            switchEvent = 1;                                                   
    }
}

void nextMotor(void) {
    switchEvent = 0; 
    labNumber++;                                                        

    if (labNumber > 3) {
        labNumber = 1;
    }
}

/**
 End of File
 */