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

#include <xc.h> // include processor files - each processor file is guarded.  

/**Macro Declaration */
#define Forward         1
#define Reverse         0
#define Forward_Dir         0x2
#define Reverse_Dir         0x3

#define PRESSED             1
#define NOT_PRESSED         0
#define RUNNING             1
#define NOT_RUNNING         0

#define Motor01Addr00    0x7001
#define Motor01Addr01    0x7002
#define Motor01Addr02    0x7003
#define Motor02Addr00    0x7004
#define Motor02Addr01    0x7005
#define Motor02Addr02    0x7006
#define maxValue         0xFFFF

#define POLE    3
#define GearRatio 250
#define RippleCountPerAngle ((float)(1*GearRatio* POLE)/180)
#define StartMotor1()         do{CWG1CON0bits.CWG1EN = 1;} while(0)
#define StartMotor2()         do{CWG2CON0bits.CWG2EN = 1;} while(0)
#define StopMotor1()          do{CWG1CON0bits.CWG1EN = 0;} while(0)
#define StopMotor2()          do{CWG2CON0bits.CWG2EN = 0;} while(0)
/**
  Section: Variable Definitions
 */

uint16_t actualPosition01 = 0;
uint16_t actualPosition02 = 0;
uint16_t actualRippleCount01;
uint16_t actualRippleCount02;
uint16_t DesiredAngle;
uint16_t difference = 0;
uint16_t ExpectedRippleCount01;
uint16_t ExpectedRippleCount02;
uint16_t getPOTValue;
uint16_t positionMemory = 0;
uint16_t positionMemory02 = 0;

uint8_t labNumber = 0;
uint8_t switchEvent = 0;
uint8_t labState = NOT_RUNNING;
uint8_t btnState = NOT_PRESSED;   

bool rotateDirection = 0;
bool Switch_Trigger = 0;

//float difference = 0;
float buffer01 = 0;
float buffer02 = 0;


void expRippleCount();
/**
    <p><b>Function prototype: Motor_Drive() </b></p>
  
    <p><b>Summary: This function is responsible for controlling the motor.     </b></p>

    <p><b>Description:  It includes computation of number of ripples based on the desired angle and controls the motor direction. </b></p>

    <p><b>Precondition: Initialization of all peripherals </b></p>

    <p><b>Parameters:   NONE</b></p>

    <p><b>Returns: NONE </b></p>
   
 */
void Motor_Drive01();
/**
    <p><b>Function prototype: Motor_Drive() </b></p>
  
    <p><b>Summary: This function is responsible for controlling the motor.     </b></p>

    <p><b>Description:  It includes computation of number of ripples based on the desired angle and controls the motor direction. </b></p>

    <p><b>Precondition: Initialization of all peripherals </b></p>

    <p><b>Parameters:   NONE</b></p>

    <p><b>Returns: NONE </b></p>
   
 */
void Motor_Drive02();
/**
    <p><b>Function prototype: Motor_Drive() </b></p>
  
    <p><b>Summary: This function is responsible for controlling the motor.     </b></p>

    <p><b>Description:  It includes computation of number of ripples based on the desired angle and controls the motor direction. </b></p>

    <p><b>Precondition: Initialization of all peripherals </b></p>

    <p><b>Parameters:   NONE</b></p>

    <p><b>Returns: NONE </b></p>
   
 */
void Motor_Drive03();

/**
   <p><b>Function prototype: MotorStall_Detection() </b></p>
  
    <p><b>Summary: This function is for detecting the stall.     </b></p>

    <p><b>Description:  It is used as a trigger to shutdown the CWG, store the current position and lights up the stall LED. </b></p>

    <p><b>Precondition: NONE </b></p>

    <p><b>Parameters:   NONE</b></p>

    <p><b>Returns: NONE </b></p>
   
 */
void MotorStall_Detection();
/**
   <p><b>Function prototype: OverCurrent_Detection() </b></p>
  
    <p><b>Summary: This function is for detecting the overcurrent condition.     </b></p>

    <p><b>Description:  It is used as a trigger to shutdown the CWG, store the current position and lights up the overcurrent LED indicator.  </b></p>

    <p><b>Precondition: NONE </b></p>

    <p><b>Parameters:   NONE</b></p>

    <p><b>Returns: NONE </b></p>
   
 */
void OverCurrent_Detection01();
void OverCurrent_Detection02();

/**
   <p><b>Function prototype: Position_Retention() </b></p>
  
    <p><b>Summary: This function is wholly dedicated for calculating and storing the angle into EEPROM.  </b></p>

    <p><b>Description:  It tests whether the direction is forward or reverse, scaled down the angle and then stored it into EEPROM .  </b></p>

    <p><b>Precondition: The number of ripples must be captured already. </b></p>

    <p><b>Parameters:   NONE    </b></p>

    <p><b>Returns: NONE     </b></p>
   
 */
void Position_Retention();

/**
    <p><b>Function prototype: SMT1_Resets() </b></p>
  
    <p><b>Summary: This function is for resetting the TIMER register and disabling the data acquisition.     </b></p>

    <p><b>Description: It resets Timer4 and SMT_TIMER registers, also it disables the SMT_GO bit. </b></p>

    <p><b>Precondition: After the capture has been done, or whenever there's a detected fault. </b></p>

    <p><b>Parameters:   NONE</b></p>

    <p><b>Returns: NONE </b></p>
   
 */
void SMT1_Resets();
void SMT2_Resets();
/**
    <p><b>Function prototype: Store() </b></p>
  
    <p><b>Summary: This function is used for storing the angle into EEPROM.  </b></p>

    <p><b>Description:  It stores the scaled value to EEPROM .  </b></p>

    <p><b>Precondition: NONE </b></p>

    <p><b>Parameters:   NONE</b></p>

    <p><b>Returns: NONE </b></p>
 */
void Store();



#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

