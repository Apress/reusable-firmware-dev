/****************************************************************************
* Title                 :   Flash
* Filename              :   flash.h
* Author                :   Jacob W. Beningo
* Origin Date           :   01/03/2013
* Version               :   1.0.0
* Compiler              :   TBD
* Target                :   TBD
* Copyright             :   Beningo Engineering
* All Rights Reserved
*
* THIS SOFTWARE IS PROVIDED BY BENINGO ENGINEERING "AS IS" AND ANY EXPRESSED
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL BENINGO ENGINEERING OR ITS CONTRIBUTORS BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
*******************************************************************************/
/****************************************************************************
* Doxygen C Template
* Copyright (c) 2013 - Jacob Beningo - All Rights Reserved
*
* Feel free to use this Doxygen Code Template at your own risk for your own
* purposes.  The latest license and updates for this Doxygen C template can be  
* found at www.beningo.com or by contacting Jacob at jacob@beningo.com.
*
* For updates, free software, training and to stay up to date on the latest 
* embedded software techniques sign-up for Jacobs newsletter at 
* http://www.beningo.com/814-2/
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Template. 
*
*****************************************************************************/
/*************** INTERFACE CHANGE LIST **************************************
*
*    Date    Version   Author         Description 
*  09/01/15   0.5.0   Jacob Beningo   Interface Created.
*  11/10/15   1.0.0   Jacob Beningo   Interface updated.
*
*****************************************************************************/
/** @file flash.h
 *  @brief The interface definition for the flash.
 * 
 *  This is the header file for the definition of the flash driver functions
 */
#ifndef FLASH_H_
#define FLASH_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>				/* For fixed width integer types */
#include "flash_config.h"		/* For Flash_ConfigType definition */

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/


/******************************************************************************
* Configuration Constants
*******************************************************************************/


/******************************************************************************
* Macros
*******************************************************************************/


	
/******************************************************************************
* Typedefs
*******************************************************************************/


/******************************************************************************
* Variables
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void Flash_Init(const Flash_Config_t * Config);
void Flash_Write(uint32_t Address, const uint16_t * Data, uint8_t Size);
void Flash_Read(uint32_t Address, const uint16_t * Data, uint8_t Size);
void Flash_Erase(uint32_t Address);
void Flash_RegisterWrite(uint32_t Address, uint32_t Value);
uint32_t Flash_RegisterRead(uint32_t Address);
void Flash_CallbackRegister(FlashCallback_t Function, TYPE (*CallbackFunction)(type));

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*FLASH_H_*/

/*** End of File **************************************************************/
