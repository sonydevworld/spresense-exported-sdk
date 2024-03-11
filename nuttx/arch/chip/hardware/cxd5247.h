/*****************************************************************************
 * arch/arm/src/cxd56xx/hardware/cxd5247.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 *****************************************************************************/

#ifndef __ARCH_ARM_SRC_CXD56XX_HARDWARE_CXD5247_H
#define __ARCH_ARM_SRC_CXD56XX_HARDWARE_CXD5247_H

/*****************************************************************************
 * Included Files
 *****************************************************************************/

#include <stdint.h>
#include <stdbool.h>

/*****************************************************************************
 * Pre-processor Definitions
 *****************************************************************************/

#define CXD56_MIC_MAXCH  (8)
#define CXD56_AMIC_MAXCH (4)

#define CXD5247_MIC_GAIN_MAX    150
#define CXD5247_MIC_PGAGAIN_MAX 60

#define CXD5247_MICID_AMIC(x) ((x) + 1)
#define CXD5247_MICID_DMIC(x) ((x) + 5)
#define CXD5247_MICID_NOTUSED (15)

#define CXD5247_MIC_AMIC    (1)
#define CXD5247_MIC_DMIC    (2)
#define CXD5247_MIC_ANADIG  (3)

/*****************************************************************************
 * Public Function Prototypes
 *****************************************************************************/

/* For CXD5247 Control */

int cxd5247_audio_mute(bool en);
int cxd5247_audio_config(bool is_mck24m, uint32_t samplerate,
                         uint8_t *chmaps, int mic_gain);
int cxd5247_audio_micgain(int mic_gain, uint8_t *chmaps);
int cxd5247_audio_poweroff(void);
int cxd5247_audio_inputoff(void);
int cxd5247_audio_outputoff(void);
uint8_t cxd5247_get_micdev(FAR uint8_t *chmaps);

#endif /* __ARCH_ARM_SRC_CXD56XX_HARDWARE_CXD5247_H */
