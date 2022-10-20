/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-09-20     10091       the first version
 */
#include "car_pwm.h"

#define DBG_TAG "pwm"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

#define AIN1_PIN GET_PIN(F, 6)
#define AIN2_PIN GET_PIN(F, 7)
#define BIN1_PIN GET_PIN(F, 8)
#define BIN2_PIN GET_PIN(F, 9)

struct rt_device_pwm * pwm1 = RT_NULL;
struct rt_device_pwm * pwm2 = RT_NULL;

rt_uint32_t period = 1000000 ;
rt_uint32_t pulse = 50;

int pwm_init(void)
{
    rt_err_t ret;
    pwm1 = (struct rt_device_pwm *)rt_device_find(PWM_DEVICE_NAME1);
    pwm2 = (struct rt_device_pwm *)rt_device_find(PWM_DEVICE_NAME2);
    if(pwm1)
    {
        ret = rt_pwm_set(pwm1, PWM_CHANNEL1, period, (period*pulse)/100);
        if(ret<0)
            LOG_D("ret1: %d\r\n",ret);
        rt_pwm_enable(pwm1, PWM_CHANNEL1);
    }
    ret = RT_EOK;
    if(pwm2)
    {
        ret = rt_pwm_set(pwm2, PWM_CHANNEL2, period, (period*pulse)/100);
        if(ret<0)
            LOG_D("ret2: %d\r\n",ret);
        rt_pwm_enable(pwm2, PWM_CHANNEL2);
    }
    ret = rt_pwm_disable(pwm1, PWM_CHANNEL1);
    ret = rt_pwm_disable(pwm2, PWM_CHANNEL2);
    return ret;
}

int my_pwm_set(int argc,char **argv)
{
      rt_uint32_t new_pulse = 0;
      rt_err_t err = RT_EOK;
      if(argc == 1)
      {
        LOG_D("please input :my_pwm_set_pulse <pwm_dev> <percent>\r\n");
        err = - RT_ERROR;
        return err;
      }
      else if(argc == 2)
      {
        LOG_D("please input :my_pwm_set_pulse <pwm_dev> <percent>\r\n");
        err = - RT_ERROR;
        return err;
      }
      else
      {
          rt_uint8_t percent = 0;
          percent = atoi(argv[2]);
          if(strcmp(argv[1],"pwm1")==0)
          {
              new_pulse = period * percent / 100;
              rt_pwm_set(pwm1, PWM_CHANNEL1, period, new_pulse);
              LOG_D("set %s %d%% ok\r\n",pwm1,percent);
          }
          else if(strcmp(argv[1],"pwm2")==0)
          {
              new_pulse = period * percent / 100;
              rt_pwm_set(pwm2, PWM_CHANNEL2, period, new_pulse);
              LOG_D("set %s %d%% ok\r\n",pwm2,percent);
          }
          else {
              LOG_D("please input correct device name\r\n");
              LOG_D("pwm1 or pwm2\r\n");
              err = - RT_ERROR;
              return err;
          }
      }
      return err;
}
MSH_CMD_EXPORT(my_pwm_set , <input percent(%)>to set the pwm pulse);



rt_err_t my_pwm_enable(void)
{
    rt_err_t ret = RT_EOK;
    ret = rt_pwm_enable(pwm1, PWM_CHANNEL1);
    ret = rt_pwm_enable(pwm2, PWM_CHANNEL2);
    return ret;
}

rt_err_t my_pwm_disable(void)
{
    rt_err_t ret = RT_EOK;
    ret = rt_pwm_disable(pwm1, PWM_CHANNEL1);
    ret = rt_pwm_disable(pwm2, PWM_CHANNEL2);
    return ret;
}





