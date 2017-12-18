/****************************************************************************
* Title                 :   Digital Input Output (DIO) Configuration
* Filename              :   dio_cfg.h
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
*****************************************************************************/
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
*  09/01/15   1.0.0   Jacob Beningo   Interface Created.
*
*****************************************************************************/
/** @file dio_cfg.h
 *  @brief This module contains interface definition for the Dio configuration.
 * 
 *  This is the header file for the definition of the interface for retrieving
 *  the digital input/output configuration table.
 */
#ifndef DIO_H_
#define DIO_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
/**
 * Defines the number of pins on each processor port.
 */
#define NUMBER_OF_CHANNELS_PER_PORT         8U

/**
 *  Defines the number of ports on the processor.
 */
#define NUMBER_OF_PORTS                 8U

/******************************************************************************
* Configuration Constants
*******************************************************************************/


/******************************************************************************
* Macros
*******************************************************************************/

	
/******************************************************************************
* Typedefs
*******************************************************************************/
/**
 * Defines the possible states for a digital output pin.
 */
 typedef enum
 {
    DIO_LOW,             /** Defines digital state ground */
    DIO_HIGH,            /** Defines digital state power */
    DIO_PIN_STATE_MAX	   /** Defines the maximum digital state */
 }DioPinState_t;

/**
 * Defines an enumerated list of all the channels (pins) on the MCU device.  
 * The last element is used to specify the maximum number of enumerated labels.
 */
typedef enum
{
   /* TODO: Populate this list based on available MCU pins */
   FCPU_HB,              /**< PORT1_0 */
   PORT1_1,              /**< PORT1_1 */
   PORT1_2,	             /**< PORT1_2 */
   PORT1_3,	             /**< PORT1_3 */
   UHF_SEL,	             /**< PORT1_4 */
   PORT1_5,	             /**< PORT1_5 */
   PORT1_6,	             /**< PORT1_6 */
   PORT1_7,	             /**< PORT1_7 */
   DIO_MAX_PIN_NUMBER    /**< MAX CHANNELS */	
}DioChannel_t;

/**
 * Defines the possible DIO pin multiplexing values.  The datasheet should be
 * reviewed for proper muxing options.
 */
typedef enum 
{
   /* TODO: Populate with possible mode options */
   DIO_MAX_MODE	
}DioMode_t;

/**
 * Defines the possible states of the channel pull-ups
 */
typedef enum 
{
   DIO_PULLUP_DISABLED,     /*< Used to disable the internal pull-ups */
   DIO_PULLUP_ENABLED,      /*< Used to enable the internal pull-ups */
   DIO_MAX_RESISTOR	        /*< Resistor states should be below this value */
}DioResistor_t;

/**
 * Defines the digital input/output configuration table elements that are used
 * by Dio_Init to configure the Dio peripheral.
 */
typedef struct 
{
	/* TODO: Add additional members for the MCU peripheral */
    DioChannel_t Channel;          /**< The I/O pin								*/
    DioResistor_t Resistor;				 /**< Pullup/Pulldown Resistor - ENABLED or DISABLED	*/
    DioDirection_t Direction;      /**< Data Direction      - OUTPUT or INPUT			*/
    DioPinState_t Data;            /**< Data                - HIGH or LOW				*/
    DioMode_t Function;            /**< Mux Function        - Dio_Peri_Select			*/
}DioConfig_t;	

/**
 * Defines the slew rate settings available
 */
typedef enum
{
  FAST,     /**< Fast slew rate is configured on the corresponding pin, */
  SLOW      /**< Slow slew rate is configured on the corresponding pin, */
}DioSlew_t;

/******************************************************************************
* Variables
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

const DioConfig_t * const Dio_ConfigGet(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*DIO_H_*/

/*** End of File **************************************************************/
