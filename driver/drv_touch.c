
#include <rtdevice.h>
#include <rthw.h>

#include "board.h"
#include "drivers/touch.h"
#include "drv_uart.h"

#include "amdev.h"
#include "io.h"
#include "interrupt.h"
#include "riscv_io.h"
#include "rtdebug.h"
#include "rtdef.h"
#include "rtthread.h"
#include "sbi.h"
#include <stdio.h>

#define LEFT_KEY_OFFSET 0
#define RIGHT_KEY_OFFSET 1
#define POSITION_X_OFFSET 8
#define POSITION_Y_OFFSET 12

static rt_size_t touch_mouse_readpoint(struct rt_touch_device *touch,
                                       void *data_buf, rt_size_t touch_num) {
  RT_ASSERT(touch);

  struct rt_touch_data *pdata = (struct rt_touch_data *)data_buf;

  rt_uint8_t left_key_press = inb(MOUSE_ADDR + LEFT_KEY_OFFSET);
  // 如何阻止优化？
  rt_uint32_t positon_x = inw(MOUSE_ADDR + POSITION_X_OFFSET);
  rt_uint32_t positon_y = inw(MOUSE_ADDR + POSITION_Y_OFFSET);


  pdata->x_coordinate = (rt_uint16_t)positon_x;
  pdata->y_coordinate = (rt_uint16_t)positon_y;
  pdata->timestamp = rt_tick_get();
  pdata->event =
      (left_key_press == 1) ? RT_TOUCH_EVENT_DOWN : RT_TOUCH_EVENT_UP;

  return touch_num;
}

static rt_err_t touch_mouse_control(struct rt_touch_device *touch, int cmd,
                                    void *arg) {
  RT_ASSERT(touch);

  switch (cmd) {
  case RT_TOUCH_CTRL_GET_ID:

    break;
  case RT_TOUCH_CTRL_GET_INFO:

    break;
  case RT_TOUCH_CTRL_SET_MODE:

    break;
  case RT_TOUCH_CTRL_SET_X_RANGE:

    break;
  case RT_TOUCH_CTRL_SET_Y_RANGE:

    break;
  case RT_TOUCH_CTRL_SET_X_TO_Y:

    break;
  case RT_TOUCH_CTRL_DISABLE_INT:

    break;
  case RT_TOUCH_CTRL_ENABLE_INT:

    break;
  default:

    break;
  }

  return RT_EOK;
}

static struct rt_touch_ops touch_ops = {
    .touch_readpoint = touch_mouse_readpoint,
    .touch_control = touch_mouse_control,
};

static struct rt_touch_device touch1;

int rt_hw_touch_init(void) {

  struct rt_touch_device *touch = &touch1;
  // config
  touch->config.dev_name = "mouse";
  touch->config.user_data = NULL;

  // info
  touch->info.point_num = 1;
  touch->info.range_x = 400;
  touch->info.range_y = 300;
  touch->info.vendor = RT_TOUCH_VENDOR_UNKNOWN;
  touch->info.type = RT_TOUCH_TYPE_NONE;

  touch->irq_handle = RT_NULL;

  // ops
  touch->ops = &touch_ops;

  rt_hw_touch_register(touch, "mouse", RT_DEVICE_FLAG_RDONLY, RT_NULL);

  //   struct touch_config config;

  return 0;
}
INIT_DEVICE_EXPORT(rt_hw_touch_init);