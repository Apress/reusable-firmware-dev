/****************************************************************************
* Title                 :   Timer Configuration
* Filename              :   tmr_cfg.h
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
/** @file tmr_cfg.h
 *  @brief This module contains the configuration interface for timer
 */
#ifndef TMR_CFG_H_
#define TMR_CFG_H_
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>				// For standard type definitions

/******************************************************************************
* Constants
*******************************************************************************/
/**
 *  Defines the timer clock input dividers
 */
typedef enum 
{
	TMR_DIV_1 = 1,			/**< Timer prescalar of 1:1 */
	TMR_DIV_2 = 2,			/**< Timer prescalar of 1:2 */
	TMR_DIV_4 = 4,			/**< Timer prescalar of 1:4 */
	TMR_DIV_8 = 8,			/**< Timer prescalar of 1:8 */
	TMR_DIV_16 = 16,		/**< Timer prescalar of 1:16 */
	TMR_DIV_32 = 32,		/**< Timer prescalar of 1:32 */
	TMR_DIV_64 = 64,		/**< Timer prescalar of 1:64 */
	TMR_DIV_128 = 128		/**< Timer prescalar of 1:128 */
}TmrPrescale_t;

/**
 *  Defines the counter modes for the timer.
 */
typedef enum 
{
	UP_COUNT,			/**< LPTPM counter operates in up counting mode. */
	UP_DOWN				/**< LPTPM counter operates in up-down counting mode. */
}TmrCounter_t;

/**
 *  Defines the clock sources for the timer.
 */
typedef enum 
{
	FLL_PLL = 1,		/**< Use the FLL or PLL clock */
	OSCERCLK,			/**< Oscillator clock frequency */
	INT_CLK				/**< Internal clock */
}TmrClkSrc_t;

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
 * Defines the timer configuration table elements that are used
 * by Tmr_Init to configure the timer registers.
 */
typedef struct
{
	uint16_t TimerChannel;		    /**< Name of Timer */
	uint16_t TimerEnable;			/**< ENABLED or DISABLED Timer channel*/
	uint16_t TimerMode;		  	    /**< Timer Counter Mode Setting */
	uint16_t ClockSource;			/**< Timer Clock Source Setting */
	uint16_t ClkMode;				/**< Timer Clock Mode Select */
	uint16_t ClkPrescaler;  		/**< Clock input divider */
    uint16_t IntEnabled;			/**< Timer Interrupt Enable - ENABLED or DISABLED */
	uint16_t IntPriority;			/**< Timer Interrupt Priority */
	uint16_t Interval;				/**< Timer interval in microseconds */
}TmrConfig_t;

/**
 *  This enumeration is a list of the timer channels
 */
typedef enum
{
	TMR0 = 0U,	       	/**< Timer 0 */
	TMR1 = 1U,         	/**< Timer 1 */
	TMR2 = 2U,         	/**< Timer 2 */
	NUM_TIMERS = 3U		/**< Number of timers on the microcontroller */
}TmrRegister_t;

/**
 *  Defines the available clock modes for the timer
 */
typedef enum
{
	STOP,				/**< LPTPM counter is disabled */
	MODULE_CLK,			/**< LPTPM counter increments on every LPTPM counter clock */
	EXTERNAL_CLK		/**< LPTPM counter increments on rising edge of LPTPM_EXTCLK synchronized to the LPTPM counter
							 clock */
}TmrClockMode_t;

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

const TmrConfig_t * Tmr_ConfigGet(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*TMR_CFG_H_*/

/*** End of File **************************************************************/
