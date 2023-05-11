
#include <rtdevice.h>
#include <rthw.h>

#include "board.h"
#include "drivers/touch.h"
#include "drv_uart.h"

#include "amdev.h"
#include "interrupt.h"
#include "io.h"
#include "riscv_io.h"
#include "rtdebug.h"
#include "rtdef.h"
#include "rtthread.h"
#include "sbi.h"
#include <stdio.h>

#define MOUSE_KEY_OFFSET 0
#define POSITION_X_OFFSET 8
#define POSITION_Y_OFFSET 12

/**
 * Used as a mask when testing buttons in buttonstate.
 *
 * - Button 1:  Left mouse button
 * - Button 2:  Middle mouse button
 * - Button 3:  Right mouse button
 */
#define SDL_BUTTON(X) (1 << ((X)-1))
#define SDL_BUTTON_LEFT 1
#define SDL_BUTTON_MIDDLE 2
#define SDL_BUTTON_RIGHT 3
#define SDL_BUTTON_X1 4
#define SDL_BUTTON_X2 5
#define SDL_BUTTON_LMASK SDL_BUTTON(SDL_BUTTON_LEFT)
#define SDL_BUTTON_MMASK SDL_BUTTON(SDL_BUTTON_MIDDLE)
#define SDL_BUTTON_RMASK SDL_BUTTON(SDL_BUTTON_RIGHT)
#define SDL_BUTTON_X1MASK SDL_BUTTON(SDL_BUTTON_X1)
#define SDL_BUTTON_X2MASK SDL_BUTTON(SDL_BUTTON_X2)

static rt_uint32_t mouse_btn_state = 0;
static rt_uint32_t positon_x = 0;
static rt_uint32_t positon_y = 0;

static void update_mouse(void) {
  mouse_btn_state = read_reg((void *)MOUSE_ADDR, MOUSE_KEY_OFFSET);
  positon_x = read_reg((void *)MOUSE_ADDR, POSITION_X_OFFSET);
  positon_y = read_reg((void *)MOUSE_ADDR, POSITION_Y_OFFSET);
}

static rt_size_t touch_mouse_readpoint(struct rt_touch_device *touch,
                                       void *data_buf, rt_size_t touch_num) {
  RT_ASSERT(touch);
  update_mouse();

  struct rt_touch_data *pdata = (struct rt_touch_data *)data_buf;
  pdata->timestamp = rt_tick_get();
  pdata->event = ((mouse_btn_state & SDL_BUTTON_LEFT) != 0)
                     ? RT_TOUCH_EVENT_DOWN
                     : RT_TOUCH_EVENT_UP;
  pdata->x_coordinate = positon_x;
  pdata->y_coordinate = positon_y;

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
// INIT_DEVICE_EXPORT(rt_hw_touch_init);