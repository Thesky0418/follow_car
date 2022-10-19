/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-09-20     lhylh       the first version
 */
#include "car.h"
#include "pid.h"
#include <rtthread.h>
#include <rtdevice.h>
#include "drivers\include\drv_common.h"

#define DBG_TAG "car"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

#define CAR_MSH_ENABLE 1

extern int pulse;


//设置车的基本速度
int car_set_percent(int argc,char **argv)
{
    if(argc != 2)
    {
        rt_kprintf("please input car_set_percent <percent>\r\n");
        return -RT_ERROR;
    }
    else {
        pulse = atoi(argv[1]);
    }
    return RT_EOK;
}


int car_init(void)
{
    rt_err_t ret = RT_EOK;

    rt_pin_mode(AIN1_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(AIN2_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(BIN1_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(BIN2_PIN, PIN_MODE_OUTPUT);

    rt_pin_write(AIN1_PIN, PIN_LOW);
    rt_pin_write(AIN2_PIN, PIN_LOW);
    rt_pin_write(BIN1_PIN, PIN_LOW);
    rt_pin_write(BIN2_PIN, PIN_LOW);

    ret = pwm_init();
    pid_init();

    return ret;
}

extern struct rt_device_pwm * pwm1;
extern struct rt_device_pwm * pwm2;
extern rt_uint32_t period;

int car_forward(void)
{
    rt_pwm_set(pwm1, PWM_CHANNEL1, period, 300000); //left
    rt_pwm_set(pwm2, PWM_CHANNEL2, period, 300000); //right
    rt_pin_write(AIN1_PIN, PIN_HIGH);
    rt_pin_write(AIN2_PIN, PIN_LOW);
    rt_pin_write(BIN1_PIN, PIN_HIGH);
    rt_pin_write(BIN2_PIN, PIN_LOW);
    my_pwm_enable();
    return RT_EOK;
}

int car_stop(void)
{
    rt_pin_write(AIN1_PIN, PIN_LOW);
    rt_pin_write(AIN2_PIN, PIN_LOW);
    rt_pin_write(BIN1_PIN, PIN_LOW);
    rt_pin_write(BIN2_PIN, PIN_LOW);
    my_pwm_disable();
    rt_kprintf("now car is stop\r\n");
    return RT_EOK;
}


#if CAR_MSH_ENABLE

MSH_CMD_EXPORT(car_set_percent , car set percent);
MSH_CMD_EXPORT(car_stop,car stop);
MSH_CMD_EXPORT(car_forward,car forward);

#endif
