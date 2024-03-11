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

#ifndef __MOSSFW_COMPONENT_H
#define __MOSSFW_COMPONENT_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdint.h>

#include <mossfw/mossfw_lock.h>
#include <mossfw/mossfw_data.h>
#include <mossfw/mossfw_ringbuff.h>
#include <mossfw/mossfw_ringbuffary.h>
#include <mossfw/mossfw_memoryallocator.h>

/****************************************************************************
 * Public Data Types
 ****************************************************************************/

struct mossfw_output_s;
struct mossfw_input_s;
struct mossfw_callback_op_s;

struct mossfw_async_op_s
{
  mossfw_thread_t tid;
  mossfw_condition_t cond;
  bool is_running;
};
typedef struct mossfw_async_op_s mossfw_async_op_t;

typedef int (*mossfw_operator_t)(struct mossfw_callback_op_s *in,
                                 unsigned long arg);

struct mossfw_callback_op_s
{
  mossfw_lock_t lock;
  mossfw_operator_t operate;
  unsigned long op_arg;
  mossfw_async_op_t *async;
  int stack_sz;
  int prio;
  struct mossfw_input_s *input;
};
typedef struct mossfw_callback_op_s mossfw_callback_op_t;

struct mossfw_input_s
{
  uint32_t type;
  struct mossfw_output_s *out;
  union
    {
      mossfw_ringbuffer_t *single;
      mossfw_ringbuffarray_t *array;
    } ringbuff;
  int wait_datasize;
  mossfw_lock_t lock;
  mossfw_callback_op_t *op;
  struct mossfw_input_s *bind_next;
  struct mossfw_input_s *cb_next;
};
typedef struct mossfw_input_s mossfw_input_t;

struct mossfw_output_s
{
  uint32_t type;
  mossfw_lock_t bindlock;
  mossfw_input_t *binded;
};
typedef struct mossfw_output_s mossfw_output_t;

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

mossfw_input_t *mossfw_input_create(uint32_t type, int block_num);
mossfw_output_t *mossfw_output_create(uint32_t type);
mossfw_callback_op_t *mossfw_callback_op_create(mossfw_operator_t op,
                                          unsigned long arg,
                                          bool async);
mossfw_callback_op_t *mossfw_callback_op_create_attr(mossfw_operator_t op,
                                                     unsigned long arg,
                                                     bool async,
                                                     int prio,
                                                     int stacksz);
void mossfw_input_delete(mossfw_input_t *in);
void mossfw_output_delete(mossfw_output_t *out);
void mossfw_callback_op_delete(mossfw_callback_op_t *op);
int mossfw_start_callback_op(mossfw_callback_op_t *op);
void mossfw_stop_callback_op(mossfw_callback_op_t *op);

int mossfw_bind_inout(mossfw_output_t *out, mossfw_input_t *in,
                      uint32_t mask);
int mossfw_unbind_inout(mossfw_output_t *out, mossfw_input_t *in);

bool mossfw_output_ismultibinded(mossfw_output_t *out);
int mossfw_deliver_data(mossfw_output_t *out, mossfw_onedata_t *dat);
int mossfw_deliver_dataarray(mossfw_output_t *out, mossfw_data_t *dat);

int mossfw_get_delivereddata_num(mossfw_input_t *in);
mossfw_data_t *mossfw_get_delivereddata_array(mossfw_input_t *in, int sz,
                                              int *used);
int mossfw_get_delivereddata_single(mossfw_input_t *in,
                                    mossfw_onedata_t *rdat);
bool mossfw_deliverback_dataarray(mossfw_input_t *in, mossfw_data_t *dat,
                               int used);
mossfw_data_t *mossfw_release_delivereddata_array(mossfw_input_t *in);

int mossfw_set_waitcondition(mossfw_input_t *in, int wait_size,
                          mossfw_callback_op_t *op);
int mossfw_update_waitsize(mossfw_input_t *in, int wait_size);
int mossfw_unset_waitcondition(mossfw_input_t *in,
                               mossfw_callback_op_t *op);
int mossfw_get_fanout(mossfw_output_t *out);

#ifdef __cplusplus
}
#endif

#endif /* __MOSSFW_COMPONENT_H */
