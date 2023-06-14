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

#ifndef __MOSSFW_DATA_H
#define __MOSSFW_DATA_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdint.h>
#include <mossfw/mossfw_lock.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define MOSSFW_DATA_TYPE_OFFSET (0)
#define MOSSFW_DATA_TYPE_INT32  (0)
#define MOSSFW_DATA_TYPE_SHORT  (1)
#define MOSSFW_DATA_TYPE_CHAR   (2)
#define MOSSFW_DATA_TYPE_FLOAT  (3)
#define MOSSFW_DATA_TYPE_INT64  (4)
#define MOSSFW_DATA_TYPE_MASK   (0x0F)
#define MOSSFW_DATA_TYPE(s)  \
                    ((s) & MOSSFW_DATA_TYPE_MASK)

#define MOSSFW_DATA_TYPEGRP_OFFSET (4)
#define MOSSFW_DATA_TYPEGRP_V1     (0 << MOSSFW_DATA_TYPEGRP_OFFSET)
#define MOSSFW_DATA_TYPEGRP_V2     (1 << MOSSFW_DATA_TYPEGRP_OFFSET)
#define MOSSFW_DATA_TYPEGRP_V3     (2 << MOSSFW_DATA_TYPEGRP_OFFSET)
#define MOSSFW_DATA_TYPEGRP_V8     (7 << MOSSFW_DATA_TYPEGRP_OFFSET)
#define MOSSFW_DATA_TYPEGRP_Q      (8 << MOSSFW_DATA_TYPEGRP_OFFSET)
#define MOSSFW_DATA_TYPEGRP_MASK   (0xFF0)
#define MOSSFW_DATA_TYPEGRP(s) \
                    ((s) & MOSSFW_DATA_TYPEGRP_MASK)

#define MOSSFW_DATA_TYPENAME_OFFSET (12)
#define MOSSFW_DATA_TYPENAME_NONE   (0 << MOSSFW_DATA_TYPENAME_OFFSET)
#define MOSSFW_DATA_TYPENAME_ACCEL  (1 << MOSSFW_DATA_TYPENAME_OFFSET)
#define MOSSFW_DATA_TYPENAME_GYRO   (2 << MOSSFW_DATA_TYPENAME_OFFSET)
#define MOSSFW_DATA_TYPENAME_GNSS   (3 << MOSSFW_DATA_TYPENAME_OFFSET)
#define MOSSFW_DATA_TYPENAME_BARO   (4 << MOSSFW_DATA_TYPENAME_OFFSET)
#define MOSSFW_DATA_TYPENAME_TEMP   (5 << MOSSFW_DATA_TYPENAME_OFFSET)
#define MOSSFW_DATA_TYPENAME_AUDIO  (6 << MOSSFW_DATA_TYPENAME_OFFSET)
#define MOSSFW_DATA_TYPENAME_MASK   (0x0FFFF000)
#define MOSSFW_DATA_TYPENAME(s) \
                    ((s) & MOSSFW_DATA_TYPENAME_MASK)

#define MOSSFW_DATA_TYPEARRAY_OFFSET (28)
#define MOSSFW_DATA_TYPEARRAY_SINGLE (0 << MOSSFW_DATA_TYPEARRAY_OFFSET)
#define MOSSFW_DATA_TYPEARRAY_ARRAY  (1 << MOSSFW_DATA_TYPEARRAY_OFFSET)
#define MOSSFW_DATA_TYPEARRAY_MASK   (0xF0000000)
#define MOSSFW_DATA_TYPEARRAY(s) \
                    ((s) & MOSSFW_DATA_TYPEARRAY_MASK)
#define MOSSFW_DATA_TYPE_ISSINGLE(s) \
                    (MOSSFW_DATA_TYPEARRAY(s) == MOSSFW_DATA_TYPEARRAY_SINGLE)

#define MOSSFW_DATA_TYPE_ISARRAY(s) \
                    (MOSSFW_DATA_TYPEARRAY(s) == MOSSFW_DATA_TYPEARRAY_ARRAY)

/****************************************************************************
 * Public Data Types
 ****************************************************************************/

/* Sensor data structure template definitions */

#ifdef MOSSFW_DATA_V8_STRUCTDEF
#undef MOSSFW_DATA_V8_STRUCTDEF
#endif
#define MOSSFW_DATA_V8_STRUCTDEF(idx,type) \
struct mossfw_data_v8##idx##_s \
{ \
  type v[8]; \
}; \
typedef struct mossfw_data_v8##idx##_s mossfw_data_v8##idx##_t;

#ifdef MOSSFW_DATA_QT_STRUCTDEF
#undef MOSSFW_DATA_QT_STRUCTDEF
#endif
#define MOSSFW_DATA_QT_STRUCTDEF(idx,type1,type2) \
struct mossfw_data_qt##idx##_s \
{ \
  union { \
    struct { \
        type1 x; \
        type1 y; \
        type1 z; \
        type1 w; \
    }; \
    type1 v[4]; \
  }; \
  type2 t; \
}; \
typedef struct mossfw_data_qt##idx##_s mossfw_data_qt##idx##_t;

#ifdef MOSSFW_DATA_Q_STRUCTDEF
#undef MOSSFW_DATA_Q_STRUCTDEF
#endif
#define MOSSFW_DATA_Q_STRUCTDEF(idx,type) \
union mossfw_data_q##idx##_u \
{ \
  struct { \
    type x; \
    type y; \
    type z; \
    type w; \
  }; \
  type v[4]; \
}; \
typedef union mossfw_data_q##idx##_u mossfw_data_q##idx##_t;

#ifdef MOSSFW_DATA_V3T_STRUCTDEF
#undef MOSSFW_DATA_V3T_STRUCTDEF
#endif
#define MOSSFW_DATA_V3T_STRUCTDEF(idx,type1,type2) \
struct mossfw_data_v3t##idx##_s \
{ \
  union { \
    struct { \
        type1 x; \
        type1 y; \
        type1 z; \
    }; \
    type1 v[3]; \
  }; \
  type2 t; \
}; \
typedef struct mossfw_data_v3t##idx##_s mossfw_data_v3t##idx##_t;

#ifdef MOSSFW_DATA_V3_STRUCTDEF
#undef MOSSFW_DATA_V3_STRUCTDEF
#endif
#define MOSSFW_DATA_V3_STRUCTDEF(idx,type) \
union mossfw_data_v3##idx##_u \
{ \
  struct { \
    type x; \
    type y; \
    type z; \
  }; \
  type v[3]; \
}; \
typedef union mossfw_data_v3##idx##_u mossfw_data_v3##idx##_t;

#ifdef MOSSFW_DATA_V2_STRUCTDEF
#undef MOSSFW_DATA_V2_STRUCTDEF
#endif
#define MOSSFW_DATA_V2_STRUCTDEF(idx,type) \
union mossfw_data_v2##idx##_u \
{ \
  struct { \
    type x; \
    type y; \
  }; \
  type v[2]; \
}; \
typedef union mossfw_data_v2##idx##_u mossfw_data_v2##idx##_t;

#ifdef MOSSFW_DATA_V1_STRUCTDEF
#undef MOSSFW_DATA_V1_STRUCTDEF
#endif
#define MOSSFW_DATA_V1_STRUCTDEF(idx,type) \
union mossfw_data_v1##idx##_u \
{ \
  type x; \
  type v[1]; \
}; \
typedef union mossfw_data_v1##idx##_u mossfw_data_v1##idx##_t;

#include <mossfw/mossfw_datatype.h>

#undef MOSSFW_DATA_V8_STRUCTDEF
#define MOSSFW_DATA_V8_STRUCTDEF(idx, type) \
mossfw_data_v8##idx##_t v8##idx

#undef MOSSFW_DATA_QT_STRUCTDEF
#define MOSSFW_DATA_QT_STRUCTDEF(idx, type1, type2) \
mossfw_data_qt##idx##_t qt##idx

#undef MOSSFW_DATA_Q_STRUCTDEF
#define MOSSFW_DATA_Q_STRUCTDEF(idx, type) \
mossfw_data_q##idx##_t q##idx

#undef MOSSFW_DATA_V3T_STRUCTDEF
#define MOSSFW_DATA_V3T_STRUCTDEF(idx, type1, type2) \
mossfw_data_v3t##idx##_t v3t##idx; \
mossfw_data_v3t##idx##_t xyzt##idx

#undef MOSSFW_DATA_V3_STRUCTDEF
#define MOSSFW_DATA_V3_STRUCTDEF(idx, type) \
mossfw_data_v3##idx##_t v3##idx; \
mossfw_data_v3##idx##_t xyz##idx

#undef MOSSFW_DATA_V2_STRUCTDEF
#define MOSSFW_DATA_V2_STRUCTDEF(idx, type) \
mossfw_data_v2##idx##_t v2##idx; \
mossfw_data_v2##idx##_t xy##idx

#undef MOSSFW_DATA_V1_STRUCTDEF
#define MOSSFW_DATA_V1_STRUCTDEF(idx, type) \
mossfw_data_v1##idx##_t v1##idx; \
mossfw_data_v1##idx##_t x##idx

union mossfw_onedata_u
{
#include <mossfw/mossfw_datatype.h>
};
typedef union mossfw_onedata_u mossfw_onedata_t;

#undef MOSSFW_DATA_V8_STRUCTDEF
#define MOSSFW_DATA_V8_STRUCTDEF(idx, type) \
mossfw_data_v8##idx##_t *v8##idx

#undef MOSSFW_DATA_QT_STRUCTDEF
#define MOSSFW_DATA_QT_STRUCTDEF(idx, type1, type2) \
mossfw_data_qt##idx##_t *qt##idx

#undef MOSSFW_DATA_Q_STRUCTDEF
#define MOSSFW_DATA_Q_STRUCTDEF(idx, type) \
mossfw_data_q##idx##_t *q##idx

#undef MOSSFW_DATA_V3T_STRUCTDEF
#define MOSSFW_DATA_V3T_STRUCTDEF(idx, type1, type2) \
mossfw_data_v3t##idx##_t *v3t##idx; \
mossfw_data_v3t##idx##_t *xyzt##idx

#undef MOSSFW_DATA_V3_STRUCTDEF
#define MOSSFW_DATA_V3_STRUCTDEF(idx, type) \
mossfw_data_v3##idx##_t *v3##idx; \
mossfw_data_v3##idx##_t *xyz##idx

#undef MOSSFW_DATA_V2_STRUCTDEF
#define MOSSFW_DATA_V2_STRUCTDEF(idx, type) \
mossfw_data_v2##idx##_t *v2##idx; \
mossfw_data_v2##idx##_t *xy##idx

#undef MOSSFW_DATA_V1_STRUCTDEF
#define MOSSFW_DATA_V1_STRUCTDEF(idx, type) \
mossfw_data_v1##idx##_t *v1##idx; \
mossfw_data_v1##idx##_t *x##idx

struct mossfw_allocator_s;

struct mossfw_data_s
{
  int refcnt;
  mossfw_lock_t lock;
  int data_bytes;
  unsigned int timestamp;
  int fs;
  struct mossfw_allocator_s *allocator;
  union
    {
#include <mossfw/mossfw_datatype.h>
    } data;
};
typedef struct mossfw_data_s mossfw_data_t;

struct mossfw_data_container_s
{
  struct mossfw_data_container_s *next;
  mossfw_data_t *data;
};
typedef struct mossfw_data_container_s mossfw_data_container_t;

#endif  /* __MOSSFW_DATA_H */
