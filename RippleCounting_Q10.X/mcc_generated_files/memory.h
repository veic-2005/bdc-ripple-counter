/**
  MEMORY Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    memory.h

  @Summary
    This is the generated header file for the MEMORY driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs.

  @Description
    This header file provides APIs for driver for MEMORY.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F46Q10
        Driver Version    :  4.20
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB             :  MPLAB X 4.15
*******************************************************************************/

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

#ifndef MEMORY_H
#define MEMORY_H

/**
  Section: Included Files
*/

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: Macro Declarations
*/

#define WRITE_FLASH_SECTORSIZE    128
#define ERASE_FLASH_SECTORSIZE    128
#define END_FLASH                 0x010000

/**
  Section: Flash Module APIs
*/

/**
  @Summary
    Reads a data byte from Program Flash Memory

  @Description
    This routine reads a data byte from given Program Flash Memory address

  @Preconditions
    None

  @Param
    flashAddr - Program Flash Memory location from which data has to be read

  @Returns
    Data byte read from given Program Flash Memory address

  @Example
    <code>
    uint8_t    readByte;
    uint32_t    flashAddr = 0x7D00;

    readByte = FLASH_ReadByte(flashAddr);
    </code>
*/
uint8_t FLASH_ReadByte(uint32_t flashAddr);

/**
  @Summary
    Reads a data word from Program Flash Memory

  @Description
    This routine reads a data word from given Program Flash Memory address    

  @Preconditions
    None

  @Param
    flashAddr - Program Flash Memory location from which data has to be read

  @Returns
    Data word read from given Program Flash Memory address

  @Example
    <code>
    uint16_t    readWord;
    uint32_t    flashAddr = 0x7D00;

    readWord = FLASH_ReadWord(flashAddr);
    </code>
*/
uint16_t FLASH_ReadWord(uint32_t flashAddr);

/**
  @Summary
    Writes a word into Flash

  @Description
    This routine writes the given word into mentioned Program Flash Memory address

  @Preconditions
    None

  @Param
    flashAddr        - Flash program memory location to which data has to be written
    word             - Word to be written in Flash

  @Returns
    None

  @Example
    <code>
    uint32_t    flashAddr = 0x1E00;
    uint16_t    word = 0x55AA;

    FLASH_WriteWord(flashAddr, word);
    </code>
*/
void FLASH_WriteWord(uint32_t flashAddr, uint16_t word);

/**
  @Summary
    Writes a byte to SECRAM

  @Description
    This routine writes a byte to SECRAM

  @Preconditions
    None

  @Param
    byte - byte to be written to SECRAM

  @Returns
    Number of bytes already written to SECRAM

  @Example
    <code>
    uint8_t secramOffset;
    uint32_t flashAddr;
    
    while(1)
    {
        :
        :
        :
        secramOffset = FLASH_WriteByteToSECRAM(EUSART_Read());
        if(secramOffset == (ERASE_FLASH_SECTORSIZE*2))
        {
            // SECRAM is filled with data received over serial port
            // Bring the SECRAM contents to Program Flash Memory
            FLASH_WriteSector(flashAddr);
            secramOffset = 0;
        }
    }
    </code>
*/
uint16_t FLASH_WriteByteToSECRAM(uint8_t byte);

/**
  @Summary
    Retrieves SECRAM to Program Flash Memory

  @Description
    This routine retrieves existing SECRAM contents to specified Program Flash Memory Sector

  @Preconditions
    Fill SECRAM with FLASH_WriteByteToSECRAM(byte) function

  @Param
    flashAddr - starting address of program Flash Memory Sector where SECRAM contents to be retrieved

  @Returns
    Status of operation. 0: SUCCESS, 1: FAILURE

  @Example
    <code>
    uint8_t secramOffset;
    uint32_t flashAddr;
    
    while(1)
    {
        :
        :
        :
        secramOffset = FLASH_WriteByteToSECRAM(EUSART_Read());
        if(secramOffset == (ERASE_FLASH_SECTORSIZE*2))
        {
            // SECRAM is filled with data received over serial port
            // Bring the SECRAM contents to Program Flash Memory
            FLASH_WriteSector(flashAddr);
            secramOffset = 0;
        }
    }
    </code>
*/
uint8_t FLASH_WriteSector(uint32_t flashAddr);

/**
  @Summary
    Erases a data sector from Program Flash Memory

  @Description
    This routine erases the given Program Flash Memory sector

  @Preconditions
    None

  @Param
    flashAddr - Flash program memory location which belongs to the sector to be erased

  @Returns
    None

  @Example
    <code>
    uint32_t    flashAddr = 0x1E00;

    FLASH_EraseSector(flashAddr);
    </code>
*/
void FLASH_EraseSector(uint32_t flashAddr);

/**
  @Summary
    Writes a data byte to EEPROM

  @Description
    This routine writes a data byte to given EEPROM address

  @Preconditions
    None

  @Param
    bAdd  - EEPROM location to which data has to be written
    bData - Data to be written to EEPROM address

  @Returns
    None

  @Example
    <code>
    uint8_t bAdd = 0x10;
    uint8_t bData = 0x55;

    DATAEE_WriteByte(dataeeAddr, dataeeData);
    </code>
*/
void DATAEE_WriteByte(uint8_t bAdd, uint8_t bData);

/**
  @Summary
    Reads a data byte from EEPROM

  @Description
    This routine reads a data byte from given EEPROM address

  @Preconditions
    None

  @Param
    bAdd  - EEPROM address from which data has to be read

  @Returns
    Data byte read from given EEPROM address

  @Example
    <code>
    uint8_t readData;
    uint8_t bAdd = 0x10;
    
    readData = DATAEE_ReadByte(bAdd);
    </code>
*/
uint8_t DATAEE_ReadByte(uint8_t bAdd);

void MEMORY_Tasks(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // MEMORY_H
/**
 End of File
*/

