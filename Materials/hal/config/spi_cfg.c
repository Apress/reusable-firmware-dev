/****************************************************************************
* Title                 :   Serial Peripheral Interface Configuration
* Filename              :   spi_cfg.c
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
/** @file spi_cfg.c
 *  @brief This module contains the configuration for the spi module
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "spi_cfg.h"    	// For configuration definitions
#include "constants.h"		// For ENABLED, DISABLED, etc

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
* the spi channels.  The channels are defined in spi_cfg.h.  The configuration
* consists of
*
*  o SPI Channel - Specify the name of the spi channel. This label must be defined in
*      the Spi_ChannelType enumeration.
*  o Channel Enable - Specify whether the Spi channel is enabled.
*  o Master Mode - Set the Spi channel to master or slave mode
*  o Slave Select Pin Mode - Select the SS Pin function.
*     GPIO  - SS pin is general purpose I/O, not spi.
*     SS_INPUT - Slave select is an input.
*     SS_OUTPUT  - SS pin is an output.
*  o Bidirectional Mode - Enable or disable bidirectional mode.  A single pin is used
*	  for both input and output.  MOSI for master, MISO for slave.
*  o Wait Mode - Enable or disable spi clock operation when CPU is in wait mode.
*  o Clock Frequency - Determines the SPI clock frequency (in Hz).
*******************************************************************************/
const SpiConfig_t SpiConfig[] =
{
//	  SPI		 Channel 	  Master 	  Slave Select    Bidirectional		Wait	     Clock
//  Channel		 Enable  	   Mode 	    Pin Mode		  Mode		    Mode	  Frequency (Hz)
//
	{SPI_0,		ENABLED, 	  MASTER, 	   	  GPIO,	   	    DISABLED,	   ENABLED,		250000UL	},
	{SPI_1,		DISABLED, 	  MASTER, 	   	  GPIO,	   	    DISABLED,	   ENABLED,		250000UL	},
};

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : Spi_ConfigGet()
*//** 
* \b Description:
*
* This function return a pointer to the Spi configuration structure. 
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
* 	const SpiConfig_t * SpiConfig = Spi_ConfigGet();
*
* 	Spi_Init(SpiConfig);
* @endcode
*
* @see Spi_ConfigGet
* @see Spi_Init
* @see Spi_ChannelRead
* @see Spi_ChannelWrite
* @see Spi_ChannelToggle
* @see Spi_ChannelModeSet
* @see Spi_ChannelDirectionSet
* @see Spi_RegisterWrite
* @see Spi_RegisterRead
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
const SpiConfig_t * Spi_ConfigGet(void)
{
	return SpiConfig;
}

/*** End of File **************************************************************/
