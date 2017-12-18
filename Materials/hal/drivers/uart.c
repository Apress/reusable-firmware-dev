/****************************************************************************
* Title                 :   UART Driver
* Filename              :   uart.c
* Author                :   Jacob W. Beningo
* Origin Date           :   08/09/2012
* Version               :   1.0.0
* Compiler              :   TBD
* Target                :   TBD
* Copyright             :   Beningo Engineering
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
*  11/10/15   1.0.0   Jacob Beningo   Interface updated
*
*******************************************************************************/
/** @file uart.c
 *  @brief The implementation for the uart. 
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "uart.h"				/* For this module's definitions	 */
#include "constants.h"			/* For REGBIT, ENABLED, DISABLED definitions */

/******************************************************************************
* Constants
*******************************************************************************/

/**
 *  Defines a table of pointers to the uart control 0 registers on the microcontroller.
 */
static TYPE volatile * const uartctl1[NUM_UART_CHANNELS] =
{
  	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2
};

/**
 *  Defines a table of pointers to the uart control 1 registers on the microcontroller.
 */
static TYPE volatile * const uartctl2[NUM_UART_CHANNELS] =
{
  	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2
};

/**
 *  Defines a table of pointers to the uart status registers on the microcontroller.
 */
static TYPE volatile * const uartstat1[NUM_UART_CHANNELS] =
{
  	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2
};

/**
 *  Defines a table of pointers to the uart status registers on the microcontroller.
 */
static TYPE volatile * const uartstat2[NUM_UART_CHANNELS] =
{
  	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2
};

/**
 *  Defines a table of pointers to the uart control 1 registers on the microcontroller.
 */
static TYPE volatile * const uartctl3[NUM_UART_CHANNELS] =
{
  	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2
};

/**
 *  Defines a table of pointers to the uart receive buffer on the microcontroller.
 */
static TYPE volatile * const uartrx[NUM_UART_CHANNELS] =
{
  	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2
};

/**
 *  Defines a table of pointers to the uart receive buffer on the microcontroller.
 */
static TYPE volatile * const uarttx[NUM_UART_CHANNELS] =
{
  	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2
};

/**
 *  Defines a table of pointers to the uart control 1 registers on the microcontroller.
 */
static TYPE volatile * const uartctl4[NUM_UART_CHANNELS] =
{
  	(TYPE*)&REGISTER1, (TYPE*)&REGISTER2
};

/**
 * Defines the Interupt IRQ values for each i2c channel
 */
static TYPE UartIrqValue[NUM_UART_CHANNELS] =
{
	INT_UART0,			/**< UART0 irq value */
	INT_UART1,			/**< UART1 irq value */
	INT_UART2,			/**< UART2 irq value */
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
 * Character array used to print hex values
 */
const unsigned char CharacterArray[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

/**
 * This table defines the uart register values for common system clock frequencies 
 * and UART baud rates.
 */
const UartBaud_t UartBaudTable[] =
{
//    Clock     Baud            
//   Freq(Hz)   Rate	  UCBRx	  UCBRSx  UCBRFx   Oversample	
//
	{1000000,	9600,		6,		0,		8,		ENABLED		},
	{1000000,	19200,		3,		0,		4,		ENABLED		},
	{1000000,	38400,		26,		0,		0,		DISABLED	},
	{1000000,	57600,		1,		7,		0,		ENABLED		},
	{1000000,	115200,		8,		6,		0,		DISABLED	},
	
	{4000000,	9600,		26,		0,		1,		ENABLED		},
	{4000000,	19200,		13,		0,		0,		ENABLED		},
	{4000000,	38400,		6,		0,		7,		ENABLED		},
	{4000000,	57600,		4,		5,		3,		ENABLED		},
	{4000000,	115200,		2,		3,		2,		ENABLED		},
	
	{8000000,	9600,		52,		0,		1,		ENABLED		},
	{8000000,	19200,		26,		0,		1,		ENABLED		},
	{8000000,	38400,		13,		0,		0,		ENABLED		},
	{8000000,	57600,		8,		0,		11,		ENABLED		},
	{8000000,	115200,		4,		5,		3,		ENABLED		},
	
	{12000000,	9600,		78,		0,		2,		ENABLED		},
	{12000000,	19200,		39,		0,		1,		ENABLED		},
	{12000000,	38400,		19,		0,		8,		ENABLED		},
	{12000000,	57600,		13,		0,		0,		ENABLED		},
	{12000000,	115200,		6,		0,		8,		ENABLED		},
	
	{16000000,	9600,		104,	0,		3,		ENABLED		},
	{16000000,	19200,		52,		0,		1,		ENABLED		},
	{16000000,	38400,		26,		0,		1,		ENABLED		},
	{16000000,	57600,		17,		0,		6,		ENABLED		},
	{16000000,	115200,		8,		0,		11,		ENABLED		},
};

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void Uart_IsrModeSet(UartChannel_t Channel, const UartConfig_t *Config);
void Uart_ParitySet(UartChannel_t Channel, const UartConfig_t *Config);

/******************************************************************************
* Functions
*******************************************************************************/
/******************************************************************************
* Function : Uart_Init()
*//** 
* \b Description:
*
* This function is used to initialize the Uart based on the configuration table
*  defined in uart_cfg module.
*  
* PRE-CONDITION: Configuration table needs to populated (sizeof > 0) <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: The uart peripheral is setup with the configuration settings.
*
* @param  		Config is a pointer to the configuration table that contains
*				the initialization for the peripheral.
*
* @return 		void
*
* \b Example:
* @code
* 	const UartConfig_t *UartConfig = Uart_ConfigGet();
*
* 	Uart_Init(UartConfig);
* @endcode
*
* @see Uart_Init
* @see Uart_ParitySet
* @see Uart_IsrModeSet
* @see Uart_BaudRateSet
* @see Uart_CharGet
* @see Uart_IsDataPresent
* @see Uart_CharPut
* @see Uart_RegisterWrite
* @see Uart_RegisterWrite
* @see Uart_CallbackRegister
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
void Uart_Init(const UartConfig_t *Config)
{

}

/******************************************************************************
* Function : Uart_ParitySet()
*//** 
* \b Description:
*
* This function is used to set the Uart transmission parity.
*  
* PRE-CONDITION: The Uart_Init function is called with valid configuration. <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: The uart channel is configured with the provided parity.
*
* @param  		Config - Pointer to UartConfig_t.
* @param		Channel - uint8_t, Uart channel number.
*
* @return 		void
*
* \b Example:
* @code
* 	const UartConfig_t *UartConfig = Uart_GetConfig();
*
* 	Uart_Init(UartConfig);
* @endcode
*
* @see Uart_Init
* @see Uart_ParitySet
* @see Uart_IsrModeSet
* @see Uart_BaudRateSet
* @see Uart_CharGet
* @see Uart_IsDataPresent
* @see Uart_CharPut
* @see Uart_RegisterWrite
* @see Uart_RegisterWrite
* @see Uart_CallbackRegister
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
void Uart_ParitySet(UartChannel_t Channel, const UartConfig_t *Config)
{

}

/******************************************************************************
* Function : Uart_IsrModeSet()
*//** 
* \b Description:
*
* This function is used to set the ISR mode.
*  
* PRE-CONDITION: The Uart_Init function is called with valid configuration. <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: The uart channel interrupt is configured
*
* @param		Channel - uint8_t, Uart channel number.
* @param  		Config - Pointer to UartConfig_t.
*
* @return 		void
*
* \b Example:
* @code
* 	const UartConfig_t *UartConfig = Uart_GetConfig();
*
* 	Uart_Init(UartConfig);
* @endcode
*
* @see Uart_Init
* @see Uart_ParitySet
* @see Uart_IsrModeSet
* @see Uart_BaudRateSet
* @see Uart_CharGet
* @see Uart_IsDataPresent
* @see Uart_CharPut
* @see Uart_RegisterWrite
* @see Uart_RegisterWrite
* @see Uart_CallbackRegister
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
void Uart_IsrModeSet(UartChannel_t Channel, const UartConfig_t *Config)
{

}

/******************************************************************************
* Function : Uart_BaudRateSet()
*//** 
* \b Description:
*
* This function is used to set channel baud rate
*  
* PRE-CONDITION: The Uart_Init function is called with valid configuration. <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: The uart channel data rate is set.
*
* @param		Channel - uint8_t, Uart channel number.
* @param  		Config - Pointer to UartConfig_t.
*
* @return 		void
*
* \b Example:
* @code
* 	Uart_Init(UartConfig_t UartConfig)
* 	{
* 		Uart_SetBaud(UartConfig);
* 	}
* @endcode
*
* @see Uart_Init
* @see Uart_ParitySet
* @see Uart_IsrModeSet
* @see Uart_BaudRateSet
* @see Uart_CharGet
* @see Uart_IsDataPresent
* @see Uart_CharPut
* @see Uart_RegisterWrite
* @see Uart_RegisterWrite
* @see Uart_CallbackRegister
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
void Uart_BaudRateSet(UartChannel_t Channel, const UartConfig_t * Config)
{

}

/******************************************************************************
* Function : Uart_CharGet()
*//** 
* \b Description:
*
* This function is used to get a character from the uart.
*  
* PRE-CONDITION: The Uart_Init function is called with valid configuration. <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: The uart channel data is received.
*
* @param		Channel - uint8_t, Uart channel number.
*
* @return 		uint8_t - the data byte
*
* \b Example:
* @code
*    uint8_t uartByte = Uart_GetChar(UART_0);
* @endcode
*
* @see Uart_Init
* @see Uart_ParitySet
* @see Uart_IsrModeSet
* @see Uart_BaudRateSet
* @see Uart_CharGet
* @see Uart_IsDataPresent
* @see Uart_CharPut
* @see Uart_RegisterWrite
* @see Uart_RegisterWrite
* @see Uart_CallbackRegister
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
uint8_t Uart_CharGet(UartChannel_t Channel)
{
    uint8_t Temp;

    Temp = *uartrx[Channel];
   
    return Temp;
}

/******************************************************************************
* Function : Uart_IsDataPresent()
*//** 
* \b Description:
*
* This routine checks to see if there is a new byte in UART reception buffer.
* Uart_Init must be called prior to calling this routine.
*  
* PRE-CONDITION: The Uart_Init function is called with valid configuration. <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: State of the receive buffer is updated.
*
* @param		Channel - uint8_t, Uart channel number.
*
* @return 		0, No new data received. 1, Data is in the receive buffer.
*
* \b Example:
* @code
*    uint8_t DataPresent = Uart_IsDataPresent(UART_0);
* @endcode
*
* @see Uart_Init
* @see Uart_ParitySet
* @see Uart_IsrModeSet
* @see Uart_BaudRateSet
* @see Uart_CharGet
* @see Uart_IsDataPresent
* @see Uart_CharPut
* @see Uart_RegisterWrite
* @see Uart_RegisterWrite
* @see Uart_CallbackRegister
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
uint8_t Uart_IsDataPresent(UartChannel_t Channel)
{
	// Mask for the uart receive interrupt flag
	// If interrupt flag is set, return true
	// Else, return false
    if((*uartstat1[Channel] & REGBIT5) == 1)
    {
        return 1;
    }    
  	else
  	{
    	return 0;
   } 	
}

/******************************************************************************
* Function : Uart_CharPut()
*//** 
* \b Description:
*
* This routine writes a character to the transmit FIFO, and then waits for the
* transmit FIFO to be empty. Uart_Init must be called prior to calling this routine.
*  
* PRE-CONDITION: The Uart_Init function is called with valid configuration. <br>
* PRE-CONDITION: The MCU clocks must be configured and enabled.
*
* POST-CONDITION: Data put out on the uart channel
*
* @param     Channel - UartChannelType, Uart channel to use.
* @param     Ch - Byte to be sent.
*
* @return 	 None
*
* \b Example:
* @code
* 	 char test = 'c';
*
*    Uart_PutChar(test, UART_0);
* @endcode
*
* @see Uart_Init
* @see Uart_ParitySet
* @see Uart_IsrModeSet
* @see Uart_BaudRateSet
* @see Uart_CharGet
* @see Uart_IsDataPresent
* @see Uart_CharPut
* @see Uart_RegisterWrite
* @see Uart_RegisterWrite
* @see Uart_CallbackRegister
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
void Uart_CharPut(UartChannel_t Channel, char Ch)
{
	if (0x0a==Ch)
	{
        Ch = 0x0d;
	}

	// Send one byte to the UxTXREG of the specified channel
    *uarttx[Channel] = Ch;

    // Mask for UCBUSY bit in UCAxSTAT register
    // If UCBUSY == 1, transmit is not completed
    // Wait for transmition to finish
//    while((*uartstat[Channel] & REGBIT0) == 1);
}

/******************************************************************************
* Function : Uart_RegisterWrite()
*//** 
* \b Description:
*
*  This function is used to directly address and modify a Uart register.  The 
*  function should be used to access specialized functionality in the Uart peripheral
*  that is not exposed by any other function of the interface.
*
* PRE-CONDITION: Address is within the boundaries of the Uart register address space
*
* POST-CONDITION: The register located at Address with be updated with Value
*
* @param  		Address is a register address within the Uart peripheral map
* @param      Value is the value to set the Uart register to
*
* @return 		void
*
* \b Example:
* @code
*    Uart_RegisterWrite(0x1000, 0x15);
* @endcode
*
* @see Uart_Init
* @see Uart_ParitySet
* @see Uart_IsrModeSet
* @see Uart_BaudRateSet
* @see Uart_CharGet
* @see Uart_IsDataPresent
* @see Uart_CharPut
* @see Uart_RegisterWrite
* @see Uart_RegisterWrite
* @see Uart_CallbackRegister
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
void Uart_RegisterWrite(uint32_t Address, uint32_t Value)
{
   uint32_t * const RegisterPointer = (uint32_t *) Address;
   
   *RegisterPointer = Value;
}

/******************************************************************************
* Function : Uart_RegisterRead()
*//** 
* \b Description:
*
* This function is used to directly address a Uart register.  The function 
* should be used to access specialized functionality in the Uart peripheral
* that is not exposed by any other function of the interface.
*
* PRE-CONDITION: Address is within the boundaries of the Uart register address space
*
* POST-CONDITION: The value stored in the register is returned to the caller
*
* @param  		Address is the address of the Uart register to read
*
* @return 		The current value of the Uart register.
*
* \b Example:
* @code
*    UartValue = Uart_RegisterRead(0x1000);
* @endcode
*
* @see Uart_Init
* @see Uart_ParitySet
* @see Uart_IsrModeSet
* @see Uart_BaudRateSet
* @see Uart_CharGet
* @see Uart_IsDataPresent
* @see Uart_CharPut
* @see Uart_RegisterWrite
* @see Uart_RegisterWrite
* @see Uart_CallbackRegister
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
uint32_t Uart_RegisterRead(uint32_t Address)
{
   uint32_t * const RegisterPointer = (uint32_t *) Address;
   
   return *RegisterPointer;
}

/******************************************************************************
* Function : Uart_CallbackRegister()
*//** 
* \b Description:
*
* This function is used to set the callback functions of the Uart driver. By 
* default, the callbacks are initialized to a NULL pointer. The driver may 
* contain more than one possible callback, so the function will take a parameter
* to configure the specified callback. 
*
* PRE-CONDITION: The UartCallback_t has been populated <br>
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
*    UartCallback_t Uart_Function = Uart_SAMPLE_COMPLETE; 
*    
*    Uart_CallbackRegister(Uart_Function, Uart_SampleAverage);
* @endcode
*
* @see Uart_Init
* @see Uart_ParitySet
* @see Uart_IsrModeSet
* @see Uart_BaudRateSet
* @see Uart_CharGet
* @see Uart_IsDataPresent
* @see Uart_CharPut
* @see Uart_RegisterWrite
* @see Uart_RegisterWrite
* @see Uart_CallbackRegister
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
void Uart_CallbackRegister(UartCallback_t Function, TYPE (*CallbackFunction)(type))
{


}

/*** End of File **************************************************************/
