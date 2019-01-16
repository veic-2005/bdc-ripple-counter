/**
  MEMORY Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    memory.c

  @Summary
    This is the generated driver implementation file for the MEMORY driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This file provides implementations of driver APIs for MEMORY.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F46Q10
        Driver Version    :  4.20
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB             :  MPLAB X 4.15
*/

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

/**
  Section: Included Files
*/

#include <xc.h>
#include "memory.h"


/**
  Section: Flash Module APIs
*/

uint8_t FLASH_ReadByte(uint32_t flashAddr)
{
    TBLPTRU = (uint8_t)((flashAddr & 0x00FF0000) >> 16);
    TBLPTRH = (uint8_t)((flashAddr & 0x0000FF00)>> 8);
    TBLPTRL = (uint8_t)(flashAddr & 0x000000FF);

    asm("TBLRD");

    return (TABLAT);
}

uint16_t FLASH_ReadWord(uint32_t flashAddr)
{
    // NVMCON1.RD operations are not affected by NVMEN, ignore NVMEN
    NVMADRL = 0xFF & flashAddr;
    NVMADRH = 0xFF & (flashAddr >> 8);
    NVMADRU = 0xFF & (flashAddr >> 16);
    
    NVMCON1bits.RD = 1;
    
    while(NVMCON1bits.RD);    
    
    return ((((uint16_t)NVMDATH) << 8) | NVMDATL);
}

static void WriteSectorToSECRAM(uint32_t flashAddr)
{
    uint8_t GIEBitValue = INTCONbits.GIE;
        
    NVMCON0bits.NVMEN = 1;    // Enable NVM access
    
    // Load 22-bit address
    NVMADRL = 0xFF & (flashAddr);
    NVMADRH = 0xFF & (flashAddr >> 8);
    NVMADRU = 0xFF & (flashAddr >> 16);
    
    // Unlock and launch the transfer from Program Flash Memory to Sector RAM
    INTCONbits.GIE = 0;
    NVMCON2 = 0xBB;
    NVMCON2 = 0x44;
    NVMCON1bits.SECRD = 1;
    
    INTCONbits.GIE = GIEBitValue;
    while(NVMCON1bits.SECRD);
    NVMCON0bits.NVMEN = 0;    // Disable NVM access
}

static void ReadSectorFromSECRAM(uint32_t flashAddr)
{
    uint8_t GIEBitValue = INTCONbits.GIE;
    
    NVMCON0bits.NVMEN = 1;    // Enable NVM access
    
    // Load 22-bit address
    NVMADRL = 0xFF & (flashAddr);
    NVMADRH = 0xFF & (flashAddr >> 8);
    NVMADRU = 0xFF & (flashAddr >> 16);
    
    // Unlock and launch the transfer from SECRAM to PFM
    INTCONbits.GIE = 0;
    NVMCON2 = 0xDD;
    NVMCON2 = 0x22;
    NVMCON1bits.SECWR = 1;
    
    INTCONbits.GIE = GIEBitValue;
    while(NVMCON1bits.SECWR);
    NVMCON0bits.NVMEN = 0;    // Disable NVM access
}

uint8_t secram __at(0xD00);
void FLASH_WriteWord(uint32_t flashAddr, uint16_t word)
{
    uint16_t *secramWordPtr = (uint16_t*)&secram;
    uint32_t sectorStartAddr = (uint32_t)(flashAddr & ((END_FLASH - 1) ^ ((ERASE_FLASH_SECTORSIZE * 2) - 1)));
    uint8_t offset = (uint8_t)((flashAddr & ((ERASE_FLASH_SECTORSIZE * 2) - 1)) / 2);
        
    // Write one Sector from Program Flash Memory to SECRAM
    WriteSectorToSECRAM(sectorStartAddr);
    
    // Erase PFM Sector
    FLASH_EraseSector(sectorStartAddr);
    
    // Modify SECRAM contents for requested word
    secramWordPtr+=offset;
    *secramWordPtr = word;
    
    // Read SECRAM contents to Program Flash Memory
    ReadSectorFromSECRAM(sectorStartAddr);
}

uint16_t FLASH_WriteByteToSECRAM(uint8_t byte)
{
    uint8_t GIEBitValue = INTCONbits.GIE;
    uint8_t *secramBytePtr = &secram;
    static uint16_t currAddrOffset = 0;
    
    INTCONbits.GIE = 0;    // Disable interrupts
    
    // Reset address offset to zero if it reaches end of SECRAM region
    if(currAddrOffset == (ERASE_FLASH_SECTORSIZE*2))
    {
        currAddrOffset = 0;
    }
    
    // Copy received byte to current SECRAM address
    // And increment offset to point to next SECRAM address
    if(currAddrOffset <= ((ERASE_FLASH_SECTORSIZE*2)-1))
    {
        secramBytePtr += currAddrOffset++;
        *secramBytePtr = byte;
    }
    
    INTCONbits.GIE = GIEBitValue;
    
    return currAddrOffset;
}

uint8_t FLASH_WriteSector(uint32_t flashAddr)
{
    uint32_t sectorStartAddr = (uint32_t)(flashAddr & ((END_FLASH - 1) ^ ((ERASE_FLASH_SECTORSIZE * 2) - 1)));
    
    // Return error status if given flash address doesn't point to start of sector
    if(flashAddr != sectorStartAddr)
    {
        return 1;
    }
    
    FLASH_EraseSector(flashAddr);
    
    // Retrieve SECRAM contents to given Program Flash Memory sector
    ReadSectorFromSECRAM(flashAddr);
    
    return 0;
}

void FLASH_EraseSector(uint32_t flashAddr)
{
    uint8_t GIEBitValue = INTCONbits.GIE;
    
    NVMCON0bits.NVMEN = 1;    // Enable NVM access
    
    // Load 22-bit address
    NVMADRL = 0xFF & (flashAddr);
    NVMADRH = 0xFF & (flashAddr >> 8);
    NVMADRU = 0xFF & (flashAddr >> 16);
    
    // Unlock and launch the erase operation
    INTCONbits.GIE = 0;    // Disable interrupts
    NVMCON2 = 0xCC;
    NVMCON2 = 0x33;
    NVMCON1bits.SECER = 1;
    
    INTCONbits.GIE = GIEBitValue;
    while(NVMCON1bits.SECER);
    NVMCON0bits.NVMEN = 0;    // Disable NVM access
}

/**
  Section: Data EEPROM Module APIs
*/

void DATAEE_WriteByte(uint8_t bAdd, uint8_t bData)
{
    uint8_t GIEBitValue = INTCONbits.GIE;
    
    // Load address
    NVMADRL = (uint8_t)(bAdd & 0xFF);
    NVMADRH = 0x00;
    NVMADRU = 0x31;    // Select DATA EE section (0x310000 - 0x3100FF)
    
    // Load data
    NVMDATL = (uint8_t)(bData & 0xFF);
    
    NVMCON0bits.NVMEN = 1;    // Enable NVM access
    INTCONbits.GIE = 0;    // Disable interrupts
    
    NVMCON2 = 0x55;
    NVMCON2 = 0xAA;
    NVMCON1bits.WR = 1;
    while(NVMCON1bits.WR);    
       
    INTCONbits.GIE = GIEBitValue;    
    NVMCON0bits.NVMEN = 0;    // Disable NVM access 
}

uint8_t DATAEE_ReadByte(uint8_t bAdd)
{
    // Load address
    NVMADRL = (uint8_t)(bAdd & 0xFF);
    NVMADRH = 0x00;
    NVMADRU = 0x31;    // Select DATA EE section (0x310000 - 0x3100FF)
    
    NVMCON1bits.RD = 1;
    NOP();  // NOPs may be required for latency at high frequencies
    NOP();

    return (NVMDATL);
}

void MEMORY_Tasks( void )
{
    /* TODO : Add interrupt handling code */
    PIR7bits.NVMIF = 0;
}
/**
 End of File
*/