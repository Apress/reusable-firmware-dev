/****************************************************************************
* Title                 :   Serial Peripheral Module
* Filename              :   spi.c
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
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Version   Author         Description 
*  09/01/15   0.5.0   Jacob Beningo   Interface Created.
*  11/10/15   1.0.0   Jacob Beningo   Updated interface.
*
*******************************************************************************/
/** @file spi.c
 *  @brief The implementation for the spi.
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "spi.h"				/* For this module's definitions */
#include "dio.h"

/******************************************************************************
* Constants
*******************************************************************************/
/**
 *  Defines a table of pointers to the spi control 0 registers on the microcontroller.
 */
static TYPE volatile * const spicon1[NUM_SPI_CHANNELS] =
{
  	(TYPE*)&REGISTER1, (TYPE*)&REGISTER1
};

/**
 *  Defines a table of pointers to the spi control 1 registers on the microcontroller.
 */
static TYPE volatile * const spicon2[NUM_SPI_CHANNELS] =
{
  	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2
};

/**
 *  Defines a table of pointers to the spi status registers on the microcontroller.
 */
static TYPE volatile * const spistat[NUM_SPI_CHANNELS] =
{
  	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2
};

/**
 *  Defines a table of pointers to the spi receive buffer registers on the microcontroller.
 */
static TYPE volatile * const spibuflow[NUM_SPI_CHANNELS] =
{
  	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2
};

/**
 *  Defines a table of pointers to the spi bit rate control registers on the microcontroller.
 */
static TYPE volatile * const spibr[NUM_SPI_CHANNELS] =
{
  	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2
};

/**
 *  Defines a pointer to the System Clock Gating Control Register 4 on the microcontroller.
 */
static TYPE volatile * const spigate =(TYPE*)&REGISTER1;

/**
 *  Defines a table of pins for the spi clock gate controls on the microcontroller.
 */
static const TYPE spipins[NUM_SPI_CHANNELS] =
{
  	REGBIT, REGBIT
};

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
 * This variable is used to store the Spi_Transfer delay value for each channel.
 */
static uint32_t TransferDelay[NUM_SPI_CHANNELS] = {0};

/******************************************************************************
* Function Prototypes
*******************************************************************************/
/*
 * The following functions are inline helper functions to keep the complexity
 * of initialization and use of the perihperal functions to a cyclomatic 
 * complexity less than 10.
 */
void Spi_Setup(const SpiTransfer_t * Config);
void Spi_ChipSelectSet(const SpiTransfer_t * Config);
void Spi_ChipSelectClear(const SpiTransfer_t * Config);
void Spi_BaudRateSet(const SpiConfig_t Config);
void Spi_SSSet(const SpiConfig_t Config);
void Spi_CalcDelay(const SpiConfig_t Config);

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : Spi_Init()
*//** 
* \b Description:
*
* This function is used to initialize the Spi based on the configuration table
*  defined in spi_cfg module.
*  
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0) <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: The peripheral is setup with the configuration settings.
*
* @param  		Config is a pointer to the configuration table that contains
*				the initialization for the peripheral.
*
* @return 		void
*
* \b Example:
* @code
* 	const SpiConfig_t *SpiConfig = Spi_ConfigGet();
*
* 	Spi_Init(SpiConfig);
* @endcode
*
* @see Spi_ConfigGet
* @see Spi_Init
* @see Spi_DeInit
* @see Spi_Transfer
* @see Spi_Setup
* @see Spi_ChipSelectSet
* @see Spi_ChipSelectClear
* @see Spi_BaudRateSet
* @see Spi_SSSet
* @see Spi_CalcDelay
* @see Spi_RegisterWrite
* @see Spi_RegisterRead
* @see Spi_CallbackRegister
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
void Spi_Init(const SpiConfig_t * Config)
{

}

/******************************************************************************
* Function : Spi_DeInit()
*//** 
* \b Description:
*
* This function is used to deinitialize the SPI channel. All registers are cleared 
* to the RESET values. 
*  
* PRE-CONDITION: Spi_Init has been called previously <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: The SPI peripheral is no longer intialized
*
* @param  		Channel is the SPI channel i.e. 0, 1, etc that will be deinitialized.
* @return 		void
*
* \b Example:
* @code
* 	const SpiConfig_t *SpiConfig = Spi_ConfigGet();
*
* 	Spi_Init(SpiConfig);
*   Spi_DeInint(SPI0);
* @endcode
*
* @see Spi_ConfigGet
* @see Spi_Init
* @see Spi_DeInit
* @see Spi_Transfer
* @see Spi_Setup
* @see Spi_ChipSelectSet
* @see Spi_ChipSelectClear
* @see Spi_BaudRateSet
* @see Spi_SSSet
* @see Spi_CalcDelay
* @see Spi_RegisterWrite
* @see Spi_RegisterRead
* @see Spi_CallbackRegister
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
void Spi_DeInit(SpiChannel_t Channel)
{

}

/******************************************************************************
* Function : Spi_Transfer()
*//** 
* \b Description:
*
* This function is used to initialize a data transfer on the SPI bus.
*  
* PRE-CONDITION: Spi_Init must be called with valid configuration data <br>
* PRE-CONDITION: SpiTransfer_t must be configured for the specified device <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: Communication will occur based on the configuration structure.
*
* @param  		Config is a configure structure describing the data transfer that 
*               occur.
*
* @return 		void
*
* \b Example:
* @code
* 	const SpiConfig_t *SpiConfig = Spi_ConfigGet();
*
* 	Spi_Init(SpiConfig);
*   Spi_Transfer(AccelerometerConfig);
*   
* @endcode
*
* @see Spi_ConfigGet
* @see Spi_Init
* @see Spi_DeInit
* @see Spi_Transfer
* @see Spi_Setup
* @see Spi_ChipSelectSet
* @see Spi_ChipSelectClear
* @see Spi_BaudRateSet
* @see Spi_SSSet
* @see Spi_CalcDelay
* @see Spi_RegisterWrite
* @see Spi_RegisterRead
* @see Spi_CallbackRegister
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
void Spi_Transfer(const SpiTransfer_t * Config)
{

}

/******************************************************************************
* Function : Spi_Setup()
*//** 
* \b Description:
*
* This function is used to setup the polarity, phase and endianess of a 
* data transfer. This is an inline function and if not inlined should be 
* declared as static.
*  
* PRE-CONDITION: Spi_Init must be called with valid configuration data <br>
* PRE-CONDITION: SpiTransfer_t must be configured for the specified device <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: Peripheral registers will be setup for the transfer.
*
* @param  		Config is a configure structure describing the data transfer that 
*               occur.
*
* @return 		void
*
* \b Example:
* @code
* 	Spi_Setup(Config);
*   
* @endcode
*
* @see Spi_ConfigGet
* @see Spi_Init
* @see Spi_DeInit
* @see Spi_Transfer
* @see Spi_Setup
* @see Spi_ChipSelectSet
* @see Spi_ChipSelectClear
* @see Spi_BaudRateSet
* @see Spi_SSSet
* @see Spi_CalcDelay
* @see Spi_RegisterWrite
* @see Spi_RegisterRead
* @see Spi_CallbackRegister
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
inline void Spi_Setup(const SpiTransfer_t * Config)
{

}

/******************************************************************************
* Function : Spi_ChipSelectSet()
*//** 
* \b Description:
*
* This function is used to select a slave device. It toggles an I/O line
* into the active state of the slave device. This is an inline function and 
* if not inlined should be declared as static.
*  
* PRE-CONDITION: Spi_Init must be called with valid configuration data <br>
* PRE-CONDITION: SpiTransfer_t must be configured for the specified device <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: Slave device will be selected via gpio line.
*
* @param  		Config is a configure structure describing the data transfer that 
*               occur.
*
* @return 		void
*
* \b Example:
* @code
* 	Spi_ChipSelectSet(Config);
*   
* @endcode
*
* @see Spi_ConfigGet
* @see Spi_Init
* @see Spi_DeInit
* @see Spi_Transfer
* @see Spi_Setup
* @see Spi_ChipSelectSet
* @see Spi_ChipSelectClear
* @see Spi_BaudRateSet
* @see Spi_SSSet
* @see Spi_CalcDelay
* @see Spi_RegisterWrite
* @see Spi_RegisterRead
* @see Spi_CallbackRegister
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
inline void Spi_ChipSelectSet(const SpiTransfer_t * Config)
{
	// Select the device
	if(Config->CsPolarity == CS_ACTIVE_LOW)
	{
		Dio_ChannelWrite(Config->ChipSelect, DIO_LOW);
	}
	else
	{
		Dio_ChannelWrite(Config->ChipSelect, DIO_HIGH);
	}
}

/******************************************************************************
* Function : Spi_ChipSelectClear()
*//** 
* \b Description:
*
* This function is used to de-select a slave device.  It toggles an I/O line
* into the inactive state. This is an inline function and 
* if not inlined should be declared as static.
*  
* PRE-CONDITION: Spi_Init must be called with valid configuration data <br>
* PRE-CONDITION: SpiTransfer_t must be configured for the specified device <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: Slave device will be de-selected via gpio line.
*
* @param  		Config is a configure structure describing the data transfer that 
*               occur.
*
* @return 		void
*
* \b Example:
* @code
* 	Spi_ChipSelectClear(Config);
*   
* @endcode
*
* @see Spi_ConfigGet
* @see Spi_Init
* @see Spi_DeInit
* @see Spi_Transfer
* @see Spi_Setup
* @see Spi_ChipSelectSet
* @see Spi_ChipSelectClear
* @see Spi_BaudRateSet
* @see Spi_SSSet
* @see Spi_CalcDelay
* @see Spi_RegisterWrite
* @see Spi_RegisterRead
* @see Spi_CallbackRegister
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
inline void Spi_ChipSelectClear(const SpiTransfer_t * Config)
{
  	// De-Select the device if an op-code is not being set
  	if(Config->CsPolarity == CS_ACTIVE_LOW)
  	{
  		Dio_ChannelWrite(Config->ChipSelect, DIO_HIGH);
  	}
  	else
  	{
  		Dio_ChannelWrite(Config->ChipSelect, DIO_LOW);
  	}
}

/******************************************************************************
* Function : Spi_ChipSelectClear()
*//** 
* \b Description:
*
* This function is used to set the baud rate divider and prescaler register
* values in order to get a SPI clock frequency as close as possible to the
* desired speed. This is an inline function and if not inlined should be 
* declared as static.
*  
* PRE-CONDITION: Spi_Init must be called with valid configuration data <br>
* PRE-CONDITION: SpiTransfer_t must be configured for the specified device <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: Slave device will be de-selected via gpio line.
*
* @param  		Config is a configure structure describing the data transfer that 
*               occur.
*
* @return 		void
*
* \b Example:
* @code
* 	Spi_BaudRateSet(Config);
*   
* @endcode
*
* @see Spi_ConfigGet
* @see Spi_Init
* @see Spi_DeInit
* @see Spi_Transfer
* @see Spi_Setup
* @see Spi_ChipSelectSet
* @see Spi_ChipSelectClear
* @see Spi_BaudRateSet
* @see Spi_SSSet
* @see Spi_CalcDelay
* @see Spi_RegisterWrite
* @see Spi_RegisterRead
* @see Spi_CallbackRegister
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
inline void Spi_BaudRateSet(const SpiConfig_t Config)
{

}

/******************************************************************************
* Function : Spi_SSSet()
*//** 
* \b Description:
*
* This function is used to set the slave select setting for a SPI channel. 
* This is an inline function and if not inlined should be declared as static. 
*  
* PRE-CONDITION: Spi_Init must be called with valid configuration data <br>
* PRE-CONDITION: SpiTransfer_t must be configured for the specified device <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: Slave device will be de-selected via gpio line.
*
* @param  		Config is a configure structure describing the data transfer that 
*               occur.
*
* @return 		void
*
* \b Example:
* @code
* 	Spi_SSSet(Config);
*   
* @endcode
*
* @see Spi_ConfigGet
* @see Spi_Init
* @see Spi_DeInit
* @see Spi_Transfer
* @see Spi_Setup
* @see Spi_ChipSelectSet
* @see Spi_ChipSelectClear
* @see Spi_BaudRateSet
* @see Spi_SSSet
* @see Spi_CalcDelay
* @see Spi_RegisterWrite
* @see Spi_RegisterRead
* @see Spi_CallbackRegister
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
inline void Spi_SSSet(const SpiConfig_t Config)
{

}

/******************************************************************************
* Function : Spi_CalcDelay()
*//** 
* \b Description:
*
* This function is used to caluclate the SPI transfer delay for a channel.
* This is an inline function and if not inlined should be declared as static. 
*  
* PRE-CONDITION: Spi_Init must be called with valid configuration data <br>
* PRE-CONDITION: SpiTransfer_t must be configured for the specified device <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: Slave device will be de-selected via gpio line.
*
* @param  		Config is a configure structure describing the data transfer that 
*               occur.
*
* @return 		void
*
* \b Example:
* @code
* 	Spi_CalcDelay(Config);
*   
* @endcode
*
* @see Spi_ConfigGet
* @see Spi_Init
* @see Spi_DeInit
* @see Spi_Transfer
* @see Spi_Setup
* @see Spi_ChipSelectSet
* @see Spi_ChipSelectClear
* @see Spi_BaudRateSet
* @see Spi_SSSet
* @see Spi_CalcDelay
* @see Spi_RegisterWrite
* @see Spi_RegisterRead
* @see Spi_CallbackRegister
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
inline void Spi_CalcDelay(const SpiConfig_t Config)
{

}

/******************************************************************************
* Function : Spi_RegisterWrite()
*//** 
* \b Description:
*
*  This function is used to directly address and modify a Spi register.  The 
*  function should be used to access specialized functionality in the Spi peripheral
*  that is not exposed by any other function of the interface.
*
* PRE-CONDITION: Address is within the boundaries of the Spi register address space
*
* POST-CONDITION: The register located at Address with be updated with Value
*
* @param  		Address is a register address within the Spi peripheral map
* @param      Value is the value to set the Spi register to
*
* @return 		void
*
* \b Example:
* @code
*    Spi_RegisterWrite(0x1000, 0x15);
* @endcode
*
* @see Spi_ConfigGet
* @see Spi_Init
* @see Spi_DeInit
* @see Spi_Transfer
* @see Spi_Setup
* @see Spi_ChipSelectSet
* @see Spi_ChipSelectClear
* @see Spi_BaudRateSet
* @see Spi_SSSet
* @see Spi_CalcDelay
* @see Spi_RegisterWrite
* @see Spi_RegisterRead
* @see Spi_CallbackRegister
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
void Spi_RegisterWrite(uint32_t Address, uint32_t Value)
{
   uint32_t * const RegisterPointer = (uint32_t *) Address;
   
   *RegisterPointer = Value;
}

/******************************************************************************
* Function : Spi_RegisterRead()
*//** 
* \b Description:
*
* This function is used to directly address a Spi register.  The function 
* should be used to access specialized functionality in the Spi peripheral
* that is not exposed by any other function of the interface.
*
* PRE-CONDITION: Address is within the boundaries of the Spi register address space
*
* POST-CONDITION: The value stored in the register is returned to the caller
*
* @param  		Address is the address of the Spi register to read
*
* @return 		The current value of the Spi register.
*
* \b Example:
* @code
*    SpiValue = Spi_RegisterRead(0x1000);
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
* @see Spi_CallbackRegister
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
uint32_t Spi_RegisterRead(uint32_t Address)
{
   uint32_t * const RegisterPointer = (uint32_t *) Address;
   
   return *RegisterPointer;
}

/******************************************************************************
* Function : Spi_CallbackRegister()
*//** 
* \b Description:
*
* This function is used to set the callback functions of the spi driver. By 
* default, the callbacks are initialized to a NULL pointer. The driver may 
* contain more than one possible callback, so the function will take a parameter
* to configure the specified callback. 
*
* PRE-CONDITION: The SpiCallback_t has been populated <br>
* PRE-CONDITION: The callback function exists within memory.
*
* POST-CONDITION: The specified callback function will be registered with the
* driver. 
*
* @param    Function is the callback function that will be registered
* @param    CallbackFunction is a function pointer to the desired function
*
* @return     None.
*
* \b Example:
* @code
*    SpiCallback_t Spi_Function = SPI_SAMPLE_COMPLETE; 
*    
*    Spi_CallbackRegister(Spi_Function, Spi_SampleAverage);
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
* @see Spi_CallbackRegister
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
void Spi_CallbackRegister(SpiCallback_t Function, TYPE (*CallbackFunction)(type))
{

}


/*** End of File **************************************************************/
