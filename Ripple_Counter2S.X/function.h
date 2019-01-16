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
 * Author: A20687
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdbool.h>

#define Forward         0x2
#define Reverse         0x3
#define positionAddr    0xF001

#define POLE    3
#define GearRatio 250
#define RippleCountPerAngle ((float)(1*GearRatio* POLE)/180)

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star

/**
    <p><b>Function prototype: Error_Correction();  </b></p>
  
    <p><b>Summary: This function is responsible for compensating error.</b></p>

    <p><b>Description: Due to formula used in the code, errors are present. </b></p>

    <p><b>Precondition: </b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */

void Error_Correction();
/**
    <p><b>Function prototype: Forward_IOC () </b></p>
  
    <p><b>Summary: This function is for forward direction of motor.     </b></p>

    <p><b>Description:  It configures the CWG into forward direction and sets the SWITCH_TRIGGER. </b></p>

    <p><b>Precondition: The angle must be already specified before calling this function . </b></p>

    <p><b>Parameters:   NONE</b></p>

    <p><b>Returns: NONE </b></p>
   
 */
void Forward_IOC();
/**
    <p><b>Function prototype: Motor_Control() </b></p>
  
    <p><b>Summary: This function is responsible for controlling the motor.     </b></p>

    <p><b>Description:  It includes computation of number of ripples based on the desired angle and controls the motor direction. </b></p>

    <p><b>Precondition: Initialization of all peripherals </b></p>

    <p><b>Parameters:   NONE</b></p>

    <p><b>Returns: NONE </b></p>
   
 */
void Motor_Control();
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
void OverCurrent_Detection();

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
    <p><b>Function prototype: Store() </b></p>
  
    <p><b>Summary: This function is used for storing the angle into EEPROM.  </b></p>

    <p><b>Description:  It stores the scaled value to EEPROM .  </b></p>

    <p><b>Precondition: NONE </b></p>

    <p><b>Parameters:   NONE</b></p>

    <p><b>Returns: NONE </b></p>
 */
void Store();

/**
    <p><b>Function prototype: Reverse_IOC () </b></p>
  
    <p><b>Summary: This function is for reverse direction of motor.     </b></p>

    <p><b>Description:  It configures the CWG into reverse direction and sets the SWITCH_TRIGGER. </b></p>

    <p><b>Precondition: The angle must be already specified before calling this function . </b></p>

    <p><b>Parameters:   NONE</b></p>

    <p><b>Returns: NONE </b></p>
   
 */
void Reverse_IOC();

/**
    <p><b>Function prototype: Reset_Timers() </b></p>
  
    <p><b>Summary: This function is for resetting all TIMERS.     </b></p>

    <p><b>Description: It resets Timer4 and SMT_TIMER registers, also it disables the SMT_GO bit. </b></p>

    <p><b>Precondition: After the capture has been done, or whenever there's a detected fault. </b></p>

    <p><b>Parameters:   NONE</b></p>

    <p><b>Returns: NONE </b></p>
   
 */
void Reset_Timers();

// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation


uint16_t actualRippleCount;
uint16_t ExpectedRippleCount;
uint16_t DesiredAngle;
uint16_t getPOTValue;

float positionMemory = 0;
float scaledReturn = 0;
float scaledLoad = 0;
float difference = 0;
float buffer = 0;
float actualPosition = 0;


bool Switch_Trigger = 0;


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

