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

/** \file mossdsp.h
 *
 * API for mossdsp library
 */

#ifndef __MOSSDSP_H
#define __MOSSDSP_H

#include "mossfw/sensorlib.h"
#include "mossfw/mossfw_data.h"

/** firfilter iirfilter last input
 *
 * member of struct mossdsp_firfilter_param_s and
 * struct mossdsp_iirfilter_param_s.
 * \ingroup filter
 */

union lastdata_u
{
  int16_t *i;  /**< array of type int16_t */
  float *f;  /**< array of float */
  mossfw_data_v3s_t *v3i;  /**< array of mossfw_data_v3s_t type */
  mossfw_data_v3f_t *v3f;  /**< array of mossfw_data_v3f_t type */
  struct vector3ia_s *v3ia;  /**< array of mossfw_data_v3ts_t type */
  struct vector3fa_s *v3fa;  /**< array of mossfw_data_v3tf_t type */
  mossfw_data_v3ts_t *v3ti;  /**< address of a variable of type struct
         * vector3 ia_s */
  mossfw_data_v3tf_t *v3tf;  /**< address of a variable of type struct
         * vector3fa_s */
  struct vector3tia_s *v3tia;  /**< address of a variable of type struct
         * vector3tia_s */
  struct vector3tfa_s *v3tfa;  /**< address of a variable of type struct
         * vector3tfa_s */
  mossfw_data_qf_t *qf;    /**< address of a variable of type
         * mossfw_data_qf_t */
  mossfw_data_qtf_t *qtf;  /**< address of a variable of type
         * mossfw_data_qtf_t */
};

/** firfilter coefficients
 *
 * \ingroup filter
 */

struct fircoefi_s
{
  int16_t *coef;  /**< Filter Factor */
  unsigned int scale;  /**< number of decimal bits in filter factor */
};

/** firfilter coefficients
 *
 * \ingroup filter
 */

union fircoef_u
{
  float *f;  /**< array of float */
  struct fircoefi_s i;  /**< array of type int16_t */
};

/** firfilter Parameters
 *
 * \ingroup filter
 */

struct mossdsp_firfilter_param_s
{
  union fircoef_u coefficients;    /**< Filter Factor */
  unsigned int cnum;  /**< Number of filter coefficients */
  union lastdata_u lastdata;  /**< Last input */
  unsigned int lnum;  /**< number of previous inputs */
  uint16_t delay;  /**< Delay */
};

/** iirfilter coefficients
 *
 * member of union iircoef_u.
 * \ingroup filter
 */

struct iircoeff_s
{
  float *ff;  /**< Feedforward filter factor */
  float *fb;  /**< Feedback Filter Factor */
  unsigned int ffnum;  /**< Number of feedforward filter coefficients */
  unsigned int fbnum;  /**< Number of feedback filter coefficients */
};

/** iirfilter coefficients
 *
 * member of union iircoef_u.
 * \ingroup filter
 */

struct iircoefi_s
{
  int16_t *ff;  /**< Feedforward filter factor */
  int16_t *fb;  /**< Feedback Filter Factor */
  unsigned int ffnum;  /**< Number of feedforward filter coefficients */
  unsigned int fbnum;  /**< Number of feedback filter coefficients */
  unsigned int scale;  /**< Scale factor of filter factor */
};

/** iirfilter coefficients
 *
 * member of struct mossdsp_iirfilter_param_s.
 * \ingroup filter
 */

union iircoef_u
{
  struct iircoeff_s f;  /**< float factor */
  struct iircoefi_s i;  /**< coefficient of type int */
};
/** iirfilter Parameters
 *
 * \ingroup filter
 */

struct mossdsp_iirfilter_param_s
{
  union iircoef_u coef;    /**< Filter Factor */
  union lastdata_u fflastdata;  /**< Output just before feedforward */
  unsigned int fflnum;  /**< number of inputs just before feedforward */
  union lastdata_u fblastdata;  /**< Input just before feedforward */
  unsigned int fblnum;  /**< number of inputs just before feedforward */
  uint16_t delay;  /**< Delay */
};

/** decimation parameter
 *
 * \ingroup resampling
 */

struct mossdsp_decimate_param_s
{
  struct mossdsp_iirfilter_param_s filterparam;    /**< Filter Factor */
  unsigned int factor;  /**< Decimation factor */
  unsigned int offset;  /**< Output Data Offset */
};

/** interpolate Processing Parameters
 *
 * \ingroup resampling
 */

struct mossdsp_interpolate_param_s
{
  uint32_t t0;  /**< input in 0 time */
  uint32_t t1;  /**< input in 1 time */
  uint32_t t;  /**< time of output */
};

/** Angular Velocity Integration Parameters
 *
 * \ingroup integral
 */

struct mossdsp_integrategyr_param_s
{
  union
  {
    mossfw_data_qf_t f;    /**< Quaternion */
    mossfw_data_qtf_t tf;  /**< Time and Quaternion */
  }
  lastout;  /**< Previous output data */
  unsigned long dt;  /**< interval */
  struct timespec res;  /**< dt1 count time */
  float scale_factor;  /**< scale factor when input angular velocity is an
       * integer */
};

/** Transform the coordinate axes of sensor data by matrix.
 *
 * Let the input be three-dimensional vector data x.
 * Let the output be three-dimensional vector data y.
 * Let the parameters be a 3x3 transformation matrix T.
 * Make the following calculations:
 *
 * y=Tx
 *
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * The transformation matrix of param 3x3.
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_axis
 */

int mossdsp_transformaxismv3i(mossfw_data_v3s_t *out,
  const mossfw_data_v3s_t *in,
  unsigned int num,
  const struct sqmatrix3i_s *param);

/** Transform the coordinate axes of sensor data by matrix.
 *
 * \see mossdsp_transformaxismv3i
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * The transformation matrix of param 3x3.
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_axis
 */

int mossdsp_transformaxismv3f(mossfw_data_v3f_t *out,
  const mossfw_data_v3f_t *in,
  unsigned int num,
  const struct sqmatrix3f_s *param);

/** Transform the coordinate axes of sensor data with a matrix
 *
 * \see mossdsp_transformaxismv3i
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * The transformation matrix of param 3x3.
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_axis
 */

int mossdsp_transformaxismv3ia(struct vector3ia_s *out,
  const struct vector3ia_s *in,
  unsigned int num,
  const struct sqmatrix3i_s *param);

/** Transform the coordinate axes of sensor data with a matrix
 *
 * \see mossdsp_transformaxismv3i
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * The transformation matrix of param 3x3.
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_axis
 */

int mossdsp_transformaxismv3fa(struct vector3fa_s *out,
  const struct vector3fa_s *in,
  unsigned int num,
  const struct sqmatrix3f_s *param);

/** Transform the coordinate axes of sensor data with a matrix
 *
 * \see mossdsp_transformaxismv3i
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * The transformation matrix of param 3x3.
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_axis
 */

int mossdsp_transformaxismv3ti(mossfw_data_v3ts_t *out,
  const mossfw_data_v3ts_t *in,
  unsigned int num,
  const struct sqmatrix3i_s *param);

/** Transform the coordinate axes of sensor data with a matrix
 *
 * \see mossdsp_transformaxismv3i
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * The transformation matrix of param 3x3.
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_axis
 */

int mossdsp_transformaxismv3tf(mossfw_data_v3tf_t *out,
  const mossfw_data_v3tf_t *in,
  unsigned int num,
  const struct sqmatrix3f_s *param);

/** Transform the coordinate axes of sensor data with a matrix
 *
 * \see mossdsp_transformaxismv3i
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * The transformation matrix of param 3x3.
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_axis
 */

int mossdsp_transformaxismv3tia(struct vector3tia_s *out,
  const struct vector3tia_s *in,
  unsigned int num,
  const struct sqmatrix3i_s *param);

/** Transform the coordinate axes of sensor data with a matrix
 *
 * \see mossdsp_transformaxismv3i
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * The transformation matrix of param 3x3.
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_axis
 */

int mossdsp_transformaxismv3tfa(struct vector3tfa_s *out,
  const struct vector3tfa_s *in,
  unsigned int num,
  const struct sqmatrix3f_s *param);

/** Transforming sensor data axes by quaternion
 *
 * It applies the rotation represented by the quaternion to
 * the input three-dimensional vector data and outputs the result.
 *
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * \param[in] param Quaternion for coordinate transformation
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_axis
 */

int mossdsp_transformaxisqv3f(mossfw_data_v3f_t *out,
  const mossfw_data_v3f_t *in,
  unsigned int num,
  const mossfw_data_qf_t *param);

/** Transforming sensor data axes by quaternion
 *
 * \see mossdsp_transformaxisqv3f
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * \param[in] param Quaternion for coordinate transformation
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_axis
 */

int mossdsp_transformaxisqv3fa(struct vector3fa_s *out,
  const struct vector3fa_s *in,
  unsigned int num,
  const mossfw_data_qf_t *param);

/** Transforming sensor data axes by quaternion
 *
 * \see mossdsp_transformaxisqv3f
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * \param[in] param Quaternion for coordinate transformation
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_axis
 */

int mossdsp_transformaxisqv3tf(mossfw_data_v3tf_t *out,
  const mossfw_data_v3tf_t *in,
  unsigned int num,
  const mossfw_data_qf_t *param);

/** Transforming sensor data axes by quaternion
 *
 * \see mossdsp_transformaxisqv3f
 * \param[out] out 3D vector data
 * \param[in] in three-dimensional vector data
 * \param num number of input data
 * \param[in] param Quaternion for coordinate transformation
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_axis
 */

int mossdsp_transformaxisqv3tfa(struct vector3tfa_s *out,
  const struct vector3tfa_s *in,
  unsigned int num,
  const mossfw_data_qf_t *param);

/** Converting Quaternion Attitude Data to Euler Angles
 *
 * \param[out] out Euler angle
 * \param[in] in postural data
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_quaternion
 */

int mossdsp_transformqanglesf(mossfw_data_v3f_t *out,
  const mossfw_data_qf_t *in,
  unsigned int num);

/** Converting Quaternion Attitude Data to Euler Angles
 *
 * \see mossdsp_transformqanglesf
 * \param[out] out Euler angle
 * \param[in] in postural data
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_quaternion
 */

int mossdsp_transformqanglestf(mossfw_data_v3tf_t *out,
  const mossfw_data_qtf_t *in,
  unsigned int num);

/** Converting Euler Angle Attitude Data to Quaternions
 *
 * \param[out] out posture data
 * \param[in] in Euler angle
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_quaternion
 */

int mossdsp_transformanglesf(mossfw_data_qf_t *out,
  const mossfw_data_v3f_t *in,
  unsigned int num);

/** Converting Euler Angle Attitude Data to Quaternions
 *
 * \see mossdsp_transformanglesf
 * \param[out] out posture data
 * \param[in] in Euler angle
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_quaternion
 */

int mossdsp_transformanglestf(mossfw_data_qtf_t *out,
  const mossfw_data_v3tf_t *in,
  unsigned int num);

/** Converting Quaternion Attitude Data to azimuth, pitch, and roll
 *
 * \param[out] out azimuth, pitch, roll
 * \param[in] in postural data
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_quaternion
 */

int mossdsp_transformqazimuthf(mossfw_data_v3f_t *out,
  const mossfw_data_qf_t *in,
  unsigned int num);

/** Converting Quaternion Attitude Data to azimuth, pitch, and roll
 *
 * \see mossdsp_transformqazimuthf
 * \param[out] out azimuth, pitch, roll
 * \param[in] in postural data
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup transform_quaternion
 */

int mossdsp_transformqazimuthtf(mossfw_data_v3tf_t *out,
  const mossfw_data_qtf_t *in,
  unsigned int num);

/** Synthesizing Attitude Data
 *
 * Let the input be the attitude data p, q. Let the output be
 * the synthesized attitude data pq.
 *
 * \param[out] out Compound posture data
 * \param[in] in 0 posture data
 * \param[in] in 1 posture data
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup quaternion
 */

int mossdsp_multiplyqf(mossfw_data_qf_t *out,
  const mossfw_data_qf_t *in0,
  const mossfw_data_qf_t *in1,
  unsigned int num);

/** Synthesizing Attitude Data
 *
 * \see mossdsp_multiplyqf
 * \param[out] out Compound posture data
 * \param[in] in 0 posture data
 * \param[in] in 1 posture data
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup quaternion
 */

int mossdsp_multiplyqtf(mossfw_data_qtf_t *out,
  const mossfw_data_qtf_t *in0,
  const mossfw_data_qtf_t *in1,
  unsigned int num);

/** Finding the Reverse Rotation of Attitude Data
 *
 * \param[out] out Attitude data reverse rotation
 * \param[in] in 0 posture data
 * \param[in] in 1 posture data
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup quaternion
 */

int mossdsp_conjugateqf(mossfw_data_qf_t *out,
  const mossfw_data_qf_t *in,
  unsigned int num);

/** Finding the Reverse Rotation of Attitude Data
 *
 * \see mossdsp_conjugateqf
 * \param[out] out Attitude data reverse rotation
 * \param[in] in 0 posture data
 * \param[in] in 1 posture data
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup quaternion
 */

int mossdsp_conjugateqtf(mossfw_data_qtf_t *out,
  const mossfw_data_qtf_t *in,
  unsigned int num);

/** FIR filter time series vector data
 *
 * \param[out] out time series data
 * \param[in] in evenly spaced time series
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_firfilteri(int16_t *out,
  const int16_t *in,
  unsigned int num,
  const struct mossdsp_firfilter_param_s *param);

/** FIR filter time series vector data
 *
 * \param[out] out time series data
 * \param[in] in evenly spaced time series
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_firfilterf(float *out,
  const float *in,
  unsigned int num,
  const struct mossdsp_firfilter_param_s *param);

/** FIR filter time series vector data
 *
 * \see mossdsp_firfilterf
 * \param[out] out time series vector data
 * \param[in] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_firfilterv3i(mossfw_data_v3s_t *out,
  const mossfw_data_v3s_t *in,
  unsigned int num,
  const struct mossdsp_firfilter_param_s *param);

/** FIR filter time series vector data
 *
 * \see mossdsp_firfilterf
 * \param[out] out time series vector data
 * \param[in] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_firfilterv3f(mossfw_data_v3f_t *out,
  const mossfw_data_v3f_t *in,
  unsigned int num,
  const struct mossdsp_firfilter_param_s *param);

/** FIR filter time series vector data
 *
 * \see mossdsp_firfilterf
 * \param[out] out time series vector data
 * \param[out] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_firfilterv3ia(struct vector3ia_s *out,
  const struct vector3ia_s *in,
  unsigned int num,
  const struct mossdsp_firfilter_param_s *param);

/** FIR filter time series vector data
 *
 * \see mossdsp_firfilterf
 * \param[in] out time series vector data
 * \param[in] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_firfilterv3fa(struct vector3fa_s *out,
  const struct vector3fa_s *in,
  unsigned int num,
  const struct mossdsp_firfilter_param_s *param);

/** FIR filter time series vector data
 *
 * \see mossdsp_firfilterf
 * \param[out] out time series vector data
 * \param[in] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_firfilterv3ti(mossfw_data_v3ts_t *out,
  const mossfw_data_v3ts_t *in,
  unsigned int num,
  const struct mossdsp_firfilter_param_s *param);

/** FIR filter time series vector data
 *
 * \see mossdsp_firfilterf
 * \param[out] out time series vector data
 * \param[in] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_firfilterv3tf(mossfw_data_v3tf_t *out,
  const mossfw_data_v3tf_t *in,
  unsigned int num,
  const struct mossdsp_firfilter_param_s *param);

/** FIR filter time series vector data
 *
 * \see mossdsp_firfilterf
 * \param[out] out time series vector data
 * \param[out] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_firfilterv3tia(struct vector3tia_s *out,
  const struct vector3tia_s *in,
  unsigned int num,
  const struct mossdsp_firfilter_param_s *param);

/** FIR filter time series vector data
 *
 * \see mossdsp_firfilterf
 * \param[in] out time series vector data
 * \param[in] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_firfilterv3tfa(struct vector3tfa_s *out,
  const struct vector3tfa_s *in,
  unsigned int num,
  const struct mossdsp_firfilter_param_s *param);

/** IIR filtering time series vector data
 *
 * \param[out] out time series vector data
 * \param[in] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_iirfilteri(int16_t *out,
  const int16_t *in,
  unsigned int num,
  struct mossdsp_iirfilter_param_s *param);

/** IIR filtering time series vector data
 *
 * \see mossdsp_iirfilteri
 * \param[out] out time series vector data
 * \param[in] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_iirfilterf(float *out,
  const float *in,
  unsigned int num,
  struct mossdsp_iirfilter_param_s *param);

/** IIR filtering time series vector data
 *
 * \see mossdsp_iirfilteri
 * \param[out] out time series vector data
 * \param[in] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_iirfilterv3i(mossfw_data_v3s_t *out,
  const mossfw_data_v3s_t *in,
  unsigned int num,
  struct mossdsp_iirfilter_param_s *param);

/** IIR filtering time series vector data
 *
 * \see mossdsp_iirfilteri
 * \param[out] out time series vector data
 * \param[in] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_iirfilterv3f(mossfw_data_v3f_t *out,
  const mossfw_data_v3f_t *in,
  unsigned int num,
  struct mossdsp_iirfilter_param_s *param);

/** IIR filtering time series vector data
 *
 * \see mossdsp_iirfilteri
 * \param[out] out time series vector data
 * \param[in] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_iirfilterv3ia(struct vector3ia_s *out,
  const struct vector3ia_s *in,
  unsigned int num,
  struct mossdsp_iirfilter_param_s *param);

/** IIR filtering time series vector data
 *
 * \see mossdsp_iirfilteri
 * \param[out] out time series vector data
 * \param[in] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_iirfilterv3fa(struct vector3fa_s *out,
  const struct vector3fa_s *in,
  unsigned int num,
  struct mossdsp_iirfilter_param_s *param);

/** IIR filtering time series vector data
 *
 * \see mossdsp_iirfilteri
 * \param[out] out time series vector data
 * \param[in] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_iirfilterv3ti(mossfw_data_v3ts_t *out,
  const mossfw_data_v3ts_t *in,
  unsigned int num,
  struct mossdsp_iirfilter_param_s *param);

/** IIR filtering time series vector data
 *
 * \see mossdsp_iirfilteri
 * \param[out] out time series vector data
 * \param[in] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_iirfilterv3tf(mossfw_data_v3tf_t *out,
  const mossfw_data_v3tf_t *in,
  unsigned int num,
  struct mossdsp_iirfilter_param_s *param);

/** IIR filtering time series vector data
 *
 * \see mossdsp_iirfilteri
 * \param[out] out time series vector data
 * \param[in] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_iirfilterv3tia(struct vector3tia_s *out,
  const struct vector3tia_s *in,
  unsigned int num,
  struct mossdsp_iirfilter_param_s *param);

/** IIR filtering time series vector data
 *
 * \see mossdsp_iirfilteri
 * \param[out] out time series vector data
 * \param[in] in vector time series data at equal intervals
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup filter
 */

int mossdsp_iirfilterv3tfa(struct vector3tfa_s *out,
  const struct vector3tfa_s *in,
  unsigned int num,
  struct mossdsp_iirfilter_param_s *param);

/** Decimating Vector Data
 *
 * \param[out] out time series vector data
 * \param[in] in time series vector data
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_decimatei(int16_t *out,
  const int16_t *in,
  unsigned int num,
  struct mossdsp_decimate_param_s *param);

/** Decimating Vector Data
 *
 * \see mossdsp_decimatei
 * \param[out] out time series vector data
 * \param[in] in time series vector data
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_decimatef(float *out,
  const float *in,
  unsigned int num,
  struct mossdsp_decimate_param_s *param);

/** Decimating Vector Data
 *
 * \see mossdsp_decimatei
 * \param[out] out time series vector data
 * \param[in] in time series vector data
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_decimatev3i(mossfw_data_v3s_t *out,
  const mossfw_data_v3s_t *in,
  unsigned int num,
  struct mossdsp_decimate_param_s *param);

/** Decimating Vector Data
 *
 * \see mossdsp_decimatei
 * \param[out] out time series vector data
 * \param[in] in time series vector data
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_decimatev3f(mossfw_data_v3f_t *out,
  const mossfw_data_v3f_t *in,
  unsigned int num,
  struct mossdsp_decimate_param_s *param);

/** Decimating Vector Data
 *
 * \see mossdsp_decimatei
 * \param[out] out time series vector data
 * \param[in] in time series vector data
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_decimatev3ia(struct vector3ia_s *out,
  const struct vector3ia_s *in,
  unsigned int num,
  struct mossdsp_decimate_param_s *param);

/** Decimating Vector Data
 *
 * \see mossdsp_decimatei
 * \param[out] out time series vector data
 * \param[in] in time series vector data
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_decimatev3fa(struct vector3fa_s *out,
  const struct vector3fa_s *in,
  unsigned int num,
  struct mossdsp_decimate_param_s *param);

/** Decimating Vector Data
 *
 * \see mossdsp_decimatei
 * \param[out] out time series vector data
 * \param[in] in time series vector data
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_decimatev3ti(mossfw_data_v3ts_t *out,
  const mossfw_data_v3ts_t *in,
  unsigned int num,
  struct mossdsp_decimate_param_s *param);

/** Decimating Vector Data
 *
 * \see mossdsp_decimatei
 * \param[out] out time series vector data
 * \param[in] in time series vector data
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_decimatev3tf(mossfw_data_v3tf_t *out,
  const mossfw_data_v3tf_t *in,
  unsigned int num,
  struct mossdsp_decimate_param_s *param);

/** Decimating Vector Data
 *
 * \see mossdsp_decimatei
 * \param[out] out time series vector data
 * \param[in] in time series vector data
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_decimatev3tia(struct vector3tia_s *out,
  const struct vector3tia_s *in,
  unsigned int num,
  struct mossdsp_decimate_param_s *param);

/** Decimating Vector Data
 *
 * \see mossdsp_decimatei
 * \param[out] out time series vector data
 * \param[in] in time series vector data
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_decimatev3tfa(struct vector3tfa_s *out,
  const struct vector3tfa_s *in,
  unsigned int num,
  struct mossdsp_decimate_param_s *param);

/** Decimating Quaternion Data
 *
 * \param[out] out time series quaternion data
 * \param[in] in time series quaternion data
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_decimateqf(mossfw_data_qf_t *out,
  const mossfw_data_qf_t *in,
  unsigned int num,
  struct mossdsp_decimate_param_s *param);

/** Decimating Quaternion Data
 *
 * \see mossdsp_decimateqf
 * \param[out] out time series quaternion data
 * \param[in] in time series quaternion data
 * \param num number of input data
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_decimateqtf(mossfw_data_qtf_t *out,
  const mossfw_data_qtf_t *in,
  unsigned int num,
  struct mossdsp_decimate_param_s *param);

/** Interpolate vector data to change data period
 *
 * Let the input be two sets of vector data.
 * Let the output be the vector data x (t).
 * The value is obtained by linear interpolation over time.
 *
 * \param[in] in0 input data
 * \param[in] in1 input data
 * \param[in,out] param parameter
 * \return Output Data
 * \ingroup resampling
 */

int16_t mossdsp_interpolatei(int16_t in0,
  int16_t in1,
  const struct mossdsp_interpolate_param_s *param);

/** Interpolate vector data to change data period
 *
 * \see mossdsp_interpolatei
 * \param[in] in0 input data at t0
 * \param[in] in1 input data at t1
 * \param num number of input data
 * \param param parameter
 * \return Output Data
 * \ingroup resampling
 */

float mossdsp_interpolatef(float in0,
  float in1,
  const struct mossdsp_interpolate_param_s *param);

/** Interpolate vector data to change data period
 *
 * \see mossdsp_interpolatei
 * \param[out] out output data
 * \param[in] in0 input data at t0
 * \param[in] in1 input data at t1
 * \param[out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_interpolatev3i(mossfw_data_v3s_t *out,
  const mossfw_data_v3s_t *in0,
  const mossfw_data_v3s_t *in1,
  const struct mossdsp_interpolate_param_s *param);

/** Interpolate vector data to change data period
 *
 * \see mossdsp_interpolatei
 * \param[out] out output data
 * \param[in] in0 input data at t0
 * \param[in] in1 input data at t1
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_interpolatev3f(mossfw_data_v3f_t *out,
  const mossfw_data_v3f_t *in0,
  const mossfw_data_v3f_t *in1,
  const struct mossdsp_interpolate_param_s *param);

/** Interpolate vector data to change data period
 *
 * \see mossdsp_interpolatei
 * \param[out] out output data
 * \param[in] in0 input data
 * \param[in] in1 input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_interpolatev3ti(mossfw_data_v3ts_t *out,
  const mossfw_data_v3ts_t *in0,
  const mossfw_data_v3ts_t *in1,
  const struct mossdsp_interpolate_param_s *param);

/** Interpolate vector data to change data period
 *
 * \see mossdsp_interpolatei
 * \param[out] out output data
 * \param[in] in0 input data
 * \param[in] in1 input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_interpolatev3tf(mossfw_data_v3tf_t *out,
  const mossfw_data_v3tf_t *in0,
  const mossfw_data_v3tf_t *in1,
  const struct mossdsp_interpolate_param_s *param);

/** Interpolate Quaternion Data to Change the Period of Data
 *
 * Let the inputs be two sets of quaternion data and the time,
 *  and the time of the data to be output.
 * Let the output be the quaternion data at time t.
 *
 * \note The calculation is a linear interpolation of the angle
 *  formed by the two quaternions.
 * \param[out] out output data
 * \param[in] in0 input data at t0
 * \param[in] in1 input data at t1
 * \param[in,out] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_interpolateqf(mossfw_data_qf_t *out,
  const mossfw_data_qf_t *in0,
  const mossfw_data_qf_t *in1,
  const struct mossdsp_interpolate_param_s *param);

/** Interpolate Quaternion Data to Change the Period of Data
 *
 * \see mossdsp_interpolateqf
 * \param[out] out output data
 * \param[in] in0 input data at t0
 * \param[in] in1 input data at t1
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup resampling
 */

int mossdsp_interpolateqtf(mossfw_data_qtf_t *out,
  const mossfw_data_qtf_t *in0,
  const mossfw_data_qtf_t *in1,
  const struct mossdsp_interpolate_param_s *param);

/** Calculating the Average of Data
 *
 * \param[in] in input data
 * \param num number of input data
 * \return average
 * \ingroup statistics
 */

int16_t mossdsp_averagei(const int16_t *in, unsigned int num);

/** Calculating the Average of Data
 *
 * \see mossdsp_averagei
 * \param num number of input data
 * \return average
 * \ingroup statistics
 */

float mossdsp_averagef(const float *in, unsigned int num);

/** Calculating the Average of Data
 *
 * \see mossdsp_averagei
 * \param[out] out average
 * \param[in] in input data
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup statistics
 */

int mossdsp_averagev3i(mossfw_data_v3s_t *out,
  const mossfw_data_v3s_t *in,
  unsigned int num);

/** Calculating the Average of Data
 *
 * \see mossdsp_averagei
 * \param[out] out average
 * \param[in] in input data
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup statistics
 */

int mossdsp_averagev3f(mossfw_data_v3f_t *out,
  const mossfw_data_v3f_t *in,
  unsigned int num);

/** Calculating the Average of Data
 *
 * \see mossdsp_averagei
 * \param[out] out average
 * \param[in] in input data
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup statistics
 */

int mossdsp_averagev3ia(mossfw_data_v3s_t *out,
  const struct vector3ia_s *in,
  unsigned int num);

/** Calculating the Average of Data
 *
 * \see mossdsp_averagei
 * \param[out] out average
 * \param[in] in input data
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup statistics
 */

int mossdsp_averagev3fa(mossfw_data_v3f_t *out,
  const struct vector3fa_s *in,
  unsigned int num);

/** Calculating the Average of Data
 *
 * \see mossdsp_averagei
 * \param[out] out average
 * \param[in] in input data
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup statistics
 */

int mossdsp_averagev3ti(mossfw_data_v3s_t *out,
  const mossfw_data_v3ts_t *in,
  unsigned int num);

/** Calculating the Average of Data
 *
 * \see mossdsp_averagei
 * \param[out] out average
 * \param[in] in input data
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup statistics
 */

int mossdsp_averagev3tf(mossfw_data_v3f_t *out,
  const mossfw_data_v3tf_t *in,
  unsigned int num);

/** Calculating the Average of Data
 *
 * \see mossdsp_averagei
 * \param[out] out average
 * \param[in] in input data
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup statistics
 */

int mossdsp_averagev3tia(mossfw_data_v3s_t *out,
  const struct vector3tia_s *in,
  unsigned int num);

/** Calculating the Average of Data
 *
 * \see mossdsp_averagei
 * \param[out] out average
 * \param[in] in input data
 * \param num number of input data
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup statistics
 */

int mossdsp_averagev3tfa(mossfw_data_v3f_t *out,
  const struct vector3tfa_s *in,
  unsigned int num);

/** Calculating the Variance of Data
 *
 * \param[in] in input data
 * \param num number of input data
 * \return Variance
 * \ingroup statistics
 */

int16_t mossdsp_variancei(const int16_t *in, unsigned int num);

/** Calculating the Variance of Data
 *
 * \see mossdsp_variancei
 * \param[in] in input data
 * \param num number of input data
 * \return Variance
 * \ingroup statistics
 */

float mossdsp_variancef(const float *in, unsigned int num);

/** Calculate Unbiased Standard Deviation of Data
 *
 * \param[in] in input data
 * \param num number of input data
 * \return Unbiased standard deviation
 * \ingroup statistics
 */

int16_t mossdsp_unbiasedsdi(const int16_t *in, unsigned int num);

/** Calculate Unbiased Standard Deviation of Data
 *
 * \see mossdsp_unbiasedsdi
 * \param[in] in input data
 * \param num number of input data
 * \return Unbiased standard deviation
 * \ingroup statistics
 */

float mossdsp_unbiasedsdf(const float *in, unsigned int num);

/** Integrating Angular Velocity Data
 *
 * The input is taken as angular velocity at time t, dt of time,
 * and attitude at time t - dt.
 * Let the output be the attitude at time t.
 *
 * \param[out] out posture
 * \param[in] in angular velocity
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup integral
 */

int mossdsp_integrategyrv3i(mossfw_data_qf_t *out,
  const mossfw_data_v3s_t *in,
  unsigned int num,
  const struct mossdsp_integrategyr_param_s *param);

/** Integrating Angular Velocity Data
 *
 * \see mossdsp_integrategyrv3i
 * \param[out] out posture
 * \param[in] in angular velocity
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup integral
 */

int mossdsp_integrategyrv3f(mossfw_data_qf_t *out,
  const mossfw_data_v3f_t *in,
  unsigned int num,
  const struct mossdsp_integrategyr_param_s *param);

/** Integrating Angular Velocity Data
 *
 * \see mossdsp_integrategyrv3i
 * \param[out] out posture
 * \param[in] in angular velocity
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup integral
 */

int mossdsp_integrategyrv3ia(mossfw_data_qf_t *out,
  const struct vector3ia_s *in,
  unsigned int num,
  const struct mossdsp_integrategyr_param_s *param);

/** Integrating Angular Velocity Data
 *
 * \see mossdsp_integrategyrv3i
 * \param[out] out posture
 * \param[in] in angular velocity
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup integral
 */

int mossdsp_integrategyrv3fa(mossfw_data_qf_t *out,
  const struct vector3fa_s *in,
  unsigned int num,
  const struct mossdsp_integrategyr_param_s *param);

/** Integrating Angular Velocity Data
 *
 * \see mossdsp_integrategyrv3i
 * \param[out] out posture
 * \param[in] in angular velocity
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup integral
 */

int mossdsp_integrategyrv3ti(mossfw_data_qtf_t *out,
  const mossfw_data_v3ts_t *in,
  unsigned int num,
  const struct mossdsp_integrategyr_param_s *param);

/** Integrating Angular Velocity Data
 *
 * \see mossdsp_integrategyrv3i
 * \param[out] out posture
 * \param[in] in angular velocity
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup integral
 */

int mossdsp_integrategyrv3tf(mossfw_data_qtf_t *out,
  const mossfw_data_v3tf_t *in,
  unsigned int num,
  const struct mossdsp_integrategyr_param_s *param);

/** Integrating Angular Velocity Data
 *
 * \see mossdsp_integrategyrv3i
 * \param[out] out posture
 * \param[in] in angular velocity
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup integral
 */

int mossdsp_integrategyrv3tia(mossfw_data_qtf_t *out,
  const struct vector3tia_s *in,
  unsigned int num,
  const struct mossdsp_integrategyr_param_s *param);

/** Integrating Angular Velocity Data
 *
 * \see mossdsp_integrategyrv3i
 * \param[out] out posture
 * \param[in] in angular velocity
 * \param num number of input data
 * \param[in] param parameter
 * \retval 0 Normal termination
 * \retval Other Error
 * \ingroup integral
 */

int mossdsp_integrategyrv3tfa(mossfw_data_qtf_t *out,
  const struct vector3tfa_s *in,
  unsigned int num,
  const struct mossdsp_integrategyr_param_s *param);

#endif
