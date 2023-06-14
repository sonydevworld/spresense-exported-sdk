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

#ifndef __MOSSFW_MEMORYALLOCATOR_H
#define __MOSSFW_MEMORYALLOCATOR_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdbool.h>
#include <mossfw/mossfw_data.h>

/****************************************************************************
 * Public Data Types
 ****************************************************************************/

struct mossfw_allocator_s
{
  mossfw_data_t *(*alloc)(void *priv, int size, bool nonblock);
  void (*free)(void *priv, mossfw_data_t *mem);
  int (*get_blksz)(void *priv);
  void *priv;
};
typedef struct mossfw_allocator_s mossfw_allocator_t;

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

mossfw_allocator_t *mossfw_fixedmem_create(int block_sz, int block_num);
int mossfw_fixedmem_delete(mossfw_allocator_t *inst);
void mossfw_data_refer(mossfw_data_t *mem);

mossfw_data_t *mossfw_data_alloc(mossfw_allocator_t *inst, int size,
                                       bool nonblock);
void mossfw_data_free(mossfw_data_t *mem);
int mossfw_fixedsize_allocator(mossfw_allocator_t *inst);

#ifdef __cplusplus
}
#endif

#endif  /* __MOSSFW_MEMORYALLOCATOR_H */
