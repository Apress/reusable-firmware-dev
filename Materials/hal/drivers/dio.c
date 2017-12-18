/*******************************************************************************
* Title                 :   Digital Input / Output (DIO)
* Filename              :   dio.c
* Author                :   Jacob W. Beningo
* Origin Date           :   09/01/2015
* Version               :   1.0.0
* Compiler              :   TBD
* Target                :   TBD
* Notes                 :   None
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
*  11/10/15   1.0.0   Jacob Beningo   Interface released.
*
*******************************************************************************/
/** @file dio.c
 *  @brief The implementation for the dio.
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "dio.h"					/* For this modules definitions */
#include <xxx.h>				   /* For Hardware definitions     */

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
/**
 *  Defines a table of pointers to the peripheral input register on the microcontroller.
 */
static TYPE volatile * const DataIn[NUM_PORTS] =
{
	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2, 
};

/**
 *  Defines a table of pointers to the peripheral data direction register on the
 *  microcontroller.
 */
static TYPE volatile * const DataDirectin[NUM_PORTS] =
{
	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2, 
};

/**
 *  Defines a table of pointers to the peripheral latch register on the
 *  microcontroller
 */
static TYPE volatile * const DataOut[NUM_PORTS] =
{
	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2, 
};

/**
 *  Defines a table of pointers to the peripheral resistor enable register
 *  on the microcontroller
 */
static TYPE volatile * const Resistor[NUM_PORTS] =
{
	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2, 
};

/**
 *  Defines a table of pointers to the ports function select register
 *  on the microcontroller
 */
static TYPE volatile * const Function[NUM_PORTS] =
{
	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2, 
};

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
/******************************************************************************
* Function : Dio_Init()
*//** 
* \b Description:
*
* This function is used to initialize the Dio based on the configuration table
*  defined in dio_cfg module.
*  
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0) <br>
* PRE-CONDITION: NUMBER_OF_CHANNELS_PER_PORT > 0 <br>
* PRE-CONDITION: NUMBER_OF_PORTS > 0 <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: The DIO peripheral is setup with the configuration settings.
*
* @param  		Config is a pointer to the configuration table that contains
*				the initialization for the peripheral.
*
* @return 		void
*
* \b Example:
* @code
* 	const DioConfig_t *DioConfig = Dio_ConfigGet();
*
* 	Dio_Init(DioConfig);
* @endcode
*
* @see Dio_Init
* @see Dio_ChannelRead
* @see Dio_ChannelWrite
* @see Dio_ChannelToggle
* @see Dio_ChannelModeSet
* @see Dio_ChannelDirectionSet
* @see Dio_RegisterWrite
* @see Dio_RegisterRead
* @see Dio_CallbackRegister
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
void Dio_Init(const DioConfig_t * Config)
{
	/* TODO: Define implementation */
}

/******************************************************************************
* Function : Dio_ChannelRead()
*//** 
* \b Description:
*
*  This function is used to read the state of a dio channel (pin)
*
* PRE-CONDITION: The channel is configured as INPUT <br>
* PRE-CONDITION: The channel is configured as GPIO <br>
* PRE-CONDITION: The channel is within the maximum DioChannel_t definition
*
* POST-CONDITION: The channel state is returned
*
* @param  		Channel is the DioChannel_t that represents a pin
*
* @return 		The state of the channel as HIGH or LOW
*
* \b Example:
* @code
*   uint8_t pin = Dio_ReadChannel(PORT1_0);
* @endcode
*
* @see Dio_Init
* @see Dio_ChannelRead
* @see Dio_ChannelWrite
* @see Dio_ChannelToggle
* @see Dio_ChannelModeSet
* @see Dio_ChannelDirectionSet
* @see Dio_RegisterWrite
* @see Dio_RegisterRead
* @see Dio_CallbackRegister
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
DioPinState_t Dio_ChannelRead(DioChannel_t Channel)
{
   /* Read the port associated with the desired pin */
   DioPinState_t PortState = (DioPinState_t)*portsin[Channel/NUM_PINS_PER_PORT];
   
   /* Determine which bit in the port is assocaited with this channel */
   DioPinState_t PinMask = (DioPinState_t)(1UL<<(Channel%NUM_PINS_PER_PORT));
 
   /* Mask the port state with the pin and return the DioPinState */
   return (( PortState & PinMask) ? DIO_HIGH : DIO_LOW);
}

/******************************************************************************
* Function : Dio_ChannelWrite()
*//** 
* \b Description:
*
*  This function is used to write the state of a channel (pin) as either logic
*  high or low through the use of the DioChannel_t enum to select the channel and
*  the DioPinState_t to define the desired state.
*
* PRE-CONDITION: The channel is configured as OUTPUT <br>
* PRE-CONDITION: The channel is configured as GPIO <br>
* PRE-CONDITION: The channel is within the maximum DioChannel_t definition
*
* POST-CONDITION: The channel state will be State
*
* @param  		Channel is the pin to write using the DioChannel_t enum definition
* @param        State is HIGH or LOW as defined in the DioPinState_t enum
*
* @return 		void
*
* \b Example:
* @code
*   Dio_WriteChannel(PORT1_0, LOW);		// Set the PORT1_0 pin low
*   Dio_WriteChannel(PORT1_0, HIGH);	// Set the PORT1_0 pin high
* @endcode
*
* @see Dio_Init
* @see Dio_ChannelRead
* @see Dio_ChannelWrite
* @see Dio_ChannelToggle
* @see Dio_ChannelModeSet
* @see Dio_ChannelDirectionSet
* @see Dio_RegisterWrite
* @see Dio_RegisterRead
* @see Dio_CallbackRegister
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
void Dio_ChannelWrite(DioChannel_t Channel, DioPinState_t State)
{
   if (State == DIO_HIGH)
   {
      *ports[Channel/NUM_PINS_PER_PORT] |= (1UL<<(Channel%NUM_PINS_PER_PORT));
   }
   else
   { 
      *ports[Channel/NUM_PINS_PER_PORT] &= ~ (1UL<<(Channel%NUM_PINS_PER_PORT));
   }
}

/******************************************************************************
* Function : Dio_ChannelToggle()
*//** 
* \b Description:
*
*  This function is used to toggle the current state of a channel (pin).
*
* PRE-CONDITION: The channel is configured as OUTPUT <br>
* PRE-CONDITION: The channel is configured as GPIO <br>
* PRE-CONDITION: The channel is within the maximum DioChannel_t definition
*
* POST-CONDITION:
*
* @param  		Channel is the pin from the DioChannel_t that is to be modified.
*
* @return 		void
*
* \b Example:
* @code
*    Dio_ChannelToggle(PORTA_1);
* @endcode
*
* @see Dio_Init
* @see Dio_ChannelRead
* @see Dio_ChannelWrite
* @see Dio_ChannelToggle
* @see Dio_ChannelModeSet
* @see Dio_ChannelDirectionSet
* @see Dio_RegisterWrite
* @see Dio_RegisterRead
* @see Dio_CallbackRegister
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
void Dio_ChannelToggle(DioChannel_t Channel)
{
   *ptoggle[Channel/NUM_PINS_PER_PORT] |= (1UL<<(Channel%NUM_PINS_PER_PORT));
}

/******************************************************************************
* Function : Dio_ChannelModeSet()
*//** 
* \b Description:
*
*  This function is used to set the mode of an individual channel (pin).  The mode
*  is defined by the DioMode_t enum.  The valid channels (pins) are defined in the
*  DioChannel_t enum.  
*
* PRE-CONDITION: The channel is within the maximum DioChannel_t definition
* PRE-CONDITION: The mode is within the maximum DioMode_t
*
* POST-CONDITION: The channel function will be updated to Mode
*
* @param  		Channel is the pin from DioChannel_t that is to have its function changed
* @param        Mode is the mode that the pin be multiplexed into.  i.e. SPI, UART, etc
*
* @return 		void
*
* \b Example:
* @code
*    Dio_ChannelModeSet(PORTA_1, GPIO);
*    Dio_ChannelModeSet(PORTA_2, SPI_MOSI);
* @endcode
*
* @see Dio_Init
* @see Dio_ChannelRead
* @see Dio_ChannelWrite
* @see Dio_ChannelToggle
* @see Dio_ChannelModeSet
* @see Dio_ChannelDirectionSet
* @see Dio_RegisterWrite
* @see Dio_RegisterRead
* @see Dio_CallbackRegister
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
void Dio_ChannelModeSet(DioChannel_t Channel, DioMode_t Mode)
{
   uint8_t Number = 0;                     // Port Number
   uint8_t Position = 0;                   // Pin Number

   // Calculate the register and channel that needs to be changed.
   Number   = Channel / NUM_PINS_PER_PORT;
   Position = Channel % NUM_PINS_PER_PORT;

   // Clear the pin mux function bits
   *(pinctl[Number] + Position) &= ~(REGBIT8 + REGBIT9 + REGBIT10);

   // Set the pin function select registers
   *(pinctl[Number] + Position) |= (Mode << 8UL);
}

/******************************************************************************
* Function : Dio_ChannelDirectionSet()
*//** 
* \b Description:
*
*  This function is used to set the direction of an individual channel (pin).  The
*  direction is defined by the  PinModeEnum_t enum.  The valid channels (pins) are 
*  defined in the DioChannel_t enum.  
*
* PRE-CONDITION: The channel is within the maximum DioChannel_t definition
* PRE-CONDITION: The pin direction is within the maximum  PinModeEnum_t <br>
* PRE-CONDITION: The pin is mode is set to GPIO
*
* POST-CONDITION: The channel direction will be updated to PinMode
*
* @param  		Channel is the pin from DioChannel_t that is to have its function changed
* @param        Mode is the mode that the pin be multiplexed into.  i.e. SPI, UART, etc
*
* @return 		void
*
* \b Example:
* @code
*    Dio_ChannelDirectionSet(PORTA_1, OUTPUT);
*    Dio_ChannelDirectionSet(PORTA_1, INPUT);
* @endcode
*
* @see Dio_Init
* @see Dio_ChannelRead
* @see Dio_ChannelWrite
* @see Dio_ChannelToggle
* @see Dio_ChannelModeSet
* @see Dio_ChannelDirectionSet
* @see Dio_RegisterWrite
* @see Dio_RegisterRead
* @see Dio_CallbackRegister
*
* <br><b> - HISTORY OF CHANGES - </b>
*  
* <table align="left" style="width:800px">
* <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
* <tr><td> 09/01/2015 </td><td> 0.5.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* <tr><td> 10/22/2015 </td><td> 0.6.0            </td><td> JWB      </td><td> Merged into HAL </td></tr>
* <tr><td> 11/10/2015 </td><td> 1.0.0            </td><td> JWB      </td><td> Interface Created </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
void Dio_ChannelDirectionSet(DioChannel_t Channel, PinModeEnum_t Mode)
{
   uint8_t Number = 0;                     // Port Number
   uint8_t Position = 0;                   // Pin Number

   // Calculate the register and channel that needs to be changed.
   Number   = Channel / NUM_PINS_PER_PORT;
   Position = Channel % NUM_PINS_PER_PORT;

   // Set the Data Direction register bit for this channel
   if(Mode == OUTPUT)
   {
      *portsddr[Number] |= (1UL<<(Position));
   }
   else
   {
      *portsddr[Number] &= ~(1UL<<(Position));
   }
}

/******************************************************************************
* Function : Dio_RegisterWrite()
*//** 
* \b Description:
*
*  This function is used to directly address and modify a Dio register.  The 
*  function should be used to access specialied functionality in the Dio peripheral
*  that is not exposed by any other function of the interface.
*
* PRE-CONDITION: Address is within the boundaries of the Dio register addresss space
*
* POST-CONDITION: The register located at Address with be updated with Value
*
* @param  		Address is a register address within the Dio peripheral map
* @param      Value is the value to set the Dio register to
*
* @return 		void
*
* \b Example:
* @code
*    Dio_RegisterWrite(0x1000, 0x15);
* @endcode
*
* @see Dio_Init
* @see Dio_ChannelRead
* @see Dio_ChannelWrite
* @see Dio_ChannelToggle
* @see Dio_ChannelModeSet
* @see Dio_ChannelDirectionSet
* @see Dio_RegisterWrite
* @see Dio_RegisterRead
* @see Dio_CallbackRegister
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
void Dio_RegisterWrite(uint32_t Address, TYPE Value)
{
   uint32_t * const RegisterPointer = (uint32_t *) Address;
   
   *RegisterPointer = Value;
}

/******************************************************************************
* Function : Dio_RegisterRead()
*//** 
* \b Description:
*
*  This function is used to directly address a Dio register.  The function 
*  should be used to access specialied functionality in the Dio peripheral
*  that is not exposed by any other function of the interface.
*
* PRE-CONDITION: Address is within the boundaries of the Dio register addresss space
*
* POST-CONDITION: The value stored in the register is returned to the caller
*
* @param  		Address is the address of the Dio register to read
*
* @return 		The current value of the Dio register.
*
* \b Example:
* @code
*    DioValue = Dio_RegisterRead(0x1000);
* @endcode
*
* @see Dio_Init
* @see Dio_ChannelRead
* @see Dio_ChannelWrite
* @see Dio_ChannelToggle
* @see Dio_ChannelModeSet
* @see Dio_ChannelDirectionSet
* @see Dio_RegisterWrite
* @see Dio_RegisterRead
* @see Dio_CallbackRegister
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
TYPE Dio_RegisterRead(uint32_t Address)
{
   uint32_t * const RegisterPointer = (uint32_t *) Address;
   
   return *RegisterPointer;
}

/******************************************************************************
* Function : Dio_CallbackRegister()
*//** 
* \b Description:
*
* This function is used to set the callback functions of the dio driver. By 
* default, the callbacks are initialized to a NULL pointer. The driver may 
* contain more than one possible callback, so the function will take a parameter
* to configure the specified callback. 
*
* PRE-CONDITION: The DioCallback_t has been populated
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
*    DioCallback_t Dio_Function = DIO_SAMPLE_COMPLETE; 
*    
*    Dio_CallbackRegister(Dio_Function, Dio_SampleAverage);
* @endcode
*
* @see Dio_Init
* @see Dio_ChannelRead
* @see Dio_ChannelWrite
* @see Dio_ChannelToggle
* @see Dio_ChannelModeSet
* @see Dio_ChannelDirectionSet
* @see Dio_RegisterWrite
* @see Dio_RegisterRead
* @see Dio_CallbackRegister
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
void Dio_CallbackRegister(DioCallback_t Function, TYPE (*CallbackFunction)(type))
{


}

/*************** END OF FUNCTIONS ***************************************************************************/
