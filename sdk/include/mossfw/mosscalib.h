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

/** \file mosscalib.h
 *
 * API for mosscalib library
 */

#ifndef __MOSSCALIB_H
#define __MOSSCALIB_H

#include "mossfw/sensorlib.h"

/** mosscalib_gyrbias Parameters
 * \ingroup calibration
 */

struct mosscalib_gyrbias_param_s
{
  union
  {
    int16_t i;  /**< representation by int16_t type */
    float f;  /**< float expression */
  }
  average;  /**< upper limit of absolute value of mean value when judging
     * stationary */
  float usd;  /**< upper bound of unbiased standard deviation when judging
     * stationary */
  unsigned int num;  /**< Number of data used for one quiesce decision */
};

/** mosscalib_gravity Parameters
 *
 * \ingroup calibration
 */

struct mosscalib_gravity_param_s
{
  mossfw_data_v3f_t vaxis;  /**< unit vector representing axis to match
         * acceleration */
  mossfw_data_v3f_t haxis;  /**< Vector representing horizontal axis of
         * rotation perpendicular to vaxis  */
};

/** adjust parameters
 *
 * \ingroup calibration
 */

struct mosscalib_adjust_param_s
{
  union
  {
    mossfw_data_v3s_t i;  /**< Representation by type vector3i */
    mossfw_data_v3f_t f;  /**< vector3f representation */
  }
  bias;    /**< Bias */
  struct sqmatrix3f_s scalefactor;  /**< scale factor */
  struct sqmatrix3f_s misalignment;  /**< Misalignment */
};

/** Generating calibration parameters for angular velocity
 *  bias correction values
 *
 * \param[out] out Three-dimensional vector data of angular velocity
 *  bias correction
 * \param[in] in 3D vector data of angular velocity at rest
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_gyrbiasv3i(mossfw_data_v3s_t *out,
  const mossfw_data_v3s_t *in,
  unsigned int num,
  const struct mosscalib_gyrbias_param_s *param);

/** Generating calibration parameters for angular velocity bias
 *  correction values
 *
 * \see mosscalib_gyrbiasv3i
 * \param[out] out Three-dimensional vector data of angular
 * velocity bias correction
 * \param[in] in 3D vector data of angular velocity at rest
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_gyrbiasv3f(mossfw_data_v3f_t *out,
  const mossfw_data_v3f_t *in,
  unsigned int num,
  const struct mosscalib_gyrbias_param_s *param);

/** Generating calibration parameters for angular velocity bias
 *  correction values
 *
 * \see mosscalib_gyrbiasv3i
 * \param[out] out Three-dimensional vector data of angular
 *  velocity bias correction
 * \param[in] in 3D vector data of angular velocity at rest
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_gyrbiasv3ia(mossfw_data_v3s_t *out,
  const struct vector3ia_s *in,
  unsigned int nun,
  const struct mosscalib_gyrbias_param_s *param);

/** Generating calibration parameters for angular velocity
 *  bias correction values
 *
 * \see mosscalib_gyrbiasv3i
 * \param[out] out Three-dimensional vector data of angular
 *  velocity bias correction
 * \param[in] in 3D vector data of angular velocity at rest
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_gyrbiasv3fa(mossfw_data_v3f_t *out,
  const struct vector3fa_s *in,
  unsigned int num,
  const struct mosscalib_gyrbias_param_s *param);

/** Generating calibration parameters for angular velocity
 *  bias correction values
 *
 * \see mosscalib_gyrbiasv3i
 * \param[out] out Three-dimensional vector time data fo
 * r angular velocity bias correction
 * \param[in] in 3D vector time data of angular velocity at rest
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_gyrbiasv3ti(mossfw_data_v3s_t *out,
  const mossfw_data_v3ts_t *in,
  unsigned int num,
  const struct mosscalib_gyrbias_param_s *param);

/** Generating calibration parameters for angular velocity
 *  bias correction values
 *
 * \see mosscalib_gyrbiasv3i
 * \param[out] out Three-dimensional vector time data for
 *  angular velocity bias correction
 * \param[in] in 3D vector time data of angular velocity at rest
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_gyrbiasv3tf(mossfw_data_v3f_t *out,
  const mossfw_data_v3tf_t *in,
  unsigned int num,
  const struct mosscalib_gyrbias_param_s *param);

/** Generating calibration parameters for angular velocity
 *  bias correction values
 *
 * \see mosscalib_gyrbiasv3i
 * \param[out] out Three-dimensional vector data of angular
 *  velocity bias correction
 * \param[in] in 3D vector data of angular velocity at rest
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_gyrbiasv3tia(mossfw_data_v3s_t *out,
  const struct vector3tia_s *in,
  unsigned int nun,
  const struct mosscalib_gyrbias_param_s *param);

/** Generating calibration parameters for angular velocity
 *  bias correction values
 *
 * \see mosscalib_gyrbiasv3i
 * \param[out] out Three-dimensional vector data of angular
 *  velocity bias correction
 * \param[in] in 3D vector data of angular velocity at rest
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_gyrbiasv3tfa(mossfw_data_v3f_t *out,
  const struct vector3tfa_s *in,
  unsigned int nun,
  const struct mosscalib_gyrbias_param_s *param);

/** Calibrate at rest to generate calibration parameters
 *  that match the direction of gravity to an arbitrary axis
 *
 * A quaternion that aligns the direction of gravitational
 *  acceleration with the specified axis.
 * \param[in] in acceleration data at rest
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_gravityv3i(mossfw_data_qf_t *out,
  const mossfw_data_v3s_t *in,
  unsigned int num,
  const struct mosscalib_gravity_param_s *param);

/** Calibrate at rest to generate calibration parameters
 *  that match the direction of gravity to an arbitrary axis
 *
 * \see mosscalib_gravityv3i
 * A quaternion that aligns the direction of gravitational
 *  acceleration with the specified axis.
 * \param[in] in acceleration data at rest
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_gravityv3f(mossfw_data_qf_t *out,
  const mossfw_data_v3f_t *in,
  unsigned int num,
  const struct mosscalib_gravity_param_s *param);

/** Calibrate at rest to generate calibration parameters
 *  that match the direction of gravity to an arbitrary axis
 *
 * \see mosscalib_gravityv3i
 * A quaternion that aligns the direction of gravitational
 *  acceleration with the specified axis.
 * \param[in] in acceleration data at rest
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_gravityv3ia(mossfw_data_qf_t *out,
  const struct vector3ia_s *in,
  unsigned int num,
  const struct mosscalib_gravity_param_s *param);

/** Calibrate at rest to generate calibration parameters
 *  that match the direction of gravity to an arbitrary axis
 *
 * \see mosscalib_gravityv3i
 * A quaternion that aligns the direction of gravitational
 *  acceleration with the specified axis.
 * \param[in] in acceleration data at rest
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_gravityv3fa(mossfw_data_qf_t *out,
  const struct vector3fa_s *in,
  unsigned int num,
  const struct mosscalib_gravity_param_s *param);

/** Calibrate at rest to generate calibration parameters
 *  that match the direction of gravity to an arbitrary axis
 *
 * \see mosscalib_gravityv3i
 * A quaternion that aligns the direction of gravitational
 *  acceleration with the specified axis.
 * \param[in] in acceleration data at rest
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_gravityv3ti(mossfw_data_qf_t *out,
  const mossfw_data_v3ts_t *in,
  unsigned int num,
  const struct mosscalib_gravity_param_s *param);

/** Calibrate at rest to generate calibration parameters
 *  that match the direction of gravity to an arbitrary axis
 *
 * \see mosscalib_gravityv3i
 * A quaternion that aligns the direction of gravitational
 *  acceleration with the specified axis.
 * \param[in] in acceleration data at rest
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_gravityv3tf(mossfw_data_qf_t *out,
  const mossfw_data_v3tf_t *in,
  unsigned int num,
  const struct mosscalib_gravity_param_s *param);

/** Calibrate at rest to generate calibration parameters
 *  that match the direction of gravity to an arbitrary axis
 *
 * \see mosscalib_gravityv3i
 * A quaternion that aligns the direction of gravitational
 *  acceleration with the specified axis.
 * \param[in] in acceleration data at rest
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_gravityv3tia(mossfw_data_qf_t *out,
  const struct vector3tia_s *in,
  unsigned int num,
  const struct mosscalib_gravity_param_s *param);

/** Calibrate at rest to generate calibration parameters
 *  that match the direction of gravity to an arbitrary axis
 *
 * \see mosscalib_gravityv3i
 * A quaternion that aligns the direction of gravitational
 *  acceleration with the specified axis.
 * \param[in] in acceleration data at rest
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_gravityv3tfa(mossfw_data_qf_t *out,
  const struct vector3tfa_s *in,
  unsigned int num,
  const struct mosscalib_gravity_param_s *param);

/** Adjusting sensor data using calibration parameters
 *
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * \param temperature
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_adjustv3i(mossfw_data_v3s_t *out,
  const mossfw_data_v3s_t *in,
  unsigned int num,
  int16_t temperature,
  const struct mosscalib_adjust_param_s *param);

/** Adjusting sensor data using calibration parameters
 *
 * \see mosscalib_adjustv3i
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * \param temperature
 * \param param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_adjustv3f(mossfw_data_v3f_t *out,
  const mossfw_data_v3f_t *in,
  unsigned int num,
  float temperature,
  const struct mosscalib_adjust_param_s *param);

/** Adjusting sensor data using calibration parameters
 *
 * \see mosscalib_adjustv3i
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * \param temperature
 * \param param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_adjustv3ia(struct vector3ia_s *out,
  const struct vector3ia_s *in,
  unsigned int num,
  int16_t temperature, const struct mosscalib_adjust_param_s *param);

/** Adjusting sensor data using calibration parameters
 *
 * \see mosscalib_adjustv3i
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * \param temperature
 * \param param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_adjustv3fa(struct vector3fa_s *out,
  const struct vector3fa_s *in,
  unsigned int num,
  float temperature, const struct mosscalib_adjust_param_s *param);

/** Adjusting sensor data using calibration parameters
 *
 * \see mosscalib_adjustv3i
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * \param temperature
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_adjustv3ti(mossfw_data_v3ts_t *out,
  const mossfw_data_v3ts_t *in, unsigned int num,
  int16_t temperature,
  const struct mosscalib_adjust_param_s *param);

/** Adjusting sensor data using calibration parameters
 *
 * \see mosscalib_adjustv3i
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * \param temperature
 * \param param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_adjustv3tf(mossfw_data_v3tf_t *out,
  const mossfw_data_v3tf_t *in,
  unsigned int num,
  float temperature,
  const struct mosscalib_adjust_param_s *param);

/** Adjusting sensor data using calibration parameters
 *
 * \see mosscalib_adjustv3i
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * \param temperature
 * \param param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_adjustv3tia(struct vector3tia_s *out,
  const struct vector3tia_s *in,
  unsigned int num, int16_t temperature,
  const struct mosscalib_adjust_param_s *param);

/** Adjusting sensor data using calibration parameters
 *
 * \see mosscalib_adjustv3i
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * \param temperature
 * \param param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup calibration
 */

int mosscalib_adjustv3tfa(struct vector3tfa_s *out,
  const struct vector3tfa_s *in,
  unsigned int num, float temperature,
  const struct mosscalib_adjust_param_s *param);

#endif
