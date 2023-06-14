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

#ifndef TRANSFORM_H
#define TRANSFORM_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "mossfw/mossfw_component.h"

/****************************************************************************
 * Public Data Types
 ****************************************************************************/

struct transform_s
  {
    mossfw_input_t *inacc;
    mossfw_input_t *ingyr;
    mossfw_callback_op_t *opacc;
    mossfw_callback_op_t *opgyr;
    mossfw_output_t *outacc;
    mossfw_output_t *outgyr;
    mossfw_allocator_t *alloc;
  };

enum transform_e
  {
    TRANSFORM_ACC1,
    TRANSFORM_GYR1
  };

struct transform_s *transform_create(mossfw_allocator_t * allocator);

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

void transform_set_param(struct sqmatrix3f_s *transform);
void transform_delete(struct transform_s *transform);

#endif
