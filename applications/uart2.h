/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-09-20     10091       the first version
 */
#ifndef APPLICATIONS_UART2_H_
#define APPLICATIONS_UART2_H_

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "rtdbg.h"

#define pid_uart_name "uart2"

rt_err_t pid_uart_init(void);
rt_err_t keyward_uart_init(void);

#endif /* APPLICATIONS_UART2_H_ */
