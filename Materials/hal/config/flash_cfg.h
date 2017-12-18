/****************************************************************************
* Title                 :   Flash Configuration
* Filename              :   flash_cfg.h
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
/** \file flash_cfg.h
 * \brief This contains the header for the flash configuration.
 */
#ifndef FLASH_CFG_H
#define FLASH_CFG_H
/******************************************************************************
 * Includes
 *******************************************************************************/
#include <stdint.h>            // for standard types

/******************************************************************************
 * Constants
 *******************************************************************************/
/**
 * The available Flash clock sources.
 */
typedef enum 
{
	AUX_CLK,		/**< Auxilary Clock */
  	M_CLK,			/**< System Clock */
  	SYS_CLK			/**< Sub-System Master Clock */
}FlashClkSrc_t;

/******************************************************************************
 * Macros
 *******************************************************************************/

/******************************************************************************
 * Typedefs
 *******************************************************************************/
/**
 * Struct Flash_ConfigType
 * The Flash Config Type structure is used to set the configuration for the Flash
 * module.
 */
typedef struct
{
	uint8_t ClkSrc;		/**< The Flash clock source */
	uint8_t ClkDiv;		/**< Set the Clock divider to 1-64. */
}FlashConfig_t;

/******************************************************************************
 * Variable Definitions
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

const FlashConfig_t *Flash_ConfigGet(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif  // FLASH_CFG_H

/****** END OF FILE ***********************************************************/
