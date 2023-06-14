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

#ifndef __MOSSFW_LOCK_H
#define __MOSSFW_LOCK_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <pthread.h>

/****************************************************************************
 * Public Data Types
 ****************************************************************************/

typedef pthread_t mossfw_thread_t;
typedef pthread_mutex_t mossfw_lock_t;
typedef pthread_cond_t mossfw_condition_t;
typedef void *(*mossfw_start_t)(void *);

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define mossfw_lock_init(l)  pthread_mutex_init((l), NULL)
#define mossfw_lock_fin(l)  pthread_mutex_destroy(l)
#define mossfw_lock_take(l)  pthread_mutex_lock(l)
#define mossfw_lock_give(l)  pthread_mutex_unlock(l)
#define mossfw_lock_trytake(l)  pthread_mutex_trylock(l)
#define mossfw_condition_init(c) pthread_cond_init(c, NULL)
#define mossfw_condition_wait(c,l) pthread_cond_wait(c,l)
#define mossfw_condition_notice(c) pthread_cond_signal(c)
#define mossfw_create_thread(t,f,a) pthread_create(t, NULL, f, a)
#define mossfw_thread_join(t) pthread_join(*(t), NULL)

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

int mossfw_create_thread_attr(mossfw_thread_t *tid,
                              mossfw_start_t func, void *arg,
                              int prior, int stksz);

#ifdef __cplusplus
}
#endif

#endif  /* __MOSSFW_LOCK_H */
