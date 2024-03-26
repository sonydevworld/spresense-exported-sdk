/****************************************************************************
 * arch/arm/src/cxd56xx/cxd56_audio_dma.h
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
 ****************************************************************************/

#ifndef __ARCH_ARM_SRC_CXD56XX_CXD56_AUDIO_DMA_H
#define __ARCH_ARM_SRC_CXD56XX_CXD56_AUDIO_DMA_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/audio/audio.h>
#include <stdint.h>
#include "cxd56_audio_driver.h"

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

int cxd56_auddma_enqueue(FAR struct cxd56_dmachannel_s *dmach,
                         FAR struct ap_buffer_s *apb);
int cxd56_auddma_start(FAR struct cxd56_dmachannel_s *dmach);
bool cxd56_auddma_stop(FAR struct cxd56_dmachannel_s *dmach);
bool cxd56_auddma_shutdown(FAR struct cxd56_dmachannel_s *dmach);
int cxd56_auddma_pause(FAR struct cxd56_dmachannel_s *dmach);
int cxd56_auddma_resume(FAR struct cxd56_dmachannel_s *dmach);
int cxd56_auddma_cancelbuff(FAR struct cxd56_dmachannel_s *dmach);
void cxd56_auddma_init(void);

struct cxd56_dmachannel_s *cxd56_get_micdmach(void);
struct cxd56_dmachannel_s *cxd56_get_i2s0out_dmach(void);
struct cxd56_dmachannel_s *cxd56_get_i2s1out_dmach(void);
struct cxd56_dmachannel_s *cxd56_get_i2s1in_dmach(void);

#endif /* __ARCH_ARM_SRC_CXD56XX_CXD56_AUDIO_DMA_H */
