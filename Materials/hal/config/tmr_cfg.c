/****************************************************************************
* Title                 :   Timer Configuration
* Filename              :   tmr_cfg.c
* Author                :   Jacob W Beningo
* Origin Date           :   11/13/2012
* Version               :   1.0.0
* Compiler              :   TBD
* Target                :   TBD
* Copyright             :   Beningo Engineering
* All Rights Reserved
*
* THIS SOFTWARE IS PROVIDED BY USA FIRMWARE "AS IS" AND ANY EXPRESSED
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL USA FIRMWARE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
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
/** @file tmr_cfg.c
 *  @brief This module contains the configuration for the tmr module
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "tmr_cfg.h"				// For this module's definitions
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
*  o Timer Name - Specify the name of the timer. This label must be defined in
*      the Tmr_RegisterType enumeration.
*  o Timer Enable - Enable or disable the specified timer channel.
*  o Timer Mode - Specify the mode of the timer.  Timer modes are defined in the
*      Tmr_CounterEnum enumeration.
*  o Clock Source - Specify the source of the timer clock.  All channels
*      must use the same clock source, so only TMR0 clock source is used.
*  o Clock Mode Selection - Specify the clock mode.  Clock modes are defined in
*	   the Tmr_ClkModeType enumeration.
*  o Clock Prescaler - Specify the clock input divider.
*  o Interrupt Enable - This sets whether the interrupt for this timer is enabled.
*     DISABLED  - Sets the interrupt enable bit low
*     ENABLED - Sets the interrupt enable bit high
*  o Timer Interval - Specify the period of the timer in microseconds.
*******************************************************************************/
const TmrConfig_t TmrConfig[] =
{
//	  Timer		  Timer		  Timer		   Clock 	  		  Clock Mode	   Clock	  Interrupt      Interrupt 		Timer
//    Name		  Enable	  Mode		   Source	  		  Selection	 Prescaler	   Enable	 Priority	  Interval (us)
//
	{TMR0,	    ENABLED,	 UP_COUNT,	  FLL_PLL,	  		  MODULE_CLK,	  TMR_DIV_1,	   DISABLED,        3,			100		},
	{TMR1,		DISABLED,	 UP_COUNT,	  NOT_APPLICABLE,	                STOP,	  TMR_DIV_1,	   DISABLED, 	    0, 			0		},
	{TMR2,		ENABLED,	 UP_COUNT,	  FLL_PLL,	  		  MODULE_CLK,	  TMR_DIV_1,	   DISABLED,	    3,			100		},
};

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : Tmr_ConfigGet()
*//** 
* \b Description:
*
* This function return a pointer to the Tmr configuration structure. 
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
* 	const TmrConfig_t * TmrConfig = Tmr_ConfigGet();
*
* 	Tmr_Init(TmrConfig);
* @endcode
*
* @see Tmr_ConfigGet
* @see Tmr_Init
* @see Tmr_Enable
* @see Tmr_Disable
* @see Tmr_RegisterWrite
* @see Tmr_RegisterRead
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
const TmrConfig_t * Tmr_ConfigGet(void)
{
	return TmrConfig;
}

/*** End of File **************************************************************/

