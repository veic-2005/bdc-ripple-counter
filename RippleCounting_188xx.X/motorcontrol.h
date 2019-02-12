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
#define MOTOR01_MODE   CWG1CON0bits.MODE
#define MOTOR02_MODE   CWG2CON0bits.MODE
#define STEER          0x00

#define MOTOR01_ADDR00        0x7000
#define MOTOR01_ADDR01        0x7002
#define MOTOR02_ADDR00        0x7004
#define MOTOR02_ADDR01        0x7006
#define INITIAL_ADDRESS_VALUE 0xFFFF

#define MOTOR01_POLE     3
#define GEAR_RATIO_01    250
#define M1_RIPPLE_COUNT_PER_ANGLE ((float)(1*GEAR_RATIO_01* MOTOR01_POLE)/180)
#define PR4_VALUE       0x22

#define MOTOR02_POLE     3
#define GEAR_RATIO_02    250
#define M2_RIPPLE_COUNT_PER_ANGLE ((float)(1*GEAR_RATIO_02* MOTOR02_POLE)/180)
#define PR6_VALUE       0x22

#define ENDPOINT 360
#define HOME     0

#define StartMotor1()         do{CWG1AS0bits.CWG1SHUTDOWN = 0;} while(0)
#define StartMotor2()         do{CWG2AS0bits.CWG2SHUTDOWN = 0;} while(0)
#define StopMotor1()          do{CWG1AS0bits.CWG1SHUTDOWN = 1;} while(0)
#define StopMotor2()          do{CWG2AS0bits.CWG2SHUTDOWN = 0;} while(0)
#define StartStallTimer4()     do{T4CONbits.TMR4ON = 1;} while(0)
#define StartStallTimer6()     do{T6CONbits.TMR6ON = 1;} while(0)
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
uint16_t actualRippleCount01;
uint16_t actualRippleCount02;

/**
  Section: Dummy Variable Definitions
 */
bool selectMotor = 0;
bool ForwardBtnPressed = 0;
bool ReverseBtnPressed = 0;
bool switchEvent = 0;

bool getCountDone01 = 0;
bool getCountDone02 = 0;
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
void SMT1_SetInterruptHandler(void (*GateInterruptHandler)(void));
void(*SMT1_InterruptHandler)(void);

void SMT2_SetInterruptHandler(void (*GateInterruptHandler)(void));
void(*SMT2_InterruptHandler)(void);
void SMT1_ISR(void);
void SMT2_ISR(void);

void LoadValues(void);
void Compare_ISR(void);
void ExpectedRippleCountRemainingAngle(void);
void ExpectedRippleCountRemainingAngle02(void);
void ExpectedRippleCountToHome(void);
void ExpectedRippleCountToHome02(void);

/**
  Section: Function Declaration for Motor 1 and 2 Drive
 */

void MotorDrive01(void);
void MotorDrive02(void);
void DualMotorDrive(void);
void NextMotor(void);

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

void ReadMotor01PositionFromEEPROM(void);
void ReadMotor02PositionFromEEPROM(void);

/**
  Section: Function Declaration for Checking Buttons
 */

void CheckForwardButton(void);
void CheckReverseButton(void); 
void CheckInputButton(void);

/**
  Section: Function Declaration dealing with Ripple Count
 */
void ReadInput(void);
void MotorInput(void);
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

