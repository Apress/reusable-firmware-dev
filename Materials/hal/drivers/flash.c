/****************************************************************************
* Title                 :   Flash
* Filename              :   flash.c
* Author                :   Jacob W. Beningo
* Origin Date           :   01/03/2013
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
*  11/10/15   1.0.0   Jacob Beningo   Interface updates.
*******************************************************************************/
/** @file flash.c
 *  @brief The implementation for the flash.
 */
/******************************************************************************
 * Includes
 *******************************************************************************/
#include <stdint.h>			/* For fixed width integer types */
#include "flash.h"			/* For this module's definitions */

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
/*lint -e715
  This file is currently serving as a place holder.  715 corresponds to unused
  parameters passed to the function.  This message is suppressed until the
  functions are filled in.  */
/******************************************************************************
* Function : Flash_Init()
*//** 
* \b Description:
*
*  This function initializes the flash driver
*  
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0) <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: The flash peripheral is setup with the configuration settings.
*
* @param     Config - Pointer to flash configuration table.
*
* @return     None.
*
* \b Example:
* @code
*	const Flash_ConfigType *FlashConfig = Flash_GetConfig();
*	Flash_Init(FlashConfig);
* @endcode
*
* @see Flash_Init
* @see Flash_Read
* @see Flash_Write
* @see Flash_Erase
* @see Flash_RegisterWrite
* @see Flash_RegisterRead
* @see Flash_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* <tr><td> 11/10/2015 </td><td> 1.0.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* </table><br><br>
* <hr>
*******************************************************************************/
void Flash_Init(const Flash_Config_t * Config)
{
 
}

/******************************************************************************
* Function : Flash_Write()
*//** 
* \b Description:
*
*  This function writes data to a location in flash
*  
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0) <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled. <br>
* PRE-CONDITION: The Flash_Init function as been called successfully
*
* POST-CONDITION: The flash peripheral writes the input data to the requested
* location in flash.
*
* @param     Address - uint32_t, address in flash memory. 
* @param     Data - uint32_t, pointer to data buffer to write to flash.
* @param     Size - uint8_t, size of data to write.
*
* \b Example:
* @code
* 	uint16_t buffer[8];
* 	Flash_Write(0x01234567, buffer, 8);
* @endcode
*
* @see Flash_Init
* @see Flash_Read
* @see Flash_Write
* @see Flash_Erase
* @see Flash_RegisterWrite
* @see Flash_RegisterRead
* @see Flash_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* <tr><td> 11/10/2015 </td><td> 1.0.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* </table><br><br>
* <hr>
*******************************************************************************/
void Flash_Write(uint32_t Address, const uint16_t* Data, uint8_t Size)
{

}

/******************************************************************************
* Function : Flash_Read()
*//** 
* \b Description:
*
*  This function reads data from flash memory.
*  
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0) <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled. <br>
* PRE-CONDITION: The Flash_Init function as been called successfully
*
* POST-CONDITION: The flash peripheral reads data from flash.
*
* @param     Address - uint32_t, address in flash memory.
* @param     Data - uint16_t, pointer to data buffer to read to flash.
* @param     Size - uint8_t, size of data to read.
*
* \b Example:
* @code
* 	value = Flash_Read(0x01234567, Buffer, 255);
* @endcode
*
* @see Flash_Init
* @see Flash_Read
* @see Flash_Write
* @see Flash_Erase
* @see Flash_RegisterWrite
* @see Flash_RegisterRead
* @see Flash_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* <tr><td> 11/10/2015 </td><td> 1.0.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* </table><br><br>
* <hr>
*******************************************************************************/
void Flash_Read(uint32_t Address, const uint16_t *Data, uint8_t Size)
{

}

/******************************************************************************
* Function : Flash_Erase()
*//** 
* \b Description:
*
*  This function erases a segment of flash memory.
*  
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0) <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled. <br>
* PRE-CONDITION: The Flash_Init function as been called successfully
*
* POST-CONDITION: The flash peripheral reads data from flash.
*
* @param     Address - uint32_t, flash memory address to read
*
* @return     None.
*
* \b Example:
* @code
* 	Flash_Erase(0x01234567);
* @endcode
*
* @see Flash_Init
* @see Flash_Read
* @see Flash_Write
* @see Flash_Erase
* @see Flash_RegisterWrite
* @see Flash_RegisterRead
* @see Flash_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* <tr><td> 11/10/2015 </td><td> 1.0.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* </table><br><br>
* <hr>
*******************************************************************************/
void Flash_Erase(uint32_t Address)
{

}

/******************************************************************************
* Function : Flash_RegisterWrite()
*//** 
* \b Description:
*
*  This function is used to directly address and modify a flash register.  The 
*  function should be used to access specialized functionality in the register peripheral
*  that is not exposed by any other function of the interface.
*
* PRE-CONDITION: Address is within the boundaries of the flash register address space
*
* POST-CONDITION: The register located at Address with be updated with Value
*
* @param  	  Address is a register address within the value peripheral map
* @param      Value is the value to set the value register to
*
* @return 		void
*
* \b Example:
* @code
*    Flash_RegisterWrite(0x1000, 0x15);
* @endcode
*
* @see Flash_Init
* @see Flash_Read
* @see Flash_Write
* @see Flash_Erase
* @see Flash_RegisterWrite
* @see Flash_RegisterRead
* @see Flash_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* <tr><td> 11/10/2015 </td><td> 1.0.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
void Flash_RegisterWrite(uint32_t Address, uint32_t Value)
{
   uint32_t * const RegisterPointer = (uint32_t *) Address;
   
   *RegisterPointer = Value;
}

/******************************************************************************
* Function : Flash_RegisterRead()
*//** 
* \b Description:
*
* This function is used to directly address a flash register.  The function 
* should be used to access specialized functionality in the flash peripheral
* that is not exposed by any other function of the interface.
*
* PRE-CONDITION: Address is within the boundaries of the flash register address space
*
* POST-CONDITION: The value stored in the register is returned to the caller
*
* @param  		Address is the address of the register to read
*
* @return 		The current value of the register.
*
* \b Example:
* @code
*    FlashValue = Flash_RegisterRead(0x1000);
* @endcode
*
* @see Flash_Init
* @see Flash_Read
* @see Flash_Write
* @see Flash_Erase
* @see Flash_RegisterWrite
* @see Flash_RegisterRead
* @see Flash_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* <tr><td> 11/10/2015 </td><td> 1.0.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
uint32_t Flash_RegisterRead(uint32_t Address)
{
   uint32_t * const RegisterPointer = (uint32_t *) Address;
   
   return *RegisterPointer;
}

/******************************************************************************
* Function : Flash_CallbackRegister()
*//** 
* \b Description:
*
* This function is used to set the callback functions of the flash driver. By 
* default, the callbacks are initialized to a NULL pointer. The driver may 
* contain more than one possible callback, so the function will take a parameter
* to configure the specified callback. 
*
* PRE-CONDITION: The FlashCallback_t has been populated
* PRE-CONDITION: The callback function exists within memory.
*
* POST-CONDITION: The specified callback function will be registered with the
* driver. 
*
* @param       Function is the callback function that will be registered
* @param       CallbackFunction is a function pointer to the desired function
*
* @return      None.
*
* \b Example:
* @code
*    FlashCallback_t Flash_Function = FLASH_SAMPLE_COMPLETE; 
*    
*    Flash_CallbackRegister(Flash_Function, Flash_SampleAverage);
* @endcode
*
* @see Flash_Init
* @see Flash_Read
* @see Flash_Write
* @see Flash_Erase
* @see Flash_RegisterWrite
* @see Flash_RegisterRead
* @see Flash_CallbackRegister
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
void Flash_CallbackRegister(FlashCallback_t Function, TYPE (*CallbackFunction)(type))
{


}

/*lint +e715 */
/*************** END OF FUNCTIONS ***************************************************************************/
