/****************************************************************************
* Title                 :   Serial Peripheral Interface (SPI)
* Filename              :   spi.h
* Author                :   Jacob W. Beningo
* Origin Date           :   01/14/2013
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
*  11/10/15   1.0.0   Jacob Beningo   Updated interface.
*
*****************************************************************************/
/** @file spi.h
 *  @brief The interface definition for spi.
 * 
 *  This is the header file for the definition of the interface for the 
 *  SPI peripheral.
 */
#ifndef SPI_H_
#define SPI_H_
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>					/* For standard type definitions */
#include "spi_cfg.h"				/* For spi configuration definitions */
#include "dio.h"					  /* For Dio_ChannelType definition */

/******************************************************************************
* Constants
*******************************************************************************/
/**
 * Defines the clock polarity options.
 */
typedef enum 
{
	POLARITY_LOW,		/**< Idle clock state is low */
	POLARITY_HIGH		/**< Idle clock state is high */
}SpiPolarity_t;

/**
 * Defines the clock phase.
 */
typedef enum 
{
	PHASE_HIGH,		/**< Sample from leading clock edge */
	PHASE_LOW		  /**< Sample from trailing clock edge */
}SpiPhase_t;

/**
 * Defines the bit ordering for a Spi Transfer.
 */
typedef enum 
{
  	LSB_FIRST,		/**< Least significant bit sent first */
  	MSB_FIRST		/**< Most significant bit sent first */
}SpiBitOrder_t;

/**
 * Defines the state of the CS when data is being transferred to the device
 */
typedef enum 
{
  	CS_ACTIVE_LOW,		/**< Chip select active low */
  	CS_ACTIVE_HIGH		/**< Chip select active high */
}SpiChipSelect_t;

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
 * The SPI Transfer Type structure is used to set the configuration for
 * transmitting SPI data.
 */
typedef struct
{
  SpiChannel_t SpiChannel;		/**< The SPI channel to be used */
  DioChannel_t ChipSelect;	  /**< The DIO channel to be used for chip select */
  SpiChipSelect_t CsPolarity;	/**< The active state of chip select */
  uint16_t NumBytes;				  /**< The number of bytes to send */
  uint8_t *TxRxData;				  /**< Pointer to the data to transfer */
  SpiPolarity_t Polarity;			/**< Transfer data polarity */
  SpiPhase_t Phase;				    /**< Transfer data phase */
  SpiBitOrder_t Direction;		/**< Bit direction */
}SpiTransfer_t;

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void Spi_Init(const SpiConfig_t *Config);
void Spi_DeInit(SpiChannel_t Channel);
void Spi_Transfer(const SpiTransfer_t *Config);
void Spi_RegisterWrite(uint32_t Address, uint32_t Value);
uint32_t Spi_RegisterRead(uint32_t Address);
void Spi_CallbackRegister(SpiCallback_t Function, TYPE (*CallbackFunction)(type));


#ifdef __cplusplus
} // extern "C"
#endif

#endif /*SPI_H_*/

/*** End of File **************************************************************/
