/****************************************************************************
 * Copyright 2023 Sony Semiconductor Solutions Corporation
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

#ifndef __MOSSFW_DEBUG_H
#define __MOSSFW_DEBUG_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdarg.h>
#include <mossfw/mossfw_lock.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

extern pthread_t avoid_id;

#define ENTER() do{ if (avoid_id != pthread_self()) mossfw_dprint("%p:%s(%d) Enter\n", pthread_self(), __func__, __LINE__); }while(0)
#define LEAVE() do{ if (avoid_id != pthread_self()) mossfw_dprint("%p:%s(%d) LEAVE\n", pthread_self(), __func__, __LINE__); }while(0)
#define WAIT(l) do{ if (avoid_id != pthread_self()) mossfw_dprint("%p:%s(%d) Waiting : %p\n", pthread_self(), __func__, __LINE__, l); }while(0)
#define NOTICE(l) do{ if (avoid_id != pthread_self()) mossfw_dprint("%p:%s(%d) Notice : %p\n", pthread_self(), __func__, __LINE__, l); }while(0)

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

void mossfw_debug_init(void);
void mossfw_dprint(const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif  /* __MOSSFW_DEBUG_H */
