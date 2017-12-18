/****************************************************************************
* Title                 :   UART Configuration
* Filename              :   uart_cfg.h
* Author                :   Jacob W. Beningo
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
/** \file uart_cfg.h
 * \brief This file contains the header definitions for the uart configuration.
 */ 
#ifndef UART_CFG_H_
#define UART_CFG_H_
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>		// For fixed width intger types

/******************************************************************************
* Constants
*******************************************************************************/
/**
 * Defines the available BRCLK source selections.
 */
typedef enum 
{
	UCLK,			/**< U Clock */
	ACLOCK,			/**< Auxilary Clock */
	SUBMCLK			/**< Sub-System Master Clock */
}UartClkSrc_t;

/**
 * Defines the uart parity selections.  
 */
typedef enum 
{
	ODD = 0x01,		/**< Odd Parity  */
	EVEN = 0x02		/**< Even Parity */
}UartParity_t;

/**
 * Defines the bit ordering for uart receive and transmit shift registers.
 */
typedef enum 
{
  	UART_LSB_FIRST,		/**< Least significant bit sent first */
  	UART_MSB_FIRST		/**< Most significant bit sent first */
}UartBitOrder_t;

/**
 * Defines the size of data sent to and from peripheral
 */
typedef enum 
{
	BITS_EIGHT,			/**< 8 bits sent at a time */
	BITS_NINE			/**< 9 bits sent at a time */
}UartComm_t;

/**
 * Defines the possible USCI modes
 */
typedef enum 
{
	UART				/**< Standard UART mode */
}UartMode_t;

/**
 * Defines the possible interrupt modes
 */
typedef enum 
{
	RX_ONLY = 1U,		/**< Enable Receive Interrupt */
	TX_ONLY = 2U,		/**< Enable Transmit Interrupt */
	RX_TX = 3U			/**< Enable both Rx and Tx Interrupts */
}UartInt_t;
	
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
	uint8_t UartChannel;		/**< Name of UART */
	uint8_t UartEnable;			/**< Uart Enable - ENABLED or DISABLED */
	uint8_t UartMode;			/**< Uart Mode Selection */
	uint8_t ClkSrc;				/**< Slect the clock source for BRCLK */
	uint32_t BaudRate;			/**< Uart channel baud rate */
	uint8_t Loopback;			/**< ENABLE or DISABLE loopback mode */
	uint8_t BitDirection;		/**< Rx and Tx Shift register bit direction */
	uint8_t DataLength;			/**< Character length, 8 or 9 bits */
	uint8_t StopBits;			/**< Specify the number of stop bits, one or two */
	uint8_t ParityType;			/**< Parity Selection.  EVEN, ODD, or DISABLED */
	uint8_t Delimiter;			/**< Break/synch delimiter length.  */
    uint8_t IntEnable;			/**< Uart Receive Interrupt Enable - ENABLED or DISABLED */
}UartConfig_t;

/**
 * This enumeration is a list of the uart channels
 */
typedef enum 
{
	UART_0,			/**< UART0 */
	UART_1,			/**< UART1 */
	UART_2,			/**< UART2 */
    
    NUM_UART_CHANNELS		/**< Number of UART channels */
}UartChannel_t;

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

const UartConfig_t *Uart_ConfigGet(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*UART_CFG_H_*/


/*** End of File **************************************************************/
