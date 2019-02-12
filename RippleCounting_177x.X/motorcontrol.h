/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MOTOR_CONTROL_H
#define	MOTOR_CONTROL_H

#include <stdint.h>
#include <xc.h> // include processor files - each processor file is guarded.  

/**Macro Declaration */


#define FORWARD_DIR        0x2
#define REVERSE_DIR        0x3
#define MOTOR01_MODE   COG1CON0bits.MD
#define MOTOR02_MODE   COG3CON0bits.MD
#define STEER          0x00;

#define MOTOR01_ADDR00        0x3F80
#define MOTOR02_ADDR00        0x3F83
#define INITIAL_ADDRESS_VALUE 0x3FFF


#define ENDPOINT 360
#define HOME     0

#define StartMotor1()         do{COG1ASD0bits.G1ASE = 0;} while(0)
#define StartMotor2()         do{COG3ASD0bits.G3ASE = 0;} while(0)
#define StopMotor1()          do{COG1ASD0bits.G1ASE = 1;} while(0)
#define StopMotor2()          do{COG3ASD0bits.G3ASE = 0;} while(0)
#define StartStallTimer()     do{T4CONbits.TMR4ON = 1;} while(0)

/**
  Section: Variable Definitions
 */

uint16_t totalAngleTurned01 = 0;
uint16_t totalAngleTurned02 = 0;
uint16_t angleTurned01;
uint16_t angleTurned02;

uint16_t remainingAngle01 = ENDPOINT;
uint16_t remainingAngle02 = ENDPOINT;
uint16_t angleDesired;
uint16_t expectedRippleCount;
uint16_t actualRippleCount;
uint16_t timer1Value;

/**
  Section: Dummy Variable Definitions
 */
bool motor01 = 1;

bool getCountDone = 0;
bool faultDetected = 0;
bool forwardDirection = 0;
bool reverseDirection = 0;
bool reverseOrigin = 0;

/**
  Section: Function Declaration for Safety Features
 */
void StallDetection(void);
void OvercurrentDetection(void);
void ResumeMotor(void);

/**
  Section: Interrupt handler Declarations
 */
void TMR1_GateSetInterruptHandler(void (*GateInterruptHandler)(void));
void(*TMR1_GateInterruptHandler)(void);

void CCP1_CompareSetInterruptHandler(void (*CompareInterruptHandler)(void));
void(*CCP1_CompareInterruptHandler)(void);

void CMP3_SetInterruptHandler(void (*InterruptHandler)(void));
void(*CMP3_InterruptHandler)(void);

void LoadValues(void);
void Compare_ISR(void);
void ExpectedRippleCountRemainingAngle(void);
void ExpectedRippleCountRemainingAngle02(void);
void  ExpectedRippleCountToHome(void);
void  ExpectedRippleCountToHome02(void);

/**
  Section: Function Declaration for Motor 1 and 2 Drive
 */

void Motor01Forward_Drive(void);
void Motor01Reverse_Drive(void);
void Motor02Forward_Drive(void);
void Motor02Reverse_Drive(void);

/**
  Section: Function Declaration dealing with Motors Position
 */
void M1_ForwardPosition(void);
void M2_ForwardPosition(void);
void M1_ReversePosition(void);
void M2_ReversePosition(void);

void Motor01Position(void);
void BrakingMechanism(void);
void Motor02Position(void);
void BrakingMechanism02(void);

void ReadMotor01PositionFromHEF(void);
void ReadMotor02PositionFromHEF(void);

/**
  Section: Function Declaration for Checking Buttons
 */

void CheckM1ForwardButton(void);
void CheckM1ReverseButton(void); 
void CheckM2ForwardButton(void);
void CheckM2ReverseButton(void);

/**
  Section: Function Declaration dealing with Ripple Count
 */
void ReadInput(void);
void CompareLoadValue(void);
uint16_t GetActualRippleCount(void);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

