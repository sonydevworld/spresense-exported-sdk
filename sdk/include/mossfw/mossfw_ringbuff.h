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

#ifndef __MOSSFW_RINGBUFF_H
#define __MOSSFW_RINGBUFF_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdbool.h>
#include <mossfw/mossfw_lock.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#ifndef MOSSFW_MEM_ALIGNMENT
# define MOSSFW_MEM_ALIGNMENT (4)
#endif

/****************************************************************************
 * Public Data Types
 ****************************************************************************/

struct mossfw_ringbuffer_s
{
  void *buffer;
  int buff_len;
  int block_sz;

  int ridx;
  int widx;
  bool is_empty;
  bool is_stop;
  mossfw_lock_t lock;
  mossfw_condition_t cond;
};

typedef struct mossfw_ringbuffer_s mossfw_ringbuffer_t;

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

mossfw_ringbuffer_t *mossfw_ringbuff_create(int block_sz, int block_num);
void mossfw_ringbuff_delete(mossfw_ringbuffer_t *buff);

bool mossfw_ringbuff_isempty(mossfw_ringbuffer_t *buff);
bool mossfw_ringbuff_isfull(mossfw_ringbuffer_t *buff);

int mossfw_ringbuff_storednum(mossfw_ringbuffer_t *buff);
int mossfw_ringbuff_storedbytes(mossfw_ringbuffer_t *buff);

void *mossfw_ringbuff_getdata(mossfw_ringbuffer_t *buff, bool nonblock);
bool mossfw_ringbuff_setdata(mossfw_ringbuffer_t *buff, void *blk,
                             bool nonblock);
void mossfw_ringbuff_releaseblock(mossfw_ringbuffer_t *buff);
void mossfw_ringbuff_setstop(mossfw_ringbuffer_t *buff, bool stop);

#ifdef __cplusplus
}
#endif

#endif  /* __MOSSFW_RINGBUFF_H */
