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
 * File:  motorcontrol.h
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
#include <stdbool.h>
#include <stdlib.h>

/*
 Section: Macro Declaration
 */
#define StopMotor()        do{CWG1AS0bits.CWG1SHUTDOWN = 1;} while(0)
#define StartMotor()       do{CWG1AS0bits.CWG1SHUTDOWN = 0;} while(0)
#define StartStallTimer()  do{T4CONbits.TMR4ON = 1;} while(0)

/**
  Section : Motor Position parameters
 */
#define END_POINT  360
#define HOME     0

/**
 * Section: Variable Declaration
 */
uint16_t angleDesired = 0;
uint16_t angleTurned = 0;
uint16_t remainingAngle = END_POINT;
uint16_t totalAngleTurned = 0;

bool inputSet = 0;
bool dummy = 0;
bool reverseOrigin = 0;
bool getCountDone = 0;
bool forwardDirection = 0;
bool reverseDirection = 0;
bool motorStalled = 0;
bool endPointReached = 0;

/**
 Section: Interrupt handlers
 */
void TMR1_GateSetInterruptHandler(void (*GateInterruptHandler)(void));
void(*TMR1_GateInterruptHandler)(void);

void CCP1_CompareSetInterruptHandler(void (*CompareInterruptHandler)(void));
void(*CCP1_CompareInterruptHandler)(void);

/**
 Section: Position Handling Functions
 */
void MotorPosition(void);
void StorePosition(void);
void ReadMotorPositionFromEEPROM(void);

/**
 Section: Functions for Setting Motor Parameters and Motor Drive
 */
void CheckHomeButton(void);
void CheckEndButton(void);
void CheckForwardButton(void);
void CheckReverseButton(void);
void ReadInput(void);
void Forward_Dir(void);
void Reverse_Dir(void);
void BrakingMechanism(void);
void ResumeMotor(void);
void StallDetection_Initialize(void);

/**
 * Section: Function declaration for Counting Ripples
 */
void ExpectedRippleCountRemainingAngle(void);
void ExpectedRippleCountToHome(void);
void ExpectedRippleCountToEndPoint(void);
void CompareLoadValue(void);
void Compare_ISR(void);
void GetAngleTurned(void);
void Compare_Initialize(void);
void StartCounting(void);
#endif	/* MOTOR_CONTROL_H */

