/****************************************************************************
* Title                 :   Watchdog Timer Configuration
* Filename              :   wdt_cfg.h
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
/** @file wdt_cfg.h
 *  @brief This module contains the configuration interface for wdt
 */
#ifndef WDT_CFG_H_
#define WDT_CFG_H_
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>				// For standard type definitions

/******************************************************************************
* Constants
*******************************************************************************/
/**
 * Defines the available modes of the Watchdog Timer
 */
typedef enum 
{
	NORMAL = 1,			/**< Normal watchdog operation */
	WINDOWED = 2		/**< Window is opened three quarters through the timeout period.
							  Only supported when the Wdt is running from the Bus clock	*/
}WdtMode_t;

/**
 * Defines the available clock sources for the Watchdog Timer
 */
typedef enum 
{
	ONE_KHZ,			/**< Internal 1 kHz clock 	*/
	BUS					/**< Bus clock				*/
}WdtClkSrc_t;

/**
 * Defines the available Watchdog Timer intervals
 */
typedef enum 
{
	NONE,				/**< Watchdog timer is disabled 					*/
	INT_32,				/**< 1 kHz internal clk source * 32, or 32 ms		*/
	INT_256,			/**< 1 kHz internal clk source * 256, or 256 ms 	*/
	INT_1024,			/**< 1 kHz internal clk source * 1024, or 1.024 s	*/

	INT_8192 = 0x01,	/**< For Bus clock, Watchdog clock source * 8192	*/
	INT_65536,			/**< For Bus clock, Watchdog clock source * 65536	*/
	INT_262144			/**< For Bus clock, Watchdog clock source * 262144	*/
}WdtInterval_t;

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
	uint8_t WdtMode;				/**< Watchdog Timer Mode - RESET or INTERVAL 	*/
	uint8_t ClockSource;			/**< Timer Clock Source Select 					*/
	uint8_t Interval;				/**< Watchdog timer interval selection 			*/
}WdtConfig_t;

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

const WdtConfig_t * Wdt_ConfigGet(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*TMR_CFG_H_*/

/*** End of File **************************************************************/
