/****************************************************************************
* Title                 :   Watchdog Timer
* Filename              :   wdt.c
* Author                :   Jacob W. Beningo
* Origin Date           :   11/07/2012
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
*  09/01/15   0.5.0   Jacob Beningo   Interface Created.
*  11/10/15   1.0.0   Jacob Beningo   Interface updated.
*
*******************************************************************************/
/**
 *  @file wdt.c
 *  @brief The implementation for the watchdog.
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "wdt.h"				/* For this module's definitions */
#include "constants.h"			/* For REGBIT definitions */

/******************************************************************************
* Constants
*******************************************************************************/
/**
 * Used to force a soft reset of the processor through the watchdog.
 */
#define WDT_SOFTWARE_RESET                  0xFF

/**
 *  Defines a pointer to the wdt control register on the microcontroller.
 */
TYPE volatile * const wdtcon = (TYPE*)&REGISTER;

/**
 *  Defines a pointer to the wdt service register on the microcontroller.
 */
TYPE volatile * const wdtsvr = (TYPE*)&REGISTER;

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
 * Used to store the most recent Watchdog Interval
 */
static uint8_t WdtInterval = 0;		

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : Wdt_Init()
*//** 
* \b Description:
*
* This function is used to initialize the watchdog based on the configuration table
*  defined in wdt_cfg module.
*  
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0) <br>
* PRE-CONDITION: System Clock Initialized
*
* POST-CONDITION: The WDT peripheral is setup with the configuration settings.
*
* @param  		Config is a pointer to the configuration table that contains
*				the initialization for the peripheral.
*
* @return 		void
*
* \b Example:
* @code
* 	const WdtConfig_t *WdtConfig = Wdt_ConfigGet();
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
* @see Wdt_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* <tr><td> 11/10/2015 </td><td> 1.0.0            </td><td> JWB      </td><td> Interface Released </td></tr>
* </table><br><br>
* <hr>
*******************************************************************************/
void Wdt_Init(const WdtConfig_t * Config)
{

}

/******************************************************************************
* Function : Wdt_Enable()
*//** 
* \b Description:
*
* This function is used to enable the watchdog. In most MCU's once enabled the
* watchdog cannot be disabled! (Thankfully).
*  
* PRE-CONDITION: Wdt_Init must be called with valid configuration data.
*
* POST-CONDITION: The WDT peripheral is enabled and now must be cleared to 
* prevent a reset.
*
* @return 		void
*
* \b Example:
* @code
* 	const WdtConfig_t *WdtConfig = Wdt_ConfigGet();
*
* 	Wdt_Init(WdtConfig);
*   Wdt_Enable();
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
* @see Wdt_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* <tr><td> 11/10/2015 </td><td> 1.0.0            </td><td> JWB      </td><td> Interface Released </td></tr>
* </table><br><br>
* <hr>
*******************************************************************************/
void Wdt_Enable(void)
{

}

/******************************************************************************
* Function : Wdt_Disable()
*//** 
* \b Description:
*
* This function is used to disable the watchdog (not recommended or possible on
* many microcontrollers once it is enabled)
*  
* PRE-CONDITION: Wdt_Init must be called with valid configuration data <br>
* PRE-CONDITION: Wdt_Enable must have been called to enable the watchdog
*
* POST-CONDITION: The WDT peripheral is disabled (if possible)
*
* @return 		void
*
* \b Example:
* @code
* 	const WdtConfig_t *WdtConfig = Wdt_ConfigGet();
*
* 	Wdt_Init(WdtConfig);
*   Wdt_Enable();
*   Wdt_Disable();
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
* @see Wdt_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* <tr><td> 11/10/2015 </td><td> 1.0.0            </td><td> JWB      </td><td> Interface Released </td></tr>
* </table><br><br>
* <hr>
*******************************************************************************/
void Wdt_Disable(void)
{

}

/******************************************************************************
* Function : Wdt_Clear()
*//** 
* \b Description:
*
* This function is used to clear the watchdog register to prevent a watchdog 
* reset of the system.
*  
* PRE-CONDITION: Wdt_Init must be called with valid configuration data <br>
* PRE-CONDITION: Wdt_Enable must have been called to enable the watchdog.
*
* POST-CONDITION: The WDT peripheral counter register is cleared.
*
* @return 		void
*
* \b Example:
* @code
* 	const WdtConfig_t *WdtConfig = Wdt_ConfigGet();
*
* 	Wdt_Init(WdtConfig);
*   Wdt_Enable();
*
*   // application code
*   // System health checks
*   if(SystemHealthy == TRUE)
*   {
*	   Wdt_Clear();
*   }
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
* @see Wdt_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* <tr><td> 11/10/2015 </td><td> 1.0.0            </td><td> JWB      </td><td> Interface Released </td></tr>
* </table><br><br>
* <hr>
*******************************************************************************/
void Wdt_Clear(void)
{
	*wdtsvr = 0x55;
	*wdtsvr = 0xAA;
}

/******************************************************************************
* Function : Wdt_Reset()
*//** 
* \b Description:
*
* This function is used to trigger a watchdog reset of the processor.  Function
* may have no effect if the Wdt register has already been written to.
*  
* PRE-CONDITION: Wdt_Init must be called with valid configuration data <br>
* PRE-CONDITION: Wdt_Enable must have been called to enable the watchdog.
*
* POST-CONDITION: The WDT forces a reset of the MCU.
*
* @return 		void
*
* \b Example:
* @code
* 	const WdtConfig_t *WdtConfig = Wdt_ConfigGet();
*
* 	Wdt_Init(WdtConfig);
*   Wdt_Enable();
*
*   // application code
*   // System health checks
*   if(SystemHealthy == TRUE)
*   {
*	   Wdt_Clear();
*   }
*   else
*   {
*	   Wdt_Reset();
*   }
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
* @see Wdt_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* <tr><td> 11/10/2015 </td><td> 1.0.0            </td><td> JWB      </td><td> Interface Released </td></tr>
* </table><br><br>
* <hr>
*******************************************************************************/
void Wdt_Reset(void)
{
	*wdtsvr = WDT_SOFTWARE_RESET;
}

/******************************************************************************
* Function : Wdt_RegisterWrite()
*//** 
* \b Description:
*
*  This function is used to directly address and modify a Dio register.  The 
*  function should be used to access specialized functionality in the Dio peripheral
*  that is not exposed by any other function of the interface.
*
* PRE-CONDITION: Address is within the boundaries of the Dio register address space
*
* POST-CONDITION: The register located at Address with be updated with Value
*
* @param  	  Address is a register address within the Dio peripheral map
* @param      Value is the value to set the Dio register to
*
* @return 	  void
*
* \b Example:
* @code
*    Wdt_RegisterWrite(0x1000, 0x15);
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
* @see Wdt_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* <tr><td> 11/10/2015 </td><td> 1.0.0            </td><td> JWB      </td><td> Interface Released </td></tr>
* </table><br><br>
* <hr>
*******************************************************************************/
void Wdt_RegisterWrite(uint32_t Address, uint32_t Value)
{
   uint32_t * const RegisterPointer = (uint32_t *) Address;
   
   *RegisterPointer = Value;
}

/******************************************************************************
* Function : Wdt_RegisterRead()
*//** 
* \b Description:
*
** This function is used to directly address a wdt register.  The function 
* should be used to access specialized functionality in the wdt peripheral
* that is not exposed by any other function of the interface.
*
* PRE-CONDITION: Address is within the boundaries of the wdt register address space
*
* POST-CONDITION: The value stored in the register is returned to the caller
*
* @param  		Address is the address of the wdt register to read
*
* @return 		The current value of the wdt register.
*
* \b Example:
* @code
*    WdtValue = Wdt_RegisterRead(0x1000);
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
* @see Wdt_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* <tr><td> 11/10/2015 </td><td> 1.0.0            </td><td> JWB      </td><td> Interface Released </td></tr>
* </table><br><br>
* <hr>
*******************************************************************************/
uint32_t Wdt_RegisterRead(uint32_t Address)
{
   uint32_t * const RegisterPointer = (uint32_t *) Address;
   
   return *RegisterPointer;
}

/******************************************************************************
* Function : Wdt_CallbackRegister()
*//** 
* \b Description:
*
* This function is used to set the callback functions of the Wdt driver. By 
* default, the callbacks are initialized to a NULL pointer. The driver may 
* contain more than one possible callback, so the function will take a parameter
* to configure the specified callback. 
*
* PRE-CONDITION: The WdtCallback_t has been populated <br>
* PRE-CONDITION: The callback function exists within memory.
*
* POST-CONDITION: The specified callback function will be registered with the
* driver. 
*
* @param  		Function is the callback function that will be registered
* @param 		CallbackFunction is a function pointer to the desired function
*
* @return 		None.
*
* \b Example:
* @code
*    WdtCallback_t Wdt_Function = Wdt_SAMPLE_COMPLETE; 
*    
*    Wdt_CallbackRegister(Wdt_Function, Wdt_SampleAverage);
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
* @see Wdt_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* <tr><td> 11/10/2015 </td><td> 1.0.0            </td><td> JWB      </td><td> Interface Released </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
void Wdt_CallbackRegister(WdtCallback_t Function, TYPE (*CallbackFunction)(type))
{


}

/*** End of File **************************************************************/

