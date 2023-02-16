/*
 * Copyright (C) 2019      Kai Ludwig, DG4KLU
 * Copyright (C) 2019-2023 Roger Clark, VK3KYY / G4KYF
 *                         Daniel Caujolle-Bert, F1RMB
 *
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer
 *    in the documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. Use of this source code or binary releases for commercial purposes is strictly forbidden. This includes, without limitation,
 *    incorporation in a commercial product or incorporation into a product or project which allows commercial use.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include <stdarg.h>

#include "interfaces/usb_com.h"
#include "interfaces/SPI_Flash.h"
#include "interfaces/uiLocalisation.h"
#include "main.h"

#define GITVERSIONREV GITVERSION

enum CPS_ACCESS_AREA
{
	CPS_ACCESS_FLASH = 1,
	CPS_ACCESS_EEPROM = 2,
	CPS_ACCESS_MCU_ROM = 5,
	CPS_ACCESS_DISPLAY_BUFFER = 6,
	CPS_ACCESS_WAV_BUFFER = 7,
	CPS_COMPRESS_AND_ACCESS_AMBE_BUFFER = 8,
	CPS_ACCESS_RADIO_INFO = 9,
};

volatile int com_request = 0;
volatile uint8_t com_requestbuffer[COM_REQUESTBUFFER_SIZE];
volatile uint8_t usbComSendBuf[COM_BUFFER_SIZE];

int sector = -1;
volatile int comRecvMMDVMIndexIn = 0;
volatile int comRecvMMDVMIndexOut = 0;
volatile int comRecvMMDVMFrameCount = 0;

bool isCompressingAMBE = false;

volatile static bool hasToReply = false;
volatile static uint32_t replyLength = 0;

volatile bool usbIsResetting = false;
bool vfoDataWasWritten = false;// flag that initially VFO data in settings battery RAM has not be written back to codeplug
bool vfoDataWasRead = false;// flag that initially VFO data in settings battery RAM need to be written to the codeplug

void tick_com_request(void)
{}


void USB_DEBUG_PRINT(char *str)
{
	strncpy((char *)usbComSendBuf, str, COM_BUFFER_SIZE);
	usbComSendBuf[COM_BUFFER_SIZE - 1] = 0; // SAFETY: strncpy won't NULL terminate the buffer if length is exceeding.

	CDC_Transmit_FS((uint8_t *)usbComSendBuf, strlen((char *)usbComSendBuf));
}

void USB_DEBUG_printf(const char *format, ...)
{
	char buf[COM_BUFFER_SIZE];
	va_list params;

	va_start(params, format);
	vsnprintf(buf, (sizeof(buf) - 2), format, params);
	//strcat(buf, "\n");
	va_end(params);
	USB_DEBUG_PRINT(buf);
}


extern USBD_HandleTypeDef hUsbDeviceFS;

bool USB_DeviceIsResetting(void)
{


	return usbIsResetting;
}
