/****************************************************************************
 * include/nuttx/sensors/cxd5602pwbimu.h
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

#ifndef __INCLUDE_NUTTX_SENSORS_CXD5602PWBIMU_H
#define __INCLUDE_NUTTX_SENSORS_CXD5602PWBIMU_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/fs/ioctl.h>

#if defined(CONFIG_SENSORS_CXD5602PWBIMU)

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Types
 ****************************************************************************/

struct cxd5602pwbimu_intconfig_s;
struct cxd5602pwbimu_csxconfig_s;

/* Interrupt configuration data structure */

typedef struct cxd5602pwbimu_intconfig_s
{
  CODE int (*irq_attach)(FAR struct cxd5602pwbimu_intconfig_s *state,
                         xcpt_t isr);
  CODE void (*irq_enable)(FAR const struct cxd5602pwbimu_intconfig_s *state,
                          bool enable);
  CODE int (*irq_readlv)(FAR const struct cxd5602pwbimu_intconfig_s *state);
} cxd5602pwbimu_intconfig_t;

/* CSX pin configuration data structure */

typedef struct cxd5602pwbimu_csxconfig_s
{
  CODE void (*csx_toggle)(FAR const struct cxd5602pwbimu_csxconfig_s *state,
                          bool pol);
} cxd5602pwbimu_csxconfig_t;

/****************************************************************************
 * struct 6-axis data
 ****************************************************************************/

typedef struct cxd5602pwbimu_packet_st_s
{
  uint8_t id;               /* id */
  uint32_t sensor_time;     /* timestamp */
  float temp;               /* temperature */
  float gx;                 /* gyro x */
  float gy;                 /* gyro y */
  float gz;                 /* gyro z */
  float ax;                 /* accel x */
  float ay;                 /* accel y */
  float az;                 /* accel z */
} cxd5602pwbimu_packet_st_t;

struct spi_dev_s;

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Name: cxd5602pwbimu_register
 *
 * Description:
 *   Register the CXD5602PWBIMU character device as 'devpath'
 *
 * Input Parameters:
 *   devpath   - The full path to the driver to register. E.g., "/dev/imu0"
 *   dev       - An instance of the SPI interface to use to communicate
 *               with CXD5602PWBIMU
 *   intconfig - An instance of the interrupt configuration data structure
 *   csxconfig - An instance of the csx pin configuration data structure
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno value on failure.
 *
 ****************************************************************************/

int cxd5602pwbimu_register(FAR const char *devpath,
                           FAR struct spi_dev_s *dev,
                           FAR cxd5602pwbimu_intconfig_t *intconfig,
                           FAR cxd5602pwbimu_csxconfig_t *csxconfig);

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* CONFIG_SENSORS_CXD5602PWBIMU */
#endif /* __INCLUDE_NUTTX_SENSORS_CXD5602PWBIMU_H */
