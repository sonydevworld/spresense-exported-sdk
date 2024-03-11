/****************************************************************************
 * arch/arm/src/cxd56xx/cxd56_audio_reg.h
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

#ifndef __ARCH_ARM_SRC_CXD56XX_CXD56_AUDIO_REG_H
#define __ARCH_ARM_SRC_CXD56XX_CXD56_AUDIO_REG_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdint.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* #define DEBUG_AUDIO_REG */

#define cxd56_raureg(reg)        (cxd56_read_aureg_addr(&(reg)))
#define cxd56_raureg32(reg)      (*((volatile uint32_t *)(reg).addr))
#define cxd56_waureg(reg, val)   (cxd56_write_aureg_addr(&(reg), (val)))
#define cxd56_waureg32(reg, val) (*((volatile uint32_t *)(reg).addr) = (val))

/****************************************************************************
 * Public Types
 ****************************************************************************/

struct cxd56_aureg_s
{
  uint32_t addr;
  uint32_t pos;
  uint32_t len;
#ifdef DEBUG_AUDIO_REG
  const char *regname;
#endif
};
typedef struct cxd56_aureg_s cxd56_aureg_t;

#ifdef CXD56_AUREGDEF
#undef CXD56_AUREGDEF
#endif

#ifdef CXD56_AUINTREGDEF
#undef CXD56_AUINTREGDEF
#endif

/* Register definition macros for Audio Registers.
 * See cxd56_audio_regdef.h for details of registers.
 */

#define CXD56_AUREGDEF(ofs,len,pos,name) \
        extern const cxd56_aureg_t AUREG_##name
#define CXD56_AUINTREGDEF(ofs,len,pos,name) \
        extern const cxd56_aureg_t AUREG_##name

#include "cxd56_audio_regdef.h"

#undef CXD56_AUREGDEF
#undef CXD56_AUINTREGDEF

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

uint32_t cxd56_read_aureg_addr(const cxd56_aureg_t *reg);
void cxd56_write_aureg_addr(const cxd56_aureg_t *reg, uint32_t val);

#endif  /* __ARCH_ARM_SRC_CXD56XX_CXD56_AUDIO_REG_H */
