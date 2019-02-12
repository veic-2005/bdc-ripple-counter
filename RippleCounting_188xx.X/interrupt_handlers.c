
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

#include "mcc_generated_files/interrupt_manager.h"
#include "mcc_generated_files/smt1.h"
#include "mcc_generated_files/smt2.h"
#include "motorcontrol.h"

void SMT1_Overflow_ISR(void)
{
  
    // Disabling SMT1 overflow interrupt flag bit.
    PIR8bits.SMT1IF = 0;
    if(SMT1_InterruptHandler)
    {
        SMT1_InterruptHandler();
    }
}

void SMT1_SetInterruptHandler(void (* GateInterruptHandler)(void))
{
    SMT1_InterruptHandler = GateInterruptHandler;
}

void SMT2_Overflow_ISR(void)
{
  
    // Disabling SMT1 overflow interrupt flag bit.
    PIR8bits.SMT2IF = 0;
    if(SMT2_InterruptHandler)
    {
        SMT2_InterruptHandler();
    }
}

void SMT2_SetInterruptHandler(void (* GateInterruptHandler)(void))
{
    SMT2_InterruptHandler = GateInterruptHandler;
}


