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

#ifndef __MOSSFW_RINGBUFFARY_H
#define __MOSSFW_RINGBUFFARY_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdbool.h>
#include <mossfw/mossfw_data.h>
#include <mossfw/mossfw_lock.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Data Types
 ****************************************************************************/

struct mossfw_ringbuffarray_s
{
  mossfw_data_container_t *top;
  mossfw_data_container_t *stored;
  int total_depth;
  int stored_num;
  int stored_bytes;
  int usedidx;
  bool is_stop;
  mossfw_lock_t lock;
  mossfw_condition_t cond;
};
typedef struct mossfw_ringbuffarray_s mossfw_ringbuffarray_t;

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

mossfw_ringbuffarray_t *mossfw_ringbuffarray_create(int depth);
void mossfw_ringbuffarray_delete(mossfw_ringbuffarray_t *ary);

bool mossfw_ringbuffarray_isempty(mossfw_ringbuffarray_t *ary);
bool mossfw_ringbuffarray_isfull(mossfw_ringbuffarray_t *ary);
int mossfw_ringbuffarray_storednum(mossfw_ringbuffarray_t *ary);
int mossfw_ringbuffarray_storedbytes(mossfw_ringbuffarray_t *ary);

mossfw_data_t *mossfw_ringbuffarray_releasedata(mossfw_ringbuffarray_t *ary);
mossfw_data_t *mossfw_ringbuffarray_getdata(mossfw_ringbuffarray_t *ary,
                                            int *used, bool nonblock);
bool mossfw_ringbuffarray_setdata(mossfw_ringbuffarray_t *ary,
                               mossfw_data_t *dat, bool nonblock);
bool mossfw_ringbuffarray_backdatarest(mossfw_ringbuffarray_t *ary,
                                    mossfw_data_t *dat, int used,
                                    bool nonblock);
void mossfw_ringbuffarray_setstop(mossfw_ringbuffarray_t *ary, bool stop);

#ifdef __cplusplus
}
#endif

#endif  /* __MOSSFW_RINGBUFFARY_H */
