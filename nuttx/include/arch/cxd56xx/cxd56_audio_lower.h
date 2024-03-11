/*****************************************************************************
 * arch/arm/include/cxd56xx/cxd56_audio_lower.h
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

#ifndef __ARCH_ARM_INCLUDE_CXD56XX_CXD56_AUDIO_LOWER_H
#define __ARCH_ARM_INCLUDE_CXD56XX_CXD56_AUDIO_LOWER_H

/*****************************************************************************
 * Included Files
 *****************************************************************************/

#include <nuttx/compiler.h>
#include <stdbool.h>

/*****************************************************************************
 * Public Data Types
 *****************************************************************************/

struct cxd56_audio_lower_s
{
  uint8_t *(*chmaps)(void);
  int      (*clksrc)(void);
  int      (*clkdiv)(void);
  bool     (*is_mclk24m)(void);
  int      (*ext_mute)(bool);
  int      (*ext_micen)(bool);
};

typedef struct cxd56_audio_lower_s cxd56_audio_lower_t;

/*****************************************************************************
 * Public Function Prototypes
 *****************************************************************************/

struct cxd56_audio_lower_s *cxd56_audio_lower(void);

#endif /* __ARCH_ARM_INCLUDE_CXD56XX_CXD56_AUDIO_LOWER_H */
