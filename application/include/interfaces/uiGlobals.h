/*
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
#ifndef _OPENGD77_UIGLOBALS_H_
#define _OPENGD77_UIGLOBALS_H_

#include <stdint.h>
#include <stdbool.h>
#include <time.h>




#define DISPLAY_H_EXTRA_PIXELS                32
#define DISPLAY_H_OFFSET                     (DISPLAY_H_EXTRA_PIXELS / 2)
#define DISPLAY_V_EXTRA_PIXELS                64
#define DISPLAY_V_OFFSET                     (DISPLAY_V_EXTRA_PIXELS / 2)
#define MENU_ENTRY_HEIGHT                     16
#define SQUELCH_BAR_H                          9
#define V_OFFSET                               0
#define OVERRIDE_FRAME_HEIGHT                 16
#define VFO_LETTER_Y_OFFSET                    8
#define LH_ENTRY_V_OFFSET                      0
#define DISPLAY_Y_POS_HEADER                   2
#define DISPLAY_X_POS_MENU_OFFSET			   4
#define DISPLAY_Y_POS_MENU_START             (16 + MENU_ENTRY_HEIGHT)
#define DISPLAY_Y_POS_MENU_ENTRY_HIGHLIGHT    64
#define DISPLAY_Y_POS_BAR                     10
#define DISPLAY_Y_POS_CONTACT                 (16 + 8)
#define DISPLAY_Y_POS_CONTACT_TX              (34 + 32)
#define DISPLAY_Y_POS_CONTACT_TX_FRAME        (34 + 16)
#define DISPLAY_Y_POS_CHANNEL_FIRST_LINE      (32 + 32)
#define DISPLAY_Y_POS_CHANNEL_SECOND_LINE     (48 + 48)
#define DISPLAY_Y_POS_SQUELCH_BAR             16
#define DISPLAY_Y_POS_CSS_INFO                (16 + 8)
#define DISPLAY_Y_POS_SQL_INFO                (25 + 8)
#define DISPLAY_Y_POS_TX_TIMER                (8 + 16)
#define DISPLAY_Y_POS_RX_FREQ                 (40 + 40)
#define DISPLAY_Y_POS_TX_FREQ                 (48 + 48)
#define DISPLAY_Y_POS_ZONE                    (50 + 64)
#define DISPLAY_Y_POS_RSSI_VALUE              (18 + 16)
#define DISPLAY_Y_POS_RSSI_BAR                (40 + 32)
#define TITLE_BOX_HEIGHT                      21










#endif
