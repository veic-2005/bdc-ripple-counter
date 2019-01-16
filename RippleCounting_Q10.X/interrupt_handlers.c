
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

#include "mcc_generated_files/ccp1.h"
#include "mcc_generated_files/interrupt_manager.h"
#include "mcc_generated_files/tmr1.h"
#include "motorcontrol.h"

void TMR1_GATE_ISR(void)
{
    PIR5bits.TMR1GIF = 0;
        if(TMR1_GateInterruptHandler)
    {
        TMR1_GateInterruptHandler();
    }
}

void TMR1_GateSetInterruptHandler(void (* GateInterruptHandler)(void))
{
    TMR1_GateInterruptHandler = GateInterruptHandler;
}

void CCP1_CompareISR(void)
{
    PIR6bits.CCP1IF = 0;
        if(CCP1_CompareInterruptHandler)
    {
        CCP1_CompareInterruptHandler();
    }
}

void CCP1_CompareSetInterruptHandler(void (* CompareInterruptHandler)(void))
{
    CCP1_CompareInterruptHandler = CompareInterruptHandler;
}