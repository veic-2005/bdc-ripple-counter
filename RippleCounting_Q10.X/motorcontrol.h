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


#define _XTAL_FREQ         16000000
#define MOTOR_MODE         CWG1CON0bits.MODE 
#define StartMotor()       do{CWG1AS0bits.CWG1SHUTDOWN = 0;} while(0)
#define StopMotor()        do{CWG1AS0bits.CWG1SHUTDOWN = 1;} while(0)
#define StartStallTimer()  do{T4CONbits.TMR4ON = 1;} while(0)
#define FORWARD_DIR         0x2
#define REVERSE_DIR         0x3
#define STEER               0x0
#define PR2_VALUE           0x3

#define MOTOR_ADDR00    0x3100F0     //0x310000 to 0x3100FF
#define MOTOR_ADDR01    0x3100F2

#define INITIAL_ADDRESS_VALUE     0xFFFF

//Motor position parameters
#define END_POINT  360
#define HOME     0

bool inputSet = 0;
bool reverseOrigin = 0;

bool getCountDone = 0;
bool forwardDirection = 0;
bool reverseDirection = 0;
bool dummy = 0;

bool motorStalled = 0;

bool homeReached = 1;
bool endPointReached = 0;

uint16_t angleDesired = 0;
uint16_t angleTurned = 0;
uint16_t remainingAngle = END_POINT;
uint16_t totalAngleTurned = 0;

uint16_t compareLoadValue = 0;
uint16_t actualRippleCount = 0;
uint16_t expectedRippleCount = 0;

//Interrupt handlers 
void TMR1_GateSetInterruptHandler(void (*GateInterruptHandler)(void));
void(*TMR1_GateInterruptHandler)(void);

void CCP1_CompareSetInterruptHandler(void (*CompareInterruptHandler)(void));
void(*CCP1_CompareInterruptHandler)(void);

//Below are the list of functions used for handling position
void MotorPosition();
void ForwardPosition();
void ReversePosition();
void StorePosition();
void ReadMotorPositionFromEEPROM();

//Below are the functions used for dealing with the setting of motor parameters and driving it
void CheckHomeButton();
void CheckEndButton();
void CheckForwardButton();
void CheckReverseButton();
void ReadInput();
void Forward_Dir();
void Reverse_Dir();
void BrakingMechanism();
void ResumeMotor();
void StallDetection();

//for counting
void ExpectedRippleCountRemainingAngle();
void ExpectedRippleCountToHome();
void ExpectedRippleCountToEndPoint();
void ExpectedRippleCountfromStall();
void CompareLoadValue();
void Compare_ISR();
void GetAngleTurned();
void StartCounting();

#endif	/* MOTOR_CONTROL_H */

