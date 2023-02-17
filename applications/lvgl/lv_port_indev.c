/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-10-18     Meco Man     The first version
 */
#include "drivers/touch.h"
#include "lv_hal_indev.h"
#include "rtthread.h"
#include <lvgl.h>
#include <rtdevice.h>
#include <stdbool.h>

#include <drv_clcd.h>

lv_indev_t *touch_indev;

static rt_device_t rt_touch_dev = RT_NULL;
static struct rt_touch_data touch_read_data;

static lv_indev_state_t last_state = LV_INDEV_STATE_REL;
static rt_int16_t last_x = 0;
static rt_int16_t last_y = 0;

static void input_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data) {

  rt_device_read(rt_touch_dev, 0, &touch_read_data, sizeof(touch_read_data));

  data->point.x = touch_read_data.x_coordinate;
  data->point.y = touch_read_data.y_coordinate;
  data->state = (touch_read_data.event == RT_TOUCH_EVENT_DOWN)
                    ? LV_INDEV_STATE_PRESSED
                    : LV_INDEV_STATE_RELEASED;
}

void lv_port_indev_input(rt_int16_t x, rt_int16_t y, lv_indev_state_t state) {
  last_state = state;
  last_x = x;
  last_y = y;
}

void lv_port_indev_init(void) {

  rt_touch_dev = rt_device_find("mouse");

  RT_ASSERT(rt_touch_dev != RT_NULL);
  rt_device_open(rt_touch_dev, RT_DEVICE_FLAG_RDONLY);

  rt_kprintf("open mouse ok\n");

  static lv_indev_drv_t indev_drv;

  lv_indev_drv_init(&indev_drv); /*Basic initialization*/
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = input_read;

  /*Register the driver in LVGL and save the created input device object*/
  touch_indev = lv_indev_drv_register(&indev_drv);
}
