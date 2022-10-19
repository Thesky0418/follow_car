/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-09-20     10091       the first version
 */
#ifndef APPLICATIONS_PID_H_
#define APPLICATIONS_PID_H_

#include "rtdbg.h"
#include "car_pwm.h"
#include "uart2.h"
#include "stdlib.h"
#include "car.h"

int pid_init(void);
void pid_clear(void);

#endif /* APPLICATIONS_PID_H_ */
