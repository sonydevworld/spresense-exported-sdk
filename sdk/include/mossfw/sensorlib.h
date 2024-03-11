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

/** \mainpage mossdsp mosscalib library
 *
 * \section intro_sec Introduction
 *
 * mossdsp is the digital signal processing library for 3-axis sensor data.
 * mosscalib is the sensor calibration library for IMU, magnetic field sensor
 *
 * \defgroup calibration Calibrate sensor data
 * \defgroup transform_axis Transform sensor data axes
 * \defgroup transform_quaternion Convert attitude data to 3-axis rotation
 * \defgroup quaternion Perform operations on posture data
 * \defgroup filter Filter time series data
 * \defgroup resampling Resampling time series data
 * \defgroup statistics Calculate the mean and variance of data
 * \defgroup integral Integrate sensor data
 */

/** \file sensorlib.h
 *
 * API for mossdsp library
 */

#ifndef SENSORLIB_H
#define SENSORLIB_H

#include <stdint.h>
#include <time.h>
#include "mossfw/mossfw_data.h"

/** 3D vector (int16_t *)
 * \ingroup filter calibration transform_axis resampling statistics integral
 */

struct vector3ia_s
{
  int16_t *x; /**< x-component of a three-dimensional vector */
  int16_t *y; /**< y-component of a three-dimensional vector */
  int16_t *z; /**< z-component of a three-dimensional vector */
};

/** 3D Arrays (float *)
 * \ingroup filter calibration transform_axis resampling statistics integral
 */

struct vector3fa_s
{
  float *x; /**< x-component of a three-dimensional vector */
  float *y; /**< y-component of a three-dimensional vector */
  float *z; /**< z-component of a three-dimensional vector */
};

/** 3D vector (int16_t *)
 * \ingroup filter calibration transform_axis resampling statistics integral
 */

struct vector3tia_s
{
  int16_t *x; /**< x-component of a three-dimensional vector */
  int16_t *y; /**< y-component of a three-dimensional vector */
  int16_t *z; /**< z-component of a three-dimensional vector */
  uint16_t *t; /**< time */
};

/** 3D Arrays (float *)
 * \ingroup filter calibration transform_axis resampling statistics integral
 */

struct vector3tfa_s
{
  float *x; /**< x-component of a three-dimensional vector */
  float *y; /**< y-component of a three-dimensional vector */
  float *z; /**< z-component of a three-dimensional vector */
  uint32_t *t; /**< time */
};

/** 3 x 3 Square Matrix (int16_t)
 * \ingroup calibration transform_axis
 */

struct sqmatrix3i_s
{
  mossfw_data_v3s_t x; /**< first row of cubic square matrix */
  mossfw_data_v3s_t y; /**< 2nd row of cubic square matrix */
  mossfw_data_v3s_t z; /**< third row of cubic square matrix */
};

/** 3x3 Square Matrix (float)
 * \ingroup calibration transform_axis
 */

struct sqmatrix3f_s
{
  mossfw_data_v3f_t x; /**< first row of cubic square matrix */
  mossfw_data_v3f_t y; /**< 2nd row of cubic square matrix */
  mossfw_data_v3f_t z; /**< third row of cubic square matrix */
};

#endif
