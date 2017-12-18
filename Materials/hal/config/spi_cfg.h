/****************************************************************************
* Title                 :   Serial Peripheral Interface Configuration
* Filename              :   spi_cfg.h
* Author                :   JWB
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
/** @file spi_cfg.c
 *  @brief This module contains the configuration interface for spi
 */
#ifndef SPI_CFG_H_
#define SPI_CFG_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>				// For standard type definitions

/******************************************************************************
* Constants
*******************************************************************************/
/**
 * The SPI peripheral has two different modes that it can operate in; MASTER mode and
 * SLAVE mode
 */
typedef enum 
{
  	SLAVE,		/**< Spi peripheral in slave mode */
  	MASTER		/**< Spi peripheral in master mode */
}SpiMode_t;

/**
 * The SPI peripheral has two different modes that it can operate in; MASTER mode and
 * SLAVE mode
 */
typedef enum 
{
  	GPIO,			/**< Slave select pin is GPIO */
  	SS_INPUT,		/**< Slave select pin function is SS input */
	SS_OUTPUT		/**< Slave select pin function is automatic SS output */
}SpiSSMode_t;

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
 * Defines the configuration data required to initialize the SPI peripheral.
 */
typedef struct
{
	uint8_t ChannelName;		/**< Defines the name of the SPI channel */
	uint8_t SpiEnable;		/**< ENABLE or DISABLE the SPI channel */
 	uint8_t MasterMode;		/**< Defines the peripheral Master/Slave mode */
	uint8_t SSPinMode;		/**< Defines the slave select pin function */
	uint8_t Bidirection;		/**< Bidirectional mode output enable */
	uint8_t WaitMode;			/**< Enable or disable operation when CPU is in wait mode */
 	uint32_t BaudRate;			/**< Defines the baud rate in Hz */
}SpiConfig_t;

/**
 * This enumeration defines a list of the spi channels
 */
typedef enum
{
	SPI_0,				/**< SPI Channel 0 */
	SPI_1, 				/**< SPI Channel 1 */

	NUM_SPI_CHANNELS	/**< Number of SPI channels */
}SpiChannel_t;

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

const SpiConfig_t *Spi_ConfigGet(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*SPI_CFG_H_*/


/*** End of File **************************************************************/
