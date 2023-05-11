
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include <rtthread.h>
#include "drv_clcd.h"
#include "amdev.h"

#define CLCD_WIDTH  (BSP_LCD_WIDTH)
#define CLCD_HEIGHT (BSP_LCD_HEIGHT)

#define CLCD_DEVICE(dev)    (struct drv_clcd_device*)(dev)



struct drv_clcd_device {
    struct rt_device parent;

    int width;
    int height;

    uint8_t* fb;
};
struct drv_clcd_device _lcd;

static rt_err_t drv_clcd_init(struct rt_device* device) {
    struct drv_clcd_device* lcd = CLCD_DEVICE(device);

    lcd = lcd; /* nothing, right now */
    return RT_EOK;
}

static rt_err_t drv_clcd_control(struct rt_device* device, int cmd, void* args) {
    struct drv_clcd_device* lcd = CLCD_DEVICE(device);

    switch (cmd) {
    case RTGRAPHIC_CTRL_RECT_UPDATE:
    {
        struct rt_device_rect_info* info = (struct rt_device_rect_info*)args;
        // uint32_t* fb = (uint32_t*)(uintptr_t)FB_ADDR;
        outl(VGACTL_SYNC_REG, 1);
        info = info; /* nothing, right now */
    }
    break;

    case RTGRAPHIC_CTRL_GET_INFO:
    {
        struct rt_device_graphic_info* info = (struct rt_device_graphic_info*)args;

        RT_ASSERT(info != RT_NULL);
        info->pixel_format = RTGRAPHIC_PIXEL_FORMAT_ARGB888;
        info->bits_per_pixel = 32;
        info->width = lcd->width;
        info->height = lcd->height;
        info->framebuffer = lcd->fb;
    }
    break;

    default:
        return -RT_EINVAL;
    }

    return RT_EOK;
}

#ifdef RT_USING_DEVICE_OPS
const static struct rt_device_ops clcd_ops =
{
    drv_clcd_init,
    RT_NULL,
    RT_NULL,
    RT_NULL,
    RT_NULL,
    drv_clcd_control
};
#endif

int drv_clcd_hw_init(void) {
    struct rt_device* device = &_lcd.parent;

    /* memset _lcd to zero */
    memset(&_lcd, 0x0, sizeof(_lcd));

    _lcd.width = CLCD_WIDTH;
    _lcd.height = CLCD_HEIGHT;
    // _lcd.fb = rt_malloc(_lcd.width * _lcd.height * 4 /*ARGB888 4 Bytes*/);
    _lcd.fb = (uint8_t*)FB_ADDR;
    if (_lcd.fb == NULL) {
        rt_kprintf("initialize frame buffer failed!\n");
        return -1;
    }

    memset(_lcd.fb, 0xff, _lcd.width * _lcd.height * 4);

    device->type = RT_Device_Class_Graphic;

#ifdef RT_USING_DEVICE_OPS
    device->ops = &clcd_ops;
#else
    device->init = drv_clcd_init;
    device->control = drv_clcd_control;
#endif

    rt_device_register(device, "lcd", RT_DEVICE_FLAG_RDWR);

    rt_kprintf("lcd\n");
    return 0;
}
// INIT_DEVICE_EXPORT(drv_clcd_hw_init);
