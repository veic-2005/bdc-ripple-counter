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
 * File: motorposition.h
 * Author: A20687
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MOTOR_POSITION_H
#define	MOTOR_POSITION_H


#include <xc.h> // include processor files - each processor file is guarded.  
#include "math.h"
/*
 Section: Macro Declaration
 */
#define INITIAL_ADDRESS_VALUE 0xFFFF

#define MOTOR01_POLE     3
#define GEAR_RATIO_01    250
#define M1_RIPPLE_COUNT_PER_ANGLE (round((float)((GEAR_RATIO_01* MOTOR01_POLE)/180)))
#define PR4_VALUE       0x17

#define MOTOR02_POLE     3
#define GEAR_RATIO_02    250
#define M2_RIPPLE_COUNT_PER_ANGLE (round((float)((GEAR_RATIO_02* MOTOR02_POLE)/180)))
#define PR6_VALUE       0x17

#define ENDPOINT 360
#define HOME     0

/**
  Section: Variable Definitions
 */
uint16_t totalAngleTurned01 = 0;
uint16_t totalAngleTurned02 = 0;
uint16_t angleTurned01;
uint16_t angleTurned02;
uint16_t remainingAngle01 = ENDPOINT;
uint16_t remainingAngle02 = ENDPOINT;
/**
  Section: Function Declaration 
 */
void M1_ForwardPosition(void);
void M2_ForwardPosition(void);
void M1_ReversePosition(void);
void M2_ReversePosition(void);
void Motor01Position(void);
void Motor02Position(void);
void ReadMotor01PositionFromEEPROM(void);
void ReadMotor02PositionFromEEPROM(void);

#endif	/* MOTOR_POSITION_H */

