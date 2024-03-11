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

#ifndef COMPLEMENTARYFILTER_H
#define COMPLEMENTARYFILTER_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "mossfw/mossfw_component.h"

/****************************************************************************
 * Public Data Types
 ****************************************************************************/

struct complementaryfilter_s
  {
    mossfw_input_t *ingyr;
    mossfw_input_t *inrotr;
    mossfw_input_t *inroti;
    mossfw_callback_op_t *opgyr;
    mossfw_callback_op_t *oprot;
    mossfw_output_t *outr;
    mossfw_output_t *outi;
    mossfw_allocator_t *allocr;
    mossfw_allocator_t *allocq;
  };

enum complementaryfilter_e
  {
    ID_DATA_ESTIMATEPOSEACC,
    COMPLEMENTARYFILTER_GYR1
  };

struct complementaryfilter_s *complementaryfilter_create(mossfw_allocator_t *
                                                         allocator,
                                                         mossfw_allocator_t *
                                                         allocatorq);

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

void complementaryfilter_set_time_resolution(long nsec);
void complementaryfilter_delete(struct complementaryfilter_s *com);

#endif
