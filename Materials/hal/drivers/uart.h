/****************************************************************************
* Title                 :   UART Header File
* Filename              :   uart.h
* Author                :   Jacob W. Beningo
* Origin Date           :   08/09/12
* Version               :   1.0.0
* Compiler              :   TBD
* Target                :   TBD 
* Copyright             :   Beningo Engineering
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
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Version   Author         Description 
*  09/01/15   0.5.0   Jacob Beningo   Interface Created.
*  11/10/15   1.0.0   Jacob Beningo   Interface updated
*
*******************************************************************************/
/** @file uart.h
 *  @brief The interface definition for the uart.
 */
#ifndef UART_H_
#define UART_H_
 /******************************************************************************
* Includes
*******************************************************************************/
#include "uart_cfg.h"			/* For uart configuration */
#include <stdint.h>				/* For fixed width integer types */

/******************************************************************************
* Constants
*******************************************************************************/
/**
 * Defines the number of entries in the UartBaudTable array
 */
#define NUM_BAUD_TABLE		(sizeof(UartBaudTable)/sizeof(UartBaud_t))

/******************************************************************************
* Configuration
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/
/**
 * Defines the uart configuration table elements that are used
 * by Uart_Init to configure the uart registers.
 */
typedef struct 
{
	uint32_t ClkFreq;			/**< System Clock Frequency */
	uint32_t BaudRate;			/**< Desired Baud Rate */
	uint8_t UCBRx;				/**< Value of UCBRx register bits */
	uint8_t UCBRSx;				/**< Value of UCBRSx register bits */
	uint8_t UCBRFx;				/**< Value of UCBRFx register bits */
	uint8_t Oversampling;		/**< Oversampling mode ENABLED or DISABLED */
}UartBaud_t;

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void Uart_Init(const UartConfig_t * Config);
void Uart_BaudRateSet(UartChannel_t Channel, const UartConfig_t * Config);
uint8_t Uart_CharGet(UartChannel_t Channel);
void Uart_CharPut(UartChannel_t Channel, char Ch);
uint8_t Uart_IsDataPresent(UartChannel_t Channel);
void Uart_RegisterWrite(uint32_t Address, uint32_t Value);
uint32_t Uart_RegisterRead(uint32_t Address);
void Uart_CallbackRegister(UartCallback_t Function, TYPE (*CallbackFunction)(type));

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*UART_H_*/

/*** End of File **************************************************************/

