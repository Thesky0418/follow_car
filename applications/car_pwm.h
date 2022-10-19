/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-09-20     10091       the first version
 */
#ifndef APPLICATIONS_CAR_PWM_H_
#define APPLICATIONS_CAR_PWM_H_

#include <rtthread.h>
#include <rtdevice.h>
#include "string.h"
#include "stdlib.h"


#define PWM_DEVICE_NAME1   "pwm3"
#define PWM_CHANNEL1         1
#define PWM_DEVICE_NAME2   "pwm3"
#define PWM_CHANNEL2         2

int pwm_init(void);
int my_pwm_set(int argc,char **argv);
rt_err_t my_pwm_set_pulse(struct rt_device_pwm * pwm_dev,rt_uint32_t pulse_val);
rt_err_t my_pwm_enable(void);
rt_err_t my_pwm_disable(void);


#endif /* APPLICATIONS_CAR_PWM_H_ */
