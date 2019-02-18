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
 * File: motorcontrol.h
 * Author: A20687
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MOTOR_CONTROL_H
#define	MOTOR_CONTROL_H


#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
/**
 * Macro Declaration 
 */
#define FORWARD_DIR        0x2
#define REVERSE_DIR        0x3
#define MOTOR01_MODE    CWG1CON0bits.MODE
#define MOTOR02_MODE    CWG2CON0bits.MODE
#define STEER           0x00

#define StartMotor1()         do{CWG1AS0bits.CWG1SHUTDOWN = 0;} while(0)
#define StartMotor2()         do{CWG2AS0bits.CWG2SHUTDOWN = 0;} while(0)
#define StopMotor1()          do{CWG1AS0bits.CWG1SHUTDOWN = 1;} while(0)
#define StopMotor2()          do{CWG2AS0bits.CWG2SHUTDOWN = 0;} while(0)
#define StartStallTimer4()     do{T4CONbits.TMR4ON = 1;} while(0)
#define StartStallTimer6()     do{T6CONbits.TMR6ON = 1;} while(0)

/**
  Section: Variable Declaration
 */
uint16_t angleDesired;
uint16_t expectedRippleCount;
uint16_t actualRippleCount01;
uint16_t actualRippleCount02;

bool selectMotor = 0;
bool ForwardBtnPressed = 0;
bool ReverseBtnPressed = 0;

bool getCountDone01 = 0;
bool getCountDone02 = 0;
bool forwardDirection = 0;
bool reverseDirection = 0;
bool reverseOrigin = 0;

bool motor01Stalled = 0;
bool motor02Stalled = 0;

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

/**
  Section: Function Declaration for Motor 1 and 2 Drive
 */
void InitiateDrive01(void);
void InitiateDrive02(void);
void MotorDrive01(void);
void MotorDrive02(void);
void DualMotorDrive(void);
void ResumeMotor01(void);
void ResumeMotor02(void);
void BrakingMechanism(void);
void BrakingMechanism02(void);

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
void LoadValues(void);
void Compare_ISR(void);
void ExpectedRippleCountRemainingAngle(void);
void ExpectedRippleCountRemainingAngle02(void);
void ExpectedRippleCountToHome(void);
void ExpectedRippleCountToHome02(void);

#endif	/*MOTOR_CONTROL_H */

