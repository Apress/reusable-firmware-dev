/****************************************************************************
* Title                 :   UART Configuration
* Filename              :   uart_cfg.c
* Author                :   Jacob W Beningo
* Origin Date           :   11/13/2012
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
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Version   Author         Description 
*  09/01/15   1.0.0   Jacob Beningo   Interface Created.
*
*******************************************************************************/
/** 
 * @file uart_cfg.c
 * @brief This module contains the uart configuration code
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "uart_cfg.h"				// For this module's definitions
#include "constants.h"				// For DISABLED, ENABLED, etc

/******************************************************************************
* Constants
*******************************************************************************/

/******************************************************************************
* Configuration
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
/**
* This configuration table is used to configure the behavior and function of 
* the timers.  The channels are defined in tmr_cfg.h.  The configuration
* consists of  
*
*  o Uart Name - Specify the name of the uart. This label must be defined in
*      the Uart_RegisterType enumeration.
*  o Uart Enable - Specify whether the uart channel is enabled.
*  o Uart Mode - Specify the mode of the UCSI channel.
*	  UART - Standard UART mode
*	  IDLE_LINE - Idle-line multiprocessor mode
*	  ADDR_BIT - Address-bit multiprocessor mode
*	  UART_AUTO - UART mode with automatic baud rate detection
*  o Clock Source - Choose the UART clock source.
*  o Baud Rate - Specify the desired baud rate for the uart channel.
*  o Loopback - Enable or disable loopback mode
*  o Bit Direction - Specify the bit ordering for uart receive and transmit shift registers.
*     LEAST_FIRST - Least significant bit first
*     MOST_FIRST - Most significant bit first
*  o Data Length - Specify the character length, 7- or 8-bits. 
*  o Data Length - Specify the number of stop bits, 1 or 2. 
*  o Parity Type - Specify whether the uart parity is ODD, EVEN, or DISABLED.
*  o AutoBaud Enable - Enable or Disable automatic baud rate detection.
*  o Delimiter - Specify the break/synch delimiter length for auto baud detection.
*  o Interrupt Enable - This sets whether the receive interrupt for this uart is enabled.
*     DISABLED  - Disable the UART interrupts
*     RX_ONLY - Enable receive interrupt, transmit interrupt disabled
*     TX_ONLY - Enable transmit interrupt, receive interrupt disabled
*     RX_TX - Enable both receive and transmit interrupts
*
*  UART_0 and UART_1 channels are shared with the SPIA_0 and SPIA_1 channel.
*  Only one of them can be enabled on a channel at a time.
*******************************************************************************/
const UartConfig_t UartConfig[] =
{
//	  Uart		UART		Uart	Clock	   Baud				    	 Bit    	  Data	    Stop 	Parity     		   		Interrupt
//    Name		Enable   	Mode	Source	   Rate	     Loopback     Direction	     Length     Bits	 Type		Delimiter	Enable
//
	{UART_0,	ENABLED, 	UART,  	SUBMCLK,   115200, DISABLED,	 UART_LSB_FIRST,   BITS_EIGHT,	  1,	DISABLED,  		1,	    DISABLED  },
	{UART_1,	DISABLED,	UART,  	SUBMCLK,   115200, DISABLED,	 UART_LSB_FIRST,   BITS_EIGHT,     1,	DISABLED,  		1,	    DISABLED  },
	{UART_2,	DISABLED,	UART,  	SUBMCLK,   115200, DISABLED,	 UART_LSB_FIRST,   BITS_EIGHT,     1,	DISABLED,  		1,	    DISABLED  },
};

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : Uart_ConfigGet()
*//** 
* \b Description:
*
* This function is used to initialize the uart based on the configuration table
*  defined in this module.  
*
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
*
* POST-CONDITION: A constant pointer to the first member of the configuration
* table will be returned.
*
* @return 		A pointer to the configuration table.
*
* \b Example Example:
* @code
* 	const UartConfig_t *UartConfig = Uart_ConfigGet();
*
* 	Uart_Init(UartConfig);
* @endcode
*
* @see Uart_Init
* @see Uart_ParitySet
* @see Uart_IsrModeSet
* @see Uart_BaudRateSet
* @see Uart_CharGet
* @see Uart_IsDataPresent
* @see Uart_CharPut
* @see Uart_RegisterWrite
* @see Uart_RegisterWrite
* @see Uart_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 1.0.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
const UartConfig_t *Uart_ConfigGet(void)
{
	return UartConfig;
}

/*** End of File **************************************************************/

