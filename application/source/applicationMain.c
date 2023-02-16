/*
 * Copyright (C) 2021-2023 Roger Clark, VK3KYY / G4KYF
 *                         Colin Durbridge, G4EML
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

#include <interfaces/HX8353E.h>
#include <stdbool.h>
#include <memory.h>
#include <malloc.h>
#include <stdio.h>

#include "main.h"



volatile bool mainIsRunning = true;
int lastVolume = 0;



#if false
static void hexDump(uint8_t *ptr, int len)
{
	char buf[8];
	char msg[128];

	msg[0] = 0;
	for (int i = 0; i < len; i++)
	{
		if ((i != 0) && (i%16 == 0))
		{
			strcat(msg,"\n");
			CDC_Transmit_FS((uint8_t *)msg,strlen(msg));
			msg[0] = 0;
		}
		else
		{
			sprintf(buf,"%02x ",*ptr);
			strcat(msg,buf);
		}
		ptr++;
		osDelay(1);
	}
}
#endif




void applicationMainTask(void)
{

	//HAL_GPIO_WritePin(PWR_SW_GPIO_Port, PWR_SW_Pin, GPIO_PIN_SET);// keep the power on

	//osDelay(500);
	//USB_DEBUG_printf("FW started\n");
	osDelay(1000);
	displayPrintCentered(64,"OS is running!", FONT_SIZE_3);

	displayRender();

	while(true)
	{
		HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
		osDelay(1000);
	}
}
