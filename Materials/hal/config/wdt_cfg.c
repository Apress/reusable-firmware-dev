/****************************************************************************
* Title                 :   Watchdog Timer Configuration
* Filename              :   wdt_cfg.c
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
/** @file wdt_cfg.c
 *  @brief This module contains the configuration for the wdt module
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "wdt_cfg.h"				// For this module's definitions
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
 * The Wdt configuration settings to initialize the wdt register.
 */
const WdtConfig_t WdtConfig =
{
	NORMAL,			/**< Wdt mode selection. NORMAL, WINDOWED, or DISABLED 	*/
  	ONE_KHZ,		/**< Watchdog clock source.								*/
  	INT_256,		/**< Watchdog timer interval.   						*/
};

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : Wdt_ConfigGet()
*//** 
* \b Description:
*
* This function return a pointer to the Wdt configuration structure. 
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
* 	const WdtConfig_t * WdtConfig = Wdt_ConfigGet();
*
* 	Wdt_Init(WdtConfig);
* @endcode
*
* @see Wdt_ConfigGet
* @see Wdt_Init
* @see Wdt_Enable
* @see Wdt_Disable
* @see Wdt_Clear
* @see Wdt_Reset
* @see Wdt_RegisterWrite
* @see Wdt_RegisterRead
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
const WdtConfig_t * Wdt_ConfigGet(void)
{
	return &WdtConfig;
}

/*** End of File **************************************************************/

