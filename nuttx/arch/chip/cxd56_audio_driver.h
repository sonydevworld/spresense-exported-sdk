/****************************************************************************
 * arch/arm/src/cxd56xx/cxd56_audio_driver.h
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

#ifndef __ARCH_ARM_SRC_CXD56XX_CXD56_AUDIO_DRIVER_H
#define __ARCH_ARM_SRC_CXD56XX_CXD56_AUDIO_DRIVER_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/spinlock.h>
#include <stdint.h>
#include <nuttx/audio/audio.h>
#include <nuttx/queue.h>
#include "arch/chip/cxd56_audio_lower.h"
#include "cxd56_audio_reg.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define AUDSTATE_SHUTDOWN    (0)
#define AUDSTATE_INITIAL     (1)
#define AUDSTATE_CONFIGURED  (2)
#define AUDSTATE_STARTING    (3)
#define AUDSTATE_PAUSED      (4)
#define AUDSTATE_STARTED     (5)
#define AUDSTATE_STOPPING    (6)
#define AUDSTATE_CLOSING     (7)
#define AUDSTATE_PAUSING     (8)
#define AUDSTATE_COMPLETING  (9)

#define STATECHANGE(d, st) ((d)->state = AUDSTATE_##st)

#define AUDSTATECHG_SHUTDOWN(d)   STATECHANGE(d, SHUTDOWN)
#define AUDSTATECHG_INITIAL(d)    STATECHANGE(d, INITIAL)
#define AUDSTATECHG_CONFIGURED(d) STATECHANGE(d, CONFIGURED)
#define AUDSTATECHG_STARTING(d)   STATECHANGE(d, STARTING)
#define AUDSTATECHG_PAUSED(d)     STATECHANGE(d, PAUSED)
#define AUDSTATECHG_STARTED(d)    STATECHANGE(d, STARTED)
#define AUDSTATECHG_STOPPING(d)   STATECHANGE(d, STOPPING)
#define AUDSTATECHG_CLOSING(d)    STATECHANGE(d, CLOSING)
#define AUDSTATECHG_PAUSING(d)    STATECHANGE(d, PAUSING)
#define AUDSTATECHG_COMPLETING(d) STATECHANGE(d, COMPLETING)

#define AUDSTATE_IS_SHUTDOWN(d)   ((d)->state == AUDSTATE_SHUTDOWN)
#define AUDSTATE_IS_INITIAL(d)    ((d)->state == AUDSTATE_INITIAL)
#define AUDSTATE_IS_CONFIGURED(d) ((d)->state == AUDSTATE_CONFIGURED)
#define AUDSTATE_IS_STARTING(d)   ((d)->state == AUDSTATE_STARTING)
#define AUDSTATE_IS_PAUSED(d)     ((d)->state == AUDSTATE_PAUSED)
#define AUDSTATE_IS_STARTED(d)    ((d)->state == AUDSTATE_STARTED)
#define AUDSTATE_IS_STOPPING(d)   ((d)->state == AUDSTATE_STOPPING)
#define AUDSTATE_IS_CLOSING(d)    ((d)->state == AUDSTATE_CLOSING)
#define AUDSTATE_IS_PAUSING(d)    ((d)->state == AUDSTATE_PAUSING)
#define AUDSTATE_IS_COMPLETING(d) ((d)->state == AUDSTATE_COMPLETING)

#define AUDSTATE_IS_DMA_RUNNING(d)                      \
  (AUDSTATE_IS_STARTED(d)  || AUDSTATE_IS_PAUSING(d) || \
   AUDSTATE_IS_STOPPING(d) || AUDSTATE_IS_COMPLETING(d))

#define AUDSTATE_HAS_RESOURCE(d)                          \
  (AUDSTATE_IS_DMA_RUNNING(d) || AUDSTATE_IS_PAUSED(d) || \
   AUDSTATE_IS_STARTING(d)    || AUDSTATE_IS_CLOSING(d))

#define CXD56_AUD_I2S0       (1 << 20)
#define CXD56_AUD_I2S1       (1 << 21)
#define CXD56_AUD_I2SDEV     (1 << 24)
#define CXD56_AUD_MICDEV     (1 << 25)

#define IS_AUDIO_INPUT(d)  ((d)->type & AUDIO_TYPE_INPUT)
#define IS_AUDIO_OUTPUT(d) ((d)->type & AUDIO_TYPE_OUTPUT)
#define IS_AUDIO_I2SDEV(d) ((d)->type & CXD56_AUD_I2SDEV)
#define IS_AUDIO_MICDEV(d) ((d)->type & CXD56_AUD_MICDEV)
#define IS_AUDIO_I2S0DEV(d) ((d)->type & CXD56_AUD_I2S0)
#define IS_AUDIO_I2S1DEV(d) ((d)->type & CXD56_AUD_I2S1)

#define AUDDISTINATION_MEM  (0)
#define AUDDISTINATION_SPK  (1)
#define AUDDISTINATION_I2S  (2)

/****************************************************************************
 * Public Types
 ****************************************************************************/

struct cxd56_aud_dmaref_s
{
  spinlock_t uselock; /* Lock for the counter */
  int        usecnt;  /* dma user counter */
};

struct cxd56_dmachannel_s
{
  struct audio_lowerhalf_s lower; /* Inherit lower-half */

  int type;
  int bitwidth;
  int channels;

  spinlock_t        dma_lock;
  volatile int state;
  struct dq_queue_s dma_pendq;
  struct dq_queue_s dma_runq;

  uint32_t cpu_intr_no;   /* CUP Interrupt Number */
  uint32_t cpu_intr_bit;
  xcpt_t isr;             /* Interrupt service routine */

  /* Registers for controlling DMA */

  const cxd56_aureg_t *addr;
  const cxd56_aureg_t *smpls;
  const cxd56_aureg_t *cmd;
  const cxd56_aureg_t *bitw;
  const cxd56_aureg_t *fifolen;
  const cxd56_aureg_t *errmon;
  const cxd56_aureg_t *status;

  const cxd56_aureg_t *chsel;

  const uint32_t intrbit_done;
  const uint32_t intrbit_err;
  const uint32_t intrbit_smp;
  const uint32_t intrbit_cmb;

  const cxd56_aureg_t *intr_stat;
  const cxd56_aureg_t *intr_mask;

  CODE int (*hwresource)(FAR struct cxd56_dmachannel_s *dma_ch, bool en);
  CODE int (*hwresource_irq)(FAR struct cxd56_dmachannel_s *dma_ch, bool en);
  CODE void (*chassign)(FAR struct cxd56_dmachannel_s *dma_ch);
  CODE int (*irqen)(FAR struct cxd56_dmachannel_s *dmach, bool en);
  void *irq_arg;

  /* Related on NuttX audio framework */

  CODE void (*setvolume)(uint32_t vol);
  CODE uint8_t (*maxch)(FAR struct cxd56_dmachannel_s *dmach);
  uint8_t caps;
  uint16_t supfs;
  uint16_t fcaps;
  bool sysinited;
  uint16_t volgain;
  int distination;
};

struct cxd56_i2sdmachannel_s
{
  struct cxd56_dmachannel_s dmach;  /* Inherit */
  struct cxd56_aud_dmaref_s *ref;
};

#endif /* __ARCH_ARM_SRC_CXD56XX_CXD56_AUDIO_DRIVER_H */
